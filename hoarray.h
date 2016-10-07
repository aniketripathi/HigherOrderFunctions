/*
 * hoarray.h
 *
 *  Created on: 04-Jul-2016
 *      Author: Aniket
 */

#ifndef HOARRAY_H_
#define HOARRAY_H_
#include <stdlib.h>

/**@addtogroup typedefGroup	Typedefines for various type of pointer to functions
 * 	@brief Declares various function pointers based on their type and number of arguments and type of return
 *  The following convention is followed in order.
 *  1. Name begins with 'fptr' to indicate that it is a function pointer.
 *  2. Then type of argument. For pointers - 'P'. Use String for character array and original names otherwise.
 *  3. Total number number of arguments.
 *  4. Return type following same convention as for arguments.
 *
 *@{
 */
typedef void (*fptrLongIntOneVoid) (long int);
typedef void (*fptrLongIntLongIntTwoVoid)(long int, long int);
typedef long int (*fptrLongIntOneLongInt)(long int);
typedef long int (*fptrLongIntLongIntTwoLongInt)(long int, long int);
typedef int (*fptrLongIntLongIntTwoInt)(long int);
typedef void (*fptrPLongIntOneVoid)(long int*);
typedef int (*fptrLongIntOneInt)(long int);
/**@}*/


/**
 * \brief Performs an action on each of the array element from begIndex to endIndex.
 *
 *  This function will take four arguments. It will perform an action on the value given by each element
 *  of the array starting from begIndex to endIndex. The action is defined by a function and a pointer to
 *  function is passed as argument. Note that this method will not affect the array in any way. In case of
 *  NULL pointer for any either of the two arguments, nothing will happen. Both begIndex and endIndex are inclusive.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param action      : A pointer to function. The function must have one argument of long int and void return type.
 * \return            : void, it does not returns anything.
 **/
void forEach(long int* array, long unsigned int begIndex, long unsigned int endIndex,fptrLongIntOneVoid action);



/**
 * \brief Sets the value of the array according to the process function.
 *
 *  This function will take four arguments. It sets the value of each element of the array starting from begIndex
 *  to endIndex according to the process function. The process is defined by a function and a pointer to
 *  function is passed as argument. It will have a single argument of long integer type. In case of
 *  NULL pointer for any either of the two arguments, nothing will happen. Both begIndex and endIndex are inclusive.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param process     : A pointer to function. The function must have one argument of long int which will be the
 * 						index of the element. The process must return the value according to index which needs
 * 						to be stored at each index.
 * \return            : void, it does not returns anything.
 **/
void setValue(long int* array, long unsigned int begIndex, long unsigned int endIndex,fptrLongIntOneLongInt process);




/**
 * \brief Performs an operation on each of the array element from begIndex to endIndex and adds the result of each operation.
 *
 * This function will take four arguments. It will perform an operation on the value given by each element
 * of the array starting from begIndex to endIndex. The operation is defined by a function which takes the array elements
 * as argument and returns a value. The summation of these values are returned. In case of if the array or pointer to function
 * is NULL, then 0 is returned.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param operation   : A pointer to function. The function must have one argument of long int and long int return type.
 * 						The operation performed on the elements depends on this function.
 * \return            : It returns the summation of all the values returned after performing the operations.
 **/
long int reduce(long int* array, long unsigned int begIndex, long unsigned int endIndex, fptrLongIntOneLongInt operation);


/**
 * \brief Performs an operation on each of the array element from begIndex to endIndex and returns a new array.
 *
 * This function will take four arguments. It will perform an operation on the value given by each element
 * of the array starting from begIndex to endIndex. The operation is defined by a function which takes the array elements
 * as argument and returns a value. A new array is created and and each element contains the operated value returned by the
 * function pointed to by operation. Memory is allocated from heap to new array. In case if the array or pointer to function
 * is NULL or failure of allocation of memory then NULL is returned. The length of newArray is same as that of original array.
 * Remember to free the memory when done with the new array returned.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param operation   : A pointer to function. The function must have one argument of long int and long int return type.
 * 						The operation performed on the elements depends on this function.
 * \return            : It returns the new array which contains the mapped value to the array elements.
 **/
long int *map(long int* array, long unsigned int begIndex, long unsigned int endIndex, fptrLongIntOneLongInt operation);


/**
 * \brief Performs an operation on each of the array element from begIndex to endIndex and returns a new array.
 *
 * This function will take four arguments. It will perform an operation on the value given by each element
 * of the array starting from begIndex to endIndex. The operation is defined by a function which takes the array elements
 * as argument and returns a value. The original array is modified and value at every index is replaced by the operated
 * value returned by the function pointed to by operation. In case if the array or pointer to function is NULL then NULL
 * is returned.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param operation   : A pointer to function. The function must have one argument of pointer to long int
 *  					and long int return type. The element of array is passed through call by reference.
 * 						The operation performed on the elements depends on this function.
 * \return            : void, it does not returned anything.
 **/
void transform(long int* array, long unsigned int begIndex, long unsigned int endIndex, fptrPLongIntOneVoid operation);


/**
 * \brief Filters the elements of the given array from begIndex to endIndex that satisfies the given test and returns a new array.
 *
 * This function will take five arguments. It will perform a test given by a function pointed to by test pointer and those elements
 * which return non-zero value for test will be stored in the new array. Memory to the new array is allocated from heap. The length of
 * the new array will be stored in the variable pointed to by the length argument. The function will return NULL under four circumstances-
 * if array is null, pointer to function is null, pointer to length is null and failure to allocate memory. The new array is returned otherwise.
 * Remember to free the memory when done with the new array.
 *
 * \param array 	  : Array of numbers
 * \param begIndex    : Starting index. To begin with first element pass 0 to it.
 * \param endIndex    : Index at which the action should stop. To stop at last index pass length-1 to it.
 * \param test	      : A pointer to function. The function must have one argument of long int and int return type.
 * 						For any non-zero return value by this function for any element will be considered as passing the test.
 * \param length	  : Pointer to a variable to hold the length of the filtered array.
 * \return            : It returns the new array which contains the filtered elements
 **/
long int *filter(long int* array, long unsigned int begIndex, long unsigned int endIndex, long unsigned int *length, fptrLongIntOneInt test);

#endif /* HOARRAY_H_ */
