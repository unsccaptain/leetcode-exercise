/**
 * ͬ���ַ���
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/987
 * ��������ӳ�䣬s->t��t->s��Ȼ��ֱ���ȷ��û��һ�Զ��ӳ�䡣
 * ��Ϊ���ַ�����������Ȼʹ������������ӳ�䡣
 **/
#pragma once

#include <map>
#include <set>
#include <string>

using namespace std;

namespace s987 {
namespace use_map {
/**
 * @brief: �ֵ䷽��
 */
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    char s_map[128] = {0};
    for (auto i = 0; i < s.size(); i++) {
      /// ������s_map�н���s->t��ӳ��
      if (s_map[s[i]] != 0) {
        /// ��ǰӳ�䲻����֮ǰ��ӳ�䣬����ʧ��
        if (t[i] != s_map[s[i]])
          return false;
      } else {
        s_map[s[i]] = t[i];
      }
    }

    char s_set[128] = {0};
    /// ������t->s��ӳ���Ƿ���ȷ��������ֶ��һ��ӳ�䣬����ʧ��
    for (unsigned i = 0; i < 128; ++i) {
      const char c = s_map[i];
      if (c != 0) {
        if (s_set[c] == 1)
          return false;

        s_set[c] = 1;
      }
    }

    return true;
  }
};
} // namespace use_map
} // namespace s987