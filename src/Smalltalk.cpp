#include <string>
#include <vector>
#include <memory>
#include "../includes/Smalltalk.h"
#include "../includes/constants.h"



//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
Smalltalk::Smalltalk(std::string myNationality,int iPerson=1):iPerson(iPerson){
	this->current_phrase = current_phrase;
	iPerson++;
	this->nationality = myNationality;

	std::vector<Smalltalk*> ST;

	//add a few classes
	for (int i=0;i<10;i++)
		ST.push_back(new Smalltalk(i));

	//talk
	for (int i=0;i<10;i++)
		ST[i]->saySomething(i);

	//time to go delete what the pointers point to and let the vector
	//manage the pointers themselvescause vector will not delete, gotta be a better way
	for (std::vector<JustAClass*>:: iterator myiter = myClasses.begin(); myiter != myClasses.end(); ++myiter)
		delete (*myiter);

}

Smalltalk::~Smalltalk(void){
	iPerson--;
}

//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
//with the last and then it starts over
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
std::string Smalltalk::saySomething(){
	return 0;
}

//Abstract Base Class (ABC), implement in derived classes
void Smalltalk::populatePhrases(){

}

