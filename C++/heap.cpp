#include <iostream>
#include <vector>
using namespace std;
template<class T>
class heap{
public:
	heap():
		_heap()
		{}
	void push_back(T x){
		_heap.push_back(x);
		adjust_up(_heap.size()-1);
	}
	void adjust_down(int root){
		int parent = root;
		int child = root*2+1;
		int size =_heap.size();
		while(child<size){
			if(child+1<size&&_heap[child]>_heap[child+1]){
				++child;
			}
			if(_heap[parent]>_heap[child]){
				swap(_heap[parent],_heap[child]);
				parent=child;
				child=child*2+1;
			}
			else {
				break;
			}
		}
	}
	void adjust_up(int pos){
		while(pos!=0){
			if(_heap[pos]<_heap[(pos-1)/2]){
				swap(_heap[pos],_heap[(pos-1)/2]);
				pos=(pos-1)/2;
			}
			else
			break;
		}
	}
	T top(){
		return _heap[0];
	}
	void build_from(int x){
		int size=_heap.size();
		int begin = (size-1)/2;
		while(begin!=x){
			adjust_down(begin);
			--begin;
		}
	}
	void pop(T x){
		int i=0;
		for( i =0;_heap[i]!=x;++i){}
		swap(_heap[i],_heap[_heap.size()-1]);		
		_heap.erase(_heap.end()-1);//vector µÄÎ²ºóÔªËØ
		adjust_down(i);
	}
	T operator [](int x){
		return _heap[x];
	}
private:
	vector<T> _heap;
};

int main()
{
	heap<int> test;
	test.push_back(-2);
	test.push_back(0);
	test.push_back(-3);	
	for(int i=0;i<3;++i){
		cout<<test[i]<<" ";
	}
	cout<<endl;
	test.push_back(1); 
	test.pop(-3);
	for(int i=0;i<3;++i){
		cout<<test[i]<<" ";
	}
	
	return 0;
}
