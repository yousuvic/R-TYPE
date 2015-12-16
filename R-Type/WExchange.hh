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

	void	recvUDP(int socket);
	int		sendUDP(int socket, const Packet& packet);
	void	disp();

	/*
	**	TCP exchange
	*/
	void	recvTCP(int socket);
	void	sendTCP(int socket);

	/*
	**	Getter
	*/
	char	*getDataRecv() const;
	char	*getDataSend() const;

private:
	struct sockaddr_in	_si_other;
	Packet::keyPressed	_recvData;

	char	_data_send[100];
	char	_data_recv[100];
};

#endif // !WEXCHANGE_HH
