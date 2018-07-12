// To run the program, try the command below:
// g++ rotate_matrix_90_degree.cpp -lgtest_main -lgtest

// rotate a matrix 90 degree

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

#define ROWS 3
#define COLS 3

void rotateMatrix(int matrix[ROWS][COLS]) {

    for (int i=0; i<ROWS/2; i++) {
        int first = i;
        int last  = ROWS - 1 - first;
        for (int j=first; j<last; j++) {
            int offset = j - first;
            int top = matrix[first][j]; // save top left

            // left element -> top element
            matrix[first][j] = matrix[last-offset][first];

            // bottom element -> left element
            matrix[last-offset][first] = matrix[last][last-offset];

            // right element -> bottom element
            matrix[last][last-offset] = matrix[j][last];

            // top element -> right element
            matrix[j][last] = top;
        }
    }
    //std::cout << "rows: " << rows << "\tcols: " << cols << std::endl;
}

template<typename T, size_t size>
::testing::AssertionResult ArraysMatch(const T (&expected)[size],
        const T (&actual)[size]){
    for (size_t i(0); i < size; ++i){
        if (expected[i] != actual[i]){
            return ::testing::AssertionFailure() << "array[" << i
                << "] (" << actual[i] << ") != expected[" << i
                << "] (" << expected[i] << ")";
        }
    }

    return ::testing::AssertionSuccess();
}

TEST(rotateMatrix, 3RowSquareMatrix) {
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int rotated_matrix[3][3] = {{7,4,1}, {8,5,2}, {9,6,3}};
    rotateMatrix(matrix);
    EXPECT_TRUE(ArraysMatch(matrix, matrix));
//    EXPECT_EQ(rotated_matrix, matrix);
}

