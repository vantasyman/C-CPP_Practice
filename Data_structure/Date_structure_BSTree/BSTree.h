#pragma once
#include <iostream>
using namespace std;
template<class T>
class BSTreeNode {
public:
	BSTreeNode(const T& x):
		_left(nullptr),
		_right(nullptr),
		_val(x)
	{}
	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _val;

};
template <class T>
class BSTree{
public:
	typedef BSTreeNode<T> Node;
	BSTree() :
		_head(nullptr){}
	bool insert(const T& x) {                                //����
		if (_head == nullptr) {
			_head = new Node(x);
			return true;
		}
		Node* cur = _head;
		Node* prev = nullptr;
		while (cur) {
			if (cur->_val == x) {
				return false;
			}
			else if (cur->_val < x) {
				prev = cur;
				cur = cur->_right;
			}
			else {
				prev = cur;
				cur = cur->_left;
			}
		}
		cur = new Node(x);
		prev->_val < x ? prev->_right = cur : prev->_left = cur;
	}
	bool find(const T& x) {
		Node* cur = _head;
		while (cur) {
			if (cur->_val == x) {
				return true;
			}
			else if (cur->_val < x) {
				cur = cur->_right;
			}
			else {
				cur = cur->_left;
			}
		}
		return false;
	}
	bool erase(const T& x) {
		Node* prev = nullptr;
		Node* cur = _head;
		while (cur) {
			if (cur->_val == x) {
				break;
			}
			else if (cur->_val < x) {
				prev = cur;
				cur = cur->_right;
			}
			else {
				prev = cur;
				cur = cur->_left;
			}
		}
		if (!cur) {//û�ҵ�
			return false;
		}
		else if (!(cur->_left && cur->_right)) {//��һ����û������
			Node* tmp = cur->_left ? cur->_left : cur->_right;
			if (prev) {
				// �����ڵ��ָ��ָ��tmp
				(prev->_left == cur) ? prev->_left = tmp : prev->_right = tmp;
			}
			else {
				// ɾ�����Ǹ��ڵ㣬����_head
				_head = tmp;
			}
		}
		else {//��������
			Node* find = cur->_left;
			Node** find_prev = &(cur->_left);//Node** �����¼��ϵ
			while (find->_right) {
				find_prev = &(find->_right);
				find = find->_right;
			}
			cur->_val = find->_val;
			*find_prev = find->_left;//��ɾ�������Ҷ˵�ֵ���������
			delete find;
			return true;
		}
		
	}
	//�������
	void inOrder() {
		Node* cur = _head;
		_inOrder(cur);
		cout << endl;
	}
private:
	void _inOrder(Node* cur) {
		if (cur == nullptr) {
			return;
		}
		_inOrder(cur->_left);
		cout << cur->_val << " ";
		_inOrder(cur->_right);
	}
	Node* _head;
};