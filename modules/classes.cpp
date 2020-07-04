#include <iostream>
using namespace std;

class Book
{
	private:
		int isbn;
		string name;
		string author1 = "NA";
		string author2 = "NA";
		int price;
		int instock;
	public:
		void setisbn(int a)
		{
			isbn = a;
		}
		void setname(string a)
		{
			name = a;
		}
		void setauthor1(string a)
		{
			author1 = a;
		}
		void setauthor2(string a)
		{
			author2 = a;
		}
		void setprice(int a)
		{
			price = a;
		}
		void setinstock(int a)
		{
			instock = a;
		}
		int getisbn()
		{
			return isbn;
		}
		string getname()
		{
			return name;
		}
		string getauthor1()
		{
			return author1;
		}
		string getauthor2()
		{
			return author2;
		}
		int getprice()
		{
			return price;
		}
		int getinstock()
		{
			return instock;
		}
};

class Librarian
{
	private:
		string name;
		string empno;
		int pin;
	public:
		void setname(string a)
		{
			name = a;
		}
		void setempno(string a)
		{
			empno = a;
		}
		void setpin(int a)
		{
			pin = a;
		}
		string getname()
		{
			return name;
		}
		string getempno()
		{
			return empno;
		}
		int getpin()
		{
			return pin;
		}
};

class Student
{
	private:
		string name;
		string rollno;
		int pin;
	public:
		void setname(string a)
		{
			name = a;
		}
		void setrollno(string a)
		{
			rollno = a;
		}
		void setpin(int a)
		{
			pin = a;
		}
		string getname()
		{
			return name;
		}
		string getrollno()
		{
			return rollno;
		}
		int getpin()
		{
			return pin;
		}
};
