#include "Controller.hh"

int		main()
{
	Controller	*Server = new Controller;

	while (1)
		Server->update();
	return (0);
}