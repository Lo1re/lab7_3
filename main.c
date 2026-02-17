#include <stdio.h>
#define ROWS 5
#define COLS 5
int min_in_row(int arr[], int cols) {
    if (cols == 1) return arr[0];           
    int min_rest = min_in_row(arr + 1, cols - 1); 
    return (arr[0] < min_rest) ? arr[0] : min_rest;
}
void min_in_matrix(int arr[ROWS][COLS], int row_index, int min[ROWS]) {
    if (row_index == ROWS) return;          
    min[row_index] = min_in_row(arr[row_index], COLS); 
    min_in_matrix(arr, row_index + 1, min); 
}
int main() {
    printf("Enter elements of the matrix (%dx%d):\n", ROWS, COLS);
    int matrix[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int min_arr[ROWS];
    min_in_matrix(matrix, 0, min_arr); 
    printf("\nmin elements:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("row %d: %d\n", i + 1, min_arr[i]);
    }
    return 0;
}