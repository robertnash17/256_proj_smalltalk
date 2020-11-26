#pragma once
#include <string>
#include <vector>
#include <memory>

class Smalltalk
{
public:
	//derived class will set Nationality, iPerson. iPerson is just a counter used to distinguish between objects of the same type
	Smalltalk(std::string myNationality,int iPerson=1);
	
	virtual ~Smalltalk(void);
	
	//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending 
	//with the last and then it starts over
	//takes the form Nationality iPerson: phrase
	//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2 
	//AMERICAN 10:Why yes, I would like to supersize that
	std::string saySomething();

	//Abstract Base Class (ABC), implement in derived classes
	virtual void populatePhrases()=0;
protected:
	const std::string			nationality;	//populated by derived classes using initilizer list from constants.h
	std::vector<std::string>	mySmallTalk;	//populated by populatePhrases in derived classes
	int							iPerson;		//what number this person is (just a way to track objects)
	int 						current_phrase;	//which phrase was last returned (use % operator to cycle through phrases)
};

