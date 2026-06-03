SELECT (SELECT name
		FROM person
		WHERE id = person_order.person_id
		GROUP BY name) AS NAME,
		CASE
			WHEN (SELECT name FROM person WHERE id = person_order.person_id
		GROUP BY name) = 'Denis'
			THEN true
			ELSE false
		END AS check_name
FROM person_order 
WHERE (menu_id = 13 OR menu_id = 14 OR menu_id = 18) 
	AND order_date = '2022-01-07';


-- Запрос возвращает имена людей (используя внутренний запрос в части SELECT), 
-- которые сделали заказы по меню с идентификаторами 13, 14 и 18, 
-- при этом дата заказа должна быть 7 января 2022 года. А также выводит
-- столбец check_name, в который записывается результат 'true', 
-- если имя персоны равно 'Denis', и 'false' в противном случае.