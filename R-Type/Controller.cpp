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
	newSocket = new WSocket();

	newSocket->init();
	newSocket->setNonBlockingMode();
}

Controller::~Controller()
{
	delete	newExchange;
	delete	newSocket;
}