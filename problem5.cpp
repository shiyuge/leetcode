/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.85%)
 * Likes:    1853
 * Dislikes: 0
 * Total Accepted:    203.8K
 * Total Submissions: 705.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int left_index = 0;
        int right_index = 0;
        for(int i=0; i<s.size(); i++) {
            // i = 1
            for(int k=0;;k++) {
                const int left = i-k;
                const int right = i+k;
                if(left<0 || right>s.size() || s[left]!=s[right]){
                    break;
                }
                else {
                    if(right-left > right_index - left_index) {
                        left_index = left;
                        right_index = right;
                    }
                }
            }
            for(int k=0;;k++) {
                const int left = i-k;
                const int right = i+k+1;
                if(left<0 || right>s.size() || s[left]!=s[right]) {
                    break;
                }
                else {
                    if(right-left > right_index - left_index) {
                        left_index = left;
                        right_index = right;
                    }
                }
            }
        }
        return string(s.begin()+left_index, s.begin()+right_index+1);
    }
};
// @lc code=end

