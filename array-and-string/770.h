/**
 * Ѱ���������������
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
    /// ��һ�˼�������֮��
    for (auto i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    int sum1 = 0;
    for (auto i = 0; i < nums.size(); i++) {
      /// �жϲ��ֺ��Ƿ�������͵�һ��
      if (sum1 * 2 + nums[i] == sum)
        return i;
      sum1 += nums[i];
    }
    return -1;
  }
};
} // namespace use_ary
} // namespace s770