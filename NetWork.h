#pragma once
#include <WinSock2.h>
#include <ws2tcpip.h>	// WinSock用
#pragma comment( lib, "ws2_32.lib" )
#include "RecvData.h"
#include "SendData.h"
#define PLAYERMENBER 2
namespace NetWork
{
	void InitSocket();
	bool InitRecv(); //プレイヤーが揃うまで
	void InitSend(); //プレイヤーが揃ったらそれぞれのClientに何Pかを伝える
	void InitSendOtherPlayers();

	void UpdateSend(SendCorrespondence content, int pNum);
	void UpdateRecv();

	void ConvertSendDate(SendCorrespondence convertDate);
};

