/**
 * ��Ч����ĸ��λ��
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/985
 * ����set��¼��һ��string������ĸ���ֵĴ�����Ȼ������ڶ����ַ�������set�м�ȥ���г��ֵ��ַ�������ж�set�ǲ��Ǳ������
 * set�����������֪�ģ�������һ����������¼
 **/
#pragma once

#include <string>
using namespace std;

namespace s985 {
namespace use_map {
/**
 * @brief: �ֵ䷽��
 */
class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = {0};
    for (auto i : s) {
      count[i - 'a']++;
    }

    for (auto i : t) {
      if (count[i - 'a'] == 0)
        return false;
      count[i - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
      if (count[i])
        return false;
    }

    return true;
  }
};
} // namespace use_map
} // namespace s985