#ifndef UEXCHANGE_HH
#define	UEXCHANGE_HH

#include <iostream>
#include "IExchange.hh"

class UExchange	:	public IExchange
{
public:
	UExchange();
	virtual ~UExchange();

	Packet	recv(int socket);
	int		send(int socket, const Packet& packet);
};

#endif // !UEXCHANGE_HH
