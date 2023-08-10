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
#include <limits>
#include <vector>
#define _CODE_CAPRICE_C_

/* Files includes  -----------------------------------------------------------*/
#include "code_caprice.h"

/*----------------------------------------------------------------------------*/

/*数组*/
int CodeCarprice::question704(std::vector<int>& nums, int target)//二分查找
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

int CodeCarprice::question27(std::vector<int>& nums, int val)//移除元素
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

std::vector<int> CodeCarprice::question977(std::vector<int>& nums)//有序数组的平方
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

int CodeCarprice::question209(int target, std::vector<int>& nums)//长度最小的子数组
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