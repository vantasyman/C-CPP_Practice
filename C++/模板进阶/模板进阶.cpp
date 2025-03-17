#include <iostream>
using namespace std;

//template<class T,class T2>
//class test_special
//{
//public:
//	test_special(T x,T2 y):_x(x),_y(y){
//		cout<<"simple : " << _x << endl<<_y<<endl;
//	}
//	T _x;
//	T2 _y;
//};
//template<class T>
//class test_special<T,double> {
//public:
//	test_special(T x, double y) :_x(x), _y(y) {
//		cout << "special : " << _x << endl << _y << endl;
//	}
//	T _x;
//	double _y;
//};


//ผฬณะ
class parent {
public:
	int _c;

};
class son:public parent
{
public:
	int _a;
	int _b;
};
int main() 
{
	parent test;
	son* ptr = (son*) & test;
	ptr->_a = 100;
	return 0;
}