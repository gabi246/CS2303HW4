/*
 * LList.cpp
 *
 *  Created on: Feb 26, 2021
 *      Author: Marie Tessier and Casey Snow
 */

#include "LList.h"
#include <cstdlib>
using namespace std;

LList::LList() {
	// TODO Auto-generated constructor stub
	search=makeEmptyLinkedList();
	history=makeEmptyLinkedList2();

	const char* pc = "Hello";

}

LList::~LList() {
	// TODO Auto-generated destructor stub
}

bool LList::isEmpty()
{
	bool ans = false;
	if(search->payP == (Payload*)0)
	{
		ans = true;
	}
	return ans;
}
bool LList::isEmpty2()
{
	bool ans = false;
	if(history->payP == (Payload2*)0)
	{
		ans = true;
	}
	return ans;
}

LLNode* LList::makeEmptyLinkedList()
{
	LLNode* search = (LLNode*) malloc(sizeof(LLNode));
	search->next = (struct LLNode*)0;
	search->prev = (struct LLNode*)0;
	search->payP = (Payload*)0;

	return search;
}
LLNode2* LList::makeEmptyLinkedList2()
{
	LLNode2* search = (LLNode2*) malloc(sizeof(LLNode2));
	search->next = (struct LLNode2*)0;
	search->prev = (struct LLNode2*)0;
	search->payP = (Payload2*)0;

	return search;
}
void LList::savePayload(Payload* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty())
	{
		search->payP = mp;
	}
	else
	{
		LLNode* temp = search;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode* newList = makeEmptyLinkedList();
		newList->payP = mp;
		temp->next = (struct LLNode*)newList;
		newList->prev = (struct LLNode*) temp;
	}
}
void LList::savePayload2(Payload2* mp)
{
	//if the list is empty, then make payP be mp
	//else traverse the list,
	//make a new list element
	//put mp in that
	//attach the new list element to the existing list
	if(isEmpty2())
	{
		history->payP = mp;
	}
	else
	{
		LLNode2* temp = history;
		while(temp->next)
		{
			temp=(LLNode2*)temp->next;
		}
		//now temp points to the last element

		//make a new element, attach mp to it, wire up the new element
		LLNode2* newList = makeEmptyLinkedList2();
		newList->payP = mp;
		temp->next = (struct LLNode2*) newList;
		newList->prev = (struct LLNode2*) temp;
	}
}

Payload* LList::dequeueLIFO()
{
	Payload* payP = (Payload*)0;
	if(isEmpty())
	{
		puts("Trying to dequeue from empty.");
	}
	else
	{

		LLNode* temp = search;
		while(temp->next)
		{
			temp=(LLNode*)temp->next;
		}
		//now temp points to the last element


		payP = temp->payP;
		temp->payP = (Payload*)0;

		//remove the last, now empty, element
		if(temp->prev)
		{
			temp=(LLNode*)temp->prev;
			//free(temp->next);

			temp->next = (struct LLNode*)0;
		}
		else
		{
			puts("Queue is now empty");
		}
		puts("returning from dequeue");fflush(stdout);
	}

	return payP;
}

backFromDQFIFO* LList::dequeueFIFO()
{
	backFromDQFIFO* fp = (backFromDQFIFO*) malloc(sizeof(backFromDQFIFO));
	if(search->next == (struct LLNode*)0)
	{
		//list of length 1 or 0
		fp->newQHead= search;
	}
	else
	{
		fp->newQHead= (LLNode*) search->next;
	}
	fp->mp= search->payP;//all return values are set
	if(search->next != (struct LLNode*)0)
	{
		//length list is >1
		free(search);
	}

	return fp;
}
void LList::printHistory()
{
    puts("Printing history");
    if(search->payP ==(Payload*)0)
    {
         puts("Empty list");
    }
    else
    {
	    //traverse the list, printing as we go
    	float treasureSubtotal = 0.0;
        int room = -1;
        LLNode* temp = search;
        while(temp->next)
        {
            //room =temp->payP->getNProps();
        	room =temp->payP->roomNumber;
        	treasureSubtotal+= temp->payP->treasure;
            printf("The number of props was %d.\n", room);
            temp=(LLNode*)temp->next;

        }
        //room =temp->payP->getNProps();
        room =temp->payP->roomNumber;
        treasureSubtotal+= temp->payP->treasure;

        printf("The number of props was was %d.\n", room);
    }
}
void LList::printHistory2()
{
    puts("Printing history");
    if(history->payP ==(Payload2*)0)
    {
         puts("Empty list");
    }
    else
    {
	    //traverse the list, printing as we go
        float treasureSubtotal = 0.0;
        int room = -1;
        LLNode2* temp = history;
        while(temp->next)
        {
            room =temp->payP->roomNumber;
            treasureSubtotal+= temp->payP->treasure;
            printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
            temp=(LLNode2*)temp->next;

        }
        room =temp->payP->roomNumber;
        treasureSubtotal+= temp->payP->treasure;
        printf("The room was %d, and the treasure subtotal was %f.\n", room, treasureSubtotal);
    }
}
LLNode* LList::removeFromList(Payload* pP)
{
	LLNode* retHead = search;//only changes if first element gets removed
	//find the payload
	//use the structure of a list, namely, list is empty or element followed by list
	if(isEmpty())
	{
		//nothing to do
	}
	else
	{
		//puts("list is not empty");fflush(stdout);
		LLNode* altHead = (LLNode*)search->next;
		//find the item, if it is there
		LLNode* temp = search;
		bool done = false;
		while((!done) && temp->next)
		{
			//are we there yet?
			if(temp->payP == pP)
			{
				done=true;
				//puts("found it 1");fflush(stdout);
			}
			else
			{
				temp=(LLNode*)temp->next;
			}
		}
		//either we are pointing to the correct element, or we are at the end, or both
		if((temp->payP) == pP)
		{
			//puts("found it 2");fflush(stdout);
			//found it, remove it
			//are we at the beginning?
			if(temp == search)
			{  //found it at the first element
				//puts("found it at first element");fflush(stdout);
				//is the list of length 1?
				if(!(temp->next))
				{//if there is no next
					//remove payload, return empty list
					search->payP = (Payload*)0;
				}
				else //not of length 1
				{ //not freeing the Payload, but freeing the first list element
					//puts("found it at first element of list with length > 1");fflush(stdout);
					//free(hP);
					retHead = altHead;
				}
			}
			else //not found at first location in list
			{
				//puts("found it not at first element");fflush(stdout);
				//save the linkages
				//found element has a next
				//found element has a prev
				//participant before has a next
				//participant after has a prev
				LLNode* prevPart = (LLNode*) temp->prev;//non-zero because not at first element
				LLNode* nextPart = (LLNode*) temp->next;//could be zero, if found at last element
				prevPart->next = (struct LLNode*) nextPart;//RHS is 0 if at end
				//puts("after setting the next of the previous");fflush(stdout);
               // printf("Next is %p, %d\n", nextPart, (bool)nextPart);fflush(stdout);
				if((bool)nextPart)//don't need guarded block if element found at end of list
				{
					//puts("before setting the previous of the next");fflush(stdout);
					nextPart->prev = (struct LLNode*) prevPart;

				}
				//puts("after handling the  previous of the next");fflush(stdout);
			}//end of not found at first location
		}//end of found it
		else
		{
			//didn't find it
			//puts("did not find it");fflush(stdout);
			//nothing to do
		}//end did not find it
	}
	//printf("Returning %p\n", retHead); fflush(stdout);
	return retHead;
}
