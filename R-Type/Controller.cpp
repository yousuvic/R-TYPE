#include "Controller.hh"

void		Controller::update()
{
	sendActionPackets();
}

void	*exTCP(void *arg)
{
	std::cout << "TCP SERVER IS RUNNING !" << std::endl;

	Protocol				tcpProtocol;
	WExchange				talk;
	WSocket					*tcpSrv = new	WSocket(SOCK_STREAM, IPPROTO_TCP);	/*		TCP		*/
	Controller*				_this = reinterpret_cast<Controller*> (arg);
	Controller::clientList	clientInfo;
	bool					isClientOK;
	
	
	while (true)
	{
		isClientOK = false;
		tcpSrv->accept_();
		std::cout << "accept" << std::endl;
		
		while (isClientOK == false)
		{
			talk.recvTCP(tcpSrv->getSocket());
			std::cout << talk.getDataRecv() << std::endl;

		}

		clientInfo.id = (_this->getCList().size() + 1);
		clientInfo.clientSocket = tcpSrv->getSocket();
		clientInfo.login = "";

		_this->setClientInfo(&clientInfo);
		_this->setCList(clientInfo);

		
		//talk.recv(tcpSrv->getSocket());
	}
}

void		Controller::sendActionPackets()
{
	/*while (true)
	{
		newExchange->recv(newSocket->getSocket());
	}*/

	this->threadTCP->create(&exTCP, static_cast<void *>(this));	/*		THREAD		*/
	while (true);
		//std::cout << this->cList.size() << std::endl;
}

void	Controller::setClientInfo(Controller::clientList *info)
{
	this->clientInfo = info;
}

Controller::clientList	*Controller::getClientInfo() const
{
	return this->clientInfo;
}

void		Controller::setCList(Controller::clientList client)
{
	this->cList.push_back(client);
}

std::vector<Controller::clientList> Controller::getCList() const
{
	return this->cList;
}

Controller::Controller()
{	
	this->threadTCP = new WThread();
	this->clientInfo = new clientList;

	clientInfo->id = 0;
	clientInfo->clientSocket = INVALID_SOCKET;
	clientInfo->login = "";
	
	/*UDP*/
	//newSocket = new WSocket(SOCK_DGRAM, IPPROTO_UDP);
	//std::cout << "UDP SERVER IS RUNNING !" << std::endl;	
}

Controller::~Controller()
{
	delete	threadTCP;
	delete	tcpSocket;
}