//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//
//// ������� ��θ� �����Ͽ� ��θ� Ž���Ѵ�.
//
//
//struct Vertex
//{
//	// data
//};
//
//vector<Vertex> vertices; // ������ �����迭 ����� �����.
//vector<vector<int>> adjacent; // ������ �����.
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
//	list<VertextCost> discovered; // �߰� ���
//	vector<int> best(6, INT32_MAX); // �� �������� ���ݱ��� �߰��� �ּ� �Ÿ�
//	vector<int> parent(6, -1);
//
//	// �������� �湮�Ѵ�. 
//	discovered.push_back(VertextCost{ here , 0 });
//	best[here] = 0;
//	parent[here] = 0;
//
//	while (discovered.empty() == false)
//	{
//		//���� ���� �ĺ��� ã�´�.
//		list<VertextCost>::iterator bestlt;
//		int bestCost = INT32_MAX; // ������ ���� �ִ´�.
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
//		discovered.erase(bestlt); // �湮 ����Ʈ���� ����
//
//		// �湮? �� ª�� ��θ� �ڴʰ� ã�Ҵٸ� ��ŵ.
//		if (best[here] < cost)
//			continue;
//
//		//�湮
//		for (int i = 0; i < 6; i++)
//		{
//			// ������� �ʾ����� ��ŵ.
//			if (adjacent[here][i] == -1)
//				continue;
//
//			//�� ���� ��θ� ���ſ� ã������ ��ŵ.
//			int nextCost = best[here] + adjacent[here][i]; // 0�� ��� 15 / 35
//			if (nextCost >= best[i]) // 4�� �������� best[3] = 35 Ż��
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