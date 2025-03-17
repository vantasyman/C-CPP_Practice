#pragma once
#include <iostream>
using namespace std;
template<class K,class V>
class AVLTreeNode {
public:
	AVLTreeNode(const pair<K,V>& kv):
		_pair(kv),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_Bf(0)
	{}
	pair<K, V> _pair;
	AVLTreeNode* _parent;
	AVLTreeNode* _left;
	AVLTreeNode* _right;
	int _Bf;//balance factor
};
template<class K,class V>
class AVLTree {
public:
	typedef AVLTreeNode<K,V> Node;
	bool insert(const pair<K, V>& kv) {
		Node* cur = _root;
		Node* parent = _root;
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		else {
			while (cur) {
				if (cur->_pair.first == kv.first)
					return false;
				else if (cur->_pair.first > kv.first) {
					parent = cur;
					cur = cur->_left;
				}
				else {
					parent = cur;
					cur = cur->_right;
				}
			}
			cur = new Node(kv);
			cur->_parent = parent;
			parent->_pair.first > kv.first ? parent->_left = cur : parent->_right = cur;//正常插入
		}
		//接下来对平衡因子进行调整
		while (parent) {//当cur走到头的时候停止
			cur == parent->_left ? parent->_Bf++ : parent->_Bf--;
			if (parent->_Bf==0) {
				break;
			}
			else if (parent->_Bf == -1 || parent->_Bf == 1) {
				cur = parent;
				parent = cur->_parent;
				continue;
			}
			else {//找到不平衡
				//进行旋转
				if (parent->_Bf == 2) {
					if (cur->_Bf == 1) {
						rotateR(parent);//右单旋
					}
					else {//左右双旋转
						rotateLR(parent);
					}
				}
				else {
					if (cur->_Bf==-1) {
						rotateL(parent);
					}
					else {//右左双旋转
						rotateRL(parent);
					}
				}
				return true;
			}
		}
	}
	void rotateL(Node* parent) {//左旋转
		Node* subR = parent->_right;
		Node* pparent = parent->_parent;
		if (pparent == nullptr) {
			_root = subR;
			subR->_parent = nullptr;
		}
		else {
			pparent->_left == parent ? pparent->_left = subR : pparent->_right = subR;
			subR->_parent = pparent;
		}
		parent->_right = subR->_left;
		if (subR->_left) {//当subR的左子树不为空时
			subR->_left->_parent = parent;
		}
		subR->_left = parent;
		parent->_parent = subR;
		parent->_Bf = subR->_Bf = 0;
	}
	void rotateR(Node* parent) {//右旋转
		Node* subL = parent->_left;
		Node* pparent = parent->_parent;
		if (pparent == nullptr) {
			_root = subL;
			subL->_parent = nullptr;
		}
		else {
			pparent->_left == parent ? pparent->_left = subL : pparent->_right = subL;
			subL->_parent = pparent;
		}
		parent->_left = subL->_right;
		if (subL->_right) {//当subL的右子树不为空时，用以判断右子树是否为nullptr
			subL->_right->_parent = parent;
		}
		subL->_right = parent;
		parent->_parent = subL;
		parent->_Bf = subL->_Bf = 0;
	}
	void rotateRL(Node* parent) {
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		int BF = subRL->_Bf;
		rotateR(subR);
		rotateL(parent);
		switch (BF)
		{
		case(-1):
			parent->_Bf = 1;
			break;
		case(1):
			subR->_Bf = -1;
			break;
		case(0)://因为rotate已经把这三个节点搞成0了，所以只需要修改不是0的节点即可
			break;
		default:
			break;
		}
	}
	void rotateLR(Node* parent) {
		Node* subL = parent->_left;
		Node* subLR = subL->_left;
		int BF = subLR->_Bf;
		rotateL(subL);
		rotateR(parent);
		switch (BF)
		{
		case(-1):
			subL->_Bf = 1;
			break;
		case(1):
			parent->_Bf = -1;
			break;
		case(0):
			break;
		default:
			break;
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