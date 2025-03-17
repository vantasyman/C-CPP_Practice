#include <iostream>
#include <assert.h>
using namespace std;
namespace simp_s
{
	class string
	{
	public:
	  /*string() :
			_str(new char[1])
		{
			_str[1] = '\0';
		}
		string(const char* str)
		{
			_str = new char[strlen(str)+1];
			strcpy(_str, str);
		}*/
		string(const char* str ="") :
			_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		string(const string& cp):
			_str(new char[cp.size() + 1])
		{
			strcpy(_str, cp._str);
		}
		~string()
		{
			delete[] _str;
		}
		size_t size() const
		{
			return strlen(_str);
		}
		string& operator=(const string& tmp)
		{
			if (&tmp == this)
			{
				return *this;
			}//防止自己等于自己的情况
			delete[] _str;//确保再新赋值的时候，原有的内存被释放
			_str = new char[tmp.size() + 1];
			strcpy(_str, tmp._str);
			return *this;//链式等于
		}
		char& operator[](int x)
		{
			return *(_str + x);
		}
	private:
		char* _str;
	};
}
namespace mult_s
{
	class string
	{
	public:
		typedef char* iterator;//迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str = "") :
			_size(strlen(str)),//'/0'不是有效字符，故我们_size不+1；
			_str(new char[_capacity+1]),
			_capacity(_size)
		{
			strcpy(_str,str);
		}
	
		string(const string& tmp)
		{
			_size = tmp._size;
			_capacity = tmp._capacity;
			_str = new char[_capacity+1];
			strcpy(_str, tmp._str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		void reverse()//重置空间
		{
			char* tmp = new char[_capacity + 1];//开新空间
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
		}
		void swap( string& s)
		{
			::swap(_str, s._str);
			::swap(_capacity, s._capacity);
			::swap(_size, s._size);
		}
		void push_back(char ch)
		{
			if (_capacity <= _size)
			{
				_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reverse();
			}
			_str[_size] = ch;//切记！！！切记——size-1才是索引
			_size++;
			_str[_size] = '\0';//封上'\0'
			
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if(_capacity<_size+len)
			{
				_capacity = _size + len;
				reverse();//重开空间
			}
			strcpy(_str + _size, str);
			_size += len;
			_str[_size] = '\0';//切记 切记_size是大小，_size-1才是索引；！！！！！！!！！！
		}
		void insert(size_t pos, char ch)//size_t是无符号整型，如果我们的i=-1时
		{
			assert(pos < _size);
			if (_capacity <= _size)
			{
				_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reverse();
			}
			for (int i = _size; i >=(int)pos ; --i)//当我们的i>=pos比较的时候会整形提升到unsigned_int，如果i是-1就完了，故我们必须强转，
			{
				_str[i+1] = _str[i];
			}
			_size++;
			_str[pos] = ch;
		}
		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_capacity < _size+len)
			{
					_capacity = _size +len;
				reverse();
			}
			for (int i = _size; i >=(int)pos; --i)
			{
				_str[i+len] = _str[i];
			}
			for (int i = 0; i <len; ++i)
			{
				_str[i + pos] = str[i];
			}
			_size += len;
		}
		void resize(size_t x, char ch = '\0')
		{
			
			if (_size < x)//正常增加
			{
				if (x > _capacity)
				{
					_capacity = x;
					reverse();
				}
				for (int i = _size; i < x; i++)
				{
					_str[i] = ch;
				}
			}
			_str[x] = '\0';//不正常就直接截断
			_size = x;
			
		}
		void erase(size_t pos,size_t len= npos)
		{
			assert(pos < _size);
			if (len > _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				
				for(size_t i = pos + len ; i<=_size; ++i)
				{
					_str[i - len] = _str[i];
				}
				_size -=len;
			}
		}
		const char* c_str()
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}
		size_t find(char ch,size_t pos)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos=0)
		{
			char* p = strstr(_str + pos, str);
			if (p == NULL)
			{
				return npos;
			}
			return p - _str;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}//需要重载一下
		string& operator+=(const char* ch)
		{
			append(ch);
			return *this;
		}
		string& operator=(const string& tmp)//=构造
		{
			if (&tmp == this)
			{
				return *this;
			}
			delete[] _str;
			_size = tmp._size;
			_capacity = tmp._capacity;
			_str = new char[_capacity];
			strcpy(_str, tmp._str);
			return *this;
		}
		bool operator<(const string& p) const
		{
			int ret=strcmp(_str , p._str);
			return ret < 0;
		}
		bool operator==(const string& p) const
		{
			int ret = strcmp(_str, p._str);
			return ret == 0;
		}
		bool operator<=(const string& p) const
		{
			return *this < p || *this == p;
		}
		bool operator >(const string& p) const
		{
			return !(*this > p);
		}
		bool operator !=(const string& p) const
		{
			return !(*this == p);
		}
		char& operator[](int x)
		{
			assert(x < _size);
			return _str[x];
		}
		const char& operator[](int x) const//增加一个const operator[]，来预防我们的const this调用
		{
			assert(x < _capacity);
			return _str[x];
		}
		
		friend istream& operator>>(istream& in, string& s);
		friend ostream& operator<<(ostream& out, const string& s);//用友元函数改变我们的this指针的位置
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		static const size_t npos = INT_MIN;
	};
	ostream& operator<<(ostream& out, const string& s)//为什么不直接cout<<_str,因为这样在遇到'\0'时会自动停下，
	{												  //而cout<<string类遇到'\0'的时候不应该自动停下
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)///!!!!!!重点
	{
		char ch;
		while (1)
		{
			ch = in.get();//这样就不会遇到\n停下
			if (ch == ' ' || ch == '\n')
			{
				break;
			}
			else
			{
				s += ch;
			}
		}
		return in;
	}
}
namespace cur_way
{
	class string
	{
	public:
		string(const char* str = "") :
			_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}
		explicit string(const string& s) :
			_str(nullptr)
		{
			string tmp(s._str);
			swap(_str, tmp._str);
		}
		string& operator=(const string& s) 
		{
			if (&s != this)
			{
				string tmp(s);
				swap(_str, tmp._str);
			}
			return *this;
		}
		~string()
		{
			delete[] _str;
		}
		char* _str;
	};
}




