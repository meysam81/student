#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;
int n = 0;
class student
{
private:
	string fname, lname, major;
	int studentno;
	float ave;
public:
	student();
	student(string, string, int, string, float);
	~student();
	void add(string, string, int, string, float, student[]);
	void del(int, student[]);
	void search(string, string, int, student[]);
	void edit(string, string, int, student[]);
	void list(student[]);
};
student::student()
{
	fname = "";
	lname = "";
	studentno = NULL;
	major = "";
	ave = 0.0;
}
student::student(string fn, string ln, int sno, string mj, float av)
{
	fname = fn;
	lname = ln;
	studentno = sno;
	major = mj;
	ave = av;
}
student::~student(){};
void student::edit(string fn, string ln, int sno, student stu[])
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i].fname == fn && stu[i].lname == ln && stu[i].studentno == sno)
		{
			cout << endl << "Enter the correct info:" << endl;
			cout << "First name: ";
			cin >> stu[i].fname;
			cout << "Last name: ";
			cin >> stu[i].lname;
			cout << "Student No. : ";
			cin >> stu[i].studentno;
			cout << "Major: ";
			cin >> stu[i].major;
			cout << "Average: ";
			cin >> stu[i].ave;
			cout << endl << "Done.";
			_getch();
			return;
		}
	}
	cout << "NOT FOUND!" << endl;
	_getch();
}
void student::add(string fn, string ln, int sno, string mj, float av, student stu[])
{
	stu[n].fname = fn;
	stu[n].lname = ln;
	stu[n].studentno = sno;
	stu[n].major = mj;
	stu[n].ave = av;
	n++;
	cout << "Done." << endl;
	_getch();
	return;
}
void student::del(int sno, student stu[])
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i].studentno == sno)
		{
			for (i; i <= n; i++)
				stu[i] = stu[i + 1];
			stu[i].fname = "";
			stu[i].lname = "";
			stu[i].studentno = NULL;
			stu[i].major = "";
			stu[i].ave = 0.0;
			n--;
			cout << "Done." << endl;
			_getch();
			return;
		}
	}
	cout << "NOT FOUND!" << endl;
	_getch();
}
void student::search(string fn, string ln, int sno, student stu[])
{
	for (int i = 0; i < n; i++)
	{
		if (stu[i].fname == fn && stu[i].lname == ln && stu[i].studentno == sno)
		{
			cout << "The student exist." << endl;
			_getch();
			return;
		}
	}
	cout << "NOT FOUND!" << endl;
	_getch();
}
void student::list(student stu [])
{
	if (n == 0)
	{
		cout << "No info entered yet!" << endl;
		_getch();
		return;
	}
	cout << setw(5) << "No. " << setw(15) << "First Name" << setw(15)
		<< "Last Name" << setw(15) << "Student No." << setw(15)
		<< "Major" << setw(15) << "Average" << endl;
	for (int i = 0; i < n; i++)
	{
		if (stu[i].fname != "" && stu[i].lname != "" && stu[i].studentno != NULL)
			cout << setw(5) << i + 1 << setw(15) << stu[i].fname << setw(15)
			<< stu[i].lname << setw(15) << stu[i].studentno << setw(15)
			<< stu[i].major << setw(15) << static_cast<float>(stu[i].ave) << endl;
	}
	_getch();
}
void main()
{
	int sel, sno;
	float av;
	string fn, ln, mj;
	student b, a[50];
	do
	{
		system("CLS");
		cout << "******************** STUDENT CLASS ********************" << endl;
		cout << endl << "1. Add a student" << endl << "2. Delete a student" << endl << "3. Search a student"
			<< endl << "4. List all students" << endl <<"5. Edit Student Info"
			<<endl<< "6. Exit the program" << endl << endl << "Enter your choice: ";
		cin >> sel;
		switch (sel)
		{
		case 1:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl;
			cout << endl << "Enter in order (First Name, Last Name, Student No., Major, Average):" << endl;
			cin >> fn >> ln >> sno >> mj >> av;
			b.add(fn, ln, sno, mj, av, a);
			break;
		case 2:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl;
			if (n == 0)
			{
				cout << "No info entered yet!" << endl;
				_getch();
				break;
			}
			cout << endl << "Enter Student No. :";
			cin >> sno;
			b.del(sno, a);
			break;
		case 3:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl;
			if (n == 0)
			{
				cout << "No info entered yet!" << endl;
				_getch();
				break;
			}
			cout << endl << "Enter in order (First Name, Last Name, Student No.):" << endl;
			cin >> fn >> ln >> sno;
			b.search(fn, ln, sno, a);
			break;
		case 4:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl
				<< endl;
			b.list(a);
			break;
		case 5:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl;
			if (n == 0)
			{
				cout << "No info entered yet!" << endl;
				_getch();
				break;
			}
			cout << endl << "Enter in order (First Name, Last Name, Student No.):" << endl;
			cin >> fn >> ln >> sno;
			b.edit(fn, ln, sno, a);
			break;
		case 6:
			exit(0);
			break;
		default:
			system("CLS");
			cout << "******************** STUDENT CLASS ********************" << endl;
			cout << endl << "WRONG ENTRY!" << endl;
			_getch();
			break;
		}
	} while (true);
}