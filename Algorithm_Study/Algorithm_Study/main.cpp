#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <queue>
using namespace std;

void CreateGraph_1()
{

	struct Vertex
	{
		vector<Vertex*> edges;
		// 정점을 연결해주는 선.
	};

	vector<Vertex> v;
	v.resize(6); // 정점의 갯수는 6

	v[0].edges.push_back(&v[1]);
	v[0].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[2]);
	v[1].edges.push_back(&v[3]);
	v[2].edges.push_back(&v[4]);
	v[3].edges.push_back(&v[6]);
	v[4].edges.push_back(&v[5]);
	v[4].edges.push_back(&v[7]);
	v[4].edges.push_back(&v[6]);
	v[6].edges.push_back(&v[8]);

	// Q)  0 -> 3번 정점이 연결되어 있나요?
	bool connected = false;
	for (Vertex* edge : v[0].edges)
	{
		if (edge == &v[3])
		{
			connected = true;
			break;
		}
	}

}

void CreateGraph_2()
{

	vector<vector<int>> adjacent(6);
	adjacent[0] = { 1,3 };
	adjacent[1] = { 0,2,3 };
	adjacent[3] = { 4 };
	adjacent[5] = { 4 };

	bool connected = false;
	for (int vertex : adjacent[0])
	{
		if (vertex == 3)
		{
			connected = true;
			break;
		}
	}

	vector<int>& adj = adjacent[0];
	bool sonnected2 = (std::find(adj.begin(), adj.end(), 3) != adj.end());
}

void CreateGraph_3()
{
	//읽는 방법 : adjacent[from][to]
	//행렬을 이용한 그래프 표현(2차원 배열)
	//메모리 소모가 심하지만, 빠른 접근이 가능하다.
	// 간선이 많은 경우 이점이 있다.
	vector<vector<bool>> adjacent(6, vector<bool>(6,false));
	adjacent[0][1] = true;
	adjacent[0][3] = true;
	adjacent[1][0] = true;
	adjacent[1][2] = true;
	adjacent[1][3] = true;
	adjacent[3][4] = true;
	adjacent[5][4] = true;
	
	bool connected = adjacent[0][3];

	vector<vector<int>> adjacent2 =
	{
		vector<int>{-1,15,-1,35,-1,-1},
		vector<int>{15,-1,-+5,10,-1,-1},
		vector<int>{-1,-1,-1,-1,-1,-1},
		vector<int>{-1,-1,-1,-1,+5,-1},
		vector<int>{-1,-1,-1,-1,-1,-1},
		vector<int>{-1,-1,-1,-1,+5,-1},
	};

}
int main()
{
	CreateGraph_1();
}