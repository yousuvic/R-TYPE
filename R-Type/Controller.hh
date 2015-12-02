#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include "WExchange.hh"
#include "WSocket.hh"

class Controller
{
public:
	Controller();
	~Controller();
	void	sendActionPackets();
	void	update();

private:
	WSocket		*newSocket;
	WExchange	*newExchange;
};

#endif // !CONTROLLER_HH
