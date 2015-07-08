#ifndef LOCALIZATIONMMANAGER_H_
#define LOCALIZATIONMMANAGER_H_

#include "Particle.h"
#include <libplayerc++/playerc++.h>
#include <vector>

#define PARTICLES_COUNT	200
#define THRESHOLD		0.6

typedef vector<Particle> particlesVector;

class LocalizationManager
{
	int printParticlesInterval;

	public:

		//A list (vector) that holds all the particles (200 particles)
		particlesVector particles;

		LocalizationManager(float robotCoordinateX,float robotCoordinateY);

		void particlesInit(float robotCoordinateX,float robotCoordinateY);

		void particlesUpdate(float deltaCoordinateX, float deltaCoordinateY, float deltaTetha,float laserScan[], int laserCount);

		void prtParticleWithMaxBelief();
};

#endif /* LOCALIZATIONMMANAGER_H_ */
