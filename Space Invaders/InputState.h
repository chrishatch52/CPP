#pragma once
class CInputState
{
	friend class CObjectManager;
public:
	enum State {
		MOVE = 0,
		ATTACK,
		SPECIAL_ATK, //user only
		SPECIAL_DEF, //user only
		PAUSE, //user only
		QUIT, //user only
		DEFAULT //initializer value
	};
public:
	CInputState();
	~CInputState() = default;

	CInputState(const CInputState& objMan) = delete;//copy
	CInputState& operator=(const CInputState& objMan) = delete;//assignment

	CInputState(CInputState&& other) = delete;//move constructor

	inline State getState() { return state; }

	inline void setState(State inputState) { state = inputState; }

private:
	State state;
};

