#include <stdio.h>
#include <stdlib.h>

void printArr(const int a[], size_t n, const char *s) {
    printf( "%s:\t", s );
    for ( size_t i = 0; i < n; i++ ) {
        printf( "%d ", a[i] );
    }
    putchar( '\n' );
}

void swapArray(int *a, int *b, size_t n) {
    // IMPLEMENT YOUR swapArray
    int *temp_array = (int *)malloc(sizeof(int)*n);
    for (size_t i = 0; i < n; i++){
        temp_array[i] = a[i];
    }
    for (size_t i = 0; i < n; i++){
        a[i] = b[i];
    }
    for (size_t i = 0; i < n; i++){
        b[i] = temp_array[i];
    }
    free(temp_array);
}

int main() {

    enum { N = 3 };
    int a[N] = { 1, 2, 3 };
    int b[N] = { 4, 5, 6 };

    printArr( a, N, "a" );
    printArr( b, N, "b" );
    putchar( '\n' );

    swapArray( a, b, N );

    printArr( a, N, "a" );
    printArr( b, N, "b" );
    putchar( '\n' );

    return 0;
}