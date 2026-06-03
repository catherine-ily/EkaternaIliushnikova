SELECT person_id
FROM person_order
WHERE order_date = '2022-01-07'
EXCEPT ALL
SELECT person_id
FROM person_visits
WHERE visit_date = '2022-01-07';

-- Запрос возвращает разницу по значениям столбца person_id между 
-- таблицами person_order и person_visits, при этом сохраняя дубликаты.
-- Запрос учитывает только записи за 7 января 2022 года