DELETE FROM person_order            -- Удаляет все заказы от 25 февраля 2022 года.
WHERE order_date = '2022-02-25';

DELETE FROM menu                    -- Удаляет позицию 'greek pizza' из меню.
WHERE pizza_name = 'greek pizza';