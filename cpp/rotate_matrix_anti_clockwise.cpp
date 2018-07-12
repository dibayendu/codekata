// To run the program, try the command below:
// g++ rotate_matrix_anti_clockwise.cpp -lgtest_main -lgtest

// rotate a matrix anti clockwise

#include "gtest/gtest.h"

template<typename T, size_t rows, size_t cols>
void rotate (T (&matrix)[rows][cols]) {
    size_t row_count = rows;
    size_t col_count = cols;


    int to_rotate_rows = row_count;
    int to_rotate_cols = col_count;

    int start_row=0;
    int start_col=0;
    int end_row=row_count-1;
    int end_col=col_count-1;

    //guaranteed that the minimum of to rotate will be even.
    while (to_rotate_rows>1 && to_rotate_cols>1) {

        //top
        int temp = matrix[start_row][end_col];
        for (int i=end_col-1; i >=start_col ; --i) {
            int value = temp;
            temp = matrix[start_row][i];
            matrix[start_row][i] = value;
        }

        //left
        for (int i=start_row+1; i <=end_row; ++i) {
            int value = temp;
            temp = matrix[i][start_col];
            matrix[i][start_col] = value;
        }


        //bottom
        for (int i=start_col+1; i <=end_col; ++i) {
            int value = temp;
            temp = matrix[end_row][i];
            matrix[end_row][i] = value;
        }

        //right
        for (int i=end_row-1; i >=start_row ; --i) {
            int value = temp;
            temp = matrix[i][end_col];
            matrix[i][end_col] = value;
        }

        to_rotate_rows -=2;
        to_rotate_cols -=2;
        start_row +=1;
        start_col +=1;
        end_row -=1;
        end_col -=1;
    }
}

template<typename T, size_t rows, size_t cols>
::testing::AssertionResult matrixMatch(const T (&expected)[rows][cols],
        const T (&actual)[rows][cols]){
    for (size_t i(0); i < rows; ++i){
        for (size_t j(0); j < cols; ++j){
            if (expected[i][j] != actual[i][j]){
                return ::testing::AssertionFailure() << "array[" << i
                    << "][" << j << "] (" << actual[i][j] << ") != expected[" << i
                    << "][" << j << "] (" << expected[i][j] << ")";
            }
        }
    }

    return ::testing::AssertionSuccess();
}

TEST(rotateMatrix, 4x4) {
    int matrix[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int expected_matrix[4][4] = {{2,3,4,8}, {1,7,11,12}, {5,6,10,16}, {9,13,14,15}};
    rotate(matrix);
    EXPECT_TRUE(matrixMatch(expected_matrix, matrix));
}

TEST(rotateMatrix, 2x2) {
    int matrix[2][2] = {{1,2}, {3,4}};
    int expected_matrix[2][2] = {{2,4}, {1,3}};
    rotate(matrix);
    EXPECT_TRUE(matrixMatch(expected_matrix, matrix));
}

TEST(rotateMatrix, 5x4) {
    int matrix[5][4] = {{1,2,3,4}, {7,8,9,10}, {13,14,15,16}, {19,20,21,22}, {25,26,27,28}};
    int expected_matrix[5][4] = {{2,3,4,10}, {1,9,15,16}, {7,8,21,22}, {13,14,20,28}, {19,25,26,27}};
    rotate(matrix);
    EXPECT_TRUE(matrixMatch(expected_matrix, matrix));
}

