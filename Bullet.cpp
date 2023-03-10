#define _WINSOCKAPI_ //WinSock2の再定義回避
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "NetWork.h"
#include "Player.h"

//コンストラクタ
Bullet::Bullet(GameObject* parent)
    :GameObject(parent, "Bullet"), hModel_(-1), move_(XMFLOAT3(0.1f, 0, 0)), fall(0)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("TankBullet.fbx");
    assert(hModel_ >= 0);

    SphereCollider* collision = new SphereCollider({0,0,0},1);
    AddCollider(collision);
}

//更新
void Bullet::Update()
{
    XMVECTOR vPos = XMLoadFloat3(&transform_.position_);

    XMVECTOR vMove = XMLoadFloat3(&move_);
    XMStoreFloat3(&transform_.position_, vPos + vMove);

    transform_.position_.y -= fall;
    fall += 0.01;
    if (transform_.position_.y <= -5)
        KillMe();
}

//描画
void Bullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}

void Bullet::OnCollision(GameObject* pTarget)
{
    if (pTarget == this->FindObject("Player"))
    {
        SendCorrespondence send;
        send.h.position = transform_.position_;
        send.h.targetPlayerNum = ((Player*)pTarget)->GetObjectHandle();
        send.h.objNum = hObject;
        send.h.hitReaction = 1;
        NetWork::UpdateSend(send, ((Player*)pTarget)->GetObjectHandle());
    }
}
