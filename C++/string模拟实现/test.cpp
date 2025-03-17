#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
using namespace mult_s;
int main()
{

	mult_s::string test("1234");
	//test.erase(1,);
	mult_s::string test2;
	mult_s::string test3;
	test.insert(0, 'a');
	cout << test << endl;
	
	return 0;
}