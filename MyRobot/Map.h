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

#define FREE 			0
#define OBSTACLE 		1

using namespace std;

class Map
{
	int map;

	public:
		Map();

		void getMapCellByPosition(float xPosition,float yPosition,int &x,int &y);

		int getMapCellValue(int xPosition,int yPosition);

		void printParticleMap();

		void loadImage(const char* filename);
};

#endif /* MAP_H_ */
