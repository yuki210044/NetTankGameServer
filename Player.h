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
    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetObjectHandle(int hObj) { hObject = hObj; }

    int GetObjectHandle() { return hObject; }

    Tank* GetTank() { return pTank; }

    void OnCollision(GameObject* pTarget) override;

    void SetRecvDate(RecvDateToClient r);
};

