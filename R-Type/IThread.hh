#ifndef ITHREAD_HH
#define	ITHREAD_HH

class IThread
{
public:
	virtual			~IThread() = default;

	virtual	void	create(void* (*start_routine)(void *), void *arg) = 0;
	virtual	void	join() = 0;
	virtual	void	cancel() = 0;
};

#endif // !ITHREAD_HH
