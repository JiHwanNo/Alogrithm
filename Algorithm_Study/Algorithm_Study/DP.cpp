//#include <iostream>
//#include <vector>
//#include <list>
//#include <algorithm>
//#include <windows.h>
//using namespace std;
//
//// ���� ��ȹ�� (DP)
//
//// memoization
//int cache[50][50];
//
//// n������ r���� ������ ����� ���� ����ϴ� �Լ�
//int combination(int n, int r)
//{
//	// 0���� ���� ��� �� n������ n���� ���� ��� ����� ���� 1���̴�. 
//	if (r == 0 || n == r)
//		return 1;
//
//	// �̹� ���� ���� �� ������ �ٷ� ��ȯ
//	int& ret = cache[n][r];
//	if (ret != -1)
//		return ret;
//
//	// ���� ���� ���ؼ� ĳ�ÿ� ����
//	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
//}
//// ��� �Լ��� �ϰԵǸ� �ߺ������ �߻��ϹǷ� �̸� ��ȸ�ϰų� ���´ٸ�, ȿ������ ����� �����ϴ�.
//
//int main()
//{
//	::memset(cache, -1, sizeof(cache));
//
//	__int32 start = GetTickCount64();
//
//	int lotto = combination(45, 6);
//
//	__int32 end = GetTickCount64();
//
//	cout << lotto << endl;
//	cout << end - start << " ms" << endl;
//}