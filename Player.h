#pragma once
#include "Engine/GameObject.h"
#include "Tank.h"
#include "Cannon.h"
#include "RecvData.h"

class Player : public GameObject
{
    Tank* pTank;
    Cannon* pCannon;
    int hObject;
    
public:
    int hPlayer;
    Player(GameObject* parent);
    //デストラクタ
    ~Player();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    void SetObjectHandle(int hObj) { hObject = hObj; }

    int GetObjectHandle() { return hObject; }

    Tank* GetTank() { return pTank; }

    void OnCollision(GameObject* pTarget) override;

    void SetRecvDate(RecvDateToClient r);
};

