#ifndef ITCPSOCKET_HH
#define	ITCPSOCKET_HH

class ITCPSocket
{
public:
	virtual			~ITCPSocket() = default;

	virtual void	init() = 0;
	virtual	void	resolveAdresse() = 0;
	virtual	void	acceptClient() = 0;
	virtual	void	addClient() = 0;
};

#endif // !ITCPSOCKET_HH