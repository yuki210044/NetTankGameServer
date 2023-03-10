#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "PlayScene.h"
#include "Engine/SceneManager.h"
#include "Player.h"
#include "RecvData.h"
#include "NetWork.h"
#include "Ground.h"
#include <list>

namespace
{
	int hObj = 0;
	std::list<Player*> pList;
	SendInitData_Player initp;

	XMFLOAT3 pPos[2] =
	{
		{0,0,0}, {0,0,5}
	};
}
//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	int i = 0;
	for (auto itr = RecvData::playerNumber.begin(); itr != RecvData::playerNumber.end(); itr++)
	{
		Player* p = Instantiate<Player>(this);
		p->SetObjectHandle(*itr);
		p->GetTank()->SetPosition(pPos[i]);
		pList.push_back(p);
		i++;
	}
	Instantiate<Ground>(this);
	
}

//更新
void PlayScene::Update()
{
	
	for (int i = 0; i < RecvData::playerRecvDate.size(); i++)
	{
		for (auto j = pList.begin(); j != pList.end(); j++)
		{
			if (RecvData::playerRecvDate[i].playerNumber == (*j)->GetObjectHandle())
			{
				(*j)->SetRecvDate(RecvData::playerRecvDate[i]);
			}
		}
	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}