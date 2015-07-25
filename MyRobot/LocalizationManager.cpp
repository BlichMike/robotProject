#include "LocalizationManager.h"

//C'Tor
LocalizationManager::LocalizationManager(float robotCoordinateX,float robotCoordinateY)
{
	printParticlesInterval = 0;
	particlesInit(robotCoordinateX,robotCoordinateY);
}

// add new particle to particles vector
void LocalizationManager::particlesInit(float robotCoordinateX,float robotCoordinateY)
{
	for (int particle = 0; particle < PARTICLES_COUNT; particle++)
	{
		Particle newP(robotCoordinateX,robotCoordinateY);
		newP.particleId = particle + 1;
		particles.push_back(newP);
	}
}

//update all particles
void LocalizationManager::particlesUpdate(float deltaCoordinateX, float deltaCoordinateY, float deltaTetha,float laserScan[], int laserCount)
{
	particlesVector::iterator particlesBegin = particles.begin();
	particlesVector::iterator particlesEnd = particles.end();

	if (particlesBegin != particlesEnd)
	{
		for (; particlesBegin != particlesEnd; particlesBegin++)
		{
			particlesBegin->updateParticle(deltaCoordinateX,deltaCoordinateY, deltaTetha,laserScan,laserCount);

			if (particlesBegin->getParticleBelief() < THRESHOLD)
				particles.erase(particlesBegin);

			else if ((particlesBegin->getParticleBelief() > THRESHOLD) && (particles.size() < PARTICLES_COUNT))
			{
					Particle newParticle(particlesBegin->particleCoordinateX,particlesBegin->particleCoordinateY);

					newParticle.setParticleYaw(particlesBegin->particleCoordinateYaw);
					newParticle.setParticleMap(particlesBegin->getParticleMap());

					particles.push_back(newParticle);
			}
		}
	}
}

// print max particle (max belief)
Particle * LocalizationManager::getParticleWithMaxBelief()
{
	float maxBelief = 0;
	Particle* bestParticle = NULL;

	for (unsigned int i = 0; i < particles.size(); i++) {
		if (particles[i].particleBelief >= maxBelief) {
			maxBelief = particles[i].particleBelief;
			bestParticle = &particles[i];
		}
	}

	return bestParticle;
}
