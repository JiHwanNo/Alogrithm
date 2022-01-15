#include <iostream>
//#include <vector>
//#include <stack>
//#include <list>
//#include <queue>
//using namespace std;
// 
//template<typename T>
//class ArrayQueue
//{
//public:
//	ArrayQueue()
//	{
//		_containe.resize(100);
//	}
//
//	void push(const T& value)
//	{
//		if (_size == _container.size())
//		{
//			int newSize = max(1,_size * 2);
//			vector<T> newData;
//			newData.resize(newSize);
//
//			for (int i = 0; i < _size; i++)
//			{
//				int index = (_front + i) % _container.size();
//				newData[i] = _container[index];
//			}
//
//			_container.swap(newData);
//			_front = 0;
//			_back = _size;
//		}
//
//
//		_container[_back] = value;
//		//순환 구조를 만들기.
//		_back = (_back + 1) & _container.size(); // capacity
//		_size++; // 데이터 크기
//	}
//	void pop()
//	{
//		_front = (_front + 1) % _container.size();
//		_size--;
//	}
//	T& front()
//	{
//		return _container[_front];
//	}
//	bool empty() { return _size ==0; }
//	int size() { return _size; }
//private:
//	vector<T> _container;
//
//	int _front = 0;
//	int _back = 0;
//	int _size = 0;
//};
//
//
//
//int main()
//{
//	queue<int> q;
//
//	for (int i = 0; i < 100; i++)
//	{
//		q.push(i);
//	}
//
//	while (q.empty() == false)
//	{
//		int value = q.front();
//		q.pop();
//		cout << value << endl;
//	}
//	int size = q.size();
//}