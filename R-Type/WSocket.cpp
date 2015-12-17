#include "WSocket.hh"

void	WSocket::create_(int type, int protocol)
{
	if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	if ((_socket = socket(AF_INET, type, protocol)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
}

void	WSocket::bind_()
{
	_server.sin_family = AF_INET;
	_server.sin_addr.s_addr = INADDR_ANY;
	_server.sin_port = htons(PORT);

	if (bind(_socket, (struct sockaddr *)&_server, sizeof(_server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	//puts("UDP SERVER IS RUNNING !");
}

void	WSocket::listen_()
{
	if ((listen(_socket, SOMAXCONN)) == SOCKET_ERROR) 
	{
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(_socket);
		WSACleanup();
		exit(EXIT_FAILURE);
	}
}

void	WSocket::accept_()
{
	if ((_tcpClientSocket = accept(_socket, NULL, NULL)) == INVALID_SOCKET)
	{
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(_socket);
		WSACleanup();
		exit(EXIT_FAILURE);
	}
}

void						WSocket::setClientInfo(struct clientList info)
{
	this->clientInfo = info;
}

void						WSocket::setVectorList(struct clientList client)
{
	this->clientList.push_back(client);
}

clientList					WSocket::getClientInfo() const
{
	return	this->clientInfo;
}

std::vector<clientList>		WSocket::getCList() const
{
	return	clientList;
}

void	WSocket::selectTCP()
{
	clientInfo.id = 0;
	clientInfo.clientSocket = INVALID_SOCKET;
	clientInfo.login = "";

	FD_ZERO(&rdfd);
	FD_ZERO(&wrfd);

	FD_SET(_socket, &rdfd);
	//FD_SET(, &wrfd); boucle client

	if ((select(_socket + 1, &rdfd, &wrfd, NULL, &tv)) == -1)
	{
		printf("Select error\n");
		exit(EXIT_FAILURE);
	}
	if (FD_ISSET(_socket, &rdfd))
	{
		accept_();
		clientInfo.id = (getCList().size() + 1);
		clientInfo.clientSocket = _tcpClientSocket;
		clientInfo.login = "";

		setClientInfo(clientInfo);
		setVectorList(clientInfo);
	}


}

/*void	WSocket::setNonBlockingMode()
{
	int		iResult;
	u_long	iMode = 1;

	iResult = ioctlsocket(_socket, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
		printf("ioctlsocket failed with error: %ld\n", iResult);
}*/

void		WSocket::closeSocket()
{
	closesocket(_socket);
}

int			WSocket::getSocket() const
{
	return (_tcpClientSocket);
}

WSocket::WSocket(int type, int protocol)
{
	this->create_(type, protocol);
	this->bind_();

	if (type == SOCK_STREAM)
	{
		this->listen_();		

		tv.tv_sec = 10;
		tv.tv_usec = 0;
	}
}

WSocket::~WSocket()
{
	closeSocket();
	WSACleanup();
}