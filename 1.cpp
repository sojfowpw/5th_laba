#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;
using my_structure = vector<vector<vector<pair<string, int>>>>; // псевдоним my_structure для типа структуры склада

void funcAdd(my_structure& vec, string product, string amount, string place) { // фукнция добавить товар
	place.erase(0, 1); // убираем зону
	int placement = stoi(place); // перевод строки в интовое значение, адрес ячейки 
	int amnt = stoi(amount); // количество товара
	int i = placement / 100 - 1; // адрес стеллажа
	int j = placement / 10 % 10 - 1; // адрес секции
	int k = placement % 10 - 1; // адрес полки
	if (i >= 0 && i < 10 && j >= 0 && j < 7 && k >= 0 && k < 4) { // проверка на правильность адреса
		if ((vec[i][j][k].second + amnt) <= 10) { // проверка на количества товара на полке
			if (vec[i][j][k].first == "0" || vec[i][j][k].first == product) { // если полка пуста или там лежит тот же товар
				vec[i][j][k].first = product;
				vec[i][j][k].second += amnt;
			}
			else {
				cout << "В ячейке уже лежит другой товар: " << vec[i][j][k].first << endl;
			}
		}
		else {
			cout << "Ячейка переполнена.\n";
		}
	}
	else {
		cout << "Такой ячейки не существует.\n";
	}
}

void funcRemove(my_structure& vec, string product, string amount, string place) { // функция удалить товар
	place.erase(0, 1); // убираем зону
	int placement = stoi(place); // перевод строки в интовое значение, адрес ячейки
	int amnt = stoi(amount); // количество товара
	int i = placement / 100 - 1; // адрес стеллажа
	int j = placement / 10 % 10 - 1; // адрес секции
	int k = placement % 10 - 1; // адрес полки
	if (i >= 0 && i < 10 && j >= 0 && j < 7 && k >= 0 && k < 4) { // проверка на правильность адреса
		if ((vec[i][j][k].second - amnt) >= 0) { // проверка на количество товара на полке
			if (vec[i][j][k].first == product) { // проверка: именно этот товар находится на полке
				vec[i][j][k].second -= amnt;
				if (vec[i][j][k].second == 0) { // если количество = 0, обнуляем название товара
					vec[i][j][k].first = "0";
				}
			}
			else {
				cout << "В ячейке лежит другой товар: " << vec[i][j][k].first << endl;
			}
		}
		else {
			cout << "В ячейке слишком мало товара.\n";
		}
	}
	else {
		cout << "Такой ячейки не существует.\n";
	}
}

void funcInfo(const my_structure& vec) { // функция информация о складе
	double sum = 0.0; // количество всех товаров
	double racks = 0.0; // количество товаров в каждом стеллаже
	int it = 0;
	for (auto& shelf : vec) {
		racks = 0.0;
		it++;
		for (auto& row : shelf) {
			for (auto& cell : row) {
				sum += cell.second;
				racks += cell.second;
			}
		}
		cout << it + 1 << " стеллаж заполнен на " << fixed << setprecision(2) << racks / 280 * 100 << "%.\n";
	}
	cout << "Склад заполнен на " << fixed << setprecision(2) << sum / 2800 * 100 << "%.\n";
	for (int i = 0; i < 10; i++) { // вывод заполненных ячеек
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 4; k++) {
				if (vec[i][j][k].second != 0) {
					cout << "Ячейка а" << i + 1 << j + 1 << k + 1 << ": " << vec[i][j][k].first << " " << vec[i][j][k].second << endl;
				}
			}
		}
	}
	cout << "Адреса пустых ячеек: ";
	for (int i = 0; i < 10; i++) { // вывод пустых ячеек
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 4; k++) {
				if (vec[i][j][k].second == 0) {
					cout << "a" << i + 1 << j + 1 << k + 1 << "  ";
				}
			}
		}
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	my_structure vec(10, vector<vector<pair<string, int>>>(7, vector<pair<string, int>>(4))); // размер структуры склада
	string command; // команда
	vector<string> commands; // вектор для слов команды
	for (auto& shelf : vec) {
		for (auto& row : shelf) {
			for (auto& cell : row) {
				cell.first = "0"; // заполнение структуры нулями
				cell.second = 0;
			}
		}
	}
	while (true) {
		cout << "Введите комманду (add, remove, info, exit): ";
		getline(cin, command); // ввод команды – строки с пробелами
		istringstream iss(command); // создание объекта, который используется для разбора строки - команды
		string word;
		while (iss >> word) {
			commands.push_back(word); // заполняем вектор командами 
		}
		if (commands[0] == "exit") {
			break;
		}
		else if (commands[0] == "add") {
			if (stoi(commands[2]) != 0) { // проверка на 0
				funcAdd(vec, commands[1], commands[2], commands[3]);
			}
			else {
				cout << "Вы не можете добавить 0 товаров.\n";
			}
		}
		else if (commands[0] == "remove") {
			if (stoi(commands[2]) != 0) { // проверка на 0
				funcRemove(vec, commands[1], commands[2], commands[3]);
			}
			else {
				cout << "Вы не можете убрать 0 товаров.\n";
			}
		}
		else if (commands[0] == "info") {
			funcInfo(vec);
		}
		else {
			cout << "Некорректная программа.\n";
		}
		commands.clear();
	}
	return 0;
}
