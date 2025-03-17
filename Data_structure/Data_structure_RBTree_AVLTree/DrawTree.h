#pragma once
#include<easyx.h>
#include<iostream>
#include<conio.h>
#include<stack>
#include<vector>
#include<windows.h>
#define COL 860
#define ROW 1000
#define R 50
using namespace std;
template<class Node>
class Node_info {
public:
	Node_info(int cur,int X,int L,Node* cur_node) {
		_cur_level = cur;
		_p_X = X;
		_node = cur_node;
		_left = L;
	}
	int _cur_level;
	int _p_X;
	Node* _node;
	int _left;
};//����Ҫ Y ��Yֱ�ӵ���_cur_level*
template<class Node>
class drawTree {
public:
	void IniBK() {
		initgraph(ROW, COL);
		setbkcolor(WHITE);
		cleardevice();
		setlinecolor(co_RED);
	}
	int tree_high(Node* _root) {
		if (!_root) {
			return 0;
		}
		int high_left = tree_high(_root->_left);
		int high_right = tree_high(_root->_right);
		return high_left > high_right ? high_left + 1 : high_right + 1;
	}
	int cur_col_gap(int cur_level) {//���㵱ǰ�еļ����
		return ROW / (pow(2, cur_level - 1) + 1);
	}
	void draw_AVL(Node* _root) {
		int high = tree_high(_root),cur_level=1;
		//��ʼ���ڵ�λ��
		int gap_row = COL / (high + 2);
		IniBK();//��ʼ������
		if (_root == nullptr) {
			return;
		}
		stack<Node_info<Node>> st;
		st.push(Node_info<Node>(1,cur_col_gap(1),0,_root));
		//����ǰ�����
		int X = cur_col_gap(1);
		while (!st.empty()) {
			//���Ƶ�һ����
			Node_info<Node> top = st.top();
			if (top._left == 1) {//�������ʱ
				X = top._p_X - cur_col_gap(top._cur_level)/2;
				line(X, top._cur_level * gap_row, top._p_X, (top._cur_level - 1) * gap_row);
				circle(X, top._cur_level * gap_row, R);
			}
			else if (top._left == -1) {//�����ұ�ʱ
				X = top._p_X + cur_col_gap(top._cur_level) / 2;
				circle(X, top._cur_level * gap_row, R);
				line(X, top._cur_level * gap_row, top._p_X, (top._cur_level - 1) * gap_row);
			}
			else {//���ǵ�һ���ڵ�ʱ
				circle(X, top._cur_level * gap_row, R);
			}
			st.pop();
			if(top._node->_right) {
				st.push(Node_info<Node>(top._cur_level+1,X,-1,top._node->_right));
			}//ѹջ��ѹ��
			if (top._node->_left) {
				st.push(Node_info<Node>(top._cur_level+1,X,1,top._node->_left));
			}
			Sleep(1000);

		}
		_getch();
	}
	void draw_RB(Node* _root) {

	}
	
};
