SELECT d_i::date AS missing_date
FROM generate_series(date '2022-01-01', '2022-01-10', '1 day') AS d_i
LEFT JOIN (SELECT DISTINCT visit_date
			FROM person_visits
			WHERE person_id = 1 OR person_id = 2) AS p_v 
			ON p_v.visit_date = d_i::date
WHERE p_v.visit_date IS NULL
ORDER BY missing_date;

-- Запрос возвращает отсутствующие даты с 1 по 10 января 2022 года 
-- (включительно) для посещений людьми с идентификаторами 1 и 2 — то есть 
-- дни, пропущенные обоими.
-- Результат отсортирован по дате посещения в порядке возрастания.
-- По условию задачи было необходимо использовать конструкцию generate_series(...).