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
    bool question20(std::string str);//有效的括号
    std::string question1047(std::string str);//删除字符串中的所有相邻重复项
    int question150(std::vector<std::string>& tokens);//逆波兰表达式求值
    std::vector<int> question239(std::vector<int>& nums, int k);//滑动窗口最大值
    std::vector<int> question347(std::vector<int>& nums, int k);//第k个高频元素

    /*二叉树*/
    void helper144(TreeNode* root, std::vector<int>& result);
    void helper145(TreeNode* root, std::vector<int>& result);
    void helper94(TreeNode* root, std::vector<int>& result);
    std::vector<int> question144(TreeNode* root);//二叉树的前序遍历
    std::vector<int> question145(TreeNode* root);//二叉树的后序遍历
    std::vector<int> question94(TreeNode* root);//二叉树的中序遍历
    std::vector<std::vector<int>> question102(TreeNode* root);//二叉树的层序遍历
    void helper226(TreeNode* root);
    TreeNode* question226(TreeNode* root);//翻转二叉树
    bool helper101(TreeNode* tree_left, TreeNode* tree_right);
    bool question101(TreeNode* root);//对称二叉树
    int helper104(TreeNode* root);
    int question104(TreeNode* root);//二叉树的最大深度
    int helper111(TreeNode* root);
    int question111(TreeNode* root);//二叉树的最小深度
    int question222(TreeNode* root);//完全二叉树的节点个数
    int helper110(TreeNode* root);
    bool question110(TreeNode* root);//平衡二叉树
    void helper257(TreeNode* root, std::vector<std::vector<int>>& paths, std::vector<int>& path);
    std::vector<std::string> question257(TreeNode* root);//二叉树的所有路径
    int helper404(TreeNode* root);
    int question404(TreeNode* root);//左叶子之和
    int question513(TreeNode* root);//找树左下角的值
    void helper112(TreeNode* root, int& targetSum, bool& result);
    bool question112(TreeNode* root, int targetSum);//路径总和
    TreeNode* helper106(std::vector<int>& inorder, int in_start, int in_end, std::vector<int>& postorder, int post_start, int post_end);
    TreeNode* question106(std::vector<int>& inorder, std::vector<int>& postorder);//从中序遍历和后序遍历构造二叉树
    TreeNode* helper654(std::vector<int>& nums, int start, int end);
    TreeNode* question654(std::vector<int>& nums);//最大二叉树
    TreeNode* helper617(TreeNode* root1, TreeNode* root2);
    TreeNode* question617(TreeNode* root1, TreeNode* root2);//合并二叉树
    TreeNode* helper700(TreeNode* root, int& val);
    TreeNode* question700(TreeNode* root, int val);//二叉搜索树中的搜索
    bool helper98(TreeNode* root, long long& max_val);
    bool question98(TreeNode* root);//验证二叉搜索树
    void helper530(TreeNode* root, std::vector<int>& inorder);
    int question530(TreeNode* root);//二叉搜索树的最小绝对差
    void helper501(TreeNode* root, std::unordered_map<int, int>& map);
    std::vector<int> question501(TreeNode* root);//二叉搜索树中的众数
    TreeNode* helper236(TreeNode* root, TreeNode* p, TreeNode* q);
    TreeNode* question236(TreeNode* root, TreeNode* p, TreeNode* q);//二叉树的最近公共祖先

    /*回溯*/
    void helper77(std::vector<std::vector<int>>& result, std::vector<int>& path, int& n, int& k, int start_idx);
    std::vector<std::vector<int>> question77(int n, int k);//组合
    void helper216(std::vector<std::vector<int>>& result, std::vector<int>& path, int n, int k, int start_idx);
    std::vector<std::vector<int>> question216(int n, int k);//组合总和III
    void helper17(std::unordered_map<char, std::string>& map, std::vector<std::string>& result, std::string& path, std::string& digits, int start_idx);
    std::vector<std::string> question17(std::string digits);//电话号码的字母组合

    /*贪心*/
    int question455(std::vector<int>& g, std::vector<int>& s);//分发饼干
    int question1005(std::vector<int>& nums, int k);//K次取反后最大化的数组和
    bool question860(std::vector<int>& bills);//柠檬水找零
    int question376(std::vector<int>& nums);//摆动序列
    int helper738(std::vector<int>& nums, int start, int end);
    int question738(int n);//单调递增的数字
    int question122(std::vector<int>& prices);//买卖股票的最佳时机
    int question135(std::vector<int>& ratings);//分发糖果
    std::vector<std::vector<int>> question406(std::vector<std::vector<int>>& people);//根据身高重建队列

    /*动态规划*/
    int question509(int n);//斐波那契数列
    int question70(int n);//爬楼梯
    int question746(std::vector<int>& cost);//使用最小花费爬楼梯
    int question62(int m, int n);//不同路径
    int question63(std::vector<std::vector<int>>& obstacleGrid);//不同路径II
    int question343(int n);//整数拆分
    int question96(int n);//不同的二叉搜索树
    void backpack_test(std::vector<int>& weights, std::vector<int>& vals, int& bag_weight);

private:

};

#endif