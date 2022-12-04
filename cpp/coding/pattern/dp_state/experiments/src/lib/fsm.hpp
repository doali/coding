#ifndef __FSM__
#define __FSM__

#include <array>

struct Fsm;

struct State
{
	State(std::string);
	virtual ~State() = default;

	virtual void nextState() = 0;
	std::string info();
	void init(Fsm *);

	Fsm *m_fsm{nullptr};
	std::string m_info{""};
};

struct Fsm
{
	~Fsm();

	void setState(State *);
	void nextState();

	void initStates();
	void startState(State *);

	std::array<State *, 2> m_states;
	State *m_state{nullptr};
};

struct Ping : State
{
	Ping();
	~Ping() override = default;

	void nextState() override;
};

struct Pong : State
{
	Pong();
	~Pong() override = default;

	void nextState() override;
};

#endif