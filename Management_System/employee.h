#pragma once
#include <iostream>

using namespace std;

typedef class employee {	//定义雇员基类
public:
	employee() = default;
	~employee() = default;
	employee(string, string);
	void showsalary();	//显示薪水
	void input(string, string);	//录入信息
	string shownum(){ return number; }
protected:
	const int level = 0;//级别
	string name;		//姓名
	string number;		//编号
	double salary;		//月薪
}employee;

typedef class business : public employee {	//定义兼职人员类，继承于employee类，多一个“工作时间”的属性。
public:
	business(){ time = 0; };
	business(string, string, double);
	~business() = default;

protected:
	const int level = -1;
	double time;
}business;

typedef class Manager : public employee {	//定义经理类，无关工作时间数，继承于employee
public:
	Manager(){};
	Manager(string name, string number) : employee(name, number){}
	void showsalary();	//显示薪水
	void input(string, string);	//录入信息
	Manager operator = (const Manager&);
protected:
	const int monthpay = 8000;	//每月固定的收入为8000
	const int level = 1;
}Manager;

typedef class Technician : public business {	//兼职技术人员
public:
	Technician(){};
	Technician(string name, string number, double time) : business(name, number, time) {}
	void showsalary();	//显示薪水
	void input(string, string, int);	//录入信息
	Technician operator = (const Technician&);

protected:
	const int hourpay = 100;
	const int level = 2;
}Technician;

typedef class Salesman : public employee {	//推销员的薪水与时间无关，因为要销售经理的部门内有销售人员，所以要继承于销售经理类，以便更新总销售额
public:
	Salesman() {}
	Salesman(string name, string number, double s) : employee(name, number), sold(s) {}
	Salesman(string name, string number) : employee(name, number) {}
	void showsalary();	//显示薪水
	void input(string, string, double);	//录入信息
	Salesman operator = (const Salesman&);

protected:
	const double ratio = 0.04;	//设置推销员月薪与销售额的比率
	const int level = 4;
	double sold;	//当月销售额
	static double subsold;	//保存部门内推销员的总销售额
}Salesman;

typedef class Salesmanager : public Salesman {	//销售经理类，薪水与时间无关
public:
	Salesmanager() {}
	Salesmanager(string name, string number) : Salesman(name, number) {}
	void showsalary();	//显示薪水
	void input(string, string);	//录入信息
	Salesmanager operator = (const Salesmanager&);

protected:
	const int monthpay = 5000;
	const int level = 3;
	const double ratio = 0.05;
}Salesmanager;
