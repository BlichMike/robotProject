/******************************************************************************************/
/*                                                                                        */
/*                             C l a s s  :  P a r t i c l e                              */
/*                             -----------------------------                              */
/*                                                                                        */
/* Description: A class which handles the particle's definition                           */
/*              (particle's belief, position, etc...)                                     */
/*                                                                                        */
/******************************************************************************************/
/*                                                                                        */
/* Methods: particleInit        - A method which initializes the particle's coordinates   */
/*                                                                                        */
/*          updateParticle      - A method which updates a particle's belief, position    */
/*                                and map                                                 */
/*                                                                                        */
/*          particleProbCalc    - A method which calculates the particle's probability    */
/*                                using the delta coordinates (X, Y & Yaw)                */
/*                                                                                        */
/*          calcPrecisionByMap  - A method which calculates the precision factor          */
/*                                (%TP / %TP + %FP) using the particle's map & laser scan */
/*                                                                                        */
/*          setParticleMap      - A method which set's a newly created particle's map     */
/*                                from a current particle's map (father -> child)         */
/*                                                                                        */
/*          setParticleYaw      - A method which set's the particle's Yaw coordinate      */
/*                                                                                        */
/*          getParticleMap      - A method which get's the particle's map                 */
/*                                                                                        */
/*          getParticleBelief   - A method which get's the particle's calculated belief   */
/*                                                                                        */
/*          convLaserIdxToAngle - A method which converts a laser index id to an angle    */
/*                                                                                        */
/*          printParticleMap    - A method which print's the particle's map               */
/*                                                                                        */
/******************************************************************************************/
#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "Map.h"

#define MAX_DEGREE 						360
#define LASER_ANGLE_RANGE 				240
#define MAX_ACCURATE_ANGLE_TO_MOVE 		1.0
#define NORMAL_ACCURATE_ANGLE_TO_MOVE	0.5
#define SAFE_DISTANCE_TO_MOVE 			0.3
#define OPEN_PATH_RANGE 				0.75
#define SENSOR_FROM_END 				15
#define SENSOR_DETECTION_RANGE 			60
#define INDEX_PER_DEGREE 				6
#define CELL_DIMENSION 					5
#define ROBOT_DIMENSION 				2
#define DEGREES_TO_RADIANS(degree)      ((degree) * M_PI / 180)
#define METER_TO_CM(meter)   		    (meter * 100)

using namespace std;

class Particle
{
	public:
		int particleId;
		double particleCoordinateX;
		double particleCoordinateY;
		double particleCoordinateYaw;
		double particleBelief;
		Map particleMap;

		Particle(float robotCoordinateX,float robotCoordinateY);

		void particleInit(float robotCoordinateX,float robotCoordinateY);

		void updateParticle(float deltaCoordinateX, float deltaCoordinateY, float deltaCoordinateYaw, float laserScan[], int laserCount);

		float particleProbCalc(float deltaCoordinateX, float deltaCoordinateY, float deltaCoordinateYaw);

		float calcPrecisionByMap(float laserScan[], int laserCount);

		void setParticleMap(Map particleMapCopy);

		void setParticleYaw(float yawCoordinate);

		Map getParticleMap();

		double getParticleBelief();

		float convLaserIdxToAngle(int index, int xCoordinate, int radius);

		void printParticleMap();
};

#endif /* PARTICLE_H_ */
