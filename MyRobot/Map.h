/*****************************************************************************/
/*                            C l a s s  :  M a p                            */
/*                            -------------------                            */
/* Description: A class which handles the all map functionality              */
/*****************************************************************************/

#ifndef MAP_H_
#define MAP_H_
#include <string>
#include "Node.h"

#define FREE 			0
#define OBSTACLE 		1

using namespace std;

class Map
{
	private :
		void loadImage(string filename);

		void saveImage(string filename,Node notesarr[]);

	public:
		Map();

		void getMapCellByPosition(float xPosition,float yPosition,int &x,int &y);

		int getMapCellValue(int xPosition,int yPosition);

		int getHeight();

		int getWidth();

		void printParticleMap();

		void saveMapWithPathToPic(Node notesarr[]);


};

#endif /* MAP_H_ */
