#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include <thread>
// 오늘의 주제 : 정렬

// 1_ 버블 정렬 (Bubble Sort)
// 가장 처음부터 차례차례 다음 수와 비교하여 정렬한다.
// 시간 복잡도 (N-1) + (N-2) + (N-3) ... +2+1
// = O(N^2)
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (v[j] > v[j+1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

//2_ 선택 정렬 (Selection Sort)
// 모두 확인하여, 정렬할 수를 고르고 정렬해준다.
// 시간복잡도 O(N^2)
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();
	
	for (int i = 0; i < n-1; i++)
	{
		int bestIDX = i;
		for (int j = i+1; j < n; j++)
		{
			if (v[j] < v[bestIDX])
				bestIDX = j;
		}

		int temp = v[i];
		v[i] = v[bestIDX];
		v[bestIDX] = temp;
	}
}

// 3_ 삽입 정렬 (Insertion Sort)
// 기존의 형태에서 하나하나 뽑아서 정렬된 vector에 넣어준다.
// 시간복잡도 O(N^2)
void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();

	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];
		int j;

		for (j = i - 1; j >= 0; j++)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}


int main()
{
	vector<int> b{1, 4, 5, 3, 12, 1551, 122, 11};
	std::sort(b.begin(), b.end());
	
	BubbleSort(b);

}