/*****************************************************************************/
/*                                                                           */
/*                            C l a s s  :  M a p                            */
/*                            -------------------                            */
/*                                                                           */
/* Description: A class which handles the all map functionality              */
/*                                                                           */
/*****************************************************************************/

#ifndef MAP_H_
#define MAP_H_
#include <string>

#define FREE 			0
#define OBSTACLE 		1

using namespace std;

class Map
{
	public:
		Map();

		void getMapCellByPosition(float xPosition,float yPosition,int &x,int &y);

		int getMapCellValue(int xPosition,int yPosition);

		int getHeight();

		int getWidth();

		void printParticleMap();

		void loadImage(string filename);
};

#endif /* MAP_H_ */
