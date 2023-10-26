#include <limits>
#include <algorithm>
#include <iostream>

int cambio(int N, int* v, int M){
	int infinito = std::numeric_limits<int>::max();
	int** matrix = new int*[N];
	for(int i = 0; i < N; i++){
		matrix[i] = new int[M+1];
		for(int j = 0; j <= M; j++){
			if(!j){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = -1;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= M; j++){
			if(i == 0 && v[0] > M){
				matrix[i][j] = infinito;
			}else if(i == 0){
				matrix[i][j] = 1 + matrix[i][j-v[0]];
			}else if(v[i] > j){
				matrix[i][j] = matrix[i-1][j];
			}else{
				std::min(matrix[i-1][j], matrix[i][j-v[i]]);
			}
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return matrix[N-1][M];	
}

int main(){
	int v[] = {1,4,6};
	int N = 3;
	int M = 8;

	printf("El valor óptimo es: %d\n", cambio(N, v, M));
	return 0;
}
