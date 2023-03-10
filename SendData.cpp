#include "SendData.h"

namespace SendData
{
	std::list<XMFLOAT3> playerPos;

	SendCorrespondence InitSendCorrespondence()
	{
		SendInitData_Player init;
		init.playerNumber = -1;
		init.position = { 0,0,0 };
		SendUpdateData_Player update;
		update.playerNumber = -1;
		update.position = { 0,0,0 };
		update.rotate_Cannon = 0;
		update.rotate_Tank = 0;
		update.shoot = false;
		SendHitData hit;
		hit.hitReaction = -1;
		hit.isHit = false;
		hit.targetPlayerNum = -1;

		SendCorrespondence initSend;
		initSend.sendContent = -1;
		initSend.h = hit;
		initSend.pInit = init;
		initSend.pUpdate = update;

		return initSend;
	}
}