//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//#include <thread>
//// 퀵 정렬
//// Quick Sort
//
//// [5][1][3][7][9][2][4][6][8]
//
//int Partition(vector<int>& v, int left, int right)
//{
//	int pivot = v[left];	//5
//	int low = left + 1;		//1 
//	int high = right;		//8
//
//	while (low <= high)
//	{
//		while (low <= right && pivot >= v[low])
//			low++;
//
//		while (high >= left + 1 && pivot <= v[high])
//			high--;
//
//		if (low < high)
//			swap(v[low], v[high]);
//	}
//
//	swap(v[left], v[high]);
//
//	return high;
//}
//// O(N^2) => 최악의 경우.
//// O(NlogN) => 평균적인 경우.
//void QuickSort(vector<int>& v, int left, int right)
//{
//	if (left > right)
//		return;
//
//	int pivot = Partition(v, left, right);
//
//	QuickSort(v, left, pivot - 1);
//	QuickSort(v, pivot + 1, right);
//}
//
//int main()
//{
//	vector<int> v;
//	srand(time(0));
//
//	for (int i = 0; i < 50; i++)
//	{
//		int randValue = rand() % 100;
//		v.push_back(randValue);
//	}
//
//	QuickSort(v, 0, v.size() - 1);
//
//}