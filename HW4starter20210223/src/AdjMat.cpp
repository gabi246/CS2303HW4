///*
// * AdjMat.cpp
// *
// *  Created on: May 30, 2020
// *      Author: Marie Tessier and Casey Snow
// */
/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"
#include <stdio.h>
#include <cstdlib>


void AdjMat::init()
{
	int ncols = n;
	printf("In init with ncols = %d\n", ncols);
	//TODO need to malloc for the edges
	edgesP = (int*) malloc(ncols*ncols*sizeof(int));
	for(int row = 0; row<ncols; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			*((edgesP)+(row*ncols)+col)= 0;
		}
	}
}

void AdjMat::setEdge(int row, int col)
{

	int ncols = n;
	int* arrayBeginning = edgesP;
	*(arrayBeginning + (ncols*row) +col) = 1;
	*(arrayBeginning + (ncols*col) + row) = 1;
}

int AdjMat::getEdge(int row, int col)
{
	//TODO
	int ncols = n;
	int* arrayBeginning = edgesP;
	return *(arrayBeginning + (ncols*row) +col) ;

}

void AdjMat::setN(int set)
{
	//TODO
	n=set;
}

void AdjMat::setEdgesP(int* set)
{
	//TODO edgesP = set;
	edgesP=set;
}

