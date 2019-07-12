#pragma once
#include "Input.h"

class CStaticInput :
	public I_Input
{
public:
	CStaticInput() = default;
	~CStaticInput() = default;

	CStaticInput(const CStaticInput& other) = delete; //copy
	CStaticInput& operator=(const CStaticInput& other) = delete; //assignment

	CStaticInput(CStaticInput&& other) = delete; //move constructor

	void move() override {} //static
};

