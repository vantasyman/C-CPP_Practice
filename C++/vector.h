#pragma once
#include <string.h>
#include <assert.h>
#include <iostream>
using namespace std;
namespace my_v{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector():
			_start(nullptr),
			_finish(nullptr),
			_endofstorage(nullptr)
			{}
		vector(const vector& x):
			_start(x._start==nullptr?nullptr:new T[capacity()]),
			_finish(_start+x.size()),
			_endofstorage(_start+x.capacity())
		{
			memcpy(_start,x._start,sizeof(T)*size());
		}
		~vector(){
			delete[] _start;
			_start=_endofstorage=_finish=nullptr;
		}
		void push_back(const T& x)
		{
			if(_finish==_endofstorage)
			{
				size_t newcapacity = capacity()==0?2:capacity()*2;
				reserve(newcapacity);
			}
			*_finish=x;
			++_finish;
		}
		size_t size() const
		{
			return _finish?_finish-_start:0;
		}
		size_t capacity() const
		{
			return _endofstorage?_endofstorage-_start:0;
		}
		void reserve(size_t x)
		{
			if(capacity()<x){
				T* tmp=new T[x];
				size_t tmp_sz=size();
				//memcpy(tmp,_start,sizeof(T)*tmp_sz);涉及深浅拷贝，eg：如果成员是string类，那么delete[]是会删掉原来的空间的
				for(size_t i=0;i<tmp_sz;++i){
					tmp[i]=_start[i];//会调用eg：string的构造函数，故实现深拷贝。
				}
				delete[] _start;
				_start=tmp;
				_endofstorage=_start+x;
				_finish=_start+tmp_sz;
			}
	                                   
	    }
	    void insert(int y,T x)
	    {
	    	//assert(y>=0);
	    	if(_finish==_endofstorage)
	    	{
	    		size_t newcapacity=capacity()?2:capacity()*2;
				reserve(newcapacity);
			}
			for(int i=size();i>y;--i)
			{
				_start[i]=_start[i-1];
			}
			_start[y]=x;
			++_finish;
		}
		void erase(int pos)
		{
			
			iterator it=_finish;
			while(it!=_start+pos)
			{
				*(it-1)=*it;
				--it;
			}
			--_finish;
		}
		void resize(size_t n,const T& val=T())
		{
			if(n<=size())
			{
				_finish=_start+n;				
			}
			else
			{
				if(capacity()<n){
					reserve(n);	
				}
				iterator it=_finish;
				_finish=_start+n;
				while(it!=_finish){
					*it = val;
					++it;
				}
			}
			
		}
	    iterator begin() 
	    {
			return _start;
		}
		iterator end() 
		{
			return _finish;
		}
		iterator const_begin() const
		{
			return _start;
		}
		iterator const_end() const{
			return _finish;
		}
		T operator[](int x)
		{
			//assert(x<size());
			return _start[x];
		}
		void swap(vector& v2)
		{
			std::swap(_start,v2._start);
			std::swap(_finish,v2.finish);
			std::swap(_endofstorage,v2._endofstorage);	
		}
		vector<T>& operator=(const vector v)//抽象的现代写法
		{
			swap(v);
			return *this;
		}
		template<class x>
		friend ostream& operator<<(ostream& m,const vector<x>& v);
		template<class x>
		friend istream& operator>>(istream& m,vector<x>& v);
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;	
	};
	template<class T>
	ostream& operator<<(ostream& x,const vector<T>& v)
	{
		typename vector<T>::const_iterator it = v.const_begin();
		while(it!=v.const_end())
		{
			x<<*it<<" ";
			++it;
		}
		return x;
	}
}
