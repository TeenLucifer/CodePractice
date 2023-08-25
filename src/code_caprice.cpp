/*------------------------------------------------------------------------------
 * @file    CODE_CAPRICE.CPP
 * @author  t-rex 
 * @date    2023/08/08 20:18:12
 * @brief   THIS FILE PROVIDES ALL THE FIRMWARE FUNCTIONS.
 * -----------------------------------------------------------------------------
 * @attention 
 
 * THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE 
 * CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE 
 * TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH 
 * HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN 
 * CONNECTION WITH PRODUCTS MADE BY CUSTOMERS. 
 * 
 * <H2><CENTER>&COPY; COPYRIGHT MINDMOTION </CENTER></H2> 
------------------------------------------------------------------------------*/

/* Define to prevent recursive inclusion  ------------------------------------*/
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <mutex>
#include <ostream>
#include <pthread.h>
#include <queue>
#include <random>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define _CODE_CAPRICE_C_

/* Files includes  -----------------------------------------------------------*/
#include "headers.h"
#include "code_caprice.h"

/*----------------------------------------------------------------------------*/

/*数组*/
int CodeCaprice::question704(std::vector<int>& nums, int target)//二分查找
{
    int res = -1;
    int left = 0;
    int right = nums.size() - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else if(nums[mid] < target)
        {
            left = mid + 1;
        }
        else if(nums[mid] == target)
        {
            res = mid;
            break;
        }
    }

    return res;
}

int CodeCaprice::question27(std::vector<int>& nums, int val)//移除元素
{
    int ptr_slow = 0;
    int ptr_fast = ptr_slow;

    for(; ptr_fast < nums.size(); ++ptr_fast)
    {
        if(nums[ptr_fast] != val)
        {
            nums[ptr_slow++] = nums[ptr_fast];
        }
    }

    return ptr_slow;
}

std::vector<int> CodeCaprice::question977(std::vector<int>& nums)//有序数组的平方
{
    //从两侧开始向中间搜索
    std::vector<int> res(nums.size(), 0);
    int left_ptr = 0;
    int right_ptr = nums.size() - 1;
    int i = nums.size() - 1;

    for(; left_ptr <= right_ptr;)
    {
        int left_square = nums[left_ptr] * nums[left_ptr];
        int right_square = nums[right_ptr] * nums[right_ptr];

        if(left_square > right_square)
        {
            res[i--] = left_square;
            left_ptr++;
        }
        else
        {
            res[i--] = right_square;
            right_ptr--;
        }
    }

    return res;
}

int CodeCaprice::question209(int target, std::vector<int>& nums)//长度最小的子数组
{
    int ptr_left = 0;
    int ptr_right = -1;
    int sum = 0;
    int min_len = std::numeric_limits<int>::max();

    while(ptr_right < int(nums.size()))
    {
        if(ptr_right == int(nums.size() - 1) && sum < target)
        {
            break;
        }

        if(sum < target)
        {
            ptr_right++;
            sum = sum + nums[ptr_right];
        }
        else if(sum >= target)
        {
            min_len = std::min(min_len, ptr_right - ptr_left + 1);
            sum = sum - nums[ptr_left];
            ptr_left++;
        }
    }

    return min_len == std::numeric_limits<int>::max() ? 0 : min_len;
}

std::vector<std::vector<int>> CodeCaprice::question59(int n)//螺旋矩阵II
{
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    if(n % 2 == 1)
    {
        result[n / 2][n / 2] = n * n;
    }
    int circles = n / 2;
    int num = 0;
    for(int i = 0; i < circles; ++i)
    {//从外到内，一圈一圈
        for(int j = 0; j < n - (2 * i) - 1; ++j)
        {//每圈从左上到右上
            result[i][j + i] = ++num;
        }
        for(int j = 0; j < n - (2 * i) - 1; ++j)
        {//每圈从右上到右下
            result[j + i][n - i - 1] = ++num;
        }
        for(int j = 0; j < n - (2 * i) - 1; ++j)
        {//每圈从右下到左下
            result[n - i - 1][n - j - i - 1] = ++num;
        }
        for(int j = 0; j < n - (2 * i) - 1; ++j)
        {//每圈从左下到左上
            result[n - j - i - 1][i] = ++num;
        }
    }

    return result;
}

ListNode* CodeCaprice::question203(ListNode* head, int val)
{
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* cur_ptr = dummy_head;

    while(cur_ptr->next != nullptr)
    {
        if(cur_ptr->next->val == val)
        {
            cur_ptr->next = cur_ptr->next->next;
        }
        else
        {
            cur_ptr = cur_ptr->next;
        }
    }
    return dummy_head->next;
}

namespace code_caprice_question707 
{
class MyLinkedList
{
private:
    ListNode* dummy_head;
    int node_num;

public:
    MyLinkedList() 
    {
        dummy_head = new ListNode();
        node_num = 0;
    }

    int get(int index)
    {
        ListNode* node = dummy_head->next;
        if(index < 0 || index >= node_num)
        {
            return -1;
        }
        while(index--)
        {
            node = node->next;
        }

        return node->val;
    }

    void addAtHead(int val)
    {
        ListNode* new_node = new ListNode(val);
        new_node->next = dummy_head->next;
        dummy_head->next = new_node;
        node_num++;
    }

    void addAtTail(int val)
    {
        ListNode* node = dummy_head;
        ListNode* new_node = new ListNode(val);
        while(node != nullptr && node->next != nullptr) 
        {
            node = node->next;
        }
        node->next = new_node;
        node_num++;
    }

    void addAtIndex(int index, int val)
    {
        ListNode* node = dummy_head;
        ListNode* new_node = new ListNode(val);
        if(index < 0 || index > node_num)
        {
            return;
        }
        while(index--)
        {
            node = node->next;
        }
        new_node->next = node->next;
        node->next = new_node;
        node_num++;
    }

    void deleteAtIndex(int index)
    {
        ListNode* node = dummy_head;
        ListNode* node_del = nullptr;
        if(index < 0 || index >= node_num)
        {
            return;
        }
        while(index--)
        {
            node = node->next;
        }
        node_del = node->next;
        node->next = node->next->next;
        delete node_del;
        node_del = nullptr;
        node_num--;
    }
};
}

ListNode* CodeCaprice::question206(ListNode* head)
{
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* cur_node = dummy_head->next;
    ListNode* pre_node = nullptr;

    while(cur_node != nullptr)
    {
        ListNode* next_node = cur_node->next;
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
    }
    dummy_head->next = pre_node;

    return dummy_head->next;
}

ListNode* CodeCaprice::question24(ListNode* head)//两两交换链表中的节点
{
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* cur_node = dummy_head;

    while(cur_node->next != nullptr && cur_node->next->next != nullptr)
    {
        ListNode* tmp_node = cur_node->next->next->next;
        cur_node->next->next->next = cur_node->next;
        cur_node->next = cur_node->next->next;
        cur_node->next->next->next = tmp_node;
        cur_node = cur_node->next->next;
    }

    return dummy_head->next;
}

ListNode* CodeCaprice::question19(ListNode* head, int n)//删除链表的倒数第n个元素
{
    //用双指针，fast指针领先slow指针n步，然后两个开始跑，fast到末尾的时候，slow在倒数第n-1个
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* ptr_slow = dummy_head;
    ListNode* ptr_fast = dummy_head;

    while(n--)
    {
        ptr_fast = ptr_fast->next;
    }

    while(ptr_fast->next != nullptr)
    {
        ptr_fast = ptr_fast->next;
        ptr_slow = ptr_slow->next;
    }
    ptr_slow->next = ptr_fast->next;
    ptr_fast->next = nullptr;
    delete ptr_fast;
    ptr_fast = nullptr;

    return dummy_head->next;
}

ListNode* CodeCaprice::question160(ListNode* head1, ListNode* head2)
{
    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;
    int node_list1_len = 0;
    int node_list2_len = 0;

    while(ptr1 != nullptr)
    {
        node_list1_len++;
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr)
    {
        node_list2_len++;
        ptr2 = ptr2->next;
    }

    ptr1 = head1;
    ptr2 = head2;
    if(node_list1_len > node_list2_len)
    {
        int cnt = node_list1_len - node_list2_len;
        while(cnt--)
        {
            ptr1 = ptr1->next;
        }
    }
    else
    {
        int cnt = node_list2_len - node_list1_len;
        while(cnt--)
        {
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != nullptr)
    {
        if(ptr1 == ptr2)
        {
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

ListNode* CodeCaprice::question142(ListNode* head)
{
    ListNode* ptr_slow = head;
    ListNode* ptr_fast = head;

    while(ptr_fast != nullptr && ptr_fast->next != nullptr && ptr_fast->next->next != nullptr)
    {
        ptr_slow = ptr_slow->next;
        ptr_fast = ptr_fast->next->next;
        if(ptr_slow == ptr_fast)
        {
            ListNode* ptr_start = head;
            while(ptr_start != ptr_slow)
            {
                ptr_slow = ptr_slow->next;
                ptr_start = ptr_start->next;
            }
            return ptr_slow;
        }
    }
    return nullptr;
}

/*哈希表*/
bool CodeCaprice::question242(std::string s, std::string t)//有效字母异位词
{
    std::unordered_map<char, int> map;
    for(int i = 0; i < s.size(); ++i)
    {
        map[s[i]]++;
    }
    for(int i = 0; i < t.size(); ++i)
    {
        map[t[i]]--;
    }
    for(int i = 0; i < 26; ++i)
    {
        if(map[char('a' + i)] != 0)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> CodeCaprice::question349(std::vector<int>& nums1, std::vector<int>& nums2)//两个数组的交集
{
    //使用unordered_set不会让数据重复
    std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());
    std::unordered_set<int> result;

    for(auto num : nums2)
    {
        if(nums1_set.find(num) != nums1_set.end())
        {
            result.insert(num);
        }
    }

    return std::vector<int>(result.begin(), result.end());
}

bool CodeCaprice::question202(int n)//快乐数
{
    bool res;
    int num = n;
    int sum = 0;
    std::unordered_set<int> set;
    
    while(sum != 1)
    {
        sum = 0;
        while(num > 0)
        {
            int bit = num % 10;
            sum = sum + bit * bit;
            num = num / 10;
        }
        if(sum == 1)
        {
            res = true;
            break;
        }

        if(set.find(sum) != set.end())
        {
            res = false;
            break;
        }
        else
        {
            set.insert(sum);
        }
        num = sum;
    }

    return res;
}


std::vector<int> CodeCaprice::question1(std::vector<int>& nums, int target)//两数之和
{
    std::unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); ++i)
    {
        auto iter = map.find(target - nums[i]);
        if(iter != map.end())
        {
            return {iter->second, i};
        }
        map.insert(std::pair<int, int>(nums[i], i));
    }
    return {};
}


int CodeCaprice::question454(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4)//四数相加II
{
    int res = 0;
    std::unordered_map<int, int> map;

    for(int i = 0; i < nums1.size(); ++i)
    {
        for(int j = 0; j < nums2.size(); ++j)
        {
            map[nums1[i] + nums2[j]]++;
        }
    }
    for(int i = 0; i < nums3.size(); ++i)
    {
        for(int j = 0; j < nums4.size(); ++j)
        {
            if(map.find(-nums3[i] - nums4[j]) != map.end())
            {
                res = res + map[-nums3[i] - nums4[j]];
            }
        }
    }
    return res;
}


bool CodeCaprice::question383(std::string ransomNote, std::string magazine)//赎金信
{
    std::unordered_map<char, int> map;

    for(int i = 0; i < magazine.size(); ++i)
    {
        map[magazine[i]]++;
    }
    for(int i = 0; i < ransomNote.size(); ++i)
    {
        if(--map[ransomNote[i]] < 0)
        {
            return false;
        }
    }

    return true;
}


std::vector<std::vector<int>> CodeCaprice::question15(std::vector<int>& nums)//三数之和
{
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > 0)
        {
            return result;
        }

        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;
        while(left < right)
        {
            if(nums[left] + nums[right] > -nums[i])
            {
                right--;
            }
            else if(nums[left] + nums[right] < -nums[i])
            {
                left++;
            }
            else
            {
                result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                while(right > left && nums[right] == nums[right - 1])
                {
                    right--;
                }
                while(right > left && nums[left] == nums[left + 1])
                {
                    left++;
                }
                left++;
                right--;
            }
        }
    }

    return result;
}


std::vector<std::vector<int>> CodeCaprice::question18(std::vector<int>& nums, int target)//四数之和
{
    //基本需要遍历，用双指针、剪枝等减轻计算次数
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] > target && nums[i] >= 0)
        {
            break;
        }
        if(i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        for(int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
            {
                break;
            }
            if(j > i + 1 && nums[j] == nums[j - 1])
            {
                continue;
            }
            int sum = nums[i] + nums[j];
            int left = j + 1;
            int right = nums.size() - 1;

            while(left < right)
            {
                if((long) nums[left] + nums[right] > (long) -sum + target)
                {
                    right--;
                }
                else if((long) nums[left] + nums[right] < (long) -sum + target)
                {
                    left++;
                }
                else
                {
                    result.push_back(std::vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                    while(right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while(right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    left++;
                    right--;
                }
            }
        }
    }
    return result;
}

void CodeCaprice::question344(std::vector<char>& str)//翻转字符串
{
    int ptr_left = 0;
    int ptr_right = str.size() - 1;

    while(ptr_left < ptr_right)
    {
        char ch = str[ptr_left];
        str[ptr_left] = str[ptr_right];
        str[ptr_right] = ch;
        ptr_left++;
        ptr_right--;
    }
}

std::string CodeCaprice::question541(std::string str, int k)//翻转字符串II
{
    int n = str.size() / (2 * k);
    int mod = str.size() % (2 * k);
    std::string result(str.begin(), str.end());
    for(int i = 0; i < n; ++i)
    {
        int ptr_left = i * 2 * k;
        int ptr_right = (i + 1) * 2 * k - k - 1;
        while(ptr_left < ptr_right)
        {
            char ch = result[ptr_left];
            result[ptr_left] = result[ptr_right];
            result[ptr_right] = ch;
            ptr_left++;
            ptr_right--;
        }
    }
    if(mod <= k)
    {
        int ptr_left = n * 2 * k;
        int ptr_right = ptr_left + mod - 1;
        while(ptr_left < ptr_right)
        {
            char ch = result[ptr_left];
            result[ptr_left] = result[ptr_right];
            result[ptr_right] = ch;
            ptr_left++;
            ptr_right--;
        }
    }
    else
    {
        int ptr_left = n * 2 * k - 1;
        int ptr_right = ptr_left + k;
        while(ptr_left < ptr_right)
        {
            char ch = result[ptr_left];
            result[ptr_left] = result[ptr_right];
            result[ptr_right] = ch;
            ptr_left++;
            ptr_right--;
        }
    }

    return result;
}


std::string CodeCaprice::question5(std::string str)//替换空格
{
    std::string result;
    int ptr = 0;

    while(ptr < str.size())
    {
        if(str[ptr] == ' ')
        {
            result = result + "%20";
        }
        else
        {
            result = result + str[ptr];
        }
        ptr++;
    }

    return result;
}

std::string CodeCaprice::question151(std::string str)//翻转字符串中的单词
{
    std::vector<std::string> strs;
    std::string result;
    int ptr_left = 0;
    int ptr_right = 0;
    
    //先去掉前面的空格
    while(str[ptr_left] == ' ')
    {
        ptr_left++;
        ptr_right++;
    }

    while(ptr_right < str.size())
    {
        //找到空格
        while(str[ptr_right] != ' ' && ptr_right < str.size())
        {
            ptr_right++;
        }
        //储存字母子串
        strs.push_back(str.substr(ptr_left, ptr_right - ptr_left));
        //找到空格字符
        while(str[ptr_right] == ' ' && ptr_right < str.size())
        {
            ptr_right++;
        }
        ptr_left = ptr_right;
    }

    result = result + strs[strs.size() - 1];
    for(int i = strs.size() - 1 - 1; i >= 0; --i)
    {
        result = result + ' ' + strs[i];
    }

    return result;
}


std::string CodeCaprice::question58(std::string str, int k)//左旋字符串
{
    std::string str1 = str.substr(0, k);
    std::string str2 = str.substr(k, str.size() - k);

    return str2 + str1;
}

//这里两个KMP方法的题目
int CodeCaprice::question28(std::string haystack, std::string needle)//找出字符串中第一个匹配项的下标
{
    //标准KMP方法做的时候第一步找前缀表，第二步通过前缀表找出字符串中匹配的子串
    //其实两步都是同一个模式，第二步中相当于把needle和haystack拼起来，然后一个指针从needle开始，另一个从haystack开始，重复第一步中找前缀表的过程
    //第一步中找前缀表的过程：
    //0和j组成的子串能够表示i前面的子串
    //因此每次回退，其实是一个在已搜索过的字符串中找子串的过程

    //找next数组
    std::vector<int> next(needle.size(), 0);
    int j = 0;

    for(int i = 1; i < needle.size(); ++i)
    {
        while(j > 0 && needle[j] != needle[i])//字符没有匹配上
        {
            //回退
            j = next[j - 1];
        }
        if(needle[j] == needle[i])
        {
            j++;
        }
        next[i] = j;
    }

    //next数组与haystack匹配
    j = 0;
    for(int i = 0; i < haystack.size(); ++i)
    {
        while(j > 0 && needle[j] != haystack[i])
        {
            j = next[j - 1];
        }
        if(needle[j] == haystack[i])
        {
            j++;
        }
        if(j == needle.size())
        {
            return (i - needle.size() + 1);
        }
    }
    return -1;
}

bool CodeCaprice::question459(std::string str)//给定一个非空的字符串，判断其是否可以通过由它一个子串重复多次构成
{
    std::vector<int> next(str.size(), 0);
    int j = 0;
    
    for(int i = 1; i < str.size(); ++i)
    {
        while(j > 0 && str[j] != str[i])
        {
            j = next[j - 1];
        }
        if(str[j] == str[i])
        {
            j++;
        }
        next[i] = j;
    }
    
    if(next[str.size() - 1] > 0 && (str.size() % (str.size() - next[str.size() - 1]) == 0))
    {
        return true;
    }

    return false;
}

/*栈与队列*/

namespace code_caprice_question232
{
class MyQueue
{
private:
    std::stack<int> stack_in;
    std::stack<int> stack_out;

public:
    MyQueue(){}
    ~MyQueue(){}

    void push(int x)
    {
        stack_in.push(x);
    }

    int pop()
    {
        int result = -1;
        if(stack_out.empty())
        {
            while(!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        result = stack_out.top();
        stack_in.pop();
        return result;
    }

    int peek()
    {
        if(stack_out.empty())
        {
            while(!stack_in.empty())
            {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        return stack_out.top();
    }

    bool empty()
    {
        return stack_in.empty() && stack_out.empty();
    }
};
}

namespace code_caprice_question225
{
class MyStack
{
private:
    std::queue<int> que;
public:
    MyStack(){}
    ~MyStack(){}

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int que_size = que.size() - 1;
        int result = -1;

        while(que_size--)
        {
            que.push(que.front());
            que.pop();
        }
        result = que.front();
        que.pop();

        return result;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }
};
}


bool CodeCaprice::question20(std::string str)//有效的括号
{
    if(str.size() % 2 != 0) return false;
    std::stack<char> stk;

    for(char ch : str)
    {
        if(ch == '(') stk.push(')');
        else if(ch == '[') stk.push(']');
        else if(ch == '{') stk.push('}');
        //下面是找到右括号的情况
        else if(stk.empty() || stk.top() != ch) return false;//这里栈为空表示没有对应的左括号；栈不为空但是栈顶元素不是对应的左括号表示括号不匹配
        else stk.pop();//栈不为空且栈顶元素是对应的左括号，表示匹配，弹出栈顶元素
    }
    return stk.empty();//最后栈为空表示所有的左括号都匹配上了；若栈不为空表示有多余的左括号
}

std::string CodeCaprice::question1047(std::string str)//删除字符串中的所有相邻重复项
{
    std::string result;
    std::stack<char> stk;
    for(char ch : str)
    {
        if(!stk.empty() && stk.top() == ch) stk.pop();
        else stk.push(ch);
    }
    while(!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int CodeCaprice::question150(std::vector<std::string>& tokens)//逆波兰表达式求值
{//什么是逆波兰表达式：后缀表达式，运算符在操作数的后面
    std::stack<std::string> stk;
    for(std::string str : tokens)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/")
        {
            std::string str_num1 = "";
            std::string str_num2 = "";
            long long num1 = 0;
            long long num2 = 0;
            long long num_tmp = 0;
            std::string str_num_tmp = "";
            str_num1 = stk.top();
            stk.pop();
            str_num2 = stk.top();
            stk.pop();
            //str2num
            int i = 0;
            if(str_num1[0] == '-') i = 1;
            for(; i < str_num1.size(); ++i)
            {
                num1 = num1 + str_num1[i] - '0';
                if(i != str_num1.size() - 1) num1 = num1 * 10;
            }
            if(str_num1[0] == '-') num1 = -num1;

            i = 0;
            if(str_num2[0] == '-') i = 1;
            for(; i < str_num2.size(); ++i)
            {
                num2 = num2 + str_num2[i] - '0';
                if(i != str_num2.size() - 1) num2 = num2 * 10;
            }
            if(str_num2[0] == '-') num2 = -num2;

            if(str == "+") num_tmp = num2 + num1;
            else if(str == "-") num_tmp = num2 - num1;
            else if(str == "*") num_tmp = num2 * num1;
            else if(str == "/") num_tmp = num2 / num1;
            //num2str
            long long num_ = std::abs(num_tmp);
            while(num_ > 0)
            {
                str_num_tmp.push_back((num_ % 10) + '0');
                num_ = num_ / 10;
            }
            if(num_tmp < 0) str_num_tmp.push_back('-');
            std::reverse(str_num_tmp.begin(), str_num_tmp.end());
            stk.push(str_num_tmp);
        }
        else
            stk.push(str);
    }
    std::string str_final = "";
    long long num_final = 0;
    if(stk.size() == 1)
    {
        //str2num
        str_final = stk.top();

        int i = 0;
        if(str_final[0] == '-') i = 1;
        for(; i < str_final.size(); ++i)
        {
            num_final = num_final + str_final[i] - '0';
            if(i != str_final.size() - 1) num_final = num_final * 10;
        }       
        if(str_final[0] == '-') num_final = -num_final;
    }
    return num_final;
}

std::vector<int> CodeCaprice::question239(std::vector<int>& nums, int k)//滑动窗口最大值
{
    std::vector<int> result;
    std::deque<int> que;

    //que中存储的是nums中的下标，que中的下标对应的nums中的值是递减的
    for(int i = 0; i < nums.size(); ++i)
    {
        while(!que.empty() && nums[que.back()] < nums[i])//这里保证了que中的下标对应的nums中的值是递减的
        {
            que.pop_back();
        }
        que.push_back(i);
        if(que.front() == i - k)//这里表示在滑动窗口范围内，没有比que.frone()表示的下标大的数了，但是滑动窗口需要走，手动把front更新掉
        {
            que.pop_front();
        }
        if(i >= k - 1)
        {
            result.push_back(nums[que.front()]);
        }
    }

    return result;
}


std::vector<int> CodeCaprice::question347(std::vector<int>& nums, int k)//第k个高频元素
{
    std::unordered_map<int, int> map;
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> result;
    for(int i = 0; i < nums.size(); ++i)
    {
        map[nums[i]]++;
    }
    for(std::pair<int, int> pair : map)
    {
        pairs.push_back(pair);
    }
    std::sort(pairs.begin(), pairs.end(), [](const std::pair<int, int>& pair1, const std::pair<int, int>& pair2){return pair1.second > pair2.second;});
    for(int i = 0; i < k; ++i)
    {
        result.push_back(pairs[i].first);
    }
    return result;
}

void CodeCaprice::helper144(TreeNode* root, std::vector<int>& result)
{
    if(root == nullptr)
        return;
    result.push_back(root->val);
    if(root->left != nullptr) helper144(root->left, result);
    if(root->right != nullptr) helper144(root->right, result);
}

std::vector<int> CodeCaprice::question144(TreeNode* root)//二叉树的前序遍历
{
    std::vector<int> result;
    helper144(root, result);
    return result;
}

void CodeCaprice::helper145(TreeNode* root, std::vector<int>& result)
{
    if(root == nullptr)
        return;
    if(root->left != nullptr) helper145(root->left, result);
    if(root->right != nullptr) helper145(root->right, result);
    result.push_back(root->val);
}

std::vector<int> CodeCaprice::question145(TreeNode* root)//二叉树的后序遍历
{
    std::vector<int> result;
    helper145(root, result);
    return result;
}

void CodeCaprice::helper94(TreeNode* root, std::vector<int>& result)
{
    if(root == nullptr)
        return;
    if(root->left != nullptr) helper94(root->left, result);
    result.push_back(root->val);
    if(root->right != nullptr) helper94(root->right, result);
}

std::vector<int> CodeCaprice::question94(TreeNode* root)//二叉树的中序遍历
{
    std::vector<int> result;
    helper94(root, result);
    return result;
}


std::vector<std::vector<int>> CodeCaprice::question102(TreeNode* root)//二叉树的层序遍历
{
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> que;
    if(root == nullptr)
        return result;
    que.push(root);
    while(!que.empty())
    {
        int n = que.size();
        std::vector<int> level;
        for(int i = 0; i < n; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            level.push_back(node->val);
            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

void CodeCaprice::helper226(TreeNode* root)
{
    if(root == nullptr)
        return;
    TreeNode* tree_left = root->left;
    TreeNode* tree_right = root->right;
    root->left = tree_right;
    root->right = tree_left;
    helper226(root->left);
    helper226(root->right);
}

TreeNode* CodeCaprice::question226(TreeNode* root)//翻转二叉树
{
    helper226(root);
    return root;
}

bool CodeCaprice::helper101(TreeNode* tree_left, TreeNode* tree_right)
{
    if(tree_left == nullptr && tree_right == nullptr) return true;
    if(tree_left == nullptr && tree_right != nullptr) return false;
    if(tree_left != nullptr && tree_right == nullptr) return false;
    if(tree_left->val != tree_right->val) return false;

    bool res1 = helper101(tree_left->left, tree_right->right);
    bool res2 = helper101(tree_left->right, tree_right->left);
    if(res1 == true && res2 == true) return true;

    return false;
}

bool CodeCaprice::question101(TreeNode* root)//对称二叉树
{
    return helper101(root->left, root->right);
}

int CodeCaprice::helper104(TreeNode* root)
{
    if(root == nullptr) return 0;
    int depth_left = helper104(root->left);
    int depth_right = helper104(root->right);
    int depth = 1 + std::max(depth_left, depth_right);
    return depth;
}

int CodeCaprice::question104(TreeNode* root)//二叉树的最大深度
{
    return helper104(root);
}

int CodeCaprice::helper111(TreeNode* root)
{
    if(root == nullptr) return 0;
    int depth_left = helper111(root->left);
    int depth_right = helper111(root->right);
    if(root->left == nullptr) return 1 + depth_right;
    if(root->right == nullptr) return 1 + depth_left;

    return 1 + std::min(depth_left, depth_right);
}

int CodeCaprice::question111(TreeNode* root)//二叉树的最小深度
{
    return helper111(root);
}


int CodeCaprice::question222(TreeNode* root)//完全二叉树的节点个数
{
    if(root == nullptr)
        return 0;
    int result = 0;
    std::queue<TreeNode*> que; 
    que.push(root);

    while(!que.empty())
    {
        int que_size = que.size();
        for(int i = 0; i < que_size; ++i)
        {
            TreeNode* node = que.front();
            que.pop();
            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
            result++;
        }
    }

    return result;
}

int CodeCaprice::helper110(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    
    int height_left = helper110(root->left);
    if(height_left == -1) return -1;
    int height_right = helper110(root->right);
    if(height_right == -1) return -1;

    return std::abs(height_left - height_right) > 1 ? -1 : 1 + std::max(height_left, height_right);
}

bool CodeCaprice::question110(TreeNode* root)//平衡二叉树
{
    return helper110(root) == - 1 ? false : true;
}

void CodeCaprice::helper257(TreeNode* root, std::vector<std::vector<int>>& paths, std::vector<int>& path)
{
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr)
        paths.push_back(path);

    if(root->left != nullptr) helper257(root->left, paths, path);
    if(root->right != nullptr) helper257(root->right, paths, path);
    path.pop_back();
}

std::vector<std::string> CodeCaprice::question257(TreeNode* root)//二叉树的所有路径
{
    std::vector<std::string> result;
    std::vector<std::vector<int>> paths;
    std::vector<int> path;
    if(root == nullptr)
        return result;
    path.push_back(root->val);
    if(root->left == nullptr && root->right == nullptr)
        paths.push_back(path);
    if(root->left != nullptr) helper257(root->left, paths, path);
    if(root->right != nullptr) helper257(root->right, paths, path);

    for(int i = 0; i < paths.size(); ++i)
    {
        std::string str;
        str += std::to_string(paths[i][0]);
        for(int j = 1; j < paths[i].size(); ++j)
        {
            str += "->";
            str += std::to_string(paths[i][j]);
        }
        result.push_back(str);
    }

    return result;
}

int CodeCaprice::helper404(TreeNode* root)
{
    if(root->left == nullptr && root->right == nullptr)
        return 0;
    if(root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        return root->left->val;

    int sum_left = 0;
    int sum_right = 0;
    if(root->left != nullptr) sum_left = helper404(root->left);
    if(root->right != nullptr) sum_right = helper404(root->right);

    return sum_left + sum_right;
}

int CodeCaprice::question404(TreeNode* root)//左叶子之和
{
    if(root == nullptr)
        return 0;
    return helper404(root);
}


int CodeCaprice::question513(TreeNode* root)//找树左下角的值
{
    std::queue<TreeNode*> que; 
    std::vector<std::vector<int>> levels;
    
    que.push(root);

    while(!que.empty())
    {
        int que_size = que.size();
        std::vector<int> level;
        for(int i = 0; i < que_size; ++i)
        {
            TreeNode* node = que.front();
            level.push_back(node->val);
            que.pop();
            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
        }
        levels.push_back(level);
    }
    return levels[levels.size() - 1][0];
}


void CodeCaprice::helper112(TreeNode* root, int& targetSum, bool& result)
{
    if(result == true) return;
    if(root->left == nullptr && root->right == nullptr)
    {
        if(targetSum == 0) result = true;
        return;
    }
    
    if(root->left != nullptr)
    {
        targetSum = targetSum - root->left->val;
        helper112(root->left, targetSum, result);
        targetSum = targetSum + root->left->val;
    }
    if(root->right != nullptr)
    {
        targetSum = targetSum - root->right->val;
        helper112(root->right, targetSum, result);
        targetSum = targetSum + root->right->val;
    }

    return;
}

bool CodeCaprice::question112(TreeNode* root, int targetSum)//路径总和
{
    bool result = false;
    helper112(root, targetSum, result);
    return result;
}



TreeNode* CodeCaprice::helper106(std::vector<int>& inorder, int in_start, int in_end, std::vector<int>& postorder, int post_start, int post_end)
{
    if(in_start > in_end || post_start > post_end)
        return nullptr;

    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);
    int in_start_left = in_start;
    int in_end_left = 0;
    int in_start_right = 0;
    int in_end_right = in_end;
    for(int i = 0; i < inorder.size(); ++i)
    {
        if(inorder[i] == root_val)
        {
            in_end_left = i - 1;
            in_start_right = i + 1;
        }
    }
    int post_start_left = post_start;
    int post_end_left = post_start + in_end_left - in_start_left;
    int post_start_right = post_end - 1 - (in_end_right - in_start_right);
    int post_end_right = post_end - 1;

    root->left = helper106(inorder, in_start_left, in_end_left, postorder, post_start_left, post_end_left);
    root->right = helper106(inorder, in_start_right, in_end_right, postorder, post_start_right, post_end_right);

    return root;
}

TreeNode* CodeCaprice::question106(std::vector<int>& inorder, std::vector<int>& postorder)//从中序遍历和后序遍历构造二叉树
{
    TreeNode* root = helper106(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    return root;
}

TreeNode* CodeCaprice::helper654(std::vector<int>& nums, int start, int end)
{
    if(start > end)
        return nullptr;
    int root_idx = 0;
    int root_val = std::numeric_limits<int>::min();
    for(int i = start; i <= end; ++i)
    {
        if(nums[i] > root_val)
        {
            root_idx = i;
            root_val = nums[i];
        }
    }
    TreeNode* root = new TreeNode(root_val);
    root->left = helper654(nums, start, root_idx - 1);
    root->right = helper654(nums, root_idx + 1, end);

    return root;
}

TreeNode* CodeCaprice::question654(std::vector<int>& nums)//最大二叉树
{
    TreeNode* root = helper654(nums, 0, nums.size() - 1);
    return root;
}

TreeNode* CodeCaprice::helper617(TreeNode* root1, TreeNode* root2)
{
    TreeNode* node_this = nullptr;
    if(root1 == nullptr && root2 == nullptr) 
        return nullptr;

    if(root1 != nullptr && root2 != nullptr) 
    {
        node_this = new TreeNode(root1->val + root2->val);
        node_this->left = helper617(root1->left, root2->left);
        node_this->right = helper617(root1->right, root2->right);
    }
    if(root1 != nullptr && root2 == nullptr) 
    {
        node_this = new TreeNode(root1->val);
        node_this->left = helper617(root1->left, nullptr);
        node_this->right = helper617(root1->right, nullptr);
    }
    if(root1 == nullptr && root2 != nullptr)
    {
        node_this = new TreeNode(root2->val);
        node_this->left = helper617(nullptr, root2->left);
        node_this->right = helper617(nullptr, root2->right);
    }

    return node_this;
}

TreeNode* CodeCaprice::question617(TreeNode* root1, TreeNode* root2)//合并二叉树
{
    TreeNode* root = helper617(root1, root2);
    return root;
}

TreeNode* CodeCaprice::helper700(TreeNode* root, int& val)
{
    if(root == nullptr) return nullptr;
    if(root->val == val) return root;
    else if(root->val > val) return helper700(root->left, val);
    else if(root->val < val) return helper700(root->right, val);

    return nullptr;
}

TreeNode* CodeCaprice::question700(TreeNode* root, int val)//二叉搜索树中的搜索
{
    return helper700(root, val);
}

bool CodeCaprice::helper98(TreeNode* root, long long& max_val)
{
    if(root == nullptr)
        return true;
    bool left = helper98(root->left, max_val);
    if(max_val < root->val) max_val = root->val;
    else return false;
    bool right = helper98(root->right, max_val);
    return left && right;
}

bool CodeCaprice::question98(TreeNode* root)//验证二叉搜索树
{
    long long max_val = std::numeric_limits<long long>::min();
    return helper98(root, max_val);
}

void CodeCaprice::helper530(TreeNode* root, std::vector<int>& inorder)
{
    if(root == nullptr)
        return;
    helper530(root->left, inorder);
    inorder.push_back(root->val);
    helper530(root->right, inorder);
}

int CodeCaprice::question530(TreeNode* root)//二叉搜索树的最小绝对差
{
    int min_val = std::numeric_limits<int>::max();
    std::vector<int> inorder;
    helper530(root, inorder);
    for(int i = 0; i < inorder.size() - 1; ++i)
    {
        min_val = std::min(min_val, inorder[i + 1] - inorder[i]);
    }
    return min_val;
}

void CodeCaprice::helper501(TreeNode* root, std::unordered_map<int, int>& map)
{
    if(root == nullptr)
        return;
    helper501(root->left, map);
    map[root->val]++;
    helper501(root->right, map);
}

std::vector<int> CodeCaprice::question501(TreeNode* root)//二叉搜索树中的众数
{
    std::unordered_map<int, int> map;
    std::vector<std::pair<int, int>> vec;
    std::vector<int> result;
    int max_cnt = std::numeric_limits<int>::min();
    helper501(root, map);
    for(std::pair<int, int> iter : map)
        vec.push_back(iter);
    std::sort(vec.begin(), vec.end(), [](std::pair<int, int>& pair1, std::pair<int, int>& pair2){
        return pair1.second > pair2.second;
    });
    for(auto iter : vec)
        if(iter.second == vec.begin()->second) result.push_back(iter.first);
        else break;
    
    return result;
}

TreeNode* CodeCaprice::helper236(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == p || root == q || root == nullptr) return root;
    TreeNode* left_node = helper236(root->left, p, q);
    TreeNode* right_node = helper236(root->right, p, q);
    if(left_node != nullptr && right_node != nullptr) return root;
    if(left_node != nullptr && right_node == nullptr) return left_node;
    if(left_node == nullptr && right_node != nullptr) return right_node;

    return nullptr;
}

TreeNode* CodeCaprice::question236(TreeNode* root, TreeNode* p, TreeNode* q)//二叉树的最近公共祖先
{
    return helper236(root, p, q);
}

/*回溯*/

void CodeCaprice::helper77(std::vector<std::vector<int>>& result, std::vector<int>& path, int& n, int& k, int start_idx)
{
    if(path.size() == k)
    {
        result.push_back(path);
        return;
    }

    for(int i = start_idx; i <= n; ++i)
    {
        path.push_back(i);
        helper77(result, path, n, k, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> CodeCaprice::question77(int n, int k)//组合
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    helper77(result, path, n, k, 1);
    return result;
}

void CodeCaprice::helper216(std::vector<std::vector<int>>& result, std::vector<int>& path, int n, int k, int start_idx)
{
    if(path.size() == k && n == 0)
    {
        result.push_back(path);
        return;
    }

    for(int i = start_idx; i <= 9; ++i)
    {
        path.push_back(i);
        helper216(result, path, n - i, k, i + 1);
        path.pop_back();
    }
}

std::vector<std::vector<int>> CodeCaprice::question216(int n, int k)//组合总和III
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    helper216(result, path, n, k, 1);
    return result;
}

void CodeCaprice::helper17(std::unordered_map<char, std::string>& map, std::vector<std::string>& result, std::string& path, std::string& digits, int start_idx)
{
    if(path.size() == digits.size())
    {
        result.push_back(path);
        return;
    }
    
    char num = digits[start_idx];
    for(char ch : map[num])
    {
        path.push_back(ch);
        helper17(map, result, path, digits, start_idx + 1);
        path.pop_back();
    }
}

std::vector<std::string> CodeCaprice::question17(std::string digits)//电话号码的字母组合
{
    std::vector<std::string> result;
    std::string path;
    std::unordered_map<char, std::string> map;
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";
    helper17(map, result, path, digits, 0);

    return result;
}


int CodeCaprice::question455(std::vector<int>& g, std::vector<int>& s)//分发饼干
{
    int result = 0;
    int index = s.size() - 1;

    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());

    for(int i = g.size() - 1; i >= 0; --i)
    {
        if(index >= 0 && s[index] >= g[i])
        {
            index--;
            result++;
        }
    }

    return result;
}

int CodeCaprice::question1005(std::vector<int>& nums, int k)//K次取反后最大化的数组和
{
    int sum = 0;
    std::sort(nums.begin(), nums.end(), [](int& a, int& b)
    {
        return std::abs(a) > std::abs(b);
    });
    for(int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] < 0 && k > 0)
        {
            k--;
            nums[i] = -nums[i];
        }
    }
    if(k % 2 == 1) nums[nums.size() - 1] *= -1;
    for(int num : nums) sum += num;

    return sum;
}


bool CodeCaprice::question860(std::vector<int>& bills)//柠檬水找零
{
    bool result = true;
    std::unordered_map<int, int> map;

    for(int bill : bills)
    {
        if(bill == 5)
        {
            //do nothing
        }
        else if(bill == 10)
        {
            if(map[5] > 0) map[5]--;
            else result = false;
        }
        else if(bill == 20)
        {
            if(map[5] > 0 && map[10] > 0)
            {
                map[5]--;
                map[10]--;
            }
            else if(map[5] > 2)
            {
                map[5] -= 3;
            }
            else
                result = false;
        }
        map[bill]++;
    }
    return result;
}


int CodeCaprice::question376(std::vector<int>& nums)//摆动序列
{
    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < nums.size(); ++i)
    {
        dp[i][0] = dp[i][1] = 1;
        for(int j = 0; j < i; ++j)
        {
            if(nums[i] < nums[j])
                dp[i][0] = std::max(dp[i][0], dp[j][1] + 1);
            if(nums[i] > nums[j])
                dp[i][1] = std::max(dp[i][1], dp[j][0] + 1);
        }
    }
    return std::max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
}

int CodeCaprice::helper738(std::vector<int>& nums, int start, int end)
{
    for(int i = 0; i < end; ++i)
        if(nums[i] > nums[i + 1])
            return i;
    return -1;
}

int CodeCaprice::question738(int n)//单调递增的数字
{
    int n_tmp = n;
    int result = 0;
    std::vector<int> nums;
    while(n_tmp > 0)
    {
        nums.push_back(n_tmp % 10);
        n_tmp /= 10;
    }
    std::reverse(nums.begin(), nums.end());

    int end = nums.size() - 1;
    int not_single_idx = end;
    not_single_idx = helper738(nums, 0, end);
    while(not_single_idx != -1)
    {
        nums[not_single_idx] -= 1;
        for(int i = not_single_idx + 1; i <= end; ++i)
        {
            nums[i] = 9;
        }
        end = not_single_idx;
        not_single_idx = helper738(nums, 0, not_single_idx);
    }

    for(int i = 0; i < nums.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            nums[nums.size() - 1 - i] = nums[nums.size() - 1 - i] * 10;
        }
        result += nums[nums.size() - 1 - i];
    }
    return result;
}


int CodeCaprice::question122(std::vector<int>& prices)//买卖股票的最佳时机
{
    int result = 0;

    for(int i = 0; i < prices.size() - 1; ++i)
    {
        result += std::max(prices[i + 1] - prices[i], 0);
    }
    return result;
}

int CodeCaprice::question135(std::vector<int>& ratings)//分发糖果
{
    std::vector<int> candyVec(ratings.size(), 1);
     // 从前向后
     for (int i = 1; i < ratings.size(); i++) {
         if (ratings[i] > ratings[i - 1]) candyVec[i] = candyVec[i - 1] + 1;
     }
     // 从后向前
     for (int i = ratings.size() - 2; i >= 0; i--) {
         if (ratings[i] > ratings[i + 1] ) {
             candyVec[i] = std::max(candyVec[i], candyVec[i + 1] + 1);
         }
     }
     // 统计结果
     int result = 0;
     for (int i = 0; i < candyVec.size(); i++) result += candyVec[i];
     return result;
}

std::vector<std::vector<int>> CodeCaprice::question406(std::vector<std::vector<int>>& people)//根据身高重建队列
{
    std::vector<std::vector<int>> result;
    std::sort(people.begin(), people.end(), [](std::vector<int>& people1, std::vector<int>& people2){
        if(people1[0] == people1[0]) return people1[1] < people2[1];
        return people1[0] > people2[0];
    });
    for(int i = 0; i < people.size(); ++i)
    {
        int positon = people[i][1];
        result.insert(result.begin() + positon, people[i]);
    }
    return result;
}

/*动态规划*/
int CodeCaprice::question509(int n)//斐波那契数列
{
    if(n == 0) return 0;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int CodeCaprice::question70(int n)//爬楼梯
{
    //1.确定dp数组含义: dp[i]表示爬i阶楼梯共有几种方法
    //2.确定递推公式: dp[i] = dp[i - 1] + dp[i - 2]; 爬楼梯可以通过i-1阶爬1步，也可以通过i-2阶爬2步
    //3.确定dp数组初始化: dp[0] = 1; dp[1] = 1;
    //4.确定遍历顺序: 从0-n级楼梯
    //5.设计几个例子验证: dp[2] = dp[1] + dp[0]; dp[3] = dp[2] + dp[1]
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int CodeCaprice::question746(std::vector<int>& cost)//使用最小花费爬楼梯
{
    //确定dp数组含义: dp[i]表示到第i阶楼梯的最小花费
    //确定递推公式: dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    //初始化dp数组: dp[0] = 0, dp[1] = min(cost[0], 0), 因为可以从1出发，所以到1的代价可以为0
    //确定遍历顺序: 0-cost.size()
    //设计几个例子验证: dp[2] = min(dp[1] + cost[1], dp[0] + cost[0])
    std::vector<int> dp(cost.size() + 1, 0);
    dp[0] = 0;
    dp[1] = cost[0];
    for(int i = 2; i < cost.size() + 1; ++i)
    {
        dp[i] = std::min(dp[i - 1], dp[i - 2]);
    }
    return dp[cost.size()];
}

int CodeCaprice::question62(int m, int n)//不同路径
{
    //确定dp数组含义：dp[i][j]表示从左上角走到位置[i][j]共有几种路径
    //确定递推公式：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]；边界条件：i == 0 || j == 0，dp[0][j] = dp[0][j-1], dp[i] = dp[i - 1][0]
    //确定dp数组初始化：dp[0][0] = 1
    //确定遍历顺序：双循环遍历
    //设计几个例子递推：dp[0][0] = 1, dp[0][1] = 1, dp[1][1] = dp[0][1] + dp[1][0] = 1 + 1
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i == 0 && j == 0) dp[i][j] = 1;
            else if(i == 0) dp[i][j] = dp[i][j - 1];
            else if(j == 0) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int CodeCaprice::question63(std::vector<std::vector<int>>& obstacleGrid)//不同路径II
{
    //确定dp数组含义：dp[i][j]表示从左上角走到位置[i][j]共有几种路径
    //确定递推公式：dp[i][j] = dp[i - 1][j] + dp[i][j - 1]；
    //  边界条件：i == 0 || j == 0，dp[0][j] = dp[0][j-1], dp[i] = dp[i - 1][0]
    //          obstacleGrid[i][j] == 1 dp[i][j] = 0;
    //确定dp数组初始化：dp[0][0] = 1
    //确定遍历顺序：双循环遍历
    //设计几个例子递推：dp[0][0] = 1, dp[0][1] = 1, dp[1][1] = dp[0][1] + dp[1][0] = 1 + 1
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
            {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0) dp[i][j] = dp[i][j - 1];
                else if(j == 0) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}

int CodeCaprice::question343(int n)//整数拆分
{
    //dp数组的定义：dp[i]表示拆分整数i得到的最大乘积
    //dp的递推公式：dp[i] = max(j * (i - j), j * dp[i - j])
    //dp的初始条件：dp[0] = 0, dp[1] = 1, dp[2] = 1
    //dp的遍历顺序：
    //设计几个例子：
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 0;
    for(int i = 2; i < n + 1; ++i)
    {
        for(int j = 1; j <= i / 2; ++j)
        {
            dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
        }
    }
    return dp[n];
}


int CodeCaprice::question96(int n)//不同的二叉搜索树
{
    //dp数组的定义：dp[i]表示节点数为i的二叉搜索树数量
    //dp的递推公式：dp[i] = \sigma dp[j - 1] * dp[n - j]
    //dp的初始条件：dp[0] = dp[1] = 1
    //dp的遍历顺序：以j为根节点编号，j到i遍历
    //设计几个例子：
    std::vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i < n + 1; ++i)
    {
        for(int j = 1; j <= i; ++j)//以j为根节点的二叉搜索树
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

void CodeCaprice::backpack_test(std::vector<int>& weights, std::vector<int>& vals, int& bag_weight)
{
    //确定dp数组含义：dp[i][j]表示标号为0~i的物品放到容量为j的背包中的最大收益
    //确定dp数组递推关系：dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i]] + val[i])，表示放物品i和不放物品i的对比
    //dp初始条件：都为0
    //dp遍历顺序：正常两个for
    std::vector<std::vector<int>> dp(weights.size(), std::vector<int>(bag_weight, 0));
    for(int i = 0; i < weights.size(); ++i)
    {
        for(int j = 0; j < bag_weight; ++j)
        {
            if(j < weights[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weights[i]] + vals[i]);
        }
    }
}