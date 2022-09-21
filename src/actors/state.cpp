#include "state.h"

void actor::State::Update()
{
}

int actor::State::GetState() const
{
	return state_current_;
}

void actor::State::SetState(int state)
{
	state_current_ = state;
}
