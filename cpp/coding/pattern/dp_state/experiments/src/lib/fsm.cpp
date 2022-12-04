#include "fsm.hpp"

#include <iostream>

State::State(std::string info) : m_info{info}
{
}

std::string State::info()
{
	return m_info;
}

void State::init(Fsm *fsm)
{
	m_fsm = fsm;
}

void Fsm::setState(State *state)
{
	m_state = state;
}

void Fsm::nextState()
{
	std::cout << m_state->info() << " -> ";
	m_state->nextState();
	std::cout << m_state->info() << std::endl;
}

void Fsm::initStates()
{
	m_states[0] = new Ping();
	m_states[1] = new Pong();

	for (State *state : m_states)
	{
		state->init(this);
	}
}

void Fsm::startState(State *state)
{
	setState(state);
}

Fsm::~Fsm()
{
	for (auto &element : m_states)
	{
		delete element;
	}
}

Ping::Ping() : State("ping")
{
}

void Ping::nextState()
{
	m_fsm->setState(m_fsm->m_states[1]);
}

Pong::Pong() : State("pong")
{
}

void Pong::nextState()
{
	m_fsm->setState(m_fsm->m_states[0]);
}
