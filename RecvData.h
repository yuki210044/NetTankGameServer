#pragma once
#include "Engine/Transform.h"
#include "Engine/GameObject.h"
#include <list>
#include <vector>


struct RecvDateToClient
{
	int playerNumber; //��P��
	XMINT3 position; //�ʒu
	float rotate_Cannon; //�C�g��]
	float rotate_Tank; //�^���N��]
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

