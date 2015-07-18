#include "Map.h"
#include "ConfigurationManager.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include "lodepng.h"

std::vector<unsigned char> image; //the raw pixels
std::vector<unsigned char> newImage; //the raw pixels
unsigned width, height, resolution;

bool doIt = 1;

//Default C'Tor
Map::Map(){
	if(doIt == 1){
		doIt = 0;
		ConfigurationManager *configFile = ConfigurationManager::getInstance();
		string mapPath = configFile->getMap();
		resolution = configFile->getGridResolutionCM();
		loadImage(mapPath);

		newImage.resize(width * height * 4);
		unsigned int y,x,i,j;

		for (y = 0; y < newImage.size(); y++)
			newImage[y]=255;

		for (y = 0; y < height; y++)
			for (x = 0; x < width; x++) {
				if (!(image[y * width * 4 + x * 4 + 0]
							|| image[y * width * 4 + x * 4 + 1]
							|| image[y * width * 4 + x * 4 + 2])){
					for (i = y - configFile->getRobotSizeY()/10; i <= y + configFile->getRobotSizeY()/10; i++){
						for (j = x - configFile->getRobotSizeX()/10; j <= x + configFile->getRobotSizeX()/10; j++){
							if ((i>=0)&&(j>=0)&&(i<height)&&(j<width)){
									newImage[i * width * 4 + j * 4 + 0] = 0;
									newImage[i * width * 4 + j * 4 + 1] = 0;
									newImage[i * width * 4 + j * 4 + 2] = 0;
							}
						}
					}
				}
			}
		lodepng::encode("newFat.png", newImage, width, height);
	}
}

// Check if the position is in map
bool Map::isPositionInMap(float xPosition,float yPosition)
{
	bool isInMap = false;
	bool xposmin  = (int)xPosition > -(int)height;
	bool xposmax  = (int)xPosition < (int)height;
	bool yposmin  = (int)yPosition > -(int)width;
	bool yposmax  = (int)yPosition < (int)width;
	// Check for X position
	if (xposmin && xposmax && yposmin && yposmax)
	{
		isInMap = true;
	}
	// return result
	return isInMap;
}

//A method which returns a map's cell by a given X & Y coordinates
void Map::getMapCellByPosition(float xPosition,float yPosition,int &x,int &y){
	x = ((int)xPosition) ;
	y = ((int)yPosition) ;
}

//A method which returns a map cell's value by a given X & Y coordinates
int Map::getMapCellValue(int xPosition,int yPosition){
//	for(int i=0; i < width; i+=4)
//	{
//		for (int j=0; j< height ;j+=4)
//		{
//			if((newImage[i * width * 4 + j * 4 + 0] == 0)&&
//						(newImage[i * width * 4 + j * 4 + 1] == 0)&&
//						(newImage[i * width * 4 + j * 4 + 2] == 0))
//				cout<< FREE;
//			else
//				cout<< OBSTACLE;
//		}
//		cout << "\n";
//	}
	if((newImage[yPosition * width * 4 + xPosition * 4 + 0] == 255)&&
			(newImage[yPosition * width * 4 + xPosition * 4 + 1] == 255)&&
			(newImage[yPosition * width * 4 + xPosition * 4 + 2] == 255))
		return FREE;
	return OBSTACLE;
}

//This method load the pic to map[][]
void Map::loadImage(string filename){
	//decode
	unsigned error = lodepng::decode(image, width, height, filename);
	//if there's an error, display it
	if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

//return height
int Map::getHeight(){return height;}

//return width
int Map::getWidth(){return width;}
