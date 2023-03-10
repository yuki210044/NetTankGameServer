#include "RecvData.h"

namespace RecvData
{
	RecvDateToClient recv;
	std::list<int> playerNumber;
	std::list<bool> playerResponse;
	std::vector<RecvDateToClient> playerRecvDate;

	RecvDateToClient GetRecvData()
	{
		return recv;
	}
}