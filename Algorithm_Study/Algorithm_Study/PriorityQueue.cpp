//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <list>
//using namespace std;
//
//template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
//class PriorityQueue
//{
//public:
//	void push(const T& data)
//	{
//		// 우선 힙 구조부터 맞춰준다.
//		_heap.push_back(data);
//
//		//도장깨기 시작
//		//static_cast<바꾸려고 하는 타입>(대상);
//		// 현재 Index를 받는다.
//		int now = static_cast<int>(_heap.size()) - 1;
//
//		while (now > 0)
//		{
//			int next = (now - 1) / 2;
//
//			if (_predicate(_heap[now], _heap[next]))
//				break;
//
//			::swap(_heap[now], _heap[next]);
//			now = next;
//		}
//	}
//
//	void pop()
//	{
//		_heap[0] = _heap.back();
//		_heap.pop_back();
//
//		int now = 0;
//
//		while (true)
//		{
//			int left = 2 * now + 1;
//			int right = 2 * now + 2;
//
//			//리프에 도달한 경우
//			if (left >= (int)_heap.size())
//				break;
//
//			int next = now;
//
//			// 왼쪽과 비교
//			if (_predicate(_heap[next], _heap[left]))
//				next = left;
//
//			//둘 중 승자를 오른쪽과 비교
//			if (right < (int)_heap.size() && _predicate(_heap[next], _heap[right]))
//				next = right;
//
//			if (next == now)
//				break;
//
//			::swap(_heap[now], _heap[next]);
//			now = next;
//		}
//	}
//
//	T& top()
//	{
//		return _heap[0];
//	}
//
//	bool empty()
//	{
//		return _heap.empty();
//	}
//private:
//	Container _heap = {};
//	Predicate _predicate = {};
//};
//
//
//int main()
//{
//	PriorityQueue<int> pq;
//
//	pq.push(700);
//	pq.push(6000);
//	pq.push(300);
//	pq.push(500);
//	pq.push(400);
//
//	while (pq.empty() == false)
//	{
//		int value = pq.top();
//		pq.pop();
//
//		cout << value << endl;
//	}
//}