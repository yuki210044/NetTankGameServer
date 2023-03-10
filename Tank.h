#pragma once
#include "Engine/GameObject.h"
#include "Cannon.h"


//���������Ǘ�����N���X
class Tank : public GameObject
{
    int hModel_;    //���f���ԍ�
    int Life_;      //�c�@
    int invincibleTime_;    //���G����
    Cannon* pCnnon;
public:
    //�R���X�g���N�^
    Tank(GameObject* parent);

    //�f�X�g���N�^
    ~Tank();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void KeyInput(float nowMove, float rotateY);

    Cannon* GetCannonInstance() { return pCnnon; }

};