#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
//using namespace std;
enum Node_COLOR1 {
	Node_RED1, Node_BLACK1
};

template<class T>
struct RBTreeNode {
	RBTreeNode(const T& x) :
		_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_COL(Node_RED1),
		_data(x) {}
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	Node_COLOR1 _COL;
	T _data;
};

template<class T>
struct _TreeIterator {//����������������
	typedef RBTreeNode<T> Node;
	_TreeIterator(Node* node):
			_node(node){}
	typedef _TreeIterator<T> Self;
	Node* _node;
	Self& operator++() {//���������operator++,�䱾����ʵ���ҵ����������Сֵ
		if (_node == nullptr) { return *this; }
		if (_node->_right != nullptr) {
			_node = _node->_right;         // ����������
			while (_node->_left != nullptr) {
				_node = _node->_left;      // �ҵ�������������ڵ�
			}
		}
		// ���2����ǰ�ڵ���������
		else {
			Node* parent = _node->_parent;
			// ���ϻ��ݣ�ֱ���ҵ���һ�����Ƚڵ㣬�ҵ�ǰ�ڵ��Ǹ����ȵ����ӽڵ�
			while (parent != nullptr && _node == parent->_right) {
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent; // ��̽ڵ��Ǹ��ڵ㣨����Ϊnullptr��
		}
		return *this;
	}
	Self& operator--() {
		if (_node == nullptr) return *this; // �߽����

		// ���1����ǰ�ڵ���������
		if (_node->_left != nullptr) {
			_node = _node->_left;          // ����������
			while (_node->_right != nullptr) {
				_node = _node->_right;     // �ҵ������������ҽڵ�
			}
		}
		// ���2����ǰ�ڵ���������
		else {
			Node* parent = _node->_parent;
			// ���ϻ��ݣ�ֱ���ҵ���һ�����Ƚڵ㣬�ҵ�ǰ�ڵ��Ǹ����ȵ����ӽڵ�
			while (parent != nullptr && _node == parent->_left) {
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent; // ǰ���ڵ��Ǹ��ڵ㣨����Ϊnullptr��
		}
		return *this;
	}
	bool operator !=(const Self& other) const {
		return other._node!= _node;
	}
	T& operator*() {
		return _node->_data;
	}
	T* operator->() {
		return &(_node->_data);
	}
};

template<class k,class T,class KofT>
class RBTree {
	typedef RBTreeNode<T> Node;
public:
	typedef _TreeIterator<T> iterator;
	iterator begin() {
		Node* ret=_root;
		while (ret && ret->_left) {
			ret = ret->_left;
		}
		return iterator(ret);
	}
	iterator end() {
		return iterator(nullptr);
	}
	bool insert(const T& x) {
		if (_root == nullptr) {
			_root = new Node(x);
			_root->_COL = Node_BLACK1;
			return true;
		}
		KofT kofT;
		Node* cur = _root;
		Node* parent = _root;
		while (cur) {
			if (kofT(cur->_data) == kofT(x)) {
				return false;
			}
			else if (kofT(cur->_data) > kofT(x)) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				parent = cur;
				cur = cur->_right;
			}
		}
		cur = new Node(x);
		kofT(parent->_data) > kofT(cur->_data) ? parent->_left = cur : parent->_right = cur;
		cur->_parent = parent;
		//�������Ľڵ���ɫ
		//���1�����·���
		while (parent && parent->_COL == Node_RED1) {//��parent�Ľڵ����ɫ��cur�ڵ����ɫ��ͬʱ
			Node* grand = parent->_parent;
			Node* uncle = (grand->_left == parent) ? grand->_right : grand->_left;
			if (uncle && uncle->_COL == Node_RED1) {//uncle���ڣ���uncle�Ǻ�ɫ
				grand->_COL = Node_RED1;
				parent->_COL = Node_BLACK1;
				uncle->_COL = Node_BLACK1;
				cur = grand;
				parent = cur->_parent;//������������
			}
			else {//uncle ������ ���� Ϊ��ɫ
				if (grand->_left == parent) {//�������
					if (parent->_left != cur) {//������˫������ʵ������ �ҵ��� �ٸ���ͨ���һ��������
						rotateL(parent);
						swap(cur, parent);//��������ָ���λ�ý����������ſ��Լ�������
					}
					rotateR(grand);
					//������ɫ
					parent->_COL = Node_BLACK1;
					grand->_COL = Node_RED1;
					break;
				}
				else {
					if (parent->_right != cur) {
						rotateR(parent);
						swap(cur, parent);//��������ָ���λ�ý����������ſ��Լ�������
					}
					rotateL(grand);
					//������ɫ
					parent->_COL = Node_RED1;
					grand->_COL = Node_RED1;
					break;
				}
			}
		}
		_root->_COL = Node_BLACK1;
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
		KofT kofT;
		while (cur) {
			if (kofT(cur->_data)< key) {
				cur = cur->_right;
			}
			else if (kofT(cur->_data) > key) {
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
		if (cur->_COL == Node_RED1 || _root == cur) {//��Ϊ���ڵ㣬˫��ֱ���ú�ɫ
			cur->_COL = Node_BLACK1;//��˫�ڽڵ�Ϊ��ɫ��ֱ���óɺ�ɫ
		}
		else if (parent->_right == cur) {//˫�����ұ����
			Node* bro = parent->_left;
			if (bro->_COL == Node_BLACK1) {
				if (bro->_left && bro->_left->_COL == Node_RED1) {
					bro->_left->_COL = bro->_COL;
					bro->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;//��ɫ
					rotateR(parent);//��ת
				}
				else if (bro->_right && bro->_right->_COL == Node_RED1) {
					bro->_right->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;
					rotateL(bro);
					rotateR(parent);
				}
				else {//�ֵܽڵ��������ڽڵ�
					//˫�����ƶ�+��ɫ��
					bro->_COL = Node_RED1;
					delete_adjust_dark(parent);
				}
			}
			else {//bro�Ǻ�ɫ
				bro->_COL = parent->_COL;
				parent->_COL = Node_RED1;
				rotateR(parent);
				delete_adjust_dark(cur);
			}
		}
		else {
			Node* bro = parent->_right;
			if (bro->_COL == Node_BLACK1) {
				if (bro->_right && bro->_right->_COL == Node_RED1) {
					bro->_right->_COL = bro->_COL;
					bro->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;//��ɫ
					rotateL(parent);//��ת
				}
				else if (bro->_left && bro->_left->_COL == Node_RED1) {
					bro->_left->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;
					rotateR(bro);
					rotateL(parent);
				}
				else {//�ֵܽڵ��������ڽڵ�
					//˫�����ƶ�
					bro->_COL = Node_RED1;
					delete_adjust_dark(parent);
				}
			}
			else {//bro�Ǻ�ɫ
				bro->_COL = parent->_COL;
				parent->_COL = Node_RED1;
				rotateL(parent);
				delete_adjust_dark(cur);
			}
		}
	}
	bool erase(const k& key) {
		Node* parent = _root;
		Node* cur = _root;
		KofT kofT;
		while (cur) {
			if (kofT(cur->_data) < key) {
				cur = cur->_right;
			}
			else if (kofT(cur->_data) > key) {
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
				tmp->_COL = Node_BLACK1;
				delete cur;
			}
			else {
				parent = cur->_parent;
				if (cur->_left || cur->_right) {//������˫�ڽڵ㣬ֱ�ӽ��ӽڵ���ɫ��ֵΪ��ɫ
					cur->_left ? cur->_left->_COL = Node_BLACK1 : cur->_right->_COL = Node_BLACK1;
				}
				else if (cur->_COL == Node_BLACK1) {
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
			cur->_data = find->_data;
			parent = find->_parent;
			if (find->_left || find->_right) {//������˫�ڽڵ�������ֱ�ӽ��ӽڵ���ɫ��ֵΪ��ɫ
				find->_left ? find->_left->_COL = Node_BLACK1 : find->_right->_COL = Node_BLACK1;
			}
			else if (find->_COL == Node_BLACK1) {//˫�����
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
		std::cout << cur->_pair.first << " : " << cur->_pair.second << std::endl;
		_Inorder(cur->_right);
	}
	Node* _root = nullptr;
};