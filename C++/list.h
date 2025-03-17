#include <iostream>
using namespace std;
namespace my_l{
	template<class T>
	class _list_node{
	public:
		_list_node<T>* _prev;
		_list_node<T>* _next;
		T _data;
	};
	template<class T,class Ref,class Ptr>
	class  _list_iterator{
	public:
		_list_iterator(const _list_iterator & x=_list_iterator()){
			_node=x._node;
		}
		_list_iterator( _list_node<T>* const & x=nullptr){//右值引用要这样写，尽量避免const在前，不然有歧义，尤其在有指针的情况下
			_node=x;
		}
		_list_iterator operator++(){
			_node=_node->_next;
			return *this;	
		}
		_list_iterator operator++(int){
			_list_iterator tmp(*this);
			_node=_node->_next;
			return tmp;
		}
		_list_iterator operator--(){
			_node=_node->_prev;
			return *this;
		}
		_list_iterator operator--(int){
			_list_iterator tmp(*this);
			_node=_node->_prev;
			return tmp;
		}
		Ptr operator ->(){
			return &_node->_data;
		}
		Ref operator*(){
			return _node->_data;
		}
		bool operator!=(const _list_iterator& x) const{
			return _node!=x._node;
		}
		_list_node<T>* _node;
	};
	
	template <class T>
	class list{
	public:
		typedef _list_node<T> node;
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;

		list():
			_head(new node){
				_head->_next=_head;
				_head->_prev=_head;
			}
		void push_back(T x){
			node* tmp=new node;
			node* tail=_head->_prev;
			tmp->_data=x;
			tmp->_next=_head;
			tmp->_prev=tail;
			tail->_next=tmp;
			_head->_prev=tmp;
		}
		iterator erase(iterator x){
			node* prev=x._node->_prev;
			node* next=x._node->_next;
			delete x._node;
			prev->_next=next;
			next->_prev=prev;
			return iterator(next);
		}
		void insert(iterator x,T data){
			node* cur=x._node;
			node* next=cur->_next;
			node* tmp=new node;
			tmp->_data=data;
			cur->_next=tmp;
			tmp->_next=next;
			next->_prev=tmp;
			tmp->_prev=cur;
		}
		void push_front(T x){
			node* next=_head->_next;
			node* tmp = new node;
			tmp->_data=x;
			_head->_next=tmp;
			tmp->_prev=_head;
			next->_prev=tmp;
			tmp->_next=next;
		}
		void clear(){
			if(!empty()){
				iterator it	= begin();
				iterator just=it;
				while(it!=end()){
					++it;
					delete just._node;
					just=it;	
				}
			}
		}
		bool empty(){
			return _head->_next==_head->_prev;
		}
		iterator begin(){
			iterator tmp(_head->_next);
			return tmp;
		}
		iterator end(){
			iterator tmp(_head);
			return tmp;
		}
		
	private:
		_list_node<T>* _head;
	};
}
