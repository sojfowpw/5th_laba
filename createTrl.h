#pragma once // �������������� ������������� ��������� ������������� ����� 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;
using my_structure = vector<pair<string, vector<string>>>; // ��������� ��� ��������� ������

enum class Command { // ����� ��� �������� ��������
	EXIT,
	CREATE_TRL,
	TRL_IN_STOP,
	STOPS_IN_TRL,
	TRLS
};

void createTrl(my_structure& list, string name, const vector<string>& stops); // ������� ������� ����������
void trlInStop(const my_structure& list, string stop, string trl); // ����������� �� ���������� ���������
void stopsInTrl(const my_structure& list, string trl); // ��������� ����������� �����������
void printTrls(const my_structure& list); // ����� ���� ������������ � ����������