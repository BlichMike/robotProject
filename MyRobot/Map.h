/*****************************************************************************/
/*                                                                           */
/*                            C l a s s  :  M a p                            */
/*                            -------------------                            */
/*                                                                           */
/* Description: A class which handles the particle's map that is being       */
/*              built online (in real-time)                                  */
/*                                                                           */
/*****************************************************************************/
/*                                                                           */
/* Methods: updateMapCell        - A method which updates a map's cell by    */
/*                                 a given X,Y coordinates & a value (0,1,2) */
/*                                                                           */
/*          getMapCellByPosition - A method which returns a map's cell by    */
/*                                 a given X & Y coordinates                 */
/*                                                                           */
/*          getMapCellValue      - A method which returns a map cell's value */
/*                                 by a given X & Y coordinates              */
/*                                                                           */
/*          printParticleMap     - A method which prints a particle's map    */
/*                                                                           */
/*****************************************************************************/
#ifndef MAP_H_
#define MAP_H_

#define MAP_HEIGHT	    100
#define MAP_WIDTH	    100
#define MAP_RESOLUTION	5

#define FREE 			0
#define OBSTACLE 		1
#define UNKNOWN 		2

using namespace std;

class Map
{
	int map[MAP_HEIGHT][MAP_WIDTH];

	public:
		Map();

		void updateMapCell(int xPosition,int yPosition,int cellValue);

		void getMapCellByPosition(float xPosition,float yPosition,int &x,int &y);

		int getMapCellValue(int xPosition,int yPosition);

		void printParticleMap();
};

#endif /* MAP_H_ */
