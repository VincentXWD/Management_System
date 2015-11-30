// opt.hpp
#pragma once
#include <fstream>
#include"lib/list"		//数据结构（双向链表）
#include "employee.h"	//类定义

enum OPT{ HEHE, MNG, TCH, SMG, SAM };

typedef class operate {
public:
	~operate();
	int devide();	//确定选择要更新的类
	void init();	//初始化他们的状态
	void quary();	//查询
	void insert();	//添加
	void remove();	//删除

	//插入操作系列
	void insertmng();
	void inserttch();
	void insertsmg();
	void insertsam();

	//删除操作系列：
	void removemng();
	void removetch();
	void removesmg();
	void removesam();

protected:
	//声明好用来维护四种人的数据结构
	kirai::list<Manager> manager;
	kirai::list<Technician> technician;
	kirai::list<Salesmanager> salesmanager;
	kirai::list<Salesman> salesman;
};

////声明好用来维护四种人的数据结构
//kirai::list<Manager> manager;
//kirai::list<Technician> technician;
//kirai::list<Salesmanager> salesmanager;
//kirai::list<Salesman> salesman;
//
//int devide();	//确定选择要更新的类
//void init();	//初始化他们的状态
//void quary();	//查询
//void insert();	//添加
//void remove();	//删除
//
////插入操作系列
//void insertmng();
//void inserttch();
//void insertsmg();
//void insertsam();
//
////删除操作系列：
//void removemng();
//void removetch();
//void removesmg();
//void removesam();

int operate::devide() {
	int sign;
	cout << "请选择您要对哪类人进行操作？" << endl;
	cout << "1：经理，2：兼职技术人员，3：销售经理，4：兼职推销员。" << endl;
	cin >> sign;
	return sign;
}

void operate::init() {	//初始化他们的状态
	manager.clear();
	technician.clear();
	salesmanager.clear();
	salesman.clear();
	ifstream input_ma("save\\manager.txt");
	ifstream input_tc("save\\technician.txt");
	ifstream input_sm("save\\salesmanager.txt");
	ifstream input_sa("save\\salesman.txt");
	string name, number;
	double time;
	while (input_ma >> name >> number) {
		manager.push_back(Manager(name, number));
	}
	while (input_tc >> name >> number >> time) {
		technician.push_back(Technician(name, number, time));
	}
	while (input_sm >> name >> number) {
		salesmanager.push_back(Salesmanager(name, number));
	}
	while (input_sa >> name >> number) {
		salesman.push_back(Salesman(name, number));
	}
	input_ma.close();
	input_tc.close();
	input_sm.close();
	input_sa.close();
}

operate::~operate() {
	//ofstream output_ma("save\\manager.txt", ios::out | ios::binary);
	//ofstream output_tc("save\\technician.txt", ios::out | ios::binary);
	//ofstream output_sm("save\\salesmanager.txt", ios::out | ios::binary);
	//ofstream output_sa("save\\salesman.txt", ios::out | ios::binary);
	//for (int i = 0; i < manager.size(); i++) {
	//	output_ma << manager[i].shownum() << " ";
	//}
	//for (int i = 0; i < technician.size(); i++) {

	//}
	//for (int i = 0; i < salesmanager.size(); i++) {

	//}
	//for (int i = 0; i < salesman.size(); i++) {

	//}
	//output_ma.close();
	//output_tc.close();
	//output_sm.close();
	//output_sa.close();
}

void operate::quary() {	//查询
	int sign = devide();
	switch (sign) {
	case 1:
		if (manager.empty()) {
			cout << "经理人数为空！请重新操作！" << endl;
			break;
		}
		for (int i = 0; i != manager.size(); i++) {
			manager[i].showsalary();
		}
		cout << endl;
		break;
	case 2:
		if (technician.empty()) {
			cout << "兼职技术人员人数为空！请重新操作！" << endl;
			break;
		}
		for (int i = 0; i != technician.size(); i++) {
			technician[i].showsalary();
		}
		cout << endl;
		break;
	case 3:
		if (salesmanager.empty()) {
			cout << "兼职推销员人数为空！请重新操作！" << endl;
			break;
		}
		for (int i = 0; i != salesmanager.size(); i++) {
			salesmanager[i].showsalary();
		}
		cout << endl;
		break;
	case 4:
		if (salesman.empty()) {
			cout << "销售经理人数为空！请重新操作！" << endl;
			break;
		}
		for (int i = 0; i != salesman.size(); i++) {
			salesman[i].showsalary();
			cout << endl;
		}
		cout << endl;
		break;
	default: cout << "您的输入有误，请重新输入 ！" << endl; break;
	}
	system("pause");
}

void operate::insert() {	//添加
	int sign = devide();
	switch (sign) {
	case MNG:
		insertmng();
		break;
	case TCH:
		inserttch();
		break;
	case SMG:
		insertsmg();
		break;
	case SAM:
		insertsam();
		break;
	default: cout << "您的输入有误，请重新输入 ！" << endl; break;
	}
	system("pause");
}

void operate::remove() {	//删除
	int sign = devide();
	switch (sign) {
	case MNG:
		removemng();
		break;
	case TCH:
		removetch();
		break;
	case SMG:
		removesmg();
		break;
	case SAM:
		removesam();
		break;
	default: cout << "您的输入有误，请重新输入 ！" << endl; break;
	}
	system("pause");
}

void operate::insertmng() {
	string name, num;
	cout << "请输入要添加的经理的姓名和编号" << endl;
	cin >> name >> num;
	Manager tmp(name, num);
	manager.push_back(tmp);
}

void operate::inserttch() {
	string name, num;
	double time;
	cout << "请输入要添加的兼职技术人员的姓名和编号以及工作时长" << endl;
	cin >> name >> num >> time;
	Technician tmp(name, num, time);
	technician.push_back(tmp);
}

void operate::insertsmg() {
	string name, num;
	cout << "请输入要添加的销售经理的姓名和编号" << endl;
	cin >> name >> num;
	Salesmanager tmp(name, num);
	salesmanager.push_back(tmp);
}

void operate::insertsam() {
	string name, num;
	double sold;
	cout << "请输入要添加的兼职推销员的姓名和编号以及当月销售额" << endl;
	cin >> name >> num >> sold;
	Salesman tmp(name, num, sold);
	salesman.push_back(tmp);
}

void operate::removemng() {
	string num;
	int del_flag = 0;
	cout << "请输入您要删除的经理的编号" << endl;
	cin >> num;
	for (int i = 0; i != manager.size(); i++) {
		if (manager[i].shownum() == num) {
			del_flag = manager.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！所删编号不存在！" << endl;
	}
}

void operate::removetch() {
	string num;
	int del_flag = 0;
	cout << "请输入您要删除的兼职技术人员的编号" << endl;
	cin >> num;
	for (int i = 0; i != technician.size(); i++) {
		if (technician[i].shownum() == num) {
			del_flag = technician.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！所删编号不存在！" << endl;
	}
}

void operate::removesmg() {
	string num;
	int del_flag = 0;
	cout << "请输入您要删除的销售经理的编号" << endl;
	cin >> num;
	for (int i = 0; i != salesmanager.size(); i++) {
		if (salesmanager[i].shownum() == num) {
			del_flag = salesmanager.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！所删编号不存在！" << endl;
	}
}

void operate::removesam() {
	string num;
	int del_flag = 0;
	cout << "请输入您要删除的兼职推销员的编号" << endl;
	cin >> num;
	for (int i = 0; i != salesman.size(); i++) {
		if (salesman[i].shownum() == num) {
			Salesman::subsold -= salesman[i].getsold();
			del_flag = salesman.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "删除成功！" << endl;
	}
	else {
		cout << "删除失败！所删编号不存在！" << endl;
	}
}
