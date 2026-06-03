SELECT *
FROM person
CROSS JOIN pizzeria
ORDER BY person.id, pizzeria.id;

-- Запрос возвращает все возможные комбинации записей из 
-- таблиц person и pizzeria, а также сортирует результат
-- сначала по таблице person, а затем — по таблице pizzeria.