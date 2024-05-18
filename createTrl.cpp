#include "createTrl.h" // подключение заголовочного файла

void createTrl(my_structure& list, string name, const vector<string>& stops) { // функция создать троллейбус
	if (stops.size() <= 1) { // проверка на количество остановок
		cout << "У троллейбуса должно быть больше одной остановки.\n";
		return;
	}
	if (set<string>(stops.begin(), stops.end()).size() != stops.size()) { // проверка на повторение остановок
		cout << "Остановки не могут повторяться.\n";
		return;
	}
	for (auto& route : list) {
		if (route.first == name) { // проверка на повторение троллейбуса
			cout << "Такой троллейбус уже существует.\n";
			return;
		}
	}
	list.push_back({ name, stops }); // заполнение пары: троллейбус и вектор его маршрутов
}

void trlInStop(const my_structure& list, string stop, string trl) { // троллейбусы, проходящие через заданную остановку
	cout << "Троллейбусы, которые проходят через остановку " << stop << ": ";
	for (auto& route : list) { 
		if (find(route.second.begin(), route.second.end(), stop) != route.second.end()) { // если остановка есть в векторе остановок
			if (route.first != trl) { // исключение повторения троллейбуса для функции вывода остановок заданного трамвая
				cout << route.first << " ";
			}
		}
	}
	cout << endl;
}

void stopsInTrl(const my_structure& list, string trl) { // остановки заданного троллейбуса
	cout << "Троллейбус " << trl << " проезжает остановки: ";
	vector<string> stops; // вектор для остановок
	for (auto& route : list) {
		if (route.first == trl) {
			for (auto& stop : route.second) {
				cout << stop << " "; // вывод остановок
				stops.push_back(stop); // заполнение вектора остановками
			}
		}
	}
	cout << endl;
	for (auto& stop : stops) {
		trlInStop(list, stop, trl); // вывыод для каждой остановки списка троллейбусов
	}
}

void printTrls(const my_structure& list) { // вывод всех троллейбусов и их маршрутов
	for (auto& route : list) {
		cout << "Маршрут: " << route.first << endl << "Остановки: ";
		for (auto& stop : route.second) {
			cout << stop << " ";
		}
		cout << endl;
	}
}