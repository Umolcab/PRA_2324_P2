#include <limits>
#include <algorithm>
#include <iostream>

int* cambio(int N, int* v, int M){
	int infinito = std::numeric_limits<int>::max();
	int** matrix = new int*[N];
	int* matrix_sol = new int[N];
	int k = N-1, l = M;
	for(int i = 0; i < N; i++){
		matrix[i] = new int[M+1];
		for(int j = 0; j <= M; j++){
			if(!j){
				matrix[i][j] = 0;
			}else{
				matrix[i][j] = -1;
			}
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= M; j++){
			if(j == 0){
				matrix[i][j] = 0;
			}else if(i == 0 && v[0] > M){
				matrix[i][j] = infinito;
			}else if(i == 0 && v[0] <= M){
				matrix[i][j] = 1 + matrix[i][j-v[0]];
			}else if(v[i] > j){
				matrix[i][j] = matrix[i-1][j];
			}else{
				matrix[i][j] = std::min(matrix[i-1][j], 1+matrix[i][j-v[i]]);
			}
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0; i < N; i++){
		matrix_sol[i] = 0;
	}

	while(k > 0 && l > 0){
		if(matrix[k][l] == (1 + matrix[k][l-v[k]])){
			matrix_sol[k] += 1;
			l -= v[k];
		}else{
			k--;
		}
	}

	return matrix_sol;	
}

int main(){
	int v[] = {1,4,6};
	int N = 3;
	int M = 8;
	int* sol = cambio(N, v, M);
	
	std::cout << "Vector solución ( ";
	for(int i = 0; i < N; i++){
		std::cout << sol[i] << " ";
	}
	std::cout << ")" << std::endl;
	return 0;
}
