#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
using namespace std;
enum Node_COLOR {
	Node_RED,Node_BLACK};
template<class k,class v>
struct RBTreeNode{
	RBTreeNode(const pair<k,v>& x):
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_COL(Node_RED),
		_pair(x){}
	RBTreeNode* _left;
	RBTreeNode* _right;
	RBTreeNode* _parent;
	Node_COLOR _COL;
	pair<k, v> _pair;
};
template<class k,class v>
class RBTree {
	typedef RBTreeNode<k,v> Node;
public:
	bool insert(const pair<k,v>& pair) {
		if (_root == nullptr) {
			_root = new Node(pair);
			_root->_COL = Node_BLACK;
			return true;
		}
		Node* cur = _root;
		Node* parent = _root;
		while (cur) {
			if (cur->_pair.first == pair.first) {
				return false;
			}
			else if (cur->_pair.first > pair.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				parent = cur;
				cur = cur->_right;
			}
		}
		cur = new Node(pair);
		parent->_pair.first > pair.first ? parent->_left = cur : parent->_right = cur;
		cur->_parent = parent;
		//�������Ľڵ���ɫ
		//���1�����·���
		while (parent && parent->_COL == Node_RED) {//��parent�Ľڵ����ɫ��cur�ڵ����ɫ��ͬʱ
			Node* grand = parent->_parent;
		    Node* uncle = (grand->_left == parent) ? grand->_right : grand->_left;
			if (uncle && uncle->_COL == Node_RED) {//uncle���ڣ���uncle�Ǻ�ɫ
				grand->_COL = Node_RED;
				parent->_COL = Node_BLACK;
				uncle->_COL = Node_BLACK;
				cur = grand;
				parent = cur->_parent;//������������
			}
			else{//uncle ������ ���� Ϊ��ɫ
				if(grand->_left==parent){//�������
					if (parent->_left != cur) {//������˫������ʵ������ �ҵ��� �ٸ���ͨ���һ��������
						rotateL(parent);
						swap(cur, parent);//��������ָ���λ�ý����������ſ��Լ�������
					}
					rotateR(grand);
					//������ɫ
					parent->_COL = Node_RED;
					grand->_COL = Node_RED;
					break;
				}
				else {
					if (parent->_right != cur) {
						rotateR(parent);
						swap(cur, parent);//��������ָ���λ�ý����������ſ��Լ�������
					}
					rotateL(grand);
					//������ɫ
					parent->_COL = Node_BLACK;
					grand->_COL = Node_RED;
					break;
				}
			}
		}
		_root->_COL = Node_BLACK;
	}
	void rotateL(Node* parent) {//����
		Node* grand = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		subR->_left = parent;
		if (_root == parent) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			grand->_left == parent ? grand->_left = subR : grand->_right = subR;
			subR->_parent = grand;
		}
		if (subRL != nullptr) {
			subRL->_parent = parent;
		}
		parent->_right = subRL;
		subR->_left = parent;
		parent->_parent = subR;
	}
	void rotateR(Node* parent) {//�ҵ���
		Node* grand = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		subL->_right = parent;
		if (_root == parent) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			grand->_left == parent ? grand->_left = subL : grand->_right = subL;
			subL->_parent = grand;
		}
		if (subLR != nullptr) {
			subLR->_parent = parent;
		}
		parent->_left = subLR;
		subL->_right = parent;
		parent->_parent = subL;
	}
	bool find(const k& key) {
		Node* cur = _root;
		while (cur) {
			if (cur->_pair.first < key) {
				cur = cur->_right;
			}
			else if (cur->_pair.first > key) {
				cur = cur->_left;
			}
			else {
				return true;
			}
		}
		return false;
	}
	void delete_Node(Node* cur) {
		Node* tmp = cur->_left ? cur->_left : cur->_right;
		Node* parent = cur->_parent;
		parent->_left == cur ? parent->_left = tmp : parent->_right = tmp;
	}
	void delete_adjust_dark(Node* cur) {//�������(˫��)�ڵ�
		Node* parent = cur->_parent;
		if (cur->_COL == Node_RED||_root==cur) {//��Ϊ���ڵ㣬˫��ֱ���ú�ɫ
			cur->_COL = Node_BLACK;//��˫�ڽڵ�Ϊ��ɫ��ֱ���óɺ�ɫ
		}
		else if (parent->_right == cur) {//˫�����ұ����
			Node* bro = parent->_left;
			if (bro->_COL == Node_BLACK) {
				if (bro->_left && bro->_left->_COL == Node_RED) {
					bro->_left->_COL = bro->_COL;
					bro->_COL = parent->_COL;
					parent->_COL = Node_BLACK;//��ɫ
					rotateR(parent);//��ת
				}
				else if (bro->_right && bro->_right->_COL == Node_RED) {
					bro->_right->_COL = parent->_COL;
					parent->_COL = Node_BLACK;
					rotateL(bro);
					rotateR(parent);
				}
				else {//�ֵܽڵ��������ڽڵ�
					//˫�����ƶ�+��ɫ��
					bro->_COL = Node_RED;
					delete_adjust_dark(parent);
				}
			}
			else {//bro�Ǻ�ɫ
				bro->_COL = parent->_COL;
				parent->_COL = Node_RED;
				rotateR(parent);
				delete_adjust_dark(cur);
			}
		}
		else {
			Node* bro = parent->_right;
			if (bro->_COL == Node_BLACK) {
				if (bro->_right && bro->_right->_COL == Node_RED) {
					bro->_right->_COL = bro->_COL;
					bro->_COL = parent->_COL;
					parent->_COL = Node_BLACK;//��ɫ
					rotateL(parent);//��ת
				}
				else if (bro->_left && bro->_left->_COL == Node_RED) {
					bro->_left->_COL = parent->_COL;
					parent->_COL = Node_BLACK;
					rotateR(bro);
					rotateL(parent);
				}
				else {//�ֵܽڵ��������ڽڵ�
					//˫�����ƶ�
					bro->_COL = Node_RED;
					delete_adjust_dark(parent);
				}
			}
			else {//bro�Ǻ�ɫ
				bro->_COL = parent->_COL;
				parent->_COL = Node_RED;
				rotateL(parent);
				delete_adjust_dark(cur);
			}
		}
	}
	bool erase(const k& key) {
		Node* parent = _root;
		Node* cur = _root;
		while (cur) {
			if (cur->_pair.first < key) {
				cur = cur->_right;
			}
			else if (cur->_pair.first > key) {
				cur = cur->_left;
			}
			else {
				break;
			}
		}
		if (cur == nullptr) {
			return false;
		}//step1�����ҽڵ�
		//step2�������������һ��ɾ����
		if (!(cur->_left && cur->_right)) {
			Node* tmp = cur->_left ? cur->_left : cur->_right;
			if (_root == cur) {
				_root = tmp;
				tmp->_COL = Node_BLACK;
				delete cur;
			}
			else {
				parent = cur->_parent;
				if (cur->_left || cur->_right) {//������˫�ڽڵ㣬ֱ�ӽ��ӽڵ���ɫ��ֵΪ��ɫ
					cur->_left ? cur->_left->_COL = Node_BLACK : cur->_right->_COL = Node_BLACK;
				}
				else if(cur->_COL==Node_BLACK){
					delete_adjust_dark(cur);//��ʱ˫�ڽڵ���cur
				}//�ڵ���Ϊ��ɫ��ֱ��ɾ��
				delete_Node(cur);
			}
		}
		else {
			Node* find = cur->_left;
			while (find->_right) {
				find = find->_right;
			}
			cur->_pair = find->_pair;
			parent = find->_parent;
			if (find->_left || find->_right) {//������˫�ڽڵ�������ֱ�ӽ��ӽڵ���ɫ��ֵΪ��ɫ
				find->_left ? find->_left->_COL = Node_BLACK : find->_right->_COL = Node_BLACK;
			}
			else if(find->_COL==Node_BLACK){//˫�����
				delete_adjust_dark(find);//��ʱ˫�ڽڵ���find
			}//
			delete_Node(find);//ɾ��ǰ���ڵ㡣
		}

	}
	void Inorder() {
		_Inorder(_root);
	}
	void _Inorder(Node* cur) {
		if (cur == nullptr) {
			return;
		}
		_Inorder(cur->_left);
		cout << cur->_pair.first << " : " << cur->_pair.second << endl;
		_Inorder(cur->_right);
	}
	Node* _root=nullptr;
};