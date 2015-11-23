#ifndef UDPEXCHANGEWIN_HH
#define	UDPEXCHANGEWIN_HH

#include <iostream>
#include <stdio.h>
#include "IUDP.hh"

#ifdef _WIN32

#include<winsock2.h>

#define PORT 4542

#endif

#pragma comment(lib,"ws2_32.lib")

#define SERVER "10.20.86.176"

class UDPExchangeWin :	public	IUDP 
{
public:
	UDPExchangeWin();
	virtual	~UDPExchangeWin();
	void	InitSrvUDP();
	int		ExchangeSrvUDP();

private:

	int					SocketFD;
	struct sockaddr_in	server;
	struct sockaddr_in	si_other;
	int					slen;
	int					recv_len;
	WSADATA				wsa;
	struct timeval		tv;
	char				_data[4];

	/*
	**	Select Srv
	*/
	fd_set	readfds;
	fd_set	writefds;

};

#endif // !UDPEXCHANGEWIN_HH
