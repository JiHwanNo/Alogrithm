//#include <iostream>
//#include <vector>
//using namespace std;
//
//// 그래프 / 트리 응용
//// 오늘의 주제 : 최소 스패닝 트리 (Minimum Spanning Tree)
//
//// 상호 배타적 집합 (Disjoint Set)
//// -> 유니온-파인드 Union - Find (합치기-찾기)
//
//
//// Lineage Battleground 개발
//// 혈맹전 + 서바이벌
//// 1인 팀 1000명 (팀 id 0~999)
//// 동맹 (1번팀 + 2번팀 = 1번팀)
//
//
//// 트리 구조를 이용한 상호 배타적 집합의 표현
//// [0] [1] [2] [3] [4]
//struct Node
//{
//	Node* leader;
//};
//
//// [1]			[3]
//// [2]		   [4][5]
////				[0]
//// 시간복잡도 : 트리의 높이에 비례한 시간이 걸림.
//// 트리를 평평한 구조로 만들어야 효율이 증가한다. 한쪽으로 치우친 트리를 해결해야 한다.
//// -> 트리 높이를 비교하여 트리를 합칠떄, 조절한다.
//// (Union-By-Rank) 랭크에 의한 합치기 최적화
//
//// 시간복잡도 O(Ackermann(n)) = O(1)
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
//
//int main()
//{
//}