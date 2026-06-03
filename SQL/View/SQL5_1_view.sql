CREATE OR REPLACE VIEW v_price_with_discount AS
	SELECT p.name AS name,
			menu.pizza_name AS pizza_name,
			menu.price AS price,
			CAST((menu.price - menu.price * 0.1) AS INTEGER) AS discount_price
	FROM person p
	JOIN person_order po ON po.person_id = p.id
	JOIN menu ON po.menu_id = menu.id
	ORDER BY 1, 2;

SELECT *
FROM v_price_with_discount;


-- Создаем представление, которое возвращает заказы человека с указанием:
-- 		имени клиента (name),
-- 		названия пиццы (pizza_name),
-- 		реальной цены (price),
-- 		столбца discount_price (рассчитывается по формуле price - price * 0.1, то есть с 10% скидкой).
-- Результаты отсортированы по имени клиента (name), названию пиццы (pizza_name).
-- Столбец discount_price приведен к целочисленному типу (integer).