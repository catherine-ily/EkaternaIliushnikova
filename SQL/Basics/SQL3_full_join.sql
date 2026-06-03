SELECT COALESCE (person.name, '-') AS pesron_name,
		CASE 
			WHEN visit_date IS NULL THEN 'null'
			ELSE visit_date::text
		END AS visit_date,
		COALESCE (pizzeria.name, '-') AS pizzeria_name
FROM person
FULL JOIN (SELECT *
			FROM person_visits
			WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-03') AS p_v ON person.id = p_v.person_id
FULL JOIN pizzeria ON pizzeria.id = p_v.pizzeria_id
ORDER BY 1, 2, 3;

-- Запрос возвращает полный список имен людей, 
-- посетивших (или не посетивших) пиццерии в период с 1 по 3 января 2022 года,
-- а также полный список названий пиццерий, 
-- которые посещались (или не посещались) в этот же период.
-- Для NULL-значений в колонках person_name и pizzeria_name используется замена на '-'.