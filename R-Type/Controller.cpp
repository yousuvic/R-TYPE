#include "Controller.hh"

void		Controller::update()
{
	sendActionPackets();
}

void	*exTCP(void *arg)
{
	std::cout << "TCP SERVER IS RUNNING !" << std::endl;

	//Controller::clientList	*clientInfo = reinterpret_cast<Controller::clientList *> (arg);
	WExchange				*talk = reinterpret_cast<WExchange *> (arg);
	WSocket					*tcpSrv = new	WSocket(SOCK_STREAM, IPPROTO_TCP);	/*		TCP		*/


	/*clientInfo->id = 1;
	clientInfo->clientSocket = INVALID_SOCKET;
	clientInfo->login = "";*/

	while (true)
	{
		//talk.recv(tcpSrv->getSocket());
	}
}

void		Controller::sendActionPackets()
{
	/*while (true)
	{
		newExchange->recv(newSocket->getSocket());
	}*/

	
	this->threadTCP->create(&exTCP, static_cast<void *>(tcpExchange));	/*		THREAD		*/
	while (true);
}

void	Controller::setClientInfo(Controller::clientList *info)
{
	this->clientInfo = info;
}

Controller::Controller()
{	
	/*clientInfo = new clientList;

	clientInfo->id = 0;
	clientInfo->clientSocket = INVALID_SOCKET;
	clientInfo->login = "";*/
	

	this->tcpExchange = new WExchange();
	this->threadTCP = new WThread();

	/*UDP*/
	//newSocket = new WSocket(SOCK_DGRAM, IPPROTO_UDP);
	//std::cout << "UDP SERVER IS RUNNING !" << std::endl;	
}

Controller::~Controller()
{
	delete	tcpExchange;
	delete	tcpSocket;
}