#include "Enemy.h"
#include<stdio.h>

//メンバ関数ポインタテーブルの用意
void (Enemy::* Enemy::pFuncTable[])() =
{
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::GetAway
};

Enemy::Enemy()
{
	phase_ = 0;
}

Enemy::~Enemy()
{
}


void Enemy::Approach()
{
	printf("近づく\n");
}

void Enemy::Shoot()
{
	printf("撃つ\n");
}

void Enemy::GetAway()
{
	printf("離脱\n");
}

void Enemy::Update()
{
	//デバッグ用
	printf("phase_ : %d\n", phase_);

	//現在の行動フェーズを実行する
	(this->*pFuncTable[phase_])();

	//次の行動フェーズに移行する
	phase_++;
	if (phase_ > 2)
	{
		phase_ = 0;
	}
}

void Enemy::Draw()
{
	printf("敵の描画\n");
}