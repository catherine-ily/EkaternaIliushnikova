-- Создаем новую таблицу, которая будет хранить информацию о скидках клиентов.
CREATE TABLE IF NOT EXISTS person_discounts (						
	id bigint PRIMARY KEY,
	person_id bigint NOT NULL,
	pizzeria_id bigint NOT NULL,
	discount numeric NOT NULL DEFAULT 0,
	CONSTRAINT fk_person_discounts_person_id FOREIGN KEY (person_id) REFERENCES person(id),
	CONSTRAINT fk_person_discounts_pizzeria_id FOREIGN KEY (pizzeria_id) REFERENCES pizzeria(id)
);

-- Вносим данные о скидках в таблицу в соответствии с условием задачи.
INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)	
SELECT 
	ROW_NUMBER() OVER() AS id,
	po.person_id AS person_id,
	m.pizzeria_id AS pizzeria_id,
	CASE 
		WHEN COUNT(*) = 1 THEN 10.5
		WHEN COUNT(*) = 2 THEN 22
		ELSE 30
	END AS discount
FROM person_order po
JOIN menu m ON m.id = po.menu_id
GROUP BY person_id, pizzeria_id;

-- Запрос, который возвращает список заказов с фактической стоимостью 
-- и стоимостью с примененной скидкой для каждого клиента в соответствующей пиццерии. 
-- Результат отсортирован по имени клиента и названию пиццы.
SELECT p.name AS name,												
		m.pizza_name AS pizza_name,									
		m.price AS price,											
		CAST(m.price * ((100 - pd.discount) / 100) AS INTEGER)  AS discount_price,
		pi.name AS pizzeria_name
FROM person_order po 
JOIN person p ON p.id = po.person_id
JOIN menu m ON m.id = po.menu_id
JOIN pizzeria pi ON pi.id = m.pizzeria_id
JOIN person_discounts pd ON (po.person_id = pd.person_id AND pi.id = pd.pizzeria_id)
ORDER BY 1, 2;