SELECT action_date, name
FROM ( SELECT order_date AS action_date, person_id
		FROM person_order
		INTERSECT ALL
		SELECT visit_date AS action_date, person_id
		FROM person_visits) AS A
JOIN person ON person.id = A.person_id
ORDER BY action_date, name DESC;

-- Запрос находит имена людей, 
-- которые в один и тот же день и посетили заведение, и сделали заказ пиццы.
-- Результат отсортирован сначала по дате действия (action_date) 
-- в порядке возрастания, затем по имени человека (person_name) в порядке убывания.