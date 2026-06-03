SELECT order_date, CONCAT(name, ' (age:', age, ')') AS person_information
FROM person_order
NATURAL JOIN (
        SELECT id AS person_id, name, age
        FROM person) AS people 
ORDER BY order_date, person_information;

-- Запрос возвращает дату заказа из таблицы person_order и
-- имя человека, сделавшего заказ (из таблицы person), 
-- имя и возраст отформатированы по образцу: Andrey (age:21)

-- Запрос сортирует результаты по обоим столбцам в порядке возрастания.
-- Используется natural join (база данных сама находит колонки с одинаковыми именами
-- и объединяет результат по ним).