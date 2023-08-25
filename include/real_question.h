/*------------------------------------------------------------------------------
 * @file    REAL_QUESTION.H
 * @author  t-rex 
 * @date    2023/08/14 08:41:43
 * @brief   机试真题收集.
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
#ifndef __REAL_QUESTION_H
#define __REAL_QUESTION_H

/* Files includes  -----------------------------------------------------------*/
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/
#ifdef _REAL_QUESTION_C_
#define GLOBAL



#else
#define GLOBAL extern
#endif



#undef GLOBAL

/* Functions ----------------------------------------------------------------*/

class RealQuestion
{
public:
    RealQuestion(){}
    ~RealQuestion(){}
    void dajiang1();
    void dajiang2();
    void mihayou1();
    void mihayou2();
    void mihayou3();
    void xiaohongshu1();//小红背单词
    bool is_palindrome(std::string str);//判断是否为回文串
    void xiaohongshu2();
    void xiaohongshu3();
    void meituan1();
    void meituan2();
    void meituan3();
    void meituan4();
    void meituan5();
    void dewu1();
    void dewu_helper2(std::vector<int>& nums, int& min_len, std::vector<int>& path, int target, int sum, int start_idx);
    void dewu2(); 

    void weilai1();
    int weilai3(std::vector<std::vector<int>>& grid);
private:

};

#endif
