#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include<conio.h>
#include<fstream>

#pragma warning(disable : 4996)
using namespace std;
int** twoDmatrix(int m, int n) {
    // create a 2D matrix of arbitrary dimensions
    int ii, ** M;
    M = new int *[m * sizeof(int**)];
    M[0] = new int[m * n * sizeof(int*)];
    for (ii = 1; ii < m; ii++) {
        M[ii] = M[0] + ii * n;
    }
    return M;
}

void free2D(int** M) {
    // free memory allocated by twoDmatrix()
    free(M[0]);
    free(M);
}

int isPow2(int n) {
    // return 1 if the argument is a valid (positive) power of 2
    if (n <= 1) return 0;
    while (n > 1) {
        if (n % 2 == 1) return 0;
        n = n / 2;
    }
    return 1;
}

void emptyBuf(void) {
    while (getchar() != '\n');
    return;
}

int main(void) {
    int** W;
    int N;
    int power = 1;
    int i, j, k, l, p = 0;
    while (1 == 1) {
        printf("enter the size of the matrix - must be a positive power of 2\n");
        if (scanf("%d", &N) != 1) {
            printf("unable to scan input\n");
            emptyBuf();
            continue;
        }
        if (!isPow2(N)) {
            printf("%d is not a valid power of 2\n", N);
            continue;
        }
        break; // valid input: go on
    }

    W = twoDmatrix(N, N); // allocate memory for 2D matrix
    W[0][0] = 1;   // this is the 1x1 Walsh code...

    while (power < N) {
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                if (!(i == 0 && j == 0)) {
                    for (k = 0; k < power; k++) {
                        for (l = 0; l < power; l++) {
                            if (i == 1 && j == 1) {
                                W[i * power + k][j * power + l] = -W[k][l]; // invert signal
                            }
                            else {
                                W[i * power + k][j * power + l] = W[k][l]; // copy signal
                            }
                        }
                    }
                }
            }
        }
        power *= 2; // double matrix and repeat
    }
    fstream file;
    file.open("input.txt");
    if (!file) {
        cout << "file khondeh nashoedeh!!";
      
    }
    
    // print out result
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            file << W[i][j]<<" ";  // <<<<< updated
        }
        file << "\n";
    }
    free2D(W); // always remember to free your memory...
}