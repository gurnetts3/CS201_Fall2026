#include <stdio.h>


void str_cpy(char str1[], char str2[]){
	int i = 0;

	while (str2[i] != '\0'){
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}


int main(){
	char x[25] = "this is x";
	char y[24] ="and y";

	printf("Before: str1: %s and str2: %s \n", x, y);
	str_cpy(x, y);
	printf("Afterc: str1: %s and str2: %s \n", x, y);

	return 0;
}
