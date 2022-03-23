//#include <iostream>
//#include <vector>
//#include <list>
//#include <algorithm>
//using namespace std;
//
///*
//Kruskal �˰���
//	���д� Ʈ��	-	������ ���� �ּ�ȭ(����Ŭ�� ����� �ȵȴ�)�ؼ�, ��� ������ �����Ѵ�.
//					N���� ������ N-1���� �������� ����
//					ex) ��� ��Ʈ��ũ ����
//						-> �ǿ뼺�� ��������, ����� �ּ�ȭ �ؾ��Ѵ�.
//	ũ�罺Į MST �˰���
//	- Ž������(Greedy) ����� �̿�
//		- ���� �� ������ ������ ���� �����Ͽ� ����� ��������.
//		- ��� ���� Ȯ���ϰ�, ���� ����� ���� �����Ų��.
//		- ��尣�� ���� �ȶԸ� ���� ������, �ٽ� ���� ����� Ȯ���ϰ� �����Ų��.
//		- ��ȯ�� ���� �ʵ��� �׻� �����Ѵ�.
//			-> ��ȯ�� �Ǵ� ������ �ϳ��� �������� ����Ѵ�.
//			��ȣ ��Ÿ�� ����(Disjoint Set)�� ���� �����ش�,
//*/
//
//// ��ȣ ��Ÿ���� ��带 ������ �Լ�
//class DisjointSet
//{
//public:
//	DisjointSet(int n) : _parent(n), _rank(n, 1) // Ʈ���� ����
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
//	//�Ѻ��
//	int ret = 0;
//
//	selected.clear();
//
//	vector<CostEdge> edges;
//	//������ ����� ������ ���͸� �����.
//	for (int u = 0; u < adjacent.size(); u++)
//	{
//		for (int v = 0; v < adjacent[u].size(); v++)
//		{
//			//�������� ���� ���µ�, �ߺ��� �����ϱ� ���� u�� Ŭ�� �ѹ��� �鸮���� �Ѵ�.
//			if (u > v)
//				continue;
//			// ������ ����� �����ϴµ�, ����� ������쵵 ����Ѵ�.
//			int cost = adjacent[u][v];
//
//			// �� ������ ���� �ȵȰ��.
//			if (cost == -1)
//				continue;
//			// ����� ������.
//			edges.push_back(CostEdge{ cost,u,v });
//		}
//	}
//	// ����� �׸��� �˰����� ���� �����Ѵ�.
//	sort(edges.begin(), edges.end());
//
//	// ��ȣ��Ÿ���� ��带 �����ֱ� ���� Ŭ���� ����.
//	DisjointSet sets(vertices.size());
//
//	// ����� ������ (�׸���)���� �ϳ��� ������ ������.
//	for (CostEdge& edge : edges)
//	{
//		//���� �̹� ���� �ִٸ� �н�
//		if (sets.Find(edge.u) == sets.Find(edge.v))
//			continue;
//		//�ƴ϶�� �����ش�.
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