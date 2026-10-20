#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structString.h"

struct String* String_create_arr(size_t arrLength){
	struct String *array;

	array = (struct String *) malloc(arrLength * sizeof(struct String));

	if (array == NULL){ //if !(array)
		printf("allocation failed");
		return NULL;
	}
	for (int i=0; i<arrLength; i++){
		array[i].cstring =NULL;
		array[i].len = 0;
		array[i].capacity = 0;
	}
	return array;
}

bool String_set_cstring(struct String* p2String, const char* newCstring){

	int sz;

	sz = strlen(newCString)+1;

	while (sz %8 != 0){
		sz +=1;
	}

	p2String->cstring = (char *) malloc(sz*sizeof(char));

	if (p2String->cstring == NULL){
		printf("Allocation failed\n");
		return false;
	}

	strcpy(p2String->cstring, newCString);

	p2String->capacity = sz;
	p2String->len = strlen(newCString);

	return true;
}

void String_del_cstring(struct String* p2String){

	if (p2String){
		if (p2String->cstring){
			free(p2String->cstring);
			p2String->cstring =NULL;
			p2String->len = 0;
			p2String->capacity = 0;
}

void String_destroy_arr(size_t arrLength, struct String* arr){

	for (int i=0,i<arrLength;i++){
		if (arr[i].cstring != NUll){
			String_del_cstring(&arr[i]);
			free(p2String->cstring);
			p2String->cstring =NULL;
			p2String->len = 0;
			p2String->capacity = 0;
		}
	}

	free(arr);

}

bool String_cat_cstring(struct String* p2String, const char* newCString);
	//concatenate newCString to p2String
	if (p2String->len+strlen(newCString)+1 <= p2String->capacity){
		strcat(p2String-cstring, newCString);
	}
	//should use old code to resize to multiple of 8
	p2String->cstring = realloc(p2String->cstring, p2String->len+strlen(newCString)+1;

	if (p2String->cstring==NULL)
		return false;

	strcat(p2String->cstring, newCString);
	p2String->len = strlen((p2String->cstring);
	p2String->capacity = p2String->len+strlen(newCString)+1;

	return true;
}

