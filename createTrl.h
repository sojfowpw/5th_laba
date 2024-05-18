#pragma once // предотвращение многократного включения заголовочного файла 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;
using my_structure = vector<pair<string, vector<string>>>; // псевдоним для структуры списка

enum class Command { // класс для хранения программ
	EXIT,
	CREATE_TRL,
	TRL_IN_STOP,
	STOPS_IN_TRL,
	TRLS
};

void createTrl(my_structure& list, string name, const vector<string>& stops); // функция создать троллейбус
void trlInStop(const my_structure& list, string stop, string trl); // троллейбусы по конкретной остановке
void stopsInTrl(const my_structure& list, string trl); // остановки конкретного троллейбуса
void printTrls(const my_structure& list); // вывод всех троллейбусов с маршрутами