SELECT p.name AS name, 
		COUNT(*) AS count_of_visits
FROM person_visits pv
JOIN person p on p.id = pv.person_id
GROUP BY 1 
HAVING COUNT(pv.id) > 3;

-- Запрос возвращает имя человека (person name) и соответствующее 
-- посещений любых пиццерий при условии, что это количество превышает 
-- 3 раза (> 3). Используется конструкция HAVING.