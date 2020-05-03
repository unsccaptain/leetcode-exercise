/**
 * 二进制求和
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/779
 **/
#pragma once

#include <string>
using namespace std;

namespace s779 {
class Solution {
public:
  string addBinary(string a, string b) {
    int p1 = a.size();
    int p2 = b.size();

    string s;

    unsigned bit = 0, carry = 0;

    /// 利用全加器公式计算低位
    while (p1 != 0 && p2 != 0) {
      unsigned b1 = a[--p1] - '0';
      unsigned b2 = b[--p2] - '0';
      bit = b1 ^ b2 ^ carry;
      carry = (b1 && b2) | (carry && (b1 ^ b2));
      s += '0' + bit;
    }

    /// 利用半加器公式计算高位
    if (p1 != 0) {
      while (p1--) {
        unsigned b1 = a[p1] - '0';
        bit = b1 ^ carry;
        carry = b1 && carry;
        s += '0' + bit;
      }
    }

    if (p2 != 0) {
      while (p2--) {
        unsigned b2 = b[p2] - '0';
        bit = b2 ^ carry;
        carry = b2 && carry;
        s += '0' + bit;
      }
    }

    if (carry) {
      s += '1';
    }

    /// 翻转结果
    reverse(s.begin(), s.end());

    return s;
  }
};
} // namespace s779