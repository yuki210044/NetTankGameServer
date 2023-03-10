#pragma once
#include "Engine/Transform.h"
#include "Engine/GameObject.h"
#include <list>
#include <vector>


struct RecvDateToClient
{
	int playerNumber; //‰½P‚©
	XMINT3 position; //ˆÊ’u
	float rotate_Cannon; //–Cg‰ñ“]
	float rotate_Tank; //ƒ^ƒ“ƒN‰ñ“]
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

