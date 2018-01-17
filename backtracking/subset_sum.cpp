#include <stdio.h>

void printAr (int array[],int size){
	for (int i = 0 ; i < size ; i ++) printf("%d\n",*array[i] );
}