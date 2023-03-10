#define _WINSOCKAPI_ //WinSock2�̍Ē�`���
#include "MatchScene.h"
#include "Engine/SceneManager.h"
#include "RecvData.h"
#include "NetWork.h"

namespace
{
	int count = 0;
}
//�R���X�g���N�^
MatchScene::MatchScene(GameObject* parent)
	: GameObject(parent, "MatchScene")
{
}

//������
void MatchScene::Initialize()
{
}

//�X�V
void MatchScene::Update()
{
	if (RecvData::playerNumber.size() == PLAYERMENBER)
	{
		NetWork::InitSend();
		NetWork::InitSendOtherPlayers();
		
		SceneManager* pScene = (SceneManager*)FindObject("SceneManager");
		pScene->ChangeScene(PLAY);
		
	}
	else
	{
		NetWork::InitRecv();
	}
}

//�`��
void MatchScene::Draw()
{
}

//�J��
void MatchScene::Release()
{
}