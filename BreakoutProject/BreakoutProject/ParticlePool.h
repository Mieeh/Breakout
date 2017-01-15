#pragma once

#include"Particle.h"

class ParticlePool {
public:
	void create(double a_x, double a_y, double a_velocityX, double a_velocityY, double a_accX, double a_accY, int a_lifeTime);

	void drawParticles(sf::RenderTarget &target);
	void update(float deltaTime);

private:
	static const int POOL_SIZE = 250;
	Particle particleArray[POOL_SIZE];
};