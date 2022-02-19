//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//
//// ������ ���� : ���� Ž�� Ʈ��
//
//// ���� Ž��(binary search)
//// ��Ȳ) �迭�� �����Ͱ� ���ĵǾ� �ִ�.
//
//// Q) 82��� ���ڰ� �迭�� �ֽ��ϱ�?
//// A)
//// [1][8][15][23][32][44][56][63][81][91]
//
//// ���ĵ� �迭�� �̿��ؼ� ���� Ž�� ���� (numbers[mid])
//// ���ĵ� ���� ������δ� �Ұ� (���� ���� X)
//vector<int> numbers;
//
////O(logN)
//void BinarySearch(int n)
//{
//	int left = 0;
//	int right = (int)numbers.size() - 1;
//
//	while (left <= right)
//	{
//		cout << "Ž�� ���� : " << left << "~" << right << endl;
//		int mid = (left + right) / 2;
//
//		if (n < numbers[mid])
//		{
//			cout << n << "<" << numbers[mid] << endl;
//			right = mid - 1;
//		}
//		else if (n > numbers[mid])
//		{
//			cout << n << ">" << numbers[mid] << endl;
//			left = mid + 1;
//		}
//		else
//		{
//			cout << "ã�� !" << endl;
//			break;
//		}
//	}
//}
//int main()
//{
//	numbers = vector<int>{ 1,8,15,23,32,44,56,63,81,91 };
//	BinarySearch(81);
//}