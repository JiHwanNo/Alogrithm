#include "BinarySearchTree.h"
#include<iostream>
#include <Windows.h>

using namespace std;


void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x,y);
	cout << node->key;
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);

}

void BinarySearchTree::Print_Inorder(Node* node)
{
	if (node == nullptr)
		return;

	cout << node->key << endl;
	Print_Inorder(node->left);
	Print_Inorder(node->right);
	
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || key == node->key)
		return node;

	if (key < node->key)
		Search(node->left, key);
	else
		Search(node->right, key);
}

Node* BinarySearchTree::Search2(Node* node, int key)
{
	while (node && node->key !=key)
	{
		if (node->key < key)
			node =node->right;
		else
			node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	while (node->right)
	{
		node = node->right;
	}
	return node;
}

Node* BinarySearchTree::Min(Node* node)
{
	while (node->left)
	{
		node = node->left;
	}
	return node;
}


Node* BinarySearchTree::Next(Node* node)
{
	if (node->right)
		return Min(node->right);

	Node* parent = node->parent;
	
	while (node == parent->right && parent)
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

	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	Node* node = _root;
	Node* parent = nullptr;

	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	newNode->parent = parent;
	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
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
