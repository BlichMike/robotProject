#include "Astar.h"
#include <vector>
#include <queue>
#include <ctime>
#include "Map.h"
using namespace std;

queue<Node> PathPlanner(Node startPoint,Node endPoint,Map map,vector<Node> AllFoundNodes)
{
	//-1-1|-1,0|-1,1
	// 0-1| 0 0| 0,1
	// 1-1| 1 0| 1,1
	//                ^
	// Vertical   =   |

	// Horizontal=   -->
	int Obstical = 1;
	bool FoundTheDestiny = false;

	// While not found the destiny
	while(!FoundTheDestiny)
	{
		int minPriority = 0;
		int minPriorityIndexFound = -1;
		// Find the lowest priority node that haven't checked
		for (int index=0; index < (int)AllFoundNodes.size(); index++)
		{
			if (AllFoundNodes[index].IsChecked())
			{
				if (AllFoundNodes[index].getPriority() <= minPriority)
				{
					minPriority =AllFoundNodes[index].getPriority();
					minPriorityIndexFound = index;
				}
			}
		}

		Node currentNode = AllFoundNodes[minPriorityIndexFound];

		// Run for all Horizontal
		for (int vertical=-1; vertical<=1; vertical++)
		{
			// Run for all vertical
			for (int horizontal=-1; horizontal <=1; horizontal++)
			{
				// Check if not current position
				if (!(horizontal ==0 && vertical ==0))
				{
					// Check the x position in the map
					if (currentNode.getxPos() + horizontal > 0 && currentNode.getxPos() + horizontal < map.getWidth())
					{
						// Check the y position in the map
						if (currentNode.getyPos() + vertical < 0 && currentNode.getyPos() + vertical < map.getHeight())
						{
							// Check if there is not obsticale
							if (!((map.getMapCellValue(currentNode.getxPos()+ horizontal, currentNode.getyPos()+vertical))==Obstical))
							{
								// Set boolean if cell was found
								bool cellfound = false;

								// Check this cell in the vector
								for (int index=0; index < (int)AllFoundNodes.size(); index++)
								{
									// Check if cell was found
									if (AllFoundNodes[index].getxPos() == currentNode.getxPos() + horizontal &&
										AllFoundNodes[index].getyPos() == currentNode.getyPos() + vertical)
									{
										// Set found
										cellfound = true;
										// Set the new found node
										Node newNode = Node(currentNode,
														    currentNode.getxPos() + horizontal,
															currentNode.getyPos() + vertical,
															currentNode.getLevel());

										newNode.UpdateData(horizontal,vertical,endPoint.getxPos(),endPoint.getyPos());
										// Check if the found Node priority is better than the old one
										if (AllFoundNodes[index].getPriority() < newNode.getPriority())
										{
											AllFoundNodes[index] = newNode;
										}

										break;
									}
								}
								// Check if cell was not found
								if (!cellfound)
								{
									Node newNode = Node(currentNode,
														currentNode.getxPos() + horizontal,
										   				currentNode.getyPos() + vertical,
										     			currentNode.getLevel());
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
