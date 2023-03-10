#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "Player.h"
#include "Engine/Input.h"
#include "SendData.h"
#include "NetWork.h"

namespace
{
	float rotateTank = 0;
	float rotateCannon = 0;
	XMFLOAT3 pos;
	XMFLOAT3 rotate_Tank;
	XMFLOAT3 rotate_Cannon;
	bool isKey = false;
}
//コンストラクタ
Player::Player(GameObject* parent)
	: GameObject(parent, "Player"), hPlayer(-1)
{
	pTank = nullptr;
}

Player::~Player()
{

}

//初期化
void Player::Initialize()
{
	pTank = Instantiate<Tank>(this);
	pCannon = pTank->GetCannonInstance();
	pos = pTank->GetPosition();
}



//更新
void Player::Update()
{
	pTank->SetPosition(pos);
	pTank->SetRotate(rotate_Tank);

	pCannon->SetRotate(rotate_Cannon);

	pCannon->KeyInput_Cannon(isKey);
	rotateCannon = 0;
	SendCorrespondence send;
	send.sendContent = 1;
	send.pUpdate.playerNumber = hObject;
	send.pUpdate.position = pTank->GetPosition();
	send.pUpdate.rotate_Cannon = pCannon->GetRotate().y;
	send.pUpdate.rotate_Tank = pTank->GetRotate().y;
	send.pUpdate.shoot = isKey;
	NetWork::UpdateSend(send, hObject);
}

//描画
void Player::Draw()
{
	
}

//開放
void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	SendHitData hit;
}

void Player::SetRecvDate(RecvDateToClient r)
{
	pos.x = (float)r.position.x / 10;
	pos.y = (float)r.position.y / 10;
	pos.z = (float)r.position.z / 10;
	rotate_Tank = pTank->GetRotate();
	rotate_Tank.y = r.rotate_Tank;
	rotate_Cannon = pCannon->GetRotate();
	rotate_Cannon.y = r.rotate_Cannon;
	isKey = r.isShoot;
}