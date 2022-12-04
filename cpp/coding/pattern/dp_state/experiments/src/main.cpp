#include "fsm.hpp"

#include <iostream>
#include <unistd.h>

int main(int argc, char **argv)
{
	Fsm fsm;
	fsm.initStates();
	fsm.startState(fsm.m_states[0U]);

	const u_int MAX_ITE{5U};
	u_int nb_ite{0U};
	while (nb_ite < MAX_ITE)
	{
		std::cout << "[" << nb_ite << "]" << std::endl;

		fsm.nextState();

		sleep(1U);
		++nb_ite;
	}

	return 0;
}
