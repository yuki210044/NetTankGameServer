#pragma once
#include "Engine/GameObject.h"

//���������Ǘ�����N���X
class Bullet : public GameObject
{
    int hModel_;    //���f���ԍ�
    XMFLOAT3 move_;//�ړ���
    float fall;
   
public:
    int hObject;
    //�R���X�g���N�^
    Bullet(GameObject* parent);

    //�f�X�g���N�^
    ~Bullet();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    void SetMove(XMFLOAT3 move) { move_ = move; }

    void OnCollision(GameObject* pTarget);
};