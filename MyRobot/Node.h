/*
 * Node.h
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

class Node {

	// current position
	int xPos;
	int yPos;
	// total distance already travelled to reach the node
	int level;
	// priority=level+remaining distance estimate
	int priority;  // smaller: higher priority

public:
	Node(int xp, int yp, int d, int p);
	int getxPos();
	int getyPos();
	int getLevel();
	int getPriority();
	void updatePriority(const int & xDest, const int & yDest);
	void nextLevel(const int & i);
	const int & estimate(const int & xDest, const int & yDest);
};

#endif /* NODE_H_ */
