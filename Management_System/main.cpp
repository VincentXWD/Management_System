// main.cpp
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <conio.h>
#include "opt.hpp"		//操作集

using namespace std;

int main() {
	bool exit_flag = false;
	int sign;
	while (1) {
		if (exit_flag) {
			exit(EXIT_SUCCESS);
		}
		cout << "欢迎进入小型公司人员信息管理系统，请选择您要进行的操作：" << endl;
		cout << "1：查询，2：添加，3：删除，4：退出" << endl;
		cin >> sign;
		switch(sign) {
		case 1:	quary(); break;
		case 2:	insert(); break;
		case 3: remove(); break;
		case 4: exit_flag = 1; break;
		default: cout << "您的输入有误，请重新输入 ！" << endl; break;
		}
		system("cls");
	}
}
