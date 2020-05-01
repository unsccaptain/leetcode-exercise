/**
 * 螺旋矩阵
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/775
 * 和774同理，也是模拟，但边界情况稍微复杂了一点。
 **/
#pragma once

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0)
      return vector<int>();
    if (matrix.size() == 1)
      return matrix[0];

    int row = 0, col = 0;
    int row_max = matrix.size() - 1;
    int col_max = matrix[0].size() - 1;
    int row_min = 1, col_min = 0;
    int count = matrix.size() * matrix[0].size();
    /// 水平方向正向还是反向
    bool rdir = true;
    /// 垂直方向正向还是反向
    bool cdir = true;
    bool rc = true;

    vector<int> out;

    while (count--) {

      out.push_back(matrix[row][col]);

      if (rc) {
        if (rdir) {
          if (col < col_max) {
            col++;
          } else {
            rc = false;
            rdir = false;
            col_max--;
            row++;
          }
        } else {
          if (col > col_min) {
            col--;
          } else {
            rc = false;
            rdir = true;
            col_min++;
            row--;
          }
        }
      } else {
        if (cdir) {
          if (row < row_max) {
            row++;
          } else {
            rc = true;
            cdir = false;
            row_max--;
            col--;
          }
        } else {
          if (row > row_min) {
            row--;
          } else {
            rc = true;
            cdir = true;
            row_min++;
            col++;
          }
        }
      }
    }

    return out;
  }
};