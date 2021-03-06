#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

说明:
所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	/*
		方法一：
		将第一个字符串设为最长公共前缀 res，之后从第二个字符串 strs[1] 开始，
		逐个与 res 两两比较找出最长公共前缀，再用新的公共前缀更新 res 值。
		*/
        if (strs.empty())
            return "";

        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            if (res == "")
                break;
            res = common(res, strs[i]);
        }
        return res;
    }

    string common(string s1, string s2)
    {
        if (s1.empty() || s2.empty())
            return "";
        int length = s1.size() > s2.size() ? s2.size() : s1.size();
        int i = 0;
        for (; i < length; ++i)
        {
            if (s1[i] != s2[i])
                break;
        }
        string tmp(s1.begin(), s1.begin() + i);
        return tmp;
    }

    /*
	方法二：
	逐位比较
	*/
};


