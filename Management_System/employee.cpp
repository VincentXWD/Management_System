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
	cout << "��ţ�" << number.c_str() << " ������" << name.c_str() << " ְ�ƣ�����" 
		<< " ��н��" << salary << "Ԫ" << endl;
}

void Manager::input(string name, string number) {
	this->name = name;
	this->number = number;
	cout << "�޸ĳɹ�����ǰ��ϢΪ��" << endl;
	showsalary();
}

Manager Manager::operator = (const Manager& m) {
	this->name = m.name;
	this->number = m.number;
	return *this;
}



void Technician::showsalary() {
	salary = time * 100;
	cout << "��ţ�" << number.c_str() << " ������" << name.c_str() << " ְ�ƣ���ְ������Ա" 
		<< " ����ʱ����" << time << "Сʱ ��н��" << salary << "Ԫ" << endl;
}

void Technician::input(string name, string number, int time) {
	this->name = name;
	this->number = number;
	this->time = time;
	cout << "�޸ĳɹ�����ǰ��ϢΪ��" << endl;
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
	cout << "��ţ�" << number.c_str() << " ������" << name.c_str() << " ְ�ƣ���ְ����Ա" 
		<< "�����۶" << sold << " ��н��" << salary << "Ԫ" << endl;
}

void Salesman::input(string name, string number, double sold) {
	this->name = name;
	this->number = number;
	this->sold = sold;
	subsold += sold;
	cout << "�޸ĳɹ�����ǰ��ϢΪ��" << endl;
	showsalary();
}

Salesman Salesman::operator = (const Salesman& s) {
	this->name = s.name;
	this->number = s.number;
	this->sold = s.sold;
	this->subsold += s.sold;	//���¾�̬����
	return *this;
}



void Salesmanager::showsalary() {
	salary = subsold * ratio + monthpay;
	cout << "��ţ�" << number.c_str() << " ������" << name.c_str() << " ְ�ƣ����۾���" 
		<< " ���۲����������۶" << subsold << " ��н��" << salary << "Ԫ" << endl;
}

void Salesmanager::input(string name, string number) {
	this->name = name;
	this->number = number;
	cout << "�޸ĳɹ�����ǰ��ϢΪ��" << endl;
	showsalary();
}

Salesmanager Salesmanager::operator = (const Salesmanager& s) {
	this->name = s.name;
	this->number = s.number;
	return *this;
}