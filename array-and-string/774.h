/**
 * �Խ��߱���
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
    /// �����������������ƺ��ƽ��ķ���
    int direction = 0;
    int ver = 0, hor = 0;
    while (ver < rows && hor < cols) {
      if (direction) {
        /// ����
        ret.push_back(matrix[ver][hor]);
        /// �ضԽ��������ƽ�
        while (hor != 0 && ver != rows - 1) {
          hor--;
          ver++;
          ret.push_back(matrix[ver][hor]);
        }
        /// �������߽磬��ת����
        if (ver == rows - 1)
          hor++;
        else
          ver++;
        direction = 0;
      } else {
        /// ����
        ret.push_back(matrix[ver][hor]);
        /// �ضԽ��������ƽ�
        while (ver != 0 && hor != cols - 1) {
          ver--;
          hor++;
          ret.push_back(matrix[ver][hor]);
        }
        /// �������߽磬��ת����
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
      /// ���㵱ǰ�Խ��ߵ���ʼ����
      int row = i < cols ? 0 : i - cols + 1;
      int col = i < cols ? i : cols - 1;

      iterator first = position;
      /// �ضԽ��������ƽ�
      while (row < rows && col >= 0) {
        *position++ = matrix[row][col];
        ++row;
        --col;
      }

      int val = i >> 1;
      /// ż���Ļ���ת
      if (i == (val << 1)) {
        reverse(first, position);
      }
    }

    return ret;
  }
};
} // namespace use_iter
} // namespace s774