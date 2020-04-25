/**
 * 根据字符出现频率排序
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/989
 **/
#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

namespace s989 {
	namespace use_map {
		/**
		 * @brief: 字典方法
		 */
		class Solution {
		public:
			string frequencySort(string s) {
				unsigned count_map[128] = { 0 };
				for (auto c : s) {
					unsigned old = count_map[c];
					++old;
					old = old | (((unsigned)c) << 16);
					count_map[c] = old;
				}

				sort(count_map, count_map + 128, [](const unsigned& a, const unsigned& b)->bool {
					if ((a & 0xffff) > (b & 0xffff))
						return true;
					return false;
				});

				int count = 0;
				for (unsigned i = 0;i < 128; ++i) {
					unsigned value = count_map[i];
					if (value == 0) break;
					for (unsigned j = 0;j < (value & 0xffff);++j) {
						s[count++] = value >> 16;
					}
				}

				return s;
			}
		};
	}
}