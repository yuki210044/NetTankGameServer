#include "Move_Cannon.h"

void Move_Cannon::MoveSelect(int move, XMFLOAT3* trans, XMFLOAT3* rotate)
{
    switch (move)
    {
    case 0:
    {
        CannonLeftMove(rotate);
        break;
    }
    case 1:
    {
        CannonRightMove(rotate);
        break;
    }
    default:
        break;
    }
}
