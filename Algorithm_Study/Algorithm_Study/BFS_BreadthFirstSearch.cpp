//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//// DFS (Depth First Search) ���� �켱 Ž��
//// �ϴ� �� �� �ִ� ����0(����)�� ������ Ž���Ѵ�.
//// BFS (Breadth First Search) �ʺ� �켱 Ž��
//// ��������� �� �� �ִ� ������ ���� Ž�� �� ���� ������ �����Ѵ�.
//
//struct Vertex
//{
//	//data
//};
//
//vector<Vertex> vertices;
//vector<vector<int>> adjacent;
//vector<bool> discoversd;
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
//void Bfs(int here)
//{
//	//������ ���� �߰� �Ǿ���?
//	vector<int> parent(6, -1);
//	//���������� ��ŭ ������ �ֳ�?
//	vector<int> distance(6, -1);
//
//	queue<int> q;
//	q.push(here);
//	discoversd[here] = true;
//
//
//	parent[here] = here;
//	distance[here] = 0;
//
//	while (q.empty() == false)
//	{
//		here = q.front();
//		q.pop();
//
//		cout << "Visited : " << here << endl;
//
//
//		for (int there : adjacent[here])
//		{
//			if (discoversd[there])
//				continue;
//
//			q.push(there);
//			discoversd[there] = true;
//
//			parent[there] = here;
//			distance[there] = distance[here] + 1;
//		}
//	}
//
//	int i = 3;
//}
//
//void BfsAll()
//{
//	for (int i = 0; i < 6; i++)
//		if (discoversd[i] == false)
//			Bfs(i);
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
//void Bfs2(int here)
//{
//	//������ ���� �߰� �Ǿ���?
//	vector<int> parent(6, -1);
//	//���������� ��ŭ ������ �ֳ�?
//	vector<int> distance(6, -1);
//
//	queue<int> q;
//	q.push(here);
//	discoversd[here] = true;
//
//
//	parent[here] = here;
//	distance[here] = 0;
//
//	while (q.empty() == false)
//	{
//		here = q.front();
//		q.pop();
//
//		cout << "Visited : " << here << endl;
//
//
//		for (int there = 0; there < 6; there++)
//		{
//			if (adjacent[here][there] == 0)
//				continue;
//			if (discoversd[there])
//				continue;
//
//			q.push(there);
//			discoversd[there] = true;
//
//			parent[there] = here;
//			distance[there] = distance[here] + 1;
//		}
//	}
//
//	int i = 3;
//}
//
//int main()
//{
//	CreateGraph();
//
//	discoversd = vector<bool>(6, false);
//
//	Bfs(0);
//}