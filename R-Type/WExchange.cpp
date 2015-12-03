#include "WExchange.hh"

Packet		WExchange::recv(int socket)
{
	Packet	_packet;
	int		bytes;
	char	data[256];
	int		_slen;

	_slen = sizeof(_si_other);
	memset(data, 0, sizeof(data));
	bytes = recvfrom(socket, reinterpret_cast<char*>(&_recvData), sizeof(Packet::keyPressed), 0, (sockaddr*)&_si_other, &_slen);
	std::cout << "data recu : " << data << std::endl;
	return (_packet);
}

int		WExchange::send(int socket, const Packet& packet)
{
	int		sent_bytes;

	sent_bytes = sendto(socket, (const char*)packet.getData().c_str(), packet.getData().size(), 0, (sockaddr*)&_si_other, sizeof(_si_other));
	return (sent_bytes);
}

WExchange::WExchange()
{
}

WExchange::~WExchange()
{
}
