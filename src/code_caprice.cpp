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
#include "headers.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <limits>
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