#include "../includes/Functions.h"
#include "../includes/constants.h"
#include "../includes/Smalltalk.h"
#include <vector>

/**
 * create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
 * objects using pointers.
 *
 * \param mv	the vector
 * \param numBrit  number of british smalltalkers
 * \param numAmerican " AMerican "
 * \param numbAmericanDonutEnthusiest " American Donut Enthusiest "
 */
void getPeople(std::vector<Smalltalk*> &mv,int numBrit, int numAmerican, int numbAmericanDonutEnthusiest){

	//add a few classes
	for (int i=0;i<sizeof(Smalltalk);i++)
		mv.push_back(new Smalltalk(i));

	//talk
	for (int i=0;i<10;i++)
		mv[i]->saySomething();

	//time to go delete what the pointers point to and let the vector
	//manage the pointers themselvescause vector will not delete, gotta be a better way
	for (std::vector<Smalltalk*>:: iterator myiter = mv.begin(); myiter != mv.end(); ++myiter)
		delete (*myiter);

}

/**
 * Iterate over the vector full of Smalltalk pointers, If a Smalltalk pointer is not null then
 * delete what it points to.  Once all Smalltalk pointers deleted then use std::vector::clear()
 * to clear the vector of the pointers.
 *
 * \param mv
 */
void clearVector(std::vector<Smalltalk*> &mv){

}
