#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Cannon : public GameObject
{
    int hModel_;    //���f���ԍ�
   
    bool  isShotCannon;
public:
    float cannonMove;
    //�R���X�g���N�^
    Cannon(GameObject* parent);

    //�f�X�g���N�^
    ~Cannon();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void KeyInput_Cannon(bool isShoot);
};