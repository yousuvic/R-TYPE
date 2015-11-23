#include "UdpExchangeWin.hh"

void	UDPExchangeWin::InitSrvUDP()
{
	slen = sizeof(this->si_other);

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//Create a socket
	if ((SocketFD = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}
	printf("Socket created.\n");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);

	//Bind
	if (bind(SocketFD, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	puts("Bind done");
}

int		UDPExchangeWin::ExchangeSrvUDP()
{
	tv.tv_sec = 10;
	tv.tv_usec = 0;
	while (1)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);

		FD_SET(SocketFD, &readfds);
		FD_SET(SocketFD, &writefds);

		if ((select(SocketFD + 1, &readfds, &writefds, NULL, &tv)) == -1)
		{
			printf("Select error\n");
			exit(EXIT_FAILURE);
		}
		if (FD_ISSET(SocketFD, &readfds))
		{
			slen = sizeof(struct sockaddr);
			/*if ((recv_len = recvfrom(SocketFD, _data, 4, 0, (struct sockaddr *)&si_other, &slen)) == SOCKET_ERROR)
			{
				printf("recvfrom() failed with error code : %d", WSAGetLastError());
				exit(EXIT_FAILURE);
			}*/
		}
		if (FD_ISSET(SocketFD, &writefds))
		{
			/*if (sendto(SocketFD, "toto", 4, 0, (struct sockaddr*)&si_other, slen) == SOCKET_ERROR)
				{
					printf("sendto() failed with error code : %d", WSAGetLastError());
					exit(EXIT_FAILURE);
				}*/
		}
	}
	closesocket(SocketFD);
	WSACleanup();
	return (0);
}

UDPExchangeWin::UDPExchangeWin()
{
}

UDPExchangeWin::~UDPExchangeWin()
{
}