#include "WThread.hh"

void	WThread::create(void* (*start_routine)(void *), void *arg)
{
	int	error;

	error = pthread_create(&(this->myhandle), NULL, start_routine, arg);
	if (error != 0)
		exit(EXIT_FAILURE);
	this->_state = true;
}

void	WThread::join()
{
	int	error;

	if (this->_state == true)
	{
		error = pthread_join(this->myhandle, NULL);
		if (error != 0)
			exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}

void	WThread::cancel()
{
	int	error;

	if (this->_state == true)
	{
		error = pthread_cancel(this->myhandle);
		if (error != 0)
			exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
}

WThread::WThread()
{

}

WThread::~WThread()
{

}