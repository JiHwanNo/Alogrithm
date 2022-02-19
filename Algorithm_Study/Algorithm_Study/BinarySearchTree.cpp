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

//3���� ����Ǽ�
//1. ����� ��忡 �ڽ��� ���� ���
//2. ����� ��忡 �ڽ��� 1���� �ִ°��.
//3. ������ ��忡 �ڽ��� �� ���� �ִ� ���.
void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	//���� Node�� ���� ���.
	if (node == nullptr)
		return;

	//���� �ڽ��� ���� ���. 
	//���� ������ ��嵵 ���� ���, ������ ���� nullptr�̹Ƿ� Replace(node, nullptr)�� �̷�����Եȴ�.
	//�׷��Ƿ� �ڽ��� ���� ���� ���� �ڽ��� ���� ��� 2������ ���ÿ� ������ �� �ִ�.
	if (node->left == nullptr)
		Replace(node, node->right);
	// ������ �ڽ� �� ���� ���.
	else if (node->right == nullptr)
		Replace(node, node->left);
	else 
	{
		// ���ʿ� �ִ� ���. ����� ���� Node�� ���� ������ ã�� ���� ���� �ٲ� ��, �����ش�.
		Node* next = Next(node);
		node->key = next->key;
		Delete(next);
	}

}

// u ��忡�� v ���� ��ü�ϴ� �۾�
void BinarySearchTree::Replace(Node* u, Node* v)
{
	// ���� �θ� ���ٸ� �ֻ���̴�.
	if (u->parent == nullptr)
		_root = v;
	// u�� �θ��� ���� ��尡 u�� ���
	else if (u == u->parent->left)
		u->parent->left = v;
	else // u�� �θ��� ������ ��尡 u�� ���
		u->parent->right = v;
	//v�� u�� �θ�� ��������ش�.
	if (v)
		v->parent = u->parent;

	delete u;
}
