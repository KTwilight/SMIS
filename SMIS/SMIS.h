#pragma once
#include "StudentDAO.h"
class SMIS
{
public:
	void showMenu();					//主菜单
	void addStudent();					//添加学生
	void addSubject();					//添加课程
	void addGradeById();				//根据学号和课程编号添加成绩
	void showAllStudent();				//展示所有学生
	void showAllSubject();				//展示所有课程
	void selectAllGradeByStuID();		//根据学号查询他所有课程的成绩
	void selectAllGradeBySubID();		//根据课程编号查询他所有课程的成绩
	void updateGradeById();				//根据学号和课程编号更新成绩


	void deleteStudent();				//根据学号删除学生
	void deleteSubject();				//根据课程编号删除课程
	void deleteGrade();					//根据学号和课程删除成绩

	void getgrading();					//统计学生优良等级
	void getAmountAll();				//统计学生总人数
	void getAmountPass();				//统计通过人数
	void getsortBygrade();				//统计各分数段人数
private:
	StudentDAO studentDAO;
};

