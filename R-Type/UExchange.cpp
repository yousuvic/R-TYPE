#include "UExchange.hh"

Packet		UExchange::recv(int socket)
{
	tmp->recv();
}

int		UExchange::send(int socket, const Packet& packet)
{
	tmp->send();	
}

UExchange::UExchange(USocket *srv)
{
	// tmp -> USocket *tmp;
	tmp = srv;
}

UExchange::~UExchange()
{
}
