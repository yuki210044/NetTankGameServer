#include "Move.h"
#include "Engine/Input.h"

Move::Move()
{
    speed_ = 3.0f;
}


void Move::PreviousMove(XMFLOAT3* trans, XMFLOAT3* rotate)
{
    //何らかの処理
    XMFLOAT3 move = { 0,0,0.3f };//z方向に0.1動く
    XMVECTOR vMove = XMLoadFloat3(&move);//moveを4次元ベクトルにする

    //XMMATRIX mRotate = XMMatrixIdentity();//何もしない行列(1.0.0.0)(0.1.0.0)(0.0.1.0)(0.0.0.1)で初期化
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(rotate->y));//y軸回転,XMConvertToRadiansは何度をradに変換するやつディレート？で逆も可

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMoveをmRotateだけ回転する

    XMVECTOR vPos = XMLoadFloat3(trans);//現在地をベクトルにして代入
    vPos += vMove;//moveの中身({ 0,0,0.1f })を足す

    XMStoreFloat3(trans, vPos);//現在地を移動する
}

void Move::BackMove(XMFLOAT3* trans, XMFLOAT3* rotate)
{
    //何らかの処理
        //transform_.position_.z -= 0.3;
    XMFLOAT3 move = { 0,0,0.3f };//z方向に0.1動く
    XMVECTOR vMove = XMLoadFloat3(&move);//moveを4次元ベクトルにする

    //XMMATRIX mRotate = XMMatrixIdentity();//何もしない行列(1.0.0.0)(0.1.0.0)(0.0.1.0)(0.0.0.1)で初期化
    XMMATRIX mRotate = XMMatrixRotationY(XMConvertToRadians(rotate->y));//y軸回転,XMConvertToRadiansは何度をradに変換するやつディレート？で逆も可

    vMove = XMVector3TransformCoord(vMove, mRotate);//vMoveをmRotateだけ回転する

    XMVECTOR vPos = XMLoadFloat3(trans);//現在地をベクトルにして代入
    vPos -= vMove;//moveの中身({ 0,0,0.1f })を足す

    XMStoreFloat3(trans, vPos);//現在地を移動する

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
