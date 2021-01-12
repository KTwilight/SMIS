#include "SMIS.h"
void SMIS::showMenu()
{
	cout << "\t\t\t\t------------------------------------" << endl;
	cout << "\t\t\t\t|          学生管理系统             |" << endl;
	cout << "\t\t\t\t|            主菜单                 |" << endl;
	cout << "\t\t\t\t| 【1】添加学生信息               |" << endl;
	cout << "\t\t\t\t| 【2】添加课程信息                 |" << endl;
	cout << "\t\t\t\t| 【3】添加成绩信息                 |" << endl;
	cout << "\t\t\t\t| 【4】展示所有学生信息               |" << endl;
	cout << "\t\t\t\t| 【5】展示所有课程信息               |" << endl;
	cout << "\t\t\t\t| 【6】查询学生所有课程成绩   |" << endl;
	cout << "\t\t\t\t| 【7】查询课程所有成绩 |" << endl;
	cout << "\t\t\t\t| 【8】更新成绩               |" << endl;
	cout << "\t\t\t\t| 【9】删除学生               |" << endl;
	cout << "\t\t\t\t| 【10】删除课程               |" << endl;
	cout << "\t\t\t\t| 【11】删除成绩               |" << endl;
	cout << "\t\t\t\t| 【12】统计课程等级               |" << endl;
	cout << "\t\t\t\t| 【13】统计学生总人数               |" << endl;
	cout << "\t\t\t\t| 【14】统计课程通过人数               |" << endl;
	cout << "\t\t\t\t| 【15】统计课程某分数段人数               |" << endl;
	cout << "\t\t\t\t| 【16】退出程序               |" << endl;
	cout << "\t\t\t\t------------------------------------|" << endl;
	cout << "\t\t\t\t请输入您的选择:" << endl << "\t\t\t\t";
}

void SMIS::addStudent()
{
	cout << "\t\t\t\t请输入您要创建的学生的数量:" << endl << "\t\t\t\t";
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		Student student;
		cout << "\t\t\t\t请输入第" << i << "个学生的学号:" << endl << "\t\t\t\t";
		cin >> student.id;
		cout << "\t\t\t\t请输入第" << i << "个学生的姓名:" << endl << "\t\t\t\t";
		cin >> student.name;
		cout << "\t\t\t\t请输入第" << i << "个学生的性别,0为男, 1为女" << endl << "\t\t\t\t";
		cin >> student.sex;
		cout << "\t\t\t\t请输入第" << i << "个学生的年龄:" << endl << "\t\t\t\t";
		cin >> student.age;
		studentDAO.addNewStudent(student);
	}
}

void SMIS::addSubject()
{
	cout << "\t\t\t\t请输入您要创建的课程的数量:" << endl << "\t\t\t\t";
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		Subject subject;
		cout << "\t\t\t\t请输入第" << i << "门课程的成绩:" << endl << "\t\t\t\t";
		cin >> subject.name;
		studentDAO.addNewSubject(subject);
	}
}

void SMIS::deleteStudent()
{
	int stuid;
	cout << "\t\t\t\t请输入您想要删除的学生的学号:" << endl << "\t\t\t\t";
	cin >> stuid;
	vector<Subject> subjectVector = studentDAO.selectSubByStuid(stuid);
	for (int i = 0; i < subjectVector.size(); i++)
	{
		studentDAO.deleteGradeByid(stuid, subjectVector[i].id);
	}
	studentDAO.deleteStudentByid(stuid);
}


void SMIS::showAllStudent()
{
	vector<Student> studentVector = studentDAO.selectAllStudent();
	for (Student student : studentVector)
	{
		student.print();
	}
}

void SMIS::showAllSubject()
{
	vector<Subject> subjectVector = studentDAO.selectAllSubject();
	for (Subject subject : subjectVector)
	{
		subject.print();
	}
}

void SMIS::selectAllGradeByStuID()
{
	cout << "\t\t\t\t请输入您想要查询的学生的学号:" << endl << "\t\t\t\t";
	int stuid;
	cin >> stuid;
	vector<Subject> subjectVector = studentDAO.selectSubByStuid(stuid);
	for (Subject subject : subjectVector)
	{
		int grade = studentDAO.selectGradeByID(stuid, subject.id);
		cout << "课程名称:" << subject.name << " 成绩:" << grade << endl;
	}
}

void SMIS::selectAllGradeBySubID()
{
	cout << "\t\t\t\t请输入您想要查询的课程的编号:" << endl << "\t\t\t\t";
	int subid;
	cin >> subid;
	vector<Student> studentVector = studentDAO.selectStuBySubid(subid);
	for (Student student : studentVector)
	{
		int grade = studentDAO.selectGradeByID(student.id, subid);
		cout << "学号:" << student.id
			<< " 姓名" << student.name
			<< " 成绩:" << grade << endl;
	}
}

void SMIS::addGradeById()
{
	int stuid, subid, grade;
	cout << "\t\t\t\t请输入您想要插入成绩的学号:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t请输入您想要插入成绩的课程编号:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t请输入成绩:" << endl << "\t\t\t\t";
	cin >> grade;
	studentDAO.addGradeById(stuid, subid, grade);
}

void SMIS::updateGradeById()
{
	int stuid, subid, grade;
	cout << "\t\t\t\t请输入您想要插入成绩的学号:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t请输入您想要插入成绩的课程编号:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t请输入成绩:" << endl << "\t\t\t\t";
	cin >> grade;
	studentDAO.updateGradeById(stuid, subid, grade);
}

void SMIS::deleteSubject()
{
	int subid;
	cout << "\t\t\t\t请输入您想要删除课程的课程编号:" << endl << "\t\t\t\t";
	cin >> subid;
	vector<Student> studentVector = studentDAO.selectStuBySubid(subid);
	for (Student student: studentVector)
	{
		studentDAO.deleteGradeByid(student.id, subid);
	}
	studentDAO.deleteSubjectByid(subid);
}

void SMIS::deleteGrade()
{
	int stuid, subid;
	cout << "\t\t\t\t请输入您想要删除的成绩的学号:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t请输入您想要删除的成绩的课程编号:" << endl << "\t\t\t\t";
	cin >> subid;

	studentDAO.deleteGradeByid(stuid, subid);
}

void SMIS::getgrading()
{
	cout << "学生成绩等级统计：" << endl;
	cout << "A：  90-100\t\t\t" << endl;
	cout << "B：  80-89\t\t\t" << endl;
	cout << "C：  70-79\t\t\t" << endl;
	cout << "D：  60-69\t\t\t" << endl;
	cout << "E:   0-59\t\t\t" << endl;
	int subid;
	cout << "\t\t\t\t请输入课程的编号:" << endl << "\t\t\t\t";
	cin >> subid;
	
	cout << "A级人数为：" << studentDAO.getsortBygrade(subid, 90, 100) << endl;
	cout << "B级人数为：" << studentDAO.getsortBygrade(subid, 80, 89) << endl;
	cout << "C级人数为：" << studentDAO.getsortBygrade(subid, 70, 79) << endl;
	cout << "D级人数为：" << studentDAO.getsortBygrade(subid, 60, 69) << endl;
	cout << "E级人数为：" << studentDAO.getsortBygrade(subid, 0, 59) << endl;
}


void SMIS::getAmountAll()				//统计学生总人数
{
	int amount = studentDAO.getStudentAmount();
	cout << "学生总人数为：" << amount << endl;
}


void SMIS::getAmountPass()				//统计通过人数
{
	cout << "\t\t\t\t请输入课程的编号:" << endl << "\t\t\t\t";
	int subid;
	cin >> subid;
	int passAmount = studentDAO.getsortBygrade(subid, 60, 100);
	int allAmount = studentDAO.getsortBygrade(subid, 0, 100);
	cout << "该课程通过人数为：" << passAmount << " 总人数为：" << allAmount << endl;
}

void SMIS::getsortBygrade()
{
	int subid, low, high;
	cout << "\t\t\t\t请输入课程的编号:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t请输入分数下界:" << endl << "\t\t\t\t";
	cin >> low;
	cout << "\t\t\t\t请输入分数上界:" << endl << "\t\t\t\t";
	cin >> high;
	int passAmount = studentDAO.getsortBygrade(subid, low, high);
	int allAmount = studentDAO.getsortBygrade(subid, 0, 100);
	cout << "该分数段中人数为：" << passAmount << " 该课程总人数为：" << allAmount << endl;
}