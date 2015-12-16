#include "WExchange.hh"

void		WExchange::recvUDP(int socket)
{
	int		bytes;
	int		_slen;

	_slen = sizeof(_si_other);
	bytes = recvfrom(socket, reinterpret_cast<char*>(&_recvData), sizeof(Packet::keyPressed), 0, (sockaddr*)&_si_other, &_slen);
	//std::cout << "data recu : " << data << std::endl;
}

int		WExchange::sendUDP(int socket, const Packet& packet)
{
	int		sent_bytes;

	sent_bytes = sendto(socket, (const char*)packet.getData().c_str(), packet.getData().size(), 0, (sockaddr*)&_si_other, sizeof(_si_other));
	return (sent_bytes);
}

void	WExchange::sendTCP(int socket)
{
	send(socket, (char *)_data_send, 100, 0);
}

void	WExchange::recvTCP(int socket)
{
	memset(_data_recv, 0, 100);
	recv(socket, _data_recv, 100, 0);
}

char	*WExchange::getDataRecv() const
{
	return	(char *)this->_data_recv;
}

char	*WExchange::getDataSend() const
{
	return	(char *)this->_data_send;
}

WExchange::WExchange()
{

}

WExchange::~WExchange()
{
}
