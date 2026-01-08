/*
Tag: Array, Prefix Sum, 2D Prefix Sum, Design

Problem Statement:
Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

*/
#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> matrx;
    vector<vector<int>> Row_Sum;
    vector<vector<int>> Col_Sum;
    NumMatrix(vector<vector<int>>& matrix) {
        matrx=matrix;
        for(auto &row:matrx){
            int total = 0;
            vector<int> row_agg;
            int i=0;
            for(auto &v:row){
                total+=v;
                row_agg.push_back(total);
            }
            this->Row_Sum.push_back(row_agg);
        }

        for(auto &row:this->Row_Sum){
            int total = 0;
            vector<int> col_agg;
            int i=0;
            for(auto &v:row){
                total+=v;
                if(Col_Sum.size()==0){
                    col_agg.push_back(v);
                }
                else{
                    col_agg.push_back(Col_Sum.back()[i]+v);
                    i++;
                }
                
            }
            this->Col_Sum.push_back(col_agg);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int final_sum = this->Col_Sum[row2][col2];
        
        if(row1>0 || col1>0){
            if(row1>0){
                final_sum=final_sum-this->Col_Sum[row1-1][col2];
                if(col1>0){
                    final_sum=final_sum+this->Col_Sum[row1-1][col1-1];
                }
            }
            if(col1>0){
                final_sum=final_sum-this->Col_Sum[row2][col1-1];
            }
        }
    
        return final_sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

 /*
 My Solution:

 - First I computed the row wise prefix sum and stored it in Row_Sum.
 - Then, I used the row wise prefix sum to compute the column wise prefix sum and stored it in Col_Sum, this means the variable Col_Sum has the sum of all the elements throughout the diagonals and rows to the left and above the current element.
 - Now as we have a requirement to compute the Sum of the rectangular region in O(1) time, we use the left bottom element of the rectangle initially to get the sum of all the elements above and beside it.
 - Then we subtract the elements which are not part of the rectangle, i.e. the elements above the top left corner and the elements to the left of the bottom right corner.
 - While subtracting we need to take care of the overlapping region which gets subtracted twice, so we add it back once.



 */