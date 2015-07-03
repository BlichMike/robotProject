/*
 * Node.h
 *
 *  Created on: Jun 23, 2015
 *      Author: colman
 */

#ifndef NODE_H_
#define NODE_H_

class Node {

	// From Where the node came from
	Node *fromWhereGetNode;
	// current position
	float xPos;
	float yPos;
	// total distance already travelled to reach the node
	int level;
	// Total distance that need to step over to get to the end node
	int estimateDist;
	// priority=distance already travelled +remaining distance estimate
	int priority;  // smaller: higher priority
	bool checked;


public:
	Node(Node &lastNode,float CurrXPosition, float CurrYPosition,int Level);
	float getxPos() const {return xPos;}
	float getyPos() const {return yPos;}
	int getLevel() const {return level;}
	int getEstimate() const {return estimateDist;}
	int getPriority() const {return priority;}
	Node getLastNode() {return *fromWhereGetNode;}
	bool IsChecked() {return checked;}

	void updateChecked(bool check);
	void UpdateData(int horizontal, int vertical, const float & xDest, const float & yDest);
	void updatePriority(const float & xDest, const float & yDest);
	void nextLevel(int horizontal, int vertical);
	const int & estimate(const float & xDest, const float & yDest);
};

#endif /* NODE_H_ */
