#include "StudentDAO.h"


StudentDAO::StudentDAO()
{
	pConn = mysql_init(NULL);
	mysql_real_connect(pConn, "localhost", "root", "root", "smis", 0, NULL, 0);
}


StudentDAO::~StudentDAO()
{
	mysql_close(pConn);
}


vector<Student> StudentDAO::selectAllStudent()
{
	vector<Student> studentVector;

	char sql[255] = "select * from student";
	mysql_query(pConn, sql);

	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		Student student = Student(atoi(row[0]), row[1], atoi(row[2]), atoi(row[3]));
		studentVector.push_back(student);
	}
	mysql_free_result(result);
	return studentVector;
}


vector<Subject> StudentDAO::selectAllSubject()
{
	vector<Subject> subjectVector;

	char sql[255] = "select * from subject";
	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		Subject subject = Subject(atoi(row[0]), row[1]);
		subjectVector.push_back(subject);
	}
	mysql_free_result(result);

	return subjectVector;
}

vector<Student> StudentDAO::selectStuBySubid(int subID)
{
	vector<Student> studentVector;

	char sql[255];
	sprintf_s(sql, "select student.stuid, student.name, student.sex, student.age from student natural join r_stu_sub where subid = %d", subID);

	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		Student student = Student(atoi(row[0]), row[1], atoi(row[2]), atoi(row[3]));
		studentVector.push_back(student);
	}
	mysql_free_result(result);
	return studentVector;
}

vector<Subject> StudentDAO::selectSubByStuid(int stuId)
{
	vector<Subject> subjectVector;

	char sql[255];
	sprintf_s(sql, "select subid, name from subject natural join r_stu_sub where stuid = %d", stuId);

	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		Subject subject = Subject(atoi(row[0]), row[1]);
		subjectVector.push_back(subject);
	}
	mysql_free_result(result);

	return subjectVector;
}

int StudentDAO::selectGradeByID(int stuID, int subID)
{
	int grade = 0;
	char sql[255];

	sprintf_s(sql, "select grade from r_stu_sub where stuid = %d and subid = %d", stuID, subID);
	mysql_query(pConn, "set names utf-8");
	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	if (row = mysql_fetch_row(result))
	{
		grade = atoi(row[0]);
	}
	mysql_free_result(result);

	return grade;
}


void StudentDAO::deleteStudentByid(int stuID)
{
	char sql[255];
	sprintf_s(sql, "delete from student where stuid = %d", stuID);
	mysql_query(pConn, sql);
	return;
}

void StudentDAO::deleteSubjectByid(int subID)
{
	char sql[255];
	sprintf_s(sql, "delete from subject where subid = %d", subID);
	mysql_query(pConn, sql);
	return;
}

void StudentDAO::deleteGradeByid(int stuID, int subID)
{
	char sql[255];
	sprintf_s(sql, "delete from r_stu_sub where stuid = %d and subid = %d", stuID, subID);
	mysql_query(pConn, sql);
	return;
}

void StudentDAO::addNewStudent(Student student)
{
	char sql[255];
	sprintf_s(sql, "insert into student values(%d,'%s',%d, %d)", student.id, student.name.c_str(), student.sex, student.age);
	mysql_query(pConn, sql);
	return;
}


void StudentDAO::addNewSubject(Subject subject)
{
	char sql[255];
	sprintf_s(sql, "insert into subject(name) values('%s')", subject.name.c_str());
	mysql_query(pConn, sql);
	return;
}

void StudentDAO::addGradeById(int stuID, int subID, int grade)
{
	char sql[255];
	sprintf_s(sql, "insert into r_stu_sub values(%d,%d,%d)", stuID, subID, grade);
	mysql_query(pConn, sql);
	return;
}


void StudentDAO::updateGradeById(int stuID, int subID, int grade)
{
	char sql[255];
	sprintf_s(sql, "update r_stu_sub set grade = %d where stuid = %d and subid = %d", grade, stuID, subID);
	mysql_query(pConn, sql);
	return;
}


int StudentDAO::getStudentAmount()
{
	int amount = 0;
	char sql[255];
	sprintf_s(sql, "select count(grade) from student");
	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	if (row = mysql_fetch_row(result))
	{
		amount = atoi(row[0]);
	}
	mysql_free_result(result);
	return amount;
}

int StudentDAO::getsortBygrade(int subid, int low, int high)
{
	int amount = 0;
	char sql[255];
	sprintf_s(sql, "select count(grade) from r_stu_sub where subid = %d and grade between %d and %d", subid, low, high);
	mysql_query(pConn, sql);
	MYSQL_RES* result = mysql_store_result(pConn);
	MYSQL_ROW row;
	if (row = mysql_fetch_row(result))
	{
		amount = atoi(row[0]);
	}
	mysql_free_result(result);
	return amount;
}
