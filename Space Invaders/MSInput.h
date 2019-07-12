#pragma once
#include "ComputerInput.h"
class MSInput :
	public CComputerInput
{
public:
	MSInput(float posX, float posY);
	~MSInput();

	//starts mothership animation
	void move() override;

	bool isActive() { return _active; }

private:
	bool _active;

	constexpr static float _mvmtSpd = 0.75f;
};

