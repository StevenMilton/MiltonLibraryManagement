void Welcome();
int Login();
int AddLibToDB();
int RemLibFromDB();
int AddStuToDB();
int RemStuFromDB();
int EditBookFromDB();
int AddBookToDB();
int RemBookFromDB();
int ShowBooks();
int ShowIBooks();
int ShowStudents();
int ShowLibrarians();
int SearchBook();
int ReturnBook();
int IssueBook();
void AskChoice();
void ShowAO();
void ShowSO();
void ShowLO();
const string currentTime();

void ShowAO()
{
	int choice;
	cout<<"1: Add Librarian to Database\n";
	cout<<"2: Remove Librarian from Database\n";
	cout<<"3: Add Student to Database\n";
	cout<<"4: Remove Student from Database\n";
	cout<<"5: Add Book to Database\n";
	cout<<"6: Remove Book from Database\n";
	cout<<"7: Edit Book from Database\n";
	cout<<"8: Show All Books\n";
	cout<<"9: Search Book\n";
	cout<<"10: Show Issued Books\n";
	cout<<"11: Show All Librarians\n";
	cout<<"12: Show All Students\n";
	cout<<"13: Exit\n";
	cout<<"Choice: "; cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
			AddLibToDB();
			AskChoice();
			break;
		case 2:
			RemLibFromDB();
			AskChoice();
			break;
		case 3:
			AddStuToDB();
			AskChoice();
			break;
		case 4:
			RemStuFromDB();
			AskChoice();
			break;
		case 5:
			AddBookToDB();
			AskChoice();
			break;
		case 6:
			RemBookFromDB();
			AskChoice();
			break;
		case 7:
			EditBookFromDB();
			AskChoice();
			break;
		case 8:
			ShowBooks();
			AskChoice();
			break;
		case 9:
			SearchBook();
			AskChoice();
			break;
		case 10:
			ShowIBooks();
			AskChoice();
			break;
		case 11:
			ShowLibrarians();
			AskChoice();
			break;
		case 12:
			ShowStudents();
			AskChoice();
			break;
		case 13:
			exit(0);
			break;
		default:
			cout<<"Not an option bud!\n\n";
			break;
	}
}

void ShowSO()
{
	int choice;
	cout<<"1: Show All Books\n";
	cout<<"2: Search Book\n";
	cout<<"3: Issue a Book\n";
	cout<<"4: Return a Book\n";
	cout<<"5: Exit\n";
	cout<<"Choice: "; cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
			ShowBooks();
			AskChoice();
			break;
		case 2:
			SearchBook();
			AskChoice();
			break;
		case 3:
			IssueBook();
			AskChoice();
			break;
		case 4:
			ReturnBook();
			AskChoice();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"Not an option bud!\n\n";
			break;
	}
}

void ShowLO()
{
	int choice;
	cout<<"1: Add Student to Database\n";
	cout<<"2: Remove Student from Database\n";
	cout<<"3: Add Book to Database\n";
	cout<<"4: Remove Book from Database\n";
	cout<<"5: Edit Book from Database\n";
	cout<<"6: Show All Books\n";
	cout<<"7: Search Book\n";
	cout<<"8: Show Issued Books\n";
	cout<<"9: Show All Librarians\n";
	cout<<"10: Show All Students\n";
	cout<<"11: Exit\n";
	cout<<"Choice: "; cin>>choice;
	system("cls");
	switch(choice)
	{
		case 1:
			AddStuToDB();
			AskChoice();
			break;
		case 2:
			RemStuFromDB();
			AskChoice();
			break;
		case 3:
			AddBookToDB();
			AskChoice();
			break;
		case 4:
			RemBookFromDB();
			AskChoice();
			break;
		case 5:
			EditBookFromDB();
			AskChoice();
			break;
		case 6:
			ShowBooks();
			AskChoice();
			break;
		case 7:
			SearchBook();
			AskChoice();
			break;
		case 8:
			ShowIBooks();
			AskChoice();
			break;
		case 9:
			ShowLibrarians();
			AskChoice();
			break;
		case 10:
			ShowStudents();
			AskChoice();
			break;
		case 11:
			exit(0);
			break;
		default:
			cout<<"Not an option bud!\n\n";
			break;
	}
}

void AskChoice()
{
	char ch = 'a';
	cout<<"\nPress N to Exit or any other key to Go To Menu!\n";
	ch = getch();
	if(ch == 'n' || ch == 'N')
	{
		exit(0);
	}
	system("cls");
}
void Welcome()
{
	cout<<"Welcome to the Library System!\n";
}

int AddLibToDB()
{
	string empno, empname;
	int emppin;
	cout<<"Enter Employee No of Librarian: ";
	cin >> empno;
	string fname = "[L]" + empno + ".txt";
	ifstream file;
	file.open(fname);
	if(file.is_open())
	{
		cout<<"Librarian Already exists in the Database!\n";
		return 2;
	}
	else
	{
		ofstream file;
		file.open(fname);
		cout<<"Enter PIN: ";cin>>emppin;
		cout<<"Enter Name: "; cin >> empname;
		file << empno << " " << emppin << " " << empname;
		file.close();
		file.open(LOG, fstream::app);
		file << "[ " << currentTime() << " ] " << "[L-LOG] " << Admin << " has created Librarian " << empno << " named " << empname << "\n";
		file.close();
		file.open(LIB, fstream::app);
		file << empno << " " << empname << "\n";
		file.close();
		return 3;
	}
}
int RemLibFromDB()
{
	string empno, empname, line;
	int emppin;
	cout<<"Enter Employee No of Librarian: ";
	cin >> empno;
	string fname = "[L]" + empno + ".txt";
	ifstream file;
	file.open(fname);
	if(!file.is_open())
	{
		cout<<"Librarian Does not exist in the Database!\n";
		return 2;
	}
	else
	{
		file.close();
		remove(fname.c_str());
		ifstream file;
		file.open(LIB);
		ofstream tempo;
		tempo.open("tempo.txt");
		while(getline(file, line))
	    {
	      	if(!(line.find(empno) != string::npos))
	        tempo << line << endl;
	    }
	    file.close();
	    tempo.close();
	    remove(LIB.c_str());
	    rename("tempo.txt", LIB.c_str());
		ofstream filee;
		filee.open(LOG, fstream::app);
		filee << "[ " << currentTime() << " ] " << "[L-LOG] " << Admin << " has removed Librarian " << empno << "\n";
		filee.close();
		return 3;
	}
}
int AddStuToDB()
{
	string rollno, stuname;
	int stupin;
	cout<<"Enter Roll No of Student: ";
	cin >> rollno;
	string fname = "[S]" + rollno + ".txt";
	ifstream file;
	file.open(fname);
	if(file.is_open())
	{
		cout<<"Student Already exists in the Database!\n";
		return 2;
	}
	else
	{
		ofstream file;
		file.open(fname);
		cout<<"Enter PIN: ";cin>>stupin;
		cout<<"Enter Name: "; cin >> stuname;
		file << rollno << " " << stupin << " " << stuname;
		file.close();
		file.open(LOG, fstream::app);
		file << "[ " << currentTime() << " ] " << "[S-LOG] " << Admin << " has created Student " << rollno << " named " << stuname << "\n";
		file.close();
		file.open(STU, fstream::app);
		file << rollno << " " << stuname << "\n";
		file.close();
		return 3;
	}
}
int RemStuFromDB()
{
	string rollno, stuname, line;
	int stupin;
	cout<<"Enter Roll No of Student: ";
	cin >> rollno;
	string fname = "[S]" + rollno + ".txt";
	ifstream file;
	file.open(fname);
	if(!file.is_open())
	{
		cout<<"Student Does not exist in the Database!\n";
		return 2;
	}
	else
	{
		file.close();
		remove(fname.c_str());
		ifstream file;
		file.open(STU);
		ofstream tempo;
		tempo.open("tempo.txt");
		while(getline(file, line))
	    {
	      	if(!(line.find(rollno) != string::npos))
	        tempo << line << endl;
	    }
	    file.close();
	    tempo.close();
	    remove(STU.c_str());
	    rename("tempo.txt", STU.c_str());
		ofstream filee;
		filee.open(LOG, fstream::app);
		filee << "[ " << currentTime() << " ] " << " [S-LOG] " << Admin << " has removed Student " << rollno << "\n";
		filee.close();
		return 3;
	}
}
int AddBookToDB()
{
	string a1, a2, bname;
	int tisbn, isbn, price, instock;
	cout<<"Enter ISBN of the book: ";
	cin>>tisbn;
	ifstream file;
	file.open(BOK);
	while(file >> bname >> isbn >> price >> instock >> a1 >> a2)
	{
		if(isbn == tisbn)
		{
			cout<<"Book already exists!\n";
			return 2;
		}
	}
	file.close();
	ofstream filee;
	filee.open(BOK, fstream::app);
	cout<<"Enter Book Name: "; cin >> bname;
	cout<<"Enter Price: "; cin>>price;
	cout<<"Enter Author: "; cin >> a1;
	cout<<"Enter another author (Optional; put NA): "; cin >> a2;
	cout<<"Enter In-Stock Books No: "; cin>>instock;
	filee << bname << " " << tisbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
	filee.close();
	filee.open(LOG, fstream::app);
	filee << "[ " << currentTime() << " ] " << "[B-LOG] " << Admin << " has created Book " << isbn << " named " << bname << "\n";
	filee.close();
	return 3;
}
int RemBookFromDB()
{
	string a1, a2, bname;
	int yes = 0, tisbn, isbn, price, instock;
	cout<<"Enter ISBN of Book: ";
	cin>>tisbn;
	ifstream file;
	file.open(BOK);
	while(file >> bname >> isbn >> price >> instock >> a1 >> a2)
	{
		if(isbn == tisbn)
		{
			ofstream tempo;
			tempo.open("tempo.txt");
			while(file >> bname >> isbn >> price >> instock >> a1 >> a2)
		    {
		      	if(isbn != tisbn)
		        tempo << bname << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 <<"\n";
		    }
		    file.close();
		    tempo.close();
		    remove(BOK.c_str());
		    rename("tempo.txt", BOK.c_str());
			tempo.open(LOG, fstream::app);
			tempo << "[ " << currentTime() << " ] " << " [B-LOG] " << Admin << " has removed Book " << bname << "\n";
			tempo.close();
			yes = 1;
			return 3;
		}
	}
	if(yes == 0)
	{
		cout<<"Book does not exits in the Database!\n";
		return 2;
	}
}

int EditBookFromDB()
{
	int tisbn, yes = 0;
	cout<<"Enter ISBN Number of the Book: "; cin>>tisbn;
	string name, a1, a2;
	int isbn, price, instock;
	ifstream file;
	file.open(BOK);
	while(file >> name >> isbn >> price >> instock >> a1 >> a2)
	{
		if(isbn == tisbn)
		{
			cout<<"Name\tISBN\tPrice\tIn Stock\tAuthor\tAuthor\n";
			cout<<name<<"\t"<<isbn<<"\t"<<price<<"\t"<<instock<<"\t"<<a1<<"\t"<<a2<<"\n\n";
			string tname, ta1, ta2;
			int isbna, tprice, tinstock;
			cout<<"Enter the same old Details of the Book if you don't want to Change that thing!\n\n";
			cout<<"Enter New Name for this Book: "; cin>>tname;
			cout<<"Enter New ISBN for this Book: "; cin>>isbna;
			cout<<"Enter New Price for this Book: "; cin>>tprice;
			cout<<"Enter New Stock (Quantity) of Book: "; cin>>tinstock;
			cout<<"Enter New Author of this Book: "; cin>>ta1;
			cout<<"Enter New Second Author of this Book: "; cin>>ta2;
			file.close();
			file.open(BOK);
			ofstream tempo;
			tempo.open("tempo.txt");
			while(file >> name >> isbn >> price >> instock >> a1 >> a2)
			{
				if(isbn != tisbn)
				{
					tempo << name << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
				}
			}
			tempo << tname << " " << isbna << " " << tprice << " " << tinstock << " " << ta1 << " " << ta2 << "\n";
			file.close();
			tempo.close();
			remove(BOK.c_str());
			rename("tempo.txt", BOK.c_str());
			ofstream filee;
			filee.open(LOG, fstream::app);
			filee << "[ " << currentTime() << " ] " << Admin << " has edited Book having ISBN: " << tisbn << "\n";
			filee.close(); 
			yes = 1;
		}
	}
	if(yes == 0)
	{
		cout<<"Book Does Not Exist!\n";
	}
}

int ShowBooks()
{
	string a1, a2, bname;
	int isbn, price, instock;
	ifstream file;
	file.open(BOK);
	system("cls");
	cout<<setw(10)<<setfill(' ')<<std::left<<"Name"<<"\t"<<"ISBN"<<"\t"<<"Price"<<"\t"<<"Stock"<<"\t"<<"Author"<<"\t"<<"Author"<<endl;
	while(file >> bname >> isbn >> price >> instock >> a1 >> a2)
	{
		cout<<setw(10)<<setfill(' ')<<std::left<<bname<<"\t"<<isbn<<"\t"<<price<<"\t"<<instock<<"\t"<<a1<<"\t"<<a2<<endl;
	}
}

int ShowIBooks()
{
	string roll;
	int isbn;
	ifstream file;
	file.open(ISS);
	system("cls");
	cout<<setw(10)<<setfill(' ')<<std::left<<"Roll NO"<<"\t"<<"ISBN"<<endl;
	while(file >> roll >> isbn)
	{
		cout<<setw(10)<<setfill(' ')<<std::left<<roll<<"\t"<<isbn<<endl;
	}
}


int SearchBook()
{
	string name, bname, line, a1, a2;
	int a = 0, isbn, instock, price;
	cout<<"Enter Book Name: "; cin >> bname;
	ifstream file;
	file.open(BOK);
	while(file >> name >> isbn >> price >> instock >> a1 >> a2)
    {
    	if(name.find(bname) != string::npos)
        {
        	a++;
			cout<<setw(10)<<setfill(' ')<<std::left<<name<<"\t"<<isbn<<"\t"<<price<<"\t"<<instock<<"\t"<<a1<<"\t"<<a2<<endl;
		}
    }
    if(a == 0)
    {
    	cout<<"No Books found with this name : "<<bname<<"\n";
    	return 2;
	}
    file.close();
}
int IssueBook()
{
	string name, roll, line, a1, a2;
	int yes = 0, iss = 0, isbn, isbna, instock, price, q = 0;
	cout<<"Enter Book ISBN: "; cin>>isbna;
	ifstream file;
	file.open(ISS);
	while(file >> roll >> isbn)
	{
		if(isbn == isbna)
		{
			iss = 1;
		}
	}
	file.close();
	if(iss == 1)
	{
		cout<<"Book already issued by student!\n";
		return 2;
	}
	file.open(BOK);
    while(file >> name >> isbn >> price >> instock >> a1 >> a2)
    {
		if(isbn == isbna)
		{
			if(instock > 0)
			{
				string tname = name, ta1 = a1, ta2 = a2;
				int tisbn = isbn, tinstock = instock-1, tprice = price;
				ofstream filee;
				filee.open(ISS, fstream::app);
				filee << stu.getrollno() << " " << isbna << "\n";
				filee.close();
				filee.open(ILOG, fstream::app);
				filee << "[ " << currentTime() << " ] " << stu.getname() << " (Roll No: " << stu.getrollno() << ") has issued book having ISBN: "<< isbn <<"!\n";
				filee.close();
				filee.open("tempo.txt");
				while(file >> name >> isbn >> price >> instock >> a1 >> a2)
			    {
			      	if(isbn != isbna)
			        {
			        	cout<<"[DBG]" << name << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
						filee << name << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
					}
			    }
			    file.close();
			    filee << tname << " " << tisbn << " " << tprice << " " << tinstock << " " << ta1 << " " << ta2 << "\n";
			    filee.close();
			    filee.open(LOG, fstream::app);
				filee << "[ " << currentTime() << " ] " << " [I-LOG] " << stu.getrollno() << " has issued Book " << tname << "\n";
				filee.close();
				remove(BOK.c_str());
			    rename("tempo.txt", BOK.c_str());
				yes = 1;
				cout<<"Book Issued successfully!\n";
				break;
			}
			else
			{
				cout<<"Book is not in stock (Quantity = 0)\n";
				return 4;
			}
		}
	}
	if(yes == 0) cout<<"Wrong ISBN No.\n";
}
int ReturnBook()
{
	string tname, ta1, ta2;
	int tisbna, tprice, tinstock;
	string name, a1, a2;
	int instock, price;
	string roll, line;
	int tisbn, isbn, ok = 0, a = 0;
	ifstream file;
	file.open(ISS);
	cout<<"Your Issued Books:\n";
	while(file >> roll >> isbn)
	{
		if(roll == stu.getrollno())
		{
			a++;
			cout<<"ISBN No: "<<isbn<<"\n";
		}
	}
	file.close();
	cout<<"No of Books issued: "<<a<<"\n";
	if(a == 0)
	{
		cout<<"You have no any book issued!\n";
		return 2;
	}
	else
	{
		cout<<"Enter the ISBN No of book you want to return: "; cin>>tisbn;
		file.open(ISS);
		while(file >> roll >> isbn)
		{
			if(isbn == tisbn)
			{
				ok = 1;
			}
		}
		file.close();
		if(ok == 0)
		{
			cout<<"You entered a wrong ISBN (You dont have this book issued!)\n";
			return 4;
		}
		ofstream tempo;
		tempo.open("tempo.txt");
		file.open(ISS);
		while(file >> roll >> isbn)
	    {
	      	if(isbn != tisbn)
	      	{
	      		cout<<"[DBG]"<<roll << " " << isbn << "\n";
			  	tempo << roll << " " << isbn << "\n";
			}
	    }
	    file.close();
	    tempo.close();
	    ifstream filee;
	    ofstream tempoo;
	    filee.open(BOK);
	    tempoo.open("tempoo.txt");
	    while(filee >> name >> isbn >> price >> instock >> a1 >> a2)
	    {
	      	if(isbn != tisbn)
	        {
	        	//cout<<"[DBG]" << name << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
				tempoo << name << " " << isbn << " " << price << " " << instock << " " << a1 << " " << a2 << "\n";
			}
			else
			{
				tname = name; tisbna = isbn; tprice = price; tinstock = instock+1; ta1 = a1; ta2 = a2;
			}
	    }
	    filee.close();
	    tempoo << tname << " " << tisbn << " " << tprice << " " << tinstock << " " << ta1 << " " << ta2 << "\n";
	    tempoo.close();
		tempo.open(RLOG, fstream::app);
   		tempo << "[ " << currentTime() << " ] " << stu.getname() << " (Roll No: " << stu.getrollno() << ") has returned book having ISBN "<< isbn <<"!\n";
		tempo.close();
		tempo.open(LOG, fstream::app);
		tempo << "[ " << currentTime() << " ] " << "[R-LOG] " << stu.getrollno() << " has returned Book having ISBN " << isbn << "\n";
		tempo.close();
		remove(ISS.c_str());
	    rename("tempo.txt", ISS.c_str());
	    remove(BOK.c_str());
	    rename("tempoo.txt", BOK.c_str());
	    cout<<"Book Returned Successfuly!\n";
	    return 3;
	}
}

int ShowStudents()
{
	string name, roll;
	ifstream file;
	file.open(STU);
	system("cls");
	cout<<setw(10)<<setfill(' ')<<std::left<<"Roll No"<<"\t"<<"Name"<<endl;
	while(file >> name >> roll)
	{
		cout<<setw(10)<<setfill(' ')<<std::left<<name<<"\t"<<roll<<endl;
	}
}

int ShowLibrarians()
{
	string name, empno;
	ifstream file;
	file.open(LIB);
	system("cls");
	cout<<setw(10)<<setfill(' ')<<std::left<<"Employee No"<<"\t"<<"Name"<<endl;
	while(file >> name >> empno)
	{
		cout<<setw(10)<<setfill(' ')<<std::left<<name<<"\t"<<empno<<endl;
	}
}




const string currentTime() // Taken from cppreference.com //
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
    tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d | %X", &tstruct);
    return buf;
}
