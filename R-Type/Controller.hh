#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include <vector>

#include "WExchange.hh"
#include "WSocket.hh"
#include "WThread.hh"

class Controller
{
public:
	typedef	struct clientList
	{
		int			id;
		SOCKET		clientSocket;
		std::string	login;
	};

	Controller();
	~Controller();
	void	sendActionPackets();
	void	update();
	void	setClientInfo(clientList *);

private:
	WSocket		*tcpSocket;
	WExchange	*tcpExchange;
	WThread		*threadTCP;

	clientList				*clientInfo;
	std::vector<clientList>	cList;
};

#endif // !CONTROLLER_HH
