#include "Move.h"
#include "Engine/Input.h"

Move::Move()
{
    speed_ = 3.0f;
}


void Move::PreviousMove(XMFLOAT3* trans, XMFLOAT3* rotate)
{
    //���炩�̏���
    XMFLOAT3 move = { 0,0,0.3f };//z������0.1����
    XMVECTOR vMove = XMLoadFloat3(&move);//move��4�����x�N�g���ɂ���

    //XMMATRIX mRotate = XMMatrixIdentity();//�������Ȃ��s��(1.0.0.0)(0.1.0.0)(0.0.1.0)(0.0.0.1)�ŏ�����
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(rotate->y));//y����],XMConvertToRadians�͉��x��rad�ɕϊ������f�B���[�g�H�ŋt����

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMove��mRotate������]����

    XMVECTOR vPos = XMLoadFloat3(trans);//���ݒn���x�N�g���ɂ��đ��
    vPos += vMove;//move�̒��g({ 0,0,0.1f })�𑫂�

    XMStoreFloat3(trans, vPos);//���ݒn���ړ�����
}

void Move::BackMove(XMFLOAT3* trans, XMFLOAT3* rotate)
{
    //���炩�̏���
        //transform_.position_.z -= 0.3;
    XMFLOAT3 move = { 0,0,0.3f };//z������0.1����
    XMVECTOR vMove = XMLoadFloat3(&move);//move��4�����x�N�g���ɂ���

    //XMMATRIX mRotate = XMMatrixIdentity();//�������Ȃ��s��(1.0.0.0)(0.1.0.0)(0.0.1.0)(0.0.0.1)�ŏ�����
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(rotate->y));//y����],XMConvertToRadians�͉��x��rad�ɕϊ������f�B���[�g�H�ŋt����

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMove��mRotate������]����

    XMVECTOR vPos = XMLoadFloat3(trans);//���ݒn���x�N�g���ɂ��đ��
    vPos -= vMove;//move�̒��g({ 0,0,0.1f })�𑫂�

    XMStoreFloat3(trans, vPos);//���ݒn���ړ�����

    //command.push_back(DIK_S);
}

void Move::LeftMove(XMFLOAT3* rotate)
{
    rotate->y -= speed_;
}

void Move::CannonLeftMove(XMFLOAT3* rotate)
{
    rotate->y -= speed_;
}

void Move::RightMove(XMFLOAT3* rotate)
{
    rotate->y += speed_;
}

void Move::CannonRightMove(XMFLOAT3* rotate)
{
    rotate->y += speed_;
}
