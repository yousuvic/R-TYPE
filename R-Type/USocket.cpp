#include "USocket.hh"

void	USocket::init()
{
	_slen = sizeof(_si_other);

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	if ((_socket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	_server.sin_family = AF_INET;
	_server.sin_addr.s_addr = INADDR_ANY;
	_server.sin_port = htons(PORT);

	if (bind(_socket, (struct sockaddr *)&_server, sizeof(_server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	puts("Bind done");
}

void	USocket::setNonBlockingMode()
{
	int		iResult;
	u_long	iMode = 1;

	iResult = ioctlsocket(_socket, FIONBIO, &iMode);
	if (iResult != NO_ERROR)
		printf("ioctlsocket failed with error: %ld\n", iResult);
}

void	USocket::run()
{

}

void		USocket::closeSocket()
{
	closesocket(_socket);
}

void		USocket::receiveData()
{
	if ((recv_len = recvfrom(_socket, data, 512, 0, (struct sockaddr *) &_si_other, &_slen)) == SOCKET_ERROR)
	{
		printf("recvfrom() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

void		USocket::sendData()
{
	if (sendto(_socket, data, recv_len, 0, (struct sockaddr*) &_si_other, _slen) == SOCKET_ERROR)
	{
		printf("sendto() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

USocket::USocket()
{

}

USocket::~USocket()
{
	
}