#include "stdafx.h"
#include "NPCActor.h"
#include "StaticInput.h"

CNPCActor::CNPCActor(float posX_init, float posY_init, Graphics *graphics) : CActor(posX_init, posY_init, graphics), 
																			staticInput(new CStaticInput())
{
	hitsLeft = true;
	hitCount = 1;
	activate();
}


CNPCActor::~CNPCActor()
{
}

void CNPCActor::takeHit() {

	hitCount++;
	if (hitCount == 5) {
		hitsLeft = false;
	}
}
