/**
 * 最长公共前缀
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/781
 * 逐个判断就好，没有什么奇淫巧计
 **/
#pragma once

#include <string>
#include <vector>
using namespace std;

namespace s781 {
class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    char c;
    int i = 0;
    string r;
    if (strs.size() == 0) {
      return r;
    }
    while (true) {
      if (strs[0].size() == i) {
        return r;
      }
      c = strs[0][i];
      for (auto &I : strs) {
        if (I.size() <= i || I[i] != c) {
          return r;
        }
      }
      /// 都有，在公共前缀上追加一个字符
      r += c;
      /// 将指针向前推进一个
      i++;
    }
  }
};
} // namespace s781