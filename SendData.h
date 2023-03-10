#pragma once
#include "Engine/Transform.h"
#include <list>

struct SendInitData_Player
{
	int playerNumber; //何Pか
	XMFLOAT3 position; //位置
};

struct SendUpdateData_Player
{
	int playerNumber; //何Pか
	XMFLOAT3 position; //位置
	float rotate_Tank; //タンク回転
	float rotate_Cannon; //砲身回転
	bool shoot;
};

//オブジェクトが当たった時に送信
struct SendHitData
{
	bool isHit;
	int targetPlayerNum;
	int objNum;
	XMFLOAT3 position;
	int hitReaction; //当たった時の処理
};

struct SendCorrespondence
{
	int sendContent;
	SendInitData_Player pInit;
	SendUpdateData_Player pUpdate;
	SendHitData h;
};



namespace SendData
{
	enum ContentSend
	{
		INIT = 0,
		UPDATE,
		HIT,
	};
	SendCorrespondence InitSendCorrespondence();

	extern std::list<XMFLOAT3> playerPos;
};

