#pragma once
#include <vector>

class I_Input
{
public:
	enum Direction {
		LEFT = 0,
		RIGHT
	};

	Direction dir;
	Direction getDir() { return dir; }
public:
	virtual void move() = 0;
};

