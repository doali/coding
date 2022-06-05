#include <iostream>

struct Context;

struct State 
{    
    Context *_ctx;
    
    State(Context *ctx) : _ctx{ctx}
    {        
        // std::cout << __func__ << std::endl;
    }
    virtual ~State() = 0;

    virtual void transToA() = 0;
    virtual void transToB() = 0;

    virtual void say() = 0;
    virtual void info() = 0;
};

State::~State() = default;

struct StateA : State
{
    StateA(Context *ctx) : State(ctx) 
    {
        // std::cout << __func__ << std::endl;
    }

    ~StateA() override = default;

    void transToA() override
    {
        // leave me empty
    }

    void transToB() override;

    void say() override
    {
        std::cout << "PING" << std::endl;
    }

    void info() override
    {
        std::cout << "A" << std::endl;
    }
};

struct StateB : State
{
    StateB(Context *ctx) : State(ctx) 
    {
        // std::cout << __func__ << std::endl;
    }
    ~StateB() override = default;

    void transToA() override;

    void transToB() override
    {
        // leave me empty
    }

    void say() override
    {
        std::cout << "PONG"  << std::endl;
    }

    void info() override
    {
        std::cout << "B" << std::endl;
    }
};

struct Context 
{
    StateA *_stateA;
    StateB *_stateB;
    State *_state; // current state
    unsigned int _nb_ite;
    
    Context(unsigned int nb_ite) :
        _nb_ite{nb_ite}
    {
        _stateA = new StateA(this);
        _stateB = new StateB(this);
        _state = _stateA; // initial state
    }

    ~Context()
    {
        delete _stateA;
        delete _stateB;
    }

    void setState(State *state)
    {
        _state = state;
    }

    void shiftToA() 
    {
        _state->transToA();
    }

    void shiftToB()
    {
        _state->transToB();
    }

    void infoState()
    {
        // _state->info();
        _state->say();
    }
};

void StateA::transToB()
{
    if (_ctx != nullptr)
    {
        _ctx->setState(_ctx->_stateB);
        // std::cout << "A -> B" << std::endl;
    }
}    

void StateB::transToA()
{
    if (_ctx != nullptr)
    {
        _ctx->setState(_ctx->_stateA);
        // std::cout << "B -> A" << std::endl;
    }        
}

int main(int argc, char **argv)
{
    Context ctx{4};

    while (ctx._nb_ite != 0) 
    {
        ctx.shiftToA();
        ctx.infoState();

        ctx.shiftToB();
        ctx.infoState();

        --ctx._nb_ite;
    }
    
    return 0;
}