WITH women AS (SELECT pizzeria_id,
					  COUNT (pv.id) AS pvc
			FROM person_visits pv
			JOIN person p ON p.id = pv.person_id
			WHERE gender = 'female'
			GROUP BY pizzeria_id),
	 men AS (SELECT pizzeria_id,
					COUNT (pv.id) AS pvc
			FROM person_visits pv
			JOIN person p ON p.id = pv.person_id
			WHERE gender = 'male'
			GROUP BY pizzeria_id)

SELECT pi.name AS pizzeria_name
FROM pizzeria pi
JOIN women w ON w.pizzeria_id = pi.id
JOIN men m ON m.pizzeria_id = pi.id
WHERE w.pvc > m.pvc

UNION ALL

SELECT pi.name AS pizzeria_name
FROM pizzeria pi
JOIN women w ON w.pizzeria_id = pi.id
JOIN men m ON m.pizzeria_id = pi.id
WHERE w.pvc < m.pvc

ORDER BY 1;

-- Запрос возвращает пиццерии, которые посещали чаще женщины или чаще мужчины.
-- Дубликаты строк сохраняются.
-- Результат отсортирован по названию пиццерии.