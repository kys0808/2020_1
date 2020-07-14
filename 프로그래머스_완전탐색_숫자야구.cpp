#include <stdio.h>

int factorial(int a){
	int sum = 1;
	for (a; a > 0; a--){
		sum = sum*a;
	}
	return sum;
}

int main(){
	for (int i = 0; i < 6; i++){
		int sum = 0;
		for (int j = 0; j < 6; j++){
			if (i == 4){
				break;
			}
			if (j == 5){
				continue;
			}
			sum = i * 10 + j;
			printf("%d\n", sum);
		}
	}
}