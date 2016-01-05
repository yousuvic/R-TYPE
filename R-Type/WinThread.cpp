#include "WinThread.hh"

WinThread::WinThread()
{
}

WinThread::~WinThread()
{
}

void		WinThread::create(void *(*start_routine)(void *), void *arg)
{
	this->thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)start_routine, (LPVOID)arg, 0, NULL);
}

void		WinThread::cancel(void)
{
	TerminateThread(this->thread, -1);
}

void		WinThread::join(void)
{
	WaitForSingleObject(this->thread, INFINITE);
}