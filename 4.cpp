#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

enum class Command { // класс для хранения команд
    EXIT,
    NEW_STUDENTS,
    SUSPICIOUS,
    IMMORTAL,
    TOP_LIST,
    SCOUNT,
    PRNT
};

Command stringToCommand(const string& str) { // определение команд
    if (str == "exit") {
        return Command::EXIT;
    }
    else if (str == "new_students") {
        return Command::NEW_STUDENTS;
    }
    else if (str == "suspicious") {
        return Command::SUSPICIOUS;
    }
    else if (str == "immortal") {
        return Command::IMMORTAL;
    }
    else if (str == "top-list") {
        return Command::TOP_LIST;
    }
    else if (str == "scount") {
        return Command::SCOUNT;
    }
    else if (str == "print") {
        return Command::PRNT;
    }
    else {
        cout << ">>> Unknown command.\n";
    }
}

void newStudents(vector<int>& students, vector<int>& susstudents, vector<int>& immortalstudents, int& it, string quantity) { // добавление студентов
    int amount = stoi(quantity); // перевод из строки в инт
    vector<int> newstudents;
    if (amount > 0) { // если количество больше 0, добавляем студентов
        for (int i = 0; i < amount; i++) {
            students.push_back(it);
            it++; // номер студента
        }
        cout << ">>> Welcome " << amount << " clever students!\n";
    }
    else if (amount == 0) { // если количество равно 0, студенты не меняются
        cout << ">>> The number of students has not changed.\n";
    }
    else { // если количество меньше 0
        amount = -amount;
        if (amount > students.size()) { // проверка: если введённое количество больше количества студентов, выводим ошибку
            cout << ">>> The specified value is greater than the number of students.\n";
            return;
        }
        cout << ">>> GoodBye " << amount << " clever students!\n";
        while (amount > 0 && !susstudents.empty()) { // удаление студентов из списка на отчисление
            int n = susstudents.front(); // первый элемент в списке на отчисление
            susstudents.erase(susstudents.begin()); // отчисление студента
            students.erase(remove(students.begin(), students.end(), n)); // убираем студента из общего списка
            amount--; // уменьшаем количество
        }
        while (amount > 0) { // удаление студентов из общего списка, если список на отчисление пуст
            auto it = find(immortalstudents.begin(), immortalstudents.end(), students.front()); // если студента нет в списке бессмертного, пропускаем его
            if (it == immortalstudents.end()) {
                students.erase(students.begin()); // отчисление студента
                amount--; // уменьшаем количество
            }
            else {
                newstudents.push_back(students.front()); // заполняем вектор студентами, которых случайно отчислили
                students.erase(students.begin()); 
            }
        }
        for (auto& i : newstudents) {
            students.push_back(i);
        }
        sort(students.begin(), students.end());
    }
}

void susStudents(const vector<int>& students, vector<int>& susstudents, string n) { // добавление студента в список на отчисление
    int number = stoi(n); // перевод строки в инт
    auto it = find(students.begin(), students.end(), number); // итератор, указывающий на студента в общем списке
    if (it != students.end()) { // если такой студент найден, добавляем его в список на отчисление
        susstudents.push_back(*it);
        cout << ">>> The suspected student " << number << endl;
    }
    else { // иначе выводим ошибку: такого студента нет в общем списке
        cout << ">>> There is no such student.\n";
    }
}

void imStudents(vector<int>& susstudents, vector<int>& immortalstudents, string n, const vector<int>& students) { // добавление студентов в список бессмертных
    int number = stoi(n); // перевод строки в инт
    auto it = find(students.begin(), students.end(), number);
    if (it != students.end()) { // если студент есть в общем списке, добавляем его в список бессмертных
        immortalstudents.push_back(*it);
        susstudents.erase(remove(susstudents.begin(), susstudents.end(), number), susstudents.end()); // убираем его из списка на отчисление
        cout << ">>> Student " << number << " is immortal!\n";
    }
    else { // иначе выводим ошибку: такого студента нет в общем списке
        cout << ">>> There is no such student.\n";
    }
}

void topList(const vector<int>& susstudents) { // вывод списка на отчисление
    if (susstudents.empty()) { // список не должен быть пустым
        cout << ">>> The list is empty.\n";
        return;
    }
    set<int> sortlist(susstudents.begin(), susstudents.end()); // сортируем список
    cout << ">>> List of students for expulsion: ";
    for (auto& person : sortlist) { // выводим список
        cout << "Student " << person << " ";
    }
    cout << endl;
}

void countSus(const vector<int>& susstudents) { // вывод количества студентов в списке на отчисление
    if (susstudents.empty()) {
        cout << ">>> The list is empty.\n"; // список не должен быть пустым
        return;
    }
    cout << ">>> List of students for expulsion consists of " << susstudents.size() << " students.\n";
}

void prnt(const vector<int>& students, const vector<int>& susstudents, const vector<int>& immortalstudents) { // вывод всех списков
    auto printVector = [](const vector<int>& v) { // лямбда-функция дял каждого вектора
        for (auto& person : v) {
            cout << person << " ";
        }
        cout << endl;
        };
    cout << ">>> Students: ";
    printVector(students);
    cout << ">>> Suspicious students: ";
    printVector(susstudents);
    cout << ">>> Immortal students: ";
    printVector(immortalstudents);
}

int main() {
    vector<int> students; // общий список студентов
    vector<int> susstudents; // список на отчисление
    vector<int> immortalstudents; // список бессмертных
    int it = 1; // номер студента
    string command; // строка - команда
    vector<string> commands; // вектор слов строки - команды
    while (true) {
        cout << "<<< ";
        getline(cin, command); // ввод с пробелами 
        istringstream iss(command); // создание объекта, который используется для разбора строки - команды
        string word;
        while (iss >> word) {
            commands.push_back(word); // заполняем вектор командами 
        }
        if (commands.empty()) { // проверка на пустой ввод
            continue;
        }
        Command cmd = stringToCommand(commands[0]); // команда
        switch (cmd) {
        case Command::EXIT:
            return 0;
        case Command::NEW_STUDENTS:
            if (commands.size() == 2) { // проверка на корректность введённой программы
                newStudents(students, susstudents, immortalstudents, it, commands[1]);
            }
            else {
                cout << ">>> Invalid number of arguments for new_students command.\n";
            }
            break;
        case Command::SUSPICIOUS:
            if (commands.size() == 2) { // проверка на корректность введённой программы
                susStudents(students, susstudents, commands[1]);
            }
            else {
                cout << ">>> Invalid number of arguments for suspicious command.\n";
            }
            break;
        case Command::IMMORTAL:
            if (commands.size() == 2) { // проверка на корректность введённой программы
                imStudents(susstudents, immortalstudents, commands[1], students);
            }
            else {
                cout << ">>> Invalid number of arguments for immortal command.\n";
            }
            break;
        case Command::TOP_LIST:
            topList(susstudents);
            break;
        case Command::SCOUNT:
            countSus(susstudents);
            break;
        case Command::PRNT:
            prnt(students, susstudents, immortalstudents);
        }
        commands.clear();
    }
    return 0;
}
