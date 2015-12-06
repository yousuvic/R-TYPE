#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include "WExchange.hh"
#include "WSocket.hh"
#include "WThread.hh"

class Controller
{
public:
	Controller();
	~Controller();
	void	sendActionPackets();
	void	update();

private:
	WSocket		*tcpSocket;
	WExchange	*tcpExchange;
	WThread		*threadTCP;
};

#endif // !CONTROLLER_HH
