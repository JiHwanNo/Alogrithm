#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include <thread>
// 해시 테이블

// map vs hash_map

// map : Red-Black Tree
// 균형적 이진 트리
// - 추가/탐색/삭제 O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map(c++11 표준 unordered_map)
// - 추가/탐색/삭제 O(1)

// 메모리를 내주고 속도를 얻는다.
// EX) 아파트 우편함
// [201][202][203][204][205]
// [101][102][103][104][105]

// 1 ~ 1000 user( userId = 1 ~ 999 )
// [1][2][3] ... [999] check

// 'hash', 'table'
// O(1)
void TestTable()
{
	struct User
	{
		int userID = 0;
		string username;
	};

	vector<User> users;
	users.resize(1000);

	users[777] = User{ 777, "Rookiss" };

	string name = users[777].username;
	cout << name << endl;

	// 테이블
	// 키를 알면, 데이터를 단번에 찾을 수 있다.
	
	// 문제의 상황
	// int32_max (3억 ~)
	// 메모리는 무한이 아니다. => hash로 해결을 한다.
}

// 보안
// EX) 
//	id : rookiss + pw : qwer1234
//	id : rookiss + pw : hash(qwer1234) -> asdlkfjas12341@2141%!#%!#@1asdfj
//	DB [rookiss][asdlkfjas12341@2141%!#%!#@1asdfj]
// 비밀번호 찾기 -> 아이디 입력 / 폰 인증 -> 옛 ) 비밀번호는 ~ 현재) 새로운 비밀번호 ~

void TestHash()
{
	struct User
	{
		int userID = 0; // 1~ int32_max
		string username;
	};

	vector<User> users;
	users.resize(1000);

	const int userID = 123456789;
	int key = (userID % 1000); // hash < 고유번호

	users[key] = User{ userID, "Rookiss" };

	User& user = users[key];
	if (user.userID == userID)
	{
		string name = user.username;
		cout << name << endl;
	}

}

	// 충돌 문제 [key값이 동일한 상태]
	// 123456789
	// 789

	// 충돌이 발생한 자리를 대신해서 다른 빈자리를 찾아나선다.
	// - 선형 조사법 (linear probing)
	// hash(key) + 1 -> hash(key) + 2
	// - 이차 조사법 (quadratic probing)
	// hash(key)+1^2 -> hash(key) + 2^2
	// -etc
	// 체이닝 - 동일한 값이 있다면 연결리스트를 이용하여 또하나의 배열을 만들어 연결해준다.
	// 

void TestHashTableChaining()
{
	struct User
	{
		int userID = 0; // 1~ int32_max
		string username;
	};

	vector< vector<User>> users;
	users.resize(1000);

	const int userID = 123456789;
	int key = (userID % 1000); // hash < 고유번호

	users[key].push_back(User{ userID, "Rookiss" });

	vector<User>& bucket = users[key];
	for (User& user : bucket)
	{
		if (user.userID == userID)
		{
			string name = user.username;
			cout << name << endl;
		}
	}
}


int main()
{
	TestTable();
	
}