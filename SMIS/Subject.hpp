#pragma once
#include <string>
#include <iostream>
using namespace std;
class Subject
{
public:
	Subject()
	{
	}
	Subject(int id, string name)
	{
		this->id = id;
		this->name = name;
	}
	void print()
	{
		cout << "�γ̱��" << id << endl;
		cout << "�γ�����" << name << endl;
	}
	int id = 0;
	string name;
};

