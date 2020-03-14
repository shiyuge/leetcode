/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.92%)
 * Likes:    1898
 * Dislikes: 0
 * Total Accepted:    175K
 * Total Submissions: 674.1K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(auto current=nums.begin(); current<nums.end(); current++) {
            if(*current>0) {
                break;
            }
            if(current>nums.begin() && *current==*(current-1)) {
                continue;
            }
            auto front = current + 1;
            auto rear = nums.end() - 1;
            while(front<rear) {
                if(*rear<0) {
                    break;
                }

                int sum = *current + *front + *rear;
                if(sum>0) {
                    rear--;
                }
                else if(sum<0) {
                    front++;
                }
                else {
                    vector<int> tuple{*current, *front, *rear};
                    result.push_back(tuple);
                    auto original_front = front;
                    while(front<rear&&*original_front==*front) {
                        front++;
                    }

                    auto original_rear = rear;
                    while(front<rear&&*original_rear==*rear) {
                        rear--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

