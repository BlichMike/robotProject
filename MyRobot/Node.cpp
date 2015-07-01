#include "Node.h"
#include <math.h>

Node::Node(Node lastNode,int CurrXPosition, int CurrYPosition,int Level)
{
	Node fromWhereGetNode = lastNode;
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
void Node::UpdateData(int horizontal, int vertical, const int & xDest, const int & yDest)
{
	nextLevel(horizontal,vertical);
	updatePriority(xDest,yDest);
}
void Node::updatePriority(const int & xDest, const int & yDest)
{
	priority=level + estimate(xDest, yDest)*10; //A*
}

// give better priority to going strait instead of diagonally
void Node::nextLevel(int horizontal, int vertical) // i: direction
{
	level+=(((horizontal + vertical)%2)==0)?10:14;
}

// Estimation function for the remaining distance to the goal.
const int & Node::estimate(const int & xDest, const int & yDest)
{
	static int xd, yd, d;
	xd=xDest-xPos;
    yd=yDest-yPos;

    // Euclidian Distance
    d=static_cast<int>(sqrt(xd*xd+yd*yd));
    estimateDist= d;
    return(d);
}
