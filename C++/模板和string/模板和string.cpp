//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
////实现了一个模拟vector
//using namespace std;
//template<class T>
//class vector
//{
//public:
//	vector()
//	{
//		_x = nullptr;
//		_sz = 0;
//		_capacity = 0;
//	}
//	vector(int a) :
//		_x(new T[a]),
//		_sz(0),
//		_capacity(0)
//	{}
//	~vector()
//	{
//		delete[] _x;
//	}
//	void push_back(T x);
//	T& operator[](int x);
//	int _size()
//	{ 
//		return _sz;
//	}
//private:
//	T* _x;
//	int _sz;
//	int _capacity;
//};
//template<class T>
//T& vector<T>::operator [](int x)
//{
//	return _x[x];
//}
//template<class T>
//void vector<T>::push_back(T x)
//{
//	if (_capacity <= _sz)
//	{
//		_capacity = _sz == 0 ? 2 : _sz * 2;
//		T* tmp = new T[_capacity];
//		if (_sz != 0)
//		{
//			memcpy(tmp, _x, _sz*sizeof(T));
//		}
//		_x = tmp;
//	}
//	_x[_sz] = x;
//	_sz++;
//}
//template<class T>
//int x(T x)
//{
//	return x;
//}
//int main()
//{
//	vector<int> X1;
//	X1.push_back(1);
//	X1.push_back(2);
//	X1.push_back(3);
//	X1.push_back(4);
//	for (int i = 0; i < X1._size(); i++)
//	{
//		cout << X1[i] << " ";
//	}
//	x<int>(100);
//	cout << endl;
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//int string2int(const string& nums)
//{
//	string::const_reverse_iterator rit = nums.rbegin();
//	int x = 1;
//	int ret = 0;
//	while (rit!=nums.rend())
//	{
//		ret = (*rit-'0') * x + ret;
//		rit++;
//		
//		x*=10;
//	}
//	return ret;
//}
//template<class T> void test()
//{
//
//}
//int main()
//{
//	string str1("xyq");
//
//	//迭代器
//	/*string::iterator it = str1.begin();
//	for (; it < str1.end(); it++)
//	{
//		cout << *it << endl;
//	}
//	string str2("12345");
//	cout << string2int(str2) << endl;*/
//	str1.insert(str1.begin() + 1, 's');
//	cout << str1 << endl;
//	return 0;
//}
