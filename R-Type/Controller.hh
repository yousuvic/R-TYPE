#ifndef CONTROLLER_HH
#define	CONTROLLER_HH

#include "UdpExchangeWin.hh"

class Controller
{
public:
	Controller();
	~Controller();
	void	sendActionPackets();
	void	update();

private:
	UDPExchangeWin		*srv;
};

#endif // !CONTROLLER_HH
