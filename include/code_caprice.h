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
#include <string>
#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>

#include "headers.h"

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/
#ifdef _CODE_CAPRICE_C_
#define GLOBAL



#else
#define GLOBAL extern
#endif



#undef GLOBAL

/* Functions ----------------------------------------------------------------*/
class CodeCaprice
{
public:
    CodeCaprice(){};
    ~CodeCaprice(){};

    /*数组*/
    int question704(std::vector<int>& nums, int target);//二分查找
    int question27(std::vector<int>& nums, int val);//移除元素
    std::vector<int> question977(std::vector<int>& nums);//有序数组的平方
    int question209(int target, std::vector<int>& nums);//长度最小的子数组
    std::vector<std::vector<int>> question59(int n);//螺旋矩阵II

    //链表
    ListNode* question203(ListNode* head, int val);//移除链表元素
    //question707 设计链表
    ListNode* question206(ListNode* head);//翻转链表
    ListNode* question24(ListNode* head);//两两交换链表中的节点
    ListNode* question19(ListNode* head, int n);//删除链表的倒数第n个节点
    ListNode* question160(ListNode* head1, ListNode* head2);//链表的相交节点
    ListNode* question142(ListNode* head);//环形链表II


    /*哈希表*/
    bool question242(std::string s, std::string t);//有效字母异位词
    std::vector<int> question349(std::vector<int>& nums1, std::vector<int>& nums2);//两个数组的交集
    bool question202(int n);//快乐数
    std::vector<int> question1(std::vector<int>& nums, int target);//两数之和
    int question454(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4);//四数相加II
    bool question383(std::string ransomNote, std::string magazine);//赎金信
    std::vector<std::vector<int>> question15(std::vector<int>& nums);//三数之和
    std::vector<std::vector<int>> question18(std::vector<int>& nums, int target);//四数之和

    /*字符串*/
    void question344(std::vector<char>& str);//翻转字符串
    std::string question541(std::string str, int k);//翻转字符串II
    std::string question5(std::string str);//替换空格
    std::string question151(std::string str);//翻转字符串中的单词
    std::string question58(std::string str, int k);//左旋字符串
    int question28(std::string haystack, std::string needle);//找出字符串中第一个匹配项的下标
    bool question459(std::string str);//给定一个非空的字符串，判断其是否可以通过由它一个子串重复多次构成

    /*栈与队列*/
    //question232用栈实现队列
    //question225用队列实现栈
private:

};

#endif