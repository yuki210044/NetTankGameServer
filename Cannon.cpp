#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Bullet.h"

namespace
{
    bool isCnnonShoot = false;
}

//�R���X�g���N�^
Cannon::Cannon(GameObject* parent)
    :GameObject(parent, "Cannon"), hModel_(-1), isShotCannon(false), cannonMove(0)
{
}

//�f�X�g���N�^
Cannon::~Cannon()
{
}

//������
void Cannon::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("TankHead.fbx");
    assert(hModel_ >= 0);
}

//�X�V
void Cannon::Update()
{
    if (isCnnonShoot)
    {
        Bullet* pBullet = Instantiate<Bullet>(GetParent()->GetParent());

        XMFLOAT3 shotPos = Model::GetBonePosition(hModel_, "ShotPos");
        XMFLOAT3 CannonRoot = Model::GetBonePosition(hModel_, "CannonRoot");

        XMVECTOR vshotPos = XMLoadFloat3(&shotPos);
        XMVECTOR vCannonRoot = XMLoadFloat3(&CannonRoot);
        XMVECTOR vMove = vshotPos - vCannonRoot;
        vMove = XMVector3Normalize(vMove);//�x�N�g���𐳋K������
        vMove *= 0.5f;//�x�N�g���̑�����ς���

        XMFLOAT3 move;
        XMStoreFloat3(&move, vMove);
        pBullet->SetPosition(shotPos);
        pBullet->SetMove(move);
        pBullet->hObject;
    }

}

//�`��
void Cannon::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Cannon::Release()
{
}

void Cannon::KeyInput_Cannon(bool isShoot)
{
    isCnnonShoot = isShoot;
}
