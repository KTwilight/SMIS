#include "SMIS.h"
using namespace std;
void selection()
{
	int order;
	SMIS smis;
	while (true)
	{
		smis.showMenu();
		cin >> order;
		switch (order)
		{
		case 1:smis.addStudent(); break;
		case 2:smis.addSubject(); break;
		case 3:smis.addGradeById(); break;
		case 4:smis.showAllStudent(); break;
		case 5:smis.showAllSubject(); break;
		case 6:smis.selectAllGradeByStuID(); break;
		case 7:smis.selectAllGradeBySubID(); break;
		case 8:smis.updateGradeById(); break;
		case 9:smis.deleteStudent(); break;
		case 10:smis.deleteSubject(); break;
		case 11:smis.deleteGrade(); break;
		case 12:smis.getgrading(); break;
		case 13:smis.getAmountAll(); break;
		case 14:smis.getAmountPass(); break;
		case 15:smis.getsortBygrade(); break;

		}
		if (order == 16)
		{
			break;
		}
		cout << "\t\t\t\t" << endl << endl;
		cout << "点击Enter键进行下一步";
		getchar();
		getchar();
		system("cls");
	}
}
int main()
{
	selection();
	return 0;
}
