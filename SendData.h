#pragma once
#include "Engine/Transform.h"
#include <list>

struct SendInitData_Player
{
	int playerNumber; //��P��
	XMFLOAT3 position; //�ʒu
};

struct SendUpdateData_Player
{
	int playerNumber; //��P��
	XMFLOAT3 position; //�ʒu
	float rotate_Tank; //�^���N��]
	float rotate_Cannon; //�C�g��]
	bool shoot;
};

//�I�u�W�F�N�g�������������ɑ��M
struct SendHitData
{
	bool isHit;
	int targetPlayerNum;
	int objNum;
	XMFLOAT3 position;
	int hitReaction; //�����������̏���
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

