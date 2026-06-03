-- Данная функция принимает входной параметр в виде массива 
-- чисел и возвращает минимальное значение.

CREATE OR REPLACE FUNCTION func_minimum (VARIADIC arr numeric[])
RETURNS numeric
AS $$
	SELECT MIN(value) FROM UNNEST(arr) AS value;
$$
LANGUAGE SQL;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);
