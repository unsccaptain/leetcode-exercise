/**
 * º”“ª
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/772
 **/
#pragma once

#include <vector>
using namespace std;

namespace s772 {
namespace use_ary {
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] != 9) {
        digits[i] += 1;
        return digits;
      } else {
        digits[i] = 0;
      }
    }

    digits.insert(digits.begin(), 1);
    return digits;
  }
};
} // namespace use_ary
} // namespace s772