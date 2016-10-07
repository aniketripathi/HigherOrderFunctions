/*


 * hoarray.c
 *
 *  Created on: 04-Jul-2016
 *      Author: Aniket Kumar Tripathi
 *
 *      This file contains the implementation of the interface of horray.h
 */
#include "hoarray.h"

/**
 * Simple implementation of forEach function. No error handler is used.
 **/
void forEach(long int *array, long int unsigned begIndex, long int unsigned endIndex, fptrLongIntOneVoid action ){
if(array != NULL && action != NULL){
	long unsigned int i;
	for(i = begIndex; i <= endIndex; i++)		action(array[i]);
}
}

/**
 * Simple implementation of setValue function. No error handler is used.
 */
void setValue(long int* array, long unsigned int begIndex, long unsigned int endIndex,fptrLongIntOneLongInt process){
	if(array != NULL && process != NULL){
		long unsigned int i;
		for(i = begIndex; i <= endIndex; i++)		array[i] = process(i);
	}

}


/**
 * Simple implementation of reduce function. No error handler is used. The function adds the values returned by the action function
 *  and then returns a single value. Modify the main expression the get different general term and result. The default value of result
 *  is zero.
 **/
long int reduce(long int *array, long int unsigned begIndex, long int unsigned endIndex, fptrLongIntOneLongInt action){
	long int result = 0;							/* Modify this to change default value */
	if(array != NULL && action != NULL){
		long unsigned int i;
		for(i = begIndex; i <= endIndex; i++)		result += action(array[i]);      /* Modify this for your own general term */
	}
	return result;
}


/**
 * Simple implementation of map function. No error handler is used. The newArray is created from the heap using malloc.
 *
 **/
long int *map(long int *array, long int unsigned begIndex, long int unsigned endIndex, fptrLongIntOneLongInt operation){
	long int *newArray = malloc(sizeof(long int) * (endIndex - begIndex + 1));
	if(array != NULL && operation != NULL && newArray != NULL){
		long unsigned int i;
		for(i = begIndex; i <= endIndex; i++)		newArray[i] = operation(array[i]);
		return newArray;
	}
	return NULL;
}

/**
 * Simple implementation of transform function. No error handler used. The original array is modified.
 */
void transform(long int *array, long int unsigned begIndex, long int unsigned endIndex, fptrPLongIntOneVoid action){
	if(array != NULL && action != NULL){
		long unsigned int i;
		for(i = begIndex; i <= endIndex; i++)		action(array+i);
	}
}

/**
 * Simple implementation of filter method. The elements are filtered on basis of test function. Memory to newArray is allocated from heap.
 * Initially memory is allocated for all the elements. If the length of newArray is less than the original array then the memory is reallocated
 *  using realloc which will free up the extra memory. You can use your custom memory allocating technique.
 */
long int *filter(long int *array, long int unsigned begIndex, long int unsigned endIndex, long unsigned int *length, fptrLongIntOneInt test){
	long unsigned int initialLength = endIndex - begIndex +1;*length = 0;
	long int *newArray = malloc(sizeof(long int) * initialLength);						/* allocating maximum memory assuming all elements are filtered */
	if(array != NULL && test != NULL && newArray != NULL){
		long unsigned int i;
		for(i = begIndex; i <= endIndex; i++){
			if(test(array[i]))		newArray[(*length) ++] = array[i];
		}
			 if((*length) == 0){													/* if no elements passes the test then free all memory */
				free(newArray);
				return NULL;
			}
			 else if((*length) != initialLength)	 								/* free extra memory if number of elements filtered is less*/
				 realloc(newArray, (*length) * sizeof(long unsigned int));
			 return newArray;
	}
	return NULL;
}
