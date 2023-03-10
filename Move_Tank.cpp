#include "Move_Tank.h"

void Move_Tank::MoveSelect(int move, XMFLOAT3* trans, XMFLOAT3* rotate)
{
    switch (move)
    {
    case 0:
    {
        PreviousMove(trans, rotate);
        break;
    }
    case 1:
    {
        BackMove(trans, rotate);
        break;
    }
    case 2:
    {
        LeftMove(rotate);
        break;
    }
    case 3:
    {
        RightMove(rotate);
        break;
    }
    default:
        break;
    }
}
