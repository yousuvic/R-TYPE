#include "Protocol.hh"

void	Protocol::greeting(int socket)
{
	try
	{
		send(socket, "greeting", 8, 0);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what();
	}
}

void	Protocol::recvLogin(int socket)
{
	try
	{
		send(socket, "ok", 2, 0);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what();
	}
}

Protocol::Protocol()
{

}

Protocol::~Protocol()
{

}