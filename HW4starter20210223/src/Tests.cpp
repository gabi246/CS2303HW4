/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese and Marie Tessier and Casey Snow
 */

#include "Tests.h"
#include <stdbool.h>
#include <cstdlib>
using namespace std;

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4  && ok6;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
	Room* theRoomPs[10];//addresses for 10 rooms

	Production* pP = new Production();

	ok = pP->readFile("houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
	if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of rooms");
		}

	}
	puts("The adjacency matrix");
	for(int i = 0; i<answer; i++)
	{
		for(int j = 0; j<answer; j++)
		{
			printf("%d",adjMP->getEdge(i, j));

		}
		printf("\n");
	}
	puts("The treasure values");
	for(int i = 0; i<answer; i++)
	{
		printf("%f\n", theRoomPs[i]->treasure);
	}


	return ok;
}
bool Tests::testEnqueue()
{
	bool ok = true;
	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ok = true;
	return ok;
}

bool Tests::testMakeLList()
{
	bool ok = true;

	 puts("starting testMakeLList");fflush(stdout);
	 //what are the criteria for success for make LList?
	 //should be able to make one, add data to it, get the data back
	 //test case 1:

	 LList* theListP = new LList();

	 //LLNode* theListP = makeEmptyLinkedList();

	 bool rightAnswer = true;
	 bool answer = theListP->isEmpty();
	 if(answer!=rightAnswer)
	 {
	 	 ok = false;
	 	 puts("test make LList did not pass.");
	 }


	 //test case 2:
	 ///LList* theListP2 = new LList();
	 //LLNode* theListP2 = makeEmptyLinkedList();
	 Room* theRoomPs[10];
	 SearchResults* srP = (SearchResults*) malloc(sizeof(SearchResults));
	 srP->roomNumber= 0;
	 Room* roomBeingSearchedP = theRoomPs[0];
	 roomBeingSearchedP->searched = true;
	 srP->treasure = roomBeingSearchedP->treasure;

	 theListP->savePayload2(srP);
	 //savePayload(theListP2,srP);
	 bool rightAnswer2 = false;
	 bool answer2 = theListP->isEmpty2();
	 if(answer2!=rightAnswer2)
	 {
	 	 ok = false;
	 	 puts("test savePayload did not pass.");
	 }


	 else
	 {
	 	 puts("tests make LList did pass.");
	 }

	return ok;
}
bool Tests::testPrintHistory()
{
	bool ok = true;
	return ok;
}



