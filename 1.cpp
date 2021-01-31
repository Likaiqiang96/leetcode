/***********************************
刷第一题的感受：
基础都不会，vector 不会用，返回都不会

教训：
	学习 vector  STL库 
	（会定义、会增删改查、知道长度）
	（ ++i  和 i++ 在 for循环中的作用是一样的， i++
	在循行的过程中会定义临时变量，所以使用++i 的运行效率更高
	 关于 for 循环的知识点，https://www.cnblogs.com/Paul-Yellow/p/10900475.html
**********************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int len=sizeof(nums)/sizeof(int); //数据量小没问题，但是要像鲁棒性强，用库函数
        int len =nums.size();//
        for(int i=0;i<len;++i)
        {
            for(int j=i+1;j<len;++j)
            {
                if(nums[i]+nums[j]==target)
                {
                     return {i, j}; //使用vector返回数据
                }
            }
        }
        return {};
    }
};