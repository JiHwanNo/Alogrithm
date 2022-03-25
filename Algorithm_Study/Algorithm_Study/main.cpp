#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <windows.h>
using namespace std;

// 동적 계획법 (DP)
// TRIANGLE_PATH
//	(0,0)부터 시작해서 아래 OR 아래우축으로 이동 가능
//  만나는 숫자를 모두 더함
//  더한 숫자가 최대가 되는 경로의 합은?

//	6 
//	1 2
//	3 7 4
//	9 4 1 7 
//	2 7 5 9 4

int N;
vector<vector <int>> board;
vector<vector <int>> cache;
vector<vector <int>> nextX;

int path(int y, int x)
{
	//기저 사항
	if (y == N - 1)
		return board[y][x];	

	//캐시 확인
	int& ret = cache[y][x];
	if (ret != -1)
		return ret;
	// 경로 기록
	{
		int nextBottom = path(y + 1, x);
		int nextBottomRight = path(y + 1, x + 1);
		if (nextBottom > nextBottomRight)
			nextX[y][x] = x;
		else
			nextX[y][x] = x + 1;
	}

	ret = board[y][x] + max(path(y + 1, x), path(y + 1, x + 1));

	return ret;
}

int main()
{ 
	board = vector<vector<int>>
	{
		{6},
		{1,2},
		{3,7,4},
		{9,4,1,7},
		{2,7,5,9,4},
	};
	N = board.size();
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	nextX = vector<vector<int>>(N, vector<int>(N));


	int ret = path(0, 0);
	cout << ret << endl;
	int x = 0;
	int y = 0;
	while (y<N)
	{
		cout << board[y][x] << "->";

		x = nextX[y][x];
		y++;
	}
}