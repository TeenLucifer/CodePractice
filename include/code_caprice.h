/*------------------------------------------------------------------------------
 * @file    CODE_CAPRICE.H
 * @author  t-rex 
 * @date    2023/08/08 20:17:48
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
#ifndef __CODE_CAPRICE_H
#define __CODE_CAPRICE_H

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <limits>

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/
#ifdef _CODE_CAPRICE_C_
#define GLOBAL



#else
#define GLOBAL extern
#endif



#undef GLOBAL

/* Functions ----------------------------------------------------------------*/
class CodeCarprice
{
public:
    CodeCarprice(){};
    ~CodeCarprice(){};

    /*数组*/
    int question704(std::vector<int>& nums, int target);//二分查找
    int question27(std::vector<int>& nums, int val);//移除元素
    std::vector<int> question977(std::vector<int>& nums);//有序数组的平方
    int question209(int target, std::vector<int>& nums);//长度最小的子数组
private:

};

#endif
