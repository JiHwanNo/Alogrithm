//#include <iostream>
//#include <vector>
//using namespace std;
//
//// �׷��� / Ʈ�� ����
//// ������ ���� : �ּ� ���д� Ʈ�� (Minimum Spanning Tree)
//
//// ��ȣ ��Ÿ�� ���� (Disjoint Set)
//// -> ���Ͽ�-���ε� Union - Find (��ġ��-ã��)
//
//
//// Lineage Battleground ����
//// ������ + �����̹�
//// 1�� �� 1000�� (�� id 0~999)
//// ���� (1���� + 2���� = 1����)
//
//
//// Ʈ�� ������ �̿��� ��ȣ ��Ÿ�� ������ ǥ��
//// [0] [1] [2] [3] [4]
//struct Node
//{
//	Node* leader;
//};
//
//// [1]			[3]
//// [2]		   [4][5]
////				[0]
//// �ð����⵵ : Ʈ���� ���̿� ����� �ð��� �ɸ�.
//// Ʈ���� ������ ������ ������ ȿ���� �����Ѵ�. �������� ġ��ģ Ʈ���� �ذ��ؾ� �Ѵ�.
//// -> Ʈ�� ���̸� ���Ͽ� Ʈ���� ��ĥ��, �����Ѵ�.
//// (Union-By-Rank) ��ũ�� ���� ��ġ�� ����ȭ
//
//// �ð����⵵ O(Ackermann(n)) = O(1)
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
//
//int main()
//{
//}