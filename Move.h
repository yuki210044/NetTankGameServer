#pragma once
#include "Engine/Transform.h"

class Move
{
	float speed_;
public:
	Move();

	virtual void MoveSelect(int move, XMFLOAT3* trans, XMFLOAT3* rotate) = 0;

	void PreviousMove(XMFLOAT3* trans, XMFLOAT3* rotate);

	void BackMove(XMFLOAT3* trans, XMFLOAT3* rotate);

	void LeftMove(XMFLOAT3* rotate);
	
	void CannonLeftMove(XMFLOAT3* rotate);

	void RightMove(XMFLOAT3* rotate);

	void CannonRightMove(XMFLOAT3* rotate);
};

