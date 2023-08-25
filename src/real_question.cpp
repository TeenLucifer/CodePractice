/*------------------------------------------------------------------------------
 * @file    REAL_QUESTION.CPP
 * @author  t-rex 
 * @date    2023/08/14 08:42:08
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
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <limits>
#include <pthread.h>
#include <queue>
#include <random>
#include <regex>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#define _REAL_QUESTION_C_

/* Files includes  -----------------------------------------------------------*/
#include "headers.h"
#include "real_question.h"

/*----------------------------------------------------------------------------*/

/*Dji 2023/08/13*/
/*
解决无人机飞行规划问题
* 给定一个环形路线实施无人机作业，在路线上有n个充电站，编号0,...,n-1，i号充电站可以给无人机提供charge[i]单位的电量。无人机从i号充电站出发作业，并飞往i+1号充电站需要小号cost[i]单位的电量。
* 假设无人机可以无限量充电。无人机从其中一个充电站完成充电出发（充电前初始电量为空），给定正整数数组charge和cost，如果无人机可以顺时针绕环形路线一周完成作业并返回出发充电站，则返回出发时充电站编号i，否则返回-1
* 注：为简化问题，如果存在解，输入数据可保证解唯一。测试用例输入格式为（length of charge, charge, lengh of cost, cost）
* e.g.1
* 输入：length of charge = 5, charge = [1, 2, 3, 4, 5], length of cost = 5, cost = [3, 4, 5, 1, 2]
* 输出：3
* 解析：从3号充电站出发，电量为4；飞到4号充电站，电量为4-1+5=8；飞到0号充电站，电量为8-2+1=7；飞到1号充电站，电量为7-3+2=6；飞到2号充电站，电量为6-4+3=5；飞回到3号充电站，电量5正好满足cost[2]
* e.g.2
* 输入：length of charge = 3, charge = [2, 3, 4], length of cost = 3, cost = [3, 4, 3]
* 输出：-1
* 解析：从0号或者1号充电站出发，得到的电量都不能满足飞到下一站的电量。从2号充电站出发，电量为4；飞到0号充电站，电量为4-3+2=3；飞到1号充电站，电量为3-3+3=3；但是无法返回2号充电站，cost[1]>3
* 输入描述：每个充电站提供的电量数组长度，数组内容，从i号充电站飞到i+1号充电站需要消耗的电量数组长度，数组内容
* 输出描述：出发充电站编号
* 样例输入：
* 5
* 1 2 3 4 5
* 5
* 3 4 5 1 2
* 样例输出：
* 3
*/
void RealQuestion::dajiang1()
{
    std::cout << "hello" << std::endl;
}

/*
* 多个航拍点，为了规划路线，提前了解了不同航拍点之间的连通性和距离，同时确认了每个航拍点充电桩的充电速度
* 电动车满电电量可以形式距离为dis，单位km，该电动车在每形式1km消耗1单位电量，且耗时1min，一共N个航拍点，每个航拍点都有充电桩，使用二维数组paths标识两个航拍点的双向连通性和距离：[[航拍点编号，相邻航拍点编号，两个航拍点的距离]]，示例：[[0,1,3],[0,2,2]...]，其中[0,1,3]表示编号为0的航拍点充电1单位耗时2分钟，10表示编号为1的航拍点充电1单位耗时10m分钟
* 当前在航拍点a，且电动车无电，请问最少花费多少分钟数从所在的航拍点a抵达航拍点b
* 输入描述：
* 1. paths: 标识两个航拍点的双向连通性和距离
* (先输入航拍点距离的二维数组长度，比如6 3，表示6组数据，每组3个数值。再跟具体的数组内容)
* 2. dis: 电动车满电行驶里程
* 3. a: 航拍点a的编号
* 4. b: 航拍点b的编号
* 5. charge: 标识每个航拍点充1单位电花费的分钟数
* (先输入充电的数组长度，比如5.再跟数组内容，比如4 1 1 3 2)
* 输出描述：
* 花费最少的分钟数
* 样例输入：
* 6 3
* 0 4 2
* 4 3 5
* 3 0 5
* 0 1 5
* 3 2 4
* 1 2 8
* 8
* 0
* 2
* 5
* 4 1 1 3 2
* 样例输出：
* 38
*/
void RealQuestion::dajiang2()
{

}

/*米哈游2023/08/13*/
/*
*前情提要：昨天是米小游生日，但是她又错过了爱莉键盘，她许了个生日愿望想让奥托主教再带她冲一次虚数之树，为世界上所有的美好而战！
* 米小游和奥托主教冲虚树之树后，掉入量子之海里失散了，但她不如道奥托主教在哪里，所以她决定先去寻找月下，再让月下带着她一起去找奥托主教。
已知量子之海可以认为是一个n* m的矩阵，左下角坐标为（1, 1），右上角坐标是（n，m）。米小游每次可以走到相邻的坐标，即当|x1 - x2|+|y1 - y2|=1时，米小游可以从（x1,y1）走到（x2,y2）。
* 另外，量子之海有一个特殊的特性，其左边界和右边界是相邻的，上边界和下边界也是相邻的。也就是说，（x,1）和（x,m）相邻，（1,y）和（n，y）也是相邻的。
* 现在按顺序给定了米小游、月下和奥托主教的坐标，请你判断米小游最少需要走几步。
* 输入描述：
*第一行输入两个整数 n，m（1≤n，m≤ 10^9）表示量子之海大小。
*接下来三行，每行输入两个整数
x（1≤x≤n），y（1≤y≤m）表示按顺序给出的点的坐标。
* 输出描述：
* 输出一个整数标识最少需要走的步数
* e.g. 1
* 输入：
* 3 3
* 1 1 
* 3 3
* 1 3
* 输出：
* 3
* 说明：
* 米小游可以先从（1，1）走到（3，1）走到（3，3），走2步。
* 然后再从（3，3）走到（1，3），走1步
* 因此总共走了3步
*/
void RealQuestion::mihayou1()
{

}

/*
* 米小游拿到了一棵有根树，树上有n个节点，根节点编号为1，所有边的长度均为1。
* 米小游每一次操作可以将一个新叶子节点接在原来的一个叶子上，新加的边的边长度也是1。米小游可以进行任意次操作。
* 她想知道，操作结束后，与根节点的距离不超过k的节点个数的最大值是多少。
* • 输入描述
* 第一行输入两个整数n（1≤n≤10^5），K（0≤k≤10^9）
* 接下来n-1行，每行输入两个整数u,v(1<=u,v<=n）表示节点u和节点v之间有一条边。
* 输出描述
* 输出一个整数表示答案。
* 示例1
* 输入输出示例仅供调试，后台判题数据一股不包含示例
* 输入：
* 4 2
* 1 2
* 1 3
* 2 4
* 输出：
* 5
*/
void RealQuestion::mihayou2()
{

}

/*
* 米小游买了一本书，名字叫《舰舰的奇妙冒险》。她每天会从第l_i页看到第r_i页，她想知道她每天看的部分有多少页是以前没看过的。
* 输入描述：
* 第一行输入两个整数 n，q（1≤n,q≤10^5）分别表示书的总页数、看书天数。
* 接下来q行，每行两个整数l_i,r_i（1≤l_i<=r_i<=n）。
* 输出描述：
* 输出q行，每行输出一个整数表示答案。
* 示例1：
* 输入输出示例仅供调试，后台判题数据一般不包含示例
* 输入
* 3 2
* 1 2
* 2 3
* 输出
* 2
* 1
* 说明：
* 第一天：米小游看了1、2页，其中1、2页之前都没看过，所以答案为2
* 第二天：米小游看了2、3页，其中第2页之前看过，第3页之前没看过，所以答案为1
*/
void RealQuestion::mihayou3()
{

}

void RealQuestion::xiaohongshu1()//小红背单词
{
    //小红每天都要背单词，如果她已经记住n个单词，且背了一个没有记住的新单词n+1次，她就会记住这个单词
    //例如：当她按顺序背["you", "thank", "thank"]时，她第一次背单词"you"就能记住"you"，而由于她已经记住了一个单词，所以需要背两次"thank"才能记住
    //现在给出小红每天背的单词，求她记住了几个单词
    //输入：第一行一个整数n，表示小红背了n个单词
    //接下来n行，每行一个单词
    //输出一个整数，表示小红记住了几个单词
    int n = 0;//表示总共背了几次单词
    std::vector<std::string> words;//表示背的单词
    std::unordered_map<std::string, int> map;
    std::unordered_map<std::string, int> map2;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }
    //要求判断她记住了几个单词
    int k = 0;//表示记住了几个单词
    for(int i = 0; i < n; ++i)
    {
        map[words[i]]++;
        if(map[words[i]] == k + 1 && map2.find(words[i]) == map2.end())
        {
            map2[words[i]]++;
            k++;
        }
    }
    std::cout << k << std::endl;
}

bool RealQuestion::is_palindrome(std::string str)//判断是否为回文串
{
    int ptr_left = 0;
    int ptr_right = str.size() - 1;
    while(ptr_left < ptr_right)
    {
        if(str[ptr_left] != str[ptr_right]) return false;
        ptr_left++;
        ptr_right--;
    }
    return true;
}

void RealQuestion::xiaohongshu2()
{
    //一个字符串可以进行以下操作：
    //1.拆分，把'w'拆成2个'v'，'m'拆成2个'n'
    //2.轴对称，把'b'轴对称成'd'，把'p'轴对称成'q'，反之亦然
    //3.翻转，把'p'翻转成'd'，把'q'翻转成'b'，把'n'翻转成'u'，反之亦然
    //需要判断输入的每行字符串经过若干次操作后是否能够变成回文串
    int n = 1;
    std::vector<std::string> strs;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::string str;
        std::cin >> str;
        strs.push_back(str);
    }
    for(int i = 0; i < n; ++i)
    {
        std::string str = strs[i];
        std::string str_cpy = "";
        for(int j = 0; j < str.size(); ++j)
        {
            if(str[j] == 'b' || str[j] == 'd' || str[j] == 'p' || str[j] == 'q') str_cpy.push_back('b');
            if(str[j] == 'n' || str[j] == 'u') str_cpy.push_back('u');
            if(str[j] == 'w')
            {
                str.push_back('v');
                str.push_back('v');
            }
            if(str[j] == 'm')
            {
                str.push_back('n');
                str.push_back('n');
            }
        }
        if(is_palindrome(str_cpy) == true)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
}

void xiaohongshu3_helper(UndirectedGraph* g, GraphNode* start_node, int& max_val, int visited_val, int time_limit, int node_limit)
{
    if(time_limit <= 0 || node_limit <= 0)
    {
        max_val = std::max(max_val, visited_val);
        return;
    }
    for(int j = 0; j < start_node->neighbors.size(); ++j)
    {
        int neighbor_id = start_node->neighbors[j].neighbor;
        int weight = start_node->neighbors[j].weight;
        GraphNode* neighbor_node = g->get_node(neighbor_id);

        if(neighbor_node->visited == true) 
            continue;
        neighbor_node->visited = true;
        xiaohongshu3_helper(g, neighbor_node, max_val, visited_val + neighbor_node->val, time_limit - neighbor_node->cost - weight, node_limit - 1);
        neighbor_node->visited = false;
    }
}

void RealQuestion::xiaohongshu3()
{
    UndirectedGraph* g = new UndirectedGraph();
    int n = 0;//n个景点
    int m = 0;//m条线路
    int k = 0;//游览时间加交通时间上限
    std::cin >> n >> m >> k;
    std::vector<int> a(n, 0);//每个景点的攻略价值
    std::vector<int> h(n, 0);//每个景点的游览时间
    std::vector<std::vector<int>> map(n, std::vector<int>(n, std::numeric_limits<int>::max()));//表示景点之间的交通时间
    for(int i = 0; i < n; ++i)
        std::cin >> a[i];
    for(int i = 0; i < n; ++i)
        std::cin >> h[i];
    for(int i = 0; i < n; ++i)
    {
        g->add_node(i + 1, a[i], h[i]);
    }
    for(int i = 0; i < m; ++i)
    {
        int u = 0;
        int v = 0;
        int w = 0;
        std::cin >> u >> v >> w;
        map[u][v] = w;
        g->add_edge(u, v, w);
    }
    //求最大攻略价值
    int max_val = std::numeric_limits<int>::min();
    for(int i = 0; i < g->nodes.size(); ++i)
    {
        GraphNode* start_node = g->get_node(i + 1);
        g->nodes[i]->visited = true;
        xiaohongshu3_helper(g, start_node, max_val, 0 + g->nodes[i]->val, k - g->nodes[i]->cost, 3 - 1);
        g->nodes[i]->visited = false;
    }
    std::cout << max_val << std::endl;
}

void RealQuestion::meituan2()
{
    //给定一个数组，将其中一个加号变为乘号，求数组之和最大值
    int n = 0;
    int sum = 0;//原始的和
    std::vector<int> nums;
    std::cin >> n;//第一行输入数组的长度n
    //第二行输入n个整数，如1 2 3 4 5 6到数组nums中
    for(int i = 0; i < n; ++i)
    {
        int num = 0;
        std::cin >> num;
        nums.push_back(num);
        sum += num;
    }
    int max_neighbors = std::numeric_limits<int>::min();
    for(int i = 0; i < n - 1; ++i)
    {
        int neighbors_val = nums[i] * nums[i + 1] - nums[i] - nums[i + 1];
        max_neighbors = std::max(max_neighbors, neighbors_val);
    }
    std::cout << sum + max_neighbors << std::endl;
}

//写一个阶乘函数
int factorial(int n)
{
    if(n == 0) return 1;
    return n * factorial(n - 1);
}

//有一个数组a，要求构造数组b，要求数组a和b对应位置的元素不同，但是两个数组之和要相等，且数组a和b都是正整数，求满足条件的b的种数
//例如：a = [1, 2, 3, 4, 5]，b = [4, 1, 5, 2, 3]，a和b对应位置的元素不同，且两个数组之和相等，且a和b都是正整数
//写一下这个函数
long long helper3(std::vector<int>& nums_a, int index, int& sum_a, int sum_b)
{
    if(index == nums_a.size())
    {
        if(sum_b == sum_a)
            return 1;
        else
            return 0;
    }
    long long count = 0;
    int len = sum_a - sum_b - (nums_a.size() - index - 1);
    for(int i = 1; i <= len; ++i)
    {
        if(i == nums_a[index]) continue;//这里表示nums_b[index]不能等于nums_a[index]
        count += helper3(nums_a, index + 1, sum_a, sum_b + i);
    }
    return count;
}

void RealQuestion::meituan4()
{
    int n = 0;
    std::vector<int> nums_a;
    std::vector<int> nums_b;
    int sum_a = 0;//数组a的和
    int count = 0;//种数
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int num = 0;
        std::cin >> num;
        nums_a.push_back(num);
        sum_a += num;
    }
    count = helper3(nums_a, 0, sum_a, 0);
    
    std::cout << count << std::endl;
}

void RealQuestion::dewu_helper2(std::vector<int>& nums, int& min_len, std::vector<int>& path, int target, int sum, int start_idx)
{
    if (sum == target) 
    {
        min_len = std::min(min_len, (int)path.size());
        return;
    }
    for (int i = start_idx; i < nums.size() && sum + nums[i] <= target; i++) {
        path.push_back(nums[i]);
        dewu_helper2(nums, min_len, path, target, sum + nums[i], i + 1);
        path.pop_back();
    }
}

void RealQuestion::dewu2()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    std::vector<int> nums;
    std::unordered_map<int, int> map;
    for(int i = 0; i < n; ++i)
    {
        int num;
        std::cin >> num;
        if(map.find(num) == map.end())
        {
            map[num]++;
            nums.push_back(num);
        }//把重复的去掉后，剩下一个组合的回溯问题
    }
    //从nums中选取若干个数字，使它们和等于m，不允许重复选取同一个数字或者相同的数字，若无解则输出No solution
    int min_len = std::numeric_limits<int>::max();
    std::vector<int> path;
    dewu_helper2(nums, min_len, path, m, 0, 0);
    if(min_len == std::numeric_limits<int>::max())
    {
        std::cout << "No solution" << std::endl;
        return;
    }

    std::cout << min_len << std::endl;
    return;
}

int pool(std::vector<std::vector<int>>& matrix, int n)
{
    if(n == 1)
        return matrix[0][0];
    std::vector<std::vector<int>> new_matrix(n / 2, std::vector<int>(n / 2, 0));
    for(int i = 0; i < n / 2; ++i)
    {
        for(int j = 0; j < n / 2; ++j)
        {
            int a = matrix[2 * i][2 * j];
            int b = matrix[2 * i][2 * j + 1];
            int c = matrix[2 * i + 1][2 * j];
            int d = matrix[2 * i + 1][2 * j + 1];
            int vals[4] = {a, b, c, d};
            std::sort(vals, vals + 4);
            new_matrix[i][j] = vals[2];
        }
    }

    return pool(new_matrix, n / 2);
}

void RealQuestion::weilai1()
{
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            std::cin >> mat[i][j];
        }
    }
    std::cout << pool(mat, n) << std::endl;
}

int weilai3(std::vector<std::vector<int>>& grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int fresh_cnt = 0;
    std::queue<std::pair<int, int>> rotten_que;
    std::vector<std::pair<int, int>> directions({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

    //初始化队列和新鲜苹果的数量
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            if(grid[i][j] == 1)
                fresh_cnt++;
            else if(grid[i][j] == 2)
                rotten_que.push({i, j});
        }
    }
    if(fresh_cnt == 0)
        return 0;

    int minutes = 0;
    while(!rotten_que.empty())
    {
        int que_size = rotten_que.size();
        bool changed = false;
        for(int i = 0; i < que_size; ++i)
        {
            int r = rotten_que.front().first;
            int c = rotten_que.front().second;
            rotten_que.pop();

            for(int j = 0; j < directions.size(); ++j)
            {
                int new_r = r + directions[j].first;
                int new_c = c + directions[j].second;
                if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c] == 1)
                {
                    grid[new_r][new_c] = 2;
                    rotten_que.push({new_r, new_c});
                    fresh_cnt--;
                    changed = true;
                }
            }
        }
        if(changed)
        {
            minutes++;
        }
    }
    return fresh_cnt == 0 ? minutes : -1;
}