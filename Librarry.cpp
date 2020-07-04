// DONE ------ 1. Optimize the code
// X --------- 2. Graphics
// DONE ------ 3. User Friendly
// DONE ------ 4. Issue Book and Return Book
// DONE ------ 5. Books stock system etc
// DONE ------ 6. Edit Books

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>

#include "modules/classes.cpp"

using namespace std;

const string Admin = "Milton";
const int AdminPin = 27;
Librarian lib;
Student stu;

const string RLOG = "returnlog.txt";
const string ILOG = "issuelog.txt";
const string LLOG = "loginlog.txt";
const string LOG = "log.txt";
const string LIB = "Librarians.txt";
const string STU = "Students.txt";
const string BOK = "Books.txt";
const string ISS = "Issued.txt";

#include "modules/functions.cpp"

int main()
{
	Welcome();
	int a;
	cout<<"What are you? \n";
	cout<<"1: Student, 2: Librarian, 3: Admin\n";
	cout<<"Choice: "; cin>>a;
	system("cls");
	switch(a)
	{
		case 3:
		{
			string name;
			int pin;
			cout<<"Enter your name, Majesty: "; cin>>name;
			if(name == Admin)
			{
				cout<<"Enter PIN: "; cin>>pin;
				if(pin == AdminPin)
				{
					ofstream file;
					file.open(LLOG, fstream::app);
					file << "|A| [ " << currentTime() << " ] " << Admin << " has logged in!\n";
					file.close();
					file.open(LOG, fstream::app);
					file << "|A| [ " << currentTime() << " ] " <<"[Login-LOG] " << Admin << " has logged in!\n";
					file.close();
					cout<<"Successfuly Logged in As Admin!\n";
					AskChoice();
					while(1)
					{
						ShowAO();
					}
					return 5;
				}
			}
			else
			{
				cout<<"Wrong name bud! Get out!";
				exit(0);
			}
		}
		case 1:
		{
			string rollno;
			int pin;
			cout<<"Enter your Roll No: ";
			cin >> rollno;
			string fname = "[S]" + rollno + ".txt";
			ifstream file;
			file.open(fname);
			if(!file.is_open())
			{
				cout<<"No such Database exists!";
				file.close();
				exit(0);
				return 2;
			}
			else
			{
				string frollno, fname;
				int fpin, a = 0;
				file >> frollno >> fpin >> fname;
				while(a < 3)
				{
					cout<<"Enter Pin: "; cin>>pin;
					if(pin == fpin)
					{
						stu.setname(fname);
						stu.setrollno(frollno);
						stu.setpin(fpin);
						ofstream file;
						file.open(LLOG, fstream::app);
						file << "|S| [ " << currentTime() << " ] " << fname << " having roll no: " << frollno << " has logged in!\n";
						file.close();
						file.open(LOG, fstream::app);
						file << "|S| [ " << currentTime() << " ] " <<"[Login-LOG] " << fname << " (Roll No: " << frollno << ") has logged in!\n";
						file.close();
						cout<<"Login Successful!\n";
						AskChoice();
						while(1)
						{
							ShowSO();
						}
						return 3;
						break;
					}
					else
					{
						a++;
						cout<<"You have entered a wrong password! Attempts: "<<a<<" out of 3!\n";
						if(a == 3)
						{
							exit(0);
						}
					}
				}
			}
			break;
		}
		case 2:
		{
			string employeeno;
			int pin;
			cout<<"Enter your Employee No: ";
			cin >> employeeno;
			string fname = "[L]" + employeeno + ".txt";
			ifstream file;
			file.open(fname);
			if(!file.is_open())
			{
				cout<<"No such Database exists!";
				file.close();
				exit(0);
				return 4;
			}
			else
			{
				string fempno, fname;
				int fpin, a = 0;
				file >> fempno >> fpin >> fname;
				while(a < 3)
				{
					cout<<"Enter Pin: "; cin>>pin;
					if(pin == fpin)
					{
						lib.setempno(fempno);
						lib.setname(fname);
						lib.setpin(fpin);
						ofstream file;
						file.open(LLOG, fstream::app);
						file << "|L| [ " << currentTime() << " ] " << fname << " having employee no: " << fempno << " has logged in!\n";
						file.close();
						file.open(LOG, fstream::app);
						file << "|L| [ " << currentTime() << " ] " <<"[Login-LOG] " << fname << " (Employee No: " << fempno << ") has logged in!\n";
						file.close();
						cout<<"Login Successful!\n";
						AskChoice();
						while(1)
						{
							ShowLO();
						}
						return 6;
						break;
					}
					else
					{
						a++;
						cout<<"You have entered a wrong password! Attempts: "<<a<<" out of 3!\n";
						if(a == 3)
						{
							exit(0);
						}
					}
				}
			}
			break;
		}
		default:
		{
			cout<<"Wrong Choice!\n";
			break;
		}
	}
}
