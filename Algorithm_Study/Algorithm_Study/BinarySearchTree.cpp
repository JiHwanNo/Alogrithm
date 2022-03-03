#include "BinarySearchTree.h"
#include<iostream>
#include <Windows.h>

using namespace std;
enum  class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	GREEN = FOREGROUND_GREEN,
	BLUE = FOREGROUND_BLUE,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};

void SetCursorColor(ConsoleColor color)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::SetConsoleTextAttribute(output, static_cast<SHORT>(color));
}

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

BinarySearchTree::BinarySearchTree()
{
	_nil = new Node();
	_root = _nil;
}

BinarySearchTree::~BinarySearchTree()
{
	delete _nil;
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == _nil)
		return;

	SetCursorPosition(x,y);

	if (node->color == Color::Black)
		SetCursorColor(ConsoleColor::BLUE);
	else 
		SetCursorColor(ConsoleColor::RED);

	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

	SetCursorColor(ConsoleColor::WHITE);
}


Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == _nil || key == node->key)
		return node;

	if (key < node->key)
		Search(node->left, key);
	else
		Search(node->right, key);
}


Node* BinarySearchTree::Max(Node* node)
{
	while (node->right != _nil)
	{
		node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left != _nil)
	{
		node = node->left;
	}
	return node;
}


Node* BinarySearchTree::Next(Node* node)
{
	if (node->right != _nil)
		return Min(node->right);

	Node* parent = node->parent;
	
	while (node == parent->right && parent != _nil)
	{
		node = parent;
		parent = parent->parent;
	}

	return parent;
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	Node* node = _root;
	Node* parent = _nil;

	while (node != _nil)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;
	if (parent == _nil)
		_root = newNode;
	else if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	//검사
	newNode->left = _nil;
	newNode->right = _nil;
	newNode->color = Color::Red;

	InsertFixup(newNode);
}

void BinarySearchTree::InsertFixup(Node* node)
{
	// p = 부모, uncle = 부모 반대편 노드
	// 1) p = red, uncle = red
	// -> p = black, uncle = black, pp = red로 바꿈
	// 2) p = red, uncle = black (Triangle)
	// -> 회전을 통해 3)으로 바꿔줌
	// 3) p = red, uncle = black (list)
	// -> 색상 변경 + 회전
	
	// 자신의 부모의 노드색이 레드인지 블랙인지 체크해준다.
	// 자신도 레드 노드이므로 부모(레드) / 자식 (레드)는 알고리즘 가정에 위반된다.
	while (node->parent->color == Color::Red)
	{
		//노드의 부모가 할머니 노드의 왼쪽편이라면,
		if (node->parent == node->parent->parent->left)
		{
			Node* uncle = node->parent->parent->right;
			if (uncle->color == Color::Red) //1) 상황
			{
				node->parent->color = Color::Black; //p
				uncle->color = Color::Black; //uncle
				node->parent->parent->color = Color::Red; //pp
				node = node->parent->parent; // 상단의 노드들을 다시 체크해준다.
			}

			else //2)상황 
			{
			//			[pp(B)]
			//		[p(R)]			[u(B)]
			//			[n(R)]
			// 
			// ㄱ자 (Triangle)를 
			// 
			//			[pp(B)]
			//		[n(R)]			[u(B)]
			//	[p(R)]
			// 
			// 상황으로 바꾼다.(정렬이 일어남)
				if (node == node->parent->right)
				{
					node = node->parent;
					LeftRotate(node);
				}

				//3) 상황

				//			[pp(R)]
				//		[p(B)]  [u(B)]
				//    [n(R)]

				//			[p(B)]
				//		[n(R)]  [pp(R)]
				//				    [u(B)]
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				RightRotate(node->parent->parent);
			}
		}
		else
		{
			// 1) 상황
			//			[pp(B)]
			//		[u(B)]  [p(R)]
			//                [n(R)]
			Node* uncle = node->parent->parent->left; 
			if (uncle->color == Color::Red) //1) 상황
			{
				node->parent->color = Color::Black; //p
				uncle->color = Color::Black; //uncle
				node->parent->parent->color = Color::Red; //pp
				node = node->parent->parent; // 상단의 노드들을 다시 체크해준다.
			}
			else 
			{
				// 2) 상황 
				//			[pp(B)]
				//		[u(B)]  [p(R)]
				//            [n(R)]   
				//  
				//			[pp(B)]
				//		[u(B)]  [p(R)]
				//                 [n(R)]                      
				if (node == node->parent->left)
				{
					node = node->parent;
					RightRotate(node);
				}

				// 3) 상황
				//			[p(B)]
				//		[pp(R)]  [n(R)]
				//   [u(B)]   
				node->parent->color = Color::Black;
				node->parent->parent->color = Color::Red;
				LeftRotate(node->parent->parent);
			}
		}
	}
		_root->color = Color::Black;
}

//3가지 경우의수
//1. 지우는 노드에 자식이 없는 경우
//2. 지우는 노드에 자식이 1개만 있는경우.
//3. 지누은 노드에 자식이 양 방향 있는 경우.
void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	//지울 Node가 없는 경우.
	if (node == nullptr)
		return;

	//왼쪽 자식이 없을 경우. 
	//만약 오른쪽 노드도 없을 경우, 오른쪽 노드는 nullptr이므로 Replace(node, nullptr)로 이루어지게된다.
	//그러므로 자식이 없을 경우와 왼쪽 자식이 없을 경우 2가지를 동시에 실행할 수 있다.
	if (node->left == nullptr)
		Replace(node, node->right);
	// 오른쪽 자식 이 없을 경우.
	else if (node->right == nullptr)
		Replace(node, node->left);
	else 
	{
		// 양쪽에 있는 경우. 지우고 싶은 Node의 다음 순번을 찾아 서로 값을 바꾼 후, 지워준다.
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

// u 노드에서 v 노드로 교체하는 작업
void BinarySearchTree::Replace(Node* u, Node* v)
{
	// 만약 부모가 없다면 최상단이다.
	if (u->parent == nullptr)
		_root = v;
	// u의 부모의 왼쪽 노드가 u일 경우
	else if (u == u->parent->left)
		u->parent->left = v;
	else // u의 부모의 오른쪽 노드가 u일 경우
		u->parent->right = v;
	//v를 u의 부모와 연결시켜준다.
	if (v)
		v->parent = u->parent;

	delete u;
}

//			[y]
//		[x]		[3]
//	   [1][2]

//			[x]
//		[1]		[y]
//			   [2][3]
// 상단 -> 하단		RightRotate
// 하단 -> 상단		LeftRotate

// 하단 -> 상단
void BinarySearchTree::LeftRotate(Node* x)
{
	Node* y = x->right; // y값을 받는다.

	x->right = y->left; //[2]을 y 왼쪽 밑으로 이동
	
	if(y->left != _nil) //만약 y의 왼쪽 노드가 값이 있다면 x로 부모를 변경해준다.
		y->left->parent = x;

	y->parent = x->parent; // y를 최상단으로 올리면서 x의 부모값을 받는다.

	if (x->parent == _nil)
		_root = y;

	else if (x == x->parent->left) // x가 부모의 왼쪽이면 y를 그쪽으로 연결
		x->parent->left = y;
	else
		x->parent->right = y; // 아니면 오른쪽으로 y를 연결

	y->left = x;	//서로 연결
	x->parent = y;
}

void BinarySearchTree::RightRotate(Node* y)
{
	Node* x = y->left; 

	y->left = x->right;

	if (y->right != _nil) 
		y->right->parent =	y;

	x->parent = y->parent;

	if (y->parent == _nil)
		_root = x;

	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;
}
