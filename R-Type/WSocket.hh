#ifndef WSOCKET_HH
#define	WSOCKET_HH

#include <stdio.h>
#include <winsock2.h>

#include <string>

#include "ISocket.hh"


#pragma comment(lib,"ws2_32.lib") //Winsock Library


#define PORT 4242

class WSocket	:	public	ISocket
{
public:
	WSocket(int type, int protocol);
	~WSocket();

	void			create_(int type, int protocol);
	void			bind_();
	void			listen_();
	void			accept_();
	void			closeSocket();

	/* ----------- GETTERS ----------- */

	int				getSocket() const;
	int				getPort() const;
	std::string		getAddress() const;

private:
	SOCKET				_socket;
	SOCKET				_tcpClientSocket;
	struct sockaddr_in	_server;
	int					_slen;
	int					_recv_len;
	WSADATA				_wsa;

	int					recv_len;
	char				data[512];
};

#endif // !WSOCKET_HH
