#ifndef		_ISOCKET_HH_
# define	_ISOCKET_HH_

class		ISocket
{

public:
  virtual	~ISocket() = default;

  virtual void	create_(int type, int protocol) = 0;
  virtual void	bind_() = 0;
  virtual void	listen_() = 0;
  virtual void	accept_() = 0;

};

#endif		/* _ISOCKET_HH_*/
