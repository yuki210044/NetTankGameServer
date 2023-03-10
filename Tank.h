#pragma once
#include "Engine/GameObject.h"
#include "Cannon.h"


//◆◆◆を管理するクラス
class Tank : public GameObject
{
    int hModel_;    //モデル番号
    int Life_;      //残機
    int invincibleTime_;    //無敵時間
    Cannon* pCnnon;
public:
    //コンストラクタ
    Tank(GameObject* parent);

    //デストラクタ
    ~Tank();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void KeyInput(float nowMove, float rotateY);

    Cannon* GetCannonInstance() { return pCnnon; }

};