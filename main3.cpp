#include "createTrl.h"

Command stringToCommand(const string& str) { // определение команд
	if (str == "exit") {
		return Command::EXIT;
	}
	else if (str == "create_trl") {
		return Command::CREATE_TRL;
	}
	else if (str == "trl_in_stop") {
		return Command::TRL_IN_STOP;
	}
	else if (str == "stops_in_trl") {
		return Command::STOPS_IN_TRL;
	}
	else if (str == "trls") {
		return Command::TRLS;
	}
	else {
		cout << "Неизвестная команда.\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	my_structure list; // структура списка 
	string command; // строка - команда
	vector<string> commands; // вектор слов строки - команды
	while (true) {
		cout << "Введите команду: ";
		getline(cin, command); // ввод с пробелами
		istringstream iss(command); // создание объекта, который используется для разбора строки - команды
		string word; 
		while (iss >> word) {
			commands.push_back(word); // заполняем вектор командами 
		}
		if (commands.empty()) { // проверка на пустой ввод
			continue;
		}
		vector<string> stops; // вектор для заданных остановок
		Command cmd = stringToCommand(commands[0]); // команда
		switch (cmd) {
		case Command::EXIT: 
			return 0;
		case Command::CREATE_TRL:
			for (int i = 2; i < commands.size(); i++) {
				stops.push_back(commands[i]); // заполнение вектора остановок
			}
			createTrl(list, commands[1], stops);
			break;
		case Command::TRLS:
			printTrls(list);
			break;
		case Command::TRL_IN_STOP:
			trlInStop(list, commands[1], " ");
			break;
		case Command::STOPS_IN_TRL:
			stopsInTrl(list, commands[1]);
			break;
		}
		commands.clear();
	}
	return 0;
}
