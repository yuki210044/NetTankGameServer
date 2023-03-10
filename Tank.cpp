#include "Tank.h"

#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Ground.h"
#include "Engine/SphereCollider.h"
#include "Engine/BoxCollider.h"

namespace
{
    XMFLOAT3 move = { 0,0,0 };
    Transform prevTrans;
}

//�R���X�g���N�^
Tank::Tank(GameObject* parent)
    :GameObject(parent, "Tank"), hModel_(-1), Life_(3), invincibleTime_(-1)
{
}
//�f�X�g���N�^
Tank::~Tank()
{
}

//������
void Tank::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("TankBase.fbx");
    assert(hModel_ >= 0);
    pCnnon = Instantiate<Cannon>(this);

    BoxCollider* collision = new BoxCollider({ 0,0,0 }, {1,1,1});
    AddCollider(collision);

    prevTrans = transform_;
}

//�X�V
void Tank::Update()
{
    //���G����
    invincibleTime_--;
}

//�`��
void Tank::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Tank::Release()
{
}

void Tank::KeyInput(float nowMove, float rotateY)
{
    transform_.rotate_.y = rotateY;
    move.z = nowMove;
}