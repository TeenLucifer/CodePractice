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
#include <cstddef>
#include <limits>
#include <random>
#include <sstream>
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

}

bool CodeCaprice::question459(std::string str)//给定一个非空的字符串，判断其是否可以通过由它一个子串重复多次构成
{

}