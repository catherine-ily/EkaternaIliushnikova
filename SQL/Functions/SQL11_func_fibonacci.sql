-- Данная функия выводит все числа из последовательности
-- фибоначчи до указанного на входе числа.

CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop integer DEFAULT 10)
RETURNS TABLE (fibonacci integer)
AS $$
	WITH RECURSIVE fib_cycle AS (
		SELECT 0 AS f_n,
				1 AS s_n,
				0 AS sum_n

		UNION ALL

		SELECT fc.s_n AS f_n,
				fc.sum_n AS s_n,
				fc.s_n + fc.sum_n AS sum_n
		FROM fib_cycle fc
		WHERE fc.s_n + fc.sum_n < pstop
	)

	SELECT sum_n AS fibonacci FROM fib_cycle;
$$
LANGUAGE SQL;

select * from fnc_fibonacci(100);

select * from fnc_fibonacci();
