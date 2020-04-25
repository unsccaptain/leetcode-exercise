/**
 * 集合set的使用:两个数组的交集
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/977/
 * 只需要将一个数组里的数字记录在set中，判断另一个数组的数字在不在set里
 **/
#pragma once

#include <vector>
#include <set>
using namespace std;

namespace s977 {
	namespace use_set {
		class Solution {
		public:
			vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
				vector<int> ret;
				set<int> ele_1;
				/// 记录nums1中所有出现的数字
				for (auto i = 0;i < nums1.size();i++)
					ele_1.insert(nums1[i]);

				/// 一但nums2中命中nums1中出现过的数字，就记录下来并将该数字从nums1中移除
				for (auto i = 0;i < nums2.size();i++) {
					set<int>::iterator it;
					if ((it = ele_1.find(nums2[i])) != ele_1.end()) {
						ret.push_back(nums2[i]);
						ele_1.erase(it);
					}
				}

				return ret;
			}
		};
	}
}