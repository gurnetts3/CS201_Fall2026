#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct String {
	char *cstring;
	size_t len;
	size_t  capacity;
};

int main(){
	struct String s1;
	struct String s2;

	char a[8] = "hello";
	char *b;

	b = (char *) malloc(8*sizeof(char));
	strcpy(b, "cat");

	s1.cstring = (char *) malloc((strlen(a)+1)*sizeof(char));
	strcpy(s1.cstring, a);
	s1.len = strlen(s1.cstring);
	s1.capacity = strlen(s1.cstring)+1;

	s2.cstring = (char *) malloc((strlen(b)+1)*sizeof(char));
	strcpy(s2.cstring, b);
	s2.len = strlen(s2.cstring);
	s2.capacity = strlen(s2.cstring)+1;

	return 0;
}
