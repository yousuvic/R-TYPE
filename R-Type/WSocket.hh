#ifndef WSOCKET_HH
#define	WSOCKET_HH

#include <stdio.h>
#include <winsock2.h>

#include <string>

#include "ISocket.hh"


#pragma comment(lib,"ws2_32.lib") //Winsock Library


#define PORT 4242

class WSocket	:	public	ISocket
{
public:
	/*
	* Constructor that initialize USocket object
	*
	* @param		const std::string&	address
	* @param		int			port
	* @return		void
	*/
	WSocket();

	/*
	* Destructor that destroy USocket object
	*
	* @param		void
	* @return		void
	*/
	virtual ~WSocket();

	/*
	* Initialize and create udp socket and bind the socket to a port number
	*
	* @param		void
	* @return		void
	*/
	void			init();

	/*
	* Virtual setter to set the socket as non-blocking mode
	*
	* @param     void
	* @return    void
	*/
	void			setNonBlockingMode();

	/*
	* Run the socket service i/o
	*
	* @param		void
	* @return		void
	*/
	void			run();

	/*
	* Close the socket
	*
	* @param		void
	* @return		void
	*/
	void			closeSocket();

	/* ----------- GETTERS ----------- */

	/*
	* Return socket of the object
	*
	* @param		void
	* @return		int
	*/
	int			getSocket() const;

	/*
	* Return the server's port
	*
	* @param		void
	* @return		int
	*/
	int			getPort() const;

	/*
	* Return the server's address
	*
	* @param		void
	* @return		std::string
	*/
	std::string		getAddress() const;

private:
	SOCKET				_socket;
	struct sockaddr_in	_server;
	int					_slen;
	int					_recv_len;
	WSADATA				_wsa;

	int					recv_len;
	char				data[512];
};

#endif // !WSOCKET_HH
