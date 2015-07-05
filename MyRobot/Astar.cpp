#include "Astar.h"
#include <vector>
#include <queue>
#include <ctime>
#include "Map.h"
#include "ConfigurationManager.h"
using namespace std;

queue<Node> Astar::PathPlanner(Node startPoint,Node endPoint)
{
	//-1-1|-1,0|-1,1
	// 0-1| 0 0| 0,1
	// 1-1| 1 0| 1,1
	//                ^
	// Vertical   =   |

	// Horizontal=   -->

	// Define the the first node
	vector<Node> AllFoundNodes;
	AllFoundNodes.push_back(startPoint);

	// Set the obstical to 1
	int Obstical = 1;

	// Check if the robot get the destiny
	bool FoundTheDestiny = false;

	// While not found the destiny
	while(!FoundTheDestiny)
	{
		int minPriority = 0;
		int minPriorityIndexFound = -1;
		// Find the lowest priority node that haven't checked
		for (int index=0; index < (int)AllFoundNodes.size(); index++)
		{
			if (!AllFoundNodes[index].IsChecked())
			{
				if (AllFoundNodes[index].getPriority() <= minPriority)
				{
					minPriority =AllFoundNodes[index].getPriority();
					minPriorityIndexFound = index;
				}
			}
		}

		Node currentNode = AllFoundNodes[minPriorityIndexFound];
		AllFoundNodes[minPriorityIndexFound].updateChecked(true);
		// For debug
		int size = (int)AllFoundNodes.size();

		// Run for all Horizontal
		for (int vertical=-1; vertical<=1; vertical++)
		{
			// Run for all vertical
			for (int horizontal=-1; horizontal <=1; horizontal++)
			{
				// Check if not current position
				if (!(horizontal ==0 && vertical ==0))
				{

					float x = currentNode.getxPos();
					float y = currentNode.getyPos();
					float rzx = ConfigurationManager().getRobotSizeX();
					float rzy = ConfigurationManager().getRobotSizeY();
					float  h = horizontal * ConfigurationManager().getRobotSizeX();

					float v = vertical * ConfigurationManager().getRobotSizeY();

					// Check the position in the map
					if (Map().isPositionInMap(currentNode.getxPos() + horizontal* ConfigurationManager().getRobotSizeX(),currentNode.getyPos() + vertical* ConfigurationManager().getRobotSizeY()))
					{
						int xpos;
						int ypos;

						// Get the current position on the map
						Map().getMapCellByPosition(currentNode.getxPos()+ horizontal, currentNode.getyPos()+vertical,xpos,ypos);
						// Check if there is not obsticale
						if (!((Map().getMapCellValue(xpos, ypos)==Obstical)))
						{
							// Set boolean if cell was found
							bool cellfound = false;
							// Check this cell in the vector (if it already exists)
							for (int index=0; index < (int)AllFoundNodes.size(); index++)
							{
								// Check if cell was found
								if (AllFoundNodes[index].getxPos() == currentNode.getxPos() + horizontal * ConfigurationManager().getRobotSizeX() &&
									AllFoundNodes[index].getyPos() == currentNode.getyPos() + vertical * ConfigurationManager().getRobotSizeY())
								{
									// Set found
									cellfound = true;
									// Set the new found node
									Node newNode = Node(currentNode,
													    currentNode.getxPos() + horizontal * ConfigurationManager().getRobotSizeX(),
														currentNode.getyPos() + vertical * ConfigurationManager().getRobotSizeY(),
														currentNode.getLevel());
									newNode.UpdateData(newNode.getxPos(),newNode.getyPos(),endPoint.getxPos(),endPoint.getyPos());
									// Check if the found Node priority is better than the old one
									if (AllFoundNodes[index].getPriority() > newNode.getPriority())
									{
										AllFoundNodes[index] = newNode;
										break;
									}
								}
							}
							// Check if cell was not found
							if (!cellfound)
							{
								Node newNode = Node(currentNode,
													currentNode.getxPos() + horizontal * ConfigurationManager().getRobotSizeX(),
													currentNode.getyPos() + vertical * ConfigurationManager().getRobotSizeY(),
									     			currentNode.getLevel());
								newNode.UpdateData(newNode.getxPos(),newNode.getyPos(),endPoint.getxPos(),endPoint.getyPos());
									// Add new Node
								AllFoundNodes.push_back(newNode);
								// Check if the cell is the destiny
								if (newNode.getxPos() == endPoint.getxPos() &&
									newNode.getyPos() == endPoint.getyPos())
								{
									FoundTheDestiny = true;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
	// After Ended Create the path
	int indexFinal =-1;

	// Search in loop where is the nodes and make of them queue
	for (int index=0; index < (int)AllFoundNodes.size(); index++)
	{
		// Get the index of final node
		// if the distancnce is 0, than you found the last one
		if(AllFoundNodes[index].getEstimate() == 0)
		{
			indexFinal = index;
		}
	}


	// Set the queue of the path
	queue<Node> finalPath;
	bool start = false;
	// Set the last node
	Node current = AllFoundNodes[indexFinal];
	finalPath.push(current);
	// While i dont get the start position
	while(!start)
	{
		// Add to the queue
		finalPath.push(current.getLastNode());
		// Check if i get the fist node
		if (current.getLastNode().getxPos() == startPoint.getxPos() && current.getLastNode().getyPos() == startPoint.getyPos())
		{
			start = true;
		}
	}
	return finalPath;
}
