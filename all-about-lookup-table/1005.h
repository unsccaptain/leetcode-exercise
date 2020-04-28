/**
 * �����ظ�Ԫ�� II
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/1005
 **/
#pragma once

#include <vector>
#include <unordered_map>
using namespace std;

namespace s1005 {
	namespace use_map {
		class Solution {
		public:
			bool containsNearbyDuplicate(vector<int>& nums, int k) {
				unordered_map<int, int> pos_map;
				for (int i = 0;i < nums.size();i++) {
					/// ��ȡnums[i]���һ�γ���λ��
					int& last_pos = pos_map[nums[i]];
					if (last_pos != 0) {
						/// ���һ��λ�ú͵�ǰλ�þ���
						unsigned distance = (i + 1) - last_pos;
						if (distance <= k) return true;
					}
					/// ���µ�ǰ�������һ�γ���λ�á�
					last_pos = i + 1;
				}
				return false;
			}
		};
	}
}