/*------------------------------------------------------------------------------
 * @file    HEADERS.H
 * @author  t-rex 
 * @date    2023/08/10 20:17:30
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
#ifndef __HEADERS_H
#define __HEADERS_H

/* Files includes  -----------------------------------------------------------*/
#include <utility>
#include <vector>
#include <unordered_map>

/* Defines -------------------------------------------------------------------*/


/* Variables -----------------------------------------------------------------*/
#ifdef _HEADERS_C_
#define GLOBAL



#else
#define GLOBAL extern
#endif



#undef GLOBAL

/* Functions ----------------------------------------------------------------*/
class GraphEdge;
class GraphNode;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right){}
};

#include <iostream>
#include <vector>

class GraphEdge {
public:
    int neighbor; // 邻居节点的标识
    int weight;   // 边的权重，如果不需要权重可以省略

    GraphEdge(int n, int w = 1) : neighbor(n), weight(w) {}
};

class GraphNode {
public:
    int id;
    int val;
    int cost;
    bool visited = false;
    std::vector<GraphEdge> neighbors; // 存储邻居节点和边

    GraphNode(int _id, int _val, int _cost) : id(_id), val(_val), cost(_cost) {}
};

class UndirectedGraph {
public:
    std::vector<GraphNode*> nodes;

    void add_node(int id, int val, int cost)
    {
        nodes.push_back(new GraphNode(id, val, cost));
    }

    void add_edge(int src_id, int dest_id, int weight = 1)
    {
        for (GraphNode* node : nodes)
        {
            if (node->id == src_id)
                node->neighbors.emplace_back(dest_id, weight);
            if (node->id == dest_id)
                node->neighbors.emplace_back(src_id, weight); // 无向图只需添加一次边
        }
    }

    GraphNode* get_node(int id)
    {
        for (GraphNode* node : nodes) 
        {
            if (node->id == id) 
                return node;
        }
        return nullptr;
    }
};

#endif