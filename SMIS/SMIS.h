#pragma once
#include "StudentDAO.h"
class SMIS
{
public:
	void showMenu();					//���˵�
	void addStudent();					//���ѧ��
	void addSubject();					//��ӿγ�
	void addGradeById();				//����ѧ�źͿγ̱����ӳɼ�
	void showAllStudent();				//չʾ����ѧ��
	void showAllSubject();				//չʾ���пγ�
	void selectAllGradeByStuID();		//����ѧ�Ų�ѯ�����пγ̵ĳɼ�
	void selectAllGradeBySubID();		//���ݿγ̱�Ų�ѯ�����пγ̵ĳɼ�
	void updateGradeById();				//����ѧ�źͿγ̱�Ÿ��³ɼ�


	void deleteStudent();				//����ѧ��ɾ��ѧ��
	void deleteSubject();				//���ݿγ̱��ɾ���γ�
	void deleteGrade();					//����ѧ�źͿγ�ɾ���ɼ�

	void getgrading();					//ͳ��ѧ�������ȼ�
	void getAmountAll();				//ͳ��ѧ��������
	void getAmountPass();				//ͳ��ͨ������
	void getsortBygrade();				//ͳ�Ƹ�����������
private:
	StudentDAO studentDAO;
};

