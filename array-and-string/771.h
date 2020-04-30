/**
 * 至少是其他数字两倍的最大数
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/771
 * 很简单，遍历一趟，记录最大数和第二大的数，然后比较他们之间的关系就好了。
 **/
#pragma once

#include <vector>
using namespace std;

namespace s770 {
namespace use_ary {
class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    if (nums.size() < 1)
      return (int)nums.size() - 1;
    int max1 = INT_MIN, max2 = INT_MIN, max1_p = 0, max2_p = 0;
    for (auto i = 0; i < nums.size(); i++) {
      /// 分别记录最大数和第二大的数
      if (nums[i] > max2) {
        if (nums[i] > max1) {
          max2 = max1;
          max2_p = max1_p;
          max1 = nums[i];
          max1_p = i;
        } else {
          max2 = nums[i];
          max2_p = i;
        }
      }
    }

    if (max1 >= max2 * 2)
      return max1_p;
    else
      return -1;
  }
};
} // namespace use_ary
} // namespace s770