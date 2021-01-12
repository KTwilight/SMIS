#include "SMIS.h"
void SMIS::showMenu()
{
	cout << "\t\t\t\t------------------------------------" << endl;
	cout << "\t\t\t\t|          ѧ������ϵͳ             |" << endl;
	cout << "\t\t\t\t|            ���˵�                 |" << endl;
	cout << "\t\t\t\t| ��1�����ѧ����Ϣ               |" << endl;
	cout << "\t\t\t\t| ��2����ӿγ���Ϣ                 |" << endl;
	cout << "\t\t\t\t| ��3����ӳɼ���Ϣ                 |" << endl;
	cout << "\t\t\t\t| ��4��չʾ����ѧ����Ϣ               |" << endl;
	cout << "\t\t\t\t| ��5��չʾ���пγ���Ϣ               |" << endl;
	cout << "\t\t\t\t| ��6����ѯѧ�����пγ̳ɼ�   |" << endl;
	cout << "\t\t\t\t| ��7����ѯ�γ����гɼ� |" << endl;
	cout << "\t\t\t\t| ��8�����³ɼ�               |" << endl;
	cout << "\t\t\t\t| ��9��ɾ��ѧ��               |" << endl;
	cout << "\t\t\t\t| ��10��ɾ���γ�               |" << endl;
	cout << "\t\t\t\t| ��11��ɾ���ɼ�               |" << endl;
	cout << "\t\t\t\t| ��12��ͳ�ƿγ̵ȼ�               |" << endl;
	cout << "\t\t\t\t| ��13��ͳ��ѧ��������               |" << endl;
	cout << "\t\t\t\t| ��14��ͳ�ƿγ�ͨ������               |" << endl;
	cout << "\t\t\t\t| ��15��ͳ�ƿγ�ĳ����������               |" << endl;
	cout << "\t\t\t\t| ��16���˳�����               |" << endl;
	cout << "\t\t\t\t------------------------------------|" << endl;
	cout << "\t\t\t\t����������ѡ��:" << endl << "\t\t\t\t";
}

void SMIS::addStudent()
{
	cout << "\t\t\t\t��������Ҫ������ѧ��������:" << endl << "\t\t\t\t";
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		Student student;
		cout << "\t\t\t\t�������" << i << "��ѧ����ѧ��:" << endl << "\t\t\t\t";
		cin >> student.id;
		cout << "\t\t\t\t�������" << i << "��ѧ��������:" << endl << "\t\t\t\t";
		cin >> student.name;
		cout << "\t\t\t\t�������" << i << "��ѧ�����Ա�,0Ϊ��, 1ΪŮ" << endl << "\t\t\t\t";
		cin >> student.sex;
		cout << "\t\t\t\t�������" << i << "��ѧ��������:" << endl << "\t\t\t\t";
		cin >> student.age;
		studentDAO.addNewStudent(student);
	}
}

void SMIS::addSubject()
{
	cout << "\t\t\t\t��������Ҫ�����Ŀγ̵�����:" << endl << "\t\t\t\t";
	int number;
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		Subject subject;
		cout << "\t\t\t\t�������" << i << "�ſγ̵ĳɼ�:" << endl << "\t\t\t\t";
		cin >> subject.name;
		studentDAO.addNewSubject(subject);
	}
}

void SMIS::deleteStudent()
{
	int stuid;
	cout << "\t\t\t\t����������Ҫɾ����ѧ����ѧ��:" << endl << "\t\t\t\t";
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
	cout << "\t\t\t\t����������Ҫ��ѯ��ѧ����ѧ��:" << endl << "\t\t\t\t";
	int stuid;
	cin >> stuid;
	vector<Subject> subjectVector = studentDAO.selectSubByStuid(stuid);
	for (Subject subject : subjectVector)
	{
		int grade = studentDAO.selectGradeByID(stuid, subject.id);
		cout << "�γ�����:" << subject.name << " �ɼ�:" << grade << endl;
	}
}

void SMIS::selectAllGradeBySubID()
{
	cout << "\t\t\t\t����������Ҫ��ѯ�Ŀγ̵ı��:" << endl << "\t\t\t\t";
	int subid;
	cin >> subid;
	vector<Student> studentVector = studentDAO.selectStuBySubid(subid);
	for (Student student : studentVector)
	{
		int grade = studentDAO.selectGradeByID(student.id, subid);
		cout << "ѧ��:" << student.id
			<< " ����" << student.name
			<< " �ɼ�:" << grade << endl;
	}
}

void SMIS::addGradeById()
{
	int stuid, subid, grade;
	cout << "\t\t\t\t����������Ҫ����ɼ���ѧ��:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t����������Ҫ����ɼ��Ŀγ̱��:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t������ɼ�:" << endl << "\t\t\t\t";
	cin >> grade;
	studentDAO.addGradeById(stuid, subid, grade);
}

void SMIS::updateGradeById()
{
	int stuid, subid, grade;
	cout << "\t\t\t\t����������Ҫ����ɼ���ѧ��:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t����������Ҫ����ɼ��Ŀγ̱��:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t������ɼ�:" << endl << "\t\t\t\t";
	cin >> grade;
	studentDAO.updateGradeById(stuid, subid, grade);
}

void SMIS::deleteSubject()
{
	int subid;
	cout << "\t\t\t\t����������Ҫɾ���γ̵Ŀγ̱��:" << endl << "\t\t\t\t";
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
	cout << "\t\t\t\t����������Ҫɾ���ĳɼ���ѧ��:" << endl << "\t\t\t\t";
	cin >> stuid;
	cout << "\t\t\t\t����������Ҫɾ���ĳɼ��Ŀγ̱��:" << endl << "\t\t\t\t";
	cin >> subid;

	studentDAO.deleteGradeByid(stuid, subid);
}

void SMIS::getgrading()
{
	cout << "ѧ���ɼ��ȼ�ͳ�ƣ�" << endl;
	cout << "A��  90-100\t\t\t" << endl;
	cout << "B��  80-89\t\t\t" << endl;
	cout << "C��  70-79\t\t\t" << endl;
	cout << "D��  60-69\t\t\t" << endl;
	cout << "E:   0-59\t\t\t" << endl;
	int subid;
	cout << "\t\t\t\t������γ̵ı��:" << endl << "\t\t\t\t";
	cin >> subid;
	
	cout << "A������Ϊ��" << studentDAO.getsortBygrade(subid, 90, 100) << endl;
	cout << "B������Ϊ��" << studentDAO.getsortBygrade(subid, 80, 89) << endl;
	cout << "C������Ϊ��" << studentDAO.getsortBygrade(subid, 70, 79) << endl;
	cout << "D������Ϊ��" << studentDAO.getsortBygrade(subid, 60, 69) << endl;
	cout << "E������Ϊ��" << studentDAO.getsortBygrade(subid, 0, 59) << endl;
}


void SMIS::getAmountAll()				//ͳ��ѧ��������
{
	int amount = studentDAO.getStudentAmount();
	cout << "ѧ��������Ϊ��" << amount << endl;
}


void SMIS::getAmountPass()				//ͳ��ͨ������
{
	cout << "\t\t\t\t������γ̵ı��:" << endl << "\t\t\t\t";
	int subid;
	cin >> subid;
	int passAmount = studentDAO.getsortBygrade(subid, 60, 100);
	int allAmount = studentDAO.getsortBygrade(subid, 0, 100);
	cout << "�ÿγ�ͨ������Ϊ��" << passAmount << " ������Ϊ��" << allAmount << endl;
}

void SMIS::getsortBygrade()
{
	int subid, low, high;
	cout << "\t\t\t\t������γ̵ı��:" << endl << "\t\t\t\t";
	cin >> subid;
	cout << "\t\t\t\t����������½�:" << endl << "\t\t\t\t";
	cin >> low;
	cout << "\t\t\t\t����������Ͻ�:" << endl << "\t\t\t\t";
	cin >> high;
	int passAmount = studentDAO.getsortBygrade(subid, low, high);
	int allAmount = studentDAO.getsortBygrade(subid, 0, 100);
	cout << "�÷�����������Ϊ��" << passAmount << " �ÿγ�������Ϊ��" << allAmount << endl;
}