-- Создаем последовательность с шагом 1.
CREATE SEQUENCE seq_person_discounts        
START WITH 1
INCREMENT BY 1;

-- Устанавливаем текущее значение последовательности как количество строк в таблице + 1.
SELECT setval('seq_person_discounts', (SELECT COUNT(*) + 1 FROM person_discounts));

-- Вводим условие, что последующие значения для колонки 'id' в таблице 'person_discount'
-- будут браться из созданной последовательности.
ALTER TABLE person_discounts
ALTER COLUMN id SET DEFAULT nextval('seq_person_discounts');