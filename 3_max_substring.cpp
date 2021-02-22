class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> windows;
        int left = 0, right = 0;
        int length = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            windows[c]++;
            // windows not valid
            // while (!isValid(windows)) {      //此处是自己写的，考虑是遍历hash表来找到是否每个元素second都不大于1,该操作耗时
            while (windows[c] > 1) {            // 替换如下，每次读入的时候就对该读入的字符进行判断，判断其是否会导致hash值大于1
                char d = s[left];
                left++;
                windows[d]--;
                
            }
            if (right - left > length)
                length = right - left;
        }
        return length;
    }

    bool isValid(unordered_map<char, int> tb) {
        for(auto iter = tb.begin(); iter != tb.end(); ++iter)
            if(iter->second > 1)
                return false;
        return true;
    }
};