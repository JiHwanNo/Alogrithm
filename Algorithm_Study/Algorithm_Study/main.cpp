#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;

	bst.Insert(50);
	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(40);
	bst.Insert(100);
	bst.Insert(150);
	bst.Insert(401);
	bst.Insert(5);
	bst.Insert(78);

	//bst.Print_Inorder();
	bst.Print();
}