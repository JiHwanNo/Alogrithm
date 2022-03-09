//#include "BinarySearchTree.h"
//#include<iostream>
//#include <Windows.h>
//
//using namespace std;
//enum  class ConsoleColor
//{
//	BLACK = 0,
//	RED = FOREGROUND_RED,
//	GREEN = FOREGROUND_GREEN,
//	BLUE = FOREGROUND_BLUE,
//	YELLOW = RED | GREEN,
//	WHITE = RED | GREEN | BLUE,
//};
//
//void SetCursorColor(ConsoleColor color)
//{
//	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
//	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
//}
//
//void SetCursorPosition(int x, int y)
//{
//	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
//	::SetConsoleCursorPosition(output, pos);
//}
//
//void ShowConsoleCursor(bool flag)
//{
//	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO cursorInfo;
//	::GetConsoleCursorInfo(output, &cursorInfo);
//	cursorInfo.bVisible = flag;
//	::SetConsoleCursorInfo(output, &cursorInfo);
//}
//
//BinarySearchTree::BinarySearchTree()
//{
//	_nil = new Node();
//	_root = _nil;
//}
//
//BinarySearchTree::~BinarySearchTree()
//{
//	delete _nil;
//}
//
//void BinarySearchTree::Print()
//{
//	::system("cls");
//	ShowConsoleCursor(false);
//	Print(_root, 10, 0);
//}
//
//void BinarySearchTree::Print(Node* node, int x, int y)
//{
//	if (node == _nil)
//		return;
//
//	SetCursorPosition(x,y);
//
//	if (node->color == Color::Black)
//		SetCursorColor(ConsoleColor::BLUE);
//	else 
//		SetCursorColor(ConsoleColor::RED);
//
//	cout << node->key;
//	Print(node->left, x - (5 / (y + 1)), y + 1);
//	Print(node->right, x + (5 / (y + 1)), y + 1);
//
//	SetCursorColor(ConsoleColor::WHITE);
//}
//
//
//Node* BinarySearchTree::Search(Node* node, int key)
//{
//	if (node == _nil || key == node->key)
//		return node;
//
//	if (key < node->key)
//		Search(node->left, key);
//	else
//		Search(node->right, key);
//}
//
//
//Node* BinarySearchTree::Max(Node* node)
//{
//	while (node->right != _nil)
//	{
//		node = node->right;
//	}
//	return node;
//}
//
//Node* BinarySearchTree::Min(Node* node)
//{
//	while (node->left != _nil)
//	{
//		node = node->left;
//	}
//	return node;
//}
//
//
//Node* BinarySearchTree::Next(Node* node)
//{
//	if (node->right != _nil)
//		return Min(node->right);
//
//	Node* parent = node->parent;
//	
//	while (node == parent->right && parent != _nil)
//	{
//		node = parent;
//		parent = parent->parent;
//	}
//
//	return parent;
//}
//
//void BinarySearchTree::Insert(int key)
//{
//	Node* newNode = new Node();
//	newNode->key = key;
//
//	Node* node = _root;
//	Node* parent = _nil;
//
//	while (node != _nil)
//	{
//		parent = node;
//		if (key < node->key)
//			node = node->left;
//		else
//			node = node->right;
//	}
//
//	newNode->parent = parent;
//	if (parent == _nil)
//		_root = newNode;
//	else if (key < parent->key)
//		parent->left = newNode;
//	else
//		parent->right = newNode;
//
//	//�˻�
//	newNode->left = _nil;
//	newNode->right = _nil;
//	newNode->color = Color::Red;
//
//	InsertFixup(newNode);
//}
//
//void BinarySearchTree::InsertFixup(Node* node)
//{
//	// p = �θ�, uncle = �θ� �ݴ��� ���
//	// 1) p = red, uncle = red
//	// -> p = black, uncle = black, pp = red�� �ٲ�
//	// 2) p = red, uncle = black (Triangle)
//	// -> ȸ���� ���� 3)���� �ٲ���
//	// 3) p = red, uncle = black (list)
//	// -> ���� ���� + ȸ��
//	
//	// �ڽ��� �θ��� ������ �������� ������ üũ���ش�.
//	// �ڽŵ� ���� ����̹Ƿ� �θ�(����) / �ڽ� (����)�� �˰��� ������ ���ݵȴ�.
//	while (node->parent->color == Color::Red)
//	{
//		//����� �θ� �ҸӴ� ����� �������̶��,
//		if (node->parent == node->parent->parent->left)
//		{
//			Node* uncle = node->parent->parent->right;
//			if (uncle->color == Color::Red) //1) ��Ȳ
//			{
//				node->parent->color = Color::Black; //p
//				uncle->color = Color::Black; //uncle
//				node->parent->parent->color = Color::Red; //pp
//				node = node->parent->parent; // ����� ������ �ٽ� üũ���ش�.
//			}
//
//			else //2)��Ȳ 
//			{
//			//			[pp(B)]
//			//		[p(R)]			[u(B)]
//			//			[n(R)]
//			// 
//			// ���� (Triangle)�� 
//			// 
//			//			[pp(B)]
//			//		[n(R)]			[u(B)]
//			//	[p(R)]
//			// 
//			// ��Ȳ���� �ٲ۴�.(������ �Ͼ)
//				if (node == node->parent->right)
//				{
//					node = node->parent;
//					LeftRotate(node);
//				}
//
//				//3) ��Ȳ
//
//				//			[pp(R)]
//				//		[p(B)]  [u(B)]
//				//    [n(R)]
//
//				//			[p(B)]
//				//		[n(R)]  [pp(R)]
//				//				    [u(B)]
//				node->parent->color = Color::Black;
//				node->parent->parent->color = Color::Red;
//				RightRotate(node->parent->parent);
//			}
//		}
//		else
//		{
//			// 1) ��Ȳ
//			//			[pp(B)]
//			//		[u(B)]  [p(R)]
//			//                [n(R)]
//			Node* uncle = node->parent->parent->left; 
//			if (uncle->color == Color::Red) //1) ��Ȳ
//			{
//				node->parent->color = Color::Black; //p
//				uncle->color = Color::Black; //uncle
//				node->parent->parent->color = Color::Red; //pp
//				node = node->parent->parent; // ����� ������ �ٽ� üũ���ش�.
//			}
//			else 
//			{
//				// 2) ��Ȳ 
//				//			[pp(B)]
//				//		[u(B)]  [p(R)]
//				//            [n(R)]   
//				//  
//				//			[pp(B)]
//				//		[u(B)]  [p(R)]
//				//                 [n(R)]                      
//				if (node == node->parent->left)
//				{
//					node = node->parent;
//					RightRotate(node);
//				}
//
//				// 3) ��Ȳ
//				//			[p(B)]
//				//		[pp(R)]  [n(R)]
//				//   [u(B)]   
//				node->parent->color = Color::Black;
//				node->parent->parent->color = Color::Red;
//				LeftRotate(node->parent->parent);
//			}
//		}
//	}
//		_root->color = Color::Black;
//}
//
//void BinarySearchTree::Delete(int key)
//{
//	Node* deleteNode = Search(_root, key);
//	Delete(deleteNode);
//}
//
//void BinarySearchTree::Delete(Node* node)
//{
//	//���� Node�� ���� ���.
//	if (node == _nil)
//		return;
//
//	if (node->left == _nil)
//	{
//		Color color = node->color;
//		Node* right = node->right;
//		Replace(node, node->right);
//
//		if (color == Color::Black)
//			DeleteFixup(right);
//
//	}
//	else if (node->right == _nil)
//	{
//		Color color = node->color;
//		Node* right = node->left;
//
//		Replace(node, node->left);
//		if (color == Color::Black)
//			DeleteFixup(right);
//	}
//	else 
//	{
//		// ���ʿ� �ִ� ���.
//		Node* next = Next(node);
//		node->key = next->key;
//		Delete(next);
//	}
//
//}
//
//void BinarySearchTree::DeleteFixup(Node* node)
//{
//	Node* x = node;
//
//	while (x != _root && x->color == Color::Black)
//	{
//		if (x == x->parent->left)
//		{
//			//case 3��	DB�� sibling ��尡 Red�� ���
//			//s = black, p = red (s <-> p ���� ��ȯ)
//			//DB �������� rotage(p)
//
//			Node* s = x->parent->right;
//			if (s->color == Color::Red)
//			{
//				s->color = Color::Black;
//				x->parent->color = Color::Red;
//
//				LeftRotate(x->parent); 
//				s = x->parent->right;
//			}
//
//			//case 4�� DB�� sibling ��尡 Black && sibling�� ���� �ڽĵ� Black
//			//�߰� Black�� parent���� ����
//			//p�� Red�̸� Black ��
//			//p�� Black�̸� DB ��
//			//s = red
//			//p�� ������� �˰��� �̾ ����(DB�� ������ �����ϸ�)
//
//			if (s->left->color == Color::Black && s->right->color == Color::Black)
//			{
//				s->color = Color::Red;
//				x = x->parent; // p�� ������� whild���� ���鼭 ������ �κ��� check ���ش�.
//			}
//			else
//			{
//				//case 5�� DB�� sibling ��尡 Black && sibling�� near child = red, far child = black
//				//s < ->near ���� ��ȯ
//				//far �������� rotate(s)
//
//				//			[p]
//				//[x(DB)]			 [s(B)]
//				//				[near(R)][far(B)]
//				//------------------------------------
//				//			[p]
//				//[x(DB)]			 [s(R)]
//				//				[near(B)][far(B)]
//				//------------------------------------
//				//			[p]
//				//[x(DB)]			 [near(B)]
//				//							[s(R)]
//				//								[far(B)]
//				if (s->right->color == Color::Black)
//				{
//					s->left->color = Color::Black;
//					s->color = Color::Red;
//					RightRotate(s);
//					s = x->parent->right;
//				}
//
//				//case 6 DB�� sibling ��尡 Black && sibling�� far child = red
//				//p < ->s ���� ��ȯ
//				//far = black
//				//rotate(p) (DB��������)
//				//�߰� Black ����
//
//				s->color = x->parent->color;
//				x->parent->color = Color::Black;
//				s->right->color = Color::Black;
//				LeftRotate(x->parent);
//				x = _root;
//			}
//		}
//		else
//		{
//			if (x == x->parent->right)
//			{
//				//case 3��	DB�� sibling ��尡 Red�� ���
//
//				Node* s = x->parent->left;
//				if (s->color == Color::Red)
//				{
//					s->color = Color::Black;
//					x->parent->color = Color::Red;
//
//					RightRotate(x->parent);
//					s = x->parent->right;
//				}
//
//				//case 4�� DB�� sibling ��尡 Black && sibling�� ���� �ڽĵ� Black
//
//				if (s->right->color == Color::Black && s->left->color == Color::Black)
//				{
//					s->color = Color::Red;
//					x = x->parent; // p�� ������� whild���� ���鼭 ������ �κ��� check ���ش�.
//				}
//				else
//				{
//					//case 5�� DB�� sibling ��尡 Black && sibling�� near child = red, far child = black
//
//					if (s->left->color == Color::Black)
//					{
//						s->right->color = Color::Black;
//						s->color = Color::Red;
//						LeftRotate(s);
//						s = x->parent->left;
//					}
//
//					//case 6 DB�� sibling ��尡 Black && sibling�� far child = red
//
//					s->color = x->parent->color;
//					x->parent->color = Color::Black;
//					s->left->color = Color::Black;
//					RightRotate(x->parent);
//					x = _root;
//				}
//			}
//		}
//	}
//
//	x->color = Color::Black;
//}
//
//// u ��忡�� v ���� ��ü�ϴ� �۾�
//void BinarySearchTree::Replace(Node* u, Node* v)
//{
//	// ���� �θ� ���ٸ� �ֻ���̴�.
//	if (u->parent == _nil)
//		_root = v;
//	// u�� �θ��� ���� ��尡 u�� ���
//	else if (u == u->parent->left)
//		u->parent->left = v;
//	else // u�� �θ��� ������ ��尡 u�� ���
//		u->parent->right = v;
//	//v�� u�� �θ�� ��������ش�.
//	delete u;
//}
//
////			[y]
////		[x]		[3]
////	   [1][2]
//
////			[x]
////		[1]		[y]
////			   [2][3]
//// ��� -> �ϴ�		RightRotate
//// �ϴ� -> ���		LeftRotate
//
//// �ϴ� -> ���
//void BinarySearchTree::LeftRotate(Node* x)
//{
//	Node* y = x->right; // y���� �޴´�.
//
//	x->right = y->left; //[2]�� y ���� ������ �̵�
//	
//	if(y->left != _nil) //���� y�� ���� ��尡 ���� �ִٸ� x�� �θ� �������ش�.
//		y->left->parent = x;
//
//	y->parent = x->parent; // y�� �ֻ������ �ø��鼭 x�� �θ��� �޴´�.
//
//	if (x->parent == _nil)
//		_root = y;
//
//	else if (x == x->parent->left) // x�� �θ��� �����̸� y�� �������� ����
//		x->parent->left = y;
//	else
//		x->parent->right = y; // �ƴϸ� ���������� y�� ����
//
//	y->left = x;	//���� ����
//	x->parent = y;
//}
//
//void BinarySearchTree::RightRotate(Node* y)
//{
//	Node* x = y->left; 
//
//	y->left = x->right;
//
//	if (y->right != _nil) 
//		y->right->parent =	y;
//
//	x->parent = y->parent;
//
//	if (y->parent == _nil)
//		_root = x;
//
//	else if (y == y->parent->left)
//		y->parent->left = x;
//	else
//		y->parent->right = x;
//
//	x->right = y;
//	y->parent = x;
//}
