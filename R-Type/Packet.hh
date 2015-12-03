#ifndef PACKET_HH
#define	PACKET_HH

#include <iostream>
#include <string>

class Packet
{
public:
	struct keyPressed
	{
		bool	_up;
		bool	_down;
		bool	_forward;
		bool	_backward;
	};

	Packet();
	~Packet();

	std::string	getData() const;
	int			getBytes() const;

private:
	std::string	_data;
	int			_bytes;
};

#endif // !PACKET_HH
