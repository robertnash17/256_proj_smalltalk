#include "../includes/Smalltalk.h"
#include "../includes/Functions.h"
#include "../includes/constants.h"

//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
Smalltalk::Smalltalk(std::string myNationality,int iPerson):nationality(myNationality), iPerson(iPerson)
{
	this->current_phrase = current_phrase;
}

Smalltalk::~Smalltalk(void){
}

//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
//with the last and then it starts over
//takes the form Nationality iPerson: phrase
//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
//AMERICAN 10:Why yes, I would like to supersize that
std::string Smalltalk::saySomething(){
}

//Abstract Base Class (ABC), implement in derived classes
void Smalltalk::populatePhrases(){

}
