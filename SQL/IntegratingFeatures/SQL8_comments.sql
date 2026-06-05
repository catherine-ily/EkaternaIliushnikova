COMMENT ON TABLE person_discounts 
	IS 'Сохраняет размер скидки клиента в соответствующей пиццерии';

COMMENT ON COLUMN person_discounts.id
	IS 'Идентификационный номер записи';

COMMENT ON COLUMN person_discounts.person_id
	IS 'Идентификационный номер клиента';

COMMENT ON COLUMN person_discounts.pizzeria_id
	IS 'Идентификационный номер пиццерии';

COMMENT ON COLUMN person_discounts.discount
	IS 'Размер скидки в процентах';

-- Добавлены комментарии, 
-- объясняющие бизнес-назначение таблицы и всех ее атрибутов.