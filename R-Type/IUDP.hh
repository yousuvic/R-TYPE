#ifndef IUDP_HPP
#define	IUDP_HPP

class		IUDP
{
public:
	virtual ~IUDP() {}

	/*
	**	Server
	*/
	virtual	void	InitSrvUDP() = 0;			/*	INIT SERVER		*/
	virtual	int		ExchangeSrvUDP() = 0;		/*	INFINTE LOOP	*/
};

#endif // !IUDP_HPP