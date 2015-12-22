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

void						WSocket::setClientInfo(clientList info)
{
	this->clientInfo = info;
}

void						WSocket::setVectorList(clientList client)
{
	this->clientVector.push_back(client);
}

clientList					WSocket::getClientInfo() const
{
	return	this->clientInfo;
}

std::vector<clientList>		WSocket::getCList() const
{
	return	clientVector;
}

int Split(std::vector<std::string>& vecteur, std::string chaine, char separateur)
{
	vecteur.clear();

	std::string::size_type stTemp = chaine.find(separateur);

	while (stTemp != std::string::npos)
	{
		vecteur.push_back(chaine.substr(0, stTemp));
		chaine = chaine.substr(stTemp + 1);
		stTemp = chaine.find(separateur);
	}
	vecteur.push_back(chaine);
	return vecteur.size();
}

void	WSocket::selectTCP()
{
	std::vector<std::string>	commande;


	clientInfo.id = 0;
	clientInfo.clientSocket = INVALID_SOCKET;
	clientInfo.login = "";

	FD_ZERO(&rdfd);
	FD_ZERO(&wrfd);

	FD_SET(_socket, &rdfd);
	//FD_SET(, &wrfd); boucle client
	for (std::vector<clientList>::iterator it = clientVector.begin(); it != clientVector.end(); ++it)
	{
		FD_SET(it->clientSocket, &wrfd);
		FD_SET(it->clientSocket, &rdfd);
	}

	if ((select(_socket + 1, &rdfd, &wrfd, NULL, &tv)) == -1)
	{
		printf("Select error\n");
		exit(EXIT_FAILURE);
	}
	if (FD_ISSET(_socket, &rdfd))
	{
		accept_();
		std::cout << "ACCEPTED" << std::endl;
		clientInfo.id = (getCList().size() + 1);
		clientInfo.clientSocket = _tcpClientSocket;
		clientInfo.login = "toto";

		std::cout << getCList().size() << std::endl;
		setClientInfo(clientInfo);
		setVectorList(clientInfo);
	}
	for (std::vector<clientList>::iterator it = clientVector.begin(); it != clientVector.end(); ++it)
	{
		memset(data, 0, 4);
		if (FD_ISSET(it->clientSocket, &rdfd))
		{
			recv_len = recv(it->clientSocket, data, 512, 0);
			data[recv_len - 1] = '\0';
			std::cout << data << std::endl;
			Split(commande, data, ';');

			if (commande[0] == "1")
			tcpPRTL.greeting(it->clientSocket);
						
			if (commande[0] == "2")
			{
				if (commande[1] == "")
					send(it->clientSocket, "ko", 2, 0);
				else
				{
					tcpPRTL.recvLogin(it->clientSocket);
					clientVector[it->id - 1].login = commande[1];
					std::cout << "login = " << clientVector[it->id - 1].login << std::endl;
				}
				//clientVector.at(it->id).login = commande[2];
				//std::cout << "login = " << commande[0] << std::endl;
			}
		

			//std::cout << "login" << commande[2] << std::endl;
			//send(it->clientSocket, "ok", 2, 0);			
			//std::cout << "read" << std::endl;
		}
		if (FD_ISSET(it->clientSocket, &wrfd))
		{
			//send(it->clientSocket, "ok", 2, 0);
			//std::cout << "write" << std::endl;
		}
	}
	//commande.clear();
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