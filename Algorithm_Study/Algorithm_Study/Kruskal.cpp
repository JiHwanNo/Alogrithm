//#include <iostream>
//#include <vector>
//#include <list>
//#include <algorithm>
//using namespace std;
//
///*
//Kruskal 알고리즘
//	스패닝 트리	-	간선의 수를 최소화(사이클이 생기면 안된다)해서, 모든 정점을 연결한다.
//					N개의 정점을 N-1개의 간선으로 연결
//					ex) 통신 네트워크 구축
//						-> 실용성이 있을려면, 비용을 최소화 해야한다.
//	크루스칼 MST 알고리즘
//	- 탐욕적인(Greedy) 방법을 이용
//		- 지금 이 순간에 최적인 답을 선택하여 결과를 도출하자.
//		- 모든 길을 확인하고, 최저 비용을 먼저 연결시킨다.
//		- 노드간에 길이 안뚤린 곳이 있으면, 다시 최저 비용을 확인하고 연결시킨다.
//		- 순환이 되지 않도록 항상 주의한다.
//			-> 순환이 되는 노드들을 하나의 묶음으로 취급한다.
//			상호 배타적 집합(Disjoint Set)을 통해 묶어준다,
//*/
//
//// 상호 배타적인 노드를 묶어줄 함수
//class DisjointSet
//{
//public:
//	DisjointSet(int n) : _parent(n), _rank(n, 1) // 트리의 높이
//	{
//		for (int i = 0; i < n; i++)
//		{
//			_parent[i] = i;
//		}
//	}
//
//	int Find(int u)
//	{
//		if (u == _parent[u])
//			return u;
//
//		return _parent[u] = Find(_parent[u]);
//	}
//
//	int Merge(int u, int v)
//	{
//		u = Find(u);
//		v = Find(v);
//
//		if (u == v)
//			return;
//
//		if (_rank[u] > _rank[v])
//			swap(u, v);
//
//		_parent[u] = v;
//
//		if (_rank[u] == _rank[v])
//		{
//			_rank[v]++;
//		}
//	}
//private:
//	vector<int> _parent;
//	vector<int> _rank;
//};
//
//
//struct Vertex
//{
//	// data
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent;
//
//void CreateGraph()
//{
//	vertices.resize(6);
//	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
//
//	adjacent[0][1] = adjacent[1][0] = 15;
//	adjacent[0][3] = adjacent[3][0] = 35;
//	adjacent[1][2] = adjacent[2][1] = 5;
//	adjacent[1][3] = adjacent[3][1] = 10;
//	adjacent[3][4] = adjacent[4][3] = 5;
//	adjacent[3][5] = adjacent[5][3] = 10;
//	adjacent[5][4] = adjacent[4][5] = 5;
//}
//
//struct CostEdge
//{
//	int cost;
//	int u;
//	int v;
//
//	bool operator<(CostEdge& other)
//	{
//		return cost < other.cost;
//	}
//};
//
//
//int Kruskal(vector<CostEdge>& selected)
//{
//	//총비용
//	int ret = 0;
//
//	selected.clear();
//
//	vector<CostEdge> edges;
//	//간선의 비용을 저장할 벡터를 만든다.
//	for (int u = 0; u < adjacent.size(); u++)
//	{
//		for (int v = 0; v < adjacent[u].size(); v++)
//		{
//			//간선끼리 전부 도는데, 중복을 제거하기 위해 u가 클때 한번만 들리도록 한다.
//			if (u > v)
//				continue;
//			// 간선의 비용을 저장하는데, 비용이 없을경우도 대비한다.
//			int cost = adjacent[u][v];
//
//			// 두 정점이 연결 안된경우.
//			if (cost == -1)
//				continue;
//			// 비용을 저장함.
//			edges.push_back(CostEdge{ cost,u,v });
//		}
//	}
//	// 비용을 그리드 알고리즘을 위해 정렬한다.
//	sort(edges.begin(), edges.end());
//
//	// 상호배타적인 노드를 묶어주기 위한 클래스 생성.
//	DisjointSet sets(vertices.size());
//
//	// 비용이 적은순 (그리드)으로 하나씩 간선을 꺼낸다.
//	for (CostEdge& edge : edges)
//	{
//		//만약 이미 묶여 있다면 패스
//		if (sets.Find(edge.u) == sets.Find(edge.v))
//			continue;
//		//아니라면 합쳐준다.
//		sets.Merge(edge.u, edge.v);
//		selected.push_back(edge);
//		ret += edge.cost;
//	}
//	return ret;
//}
//
//int main()
//{
//	CreateGraph();
//
//	vector<CostEdge> selected;
//	int cost = Kruskal(selected);
//}