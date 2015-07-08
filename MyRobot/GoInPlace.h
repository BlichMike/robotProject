//*************************************************************************************/
/*                                                                                    */
/*                          C l a s s  : G o I n P l a c e                            */
/*                          ------------------------------                            */
/*                                                                                    */
/**************************************************************************************/
#ifndef GOINPLACE_H_
#define GOINPLACE_H_

#include "Robot.h"
#include "Behaviors.h"

using namespace std;

class GoInPlace: public Behaviors
{
	public:

		GoInPlace(Robot* robot);

		bool startCondition();

		bool stopCondition();

		void action();
};

#endif /* GOINPLACE_H_ */
