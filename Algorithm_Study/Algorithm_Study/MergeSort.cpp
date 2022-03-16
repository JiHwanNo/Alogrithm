//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//#include <thread>
//// 오늘의 주제 : 정렬
//
//// 힙 정렬
////O(Nlog(N))
//void HeapSort(vector<int>& v)
//{
//	priority_queue<int, vector<int>, greater<int>> pq;
//
//	for (int num : v)
//	{
//		pq.push(num);
//	}
//
//	v.clear();
//	while (pq.empty() == false)
//	{
//		v.push_back(pq.top());
//		pq.pop();
//	}
//}
//
//// 병합 정렬
//// 분할 정복(Divide and Conquer)
//// - 분할(Divide)		문제를 더 단순하게 분할한다.
//// - 정복(Conquer)		분할된 문제를 해결
//// - 결합(Combine)		결과를 취합하여 마무리
//
//// [3][K][7][2][J][4][8][9]			분할한다.
//// [3][K][7][2] [J][4][8][9]		정복한다.
//// [2][3][7][K] [4][8][9][J]		결합한다.
//// [2][3][4][7][8][9][J][K]
//
//// [3][K][7][2][J][4][8][9]			8개 * 1
//// [3][K][7][2] [J][4][8][9]		4개 * 2
//// [3][K] [7][2] [J][4] [8][9]		2개 * 4
//// [3] [K] [7] [2] [J] [4] [8] [9]	1개 * 8
//// [3][K] [2][7] [4][J] [8][9]		2개 * 4
//
//
//// O(NlogN)
//void MergeResult(vector<int>& v, int left, int mid, int right)
//{
//	// [2][3][7][K] [4][8][9][J]
//
//	int leftIdx = left;
//	int rightIdx = mid + 1;
//
//	vector<int> temp;
//
//	while (leftIdx <= mid && rightIdx <= right)
//	{
//		if (v[leftIdx] <= v[rightIdx])
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//		else
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//
//	}
//
//	// 왼쪽이 먼저 끝났으면, 오른쪽 나머지 데이터 복사
//	if (leftIdx > mid)
//	{
//		while (rightIdx <= right)
//		{
//			temp.push_back(v[rightIdx]);
//			rightIdx++;
//		}
//	}
//	else
//	{
//		while (leftIdx <= mid)
//		{
//			temp.push_back(v[leftIdx]);
//			leftIdx++;
//		}
//	}
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		// 시작점이 left이라서
//		v[left + i] = temp[i];
//	}
//}
//
//
//
//
//void MergeSort(vector<int>& v, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	int mid = (left + right) / 2;
//
//	MergeSort(v, left, mid);	// 4
//	MergeSort(v, mid + 1, right);	// 4
//
//	//결과를 합친다.
//	MergeResult(v, left, mid, right);
//}
//
//int main()
//{
//	vector<int> b;
//
//	srand(time(0));
//
//	for (int i = 0; i < 50; i++)
//	{
//		int randValue = rand() % 100;
//		b.push_back(randValue);
//	}
//
//	MergeSort(b, 0, b.size() - 1);
//
//}