-- Запрос возвращает общий объем (сумму всех средств) транзакций 
-- из балансов пользователей, сгруппированный по пользователям и 
-- типам балансов, с учетом курса валют.

-- Исходные таблицы не находятся в состоянии согласованности данных.
-- Возможны значения NULL в полях Name и Lastname таблицы User

WITH balance_sum AS (
	SELECT user_id,
		   SUM(money) AS volume,
		   type,
		   currency_id
	FROM balance
	GROUP BY user_id, type, currency_id 
	),
	currency_clear AS (
	SELECT id,
		   name,
		   rate_to_usd,
		   updated,
		   ROW_NUMBER() OVER(PARTITION BY id ORDER BY updated DESC) AS last_udt
	FROM "currency"
	)

SELECT COALESCE(u.name, 'not defined') AS name,
		COALESCE(u.lastname, 'not defined') AS lastname,
		bs.type AS type,
		bs.volume AS volume,
		COALESCE(cc.name, 'not defined') AS currency_name,
		COALESCE(cc.rate_to_usd, 1) AS last_rate_to_usd,
		bs.volume * COALESCE(cc.rate_to_usd, 1) AS total_volume_in_usd
FROM balance_sum bs
LEFT JOIN "user" u ON u.id = bs.user_id
LEFT JOIN currency_clear cc ON bs.currency_id = cc.id AND cc.last_udt = 1
ORDER BY 1 DESC, 2, 3;
