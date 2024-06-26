# Учёт товаров на складе
Все ячейки на складе имеют свои адреса (например А1739), адрес состоит из следующих обозначений: 1) А, Б, В - зона хранения - теплый, холодный склад или часть склада; 2) 17 - порядковый номер стеллажа; 3) 3 - порядковый номер вертикальной секции стеллажа; 4) 9 - порядковый номер полки. В каждую ячейку помещается не более 10 единиц товара. Программа позволяет добавлять товары в ячейки, просматривать состояние склада, убирать товар из ячейки.

Для добавления товара в ячейка использовать команду ADD <наименование товара> <количество> <адрес ячейки>. Пример: ADD Апельсины 8 А1739.
Для удаления товара из ячейки использовать команду REMOVE <наименование товара> <количество> <адрес ячейки>. Пример: REMOVE Апельсины 8 А1739. 
Для получения информации о состоянии склада использовать команду INFO. 
# Реализация электронной очереди
На вход в программу подается кол-во окон способных обрабатывать очередь посетителей. Далее с использованием команды ENQUEUE посетители добавляются в очередь, команда принимает продолжительность посещения и выдает номер талона. После того как введено нужное количество посетителей вводится команда DISTRIBUTE. Программа выводит распределение очереди посетителей на все окна, распределение такое, чтобы обработать очередь максимально быстро. 

Пример работы программы:
“>>>” – вывод данных
“<<<” - ввод данных
>>> Введите кол-во окон
<<< 2
<<< ENQUEUE 5
>>> T764
<<< ENQUEUE 10
>>> T047
<<< ENQUEUE 5
>>> T903
<<< DISTRIBUTE
>>> Окно 1 (10 минут): T764, T903
>>> Окно 2 (10 минут): T047
# График движения троллейбусов
CREATE_TRL trl stop1 …. Stopn - Создание троллейбуса с именем trl, который проходит через остановки
TRL_IN_STOP stop - Вывод всех троллейбусов, которые проходят через конкретную остановку
STOPS_IN_TRL trl - Вывод всех остановок, которые проезжает троллейбус с именем trl. Для каждой остановки прописать, какие троллейбусы идут через эту остановку (не включая trl)
TRLS - Отобразить все троллейбусы с указанием остановок
# Управление списками студентов
Будем считать, что студенты находятся в списке учащихся, и ежегодно данный список пополняется. Причем новые студенты попадают в конец списка всегда. В зависимости от ситуации в долгами, некоторые студенты могут быть кандидатами на отчисления. Но при ликвидации задолженностей могут и уйти из списка на отчисление.
NEW_STUDENTS number - Добавить в конец очереди студентов в количестве number
SUSPICIOUS number_student - Студент с порядковым номером number_student является крайне подозрительным и входит в топ-лист на отчисление
IMMORTAL number_student - Студент с порядковым номером number_student является неприкасаемым и из топ-листа на отчисление уходит. Такого студента никто и ничто не может отчислить
TOP-LIST - Вывод отсортированного списка студентов, входящих в топ-лист на отчисление
SCOUNT - Вывод количества студентов, входящих в топ-лист на отчисление
