#pragma once
#include "Actor.h"
#include "StaticInput.h"
#include <iostream>
class CNPCActor :
	public CActor
{

public:

	CNPCActor() = default;
	explicit CNPCActor(float posX_init, float posY_init, Graphics *graphics);
	~CNPCActor();

	CNPCActor(const CNPCActor& objMan) = delete;//copy
	CNPCActor& operator=(const CNPCActor& objMan) = delete;//assignment

	CNPCActor(CNPCActor&& other) = delete;//move constructor

	void update() {}

	inline bool hasHitsLeft() { return hitsLeft; }
	void takeHit();

	inline I_Input* getInput() { return staticInput; }

private:
	bool hitsLeft;
	int hitCount;
	constexpr static int maxHits = 5;
	CStaticInput* staticInput;
};

