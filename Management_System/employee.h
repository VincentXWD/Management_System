#pragma once
#include <iostream>

using namespace std;

typedef class employee {	//�����Ա����
public:
	employee() = default;
	~employee() = default;
	employee(string, string);
	void showsalary();	//��ʾнˮ
	void input(string, string);	//¼����Ϣ
	string shownum(){ return number; }
protected:
	const int level = 0;//����
	string name;		//����
	string number;		//���
	double salary;		//��н
}employee;

typedef class business : public employee {	//�����ְ��Ա�࣬�̳���employee�࣬��һ��������ʱ�䡱�����ԡ�
public:
	business(){ time = 0; };
	business(string, string, double);
	~business() = default;

protected:
	const int level = -1;
	double time;
}business;

typedef class Manager : public employee {	//���徭���࣬�޹ع���ʱ�������̳���employee
public:
	Manager(){};
	Manager(string name, string number) : employee(name, number){}
	void showsalary();	//��ʾнˮ
	void input(string, string);	//¼����Ϣ
	Manager operator = (const Manager&);
protected:
	const int monthpay = 8000;	//ÿ�¹̶�������Ϊ8000
	const int level = 1;
}Manager;

typedef class Technician : public business {	//��ְ������Ա
public:
	Technician(){};
	Technician(string name, string number, double time) : business(name, number, time) {}
	void showsalary();	//��ʾнˮ
	void input(string, string, int);	//¼����Ϣ
	Technician operator = (const Technician&);

protected:
	const int hourpay = 100;
	const int level = 2;
}Technician;

typedef class Salesman : public employee {	//����Ա��нˮ��ʱ���޹أ���ΪҪ���۾���Ĳ�������������Ա������Ҫ�̳������۾����࣬�Ա���������۶�
public:
	Salesman() {}
	Salesman(string name, string number, double s) : employee(name, number), sold(s) {}
	Salesman(string name, string number) : employee(name, number) {}
	void showsalary();	//��ʾнˮ
	void input(string, string, double);	//¼����Ϣ
	Salesman operator = (const Salesman&);

protected:
	const double ratio = 0.04;	//��������Ա��н�����۶�ı���
	const int level = 4;
	double sold;	//�������۶�
	static double subsold;	//���沿��������Ա�������۶�
}Salesman;

typedef class Salesmanager : public Salesman {	//���۾����࣬нˮ��ʱ���޹�
public:
	Salesmanager() {}
	Salesmanager(string name, string number) : Salesman(name, number) {}
	void showsalary();	//��ʾнˮ
	void input(string, string);	//¼����Ϣ
	Salesmanager operator = (const Salesmanager&);

protected:
	const int monthpay = 5000;
	const int level = 3;
	const double ratio = 0.05;
}Salesmanager;
