#pragma once
#include <winsock.h> //注意顺序，要放在mysql.h前
#include <mysql.h>//控制台项目中要在mysql.h之前include <winsock.h>
#include "Student.hpp"
#include "Subject.hpp"
#include <vector>
#include <iostream>
using namespace std;

class StudentDAO
{
public:
	StudentDAO();
	~StudentDAO();
	vector<Student> selectAllStudent();				//获取所有学生的信息
	vector<Subject> selectAllSubject();				//获取所有科目的信息，科目只包含名字属性

	vector<Student> selectStuBySubid(int subID);	//获取所有学生的信息
	vector<Subject> selectSubByStuid(int stuId);	//获取所有科目的信息，科目只包含名字属性

	int selectGradeByID(int stuID, int subID);		//根据学生的id与科目的id获取学生该科成绩
	
	void deleteStudentByid(int stuID);				//根据学生的id删除该学生信息
	void deleteSubjectByid(int subID);				//根据科目的id删除该科
	void deleteGradeByid(int stuID, int subID);

	void addNewStudent(Student student);			//添加学生
	void addNewSubject(Subject subject);			//添加科目
	void addGradeById(int stuID, int subID, int grade);		//根据学生的id与科目的id为该学生添加成绩
	void updateGradeById(int stuID, int subID, int grade);		//根据学生的id与科目的id为该学生更新成绩

	int getsortBygrade(int subid, int low, int high);		//统计分数段中的人数
	int getStudentAmount();									//统计学生总人数
private:
	MYSQL* pConn;
};

