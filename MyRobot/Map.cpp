#include "Map.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//Default C'Tor
Map::Map()
{
	//Initialize the map (setting all cells to UNKNOWN (=2) value)
	for (int i=0; i<MAP_HEIGHT;i++)
	{
		for (int j=0; j<MAP_WIDTH;j++)
		{
			map[i][j] = UNKNOWN;
		}
	}
}

//A method which updates a map's cell by a given X,Y coordinates & a value (0,1,2)
void Map::updateMapCell(int xPosition,int yPosition,int cellValue)
{
	map[xPosition][yPosition] = cellValue;
}

//A method which returns a map's cell by a given X & Y coordinates
void Map::getMapCellByPosition(float xPosition,float yPosition,int &x,int &y)
{
	x = ((int)xPosition)/MAP_RESOLUTION + MAP_HEIGHT/2;
	y = ((int)yPosition)/MAP_RESOLUTION + MAP_WIDTH/2;
}

//A method which returns a map cell's value by a given X & Y coordinates
int Map::getMapCellValue(int xPosition,int yPosition)
{
	return map[xPosition][yPosition];
}

//A method which prints a particle's map
void Map::printParticleMap()
{
    for (int i=0; i<100; i++)
    {
    	for (int j=0; j<100; j++)
    		cout<<map[i][j];

    	cout<<endl;
    }
}
