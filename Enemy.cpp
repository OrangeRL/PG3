#include "Enemy.h"
#include "DxLib.h"

bool Enemy::isAlive = true;

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Enemy* Enemy::GetInstance()
{
	static Enemy instance;

	return &instance;
}

void Enemy::Dead()
{
	isAlive = false;
}

void Enemy::Draw(int x, int y)
{
	if (isAlive)
	{
		DrawCircle(x, y, 50, GetColor(255, 255, 0), true);
	}
}