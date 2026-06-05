INSERT INTO menu (id, pizzeria_id, pizza_name, price)				-- Добавляет новую пиццу с названием 'greek pizza' в меню.
VALUES (
	(SELECT MAX(id) + 1 FROM menu),  
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'greek pizza', 
	900);

INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)  -- Добавляет новый визит для посетителя 'Irina' в пиццерии 'Dominos'.
VALUES (
	(SELECT MAX(id) + 1 FROM person_visits),
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'),
	'2022-02-24');

INSERT INTO person_order (id, person_id, menu_id, order_date)		-- Добавляет новый заказ пиццы 'greek pizza' всем посетителям.
SELECT 
	(SELECT MAX(id) FROM person_order) + gs,
	p.id,
	(SELECT id FROM menu WHERE pizza_name = 'greek pizza'),
	'2022-02-25'
FROM person p
JOIN generate_series(1, (SELECT COUNT(*) FROM person)) AS gs  ON gs = p.id;

