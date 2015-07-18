#include "Node.h"
#include <math.h>
#include <cmath>
Node::Node(Node &lastNode,int CurrXPosition, int CurrYPosition,int Level)
{
	Node *fromWhereGetNode = &lastNode;
	xPos=CurrXPosition;
	yPos=CurrYPosition;
	level=Level; // level
	estimateDist=0; // Distance from the end
	priority=0; // sum of the level and the estimate
	checked=false; // Check if the node was checked
}
void Node::updateChecked(bool check)
{
	checked = check;
}
void Node::UpdateData(int horizontal, int vertical,int xDest,int yDest)
{
	nextLevel(horizontal,vertical);
	updatePriority(xDest,yDest);
}
void Node::updatePriority(int xDest,int yDest)
{
	priority=level + estimate(xDest, yDest); //A*
}

// give better priority to going strait instead of diagonally
void Node::nextLevel(int horizontal, int vertical) // i: direction
{
	level+=(((horizontal + vertical)%2)==0)?10:14;
}

// Estimation function for the remaining distance to the goal.
int Node::estimate(int xDest, int yDest)
{
	int xDistance, yDistance, totalDistance;
	xDistance=std::abs(xDest - xPos);
    yDistance=std::abs(yDest - yPos);

    // Euclidian Distance
    totalDistance=(int)(sqrt(xDistance*xDistance+yDistance*yDistance));
    estimateDist= totalDistance;
    return(totalDistance);
}
