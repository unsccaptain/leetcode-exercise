/**
 * 杨辉三角
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/776
 **/
#pragma once

#include <vector>
using namespace std;

namespace s776 {
namespace use_iter {
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> nums;
    if (numRows == 0)
      return nums;
    nums.push_back(vector<int>(1, 1));
    if (numRows == 1)
      return nums;
    nums.push_back(vector<int>(2, 1));
    for (int i = 2; i < numRows; i++) {
      nums.push_back(vector<int>());
      ///  前一行和前两行
      vector<int> &last = nums[i - 1];
      vector<int> &current = nums[i];
      current.push_back(1);
      for (int j = 1; j < i; j++) {
        current.push_back(last[j - 1] + last[j]);
      }
      current.push_back(1);
    }
    return nums;
  }
};
} // namespace use_iter
} // namespace s776