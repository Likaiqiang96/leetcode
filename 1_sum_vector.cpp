/***********************************
刷第一题的感受：
基础都不会，vector 不会用，返回都不会

教训：
	学习 vector  STL库 
	（会定义、会增删改查、知道长度）
	（ ++i  和 i++ 在 for循环中的作用是一样的， i++
	在循行的过程中会定义临时变量，所以使用++i 的运行效率更高
	 关于 for 循环的知识点，https://www.cnblogs.com/Paul-Yellow/p/10900475.html


    遇到的问题
    Q:  sizeof(nums)/sizeof(int) 为什么不行？  
    A:  vector是容器，是一个数据结构，不是数组
        https://blog.csdn.net/zcsylj/article/details/7857009
    Q:vector 与数组的差异 
    A:https://www.zhihu.com/question/21760520/answer/914049558
    
    Q:vector 的输出
    A:
**********************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //int len=sizeof(nums)/sizeof(int); //数据量小没问题？但是要像鲁棒性强，用库函数
        // 一开始以为 int 不够 ，改成 long long 也不行，最后的测试用例是三位数
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

//vector的显示函数
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