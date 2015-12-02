#include "Packet.hh"

std::string		Packet::getData() const
{
	return _data;
}

int				Packet::getBytes() const
{
	return _bytes;
}

Packet::Packet()
{
}

Packet::~Packet()
{
}