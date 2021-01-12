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
		cout << "¿Î³Ì±àºÅ" << id << endl;
		cout << "¿Î³ÌÃû×Ö" << name << endl;
	}
	int id = 0;
	string name;
};

