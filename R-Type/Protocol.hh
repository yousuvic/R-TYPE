#ifndef PROTOCOL_HH
#define	PROTOCOL_HH

#include <iostream>
#include <winsock2.h>
#include <string>

class Protocol
{
public:
	Protocol();
	~Protocol();

	void	greeting(int socket);
	void	recvLogin(int socket);

private:

};

#endif // !PROTOCOL_HH
