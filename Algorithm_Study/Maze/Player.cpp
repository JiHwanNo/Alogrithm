#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	_path.clear();
	_path.push_back(_pos);

	Pos pos = _pos;

	Pos dest = board->GetExitPos();

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
		if (IsGo(pos + front[newDir]) ) //1 구현
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
		/*	switch (_dir)
			{
			case DIR_UP:
				_dir = DIR_LEFT;
					break;
			case DIR_LEFT:
				_dir = DIR_DOWN;
				break;
			case DIR_DOWN:
				_dir = DIR_RIGHT;
				break;
			case DIR_RIGHT:
				_dir = DIR_UP;
				break;
			default:
				break;
			}*/
		}
	}
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
