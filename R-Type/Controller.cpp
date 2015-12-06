#include "Controller.hh"

void		Controller::update()
{
	sendActionPackets();
}

void		Controller::sendActionPackets()
{
	/*while (true)
	{
		newExchange->recv(newSocket->getSocket());
	}*/
}

void	*exTCP(void *arg)
{
	std::cout << "TCP SERVER IS RUNNING !" << std::endl;

	WExchange	*talk = reinterpret_cast<WExchange *> (arg);
	WSocket		*tcpSrv = new	WSocket(SOCK_STREAM, IPPROTO_TCP);	/*		TCP		*/

	while (true)
	{
		//talk.recv(tcpSrv->getSocket());
	}
}

Controller::Controller()
{
	this->tcpExchange = new WExchange();
	this->threadTCP = new WThread();

	threadTCP->create(&exTCP, static_cast<void *>(tcpExchange));
	while (true)
	{

	}
	/*UDP*/
	//newSocket = new WSocket(SOCK_DGRAM, IPPROTO_UDP);
	//std::cout << "UDP SERVER IS RUNNING !" << std::endl;	
}

Controller::~Controller()
{
	delete	tcpExchange;
	delete	tcpSocket;
}