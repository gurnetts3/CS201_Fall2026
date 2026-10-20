#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

	char a[8];
	char *b;

	strcpy(a, "hello");
	b = (char *)  malloc((strlen(a)+1) * sizeof(char));
	strcpy(b, a);

	printf(" a is  %s and b is %s\n", a, b);
	free(b);
	b = NULL;
	return 0;
}
