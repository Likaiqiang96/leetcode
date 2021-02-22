//散列表实现状态机

#include <iostream>
#include <vector>
#include <string>
#include < unordered_map >
using namespace std;
class Automaton {
    string state = "start";//设定初始状态
    unordered_map<string, vector<string>> table = {
        {"start",     {"start", "signed", "in_number", "end"}},
        {"signed",    {"end",   "end",    "in_number", "end"}},
        {"in_number", {"end",   "end",    "in_number", "end"}},
        {"end",       {"end",   "end",     "end",      "end"}}
    };
    //状态标号判断程序
    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];//根据条件的标号进行状态转移
        if (state == "in_number") {
            ans = ans * 10 + c - '0'; //合成数字的常用方式 ，左移 ，加 ，这里是字符 ，所以 -‘0’
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);//这里的 - 是做了绝对值
        }
        else if (state == "signed")//上面计算出的是绝对值，这里负责判断正负
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str) //换成 &c 更合理
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};

//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main()
{
    Solution Sol;
    string s;
    cin >> s;
    cout << Sol.myAtoi(s) << endl;
   
    return 0;
}

//传统方法
#include <iostream>
#include <vector>
#include <string>
#include < unordered_map >
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int  ans = 0;
        int i = 0;
        int sign = 1;
        cout << str << "   : ";
        while (str[i] == ' '&& (i < str.size()))i++;
        if (str[i] =='-')
        {
            sign = -1;
        }
        if (str[i] == '+' ||str[i]=='-')
        {
            i++;
        }
        while (isdigit(str[i])&&( i<str.size() ))
        {
            //2147483647
            // int tmp = str[i]-'0'; //直接使用这种方式可以避开后面的问题
            if (ans > INT_MAX / 10 ||(ans ==INT_MAX/10 && (str[i] - '0')> 7))
            {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + (str[i] - '0');//必须加括号，否则运算过程会溢出
            //在leetcode上就出现了Line 23: Char 28: 
            //runtime error: signed integer overflow: 
            //2147483640 + 54 cannot be represented in type 'int' (solution.cpp)
            i++;
        }
        return sign > 0 ? ans : -ans;
    }
};

int main()
{
    Solution Sol;
    string s;
    //cin >> s;
    cout << INT_MAX << endl;;
    s = "-12345asb";
    cout << Sol.myAtoi(s) << endl;
    s = "12345asb";
    cout << Sol.myAtoi(s) << endl;
    s = "  12345 asb";
    cout << Sol.myAtoi(s) << endl;
    s = "a-12345asb";
    cout << Sol.myAtoi(s) << endl;
   
    s ="21474836460";
    cout << Sol.myAtoi(s) << endl;
    s = "2147483648";
    cout << Sol.myAtoi(s) << endl;
    s = "-2147483649";
    cout << Sol.myAtoi(s) << endl;
    return 0;
}