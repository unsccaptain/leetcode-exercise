/**
 * 寻找数组的中心索引
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/770
 **/
#pragma once

#include <vector>
using namespace std;

namespace s770 {
namespace use_ary {
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int sum = 0;
    /// 第一趟计算数组之和
    for (auto i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    int sum1 = 0;
    for (auto i = 0; i < nums.size(); i++) {
      /// 判断部分和是否是整体和的一半
      if (sum1 * 2 + nums[i] == sum)
        return i;
      sum1 += nums[i];
    }
    return -1;
  }
};
} // namespace use_ary
} // namespace s770