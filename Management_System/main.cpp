// main.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <conio.h>
#include "opt.hpp"		//������

using namespace std;

int main() {
	bool exit_flag = false;
	int sign;
	while (1) {
		if (exit_flag) {
			exit(EXIT_SUCCESS);
		}
		cout << "��ӭ����С�͹�˾��Ա��Ϣ����ϵͳ����ѡ����Ҫ���еĲ�����" << endl;
		cout << "1����ѯ��2����ӣ�3��ɾ����4���˳�" << endl;
		cin >> sign;
		switch(sign) {
		case 1:	quary(); break;
		case 2:	insert(); break;
		case 3: remove(); break;
		case 4: exit_flag = 1; break;
		default: cout << "���������������������� ��" << endl; break;
		}
		system("cls");
	}
}
