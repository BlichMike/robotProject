/*************************************************************************************/
/*                                                                                   */
/*                     C l a s s  :  S l a m A l g o r i t h m                       */
/*                     ----------------------------------------                      */
/*                                                                                   */
/* Description: A class which handles the particle's update (control's the slam -    */
/*              system algorithm)                                                    */
/*                                                                                   */
/*************************************************************************************/
/*                                                                                   */
/* Methods: particlesInit            - A method which initializes & add a new        */
/*                                     particle to the particle's vector (list)      */
/*                                                                                   */
/*          particlesUpdate          - A method which updates all the particles that */
/*                                     are stored in the particl'es vector (list)    */
/*                                                                                   */
/*          prtParticleWithMaxBelief - A method which print's the particle that has  */
/*                                     the maximum belief (of all of the particles)  */
/*                                                                                   */
/*************************************************************************************/
#ifndef SLAMALGORITHM_H_
#define SLAMALGORITHM_H_

#include "Particle.h"
#include <libplayerc++/playerc++.h>
#include <vector>

#define PARTICLES_COUNT	200
#define THRESHOLD		0.6

typedef vector<Particle> particlesVector;

class SlamAlgorithm
{
	int printParticlesInterval;

	public:

		//A list (vector) that holds all the particles (200 particles)
		particlesVector particles;

		SlamAlgorithm(float robotCoordinateX,float robotCoordinateY);

		void particlesInit(float robotCoordinateX,float robotCoordinateY);

		void particlesUpdate(float deltaCoordinateX, float deltaCoordinateY, float deltaTetha,float laserScan[], int laserCount);

		void prtParticleWithMaxBelief();
};

#endif /* SLAMALGORITHM_H_ */
