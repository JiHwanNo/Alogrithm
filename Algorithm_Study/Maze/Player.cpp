#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Bfs();
}

void Player::Update(uint64 deltaTick)
{	
	if (_pathIndex >= _path.size())
		return;
	
	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}

}

bool Player::IsGo(Pos pos)
{
	TileType tiletype = _board->GetTileType(pos);
	return tiletype == TileType::EMPTY;
}

void Player::RightHand()
{
	_path.clear();
	_path.push_back(_pos);

	Pos pos = _pos;

	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1,0},	//UP
		Pos {0,-1},	//LEFT
		Pos {1,0},	//DOWN
		Pos {0,1},	//RIGHT
	};

	while (pos != dest)
	{
		//1.	현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
		//2.	현재 바라보는 방향 기준으로 전진할 수 있는가?
		//3.	왼쪽으로 방향을 전환한다.
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT; //현재 기준의 오른쪽
		if (IsGo(pos + front[newDir])) //1 구현
		{
			_dir = newDir;
			pos += front[_dir];

			_path.push_back(pos);
		}
		else if (IsGo(pos + front[_dir])) //2 구현
		{
			pos += front[_dir];

			_path.push_back(pos);
		}
		else //3 구현
		{
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}
	// 경로 설정이 끝났다.

	// 경로를 stack에 쌓는다.
	stack<Pos> s;
	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	if (_path.empty() == false)
		s.push(_path.back());

	// stack은 기본적으로 후입선출이므로 vector에 값을 넣어주고
	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}
	// 처음과 끝을 뒤짚어준다.
	reverse(path.begin(), path.end());

	_path = path;

}

void Player::Bfs()
{
	Pos pos = _pos;

	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1,0},	//UP
		Pos {0,-1},	//LEFT
		Pos {1,0},	//DOWN
		Pos {0,1},	//RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size,false));
	
	//vector<vector<Pos>> parent;
	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		if (pos == dest)
		{
			break;
		}

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];

			if (IsGo(nextPos) == false)
				continue;
			if (discovered[nextPos.y][nextPos.x])
				continue;

			q.push(nextPos);
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;

		}
	}

	_path.clear();

	pos = dest;
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	reverse(_path.begin(), _path.end());
	

}
