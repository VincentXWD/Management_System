// opt.hpp
#pragma once
#include <fstream>
#include"lib/list"		//���ݽṹ��˫������
#include "employee.h"	//�ඨ��

enum OPT{ HEHE, MNG, TCH, SMG, SAM };

typedef class operate {
public:
	~operate();
	int devide();	//ȷ��ѡ��Ҫ���µ���
	void init();	//��ʼ�����ǵ�״̬
	void quary();	//��ѯ
	void insert();	//���
	void remove();	//ɾ��

	//�������ϵ��
	void insertmng();
	void inserttch();
	void insertsmg();
	void insertsam();

	//ɾ������ϵ�У�
	void removemng();
	void removetch();
	void removesmg();
	void removesam();

protected:
	//����������ά�������˵����ݽṹ
	kirai::list<Manager> manager;
	kirai::list<Technician> technician;
	kirai::list<Salesmanager> salesmanager;
	kirai::list<Salesman> salesman;
};

////����������ά�������˵����ݽṹ
//kirai::list<Manager> manager;
//kirai::list<Technician> technician;
//kirai::list<Salesmanager> salesmanager;
//kirai::list<Salesman> salesman;
//
//int devide();	//ȷ��ѡ��Ҫ���µ���
//void init();	//��ʼ�����ǵ�״̬
//void quary();	//��ѯ
//void insert();	//���
//void remove();	//ɾ��
//
////�������ϵ��
//void insertmng();
//void inserttch();
//void insertsmg();
//void insertsam();
//
////ɾ������ϵ�У�
//void removemng();
//void removetch();
//void removesmg();
//void removesam();

int operate::devide() {
	int sign;
	cout << "��ѡ����Ҫ�������˽��в�����" << endl;
	cout << "1������2����ְ������Ա��3�����۾���4����ְ����Ա��" << endl;
	cin >> sign;
	return sign;
}

void operate::init() {	//��ʼ�����ǵ�״̬
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

void operate::quary() {	//��ѯ
	int sign = devide();
	switch (sign) {
	case 1:
		if (manager.empty()) {
			cout << "��������Ϊ�գ������²�����" << endl;
			break;
		}
		for (int i = 0; i != manager.size(); i++) {
			manager[i].showsalary();
		}
		cout << endl;
		break;
	case 2:
		if (technician.empty()) {
			cout << "��ְ������Ա����Ϊ�գ������²�����" << endl;
			break;
		}
		for (int i = 0; i != technician.size(); i++) {
			technician[i].showsalary();
		}
		cout << endl;
		break;
	case 3:
		if (salesmanager.empty()) {
			cout << "��ְ����Ա����Ϊ�գ������²�����" << endl;
			break;
		}
		for (int i = 0; i != salesmanager.size(); i++) {
			salesmanager[i].showsalary();
		}
		cout << endl;
		break;
	case 4:
		if (salesman.empty()) {
			cout << "���۾�������Ϊ�գ������²�����" << endl;
			break;
		}
		for (int i = 0; i != salesman.size(); i++) {
			salesman[i].showsalary();
			cout << endl;
		}
		cout << endl;
		break;
	default: cout << "���������������������� ��" << endl; break;
	}
	system("pause");
}

void operate::insert() {	//���
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
	default: cout << "���������������������� ��" << endl; break;
	}
	system("pause");
}

void operate::remove() {	//ɾ��
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
	default: cout << "���������������������� ��" << endl; break;
	}
	system("pause");
}

void operate::insertmng() {
	string name, num;
	cout << "������Ҫ��ӵľ���������ͱ��" << endl;
	cin >> name >> num;
	Manager tmp(name, num);
	manager.push_back(tmp);
}

void operate::inserttch() {
	string name, num;
	double time;
	cout << "������Ҫ��ӵļ�ְ������Ա�������ͱ���Լ�����ʱ��" << endl;
	cin >> name >> num >> time;
	Technician tmp(name, num, time);
	technician.push_back(tmp);
}

void operate::insertsmg() {
	string name, num;
	cout << "������Ҫ��ӵ����۾���������ͱ��" << endl;
	cin >> name >> num;
	Salesmanager tmp(name, num);
	salesmanager.push_back(tmp);
}

void operate::insertsam() {
	string name, num;
	double sold;
	cout << "������Ҫ��ӵļ�ְ����Ա�������ͱ���Լ��������۶�" << endl;
	cin >> name >> num >> sold;
	Salesman tmp(name, num, sold);
	salesman.push_back(tmp);
}

void operate::removemng() {
	string num;
	int del_flag = 0;
	cout << "��������Ҫɾ���ľ���ı��" << endl;
	cin >> num;
	for (int i = 0; i != manager.size(); i++) {
		if (manager[i].shownum() == num) {
			del_flag = manager.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ���ɾ��Ų����ڣ�" << endl;
	}
}

void operate::removetch() {
	string num;
	int del_flag = 0;
	cout << "��������Ҫɾ���ļ�ְ������Ա�ı��" << endl;
	cin >> num;
	for (int i = 0; i != technician.size(); i++) {
		if (technician[i].shownum() == num) {
			del_flag = technician.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ���ɾ��Ų����ڣ�" << endl;
	}
}

void operate::removesmg() {
	string num;
	int del_flag = 0;
	cout << "��������Ҫɾ�������۾���ı��" << endl;
	cin >> num;
	for (int i = 0; i != salesmanager.size(); i++) {
		if (salesmanager[i].shownum() == num) {
			del_flag = salesmanager.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ���ɾ��Ų����ڣ�" << endl;
	}
}

void operate::removesam() {
	string num;
	int del_flag = 0;
	cout << "��������Ҫɾ���ļ�ְ����Ա�ı��" << endl;
	cin >> num;
	for (int i = 0; i != salesman.size(); i++) {
		if (salesman[i].shownum() == num) {
			Salesman::subsold -= salesman[i].getsold();
			del_flag = salesman.remove(i);
			break;
		}
	}
	if (del_flag) {
		cout << "ɾ���ɹ���" << endl;
	}
	else {
		cout << "ɾ��ʧ�ܣ���ɾ��Ų����ڣ�" << endl;
	}
}
