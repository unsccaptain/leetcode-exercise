/**
 * �����ǰ׺
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/781
 * ����жϾͺã�û��ʲô�����ɼ�
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
      /// ���У��ڹ���ǰ׺��׷��һ���ַ�
      r += c;
      /// ��ָ����ǰ�ƽ�һ��
      i++;
    }
  }
};
} // namespace s781