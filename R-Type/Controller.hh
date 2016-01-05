#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include "WExchange.hh"
#include "Protocol.hh"
#include "WSocket.hh"
#include "WinThread.hh"

class Controller
{
public:
	Controller();
	~Controller();
	void	sendActionPackets();
	void	update();

private:
	WSocket		*tcpSocket;
	WinThread		*threadTCP;

};

#endif // !CONTROLLER_HH
