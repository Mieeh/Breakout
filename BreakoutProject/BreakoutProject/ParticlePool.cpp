#include "ParticlePool.h"

void ParticlePool::create(double a_x, double a_y, double a_velocityX, double a_velocityY, double a_accX, double a_accY, int a_lifeTime)
{
	for (int i = 0; i < POOL_SIZE; i++) {
		if (!particleArray[i].alive()) {
			particleArray[i].init(a_x, a_y, a_velocityX, a_velocityY, a_accX, a_accY, a_lifeTime);
			return;
		}
	}
}

void ParticlePool::drawParticles(sf::RenderTarget & target)
{
	for (int i = 0; i < POOL_SIZE; i++) {
		if (particleArray[i].alive())
			target.draw(particleArray[i].getShape());
	}
}

void ParticlePool::update(float deltaTime)
{
	for (int i = 0; i < POOL_SIZE; i++) {
		particleArray[i].update(deltaTime);
	}
}
