//#define _CRT_SECURE_NO_WARNINGS 1

//class in
//{
//public:
//	in()
//	{
//		_a = 100;
//	}
//	int _a;
//};
//
//
//
//class test
//{
//public:
//	test(int a = 0,int b=0)
//	{
//		_a = a;
//		_b = b;
//	}
//	void print()
//	{
//		cout <<"a= " <<_a<< " b=" << _b << " xΪ" << x._a << endl;
//	}
//	~test()
//	{
//
//	}
//private:
//	int _a;
//	int _b;
//	in x;
//};
//
//
//int main()
//{
//	test a;
//	a.print();
//	/*test a;
//	a.print();*/
//	return 0;
//}

//class Stu
//{
//public:
//	Stu(int age = 18, const char *name = "ass", int id = 111)
//	{
//		strcpy(_name, name);
//		_age = age;
//		_id = id;
//	}
//	Stu(const Stu& x)
//	{
//		strcpy(_name, x._name);
//		_id = x._id;
//		_age = x._age;
//	}
//	void print()
//	{
//		cout << "name: " << _name <<  " age: " <<  _age  << " id: "<< _id << endl;
//	}
//	bool operator==(Stu& x)
//	{
//		return _age == x._age;
//	}
//private:
//	int _age;
//	char _name[10];
//	int _id;
//};
//#include <iostream>
//#include <cstring>
//#include <clocale>
//using namespace std;
//
//class Date
//{
//public:
//	int Getmonthday(int year,int month)
//	{
//		int monthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && year % 4 == 0 && year % 100 != 0)
//		{
//			return 29;
//		}
//		return monthDays[month];
//	}
//	bool operator==(const Date&x)
//	{
//		return _year == x._year && _month == x._month && _day == x._day;
//	}
//	bool operator<(const Date& x)
//	{
//		return _year * 10000 + _month * 100 + _day < x._year * 10000 + x._month * 100 + x._day;
//	}
//	bool operator>(const Date& x)
//	{
//		return _year * 10000 + _month * 100 + _day > x._year * 10000 + x._month * 100 + x._day;
//	}
//	bool operator>=(const Date& x)
//	{
//		return *this > x || *this == x;
//	}
//	bool operator<=(const Date& x)
//	{
//		return *this < x || *this == x;
//	}
//	bool operator!=(const Date& x)
//	{
//		return !(*this == x);
//	}
//	Date operator+(int day)
//	{
//		int sz = Getmonthday(_year, _month);
//		int count = 0;
//		int total = day + _day;
//		Date tmp(_year, _month, _day);
//		tmp._day = 0;
//		while (total> sz)
//		{
//			total-= sz;
//			count++;
//			if (tmp._month + count > 12)
//			{
//				tmp._month = 1;
//				count = 0;
//				tmp._year++;
//			}
//			sz = Getmonthday(tmp._year, tmp._month + count);
//		}
//		tmp._day = total;
//		tmp._month += count;
//		return tmp;
//	}
//
//	Date(int year = 0, int month = 1, int day = 1)
//	{
//		if (year >= 0 && month <= 12 && month >= 1 && day >= 1&&day<=Getmonthday(year,month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "非法数据" << endl;
//		}
//	}
//	Date(const Date& x)
//	{
//		_year = x._year;
//		_month = x._month;
//		_day = x._day;
//	}
//	void Print()
//	{
//		cout << "year: " << _year << "\nmonth:" << _month << "\nday:" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	system("chcp 65001");
//	Date test1(2004, 12, 3);
//	Date test2(2001, 11, 3);
//	test1.Print();
//	test1=test1 + 300;
//	test1.Print();
//	if (test1 != test2)
//	{
//		printf("你好");
//	}
//}


#include <iostream>
using namespace std;
class Date
{
public:
	friend istream& operator>>(istream& in,  Date& x);
	friend ostream& operator<<(ostream& out, const Date& x);
	friend void f(Date& m);//在这里声明一下
	Date(int a = 10, int b = 10, int c = 10)
	{
		_a = a;
		_b = b;
		_c = c;
	}

private:
	int _a;
	int _b;
	int _c;
};
void f(Date& m)
{
	cout << m._a << endl;
}
ostream& operator<<(ostream& out, const Date& x)
{
	out << x._a << "-" << x._b << "-" << x._c << endl;
	return out;
}
istream& operator>>(istream& in,  Date& x)
{
	in >> x._a >> x._b >> x._c;
	return in;
}
int main()
{
	Date x;
	int tmp = 0;
	cin >> x >> tmp;
	cout << tmp << endl;
	f(x);
	cout << x << endl;
	return 0;
}