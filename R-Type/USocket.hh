#ifndef USOCKET_HH
#define	USOCKET_HH

#include <stdio.h>
#include <winsock2.h>

#include "ISocket.hh"


#pragma comment(lib,"ws2_32.lib") //Winsock Library


#define PORT 4242

class USocket	:	public	ISocket
{
public:
	USocket();
	virtual ~USocket();

	void	init();
	void	setNonBlockingMode();
	void	run();
	void	closeSocket();
	void	receiveData();
	void	sendData();

private:
	SOCKET				_socket;
	struct sockaddr_in	_server;
	struct sockaddr_in	_si_other;
	int					_slen;
	int					_recv_len;
	WSADATA				_wsa;

	int					recv_len;
	char				data[512];
};

#endif // !USOCKET_HH
