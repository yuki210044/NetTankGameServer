#pragma once
#include "Engine/GameObject.h"

//◆◆◆を管理するクラス
class Bullet : public GameObject
{
    int hModel_;    //モデル番号
    XMFLOAT3 move_;//移動量
    float fall;
   
public:
    int hObject;
    //コンストラクタ
    Bullet(GameObject* parent);

    //デストラクタ
    ~Bullet();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetMove(XMFLOAT3 move) { move_ = move; }

    void OnCollision(GameObject* pTarget);
};