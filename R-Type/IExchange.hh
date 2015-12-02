//
// IExchange.hh for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/network
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Tue Nov 24 17:55:43 2015 SOIDIKI Djamil
// Last update Thu Nov 26 20:26:38 2015 SOIDIKI Djamil
//

#ifndef		_IEXCHANGE_HH_
#define		_IEXCHANGE_HH_

#include	"Packet.hh"

class		IExchange
{

public:
  virtual	~IExchange() = default;

  virtual Packet	recv(int socket) = 0;
  virtual int		send(int socket, const Packet& packet) = 0;
};

#endif		/* _IEXCHANGE_HH_ */
