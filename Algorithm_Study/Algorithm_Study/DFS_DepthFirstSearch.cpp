//#include <iostream>
//#include <vector>
//using namespace std;
//
//// DFS (Depth First Search) 깊이 우선 탐색
//// 일단 갈 수 있는 방향0(깊이)을 가보고 탐색한다.
//// BFS (Breadth First Search) 너비 우선 탐색
//// 출발점에서 갈 수 있는 방향을 먼저 탐색 후 다음 방향을 설정한다.
//
//struct Vertex
//{
//	//data
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent;
//vector<bool> visited;
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6);
//	adjacent[0].push_back(1);
//	adjacent[0].push_back(3);
//	adjacent[1].push_back(0);
//	adjacent[1].push_back(2);
//	adjacent[1].push_back(3);
//	adjacent[3].push_back(4);
//	adjacent[5].push_back(4);
//}
//
//void Dfs(int here)
//{
//	visited[here] = true;
//	cout << "visited : " << here << endl;
//
//	//인접 리스트 version
//	//모든 인접 정점을 순회한다.
//	for (int i = 0; i < adjacent[here].size(); i++)
//	{
//		int there = adjacent[here][i];
//		if (visited[there] == false)
//		{
//			Dfs(there);
//		}
//	}
//}
//void CreateGraph2()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6);
//
//	adjacent = vector<vector<int>>
//	{
//		{0,1,0,1,0,0},
//		{1,0,1,1,0,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//		{0,0,0,0,0,0},
//		{0,0,0,0,1,0},
//	};
//}
////DFS
//
//void Dfs2(int here)
//{
//	visited[here] = true;
//	cout << "visited : " << here << endl;
//
//	for (int i = 0; i < adjacent[here].size(); i++)
//	{
//		if (adjacent[here][i] == 0)
//			continue;
//
//		if (visited[i] == false)
//			Dfs2(i);
//	}
//}
//
//void DfsAll()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		if (visited[i] == false)
//			Dfs(i);
//	}
//}
//
//int main()
//{
//	CreateGraph2();
//
//	visited = vector<bool>(6, false);
//
//	Dfs2(0);
//	//DfsAll();
//}