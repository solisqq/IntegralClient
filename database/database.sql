--
-- Plik wygenerowany przez SQLiteStudio v3.2.1 dnia Sun Oct 18 21:48:08 2020
--
-- Uzyte kodowanie tekstu: System
--
#PRAGMA foreign_keys = off;
#BEGIN TRANSACTION;

-- Tabela: inputs
CREATE TABLE inputs (id INTEGER PRIMARY KEY AUTO_INCREMENT UNIQUE NOT NULL, name TEXT, inputid INT, connectionid INT, type INT, posx DOUBLE, posy DOUBLE);
INSERT INTO inputs (id, name, inputid, connectionid, type, posx, posy) VALUES (42, 'Unknown', 1, 23, 0, 276.0, 226.316);
INSERT INTO inputs (id, name, inputid, connectionid, type, posx, posy) VALUES (43, 'WEJ', 1, 51, 4, 726.159, 384.892);

-- Tabela: integrals
CREATE TABLE integrals (id INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL UNIQUE, name TEXT (32) NOT NULL, ip TEXT (32), posx REAL NOT NULL, posy REAL NOT NULL, port INTEGER, image INT, zones TEXT, pass TEXT);
INSERT INTO integrals (id, name, ip, posx, posy, port, image, zones, pass) VALUES (49, 'G.BUD.', '192.168.100.128', 639.972, 350.754, 7094, 3, 'Strefa 1', '');
INSERT INTO integrals (id, name, ip, posx, posy, port, image, zones, pass) VALUES (51, 'DOM.', '192.168.0.60', 412.256, 398.995, 7094, 0, 'Strefa 1,Strefa 2', 1111);
INSERT INTO integrals (id, name, ip, posx, posy, port, image, zones, pass) VALUES (52, 'Magazyn', '192.168.0.25', 253.482, 757.789, 7094, 2, 'Strefa 1', '');

-- Tabela: log
CREATE TABLE log (id INTEGER PRIMARY KEY AUTO_INCREMENT UNIQUE NOT NULL, date DATETIME, msg TEXT);
INSERT INTO log (id, date, msg) VALUES (1, '2020-09-10 02:05:57', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (2, '2020-09-10 02:06:00', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (3, '2020-09-10 02:21:39', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (4, '2020-09-10 02:21:41', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (5, '2020-09-10 02:23:31', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (6, '2020-09-10 02:23:33', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (7, '2020-09-10 02:25:30', 'Wyswietlono alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (8, '2020-09-10 02:25:33', 'Odczytano alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (9, '2020-09-10 02:25:34', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (10, '2020-09-10 02:25:36', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (11, '2020-09-10 02:41:48', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (12, '2020-09-10 02:41:50', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (13, '2020-09-10 02:45:13', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (14, '2020-09-10 02:45:14', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (15, '2020-09-10 02:57:53', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (16, '2020-09-10 02:57:54', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (17, '2020-09-10 02:58:31', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (18, '2020-09-10 02:58:32', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (19, '2020-09-10 02:59:47', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (20, '2020-09-10 02:59:48', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (21, '2020-09-10 03:00:21', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (22, '2020-09-10 03:00:23', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (23, '2020-09-10 03:01:28', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (24, '2020-09-10 03:01:29', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (25, '2020-09-10 03:03:00', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (26, '2020-09-10 03:03:02', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (27, '2020-09-10 03:03:50', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (28, '2020-09-10 03:03:51', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (29, '2020-09-10 03:04:17', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (30, '2020-09-10 03:04:18', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (31, '2020-09-10 03:05:12', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (32, '2020-09-10 03:05:13', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (33, '2020-09-10 03:06:00', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (34, '2020-09-10 03:06:02', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (35, '2020-09-10 03:08:01', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (36, '2020-09-10 03:08:02', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (37, '2020-09-10 03:11:07', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (38, '2020-09-10 03:11:08', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (39, '2020-09-10 03:13:44', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (40, '2020-09-10 03:13:46', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (41, '2020-09-10 16:03:01', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (42, '2020-09-10 18:52:53', 'Wyswietlono alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (43, '2020-09-10 18:52:55', 'Odczytano alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (44, '2020-09-10 19:31:39', 'Wykryto zdarzenie w Komunikat: Uzbrojono. Tresc: Poprawnie uzbrojono strefy/strefe.');
INSERT INTO log (id, date, msg) VALUES (45, '2020-09-10 19:32:08', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (46, '2020-09-10 19:32:13', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (47, '2020-09-10 20:01:12', 'Wyswietlono alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (48, '2020-09-10 20:01:14', 'Odczytano alarm: Problem w jednostce nazwa (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: nazwa.');
INSERT INTO log (id, date, msg) VALUES (49, '2020-09-10 20:01:19', 'Wykryto zdarzenie w Komunikat: Skasowano alarmy. Tresc: Poprawnie zresetowano alarmy w strefach.');
INSERT INTO log (id, date, msg) VALUES (50, '2020-09-10 22:18:35', 'Wyswietlono alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (51, '2020-09-10 22:18:37', 'Odczytano alarm: Utracono polaczenie z jedna z central. Sprawdz polaczenie komputera oraz centrali.. Zródlo: 192.168.0.60.');
INSERT INTO log (id, date, msg) VALUES (52, '2020-09-17 22:44:07', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (53, '2020-09-17 23:01:30', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (54, '2020-09-17 23:01:56', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (55, '2020-09-17 23:07:06', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (56, '2020-09-17 23:10:33', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (57, '2020-09-17 23:12:02', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (58, '2020-09-17 23:12:13', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (59, '2020-09-17 23:12:16', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (60, '2020-09-17 23:27:32', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (61, '2020-09-17 23:40:56', 'Wyswietlono alarm: TestError. Zródlo: Test.');
INSERT INTO log (id, date, msg) VALUES (62, '2020-09-17 23:41:01', 'Odczytano alarm: TestError. Zródlo: Test.');
INSERT INTO log (id, date, msg) VALUES (63, '2020-09-17 23:42:34', 'Wykryto zdarzenie w Komunikat: Brak autoryzacji. Tresc: Podano bledne haslo do uzyskania uprawnien, nieudana próbe logowania odnotowano w bazie danych.');
INSERT INTO log (id, date, msg) VALUES (64, '2020-09-17 23:43:03', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (65, '2020-09-17 23:44:58', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (66, '2020-09-17 23:45:35', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (67, '2020-09-17 23:46:46', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (68, '2020-09-17 23:47:20', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (69, '2020-09-17 23:53:07', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (70, '2020-09-17 23:54:22', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (71, '2020-09-17 23:56:01', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (72, '2020-09-18 00:32:27', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (73, '2020-09-29 15:01:46', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (74, '2020-10-13 20:47:07', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (75, '2020-10-13 20:58:25', 'Wykryto zdarzenie w Komunikat: Nie rozbrojono. Tresc: Nie udalo sie rozbroic stref(y). Sprawdz czy komputer poprawnie polaczony jest z centrala lub wprowadz inne klucz dostepu.');
INSERT INTO log (id, date, msg) VALUES (76, '2020-10-13 20:58:34', 'Wykryto zdarzenie w Komunikat: Rozbrojono. Tresc: Poprawnie rozbrojono strefy/strefe.');
INSERT INTO log (id, date, msg) VALUES (77, '2020-10-13 20:59:37', 'Wykryto zdarzenie w Komunikat: Uzbrojono. Tresc: Poprawnie uzbrojono strefy/strefe.');
INSERT INTO log (id, date, msg) VALUES (78, '2020-10-13 21:03:58', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (79, '2020-10-13 21:22:38', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (80, '2020-10-13 21:23:07', 'Wykryto zdarzenie w Komunikat: Rozbrojono. Tresc: Poprawnie rozbrojono strefy/strefe.');
INSERT INTO log (id, date, msg) VALUES (81, '2020-10-13 21:23:14', 'Wykryto zdarzenie w Komunikat: Uzbrojono. Tresc: Poprawnie uzbrojono strefy/strefe.');
INSERT INTO log (id, date, msg) VALUES (82, '2020-10-13 21:37:48', 'Wyswietlono alarm: Problem w jednostce DOM. (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: DOM..');
INSERT INTO log (id, date, msg) VALUES (83, '2020-10-13 21:37:54', 'Odczytano alarm: Problem w jednostce DOM. (IP: 192.168.0.60). Wystapil Alarm w strefach: 1 . Zródlo: DOM..');
INSERT INTO log (id, date, msg) VALUES (84, '2020-10-13 21:38:14', 'Wykryto zdarzenie w Komunikat: Autoryzacja. Tresc: Poprawnie nadano uprawnienia instalatorskie.');
INSERT INTO log (id, date, msg) VALUES (85, '2020-10-13 21:38:20', 'Wykryto zdarzenie w Komunikat: Skasowano alarmy. Tresc: Poprawnie zresetowano alarmy w strefach.');

#COMMIT TRANSACTION;
#PRAGMA foreign_keys = on;
