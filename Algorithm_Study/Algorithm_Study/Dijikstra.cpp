//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//
//// 비용적인 경로를 생각하여 경로를 탐색한다.
//
//
//struct Vertex
//{
//	// data
//};
//
//vector<Vertex> vertices; // 데이터 동적배열 노드을 만든다.
//vector<vector<int>> adjacent; // 간선을 만든다.
//
//void CreateGraph()
//{
//	vertices.reserve(6);
//	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//	adjacent[0][1] = 15;
//	adjacent[0][3] = 35;
//
//	adjacent[1][0] = 15;
//	adjacent[1][2] = 5;
//	adjacent[1][3] = 10;
//
//	adjacent[3][4] = 5;
//	adjacent[5][4] = 5;
//}
//
//
//void Dijikstra(int here)
//{
//	struct VertextCost
//	{
//		int vertex;
//		int cost;
//	};
//
//	list<VertextCost> discovered; // 발견 목록
//	vector<int> best(6, INT32_MAX); // 각 정점별로 지금까지 발견한 최소 거리
//	vector<int> parent(6, -1);
//
//	// 시작점을 방문한다. 
//	discovered.push_back(VertextCost{ here , 0 });
//	best[here] = 0;
//	parent[here] = 0;
//
//	while (discovered.empty() == false)
//	{
//		//제일 좋은 후보를 찾는다.
//		list<VertextCost>::iterator bestlt;
//		int bestCost = INT32_MAX; // 임의의 값을 넣는다.
//
//		for (auto it = discovered.begin(); it != discovered.end(); it++)
//		{
//			const int vertex = it->vertex;	// 0	
//			const int cost = it->cost;		// 0
//
//			if (cost < bestCost)	// 0 < 2147483647
//			{
//				bestCost = cost; // bestCost = 0
//				bestlt = it;		// bestlt = 0
//			}
//		}
//
//		int cost = bestlt->cost; //cost = 0
//		here = bestlt->vertex;
//		discovered.erase(bestlt); // 방문 리스트에서 삭제
//
//		// 방문? 더 짧은 경로를 뒤늦게 찾았다면 스킵.
//		if (best[here] < cost)
//			continue;
//
//		//방문
//		for (int i = 0; i < 6; i++)
//		{
//			// 연결되지 않았으면 스킵.
//			if (adjacent[here][i] == -1)
//				continue;
//
//			//더 좋은 경로를 과거에 찾았으면 스킵.
//			int nextCost = best[here] + adjacent[here][i]; // 0의 경우 15 / 35
//			if (nextCost >= best[i]) // 4번 과정에서 best[3] = 35 탈락
//				continue;
//
//			best[i] = nextCost;		// best[1] = 15; //best[3] = 35 
//			parent[i] = here;		//parent[1] = 0; // parent[3] = 0;
//			discovered.push_back(VertextCost{ i, nextCost });
//
//			//discoverd => 2 {1, 15} {3, 35};
//		}
//
//	}
//	int a = 3;
//}
//int main()
//{
//	CreateGraph();
//
//
//	Dijikstra(0);
//}