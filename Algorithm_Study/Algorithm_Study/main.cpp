#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include "BinarySearchTree.h"
#include <thread>
int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(40);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(100);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(150);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(401);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(5);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Insert(78);
	bst.Print();
	this_thread::sleep_for(1s);

	//bst.Print_Inorder();
	bst.Print();
}