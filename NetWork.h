#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>	// WinSock�p
#pragma comment( lib, "ws2_32.lib" )
#include "RecvData.h"
#include "SendData.h"
#define PLAYERMENBER 2
namespace NetWork
{
	void InitSocket();
	bool InitRecv(); //�v���C���[�������܂�
	void InitSend(); //�v���C���[���������炻�ꂼ���Client�ɉ�P����`����
	void InitSendOtherPlayers();

	void UpdateSend(SendCorrespondence content, int pNum);
	void UpdateRecv();

	void ConvertSendDate(SendCorrespondence convertDate);
};

