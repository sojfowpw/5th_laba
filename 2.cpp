#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>

using namespace std;
using my_structure = vector<pair<int, vector<string>>>; // псевдоним my_structure для типа структуры склада

string makeTalon(int i) { // функция для создания талона
	string it = to_string(i); // итератор, перевод в строку
	return "T" + it;
}

void funcEnqueue(my_structure& queue, string t, int N, string talon) { // функция заполнения очереди
	int time = stoi(t); // перевод из строки в инт
	int k = 0;
	for (int i = 0; i < N; i++) { // проверка на переполнение очереди
		if ((queue[i].first + time) > 10) { // предел - 10 минут
			k++;
		}
	}
	if (k == N) {
		cout << ">>> В очереди больше нет мест." << endl;
	}
	for (int i = 0; i < N; i++) {
		if ((queue[i].first + time) <= 10) {
			queue[i].second.push_back(talon); // заполнение вектора талонами
			queue[i].first += time;
			break;
		}
	}
}

void funcDistribute(const my_structure& queue) { // функция для вывода распределения
	int it = 1; // итератор для номера окна
	for (const auto& pair : queue) { // перебор пар
		cout << ">>> Окно " << it << " (" << pair.first << " минут): ";
		it++;
		for (const auto& str : pair.second) { // перебор талонов в окне
			cout << str << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	random_device rd;
	mt19937_64 random_(rd()); // подключение рандома
	cout << ">>> Введите кол-во окон" << endl << "<<< ";
	int N = 0; // количество окон
	int it = random_() % (900 - 100 + 1) + 100; // случайное значение номера для талона
	cin >> N;
	cin.ignore(); // удаление символа новой строки из потока для дальнейшего ввода
	string command; // строка для команды
	string talon; // талон
	vector<string> commands; // вектор для команды
	my_structure queue(N, make_pair(0, vector<string>())); // размер структуры очереди
	while (true) {
		cout << "<<< ";
		getline(cin, command); // ввод команды с пробелами
		istringstream iss(command); // создание объекта, который используется для разбора строки - команды
		string word;
		while (iss >> word) {
			commands.push_back(word); // заполняем вектор командами
		}
		if (commands[0] == "exit") {
			break;
		}
		else if (commands[0] == "enqueue") {
			string talon = makeTalon(it); // получение талона
			it++; // изменение номера талона на последующий
			cout << ">>> " << talon << endl;
			funcEnqueue(queue, commands[1], N, talon);
		}
		else if (commands[0] == "distribute") {
			funcDistribute(queue);
		}
		else { // проверка на корректность введённой команды
			cout << ">>> Некорректная команда." << endl;
		}
		commands.clear();
	}
	return 0;
}
