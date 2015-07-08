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

		if (particles.size() != 0)
			prtParticleWithMaxBelief();
	}
}

// print max particle (max belief)
void LocalizationManager::prtParticleWithMaxBelief()
{
	unsigned int particleIdx;
	int particleId;
	Particle * particle;

	particle = new Particle(0,0);
	particle->particleBelief = 0;

	// % 5
	if (printParticlesInterval % 5 == 0)
	{
		for (particleIdx = 0; particleIdx<particles.size(); particleIdx++)
		{
			if (particles.at(particleIdx).particleBelief > particle->particleBelief)
			{
				*particle = particles.at(particleIdx);
				particleId = particleIdx;
			}
		}

		cout << endl;
		cout<<"> Particle #"<< particleId <<" is with the maximum belief probability: "<<endl;
		cout<<"---------------------------------------------------------------"<<endl;
		particle->printParticleMap();
	}

	printParticlesInterval++;
	delete particle;
}
