#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	vector<int> v2(v1);
	vector<int>::const_reverse_iterator it = v1.rbegin();
	while (it != v1.rend())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	return 0;
}