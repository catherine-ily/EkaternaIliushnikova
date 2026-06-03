SELECT pi.name AS name,
		COUNT (*) AS count_of_orders,
		ROUND(AVG (m.price), 2) AS average_price,
		MAX (m.price) AS max_price,
		MIN (m.price) AS min_price
FROM person_order po
JOIN menu m ON m.id = po.menu_id
JOIN pizzeria pi ON pi.id = m.pizzeria_id
GROUP BY 1
ORDER BY 1;

-- Запрос возвращает для каждой пиццерии:
-- 		общее количество заказов,
-- 		среднюю цену,
-- 		максимальную цену
-- 		и минимальную цену на проданные пиццы.