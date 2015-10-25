// employee.cpp
#include "employee.h"

employee::employee(string name, string number) {
	this->name = name;
	this->number = number;
}

business::business(string name, string number, double time) {
	this->name = name;
	this->number = number;
	this->time = time;
}



void Manager::showsalary() {
	salary = monthpay;
	cout << "编号：" << number.c_str() << " 姓名：" << name.c_str() << " 职称：经理" 
		<< " 月薪：" << salary << "元" << endl;
}

void Manager::input(string name, string number) {
	this->name = name;
	this->number = number;
	cout << "修改成功！当前信息为：" << endl;
	showsalary();
}

Manager Manager::operator = (const Manager& m) {
	this->name = m.name;
	this->number = m.number;
	return *this;
}



void Technician::showsalary() {
	salary = time * 100;
	cout << "编号：" << number.c_str() << " 姓名：" << name.c_str() << " 职称：兼职技术人员" 
		<< " 工作时长：" << time << "小时 月薪：" << salary << "元" << endl;
}

void Technician::input(string name, string number, int time) {
	this->name = name;
	this->number = number;
	this->time = time;
	cout << "修改成功！当前信息为：" << endl;
	showsalary();
}

Technician Technician::operator = (const Technician& t) {
	this->name = t.name;
	this->number = t.number;
	this->time = t.time;
	return *this;
}



double Salesman::subsold = 0;

void Salesman::showsalary() {
	salary = sold * ratio;
	cout << "编号：" << number.c_str() << " 姓名：" << name.c_str() << " 职称：兼职推销员" 
		<< "月销售额：" << sold << " 月薪：" << salary << "元" << endl;
}

void Salesman::input(string name, string number, double sold) {
	this->name = name;
	this->number = number;
	this->sold = sold;
	subsold += sold;
	cout << "修改成功！当前信息为：" << endl;
	showsalary();
}

Salesman Salesman::operator = (const Salesman& s) {
	this->name = s.name;
	this->number = s.number;
	this->sold = s.sold;
	this->subsold += s.sold;	//更新静态变量
	return *this;
}



void Salesmanager::showsalary() {
	salary = subsold * ratio + monthpay;
	cout << "编号：" << number.c_str() << " 姓名：" << name.c_str() << " 职称：销售经理" 
		<< " 销售部门总月销售额：" << subsold << " 月薪：" << salary << "元" << endl;
}

void Salesmanager::input(string name, string number) {
	this->name = name;
	this->number = number;
	cout << "修改成功！当前信息为：" << endl;
	showsalary();
}

Salesmanager Salesmanager::operator = (const Salesmanager& s) {
	this->name = s.name;
	this->number = s.number;
	return *this;
}