/**
 * 两个数组的交集 II
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/983
 * 先将两个数组排序，然后步进比较
 **/
#pragma once

#include <vector>
#include <algorithm>
using namespace std;

namespace s983 {
	namespace use_sort {
		/**
		 * @brief：排序方法
		 */
		class Solution {
		public:
			vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
				int index = 0;
				vector<int> ret;
				if (nums1.size() == 0 || nums2.size() == 0)
					return ret;
				sort(nums1.begin(), nums1.end());
				sort(nums2.begin(), nums2.end());
				for (int i = 0;i < nums1.size();++i) {
					for (int j = index;j < nums2.size();++j) {
						if (nums2[j] == nums1[i]) {
							ret.push_back(nums1[i]);
							index = j + 1;
							break;
						}
					}
				}
				return ret;
			}
		};
	}
}