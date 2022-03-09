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
//	//검사
//	newNode->left = _nil;
//	newNode->right = _nil;
//	newNode->color = Color::Red;
//
//	InsertFixup(newNode);
//}
//
//void BinarySearchTree::InsertFixup(Node* node)
//{
//	// p = 부모, uncle = 부모 반대편 노드
//	// 1) p = red, uncle = red
//	// -> p = black, uncle = black, pp = red로 바꿈
//	// 2) p = red, uncle = black (Triangle)
//	// -> 회전을 통해 3)으로 바꿔줌
//	// 3) p = red, uncle = black (list)
//	// -> 색상 변경 + 회전
//	
//	// 자신의 부모의 노드색이 레드인지 블랙인지 체크해준다.
//	// 자신도 레드 노드이므로 부모(레드) / 자식 (레드)는 알고리즘 가정에 위반된다.
//	while (node->parent->color == Color::Red)
//	{
//		//노드의 부모가 할머니 노드의 왼쪽편이라면,
//		if (node->parent == node->parent->parent->left)
//		{
//			Node* uncle = node->parent->parent->right;
//			if (uncle->color == Color::Red) //1) 상황
//			{
//				node->parent->color = Color::Black; //p
//				uncle->color = Color::Black; //uncle
//				node->parent->parent->color = Color::Red; //pp
//				node = node->parent->parent; // 상단의 노드들을 다시 체크해준다.
//			}
//
//			else //2)상황 
//			{
//			//			[pp(B)]
//			//		[p(R)]			[u(B)]
//			//			[n(R)]
//			// 
//			// ㄱ자 (Triangle)를 
//			// 
//			//			[pp(B)]
//			//		[n(R)]			[u(B)]
//			//	[p(R)]
//			// 
//			// 상황으로 바꾼다.(정렬이 일어남)
//				if (node == node->parent->right)
//				{
//					node = node->parent;
//					LeftRotate(node);
//				}
//
//				//3) 상황
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
//			// 1) 상황
//			//			[pp(B)]
//			//		[u(B)]  [p(R)]
//			//                [n(R)]
//			Node* uncle = node->parent->parent->left; 
//			if (uncle->color == Color::Red) //1) 상황
//			{
//				node->parent->color = Color::Black; //p
//				uncle->color = Color::Black; //uncle
//				node->parent->parent->color = Color::Red; //pp
//				node = node->parent->parent; // 상단의 노드들을 다시 체크해준다.
//			}
//			else 
//			{
//				// 2) 상황 
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
//				// 3) 상황
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
//	//지울 Node가 없는 경우.
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
//		// 양쪽에 있는 경우.
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
//			//case 3번	DB의 sibling 노드가 Red일 경우
//			//s = black, p = red (s <-> p 색상 교환)
//			//DB 방향으로 rotage(p)
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
//			//case 4번 DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
//			//추가 Black을 parent에게 이전
//			//p가 Red이면 Black 됨
//			//p가 Black이면 DB 됨
//			//s = red
//			//p를 대상으로 알고리즘 이어서 실행(DB가 여전히 존재하면)
//
//			if (s->left->color == Color::Black && s->right->color == Color::Black)
//			{
//				s->color = Color::Red;
//				x = x->parent; // p를 대상으로 whild문을 돌면서 나머지 부분을 check 해준다.
//			}
//			else
//			{
//				//case 5번 DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
//				//s < ->near 색상 교환
//				//far 방향으로 rotate(s)
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
//				//case 6 DB의 sibling 노드가 Black && sibling의 far child = red
//				//p < ->s 색상 교환
//				//far = black
//				//rotate(p) (DB방향으로)
//				//추가 Black 제거
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
//				//case 3번	DB의 sibling 노드가 Red일 경우
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
//				//case 4번 DB의 sibling 노드가 Black && sibling의 양쪽 자식도 Black
//
//				if (s->right->color == Color::Black && s->left->color == Color::Black)
//				{
//					s->color = Color::Red;
//					x = x->parent; // p를 대상으로 whild문을 돌면서 나머지 부분을 check 해준다.
//				}
//				else
//				{
//					//case 5번 DB의 sibling 노드가 Black && sibling의 near child = red, far child = black
//
//					if (s->left->color == Color::Black)
//					{
//						s->right->color = Color::Black;
//						s->color = Color::Red;
//						LeftRotate(s);
//						s = x->parent->left;
//					}
//
//					//case 6 DB의 sibling 노드가 Black && sibling의 far child = red
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
//// u 노드에서 v 노드로 교체하는 작업
//void BinarySearchTree::Replace(Node* u, Node* v)
//{
//	// 만약 부모가 없다면 최상단이다.
//	if (u->parent == _nil)
//		_root = v;
//	// u의 부모의 왼쪽 노드가 u일 경우
//	else if (u == u->parent->left)
//		u->parent->left = v;
//	else // u의 부모의 오른쪽 노드가 u일 경우
//		u->parent->right = v;
//	//v를 u의 부모와 연결시켜준다.
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
//// 상단 -> 하단		RightRotate
//// 하단 -> 상단		LeftRotate
//
//// 하단 -> 상단
//void BinarySearchTree::LeftRotate(Node* x)
//{
//	Node* y = x->right; // y값을 받는다.
//
//	x->right = y->left; //[2]을 y 왼쪽 밑으로 이동
//	
//	if(y->left != _nil) //만약 y의 왼쪽 노드가 값이 있다면 x로 부모를 변경해준다.
//		y->left->parent = x;
//
//	y->parent = x->parent; // y를 최상단으로 올리면서 x의 부모값을 받는다.
//
//	if (x->parent == _nil)
//		_root = y;
//
//	else if (x == x->parent->left) // x가 부모의 왼쪽이면 y를 그쪽으로 연결
//		x->parent->left = y;
//	else
//		x->parent->right = y; // 아니면 오른쪽으로 y를 연결
//
//	y->left = x;	//서로 연결
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
