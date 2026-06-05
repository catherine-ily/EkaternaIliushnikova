-- Запрос возвращает всех пользователей, все операции по балансу 
-- (в этой задаче игнорируются валюты, отсутствующие в таблице Currency) 
-- с указанием наименования валюты и рассчитанным значением суммы в USD.
-- Курс валюты берется либо самый ближайший по времени к дате транзакции,
-- либо, в случае отсутствия такового, ближайший к дате транзакции курс валюты 
-- из будущего.

insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

WITH currency_clear AS (
	SELECT c.name AS currency_name,
			COALESCE(
				(SELECT c1.rate_to_usd
				FROM currency c1
				WHERE c.name = c1.name AND b.updated >= c1.updated
				ORDER BY c1.updated DESC
				LIMIT 1
				),
				(SELECT c2.rate_to_usd
				FROM currency c2
				WHERE c.name = c2.name AND b.updated < c2.updated
				ORDER BY c2.updated ASC
				LIMIT 1)
			) AS clear_currency,
			money,
			u.name,
			u.lastname
	FROM balance b
    LEFT JOIN "user" u ON u.id = b.user_id
    JOIN (SELECT DISTINCT id, name FROM currency ) AS c ON c.id = b.currency_id
    WHERE c.name IS NOT NULL
	)

SELECT COALESCE(cc.name, 'not defined') AS name,
		COALESCE(cc.lastname, 'not defined') AS lastname,
		cc.currency_name AS currency_name,
		cc.clear_currency * cc.money AS currency_in_usd
FROM currency_clear cc
ORDER BY 1 DESC, 2, 3;
