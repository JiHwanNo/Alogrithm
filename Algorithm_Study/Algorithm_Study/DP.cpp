//#include <iostream>
//#include <vector>
//#include <list>
//#include <algorithm>
//#include <windows.h>
//using namespace std;
//
//// 동적 계획법 (DP)
//
//// memoization
//int cache[50][50];
//
//// n개에서 r개를 추출할 경우의 수를 계산하는 함수
//int combination(int n, int r)
//{
//	// 0개를 뽑을 경우 및 n개에서 n개를 뽑을 경우 경우의 수는 1개이다. 
//	if (r == 0 || n == r)
//		return 1;
//
//	// 이미 답을 구한 적 있으면 바로 반환
//	int& ret = cache[n][r];
//	if (ret != -1)
//		return ret;
//
//	// 새로 답을 구해서 캐시에 저장
//	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
//}
//// 재귀 함수를 하게되면 중복계산이 발생하므로 이를 우회하거나 막는다면, 효율적인 계산이 가능하다.
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