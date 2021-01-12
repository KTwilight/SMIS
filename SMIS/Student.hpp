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
		cout << "学号:\t\t\t" << id << endl;
		cout << "姓名:\t\t\t" << name << endl;
		cout << "性别:\t\t\t";
		if (sex == 0)
			cout << "男" << endl;
		else
			cout << "女" << endl;
		cout << "年龄:\t\t\t" << age << endl;
	}

	int id = 0;
	string name;
	int sex = 0;
	int age = 0;
};

