/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.54%)
 * Likes:    792
 * Dislikes: 0
 * Total Accepted:    84.2K
 * Total Submissions: 114.5K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result(0);
        backtrace(result, "", 0, 0, n);
        return result;
    }

    void backtrace(vector<string>& result, string s, int left, int right, int n)
    {
        if (left == n && right == n)
        {
            result.push_back(s);
            return;
        }
        if (left < n)
        {
            backtrace(result, s+'(', left + 1, right, n);
        }
        if (left > right)
        {
            backtrace(result, s+')',  left, right + 1, n);
        }
    }
};
// @lc code=end

