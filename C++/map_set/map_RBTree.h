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
struct _TreeIterator {//迭代器启动！！！
	typedef RBTreeNode<T> Node;
	_TreeIterator(Node* node):
			_node(node){}
	typedef _TreeIterator<T> Self;
	Node* _node;
	Self& operator++() {//中序遍历的operator++,其本质其实是找到比它大的最小值
		if (_node == nullptr) { return *this; }
		if (_node->_right != nullptr) {
			_node = _node->_right;         // 进入右子树
			while (_node->_left != nullptr) {
				_node = _node->_left;      // 找到右子树的最左节点
			}
		}
		// 情况2：当前节点无右子树
		else {
			Node* parent = _node->_parent;
			// 向上回溯，直到找到第一个祖先节点，且当前节点是该祖先的左子节点
			while (parent != nullptr && _node == parent->_right) {
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent; // 后继节点是父节点（可能为nullptr）
		}
		return *this;
	}
	Self& operator--() {
		if (_node == nullptr) return *this; // 边界情况

		// 情况1：当前节点有左子树
		if (_node->_left != nullptr) {
			_node = _node->_left;          // 进入左子树
			while (_node->_right != nullptr) {
				_node = _node->_right;     // 找到左子树的最右节点
			}
		}
		// 情况2：当前节点无左子树
		else {
			Node* parent = _node->_parent;
			// 向上回溯，直到找到第一个祖先节点，且当前节点是该祖先的右子节点
			while (parent != nullptr && _node == parent->_left) {
				_node = parent;
				parent = parent->_parent;
			}
			_node = parent; // 前驱节点是父节点（可能为nullptr）
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
		//调整树的节点颜色
		//情况1：无事发生
		while (parent && parent->_COL == Node_RED1) {//当parent的节点的颜色与cur节点的颜色相同时
			Node* grand = parent->_parent;
			Node* uncle = (grand->_left == parent) ? grand->_right : grand->_left;
			if (uncle && uncle->_COL == Node_RED1) {//uncle存在，且uncle是红色
				grand->_COL = Node_RED1;
				parent->_COL = Node_BLACK1;
				uncle->_COL = Node_BLACK1;
				cur = grand;
				parent = cur->_parent;//调整完向上走
			}
			else {//uncle 不存在 或者 为黑色
				if (grand->_left == parent) {//左树情况
					if (parent->_left != cur) {//此左右双旋，其实可以先 右单旋 再跟普通情况一起左单旋。
						rotateL(parent);
						swap(cur, parent);//把这两个指针的位置交换，这样才可以继续左单旋
					}
					rotateR(grand);
					//调整颜色
					parent->_COL = Node_BLACK1;
					grand->_COL = Node_RED1;
					break;
				}
				else {
					if (parent->_right != cur) {
						rotateR(parent);
						swap(cur, parent);//把这两个指针的位置交换，这样才可以继续左单旋
					}
					rotateL(grand);
					//调整颜色
					parent->_COL = Node_RED1;
					grand->_COL = Node_RED1;
					break;
				}
			}
		}
		_root->_COL = Node_BLACK1;
	}
	void rotateL(Node* parent) {//左单旋
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
	void rotateR(Node* parent) {//右单旋
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
	void delete_adjust_dark(Node* cur) {//调整深黑(双黑)节点
		Node* parent = cur->_parent;
		if (cur->_COL == Node_RED1 || _root == cur) {//若为根节点，双黑直接置黑色
			cur->_COL = Node_BLACK1;//若双黑节点为红色，直接置成黑色
		}
		else if (parent->_right == cur) {//双黑在右边情况
			Node* bro = parent->_left;
			if (bro->_COL == Node_BLACK1) {
				if (bro->_left && bro->_left->_COL == Node_RED1) {
					bro->_left->_COL = bro->_COL;
					bro->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;//变色
					rotateR(parent);//旋转
				}
				else if (bro->_right && bro->_right->_COL == Node_RED1) {
					bro->_right->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;
					rotateL(bro);
					rotateR(parent);
				}
				else {//兄弟节点有两个黑节点
					//双黑上移动+变色儿
					bro->_COL = Node_RED1;
					delete_adjust_dark(parent);
				}
			}
			else {//bro是红色
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
					parent->_COL = Node_BLACK1;//变色
					rotateL(parent);//旋转
				}
				else if (bro->_left && bro->_left->_COL == Node_RED1) {
					bro->_left->_COL = parent->_COL;
					parent->_COL = Node_BLACK1;
					rotateR(bro);
					rotateL(parent);
				}
				else {//兄弟节点有两个黑节点
					//双黑上移动
					bro->_COL = Node_RED1;
					delete_adjust_dark(parent);
				}
			}
			else {//bro是红色
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
		}//step1：查找节点
		//step2：像二叉搜索树一般删除。
		if (!(cur->_left && cur->_right)) {
			Node* tmp = cur->_left ? cur->_left : cur->_right;
			if (_root == cur) {
				_root = tmp;
				tmp->_COL = Node_BLACK1;
				delete cur;
			}
			else {
				parent = cur->_parent;
				if (cur->_left || cur->_right) {//不会有双黑节点，直接将子节点颜色赋值为黑色
					cur->_left ? cur->_left->_COL = Node_BLACK1 : cur->_right->_COL = Node_BLACK1;
				}
				else if (cur->_COL == Node_BLACK1) {
					delete_adjust_dark(cur);//此时双黑节点是cur
				}//节点若为红色，直接删除
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
			if (find->_left || find->_right) {//不会有双黑节点的情况，直接将子节点颜色赋值为黑色
				find->_left ? find->_left->_COL = Node_BLACK1 : find->_right->_COL = Node_BLACK1;
			}
			else if (find->_COL == Node_BLACK1) {//双黑情况
				delete_adjust_dark(find);//此时双黑节点是find
			}//
			delete_Node(find);//删除前驱节点。
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