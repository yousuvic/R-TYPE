#ifndef WTCPSOCKET_HH
#define	WTCPSOCKET_HH

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <list>

#include "ITCPSocket.hh"

#pragma comment (lib, "Ws2_32.lib")
//#pragma comment (lib, "Mswsock.lib")

#define DEFAULT_PORT	"27015"

class WTCPSocket	: public	ITCPSocket
{
public:
	WTCPSocket();
	virtual	~WTCPSocket();

	void	init();
	void	resolveAdresse();
	void	acceptClient();
	void	addClient();

private:
	WSADATA			wsaData;
	int				iResult;

	SOCKET			tcpListenSocket = INVALID_SOCKET;
	SOCKET			tcpClientSocket = INVALID_SOCKET;

	struct addrinfo	*result = NULL;
	struct addrinfo hints;

	int							_id;
	int							_socket;
	std::string					_login;
	//std::list<std::string, int>	_clientList;
};

#endif // !WTCPSOCKET_HH
