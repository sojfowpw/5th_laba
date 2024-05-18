#include "createTrl.h" // ����������� ������������� �����

void createTrl(my_structure& list, string name, const vector<string>& stops) { // ������� ������� ����������
	if (stops.size() <= 1) { // �������� �� ���������� ���������
		cout << "� ����������� ������ ���� ������ ����� ���������.\n";
		return;
	}
	if (set<string>(stops.begin(), stops.end()).size() != stops.size()) { // �������� �� ���������� ���������
		cout << "��������� �� ����� �����������.\n";
		return;
	}
	for (auto& route : list) {
		if (route.first == name) { // �������� �� ���������� �����������
			cout << "����� ���������� ��� ����������.\n";
			return;
		}
	}
	list.push_back({ name, stops }); // ���������� ����: ���������� � ������ ��� ���������
}

void trlInStop(const my_structure& list, string stop, string trl) { // �����������, ���������� ����� �������� ���������
	cout << "�����������, ������� �������� ����� ��������� " << stop << ": ";
	for (auto& route : list) { 
		if (find(route.second.begin(), route.second.end(), stop) != route.second.end()) { // ���� ��������� ���� � ������� ���������
			if (route.first != trl) { // ���������� ���������� ����������� ��� ������� ������ ��������� ��������� �������
				cout << route.first << " ";
			}
		}
	}
	cout << endl;
}

void stopsInTrl(const my_structure& list, string trl) { // ��������� ��������� �����������
	cout << "���������� " << trl << " ��������� ���������: ";
	vector<string> stops; // ������ ��� ���������
	for (auto& route : list) {
		if (route.first == trl) {
			for (auto& stop : route.second) {
				cout << stop << " "; // ����� ���������
				stops.push_back(stop); // ���������� ������� �����������
			}
		}
	}
	cout << endl;
	for (auto& stop : stops) {
		trlInStop(list, stop, trl); // ������ ��� ������ ��������� ������ ������������
	}
}

void printTrls(const my_structure& list) { // ����� ���� ������������ � �� ���������
	for (auto& route : list) {
		cout << "�������: " << route.first << endl << "���������: ";
		for (auto& stop : route.second) {
			cout << stop << " ";
		}
		cout << endl;
	}
}