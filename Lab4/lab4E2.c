#include <stdio.h>
#include <ctype.h> //toupper or tolower

int main(){

	char isTaken[100]={0}, ans; //initializer syntax
	int seat;

	printf("The theater has 100 seats numbered 1 to 100\n");
	printf("Enter a seat number (ctr-d) to quit: ");

	while (scanf("%d", &seat) == 1){
		//if seat is available
		if (isTaken[seat-1] == 0){
			printf("Seat %d is available\n", seat);
			printf("Would you like to book it: ");
			getchar();
			ans = getchar();
			if (toupper(ans) == 'Y'){
				isTaken[seat-1] = 1;
				printf("Booking successful.\n");
			}
		}
		//if seat is taken
		else{
			printf("Seat %d is taken\n", seat);
		}
		printf("Enter a seat number (ctr-d) to quit");
	}
	return 0;
}
