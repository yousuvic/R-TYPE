#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include <vector>

#include "WExchange.hh"
#include "Protocol.hh"
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
	clientList	*getClientInfo() const;

	void						setCList(clientList);
	std::vector<clientList>		getCList() const;

private:
	WSocket		*tcpSocket;
	WThread		*threadTCP;

	clientList				*clientInfo;
	std::vector<clientList>	cList;

};

#endif // !CONTROLLER_HH
