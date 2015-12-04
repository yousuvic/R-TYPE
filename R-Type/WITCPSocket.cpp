#include "WTCPSocket.hh"

void	WTCPSocket::init()
{
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed with error: %d\n", iResult);
		return;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;
}

void	WTCPSocket::resolveAdresse()
{
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iResult != 0) {
		printf("getaddrinfo failed with error: %d\n", iResult);
		WSACleanup();
		return;
	}
	tcpListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (tcpListenSocket == INVALID_SOCKET) {
		printf("socket failed with error: %ld\n", WSAGetLastError());
		freeaddrinfo(result);
		WSACleanup();
		return;
	}
	iResult = bind(tcpListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(result);
		closesocket(tcpListenSocket);
		WSACleanup();
		return;
	}
	freeaddrinfo(result);
	iResult = listen(tcpListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		printf("listen failed with error: %d\n", WSAGetLastError());
		closesocket(tcpListenSocket);
		WSACleanup();
		return;
	}
}

void	WTCPSocket::acceptClient()
{
	tcpClientSocket = accept(tcpListenSocket, NULL, NULL);
	if (tcpClientSocket == INVALID_SOCKET) {
		printf("accept failed with error: %d\n", WSAGetLastError());
		closesocket(tcpListenSocket);
		WSACleanup();
		return;
	}
}

void	WTCPSocket::addClient()
{

}


WTCPSocket::WTCPSocket()
{
	_id = 0;
	_login = "";
}

WTCPSocket::~WTCPSocket()
{
	closesocket(tcpListenSocket);
	closesocket(tcpClientSocket);
	WSACleanup();
}