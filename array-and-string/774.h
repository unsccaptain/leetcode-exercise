/**
 * 对角线遍历
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/774
 **/
#pragma once

#include <algorithm>
#include <vector>
using namespace std;

namespace s774 {
namespace use_simulate {
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {

    vector<int> ret;
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return ret;

    int rows = matrix.size();
    int cols = matrix[0].size();
    /// 利用这三个变量控制好推进的方向
    int direction = 0;
    int ver = 0, hor = 0;
    while (ver < rows && hor < cols) {
      if (direction) {
        /// 向下
        ret.push_back(matrix[ver][hor]);
        /// 沿对角线向下推进
        while (hor != 0 && ver != rows - 1) {
          hor--;
          ver++;
          ret.push_back(matrix[ver][hor]);
        }
        /// 触碰到边界，调转方向
        if (ver == rows - 1)
          hor++;
        else
          ver++;
        direction = 0;
      } else {
        /// 向上
        ret.push_back(matrix[ver][hor]);
        /// 沿对角线向上推进
        while (ver != 0 && hor != cols - 1) {
          ver--;
          hor++;
          ret.push_back(matrix[ver][hor]);
        }
        /// 触碰到边界，调转方向
        if (hor == cols - 1)
          ver++;
        else
          hor++;
        direction = 1;
      }
    }

    return ret;
  }
};
} // namespace use_simulate
namespace use_iter {
class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return vector<int>();

    using iterator = vector<int>::iterator;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int diff = cols - 1;
    vector<int> ret = vector<int>(rows * cols);
    iterator position = ret.begin();

    for (int i = 0; i < rows + cols - 1; ++i) {
      /// 计算当前对角线的起始坐标
      int row = i < cols ? 0 : i - cols + 1;
      int col = i < cols ? i : cols - 1;

      iterator first = position;
      /// 沿对角线向下推进
      while (row < rows && col >= 0) {
        *position++ = matrix[row][col];
        ++row;
        --col;
      }

      int val = i >> 1;
      /// 偶数的话逆转
      if (i == (val << 1)) {
        reverse(first, position);
      }
    }

    return ret;
  }
};
} // namespace use_iter
} // namespace s774