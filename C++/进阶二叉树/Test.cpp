#include "BSTree.h"
using namespace std;
//class A {
//public:
//    A(int x = 0) {
//        cout << "A" << endl;
//    }
//    virtual void printA() {
//        cout << "Hello A" << endl;
//    }
//};
//
//class B :virtual public A {
//public:
//    B(int x = 0) {
//        cout << "B" << endl;
//    }
//    virtual void printA() {
//        cout << "Hello A" << endl;
//    }
//};
//int main() {
//    B test;
//    cout << sizeof(test) << endl;
//    return 0;
//}
int main() {
	BSTree<int> test;
	int x[] = { 9,1,8,3,12,3 };
	for (auto a : x) {
		test.insert(a);
	}
	test.erase(9);
	test.inOrder();
	//cout << test.find(3) << endl;
	return 0;
}