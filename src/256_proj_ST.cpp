// smalltalk_VirtualAbstractVector.cpp : Defines the entry point for the console application.

#include <iostream>
#include <stdlib.h>
#include <memory>
#include <vector>
#include <time.h>
//for delays
#include <chrono>
#include <thread>


#include "../includes/Smalltalk_American.h"
#include "../includes/ST_American_DonutEnthusiest.h"
#include "../includes/Smalltalk_Brit.h"
#include "../includes/constants.h"
#include "../includes/Functions.h"

using namespace std;

//tracks how many points you will get
//yeah, yeah its a global
int total_points =10;		//10 points to start

//this is a template class, its mostly here as a helper for me
//the T and U are generic params, I can substitute any type for them
//they must be comparable with ==, templates are extremely hard to get right BTW
template<typename T, typename U>
bool EXPECT_EQ(T expectedVal, U actualVal,string testnumb = "", int pts=1){
	bool bout = (expectedVal == actualVal);
	try{
		if (bout){
			total_points+=pts;
			cout<<"SUCCESS "+testnumb<<" points:"<<total_points;
		}
		else
			cout<<"FAIL "+ testnumb;
		cout<<endl;
	}catch(...)
	{
		std::cout<<"THREW EXCEPTION IN EXPECT_EQ"<<std::endl;
	}
	return bout;
}

bool EXPECT_CONTAINS(string expectedVal, string actualVal,string testnumb = "", int pts=1, bool bVerbose = false){
	bool bout =(actualVal.find(expectedVal) != string::npos );
	if (bout){
		total_points+=pts;
		cout<<"SUCCESS "+testnumb<<" points:"<<total_points;
	}
	else
		cout<<"FAIL "+ testnumb;
	if(!bout && bVerbose)
		cout<<" Expected contains:"<<expectedVal<<" received:"<<actualVal;
	cout<<endl;
	return bout;
}

void testRandomRun(int numEachGroup, bool saySomething=true) {
	std::vector<Smalltalk*> mv;

	//allocate a bunch of smalltalkers and push on vector
	getPeople(mv, numEachGroup,	numEachGroup, numEachGroup);
	for (int j = 0; j < mv.size(); j++) {
		int i = rand() % mv.size();
		if (saySomething)
			std::cout<< mv[i]->saySomething()<<endl;

		//snooze for a bit, get at least 1 ms and yield the time slice to boot
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

	clearVector(mv);
	clearVector(mv);	//if this line causes failure then check your implementation of clearVector
}

void testDeterministicRun(int numEachGroup, bool saySomething=true) {
	std::vector<Smalltalk*> mv;

	//allocate a bunch of smalltalkers and push on vector
	getPeople(mv, numEachGroup,	numEachGroup, numEachGroup);

	for (int j = 0; j < mv.size(); j++) {
		if (saySomething)
			std::cout<< mv[j]->saySomething()<<endl;

		//snooze for a bit, get at least 1 ms and yield the time slice to boot
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

	clearVector(mv);
}

void test_getPeople(int numEachGroup) {
	cout <<endl<< "test_getPeople" << " numEachGroup=" <<numEachGroup<<endl;

	//create vector of people
	std::vector<Smalltalk*> mv;

	//allocate a bunch of smalltalkers and push on vector
	getPeople(mv, numEachGroup,	numEachGroup, numEachGroup);

	int mv_size = mv.size();

	//right number of people
	EXPECT_EQ(numEachGroup*3, mv_size,"1  -right number of people",20);

	//right mix of people?

	//time to go delete what the pointers point to and let the vector
	//manage the pointers themselvescause vector will not delete, gotta be a better way
	clearVector(mv);
}

enum nationality{ST_A,ST_A_DE,ST_B};
void testPhrasing(nationality mn, Smalltalk *ptalk) {
	if (!ptalk)
		return;

	switch(mn){
	case ST_A:
		try{
			cout <<endl<< "test saySomething for American" <<endl;
			EXPECT_CONTAINS(AMERICAN_PHRASE_1, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_2, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_3, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_4, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_5, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_1, ptalk->saySomething(),"4 - phrasing",2,true);
		}
		catch(...){
				cout<<"Threw exception in testPhrasing:ST_A"<<endl;
		}
		break;
	case ST_A_DE:
		try{
			cout <<endl<< "test saySomething for American Donut Enthusiest" <<endl;
			EXPECT_CONTAINS(AMERICAN_PHRASE_1, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_2, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_3, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_4, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_5, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_DE_PHRASE_1, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_DE_PHRASE_2, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_DE_PHRASE_3, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_DE_PHRASE_4, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_DE_PHRASE_5, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(AMERICAN_PHRASE_1, ptalk->saySomething(),"4 - phrasing",2,true);
		}
			catch(...){
				cout<<"Threw exception in testPhrasing:ST_A_DE"<<endl;
			}
		break;

	case ST_B:
		try{
			cout <<endl<< "test saySomething for Brit" <<endl;
			EXPECT_CONTAINS(BRIT_1, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_2, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_3, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_4, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_5, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_6, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_7, ptalk->saySomething(),"4 - phrasing",2,true);
			EXPECT_CONTAINS(BRIT_1, ptalk->saySomething(),"4 - phrasing",2,true);
		}
		catch(...){
				cout<<"Threw exception in testPhrasing:ST_B"<<endl;
		}
		break;
	}
}

//enum nationality{ST_A,ST_A_DE,ST_B};
int main() {
	//test getPeople
	test_getPeople(0);	//test with 0
	test_getPeople(4);	//test with 3*4 =12 people

	//test order of phrasing
	Smalltalk_American sta;
	testPhrasing(ST_A,&sta);	//run through utterances, make sure they
								//iterate in the right order and correctly
								//restart at beginning once all phrases uttered

	ST_American_DonutEnthusiest stade;
	testPhrasing(ST_A_DE,&stade);	//same as above but will go through both
									//ST_A then ST_DE utterances
									//before it restarts at beginning
	Smalltalk_Brit stb;
	testPhrasing(ST_B,&stb);

	return 0;
}
