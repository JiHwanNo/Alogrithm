#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include <thread>
// ������ ���� : ����

// 1_ ���� ���� (Bubble Sort)
// ���� ó������ �������� ���� ���� ���Ͽ� �����Ѵ�.
// �ð� ���⵵ (N-1) + (N-2) + (N-3) ... +2+1
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

//2_ ���� ���� (Selection Sort)
// ��� Ȯ���Ͽ�, ������ ���� ���� �������ش�.
// �ð����⵵ O(N^2)
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

// 3_ ���� ���� (Insertion Sort)
// ������ ���¿��� �ϳ��ϳ� �̾Ƽ� ���ĵ� vector�� �־��ش�.
// �ð����⵵ O(N^2)
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