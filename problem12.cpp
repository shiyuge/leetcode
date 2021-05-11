/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (62.84%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    72.7K
 * Total Submissions: 115.6K
 * Testcase Example:  '3'
 *
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: "III"
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "IV"
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: "IX"
 * 
 * 示例 4:
 * 
 * 输入: 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        map<int, string> thousand_map = {
            {1, "M"},
            {2, "MM"},
            {3, "MMM"},
        };
        map<int, string> hundred_map = {
            {1, "C"},
            {2, "CC"},
            {3, "CCC"},
            {4, "CD"},
            {5, "D"},
            {6, "DC"},
            {7, "DCC"},
            {8, "DCCC"},
            {9, "CM"},
        };
        map<int, string> teen_map = {
            {1, "X"},
            {2, "XX"},
            {3, "XXX"},
            {4, "XL"},
            {5, "L"},
            {6, "LX"},
            {7, "LXX"},
            {8, "LXXX"},
            {9, "XC"},
        };
        map<int, string> digit_map = {
            {1, "I"},
            {2, "II"},
            {3, "III"},
            {4, "IV"},
            {5, "V"},
            {6, "VI"},
            {7, "VII"},
            {8, "VIII"},
            {9, "IX"},
        };


        int digit = num % 10;
        num = num/10;

        int teen = num % 10;
        num = num/10;

        int hundred = num % 10;
        num = num/10;

        int thousand = num % 10;
        num = num/10;


        stringstream ss;
        auto iter = thousand_map.find(thousand);
        if(iter!=thousand_map.end()) {
            ss << iter->second;
        }
        iter = hundred_map.find(hundred);
        if(iter!=hundred_map.end()) {
            ss << iter->second;
        }
        iter = teen_map.find(teen);
        if(iter!=teen_map.end()) {
            ss << iter->second;
        }
        iter = digit_map.find(digit);
        if(iter!=digit_map.end()) {
            ss << iter->second;
        }
        return ss.str();

    }
};
// @lc code=end

