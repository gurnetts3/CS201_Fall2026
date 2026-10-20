#include <stdio.h>

void eliminate_loser(int *p1, int *p2);

int main(){
	int player1, player2;

	player1 = 0; //rock
	player2 = 2; //scissors

	if (player1 == player2){
		printf("tie\n");
	}

	eliminate_loser(&player1, &player2);

	printf("player1 %d and player2 %d\n", player1, player2);

	return 0;
}

void eliminate_loser(int *p1, int *p2){

	if ((*p1 == 0) && (*p2 == 1)){
		*p1 =-1;
	}else if ((*p1 == 0) && (*p2 == 2)){
		*p2 =-1;
	}else if ((*p1 == 1) && (*p2 == 0)){
		*p2 =-1;
	}else if ((*p1 == 1) && (*p2 == 2)){
		 *p1 =-1;
	}else if ((*p2 == 2) && (*p2 == 0)){
		*p2 =-1;
	}else if ((*p1 == 2) && (*p2 == 1)){
		*p1 =-1;
	}
}
