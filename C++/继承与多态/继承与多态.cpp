#include <iostream>
using namespace std;
//class person
//{
//protected:
//	person(int a,int b):_ID(a),_age(b){}
//	person(const person& x) {
//		_ID = x._ID;
//		_age = x._age;
//	}
//	person operator=(const person& x) {
//		_age = x._age;
//		_ID = x._ID;
//		return *this;
//	}
//	int _ID;
//	int _age;
//};
//class stu :public person
//{
//public:
//	stu(int a,int b, int c):person(a,b),_grade(c){}
//	stu(const stu& x):person(x){//�ڳ�ʼ���б���û���Ŀ�������//ֱ�����òü���
//		_grade = x._grade;
//	}
//	stu operator =(const stu& x) {
//		_grade = x._grade;
//		person::operator=(x);//�ü�
//		return *this;
//	}
//	~stu() {
//		//��������д���������
//	}
//	int _grade;
//};
//int main()
//{
//	
//	
//	return 0;
//}
//class high {
//public:
//	int h;
//};
//class mid_1 : virtual public high
//{
//public:
//	int m1;
//};
//class mid_2 : virtual public high {
//public:
//	int m2;
//};
//class lat :public mid_2, public mid_1
//{
//public:
//	int l;
//};
////����麯����
//class fir {
//private:
//	virtual void func1() { cout << "func1" << endl; }
//	virtual void func2() { cout << "func2" << endl; }
//};
//class sec:private fir {
//public:
//	virtual void func1() { cout << "sec func1" << endl;}
//	virtual void func3() { cout << "func3" << endl; }
//};
//typedef void (*p) ();
//void print_VFP(p* VFP) {
//	for (size_t i = 0; *(VFP + i) != 0; ++i) {
//		printf("VFP[%d]��%p\n", i, VFP[i]);
//		p tmp = VFP[i];
//		tmp();                   //ͨ���麯����ֱ���ƿ����Ʒ���
//	}
//	cout << endl;
//}
//
//int main()
//{
//	fir a;
//	sec b;
//	print_VFP((p*)(*(int*)&b));
//	return 0;
//}
#include <iostream>
using namespace std;

class A {
public:
    A(const char* s) { cout << s << endl; }
    ~A() {}
};

class B : virtual public A {
public:
    B(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
};

class C : virtual public A {
public:
    C(const char* s1, const char* s2) : A(s1) { cout << s2 << endl; }
};

class D : public B, public C {
public:
    D(const char* s1,const char* s2,const char* s3,const char* s4) : B(s1, s2), C(s1, s3),A(s1){
        cout << s4 << endl;
    }
};

int main() {
    D* p =new D("class A", "class B", "class C", "class D");
    delete p;
    return 0;
}
