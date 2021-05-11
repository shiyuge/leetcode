/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.84%)
 * Likes:    608
 * Dislikes: 0
 * Total Accepted:    87.8K
 * Total Submissions: 166.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        for(const char digit: digits) {
            result = expand(result, digit);
        }
        return result;
    }

    vector<string> grow(string original, string candidates) {
        vector<string> result;
        for(char new_digit: candidates) {
            stringstream ss;
            ss << original;
            ss << new_digit;
            result.emplace_back(ss.str());
        }
        return result;
    }

    vector<string> expand(vector<string>& input, char digit)
    {
        map<char, string> digit2chars = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "nmo"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string candidates = digit2chars[digit];
        
        if(input.size()==0) {
            return grow("", candidates);
        }

        vector<string> result;
        for(string s:input) {
            vector<string> a = grow(s, candidates);
            result.insert(result.end(), a.begin(), a.end());
        }
        
        return result;
    }
};
// @lc code=end

