#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
	Student()
	{

	}
	Student(int id, string name, int sex, int age)
	{
		this->id = id;
		this->name = name;
		this->sex = sex;
		this->age = age;
	}
	void print()
	{
		cout << endl;
		cout << "ѧ��:\t\t\t" << id << endl;
		cout << "����:\t\t\t" << name << endl;
		cout << "�Ա�:\t\t\t";
		if (sex == 0)
			cout << "��" << endl;
		else
			cout << "Ů" << endl;
		cout << "����:\t\t\t" << age << endl;
	}

	int id = 0;
	string name;
	int sex = 0;
	int age = 0;
};

