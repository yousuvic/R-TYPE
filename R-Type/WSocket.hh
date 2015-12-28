#ifndef WSOCKET_HH
#define	WSOCKET_HH

#include <stdio.h>
#include <iostream>
#include <winsock2.h>
#include <vector>
#include <string>

#include "ISocket.hh"
#include "Protocol.hh"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define PORT 4243

typedef	struct	s_clientList
{
	int			id;
	SOCKET		clientSocket;
	std::string	login;
	std::string	roomName;
	bool		isHost;
}				clientList;

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
	void			selectTCP();

	/* ----------- GETTERS ----------- */

	int				getSocket() const;
	int				getPort() const;
	std::string		getAddress() const;

	

	/*----------- CLIENT LIST ----------*/

	void						setClientInfo(clientList info);
	void						setVectorList(clientList client);

	clientList					getClientInfo() const;
	std::vector<clientList>		getCList() const;

private:
	SOCKET				_socket;
	SOCKET				_tcpClientSocket;
	struct sockaddr_in	_server;
	int					_slen;
	int					_recv_len;
	WSADATA				_wsa;

	int					recv_len;
	char				data[512];

	/*----------- CLIENT LIST ----------*/
	clientList					clientInfo;
	std::vector<clientList>		clientVector;

	/*------------- SELECT -------------*/
	fd_set						rdfd;
	fd_set						wrfd;
	struct timeval				tv;

	/*------------- PROTOCOL -------------*/
	Protocol					tcpPRTL;
	std::vector<std::string>	room;
};

#endif // !WSOCKET_HH
