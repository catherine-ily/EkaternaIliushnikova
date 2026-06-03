CREATE UNIQUE INDEX idx_menu_unique ON menu (pizzeria_id, pizza_name);  -- Создаем уникальный (гарантирует, что значения связки 'pizzeria_id' - 'pizza_name' в выводе не будут повторяться)
                                                                        -- индекс для таблицы menu для столбцов pizzeria_id и pizza_name.

SET enable_seqscan = off;                                               -- Отключаем последовательное сканирование.

EXPLAIN ANALYZE                                                         -- Вызывает подробный отчет о вызове, доказывает, что индекс работает.
SELECT *
FROM menu m
WHERE pizza_name = 'pepperoni pizza' AND pizzeria_id = 1;