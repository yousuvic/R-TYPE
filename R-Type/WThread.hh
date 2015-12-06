#ifndef WTHREAD_HH
#define	WTHREAD_HH

#include <Windows.h>
#include <process.h>
#include <pthread.h>
#include <iostream>

#include "IThread.hh"

class WThread :	public	IThread
{
public:
	WThread();
	virtual	~WThread();

	void	create(void* (*start_routine)(void *), void *arg);
	void	join();
	void	cancel();

private:
	pthread_t	myhandle;
	bool		_state = false;
};

#endif // !WTHREAD_HH
