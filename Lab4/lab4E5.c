#include <stdio.h>

void mat_print_3hd(int m, short x[][3]);
void mat_print(int m, int n, short x[m][n]);

int main(){
	int rows, cols;

	printf("Enter number of rows: ");
	scanf("%d", &rows);
	printf("Enter number of cols: ");
	scanf("%d", &cols);

	short int mat[rows][cols];// = {{10, 20, 30}, {40, 50, 60}};
	mat_print(rows, cols, mat);
	return 0;
}
void mat_print(int m, int n, short x[m][n]){

        for (int i=0; i<m; i++){
                for (int j=0; j<n; j++){
                        printf("%d   ", x[i][j]);
                }
        printf("\n");
        }
}

void mat_print_3hd(int m, short x[][3]){

	for (int i=0; i<m; i++){
		for (int j=0; j<3; j++){
			printf("%d   ", x[i][j]);
		}
	printf("\n");
	}
}
