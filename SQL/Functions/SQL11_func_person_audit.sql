-- Создаем таблицу, в которой будем хранить информацию
-- об изменениях, вносимых в таблицу 'person'.
CREATE TABLE person_audit (
	created timestamp with time zone DEFAULT current_timestamp NOT NULL,
	type_event char(1) DEFAULT 'I' NOT NULL,
	row_id bigint NOT NULL,
	name varchar,
	age integer,
	gender varchar,
	address varchar,
	CONSTRAINT ch_type_event CHECK (type_event IN ('I', 'U', 'D'))
);

-- Пишем функцию, которая будет вносить новую строку в нашу таблицу
-- при выполнении оперций 'insert', 'update', 'delete'.
CREATE OR REPLACE FUNCTION fnc_trg_person_audit()
RETURNS TRIGGER 
AS $$
	BEGIN
		IF (TG_OP = 'INSERT')  THEN
			INSERT INTO person_audit
			VALUES (current_timestamp, 'I', NEW.*);
		ELSEIF (TG_OP = 'UPDATE') THEN
			INSERT INTO person_audit
			VALUES (current_timestamp, 'U', OLD.*);
		ELSEIF (TG_OP = 'DELETE') THEN
			INSERT INTO person_audit
			VALUES (current_timestamp, 'D', OLD.*);
		END IF;
		RETURN NULL;
	END;
$$
LANGUAGE plpgsql;

-- Создаем соответствующий триггер, чтобы указать таблицу,
-- для которой нужно запустить функцию.
CREATE TRIGGER trg_person_audit
AFTER INSERT OR UPDATE OR DELETE ON person FOR EACH ROW
EXECUTE FUNCTION fnc_trg_person_audit();

-- Выполняем действия с таблицей 'person'.
INSERT INTO person(id, name, age, gender, address) VALUES (10,'Damir', 22, 'male', 'Irkutsk'); 
UPDATE person SET name = 'Bulat' WHERE id = 10; 
UPDATE person SET name = 'Damir' WHERE id = 10; 
DELETE FROM person WHERE id = 10;

-- Видим, что новые строки были внесены в таблицу 'person_audit'.
SELECT *
FROM person_audit;