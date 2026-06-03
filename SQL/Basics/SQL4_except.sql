SELECT pizza_name,
		price,
		pi.name AS pizzeria_name
FROM menu
JOIN pizzeria pi ON pi.id = menu.pizzeria_id
WHERE menu.id IN (SELECT id
	FROM menu
	EXCEPT 
	SELECT menu_id
	FROM person_order)
ORDER BY 1, 2;

-- Выводит названия пицц из пиццерии, которые никто не заказывал, 
-- включая соответствующие цены.
-- Результат отсортирован по названию пиццы и цене.