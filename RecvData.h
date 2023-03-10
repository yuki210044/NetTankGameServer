#pragma once
#include "Engine/Transform.h"
#include "Engine/GameObject.h"
#include <list>
#include <vector>


struct RecvDateToClient
{
	int playerNumber; //何Pか
	XMINT3 position; //位置
	float rotate_Cannon; //砲身回転
	float rotate_Tank; //タンク回転
	bool isShoot;
};

namespace RecvData
{
	extern RecvDateToClient recv;
	extern std::list<int> playerNumber;
	extern std::list<bool> playerResponse;
	extern std::vector<RecvDateToClient> playerRecvDate;

	RecvDateToClient GetRecvData();

	
};

