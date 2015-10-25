// opt.hpp
#pragma once
#include"lib/list"		//���ݽṹ��˫������
#include "employee.h"	//�ඨ��

enum OPT{ HEHE, MNG, TCH, SMG, SAM };

//����������ά�������˵����ݽṹ
kirai::list<Manager> manager;
kirai::list<Technician> technician;
kirai::list<Salesmanager> salesmanager;
kirai::list<Salesman> salesman;

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

int devide() {
	int sign;
	cout << "��ѡ����Ҫ�������˽��в�����" << endl;
	cout << "1������2����ְ������Ա��3�����۾���4����ְ����Ա��" << endl;
	cin >> sign;
	return sign;
}

void init() {	//��ʼ�����ǵ�״̬
	manager.clear();
	technician.clear();
	salesmanager.clear();
	salesman.clear();
}

void quary() {	//��ѯ
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

void insert() {	//���
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

void remove() {	//ɾ��
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

void insertmng() {
	string name, num;
	cout << "������Ҫ��ӵľ���������ͱ��" << endl;
	cin >> name >> num;
	Manager tmp(name, num);
	manager.push_back(tmp);
}

void inserttch() {
	string name, num;
	double time;
	cout << "������Ҫ��ӵļ�ְ������Ա�������ͱ���Լ�����ʱ��" << endl;
	cin >> name >> num >> time;
	Technician tmp(name, num, time);
	technician.push_back(tmp);
}

void insertsmg() {
	string name, num;
	cout << "������Ҫ��ӵ����۾���������ͱ��" << endl;
	cin >> name >> num;
	Salesmanager tmp(name, num);
	salesmanager.push_back(tmp);
}

void insertsam() {
	string name, num;
	double sold;
	cout << "������Ҫ��ӵļ�ְ����Ա�������ͱ���Լ��������۶�" << endl;
	cin >> name >> num >> sold;
	Salesman tmp(name, num, sold);
	salesman.push_back(tmp);
}

void removemng() {
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

void removetch() {
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

void removesmg() {
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

void removesam() {
	string num;
	int del_flag = 0;
	cout << "��������Ҫɾ���ļ�ְ����Ա�ı��" << endl;
	cin >> num;
	for (int i = 0; i != salesman.size(); i++) {
		if (salesman[i].shownum() == num) {
			Salesman::subsold -= salesman[i].sold;
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
