#ifndef		_ISOCKET_HH_
# define	_ISOCKET_HH_

class		ISocket
{

public:
  /*
   * Virtual destructor for interface class
   *
   * @param	void
   * @return	void
   */
  virtual	~ISocket() = default;
  
  /*
   * Virtual function to initialize and create udp socket and bind it
   *
   * @param	void
   * @return	void
   */
  virtual void	init() = 0;

  /*
   * Virtual setter to set the socket as non-blocking mode
   * 
   * @param	void
   * @return	void
   */
  virtual void	setNonBlockingMode() = 0;

  /*
   * Virtual function to run the socket service i/o
   *
   * @param	void
   * @return	void
   */
  virtual void	run() = 0;   
};

#endif		/* _ISOCKET_HH_*/
