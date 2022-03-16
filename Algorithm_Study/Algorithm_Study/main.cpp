#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;
#include <thread>
// �ؽ� ���̺�

// map vs hash_map

// map : Red-Black Tree
// ������ ���� Ʈ��
// - �߰�/Ž��/���� O(logN)

// C# dictionary = C++ map (X)
// C# dictionary = C++ unordered_map

// hash_map(c++11 ǥ�� unordered_map)
// - �߰�/Ž��/���� O(1)

// �޸𸮸� ���ְ� �ӵ��� ��´�.
// EX) ����Ʈ ������
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

	// ���̺�
	// Ű�� �˸�, �����͸� �ܹ��� ã�� �� �ִ�.
	
	// ������ ��Ȳ
	// int32_max (3�� ~)
	// �޸𸮴� ������ �ƴϴ�. => hash�� �ذ��� �Ѵ�.
}

// ����
// EX) 
//	id : rookiss + pw : qwer1234
//	id : rookiss + pw : hash(qwer1234) -> asdlkfjas12341@2141%!#%!#@1asdfj
//	DB [rookiss][asdlkfjas12341@2141%!#%!#@1asdfj]
// ��й�ȣ ã�� -> ���̵� �Է� / �� ���� -> �� ) ��й�ȣ�� ~ ����) ���ο� ��й�ȣ ~

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
	int key = (userID % 1000); // hash < ������ȣ

	users[key] = User{ userID, "Rookiss" };

	User& user = users[key];
	if (user.userID == userID)
	{
		string name = user.username;
		cout << name << endl;
	}

}

	// �浹 ���� [key���� ������ ����]
	// 123456789
	// 789

	// �浹�� �߻��� �ڸ��� ����ؼ� �ٸ� ���ڸ��� ã�Ƴ�����.
	// - ���� ����� (linear probing)
	// hash(key) + 1 -> hash(key) + 2
	// - ���� ����� (quadratic probing)
	// hash(key)+1^2 -> hash(key) + 2^2
	// -etc
	// ü�̴� - ������ ���� �ִٸ� ���Ḯ��Ʈ�� �̿��Ͽ� ���ϳ��� �迭�� ����� �������ش�.
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
	int key = (userID % 1000); // hash < ������ȣ

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