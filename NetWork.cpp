#include "NetWork.h"
#include <list>

namespace NetWork
{

	SOCKET sock_;
	int fromlen_;
	int ret_;
	int tolen_;
	SOCKADDR_IN toAddr_;
	SOCKADDR_IN fromAddr_;
	int pNum = 0;
	

	std::list<SOCKADDR_IN> ClientDate;

	void InitSocket()
	{
		WSADATA wsaData;
		int wsetup = WSAStartup(MAKEWORD(2, 2), &wsaData);


		// ソケット作成
		sock_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (sock_ > 0)
		{

			//  message.append("socket ok\r\n");

		}
		u_long arg = 0x01;
		int stop = ioctlsocket(sock_, FIONBIO, &arg);
		if (stop == 0)
		{
		}

		// bind
		SOCKADDR_IN bindAddr;
		memset(&bindAddr, 0, sizeof(bindAddr));
		bindAddr.sin_family = AF_INET;
		bindAddr.sin_port = htons(8080);
		bindAddr.sin_addr.s_addr = htonl(INADDR_ANY);	// すべての自分のNICが対象
	  //  bindAddr.sin_addr.S_un.S_addr = INADDR_ANY;
		ret_ = bind(sock_, (SOCKADDR*)&bindAddr, sizeof(bindAddr));
		if (ret_ == 0)
		{
			// message.append("bind ok\r\n");

		}
		ClientDate.clear();
		
	}

	bool InitRecv()
	{
		XMFLOAT3 pPos[2] =
		{
			{ 0,0,0},
			{0,0, 5}
		};
		int posNum = 0;
		char buff[1024];
		SOCKADDR_IN  fromAddr_;
		fromlen_ = sizeof(fromAddr_);
		ret_ = recvfrom(sock_, buff, sizeof(buff), 0, (SOCKADDR*)&fromAddr_, &fromlen_);
		int error = 0;
		if (ret_ < 0)
		{
			error = WSAGetLastError();
			if (error != WSAEWOULDBLOCK)
			{

				// エラー
				int a = 0;
			}
			int i = 0;
		}
		else
		{
		
			if (ClientDate.size() > 0)
			{
				for (auto itr = ClientDate.begin(); itr != ClientDate.end(); itr++)
				{
					if ((itr)->sin_addr.s_addr == fromAddr_.sin_addr.s_addr && (itr)->sin_port == fromAddr_.sin_port)
					{
						return true;
					}
				}
			}
			ClientDate.push_back(fromAddr_);
			
			RecvData::playerNumber.push_back(pNum);
			pNum++;
			RecvData::playerResponse.push_back(false);
			SendData::playerPos.push_back(pPos[posNum]);
			posNum++;
			return true;
		}
		return false;
	}

	void InitSend()
	{
		XMFLOAT3 pPos[2] =
		{
			{ 0,0,0},
			{0,0, 5}
		};
		auto player = RecvData::playerNumber.begin();
		int i = 0;
		for (auto itr = ClientDate.begin(); itr != ClientDate.end(); itr++)
		{
			memset(&toAddr_, 0, sizeof(toAddr_));
			toAddr_ = (*itr);
			int ClientNumber = (*player);
			ClientNumber = htonl(ClientNumber);
			SendCorrespondence s;
			s = SendData::InitSendCorrespondence();
			s.sendContent = 0;

			SendInitData_Player sendp;
			sendp.playerNumber = ClientNumber;
			sendp.position.x = htonf(pPos[i].x);
			sendp.position.y = htonf(pPos[i].y);
			sendp.position.z = htonf(pPos[i].z);
			s.pInit = sendp;

			int tolen = sizeof(toAddr_);
			int ret = sendto(sock_, (char*)&s, sizeof(s), 0, (sockaddr*)&toAddr_, tolen);
			if (ret > 0)
			{
			}
			else
			{
				int error = WSAGetLastError();
			}
			player++;
			i++;
		}
	}

	void InitSendOtherPlayers()
	{
		XMFLOAT3 pPos[2] =
		{
			{ 0,0,0},
			{0,0, 5}
		};
		int ret = -1;
		for (auto itr = ClientDate.begin(); itr != ClientDate.end(); itr++)
		{
			int i = 0;
			SendCorrespondence s[2];
			for (auto player = RecvData::playerNumber.begin(); player != RecvData::playerNumber.end(); player++)
			{
				
				s[i] = SendData::InitSendCorrespondence();
				s[i].sendContent = 0;

				SendInitData_Player sendp;
				sendp.playerNumber = htonl((*player));
				sendp.position.x = htonf(pPos[i].x);
				sendp.position.y = htonf(pPos[i].y);
				sendp.position.z = htonf(pPos[i].z);
				s[i].pInit = sendp;

				memset(&toAddr_, 0, sizeof(toAddr_));
				toAddr_ = (*itr);
				int tolen = sizeof(toAddr_);
				ret = sendto(sock_, (char*)&s[i], sizeof(s[i]), 0, (sockaddr*)&toAddr_, tolen);
				i++;
			}
			
			if (ret > 0)
			{
			}
			else
			{
				int error = WSAGetLastError();
			}
		}
	}

	void UpdateSend(SendCorrespondence content, int pNum)
	{
		auto player = RecvData::playerNumber.begin();
		for (auto itr = ClientDate.begin(); itr != ClientDate.end(); itr++)
		{	
			if ((*player) == pNum)
			{
				SendCorrespondence s = content;
				ConvertSendDate(s);
				memset(&toAddr_, 0, sizeof(toAddr_));
				toAddr_ = (*itr);

				int tolen = sizeof(toAddr_);
				int ret = sendto(sock_, (char*)&s, sizeof(s), 0, (sockaddr*)&toAddr_, tolen);
				if (ret > 0)
				{
				}
				else
				{
					int error = WSAGetLastError();
				}
			}
			player++;
		}
	}

	void UpdateRecv()
	{
		int posNum = 0;
		RecvDateToClient recv;
		SOCKADDR_IN  fromAddr_;
		fromlen_ = sizeof(fromAddr_);
		ret_ = recvfrom(sock_, (char*)&recv, sizeof(recv), 0, (SOCKADDR*)&fromAddr_, &fromlen_);
		int error = 0;
		if (ret_ < 0)
		{
			error = WSAGetLastError();
			if (error != WSAEWOULDBLOCK)
			{

				// エラー
				int a = 0;
			}
			int i = 0;
		}
		else
		{
			recv.playerNumber = ntohl(recv.playerNumber);
			recv.position.x = ntohl(recv.position.x);
			recv.position.y = ntohl(recv.position.y);
			recv.position.z = ntohl(recv.position.z);
			recv.rotate_Cannon = ntohf(recv.rotate_Cannon);
			recv.rotate_Tank = ntohf(recv.rotate_Tank);
			RecvData::playerRecvDate.push_back(recv);
		}
	}

	void ConvertSendDate(SendCorrespondence convertDate)
	{
		convertDate.sendContent = htonl(convertDate.sendContent);

		convertDate.pInit.playerNumber = htonl(convertDate.pInit.playerNumber);
		convertDate.pInit.position.x = htonf(convertDate.pInit.position.x);
		convertDate.pInit.position.y = htonf(convertDate.pInit.position.y);
		convertDate.pInit.position.z = htonf(convertDate.pInit.position.z);

		convertDate.pUpdate.playerNumber = htonl(convertDate.pUpdate.playerNumber);
		convertDate.pUpdate.position.x = htonf(convertDate.pUpdate.position.x);
		convertDate.pUpdate.position.y = htonf(convertDate.pUpdate.position.y);
		convertDate.pUpdate.position.z = htonf(convertDate.pUpdate.position.z);
		convertDate.pUpdate.rotate_Cannon = htonf(convertDate.pUpdate.rotate_Cannon);
		convertDate.pUpdate.rotate_Tank = htonf(convertDate.pUpdate.rotate_Tank);
		
		convertDate.h.hitReaction = htonl(convertDate.h.hitReaction);
		convertDate.h.targetPlayerNum = htonl(convertDate.h.targetPlayerNum);
		convertDate.h.objNum = htonl(convertDate.h.objNum);
		convertDate.h.position.x = htonf(convertDate.h.position.x);
		convertDate.h.position.y = htonf(convertDate.h.position.y);
		convertDate.h.position.z = htonf(convertDate.h.position.z);
	}
}