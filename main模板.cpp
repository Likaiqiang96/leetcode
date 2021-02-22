#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int len=sizeof(nums)/sizeof(int); //错误用法
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

void show_vector(vector<int>&vec)
{
    //auto it = vec.begin();
    vector<int>::iterator it =vec.begin();
    cout<<"---"<<endl;
    while(it != vec.end())
    {
        cout<< *it <<" ";
        it++;
    }
    cout<<endl;
    cout<<"---"<<endl;
}
//auto 一般不用，只用在比较简单的地方，直接写出变量的类型更加清晰易懂
void show_vector_auto(vector<int> &res)
{
    for (auto &i : res)//使用引用本来的值改变
    {
    i *= i;
    cout << i << " ";
    }
}
int main()
{
    Solution Solution1;
    vector<int> num_test{1,2,3};
    vector<int> res;
    res =Solution1.twoSum(num_test,3);
    show_vector(res);
    show_vector_auto(res);
    cout << "done" << endl;
    return 0;
}