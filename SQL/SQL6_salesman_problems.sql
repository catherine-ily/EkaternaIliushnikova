CREATE TABLE IF NOT EXISTS tour_table (				-- Создаем таблицу, где будем хранить начальную и 
	point1 VARCHAR NOT NULL,						-- конечную точку пути и стоимость перемещения между ними.
	point2 VARCHAR NOT NULL,
	cost INTEGER NOT NULL
);

INSERT INTO tour_table (point1, point2, cost)		-- Вносим данные в созданную таблицу на основании условия задачи.
VALUES ('a','b',10), ('b','a',10),
	   ('a','d',20), ('d','a',20),
       ('a','c',15), ('c','a',15), 
       ('b','d',25), ('d','b',25),
       ('b','c',35), ('c','b',35),
       ('c','d',30), ('d','c',30);

WITH RECURSIVE tours AS (							-- Создаем обобщенное табличное выражение, в котором реализуем рекурсию.
	SELECT  point1 AS start_point,					-- Эта часть кода найдет нам все варианты и стоимость отправления из точки 'а'.
			point2 AS current_point,
			ARRAY[point1, point2] AS tour,
			cost AS total_cost,
			1 AS depth
	FROM tour_table 
	WHERE point1 = 'a'
	
	
	UNION ALL

	SELECT  t.start_point,							-- А потом к ней мы присоединим результаты выполнения данной, рекурсивной, части: 
			tt.point2 AS current_point,				-- здесь мы сохраняем каждую последующую точку марштрута в массив, суммируем стоимость маршрута.
			t.tour || tt.point2 AS tour,			-- По итогу у нас получится таблица со всеми возможными вариантами перемещений, 
			tt.cost + t.total_cost AS total_cost,	-- где стартовая точка всегда 'a' и суммарной стоимостью такого маршрута.
			1 + t.depth AS depth
	FROM tours t
	JOIN tour_table tt ON tt.point1 = t.current_point
	WHERE NOT tt.point2 = ANY(t.tour) AND NOT (tt.point2 = 'a' AND t.depth < 3)
),

	complete_tours AS (								-- Данное табличное выражение использует данные из табличного выражения  'tours',
	SELECT  tt.cost + t.total_cost AS total_cost,	-- чтобы закончить маршрут (к каждому получившемуся массиву добавляется в конец точка 'a',
			t.tour || tt.point2 AS tour				-- и также увеличивается общая стоимость пути).
	FROM tours t
	JOIN tour_table tt ON tt.point1 = t.current_point AND tt.point2 = 'a'
	WHERE array_length(t.tour, 1) = 4 
	)

       
SELECT  total_cost,									-- Запрос вернет только строку с минимальным значением параметра стоимость.
		tour
FROM complete_tours
WHERE total_cost = (SELECT MIN(total_cost) FROM complete_tours)
ORDER BY 1, 2;