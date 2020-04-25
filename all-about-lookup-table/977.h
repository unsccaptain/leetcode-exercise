/**
 * ����set��ʹ��:��������Ľ���
 * https://leetcode-cn.com/explore/orignial/card/all-about-lockup-table/236/learn-to-use-set/977/
 * ֻ��Ҫ��һ������������ּ�¼��set�У��ж���һ������������ڲ���set��
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
				/// ��¼nums1�����г��ֵ�����
				for (auto i = 0;i < nums1.size();i++)
					ele_1.insert(nums1[i]);

				/// һ��nums2������nums1�г��ֹ������֣��ͼ�¼�������������ִ�nums1���Ƴ�
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