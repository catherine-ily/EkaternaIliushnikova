CREATE MATERIALIZED VIEW IF NOT EXISTS mv_dmitriy_visits_and_eats AS
	SELECT pi.name AS pizzeria_name
	FROM person p
	JOIN person_visits pv ON pv.person_id = p.id
	JOIN pizzeria pi ON pi.id = pv.pizzeria_id
	JOIN menu ON menu.pizzeria_id = pi.id
	WHERE p.name = 'Dmitriy' 
		AND pv.visit_date = '2022-01-08' 
		AND menu.price < 800;

SELECT *
FROM mv_dmitriy_visits_and_eats;

-- Создаем материализованное представление на основе SQL-запроса, 
-- который находит название пиццерии, где Дмитрий был 8 января 2022 года 
-- и мог съесть пиццу дешевле 800 рублей.