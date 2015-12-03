#ifndef WEXCHANGE_HH
#define	WEXCHANGE_HH

#include <iostream>
#include <winsock2.h>
#include "IExchange.hh"

class WExchange	:	public IExchange
{
public:
	WExchange();
	virtual ~WExchange();

	Packet	recv(int socket);
	int		send(int socket, const Packet& packet);

private:
	struct sockaddr_in	_si_other;
	Packet::keyPressed	_recvData;
};

#endif // !WEXCHANGE_HH
