#pragma once
#include <winsock.h> //ע��˳��Ҫ����mysql.hǰ
#include <mysql.h>//����̨��Ŀ��Ҫ��mysql.h֮ǰinclude <winsock.h>
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
	vector<Student> selectAllStudent();				//��ȡ����ѧ������Ϣ
	vector<Subject> selectAllSubject();				//��ȡ���п�Ŀ����Ϣ����Ŀֻ������������

	vector<Student> selectStuBySubid(int subID);	//��ȡ����ѧ������Ϣ
	vector<Subject> selectSubByStuid(int stuId);	//��ȡ���п�Ŀ����Ϣ����Ŀֻ������������

	int selectGradeByID(int stuID, int subID);		//����ѧ����id���Ŀ��id��ȡѧ���ÿƳɼ�
	
	void deleteStudentByid(int stuID);				//����ѧ����idɾ����ѧ����Ϣ
	void deleteSubjectByid(int subID);				//���ݿ�Ŀ��idɾ���ÿ�
	void deleteGradeByid(int stuID, int subID);

	void addNewStudent(Student student);			//���ѧ��
	void addNewSubject(Subject subject);			//��ӿ�Ŀ
	void addGradeById(int stuID, int subID, int grade);		//����ѧ����id���Ŀ��idΪ��ѧ����ӳɼ�
	void updateGradeById(int stuID, int subID, int grade);		//����ѧ����id���Ŀ��idΪ��ѧ�����³ɼ�

	int getsortBygrade(int subid, int low, int high);		//ͳ�Ʒ������е�����
	int getStudentAmount();									//ͳ��ѧ��������
private:
	MYSQL* pConn;
};

