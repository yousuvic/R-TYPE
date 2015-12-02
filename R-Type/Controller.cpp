#include "Controller.hh"

void		Controller::update()
{
	sendActionPackets();
}

void		Controller::sendActionPackets()
{
	//srv->InitSrvUDP();
	//srv->ExchangeSrvUDP();
}

Controller::Controller()
{
	//srv = new UDPExchangeWin;
}

Controller::~Controller()
{
}