//**********************************************************************************/
/*                                                                                 */
/*                            C l a s s  : G o R i g h t                           */
/*                            --------------------------                           */
/***********************************************************************************/
#ifndef GORIGHT_H_
#define GORIGHT_H_

#include "Robot.h"
#include "Behaviors.h"
using namespace std;

class GoRight: public Behaviors
{
	public:
		GoRight(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};

#endif /* GORIGHT_H_ */
