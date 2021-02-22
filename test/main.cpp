#include <iostream>
#include <vector>
#include <string>
#include < unordered_map >
using namespace std;


// Definition for singly-linked list.
struct ListNode {
   int val;
   //next指针
   ListNode *next;
   //重载 
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//第一问：倒序输出
//第二问：正序输出 -- 链表反转
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //新建一个单链表，声明头指针和尾指针，其中tail用于尾插
        ListNode* head = nullptr, * tail = nullptr;
        //进位标志位
        int carry = 0;
        //单链表的值不为空
        while (l1 || l2) {
            //有值就取出单链表的值，没有就为0
            //这步处理是为了处理两个链表长度不同的情况
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            //带进位加法
            int sum = n1 + n2 + carry;
            if (!head) {
                //创建新的单链表
                head = tail = new ListNode(sum % 10);
            }
            else {
                //尾插法插入新值
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            //若链表不到表尾，则指向下一个结点
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        //全部扫描结束后，还有进位，则再新建一个结点存放进位值
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        //返回存放结果的新单链表的头指针
        return head;
    }
};

//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

//单链表的显示方法
void show_list(ListNode *L)
{
    if (L == nullptr)cout << "Empty List" << endl;
    while (L!=nullptr)
    {
        cout << L->val;
        L = L->next;
    }
    cout << endl;
}
//list append function
//append val into List
//尾插法 实现列表结点append
bool List_append(ListNode &tail,int val)
{
    tail = tail->next;
    return tail->next = new ListNode(val);
    tail = tail->next;
}
//回收内存
void delete_List(ListNode* L)
{
    if (L == nullptr)cout << "Empty List" << endl;
    while (L)
    {
       //delete(L->val);
        L = L->next;
    }
    
}
int main()
{
    Solution Sol;
    ListNode* head = nullptr, * tail = nullptr;
    //使用的是new，故地址不连续，在自己程序运行后记得 delete
    head = tail = new ListNode(1);
    tail->next  = new ListNode(2);
    tail = tail->next;
    tail->next = new ListNode(3);
    List_append(tail, 4);
    List_append(tail, 5);
    List_append(tail, 6);
    //调用的时候把头指针传入即可
    show_list(head);
    ListNode* l3 = Sol.addTwoNumbers(head, head);
    
    show_list(l3);
    
    return 0;
}