SELECT object_name FROM (
    SELECT name AS object_name, 1 AS order_num FROM person
    UNION ALL
    SELECT pizza_name AS object_name, 2 AS order_num FROM menu
) AS combined
ORDER BY order_num, object_name;

-- Запрос объединяет в один общий список идентификаторы меню 
-- и названия пицц из таблицы menu, а также идентификаторы 
-- и имена людей из таблицы person.
-- Выводятся сначала данные из таблицы person? затем данные из таблицы menu.
-- Дублирующиеся строки сохраняются.