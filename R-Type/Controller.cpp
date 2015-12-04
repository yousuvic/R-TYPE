#include "Controller.hh"

void		Controller::update()
{
	sendActionPackets();
}

void		Controller::sendActionPackets()
{
	while (true)
	{
		newExchange->recv(newSocket->getSocket());
	}
}

Controller::Controller()
{
	newExchange = new WExchange();
	/*UDP*/
	//newSocket = new WSocket(SOCK_DGRAM, IPPROTO_UDP);

	/*TCP*/
	newSocket = new WSocket(SOCK_STREAM, IPPROTO_TCP);
	
}

Controller::~Controller()
{
	delete	newExchange;
	delete	newSocket;
}