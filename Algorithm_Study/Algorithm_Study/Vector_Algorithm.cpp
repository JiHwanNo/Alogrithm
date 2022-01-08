//#include <iostream>
//#include <vector>
//using namespace std;
//
//template<typename T>
//class Vector
//{
//public:
//	Vector()
//	{
//
//	}
//	~Vector()
//	{
//		if (_data)
//			delete[] _data;
//	}
//
//	void puch_back(const T& value)
//	{
//		if (_size == _capacity)
//		{
//			int newCapacity = _capacity * 1.5;
//			if (newCapacity == _capacity)
//				newCapacity++;
//
//			reserve(newCapacity);
//		}
//
//		_data[_size] = value;
//		_size++;
//	}
//
//	void reserve(int capacity)
//	{
//		if (_capacity >= capacity)
//			return;
//
//		_capacity = capacity;
//
//		T* newData = new T[_capacity];
//
//		for (int i = 0; i < _size; i++)
//			newData[i] = _data[i];
//
//		if (_data)
//			delete[] _data;
//
//		_data = newData;
//	}
//
//	T& operator[](const int pos) { return _data[pos]; }
//
//	int size() { return _size; }
//	int capacity() { return _capacity; }
//
//	void Clear()
//	{
//		if (_data)
//		{
//			delete[] _data;
//			_data = new T[_capacity];
//		}
//		_size = 0;
//	}
//private:
//	T* _data = nullptr;
//	int _size = 0;
//	int _capacity = 0;
//};
//
//int main()
//{
//	vector<int> vec;
//
//	vec.reserve(100);
//	cout << vec.size() << " " << vec.capacity() << endl;
//
//	for (int i = 0; i < 100; i++)
//	{
//		vec.push_back(i);
//		cout << vec.size() << " " << vec.capacity() << endl;
//	}
//
//
//	vec.clear();
//	cout << vec.size() << " " << vec.capacity();
//}
