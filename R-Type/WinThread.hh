#ifndef WINTHREAD_HH
#define	WINTHREAD_HH

#include <Windows.h>
#include <process.h>
#include <pthread.h>
#include <iostream>

#include "IThread.hh"

class WinThread : public	IThread
{
public:
	WinThread();
	virtual	~WinThread();

	void		create(void *(*start_routine)(void *), void *arg);
	void		cancel();
	void		join();

private:
	HANDLE thread;
};

#endif // !WINTHREAD_HH