#pragma once
#include "Actor.h"
#include "ComputerInput.h"

class CAlienActor :
	public CActor
{

public:

	CAlienActor(float posX_init, float posY_init, Graphics *graphic, int newRow);
	~CAlienActor();

	CAlienActor(const CAlienActor& objMan) = delete;//copy
	CAlienActor& operator=(const CAlienActor& objMan) = delete;//assignment

	CAlienActor(CAlienActor&& other) = delete;//move constructor

	inline I_Input* getInput() override { return alienInput; }
	inline int getRow() { return row; }

	void update() override;

private:
	CComputerInput* alienInput;
	int row;
};

