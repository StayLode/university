--SELECT 'there are two cats in the room'::tsvector; 
-- Prende in input una stringa e restituisce un valore tsvector, facendo delle modifiche (rimuove le stopwords...)
--SELECT to_tsvector('english','there are two cats in the room'); 
--SELECT 'Cats & room | prova'::tsquery; 
--SELECT to_tsquery('english','cat & room'); 
--SELECT to_tsquery('english','Cats | Rooms'); 
--SELECT 'there are two cats in the room'::tsvector @@ 'cat & room'::tsquery; 
--SELECT to_tsvector('english','there are two cats in the room') @@ to_tsquery('english','Cats & Rooms'); 
SELECT to_tsvector('fatal error') @@ to_tsquery('fatal <-> error');
--CREATE TABLE documenti (title varchar(20), primiElementi varchar(50), altriElementi varchar(50)); 
--INSERT INTO documenti(title,primiElementi,altriElementi) VALUES('frutta','mela pera','arancia pesca'); 
--INSERT INTO documenti(title,primiElementi,altriElementi) VALUES('auto','alfa lancia','fiat mercedes'); 
--INSERT INTO documenti(title,primiElementi,altriElementi) VALUES('vari','mela fiat','pera'); 

--SELECT title FROM documenti WHERE to_tsvector(primiElementi)@@to_tsquery('mela'); 
--SELECT title FROM documenti WHERE to_tsvector(primiElementi)@@to_tsquery('fiat'); 
--SELECT title FROM documenti WHERE to_tsvector(primiElementi || ' ' || altriElementi)@@to_tsquery('fiat'); 

--ALTER TABLE documenti ADD COLUMN primiEle_tsvector tsvector; 
--UPDATE documenti SET primiEle_tsvector = to_tsvector(primiElementi); 
--CREATE INDEX primiEle_idx ON documenti USING GIN(primiEle_tsvector); 

--ALTER TABLE documenti ADD COLUMN tuttiEle_tsvector tsvector; 
--UPDATE documenti SET tuttiEle_tsvector = to_tsvector(primiElementi || ' ' || altriElementi); 
--CREATE INDEX tuttiEle_idx ON documenti USING GIN(tuttiEle_tsvector); 
--SELECT title FROM documenti WHERE tuttiEle_tsvector@@to_tsquery('fiat');

