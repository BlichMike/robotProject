#include "Map.h"
#include "ConfigurationManager.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "lodepng.h"

std::vector<unsigned char> image; //the raw pixels
unsigned width, height, resolution;
int** map;

//Default C'Tor
Map::Map()
{
	ConfigurationManager *configFile = ConfigurationManager::getInstance();

	string mapPath = configFile->getMap();
	resolution = configFile->getMapResolutionCM();


	//TODO MICHAEL NEED TO FIX
	mapPath = "hospital_section2.png";
	//decode
	loadImage(mapPath);

	//define our map by the height and width
	map = new int*[height];
	for(int i = 0; i < height; ++i)
		map[i] = new int[width];

	int count = 0;
	//Initialize the map (setting all cells to UNKNOWN (=2) value)
	for (int i=0; i<height;i++)
	{
		for (int j=0; j<width;j++)
		{
			// Check if the pixel is all white
			if((image[count]==255)&&(image[count+1]==255)&&(image[count+2]==255)&&(image[count+3]==255)){
				map[i][j] = FREE;
			// If not all white then OBSTACLE
			} else {
				map[i][j] = OBSTACLE;
			}
			// + 4 because we work with RBGA for each pixel
			count = count + 4;
		}
	}
}

//A method which returns a map's cell by a given X & Y coordinates
void Map::getMapCellByPosition(float xPosition,float yPosition,int &x,int &y)
{
	x = ((int)xPosition)/resolution + height/2;
	y = ((int)yPosition)/resolution + width/2;
}

//A method which returns a map cell's value by a given X & Y coordinates
int Map::getMapCellValue(int xPosition,int yPosition)
{
	return map[xPosition][yPosition];
}

//This method load the pic to map[][]
void Map::loadImage(string filename)
{
  //decode
  unsigned error = lodepng::decode(image, width, height, filename);

  //if there's an error, display it
  if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

//return height
int Map::getHeight()
{
	return height;
}

//return width
int Map::getWidth()
{
	return width;
}

//A method which prints a particle's map
void Map::printParticleMap()
{
    for (int i=0; i<height; i++)
    {
    	for (int j=0; j<width; j++)
    		cout<<map[i][j];

    	cout<<endl;
    }
}
