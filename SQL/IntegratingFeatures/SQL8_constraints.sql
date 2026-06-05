ALTER TABLE person_discounts
	ADD CONSTRAINT ch_nn_person_id CHECK (person_id IS NOT NULL),
	ADD CONSTRAINT ch_nn_pizzeria_id CHECK (pizzeria_id IS NOT NULL),
	ADD CONSTRAINT ch_nn_discount CHECK (discount IS NOT NULL),
	ALTER COLUMN discount SET DEFAULT 0,
	ADD CONSTRAINT ch_range_discount CHECK (discount BETWEEN 0 AND 100);


-- Добавлены следующие правила ограничений для 
-- существующих столбцов таблицы person_discounts:
-- 		Столбец person_id не должен содержать NULL.
-- 		Столбец pizzeria_id не должен содержать NULL.
-- 		Столбец discount не должен содержать NULL.
-- 		Столбец discount должен иметь значение по умолчанию 0.
-- 		Столбец discount должен содержать значения в диапазоне от 0 до 100.