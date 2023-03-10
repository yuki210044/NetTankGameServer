#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Bullet.h"

namespace
{
    bool isCnnonShoot = false;
}

//コンストラクタ
Cannon::Cannon(GameObject* parent)
    :GameObject(parent, "Cannon"), hModel_(-1), isShotCannon(false), cannonMove(0)
{
}

//デストラクタ
Cannon::~Cannon()
{
}

//初期化
void Cannon::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("TankHead.fbx");
    assert(hModel_ >= 0);
}

//更新
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
        vMove = XMVector3Normalize(vMove);//ベクトルを正規化する
        vMove *= 0.5f;//ベクトルの速さを変える

        XMFLOAT3 move;
        XMStoreFloat3(&move, vMove);
        pBullet->SetPosition(shotPos);
        pBullet->SetMove(move);
        pBullet->hObject;
    }

}

//描画
void Cannon::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Cannon::Release()
{
}

void Cannon::KeyInput_Cannon(bool isShoot)
{
    isCnnonShoot = isShoot;
}
