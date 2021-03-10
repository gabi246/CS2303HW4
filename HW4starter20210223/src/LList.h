/*
 * LList.h
 *
 *  Created on: Feb 26, 2021
 *      Author: theresesmith
 */

#ifndef LLIST_H_
#define LLIST_H_

//#include "Room.h"
//#include "Aircraft.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Room.h"
typedef struct SearchResults
{
	int roomNumber;
	float treasure;
}SearchResults;
//typedef Aircraft Payload;//temp
typedef SearchResults Payload2;
typedef Room Payload;
struct LLNode;
typedef struct LLNode
{
	struct LLNode* next;
	struct LLNode* prev;
	Payload* payP;
}LLNode;
typedef struct LLNode2
{
	struct LLNode2* next;
	struct LLNode2* prev;
	Payload2* payP;
}LLNode2;

typedef struct backFromDQFIFO
{
	Payload* mp;
	LLNode* newQHead;
}backFromDQFIFO;

class LList {
public:
	LList();
	virtual ~LList();
	LLNode* makeEmptyLinkedList();
	LLNode2* makeEmptyLinkedList2();
	LLNode* removeFromList(Payload* pP);
	void savePayload(Payload* mp);
	void savePayload2(Payload2* mp);
	bool isEmpty();
	bool isEmpty2();
	Payload* dequeueLIFO();
	backFromDQFIFO* dequeueFIFO();
	void printHistory();
	void printHistory2();

private:
	LLNode* search;
	LLNode2* history;
};




#endif /* LLIST_H_ */
