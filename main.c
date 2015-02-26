/*	Systems Programming
 *    Assignment #2 (pa2)
 *    Author:  Jesse Strivelli
 */


#include <stdio.h>
#include <stdlib.h>
#include "sorted-list.h"
#include <string.h>

/* this method includes the */
int compInts(void* a, void* b){
	/* This is for int comparisons */
		int cmp1 = *(int*)a;
		int cmp2 = *(int*)b;
		if(cmp1 < cmp2){
			return -1;
		}
		else if(cmp1 == cmp2){
			return 0;
		}
		else{
			return 1;
		}
		
}	
/*This is for double comparisons*/
int compDoubles(void* a, void* b){

		double cmp3 = *(double*)a;
		double cmp4 = *(double*)b;
		if(cmp3 < cmp4){
			return -1;
		}
		else if(cmp3 == cmp4){
			return 0;
		}
		else{
			return 1;
		}	
}

int stringComp(void* a, void* b){
	/*This is for string comparisons*/
		char *str1 = a;
		char *str2 = b;
		if(strcmp(str1, str2) < 0){
			return -1;
		}
		else if(strcmp(str1, str2) > 0){
			return 1;
		}
		else
			/*This will equal 0*/
			return strcmp(str1, str2);

}

int structCmp(void* a, void* b){
	return 0;
	/*This method compares struct types*/
}

void dfInt(void * a){
	int *b = (int*) a;
	free(b);
	b = NULL;
	return;
}

void dfDouble(void *a){
	double *b = (double*)a;
	free(b);
	b = NULL;
}

void dfString(void *a){
	char *str = a;
	free(str);
	str = NULL;
}

int main(int argc, char** argv){

	SortedListPtr sl = SLCreate(&compInts, &dfInt);
	int* a = malloc(sizeof(int*));
	int* b = malloc(sizeof(int*));
	int* c = malloc(sizeof(int*));
	int* d = malloc(sizeof(int*));
	int* e = malloc(sizeof(int*));

	*a = 34;
	*b = 43;
	*c = 6;
	*d = 26;
	*e = 41;

	printf("----------------------\n\ntest #1: inserting integers\n");

	 SLInsert(sl, a);
	 SLInsert(sl, b);
	 SLInsert(sl, c);
	 SLInsert(sl, d);
	 SLInsert(sl, e);


	SortedListIteratorPtr iter1 = SLCreateIterator(sl);
  	int* check1 = SLGetItem(iter1);
  	while(check1 != NULL){
  		printf("%d\n", *check1);
  		check1 = SLNextItem(iter1);
  	}
  	SLDestroyIterator(iter1);

  	printf("\ntest #2: removing 2 integers from middle and end of list\n");

  	SLRemove(sl, a);
  	SLRemove(sl, c);

    iter1 = SLCreateIterator(sl);
  	int* check2 = SLGetItem(iter1);
  	while(check2 != NULL){
  		printf("%d\n", *check2);
  		check2 = SLNextItem(iter1);
  	}
  	SLDestroyIterator(iter1);

  	SLDestroy(sl);

  	printf("\ntest #3: inserting doubles\n");
	SortedListPtr list = SLCreate(&compDoubles, &dfDouble);
	
	double* d1 = (double*)malloc(sizeof(double));
	double* d2 = (double*)malloc(sizeof(double));
	double* d3 = (double*)malloc(sizeof(double));
	double* d4 = (double*)malloc(sizeof(double));
	double* d5 = (double*)malloc(sizeof(double));

	*d1 = 53.75;
	*d2 = 67.3;
	*d3 = 42.281;
	*d4 = 42.111;
	*d5 = 42.9018;

	SLInsert(list, d1);
	SLInsert(list, d2);
	SLInsert(list, d3);
	SLInsert(list, d4);
	SLInsert(list, d5);

	
	iter1 = SLCreateIterator(list);
	while(iter1->ptr!=NULL){
		printf("%f\n",*(double*)SLGetItem(iter1));
		SLNextItem(iter1);
	}

 	SLDestroyIterator(iter1);

 	SLRemove(list, d1);
 	SLRemove(list, d4);
 	SLRemove(list, d5);

 	printf("\ntest #4: removing 2 doubles from middle and 1 from end of list\n");

 	iter1 = SLCreateIterator(list);
 	while(iter1->ptr!=NULL){
		printf("%f\n",*(double*)iter1->ptr->data);
		SLNextItem(iter1);
	}

	SLDestroyIterator(iter1);
	SLDestroy(list);

	printf("\ntest #5: inserting Strings\n");
	SortedListPtr listString = SLCreate(&stringComp, &dfString);
	char* s1 = malloc(sizeof(char)* 5);
	char* s2 = malloc(sizeof(char)* 5);
	char* s3 = malloc(sizeof(char)* 8);
	char* s4 = malloc(sizeof(char)* 5);
	char* s5 = malloc(sizeof(char)* 5);


	strcpy(s1, "hello");
	strcpy(s2, "world");
	strcpy(s3, "what are");
	strcpy(s4, "up to");
	strcpy(s5, "today");

	SLInsert(listString, s1);
	SLInsert(listString, s2);
	SLInsert(listString, s3);
	SLInsert(listString, s4);
	SLInsert(listString, s5);

	iter1 = SLCreateIterator(listString);
	while(iter1->ptr!=NULL){
		printf("%s\n",(char*)iter1->ptr->data);
		SLNextItem(iter1);
	}

	SLDestroyIterator(iter1);

	printf("\ntest #6: trying to remove data that does not exist from the string list\n");
	SLRemove(listString, (void*)"yo");
	SLDestroy(listString);
	free(a);

	printf("\nFinished with test cases from main\n\n----------------------\n");

}
