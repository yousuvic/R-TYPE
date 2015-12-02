#ifndef PACKET_HH
#define	PACKET_HH

#include <iostream>
#include <string>

class Packet
{
public:
	Packet();
	~Packet();

	std::string	getData() const;
	int			getBytes() const;

private:
	std::string	_data;
	int			_bytes;
};

#endif // !PACKET_HH
