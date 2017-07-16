452.删除链表中指定元素  //Remove Linked List Elements
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        // 方法1
        /*
       if (head == nullptr)
            return head;
        ListNode *pCurrent = head;
        ListNode *pPrevious = nullptr;
        while (pCurrent != nullptr)
        {
            if (pCurrent->val == val)
            {
                ListNode *pNodeDelete = pCurrent;
                pCurrent = pCurrent->next;
                if (pPrevious != nullptr)
                    pPrevious->next = pCurrent;
                else
                    head = pCurrent;
                delete pNodeDelete;
            }
            else
            {
                pPrevious = pCurrent;
                pCurrent = pCurrent->next;
            }
        }
        
        return head;
        */
        
        // 方法2
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        while (head->next != NULL)
        {
            if (head->next->val == val)
            {
                ListNode *temp = head->next;
                head->next = head->next->next;
                delete temp;
            }
            else
            {
                head = head->next;
            }
            
        }
        return dummy.next;
    }
};




/// 1. A + B问题，  给出两个整数a和b, 求他们的和, 但不能使用 + 等数学运算符

//解题思路：
//根据提示，本题需要借助位运算模拟加法运算。首先想到的是异或运算，
//按位异或可以模拟一种不进位的加法运算，如二进制的11^10=01，
//每一位异或都相对于每一位的加法，但是缺乏进位。如何解决进位的问题呢？
//由于异或运算仅仅是忽略了进位，那么每次有进位发生时，异或运算相当于忽略了高位的一个1。
//使用按位与“&”运算可以帮助我们判断该位是否有进位。如11&11 =11，
//说明两位在加运算中都产生了进位1。由于该进位是加在高位上的，
//所以很自然的想到了把与运算的结果往左移一位，再和异或结果相加，即为最后结果。
//代码如下：

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        if(a==0)return b;
        if(b==0)return a;
        int x1 = a^b;
        int x2 = (a&b)<<1;
        return aplusb(x1,x2);
    }
};

/// 366. 斐波那契，  查找斐波纳契数列中第 N 个数

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a = 0;
        int b = 1;
        for (int i = 1; i < n; i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};


/// 408.二进制求和

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        int i = a.length() - 1;
        int j = b.length() - 1;
        string result;
        int remainder = 0;
        int sum = 0;
        for (; i >= 0 && j >=0; i--, j--)
        {
            sum = (a[i] - '0') + (b[j] - '0') + remainder;
            remainder = sum / 2;
            sum = sum % 2;
            result += sum + '0';
        }
        for (; i >=0; i--)
        {
            sum = a[i] - '0' + remainder;
            remainder = sum / 2;
            sum = sum % 2;
            result += sum + '0';
        }
        for (; j >= 0; j--)
        {
            sum = b[j] - '0' + remainder;
            remainder = sum / 2;
            sum = sum % 2;
            result += sum + '0';
        }
        if (remainder != 0)
            result += remainder + '0';
        //reverse(result.begin(), result.end());
        int len = result.length();
        for (int k = 0; k < len / 2; k++)
        {
            char temp = result[k];
            result[k] = result[len - k - 1];
            result[len - k - 1] = temp;
        }

        return result;
    }
};


/// 167. 链表求和，
//你有两个用链表代表的整数，其中每个节点包含一个数字。
//数字存储按照在原来整数中相反的顺序，使得第一个数字位于链表的开头。
//写出一个函数将两个整数相加，用链表形式返回和。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode *L1Head = l1;
        ListNode *L2Head = l2;
        ListNode *ResultHead = NULL;
        ListNode *ResultTail = NULL;
        int iCarry = 0;
        int iValue = 0;

        while (L1Head != NULL && L2Head != NULL)
        {
            iValue = L1Head->val + L2Head->val + iCarry;
            iCarry = iValue / 10;
            iValue = iValue % 10;

            ListNode *TempNode = new ListNode(iValue);
            if (TempNode == NULL)
            {
                cerr << "memory allocate failure!" << endl;
                exit(1);
            }
            if (ResultHead == NULL)
            {
                ResultHead = TempNode;
            }
            if (ResultTail != NULL)
            {
                ResultTail->next = TempNode;
            }
            ResultTail = TempNode;
            L1Head = L1Head->next;
            L2Head = L2Head->next;
        }

        while (L1Head != NULL)
        {
            iValue = L1Head->val + iCarry;
            iCarry = iValue / 10;
            iValue = iValue % 10;

            ListNode *TempNode = new ListNode(iValue);
            if (TempNode == NULL)
            {
                cerr << "memory allocate failure!" << endl;
                exit(1);
            }
            if (L1Head == NULL)
            {
                L1Head = TempNode;
            }
            if (ResultTail != NULL)
            {
                ResultTail->next = TempNode;
            }
            ResultTail = TempNode;
            L1Head = L1Head->next;
        }

        while (L2Head != NULL)
        {
            iValue = L2Head->val + iCarry;
            iCarry = iValue / 10;
            iValue = iValue % 10;

            ListNode *TempNode = new ListNode(iValue);
            if (TempNode == NULL)
            {
                cerr << "memory allocate failure !" << endl;
                exit(1);
            }
            if (L2Head == NULL)
            {
                L2Head = TempNode;
            }
            if (ResultTail != NULL)
            {
                ResultTail->next = TempNode;
            }
            ResultTail = TempNode;
            L2Head = L2Head->next;
        }

        if (iCarry != 0)
        {
            ListNode *TempNode = new ListNode(iCarry);
            if (TempNode == NULL)
            {
                cerr << "memory allocate failure!" << endl;
                exit(1);
            }
            ResultTail->next = TempNode;
        }

        return ResultHead;
    }
};



/// 66. 二叉树前序遍历
// 给出一棵二叉树，返回其节点值的前序遍历。

// 自己答案
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        static vector<int> Vaa;
        if (NULL != root)
        {
            Vaa.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        return Vaa;
    }
};


// 九章算法
/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，BAT国内班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

#include <vector>
#include "lintcode.h"

using namespace std;

class Solution {
public:
    vector<int> preorder;

    void traverse(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        preorder.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        preorder.clear();
        traverse(root);
        return preorder;
    }
};


// 67. 二叉树中序遍历
// 给出一棵二叉树,返回其中序遍历

// 自己

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        static vector<int> InOrder;
        if (NULL != root)
        {
            inorderTraversal(root->left);
            InOrder.push_back(root->val);
            inorderTraversal(root->right);
        }
        return InOrder;
    }
};


///  68.二叉树的后序遍历
// 给出一棵二叉树，返回其节点值的后序遍历。

// 自己

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here

        static vector<int> PostOrder;
        if (NULL != root)
        {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            PostOrder.push_back(root->val);
        }
        return PostOrder;
    }
};


/// 93.平衡二叉树
// 给定一个二叉树,确定它是高度平衡的。对于这个问题,
//一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int LeftDepth, RightDepth;
        if (NULL == root)
            return true;
        LeftDepth = Depth(root->left);
        RightDepth = Depth(root->right);

        if (abs(LeftDepth - RightDepth) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;

    }

    int Depth(TreeNode *root)
    {
        int LDepth, RDepth;
        if (NULL == root)
        return -1;
        else
        {
            LDepth = Depth(root->left);
            RDepth = Depth(root->right);
        }
        return 1 + ((LDepth > RDepth) ? LDepth : RDepth);
    }
};


/// 480. 二叉树的所有路径
// 给一棵二叉树，找出从根节点到叶子节点的所有路径。

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<string> result;
        if (NULL == root)
            return result;
        else
        {
            binaryPathFind(root, result, to_string(root->val));
            return result;
        }
    }

    void binaryPathFind(TreeNode *root, vector<string> &path, string str)
    {
        if (NULL == root->left && NULL == root->right)
        {
            path.push_back(str);
            return;
        }
        if (NULL != root->left)
            binaryPathFind(root->left, path, str + "->" + to_string(root->left->val));
        if (NULL != root->right)
            binaryPathFind(root->right, path, str + "->" + to_string(root->right->val));
    }
};

/// 111. 爬楼梯
// 假设你正在爬楼梯，需要n步你才能到达顶部。但每次你只能爬一步或者两步，你能有多少种不同的方法爬到楼顶部？

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if (0 == n || 1 == n)
            return 1;
        else
        {
            int a = 0;
            int b = 1;
            int c;
            for (int i = 0; i < n; i++)
            {
                c = a + b;
                a = b;
                b = c;
            }
            return c;
            //return climbStairs(n - 1) + climbStairs( n - 2);
        }
    }
};


/// 55. 比较字符串
// 比较两个字符串A和B，确定A中是否包含B中所有的字符。字符串A和B中的字符都是 大写字母
//注意事项
//在 A 中出现的 B 字符串里的字符不需要连续或者有序。

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int CountAlpha[26] = {0};

        for (int i = 0; i < A.length(); i++)
            CountAlpha[A[i] - 'A']++;
        for (int i = 0; i < B.length(); i++)
        {
            CountAlpha[B[i] - 'A']--;
            if (CountAlpha[B[i] - 'A'] < 0)
                return false;
        }
        return true;
    }
};


//solution self

        map<char, int> CountAlpha;
        for (const auto it : A)
        	++CountAlpha[it];
        for (const auto it : B)
        {
        	auto iter = CountAlpha.find(it);
        	if (CountAlpha.cend() == iter)
		        return false;
	        else
	        {
	        	if (--(iter->second) < 0)
		        	return false;
        	}
        }
        return true;


/// 177.  把排序数组转换为高度最小的二叉搜索树
// 给一个排序数组（从小到大），将其转换为一棵高度最小的排序二叉树。
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if (A.empty())
            return nullptr;
        int start = 0;
        int end = A.size() - 1;
        int mid = (start + end) / 2;
        TreeNode *tree_root = new TreeNode(A[mid]);
        tree_root->left = SortedArrayToBSTCore(A, start, mid - 1);
        tree_root->right = SortedArrayToBSTCore(A, mid + 1, end);
        return tree_root;
    }

    TreeNode *SortedArrayToBSTCore(const vector<int> &A, int start, int end)
    {
        if (start > end)
            return nullptr;
        int mid = (start + end) / 2;
        TreeNode *tree_root = new TreeNode(A[mid]);
        tree_root->left = SortedArrayToBSTCore(A, start, mid - 1);
        tree_root->right = SortedArrayToBSTCore(A, mid + 1, end);
        return tree_root;
    }
};

/// 445.  余弦相似度
///media/problem/cosine-similarity.png
//给你两个相同大小的向量 A B，求出他们的余弦相似度
//返回 2.0000 如果余弦相似不合法 (比如 A = [0] B = [0]).
// 样例
// 给出 A = [1, 2, 3], B = [2, 3 ,4].
// 返回 0.9926.
// 给出 A = [0], B = [0].
// 返回 2.0000

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int squre_sum_A = 0;
        int squre_sum_B = 0;

        for (int i = 0; i < A.size(); i++)
        {
            squre_sum_A = squre_sum_A + A[i] * A[i];
            squre_sum_B = squre_sum_B + B[i] * B[i];
        }
        if (0 == squre_sum_A || 0 == squre_sum_B)
            return 2.0000;
        double squre_sum_sqrt_A = sqrt(squre_sum_A);
        double squre_sum_sqrt_B = sqrt(squre_sum_B);

        int inner_product = 0;
        for (int i = 0; i < A.size(); i++ )
        {
            inner_product = inner_product + A[i] * B[i];
        }
        return static_cast<double> (inner_product / squre_sum_sqrt_A / squre_sum_sqrt_B);
        //return double(inner_product / (squre_sum_sqrt_A * squre_sum_sqrt_B));
    }
};



/// 365. 二进制中有多少个1
// 计算在一个 32 位的整数的二进制表式中有多少个 1

// 方法1
// 如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1
// ，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。
// 其余所有位将不会受到影响。举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。
// 减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.
// 我们发现减1的结果是把最右边的一个1开始的所有位都取反了。
// 这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。
// 如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，
// 会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here

        int one_count = 0;
        while (num != 0)
        {
            one_count++;
            num = num & (num - 1);
        }
        return one_count;

    }

};

// 方法2
// 使用右移操作, -1>>1之后还是-1，也即是说负数需要特殊处理，为了解决这个问题，只需要把int型转换成unsigned int型。
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here

        int one_count = 0;
        unsigned unsigned_num = num;

        while (unsigned_num != 0)
        {
            one_count += 1 & unsigned_num;
            unsigned_num >>= 1;
        }
        return one_count;

    }

};

// 方法3
class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here

        int one_count = 0;
        unsigned unsigned_num = num;

        while (unsigned_num != 0)
        {
            if (1 == unsigned_num % 2)
            one_count++;
            unsigned_num = unsigned_num / 2;
        }
        return one_count;
    }

};

// 方法4

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        // write your code here

        int value[32] = {0};
        int index = 31;
        int one_count = 0;
        unsigned unsigned_num = num;
        TransDecimalToBinary(unsigned_num, value, index);
        for(const auto &it : value)
        {
            if (1 == it)
                one_count++;
        }
        return one_count;
    }

    void TransDecimalToBinary(unsigned num_to_binary, int *value, int &index)
    {
        if (0 == num_to_binary || 1 == num_to_binary)
            value[index--] = num_to_binary;
        else
        {
            value[index--] = num_to_binary % 2;
            TransDecimalToBinary(num_to_binary / 2, value, index);
        }
    }
};


/// 420. 报数
//报数指的是，按照其中的整数的顺序进行报数，然后得到下一个数。如下所示：
//1, 11, 21, 1211, 111221, ...
//1 读作 "one 1" -> 11.
//11 读作 "two 1s" -> 21.
//21 读作 "one 2, then one 1" -> 1211.
//给定一个整数 n, 返回 第 n 个顺序。
// 注意事项
//整数的顺序将表示为一个字符串。
//样例
//给定 n = 5, 返回 "111221".

// 方法1 self
class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        // Write your code here
        if (1 == n)
            return to_string(1);
        else
        {
            string count_say{"1"};
            int num_count = 1;
            int index = 1;
            while(index != n)
            {
                string result;
                int str_length = count_say.length();
                for (int i = 0; i < str_length; i++)
                {
                    if (i + 1 < str_length && count_say[i + 1] == count_say[i])
                        ++num_count;
                    else
                    {
                        result = result + to_string(num_count) + count_say[i];
                        num_count = 1;
                    }
                }
                ++index;
                count_say = result;
            }
            return count_say;
        }
    }
};

// 方法2
class Solution {
public:
    string countAndSay(int n) {
        string s("1");

        while (--n)
            s = getNext(s);

        return s;
    }

    string getNext(const string &s) {
        stringstream ss;

        for (auto i = s.begin(); i != s.end(); ) {
            auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
            ss << distance(i, j) << *i;
            i = j;
        }

        return ss.str();
    }
};


/// 372. 在O(1)时间复杂度删除链表节点
// 给定一个单链表中的一个等待被删除的节点(非表头或表尾)。请在在O(1)时间复杂度删除该链表节点。
// 样例
// 给定 1->2->3->4，和节点 3，删除 3 之后，链表应该变为 1->2->4。
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        ListNode *next_node = node->next;
        node->val = next_node->val;
        node->next=next_node->next;
        delete next_node;
    }
};



/// 14.二分查找
// 给定一个排序的整数数组（升序）和一个要查找的整数target，
// 用O(logn)的时间查找到target第一次出现的下标（从0开始），如果target不存在于数组中，返回-1

// 方法1
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int start = 0;
        int end = array.size() - 1;
        vector<int> index_result;
        BinarySearchCore(array, target, start, end, index_result);
        if (!index_result.empty())
            return *min_element(index_result.cbegin(), index_result.cend());
        else
            return -1;
    }
    
    void BinarySearchCore(vector<int> &array, const int &target, int start, int end,
                            vector<int> &result)
        {
            if (start > end)
                return;
            int middle = (start + end) / 2;
            if (target < array[middle])
                BinarySearchCore(array, target, start, middle - 1, result);
            else if (target > array[middle])
                BinarySearchCore(array, target, middle + 1, end, result);
            else
            {
                result.push_back(middle);
                BinarySearchCore(array, target, start, middle - 1, result);
            }
        }
};

// 方法2
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        auto bound = equal_range(array.cbegin(), array.cend(), target);  //pair<vector<int>::iterator, vector<int>::iterator> bound;
        if (bound.first != bound.second)
            return min_element(bound.first, bound.second) - array.begin();
        else
            return -1;
		
		int left = 0;
        int right = array.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (right - left) / 2 + left;
            if (target < array[mid])
                right = mid - 1;
            else if (target > array[mid])
                left = mid +1;
            else
                right = mid;
        }
        if(array[right] == target)
            return right;
        else
            return -1;
    }  
};

// 方法3
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
		int left = 0;
        int right = array.size() - 1;
        int mid;
        while (left < right)
        {
            mid = (right - left) / 2 + left;
            if (target < array[mid])
                right = mid - 1;
            else if (target > array[mid])
                left = mid +1;
            else
                right = mid;
        }
        if(array[right] == target)
            return right;
        else
            return -1;
    }  
};





class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> results;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                results.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                results.push_back("buzz");
            } else if (i % 3 == 0) {
                results.push_back("fizz");
            } else {
                results.push_back(to_string(i));
            }
        }
        return results;
    }
};


/// 375,克隆二叉树
// 深度复制一个二叉树，给定一个二叉树，返回一个他的 克隆品 

// 方法1：
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        if (nullptr == root)
            return nullptr;
        TreeNode *clone_root = new TreeNode(root->val);
        clone_root->left = cloneTree(root->left);
        clone_root->right = cloneTree(root->right);
        return clone_root;     
    }
};


// 方法2：
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
        TreeNode *newroot = nullptr;
        if (nullptr == root)
        {
            return nullptr;
        }
        else
        {
            preorderTraversal(root, &newroot);
            return newroot;
        }
    }
    
    void preorderTraversal(TreeNode *root, TreeNode **newroot)
    {
        if (root != nullptr)
        {
            *newroot = new TreeNode;
            (*newroot)->val = root->val;
            preorderTraversal(root->left, &((*newroot)->left));
            preorderTraversal(root->right, &((*newroot)->right));
        }
        else
        {
            *newroot = nullptr;
        }
    }
};


/// 22. 平面列表
// 给定一个列表，该列表中的每个要素要么是个列表，要么是整数。将其变成一个只包含整数的简单列表。
 // 注意事项
// 如果给定的列表中的要素本身也是一个列表，那么它也可以包含列表。
// 样例
// 给定 [1,2,[1,2]]，返回 [1,2,1,2]。
// 给定 [4,[3,[2,[1]]]]，返回 [4,3,2,1]。
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nestedList) {
        // Write your code here
        vector<int> result;
        for (auto each : nestedList)
        {
            if (each.isInteger())
            {
                result.push_back(each.getInteger());
            }
            else
            {
                vector<NestedInteger> sub_list = each.getList();
                auto temp = flatten(sub_list);
                result.insert(result.end(), temp.begin(), temp.end());
            }
        }
        return result;
    }
};



/// 128. 哈希函数
// 在数据结构中，哈希函数是用来将一个字符串（或任何其他类型）转化为小于哈希表大小且大于等于零的整数。一个好的哈希函数可以尽可能少地产生冲突。一种广泛使用的哈希函数算法是使用数值33，假设任何字符串都是基于33的一个大整数，比如：
// hashcode("abcd") = (ascii(a) * 333 + ascii(b) * 332 + ascii(c) *33 + ascii(d)) % HASH_SIZE 
                              // = (97* 333 + 98 * 332 + 99 * 33 +100) % HASH_SIZE
                              // = 3595978 % HASH_SIZE
// 其中HASH_SIZE表示哈希表的大小(可以假设一个哈希表就是一个索引0 ~ HASH_SIZE-1的数组)。
// 给出一个字符串作为key和一个哈希表的大小，返回这个字符串的哈希值。

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        /*  // 不正确
        int key_length = key.length();
        long long sum = 0;
        for (int i = key_length - 1; i != -1; i--)
        {
            sum += (int)(key[i]) * pow(33, i);
        }
        return sum % HASH_SIZE;
        */
        
        // 正确
        int ans = 0;
        for(int i = 0; i < key.size();i++) {
            ans = (1LL * ans * 33 + key[i]) % HASH_SIZE; 
        }
	    return ans;
	    
    }
};


/// 469.等价二叉树
// 检查两棵二叉树是否等价。等价的意思是说，首先两棵二叉树必须拥有相同的结构，并且每个对应位置上的节点上的数都相等。

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @aaram a, b, the root of binary trees.
     * @return true if they are identical, or false.
     */
    bool isIdentical(TreeNode* a, TreeNode* b) {
        // Write your code here
        if ((nullptr == a && nullptr != b) || (nullptr != a && nullptr == b))
            return false;
        else if (nullptr == a && nullptr == b)
            return true;
        else
        {
            if (a->val != b->val)
                return false;
            else return (isIdentical(a->left, b->left) && isIdentical(a->right, b->right));
        }
    }
};


/// 30.插入区间
// 给出一个无重叠的按照区间起始端点排序的区间列表。
// 在列表中插入一个新的区间，你要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
// 您在真实的面试中是否遇到过这个题？ Yes
// 样例
// 插入区间[2, 5] 到 [[1,2], [5,9]]，我们得到 [[1,9]]。
// 插入区间[3, 4] 到 [[1,2], [5,9]]，我们得到 [[1,2], [3,4], [5,9]]。
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
bool com(Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), com);
        int len = intervals.size();
        vector<Interval> res;
        int i = 0;
        for (i = 1; i < len; i++)
        {
            while (intervals[i].start <= intervals[i - 1].end && i < len)
            {
                intervals[i].start = intervals[i - 1].start;
                intervals[i].end = intervals[i].end > intervals[i - 1].end ? 
                    intervals[i].end : intervals[i - 1].end;
                i++;
            }
            res.push_back(intervals[i - 1]);
            if (i >= len)
            {
                return res;
            }
        }
        res.push_back(intervals[i - 1]);
        return res;
    }
};

/// 85.在二叉查找树中插入节点
// 给定一棵二叉查找树和一个新的树节点，将节点插入到树中。
// 你需要保证该树仍然是一棵二叉查找树。


// 方法1
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        
        if (root == nullptr)
        {
            return node;
        }
        if (node->val < root->val)
        {
            root->left = insertNode(root->left, node);
            return root;
        }
        else
        {
            root->right = insertNode(root->right, node);
            return root;
        }
    }
};

// 方法2
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        /*
        TreeNode *head = root;
        TreeNode *previous = nullptr;
        while (head != nullptr)
        {
            previous = head;
            if (head->val > node->val)
            {
                //previous = head;
                head = head->left;
            }
            //if (head->val < node->val)
            else
            {
                //previous = head;
                head = head->right;
            }
        }
        
        if (nullptr == previous)
            return node;
        else if (previous->val > node->val)
            previous->left = node;
        //else if (previous->val < node->val)
        else
            previous->right = node;
        return root;   
    }
};


/// 173. 链表插入排序
// 用插入排序对链表排序
// 思路，创建一个哑节点， 将链表中的节点一个一个插入哑节点开始的链表中，返回哑节点链表

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (nullptr == head)
        {
            return nullptr;
        }
        
        ListNode *dummy = new ListNode; // 创建一个以哑节点为头节点的链表
        ListNode *temp = nullptr;
        while (head != nullptr)
        {
            temp = dummy;
            ListNode *next = head->next;
            // 在哑节点链表中寻找插入节点，往该节点后面插入
            while (temp->next != nullptr && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        temp = dummy;
        dummy = dummy->next;
        delete temp;
        return dummy;
    }
};

// 相同方法，另一种编程表示
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        // 思路，创建一个哑节点， 将链表中的节点一个一个插入哑节点开始的链表中，返回哑节点链表
        if (NULL == head)
        {
            return head;
        }
        ListNode dummy;// 哑节点
        ListNode *temp;
        while (NULL != head)
        {
            temp = &dummy;
            // 保存源链表中头结点的下一个节点
            ListNode *next = head->next;
            // 在哑节点链表中寻找插入节点，往该节点后面插入
            while (temp->next != NULL && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            // 在哑节点链表中找到插入点temp，在temp之后插入head节点，需要将temp之后的链表接到
            // head节点之后
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy.next;
    }
};

/// 35. 翻转一个链表  Reverse Linked List
// 给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        // 1. 采用头插法反转
        /*
        if (nullptr == head)
        {
            return nullptr;
        }
        ListNode *dummy_head = new ListNode;
        ListNode *temp = nullptr;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            temp->next = dummy_head->next;
            dummy_head->next = temp;
        }
        temp = dummy_head;
        dummy_head = dummy_head->next;
        delete temp;
        return dummy_head;
        */
        
        // 2.在原链表上进行反转
        ListNode *pre = nullptr;
        while (head != nullptr)
        {
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        return pre;
    }
};


/// 547. 两数组的交 the intersection of two arrays
// 返回两个数组的交
// nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2]
class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> intersect;
        vector<int>::iterator it1 = nums1.begin(), it2 = nums2.begin();
        while ((it1 != nums1.end()) && (it2 != nums2.end()))
        {
            if (*it1 < *it2) it1++;
            else if (*it1 > *it2) it2++;
            else 
            {
                intersect.push_back(*it1); 
                it1++; it2++;
            }
        }

        auto last = unique(intersect.begin(), intersect.end());
        intersect.erase(last, intersect.end());
        return intersect;

		// 方法2
        /*
        int len = nums1.size() + nums2.size();
        vector<int> intersection(len);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto it = set_intersection(nums1.begin(), nums1.end(),
                    nums2.begin(), nums2.end(), intersection.begin());
        intersection.resize(it - intersection.begin());
        auto last = unique(intersection.begin(), intersection.end());
        intersection.erase(last, intersection.end());
        return intersection;
        */
        // 方法3
        /*
        vector<int> result;
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        unordered_set<int> nums2_set(nums2.begin(), nums2.end());
        for (const auto &each : nums2_set)
        {
            if (nums1_set.find(each) != nums1_set.end())
            {
                result.push_back(each);
            }
        }
        return result;
		*/
    }
};

/// 548.两数组的交 II
// 计算两个数组的交
// 注意事项
// 每个元素出现次数得和在数组里一样
// 答案可以以任意顺序给出

// 样例
// nums1 = [1, 2, 2, 1], nums2 = [2, 2], 返回 [2, 2].

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        // 方法1
        /*
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len = nums1.size() + nums2.size();
        vector<int> result(len);
        auto last = set_intersection(nums1.begin(), nums1.end(),
                    nums2.begin(), nums2.end(), result.begin());
        result.resize(last - result.begin());
        return result;
        */
        
        // 方法2
        /*
        vector<int> result;
        unordered_map<int, int> count_map;
        for (const auto &each : nums1)
        {
            ++count_map[each];
        }
        for (const auto &each : nums2)
        {
            if (count_map[each] > 0)
            {
                result.push_back(each);
                --count_map[each];
            }
            
        }
        return result;
        */
        // 方法3
        vector<int> result;
        unordered_multiset<int> temp_set(nums1.begin(), nums1.end());
        for (auto each : nums2)
        {
            auto find_result = temp_set.find(each);
            if (find_result != temp_set.end())
            {
                result.push_back(each);
                temp_set.erase(find_result);
            }
        }
        return result;
    }
};

if (!root) return;
queue<TreeNode*> level;
level.push(root);
while (!level.empty()) 
{
	TreeNode* node = level.front();
    level.pop();
    swap(node -> left, node -> right);
    if (node -> left) level.push(node -> left);
    if (node -> right) level.push(node -> right);
}


/// 175. 翻转二叉树  Invert Binary Tree
// 翻转一棵二叉树
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        // 方法1 递归
        /*
        if (root != nullptr)
        {
            //TreeNode *temp = root->left;
            //root->left = root->right;
            //root->right = temp;
            swap(root->left, root->right);
            invertBinaryTree(root->left);
            invertBinaryTree(root->right);
        }
        */
        
        // 方法2 迭代
        if (!root)
			return;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) 
        {
	        TreeNode* node = level.front();
            level.pop();
            swap(node -> left, node -> right);
            if (node -> left) 
            level.push(node -> left);
            if (node -> right) 
            level.push(node -> right);
        }
        
    }
};

/// 524. 左填充
// 实现一个leftpad库，如果不知道什么是leftpad可以看样例
// leftpad("foo", 5)
// >> "  foo"
// leftpad("foobar", 6)
// >> "foobar"
// leftpad("1", 2, "0")
// >> "01"

// 备注：size小于originalStr长度时，直接返回originalStr

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        string result_string;
        int string_length = originalStr.size();
        if (size <= string_length)
        {
            result_string = originalStr;
        }
        else
        {
            unsigned length_error = size - string_length;
            result_string.append(length_error, padChar);
            result_string.append(originalStr);
        }
        return result_string;
    }
};

///. 422 最后一个单词的长度
// 给定一个字符串， 包含大小写字母、空格' '，请返回其最后一个单词的长度。
// 如果不存在最后一个单词，请返回 0 。
 // 注意事项
// 一个单词的界定是，由字母组成，但不包含任何的空格。
// 给定 s = "Hello World"，返回 5。

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int string_length = s.size();
        unsigned pos;
		// 删除最后一个单词后的空格
        pos = s.find_last_not_of(' ');
        if ((int)pos != string_length - 1)
        {
            s.erase((string::iterator)(&s[pos + 1]), s.end());
        }

        pos = s.rfind(' ');
        //auto pos = s.find_last_of(' ');
        if (pos == string::npos)
        {
            return string_length;
        }
        else
        {
            return string_length - (int)(pos) - 1;
        }
    }
};

///.397 最长上升连续子序列

// 给定一个整数数组（下标从 0 到 n-1， n 表示整个数组的规模），请找出该数组中的最长上升连续子序列。（最长上升连续子序列可以定义为从右到左或从左到右的序列。）
// 样例
// 给定 [5, 4, 2, 1, 3], 其最长上升连续子序列（LICS）为 [5, 4, 2, 1], 返回 4.

// 给定 [5, 1, 2, 3, 4], 其最长上升连续子序列（LICS）为 [1, 2, 3, 4], 返回 4.


class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int vector_size = A.size();
        if (0 == vector_size)
        {
            return 0;
        }
        int max_increase_nums = 1;
        int increase_nums = 1;
        int max_decrease_nums = 1;
        int decrease_nums = 1;
        for (int i = 1; i < vector_size; i++)
        {
            if (A[i] > A[i - 1])
            {
                increase_nums++;
            }
            else
            {
                increase_nums = 1;
            }
            if (increase_nums > max_increase_nums)
            {
                max_increase_nums = increase_nums;
            }
            
            if (A[i] < A[i - 1])
            {
                decrease_nums++;
            }
            else
            {
                decrease_nums = 1;
            }
            if (decrease_nums > max_decrease_nums)
            {
                max_decrease_nums = decrease_nums;
            }
        }
        return (max_increase_nums > max_decrease_nums) ? max_increase_nums : max_decrease_nums;
    }
};

// 九章算法答案
/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        int max = 1, s = 1, l = 1;
        int len = A.size();
        if (len == 0)
            return 0;
        for (int i = 1; i < len; ++i) {
            if (A[i] > A[i-1])
                s += 1;
            else {
                if (s > max) max = s;
                s = 1;
            } 
            
            if (A[i] < A[i-1])
                l += 1;
            else {
                if (l > max) max = l;
                l = 1;
            } 
        }
        if (s > max) max = s;
        if (l > max) max = l;
        return max;
    }
};


///. 133.最长单词
// 给一个词典，找出其中所有最长的单词。
// 在词典

// {
  // "dog",
  // "google",
  // "facebook",
  // "internationalization",
  // "blabla"
// }
// 中, 最长的单词集合为 ["internationalization"]

// 在词典

// {
  // "like",
  // "love",
  // "hate",
  // "yes"
// }
// 中，最长的单词集合为 ["like", "love", "hate"]

// 方法1
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
     struct comp
     {
         bool operator() (const string &first, const string &second) const
         {
             return first.size() < second.size();
         }
     }mycomp;
     
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        
        vector<string> result_vector_string;
        int vector_size = dictionary.size();
        if (0 == vector_size)
        {
            return result_vector_string;
        }
        int max_string_length = dictionary[0].size();
        for (int  i = 1; i < vector_size; i++)
        {
            if (dictionary[i].size() > max_string_length)
            {
                max_string_length = dictionary[i].size();
            }
        }
        for (int i = 0; i < vector_size; i++)
        {
            if (dictionary[i].size() == max_string_length)
            {
                result_vector_string.push_back(dictionary[i]);
            }
        }
        return result_vector_string;
    }
};

// 方法2
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
     struct comp
     {
         bool operator() (const string &first, const string &second) const
         {
             return first.size() < second.size();
         }
     }mycomp;
     
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        
        multiset<string, comp> set_string(dictionary.begin(), dictionary.end());
        //multiset<string, comp> set_string;
        //set_string.insert(dictionary.begin(), dictionary.end());
        auto pos = max_element(set_string.begin(), set_string.end(), mycomp);
        vector<string> result_vector_string(pos, set_string.end());
        return result_vector_string;
    }
};


/// 46.主元素
// 给定一个整型数组，找出主元素，它在数组中的出现次数严格大于数组元素个数的二分之一。
// 样例
// 给出数组[1,1,1,1,2,2,2]，返回 1

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
     struct COMP
     {
         bool operator()(pair<int, int> a, pair<int, int> b)
         {
            return a.second < b.second;
        } 
     }comp;
    
    int majorityNumber(vector<int> nums) {
        // write your code here
        /*
        int result = 0;
        int n = 0;
        int vector_size = nums.size();
        for (int i = 0; i < vector_size; i++)
        {
            if (0 == n)
            {
                result = nums[i];
                n++;
            }
            else
            {
                if (result == nums[i])
                {
                    n++;
                }
                else
                {
                    n--;
                }
            }
        }
        return result;
        */
        
        sort(nums.begin(), nums.end());
        int vector_size = nums.size();
        return nums[vector_size / 2];
        
    }
};


///。185 矩阵的之字型遍历
// 给你一个包含 m x n 个元素的矩阵 (m 行, n 列), 求该矩阵的之字型遍历
// 样例
// 对于如下矩阵：

// [
  // [1, 2,  3,  4],
  // [5, 6,  7,  8],
  // [9,10, 11, 12]
// ]
// 返回 [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

// 方法1， 未看懂

/**
 * 本代码由九章算法编辑提供。没有版权欢迎转发。
 * - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
 * - 现有的面试培训课程包括：九章算法班，系统设计班，九章强化班，Java入门与基础算法班
 * - 更多详情请见官方网站：http://www.jiuzhang.com/
 */

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> z;
        if (matrix.size()==0) return z;
        else
            if (matrix[0].size()==0) return z;
        int x, y, dx, dy, count, m, n;
        x = y = 0;
        count = 1;
        dx = -1; dy = 1; 
        m = matrix.size();
        n = matrix[0].size();
        z.push_back(matrix[0][0]);
        while (count<m*n) {
            if (x+dx>=0 && y+dy>=0 && x+dx<m && y+dy<n) {
                x += dx; y += dy;   
            }        
            else
                if (dx==-1 && dy == 1) {
                    if (y+1<n) ++y; else ++x;
                    dx = 1; dy = -1;
                }
                else {
                    if (x+1<m) ++x; else ++y;
                    dx = -1; dy = 1;                
                }
            z.push_back(matrix[x][y]); ++count;       
        }
        return z;
    }
};

// 方法2
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> result;
        int row = matrix.size();
        int column = matrix[0].size();
        if (0 == row)
            return result;
        if (0 == column)
            return result;
        result.push_back(matrix[0][0]);
        bool forward = true;
        for (int j = 1; j < column; j++)
        {
            int m;
            int n;
            vector<int> temp;
            for (m = 0, n = j; n >=0 && m < row; n--, m++)
            {
                temp.push_back(matrix[m][n]);
            }
            if (!forward)
            {
               reverse(temp.begin(), temp.end());
            }
            result.insert(result.end(), temp.begin(), temp.end());
            forward = !forward;
        }
        for (int i = 1; i < row; i++)
        {
            int m;
            int n;
            vector<int> temp;
            for (m = i, n = column - 1; m < row && n >= 0; m++, n--)
            {
                temp.push_back(matrix[m][n]);
            }
            if (!forward)
            {
               reverse(temp.begin(), temp.end());
            }
            result.insert(result.end(), temp.begin(), temp.end());
            forward = !forward;
        }
        return result;
    }
};


/// 97.二叉树的最大深度
// 给定一个二叉树，找出其最大深度。
// 二叉树的深度为根节点到最远叶子节点的距离。

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (nullptr == root)
        {
            return 0;
        }
        else
        {
            int left_depth = maxDepth(root->left);
            int right_depth = maxDepth(root->right);
            return (left_depth > right_depth ? left_depth : right_depth) + 1;
        }
    }
};

/// 41.最大子数组
// 给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。

 // 注意事项

// 子数组最少包含一个数
// 样例
// 给出数组[?2,2,?3,4,?1,2,1,?5,3]，符合要求的子数组为[4,?1,2,1]，其最大和为6

// 方法1 时间复杂度超出要求 O(n2)
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        
        int nums_size = nums.size();
        vector<int> max_subarray = {nums[0]};
        for (int i = 0; i < nums_size; i++)
        {
            for (int j = i + 1; j <= nums_size; j++)  
            //j <= nums_size必须有等号，否则无法获取最后一个元素
            {
                int max_subarray_sum = accumulate(max_subarray.begin(), max_subarray.end(),
                        0);
                int sub_vector_sum = accumulate((vector<int>::iterator)(&nums[i]),
                    (vector<int>::iterator)(&nums[j]), 0);
                if (sub_vector_sum > max_subarray_sum)
                {
                    max_subarray.assign((vector<int>::iterator)(&nums[i]),
                                        (vector<int>::iterator)(&nums[j]));
                }
            }
        }
        
        return accumulate(max_subarray.begin(), max_subarray.end(),0);
        
    }
};

// 方法2  原理不懂
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        
        int sum = 0, minSum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum - minSum);
            minSum = min(minSum, sum);
        }
        return maxSum;
    }
};

// 方法3 时间复杂度 O（n）

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
     
        int size = nums.size();
        int cur_sum = nums[0];  // 以下标i为起点的最大连续和
        int max_sum = nums[0];  // 前i个元素的最大子数组和
        for (int i = 1; i < size; i++)
        {
            if (cur_sum < 0)
            {
                cur_sum = 0;
            }
            cur_sum += nums[i];
            if (cur_sum > max_sum)				//如果累加和出现小于0的情况，则和最大的子序列肯定不可能包含前面的元素，
            {                                   // 这时将累加和置0，从下个元素重新开始累加
                max_sum = cur_sum;
            }
        }
        return max_sum;
        
    }
};


///. 中位数
// 给定一个未排序的整数数组，找到其中位数。
// 中位数是排序后数组的中间值，如果数组的个数是偶数个，则返回排序后数组的第N/2个数。
// 给出数组[4, 5, 1, 2, 3]， 返回 3
// 给出数组[7, 9, 4, 5]，返回 5

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
		// 方法1
        /*
        sort(nums.begin(), nums.end());
        int nums_length = nums.size();
        return nums[(nums_length - 1) / 2];
        */

		// 方法2
        int k = (nums.size() + 1) / 2;
        priority_queue<int> que;
        int len = nums.size();
        for(int i = 0; i < len; i ++) {
            if(que.size() == k) {
                if(nums[i] < que.top()) {
                    que.pop();
                    que.push(nums[i]);
                }
            }else {
                que.push(nums[i]);
            }
        }
        return que.top();
    }
};


///.156 合并区间

// 给出若干闭合区间，合并所有重叠的部分。
// 给出的区间列表 => 合并后的区间列表：

// [                     [
  // [1, 3],               [1, 6],
  // [2, 6],      =>       [8, 10],
  // [8, 10],              [15, 18]
  // [15, 18]            ]
// ]


/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
 struct COM
 {
     bool operator()(const Interval &a, const Interval &b)
     {
         return a.start < b.start;
     }
 }com;
 
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        // 方法1
        /*
        int len = intervals.size();
        if (0 == len)
            return intervals;
        sort(intervals.begin(), intervals.end(), com);
        vector<Interval> result;
        int i = 0;
        for (i = 1; i < len; i++)
        {
            while (intervals[i].start <= intervals[i - 1].end && i < len)
            {
                intervals[i].start = intervals[i - 1].start;
                intervals[i].end = intervals[i].end > intervals[i - 1].end ?
                                    intervals[i].end : intervals[i - 1].end;
                i++;
            }
            result.push_back(intervals[i - 1]);
            if (i >= len)
            {
                return result;
            }
        }
        result.push_back(intervals[i - 1]);
        return result;
        */
        
        // 方法2
        if (intervals.empty())
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), com);
        int length = intervals.size();
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < length; i++)
        {
            if (intervals[i].start <= result.back().end)
            {
                Interval temp(result.back().start, max(intervals[i].end, result.back().end));
                result.pop_back();
                result.push_back(temp);
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};


///.6 合并两个排序的整数数组A和B变成一个新的数组。
// 给出A=[1,2,3,4]，B=[2,4,5,6]，返回 [1,2,2,3,4,4,5,6]

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        // 方法1
        /*
        multiset<int> set_result(A.begin(), A.end());
        set_result.insert(B.begin(), B.end());
        vector<int> result(set_result.begin(), set_result.end());
        return result;
        */
        
        // 方法2
        /*
        vector<int> result(A.begin(), A.end());
        result.insert(result.end(), B.begin(), B.end());
        sort(result.begin(), result.end());
        return result;
        */
        
        // 方法3
        vector<int> result;
        int length_A = A.size();
        int length_B = B.size();
        int i = 0;
        int j = 0;
        while (i < length_A && j < length_B)
        {
            int temp = A[i] < B[j] ? A[i++] : B[j++];
            result.push_back(temp);
        }
        while (i < length_A)
        {
            result.push_back(A[i++]);
        }
        while (j < length_B)
        {
            result.push_back(B[j++]);
        }
        return result;
    }
};


///.64 合并排序数组 II  Merge Sorted Array
// 合并两个排序的整数数组A和B变成一个新的数组。

 // 注意事项

// 你可以假设A具有足够的空间（A数组的大小大于或等于m+n）去添加B中的元素。
// 给出 A = [1, 2, 3, empty, empty], B = [4, 5]

// 合并之后 A 将变成 [1,2,3,4,5]

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int pos = m + n -1;
        int i = m -1;
        int j = n - 1;
        while (i >= 0 && j >= 0)
        {
            A[pos--] = A[i] > B[j] ? A[i--] : B[j--];
        }
        while (i >= 0)
        {
            A[pos--] = A[i--];
        }
        while (j >= 0)
        {
            A[pos--] = B[j--];
        }
    }
};


/// 165.合并两个排序链表  Merge Two Sorted Lists

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 * int val;
 * ListNode *next;
 * ListNode(int val) {
 * this->val = val;
 * this->next = NULL;
 * }
 * }
 */
class Solution {
public:
 /**
 * @param ListNode l1 is the head of the linked list
 * @param ListNode l2 is the head of the linked list
 * @return: ListNode head of linked list
 */
 ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
 // write your code here
 // 方法1
 /*
 ListNode *head1 = l1;
 ListNode *head2 = l2;
 ListNode *dummy = new ListNode;
 ListNode *head = dummy;
 while (head1 != NULL && head2 != NULL)
 {
    int temp_val;
    if (head1->val < head2->val)
    {
        temp_val = head1->val;
        head1 = head1->next;
    }
    else
    {
        temp_val = head2->val;
        head2 = head2->next;
    }
    head->next = new ListNode(temp_val, NULL);
    head = head->next;
 }
 while (head1 != NULL)
 {
     head->next = new ListNode(head1->val, NULL);
     head1 = head1->next;
     head = head->next;
 }
 while (head2 != NULL)
 {
     head->next = new ListNode(head2->val, NULL);
     head2 = head2->next;
     head = head->next;
 }
 head = dummy->next;
 delete dummy;
 return head;
 */
 
 // 方法2
 ListNode *dummy = new ListNode(0);
 ListNode *temp = dummy;
 while (NULL != l1 && NULL != l2)
 {
     if (l1->val < l2->val)
     {
         temp->next = l1;
         l1 = l1->next;
     }
     else
     {
         temp->next = l2;
         l2 = l2->next;
     }
     temp = temp->next;
 }
 if (NULL != l1)
 {
    temp->next = l1;
 }
 else
 {
     temp->next = l2;
 }
 ListNode *head = dummy->next;
 delete dummy;
 return head;
 
 }
};

///155.二叉树的最小深度
// 给定一个二叉树，找出其最小深度。

// 二叉树的最小深度为根节点到最近叶子节点的距离。
// 给出一棵如下的二叉树:

        // 1

     // /     \ 

   // 2       3

          // /    \

        // 4      5  

// 这个二叉树的最小深度为 2

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 * int val;
 * TreeNode *left, *right;
 * TreeNode(int val) {
 * this->val = val;
 * this->left = this->right = NULL;
 * }
 * }
 */
class Solution {
public:
 /**
 * @param root: The root of binary tree.
 * @return: An integer
 */
 int minDepth(TreeNode *root) {
 // write your code here
 if (NULL == root)
 {
     return 0;
 }
 else
 {
    return Depth(root);
 }
 }
 
 int Depth(TreeNode *root)
{
    if (NULL == root)
    {
        return INT_MAX;
    }
    if (NULL == root->left && NULL == root->right)
    {
        return 1;
    }
    return min(Depth(root->left), Depth(root->right)) + 1;
}

};


110 最小路径和  Minimum Path Sum   // 起点终点也算路径，也需要加进去
给定一个只含非负整数的m*n网格，找到一条从左上角到右下角的可以使数字和最小的路径。

 注意事项

你在同一时间只能向下或者向右移动一步

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
        vector<int> path_sum;
        int m = grid.size();
        int n = grid[0].size();
        if (0 == m || n == 0)
        {
            return 0;
        }
        int min_path[m][n];  // 从起点到某个点的最小路径和
        min_path[0][0] = grid[0][0];
        for (int i = 1; i < m; i++)
        {
            min_path[i][0] = min_path[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++)
        {
            min_path[0][j] = min_path[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                min_path[i][j] = min(min_path[i - 1][j], min_path[i][j - 1]) + grid[i][j];
            }
        }
        return min_path[m- 1][n - 1];
    }
};


44最小子数组
// 给定一个整数数组，找到一个具有最小和的子数组。返回其最小和。

 // 注意事项
// 子数组最少包含一个数字
// 样例
// 给出数组[1, -1, -2, 1]，返回 -3


class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int size = nums.size();
        int cur_min_sum = nums[0];
        int min_sum = nums[0];
        for (int i = 1; i < size; i++)
        {
            if (cur_min_sum > 0)
            {
                cur_min_sum = 0;
            }
            cur_min_sum += nums[i];
            if (cur_min_sum < min_sum)
            {
                min_sum = cur_min_sum;
            }
        }
        return min_sum;
    }
};


539. 移动零
给一个数组 nums 写一个函数将 0 移动到数组的最后面，非零元素保持原数组的顺序

 // 注意事项

// 1.必须在原数组上操作
// 2.最小化操作数
// 样例
// 给出 nums = [0, 1, 0, 3, 12], 调用函数之后, nums = [1, 3, 12, 0, 0].

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        // 方法1
        /*
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (0 == nums[i])
            {
                for (int j = i + 1; j < size; j++)
                {
                     nums[j - 1] = nums[j];
                }
                nums[size - 1] = 0;
                size--;
                i--;
            }
        }
        */
        
        // 方法2
        /*
        auto last = remove(nums.begin(), nums.end(), 0);
        for (auto &it = last; it != nums.end(); it++)
        {
            *it = 0;
        }
        */
        
        // 方法3
        /*
        int zero_nums = count(nums.begin(), nums.end(), 0);
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (0 == *it)
            {
                it = nums.erase(it) - 1;
            }
        }
        nums.insert(nums.end(), zero_nums, 0);
        */

	// 方法4  不理解
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            right++;
        }
    }
};



166.链表倒数第n个节点
// 找到单链表倒数第n个节点，保证链表中节点的最少数量为n。

// 样例
// 给出链表 3->2->1->5->null和n = 2，返回倒数第二个节点的值1.

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        // 方法1
        /*
        if (head == NULL)
        {
            return NULL;
        }
        int node_nums = 0;
        ListNode *first = head;
        while (first != NULL)
        {
            node_nums++;
            first = first->next;
        }
        int the_node_num = node_nums - n + 1;
        int i = 0;
        while (head != NULL)
        {
            i++;
            if (i == the_node_num)
            {
                return head;
            }
            head = head->next;
        }
        */
        
        // 方法2
        if (head == NULL || n < 1)
        {
            return NULL;
        }
        ListNode *p1 = head;
        ListNode *p2 = head;
        for (int i = 0; i < n - 1; i++)
        {
            if (p2->next == NULL)
            {
                return NULL;
            }
            p2 = p2->next;
        }
        while (p2->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

433.岛屿的个数
给一个01矩阵，求不同的岛屿的个数。

0代表海，1代表岛，如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。

在矩阵：

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]


class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int row = grid.size();
        int column = grid[0].size();
        int land_nums = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (grid[i][j])
                {
                    dfs(grid, i, j);
                    land_nums++;
                }
            }
        }
        return land_nums;
    }
    
    
    void dfs(vector<vector<bool>> &grid, int x, int y)
    {
        if (x < 0 || x >= grid.size())
        {
            return;
        }
        if (y < 0 || y >= grid[0].size())
        {
            return;
        }
        if (!grid[x][y])
        {
            return;
        }
        grid[x][y] = false;
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
};


142.O(1)时间检测2的幂次

用 O(1) 时间检测整数 n 是否是 2 的幂次。

 注意事项

O(1) 时间复杂度

n=4，返回 true;

n=5，返回 false.

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
       return n > 0 ? (n & (n - 1)) == 0 : 0;
    }
};


514.栅栏染色

我们有一个栅栏，它有n个柱子，现在要给柱子染色，有k种颜色可以染。
必须保证任意两个相邻的柱子颜色不同，求有多少种染色方案。

 注意事项

n和k都是非负整数

您在真实的面试中是否遇到过这个题？ Yes
样例
n = 3, k = 2, return 6

      post 1,   post 2, post 3
way1    0         0       1 
way2    0         1       0
way3    0         1       1
way4    1         0       0
way5    1         0       1
way6    1         1       0


问题分析

问题描述

lintcode表述有问题，原文是“必须保证任意两个相邻的柱子颜色不同，应该表述为 “不能有连续三个柱子颜色相同”。

参考

LintCode:栅栏染色 
参考里改掉的表述感觉也不对，还是应该说“不能有连续三个柱子颜色相同”。

笔记

在改掉问题表述的情况下： 
假设buff[i]为有i个柱子时的染色方案。可以分为两种情况： 
1. 最后两个柱子颜色相同。 
前i-2个柱子已经有buff[i-2]种方案了，第i-1个和第i个柱子取相同的颜色，但是要和i-2个柱子不同，有（k-1）种取法。 
2. 最后两个柱子颜色不同。 
前i-1个柱子符合要求，已经有buff[i-1]种方案了，第i个柱子的颜色要和第i-1个柱子颜色不同，还有（k-1）种方案。 
由此，状态转移方程为：

buff[i] = buff[i-1] * (k-1) + buff[i-2] * (k-1);

初始条件： 
buff[1] = k; buff[2] = k*k;

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        // Write your code here
        if (n == 0 || k == 0)
            return 0;
        if (n == 1)
            return k;
        if (n == 2)
            return k*k;
        int pre = k;
        int now = k*k;
        for (int i = 3; i <= n; i++)
        {
            int tmp = now;
            now = pre * (k-1) + now * (k - 1);
            pre = tmp;
        }
        return now;
    }
};


373.奇偶分割数组
分割一个整数数组，使得奇数在前偶数在后。

样例
给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]。

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        // 方法1
        /*
        vector<int> temp;
        for (auto &each : nums)
        {
            if ((each & 1) == 1)
            {
                temp.push_back(each);
            }
        }
        for (auto &each : nums)
        {
            if (!((each & 1) == 1))
            {
                temp.push_back(each);
            }
        }
        nums.assign(temp.begin(), temp.end());
        */
        
        // 方法2
        
        int nums_size = nums.size();
        int j;
        for (int i = 0; i < nums_size; i++)
        {
            if (!(nums[i] & 1))
            {
                for (j = i; j < nums_size; j++)
                {
                    if ((nums[j] & 1))
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
            if (j >= nums_size) // 减小复杂度
            {
                return;
            }
        }
        
        
        // 方法3
        //partition(nums.begin(), nums.end(), [](int &it) { return (it & 1);});
    }
};


96.链表划分
给定一个单链表和数值x，划分链表使得所有小于x的节点排在大于等于x的节点之前。

你应该保留两部分内链表节点原有的相对顺序。

样例
给定链表 1->4->3->2->5->2->null，并且 x=3

返回 1->2->2->4->3->5->null

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        
        ListNode dummy_smaller;
        ListNode dummy_larger;
        ListNode *tail_smaller = &dummy_smaller;
        ListNode *tail_larger = &dummy_larger;
        while(head != NULL)
        {
            if (head->val < x)
            {
                tail_smaller->next = head;
                tail_smaller = tail_smaller->next;
            }
            else
            {
                tail_larger->next = head;
                tail_larger = tail_larger->next;
            }
            head = head->next;
        }
        tail_larger->next = NULL;   // 最后一个大于x的数不是尾节点
        tail_smaller->next = (&dummy_larger)->next;
        head = (&dummy_smaller)->next;
        return head;
        
    }
};

197.排列序号 permutation-index

// 方法1  其中 折半插入排序（从后向前插入)不理解 
1.首先观察一个全排列， 例如：95412 = X

　　a.题目转换成按照字典序，这个全排列之前有多少个全排列。

　　b.X的前面的所有全排列中，对于位置1上可以是5, 4, 1, 2任意一个数，而且对应的全排列的基数都是4!个。

　　c.同理位置2, 3, 4, 5对应的基数分别是，3！，2！，1！，0！(0!==0)。

　　d.得到该位置对应的基数后，那么该位置对应多少个可变数字？9所在位置对应的可变数字的个数为4，分别是5,4,1,2；

　　　5所在位置对应的可变数字是4,1,2；4所在位置对应的可变数字是1,2,；1所在位置的对应的可变数字:无。2所在位置

　　   对应可变数也是无。

　　e.可以得到结论，X全排列某个位置上对应的可变数字的个数 == 这个数后面有多少个比它小的数的个数。

　　f.为了得到某个数后面有多少个比它小的数的个数，我们采用折半插入排序（从后向前插入）。


class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        
        vector<int> a;
        int len = A.size();
        int cnt[len];
        cnt[len-1] = 0;
        a.push_back(A[len-1]);
        for(int i=len-2; i>=0; --i){//统计每个数后面有多少个比它小的数的个数
            vector<int>::iterator it = lower_bound(a.begin(), a.end(), A[i]);
            cnt[i] = it-a.begin();
            a.insert(it, A[i]);
        }
        
        long long ans=1, fac=1, c=1;//基数fac从1开始
        for(int i=len-2; i>=0; --i)
            ans += (fac*=c++)*cnt[i];
        return ans;
    }
};

// 方法2  采用STL，超时
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
     
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        
        vector<int> permutation(A);
        sort(permutation.begin(), permutation.end());
        long long cnt = 0;
        do
        {
            cnt++;
            if(permutation == A)
            {
                break;
            }
        } while(next_permutation(permutation.begin(), permutation.end()));
        return cnt;
    }
};


方法3.
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
     class IsLessValue
     {
        private:
            int value_;
        public:
           IsLessValue(int value) : value_(value) {}
           bool operator()(int val) {return val < value_;}
     };
     
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        int len = A.size();
        int cnt[len];
        cnt[len - 1] = 0;
        int i = 0;
        for(auto start = A.begin(); start != A.end() - 1; start++)
        {
           //1. cnt[i++] = count_if(start + 1, A.end(), IsLessValue(*start));
           
           //2.
           cnt[i++] = count_if(start + 1, A.end(), [start](int ele) {return ele < *start;});
           
           //3.
           //auto val = *start;
           //cnt[i++] = count_if(start + 1, A.end(), [val](int ele) {return ele < val;});
        }
        long long ans=1, fac=1, c=1;//基数fac从1开始
        for(int i=len-2; i>=0; --i) // 从倒数第二个元素开始计算
        {
            fac = fac * c;
            ans += fac * cnt[i];
            c++;
        }
           
        return ans;
    }
};


407.加一
// 给定一个非负数，表示一个数字数组，在该数的基础上+1，返回一个新的数组。

该数字按照大小进行排列，最大的数在列表的最前面。

样例
给定 [1,2,3] 表示 123, 返回 [1,2,4].

给定 [9,9,9] 表示 999, 返回 [1,0,0,0].

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code here
        /*
        int vector_size = digits.size();
        int carry = 1;
        int head = 0;
        for (int i = vector_size - 1; i >= 0; i--)
        {
            if (digits[i] + carry > 9)
            {
                digits[i] = 0;
                carry = 1;
            }
            else
            {
                digits[i] = digits[i] + 1;
                carry = 0;
                break;
            }
            if (i == 0 && carry == 1)
            {
                head = 1;
            }
        }
        if (head == 1)
        {
            digits.insert(digits.begin(), head);
        }
        return digits;
        */
        
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
        {
            *it += carry;
            carry = *it / 10;
            *it = *it % 10;
        }
        if (carry > 0)
        {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};


50.数组剔除元素后的乘积  product of array exclude itself
给定一个整数数组A。

定义B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]， 计算B的时候请不要使用除法。

给出A=[1, 2, 3]，返回 B为[6, 3, 2]

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        // 方法1
        /*
        vector<long long> result;
        if (nums.empty())
        {
            return result;
        }
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++)
        {
            long long product = 1;
            for (int j = 0; j < nums_size; j++)
            {
                if (i != j)
                {
                    product *=nums[j];
                }
            }
            result.push_back(product);
        }
        return result;
        */
        
        // 方法2
        /*
        vector<long long> result;
        int nums_size = nums.size();
        long long right[nums_size + 1]; //i后及i的乘积
        right[nums_size] = 1;
        for (int i = nums_size - 1; i >= 0; i--)
        {
            right[i] = nums[i] * right[i + 1];
        }
        long long temp = 1;
        for(int i = 0; i < nums_size; i++)
        {
            result.push_back(temp * right[i + 1]);
            temp *= nums[i];
        }
        return result;
        */
        
        // 方法3
        vector<long long> result;
        int nums_size = nums.size();
        long long left[nums_size];  // i之前元素的积，不包括i
        long long right[nums_size]; // i之后元素的积，不包括i
        left[0] = 1;
        for (int i = 1; i < nums_size; i++)
        {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[nums_size - 1] = 1;
        for (int i = nums_size - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < nums_size; i++)
        {
            result.push_back(left[i] * right[i]);
        }
        return result;
    }
};


39. 恢复旋转排序数组 Recover Rotated Sorted Array
给定一个旋转排序数组，在原地恢复其排序。

什么是旋转数组？

比如，原始数组为[1,2,3,4], 则其旋转数组可以是[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
样例
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        // method 1
        /*
        int nums_size = nums.size();
        vector<int>::const_iterator min_value_iterator = min_element(nums.cbegin(), nums.cend());
        //auto min_value_iterator = min_element(nums.cbegin(), nums.cend());
        //vector<int>::iterator min_value_iterator = min_element(nums.begin(), nums.end());
        int nums_need_move = static_cast<int> (min_value_iterator - nums.begin());
        for (int i = nums_need_move; i > 0; i--)
        {
            for (int j = 0; j < nums_size - 1; j++)
            {
                swap(nums[j], nums[j + 1]);
            }
        }
        */
        
        // method 2
        sort(nums.begin(), nums.end());
    }
};

100 删除排序数组中的重复数字  Remove Duplicate Numbers in Array
给定一个排序数组，在原数组中删除重复出现的数字，使得每个元素只出现一次，并且返回新的数组的长度。
不要使用额外的数组空间，必须在原地没有额外空间的条件下完成。

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        
        //method 1
        //auto first_delete_iterator = unique(nums.begin(), nums.end());
        //nums.erase(first_delete_iterator, nums.end());
        //return nums.size();
        
        //method 2 超时
        /*
        if (nums.empty())
            return 0;
        for (auto beg = nums.begin(), end = nums.end(); beg + 1 != end; ++beg)
        {
            if (*beg == *(beg + 1))
            {
                nums.erase(beg + 1);
                beg = nums.begin();
                end = nums.end();
            }
        }
        return nums.size();
        */
        
        //method 3
        /*
        if (nums.empty())
            return 0;
        int len = 0;
        int i = 0;
        for (i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] != nums[i + 1])
                nums[len++] = nums[i];
        }
        nums[len++] = nums[i];
        return len;
        */
        
        // method 4
        if (nums.size() == 0) {
            return 0;
        }
        int len = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[len] != nums[i]) {
                nums[++len] = nums[i];
            }
        }
        return len + 1;
    }
};

101 删除排序数组中的重复数字 II  Remove Duplicates from Sorted Array II
class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if (nums.empty())
            return 0;
        int iCount = 1;
        int iLen = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[iLen] != nums[i])
            {
                nums[++iLen] = nums[i];
                iCount = 1;
            }
            else
            {
                ++iCount;
                if (iCount <= 2)
                {
                    nums[++iLen] = nums[i];
                }
            }
        }
        return iLen + 1;
    }
};

112 删除排序链表中的重复元素    Remove Duplicates from Sorted List
给定一个排序链表，删除所有重复的元素每个元素只留下一个。
样例
给出 1->1->2->null，返回 1->2->null
给出 1->1->2->3->3->null，返回 1->2->3->null

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        //1
        /*
        if (NULL == head)
            return head;
        auto first = head;
        auto next = first;
        while ((next = next->next) != NULL)
        {
            if (first->val == next->val)
            {
                auto temp = next;
                first->next = next->next;
                delete temp;
            }
            else
            {
                first = next;
            }
            next = first;
        }
        return head;
        */
        
        //2
        if (head == NULL) {
            return NULL;
        }

        ListNode *node = head;
        while (node->next != NULL)
        {
            if (node->val == node->next->val) 
            {
                node->next = node->next->next;
            } else
            {
                node = node->next;
            }
        }
        return head;
    }
};

172  删除元素     Remove Element
给定一个数组和一个值，在原地删除与值相同的数字，返回新数组的长度。
元素的顺序可以改变，并且对新的数组不会有影响。

给出一个数组 [0,4,4,0,0,2,4,4]，和值 4

返回 4 并且4个元素的新数组为[0,0,0,2]

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        //1
        /*
        auto first = remove(A.begin(), A.end(), elem);
        A.erase(first, A.end());
        return A.size();
        */
        
        //2
        int iLen = 0;
        int iSize = A.size();
        for (int i = 0; i < iSize; i++)
        {
            if (elem != A[i])
            {
                A[iLen++] = A[i];
            }
        }
        return iLen;
    }
};

174 删除链表中倒数第n个节点     Remove Nth Node From End of List
给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。
样例
给出链表1->2->3->4->5->null和 n = 2.
删除倒数第二个节点之后，这个链表将变成1->2->3->5->null.

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        //1
        /*
        auto node = head;
        int node_nums = 0;
        while (node != NULL)
        {
            node_nums++;
            node = node->next;
        }
        int the_node_num = node_nums - n + 1;
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        for (int i = 1; i < the_node_num; i++)  // 找到要删除节点的前一个节点
        {
            head = head->next;
        }
        auto temp = head->next;
        head->next = head->next->next;
        delete temp;
        return dummy.next;
        */
        
        //2
        if (NULL == head || n < 1)
            return NULL;
        auto p2 = head;
        for (int i = 0; i < n - 1; i++)  // p2指向正数第n个节点
        {
            p2 = p2->next;
        }
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        while (p2->next != NULL)  // 找到要删除节点的前一个节点
        {
            head = head->next;
            p2 = p2->next;
        }
        auto temp = head->next;
        head->next = head->next->next;
        delete temp;
        return dummy.next;
    }
};

413. 反转整数
将一个整数中的数字进行颠倒，当颠倒后的整数溢出时，返回 0 (标记为 32 位整数)。 reverse Integer

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
     int Reverse(int result, int n)
     {
         int temp = result;
         if (n != 0)
         {
             result = temp * 10 + n % 10;
             if (result / 10 != temp)
                return 0;
             return Reverse(result, n / 10);
         }
         else
            return result;
     }
    int reverseInteger(int n) {
        // Write your code here
        //1
        /*
        int k = 1;
        if (n < 0)
        {
             k = -1;
             n = -n;
        }
        
        long  result = 0;
        while (n > 0)
        {
            int remainder = n % 10;
            n = n /10;
            result = 10 * result + remainder;
            if (result > INT_MAX)
                return 0;
        }
        return (int)(k * result);
        */
        
        //2
        /*
        int result = 0;
        int temp = 0;
        while (n != 0)   // n != 0 不用判断正负
        {
            result = 10 * temp + n % 10;
            n = n / 10;
            if (result / 10 != temp)
                return 0;
            temp = result;
        }
        return result;
        */
        
        //3 递归版本
        return Reverse(0, n);
        
    }
};

//53 翻转字符串 Reverse Words in a String
给定一个字符串，逐个翻转字符串中的每个单词。

说明
单词的构成：无空格字母构成一个单词
输入字符串是否包括前导或者尾随空格？可以包括，但是反转后的字符不能包括
如何处理两个单词间的多个空格？在反转字符串中间空格减少到只含一个
样例


解法1：
这道题让我们翻转字符串中的单词，题目中给了我们写特别说明，如果单词之间遇到多个空格，只能返回一个，而且首尾不能有单词，并且对C语言程序员要求空间复杂度为O(1)，所以我们只能对原字符串s之间做修改，而不能声明新的字符串。那么我们如何翻转字符串中的单词呢，我们的做法是，先整个字符串整体翻转一次，然后再分别翻转每一个单词（或者先分别翻转每一个单词，然后再整个字符串整体翻转一次），此时就能得到我们需要的结果了。那么这里我们需要定义一些变量来辅助我们解题，storeIndex表示当前存储到的位置，n为字符串的长度。我们先给整个字符串反转一下，然后我们开始循环，遇到空格直接跳过，如果是非空格字符，我们此时看storeIndex是否为0，为0的话表示第一个单词，不用增加空格；如果不为0，说明不是第一个单词，需要在单词中间加一个空格，然后我们要找到下一个单词的结束位置我们用一个while循环来找下一个为空格的位置，在此过程中继续覆盖原字符串，找到结束位置了，下面就来翻转这个单词，然后更新i为结尾位置，最后遍历结束，我们剪裁原字符串到storeIndex位置，就可以得到我们需要的结果，代码如下：

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        
        // 1.原址翻转
        
        int storeIndex = 0;
        int n = s.size();
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                if (storeIndex != 0)
                {
                    s[storeIndex++] = ' ';
                }
                int j = i;
                while (j < n && s[j] != ' ')
                {
                    s[storeIndex++] = s[j++];
                }
                // 很重要， 容易出错， j - i表示单词长度
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
       
    }
};

// 解法2 使用istringstream
class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        // 使用istringstream
        istringstream istr(s);
        string strTemp;
        istr >> s;   //s被重新赋值，为第一个字符串 istr忽略开头空格，字符串以空格分割， 
        while (istr >> strTemp)
        {
            s = strTemp + " " + s;
        }
        return s;   
    }
};


53 旋转字符串 rotate String
给定一个字符串和一个偏移量，根据偏移量旋转字符串(从左向右旋转)

样例
对于字符串 "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        //1
        /*
        int iStrLength = str.size();
        if (iStrLength == 0)
            return;
        if (offset > iStrLength - 1)
            offset = offset % iStrLength;
        int i = iStrLength - offset;  // 开始交换的下标
        int m = 0; 
        while (i < iStrLength)
        {
            for (int j = i - 1; j >= m; j--)
            {
                swap(str[j], str[j + 1]);
            }
            i++;
            m++;
        }
        */
        
        //2
        /*
        int iStrLength = str.size();
        if (iStrLength == 0)
            return;
        if (offset > iStrLength - 1)
            offset = offset % iStrLength;
        int i = iStrLength - offset;  // 开始交换的下标
        rotate(str.begin(), string::iterator(&str[i]), str.end());
        */

		//3
        if (str.empty())
            return;
        int iStrLength = str.size();
        offset = offset % iStrLength;
        str = str.substr(iStrLength - offset, offset) + 
                str.substr(0, iStrLength - offset);
    }
};

60 搜索插入位置    Search Insert Position

给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。

你可以假设在数组中无重复元素。
样例
[1,3,5,6]，5 → 2

[1,3,5,6]，2 → 1

[1,3,5,6]， 7 → 4

[1,3,5,6]，0 → 0


class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        //1
        auto it = lower_bound(A.begin(), A.end(), target);
        return it - A.begin();
        
        //2
        int start = 0;
        int end = A.size() - 1;
        while (start != end)
        {
            int mid = (start + end) / 2;
            if (target == A[mid])
                return mid;
            if (target < A[mid])
            {
                end = mid - 1;
            }
            if (target > A[mid])
            {
                start = mid + 1;
            }
        }
        if (target == A[start])
        {
            return start;
        }
        else if (target < A[start])
        {
            return start - 1;
        }
        else
        {
            return start + 1;
        }
    }
};

28 搜索二维矩阵  Search a 2D Matrix
写出一个高效的算法来搜索 m × n矩阵中的值。

这个矩阵具有以下特性：

每行中的整数从左到右是排序的。
每行的第一个数大于上一行的最后一个整数。

样例
考虑下列矩阵：

[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
给出 target = 3，返回 true


class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        //1
        /*
        if (matrix.empty() || matrix[0].empty())
            return false;
        int iRow = matrix.size();
        int iColumn = matrix[0].size();
        if (target < matrix[0][0] || target > matrix[iRow - 1][iColumn - 1])
            return false;
        int i = 0;
        for (i = 0; i + 1 < iRow; i++)
        {
            if (target >= matrix[i][0] && target < matrix[i + 1][0])
                break;
        }
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
        */
        
        //2 二维数组看为一维数组进行二分查找
        
        if (matrix.empty() || matrix[0].empty())
            return false;
        int iRow_size = matrix.size();
        int iColumn_size = matrix[0].size();
        int start = 0;
        int end = iRow_size * iColumn_size - 1;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            int iRow = mid / iColumn_size;
            int iColumn = mid % iColumn_size;
            if (target == matrix[iRow][iColumn])
                return true;
            if (target < matrix[iRow][iColumn])
            {
                end = mid - 1;
            }
            if (target > matrix[iRow][iColumn])
            {
                start = mid + 1;
            }
        }
        return false;
        
        
    }
};


82  落单的数  Single Number
给出2*n + 1 个的数字，除其中一个数字之外其他每个数字均出现两次，找到这个数字。

样例
给出 [1,2,2,1,3,4,3]，返回 4
挑战 
一次遍历，常数级的额外空间复杂度


class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        //1
        /*
        if (A.empty())
            return 0;
        sort(A.begin(), A.end());
        int iVectorSize = A.size();
        int i = 0;
        for (i = 0; i + 1 < iVectorSize; i = i + 2)
        {
            if (A[i] != A[i + 1])
                break;
        }
        return A[i];
        */
        
        
        //2
        /*
        if (A.empty())
            return 0;
        int iVectorSize = A.size();
        map<int, int> mmap;
        for (int i = 0; i < iVectorSize; i++)
           ++mmap[A[i]];
        for (const auto &it : mmap)
        {
            if (it.second != 2)
                return it.first;
        }
        */
        
        //3 把数组中所有的数字做异或，因为相同的两个数组异或结果为0，所以最后得到的数字就是结果。异或满足交换律
        int ans = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            ans ^= A[i];
        }
        return ans;
    }
};


212  空格替换    space replacement
class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        if (length == 0)
            return 0;
        int iSpaceNums = 0;
        for (int i = 0; i < length; i++)
        {
            if (string[i] == ' ')
                iSpaceNums++;
        }
        int j = length + 2 * iSpaceNums;
        
        for (int i = length; i >=0; i--)
        {
            if (string[i] != ' ')
            {
                string[j--] = string[i];
            }
            else
            {
                string[j--] = '0';
                string[j--] = '2';
                string[j--] = '%';
            }
        }
        return strlen(string);
    }
};  


141  x的平方根  Sqrt(x)

实现 int sqrt(int x) 函数，计算并返回 x 的平方根。

您在真实的面试中是否遇到过这个题？ Yes
样例
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3


class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        // 二分法
        long long iLeft = 0;
        long long iRight = x / 2 + 1;
        long long llSquare = 0;
        while (iLeft <= iRight)
        {
            long long iMid = (iLeft + iRight) / 2;
            llSquare = iMid * iMid;
            if (llSquare == x)
                return iMid;
            else if (llSquare < x)
                iLeft = iMid + 1;
            else
                iRight = iMid - 1;
        }
       // return iRight;  //返回iLeft出错，为什么一定要返回iRight
       return iLeft * iLeft - x < iRight * iRight - x ? iLeft : iRight;
    }
};


211 字符串置换  string Permutation


给定两个字符串，请设计一个方法来判定其中一个字符串是否为另一个字符串的置换。

置换的意思是，通过改变顺序可以使得两个字符串相等。

样例
"abc" 为 "cba" 的置换。

"aabc" 不是 "abcc" 的置换。


class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        // Write your code here
        //1
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return A == B ? true : false;
        
        
        //2
        /*
        map<char, int> map_A;
        map<char, int> map_B;
        for (int i = 0; i < A.size(); i++)
        {
            ++map_A[A[i]];
        }
        for (int i = 0; i < B.size(); i++)
        {
            ++map_B[B[i]];
        }
        if (map_A.size() != map_B.size())
        {
            return false;
        }
        for (auto it_A = map_A.begin(), it_B = map_B.begin();
            it_A != map_A.end(); ++it_A, ++it_B)
        {
            if (it_A->first != it_B->first || it_A->second != it_B->second)
            {
                return false;
            }
        }
        return true;
        */
    }
};


138. 子数组之和 subarraySum


给定一个整数数组，找到和为零的子数组。你的代码应该返回满足要求的子数组的起始位置和结束位置
注意事项

There is at least one subarray that it's sum equals to zero.

样例

给出 [-3, 1, 2, -3, 4]，返回[0, 2] 或者 [1, 3].

方法2解题思路：

依次求数组的前缀和，同时执行如下操作：

假定当前位置是i，查找i之前位置的前缀和，是否存在j位置，使得，j位置的前缀和 等于 i位置的前缀和。

若有，则j 到 i 之间的区间数的和为0,(i, j],左开右闭

直到遍历完整个数组。

时间复杂度O(n)，空间复杂度O(n).


class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        //1
        /*
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++)
        {
            int sum = 0;
            for (int j = i; j < numsSize; j++)
            {
                sum += nums[j];
                if (0 == sum)
                {
                    return vector<int>{i, j};
                }
            }
        }
        */
        
        //2

        vector<int> result;
        unordered_map<int, int> sum_index_mapping;  // <sum, n>前n个元素的和
        sum_index_mapping[0] = -1;  //下标为-1的元素的和为0
                                    // 防止和为零的序列正好从第一个元素开始
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum_index_mapping.count(sum))
            {
                result.push_back(sum_index_mapping[sum] + 1);
                result.push_back(i);
                return result;
            }
            sum_index_mapping[sum] = i;
        }
        return result;
    }
};


245. 子树
有两个不同大小的二进制树： T1 有上百万的节点； T2 有好几百的节点。请设计一种算法，判定 T2 是否为 T1的子树。

 注意事项

若 T1 中存在从节点 n 开始的子树与 T2 相同，我们称 T2 是 T1 的子树。也就是说，如果在 T1 节点 n 处将树砍断，砍断的部分将与 T2 完全相同。

样例
下面的例子中 T2 是 T1 的子树：

       1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4
下面的例子中 T2 不是 T1 的子树：

       1               3
      / \               \
T1 = 2   3       T2 =    4
        /
       4


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        //1 层次遍历
        /*
        if (NULL == T2 && NULL == T1)
            return true;
        if (NULL== T2)
            return true;
        if (NULL == T1)
            return false;
        bool flag = false;
        LevelOrderTraversal(T1, T2, flag);
        return flag;
        */
        
        //2 递归
        if (NULL == T2 && NULL == T1)
            return true;
        if (NULL== T2)
            return true;
        if (NULL == T1)
            return false;
        if (IsIdentical(T1, T2))
            return true;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }
    
    bool IsIdentical(TreeNode* a, TreeNode* b)
    {
        if ((nullptr == a && nullptr != b) || (nullptr != a && nullptr == b))
            return false;
        else if (nullptr == a && nullptr == b)
            return true;
        else
        {
            if (a->val != b->val)
                return false;
            else return (IsIdentical(a->left, b->left) && IsIdentical(a->right, b->right));
        }
    }
        
    void LevelOrderTraversal(TreeNode *root, TreeNode *T2, bool &flag)
    {
        if(NULL == root)
        {
            return;
        }
        queue<TreeNode *> tree_node_queue;
        tree_node_queue.push(root);
        while (!tree_node_queue.empty())
        {
            TreeNode *head = tree_node_queue.front();
             tree_node_queue.pop();
            if (IsIdentical(head, T2))
            {
                flag = true;
                return;
            }
            if (NULL != head->left)
            {
                tree_node_queue.push(head->left);
            }
            if (NULL != head->right)
            {
                tree_node_queue.push(head->right);
            }
        }
    }
};


451 两两交换链表中的节点    Swap Nodes in Pairs

给一个链表，两两交换其中的节点，然后返回交换后的链表。

样例
给出 1->2->3->4, 你应该返回的链表是 2->1->4->3。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        // Write your code here
        if (NULL == head || NULL == head->next)
        {
            return head;
        }
        ListNode *dummy = new ListNode;
        ListNode *remaining_list_head = head;
        ListNode *current = dummy;
        ListNode *temp;
        while (NULL != remaining_list_head &&
            NULL != remaining_list_head->next)
        {
            temp = remaining_list_head->next->next;
            current->next = remaining_list_head->next;
            current = current->next;
            current->next = remaining_list_head;
            current = current->next;
            current->next = NULL;      // 原链表截为两个链表,一个已交换好，一个未交换
            remaining_list_head = temp;
        }
        if (NULL != remaining_list_head) // 剩余链表只有一个节点
        {
            current->next = remaining_list_head;
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

2. 尾部的零    Trailing Zeros
设计一个算法，计算出n阶乘中尾部零的个数

样例
11! = 39916800，因此应该返回 2

// 解题思路
求末尾0的个数： 
至于一个数阶乘的末尾有多少个0，0的个数为（其中的“/”是取整除法）： 
例子：1000的阶乘末尾0的个数 
1000/5 + 1000/25 + 1000/125 + 1000/625 
= 200 + 40 + 8 + 1 
= 249(个)

原理是： 
假如你把1 × 2 ×３× 4 ×……×N中每一个因数分解质因数，结果就像： 
1 × 2 × 3 × (2 × 2) × 5 × (2 × 3) × 7 × (2 × 2 ×2) ×…… 
10进制数结尾的每一个0都表示有一个因数10存在——任何进制都一样，对于一个M进制的数，让结尾多一个0就等价于乘以M。 
10可以分解为2 × 5——因此只有质数2和5相乘能产生0，别的任何两个质数相乘都不能产生0，而且2，5相乘只产生一个0。 
所以，分解后的整个因数式中有多少对(2, 5)，结果中就有多少个0，而分解的结果中，2的个数显然是多于5的，因此，有多少个5，就有多少个(2, 5)对。 
所以，讨论1000的阶乘结尾有几个0的问题，就被转换成了1到1000所有这些数的质因数分解式有多少个5的问题。 
5的个数可以用上面那个式子算出，所以1000的阶乘结尾有249个0。

至于为什么用这个式子，可以见下例： 
求26的阶乘的尾部有多少个0. 
26！ = 1 × 2 ×３× 4 × 5 × 6 × 7 × 8 × 9 × 10 × 11 × 12 × 13× 14 × 15 × 16 × 17 × 18 × 19 × 20 × 21 × 22 ×2３× 24 × 25 × 26 
内有 26/5 + 26/25 = 6（个）5相乘 
因为25其实可以分解成2个5相乘，而26/5只计算了一个5，因此还要再加26/25.

像5,10,15,20等数只有一个5的因子，因此count5++就可以了，但碰到25,50,75等数，包含了2个5的因子，因此count5应该加2，碰到125等含3个5的因子，count5应该加3。因此，可以采用下面的算法。例如105的阶乘，1~105有21个能被5整除的数，105/5=21，1~21中有4个能被5整除的数，21/5=4，1~4中没有，count5=21+4+0=25.即从1~105中挑出5=5*1,10=5*2，15=5*3,20=5*4,25=5*5,30=5*6...100=5*20,105=5*21这21个数，在从这21个数中挑出能继续被5整除的25,50,75,100这四个数

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        // 1 超时
        /*
        long long factory = Factory(n);
        int count = 0;
        while (factory % 10 == 0)
        {
            count++; 
            factory = factory / 10;
        }
        return count;
        */

        // 2
        long long count = 0;
        while (n != 0)
        {
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
    
    long long Factory(long long n)
    {
        if (0 >= n)
        {
            return 1;
        }
        return n * Factory(n - 1);
    }
};


415 有效回文串  Valid Palindrome

给定一个字符串，判断其是否为一个回文串。只包含字母和数字，忽略大小写。

 注意事项

你是否考虑过，字符串有可能是空字符串？这是面试过程中，面试官常常会问的问题。

在这个题目中，我们将空字符串判定为有效回文。

"A man, a plan, a canal: Panama" 是一个回文。

"race a car" 不是一个回文。


class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        
        //1
        /*
        int length = s.size();
        if (0 == length)
        {
            return true;
        }
        int up = 0;
        int down = length - 1;
        while (up < down)
        {
            while (!isalnum(s[up]) && up < down)
            {
                up++;
            }
            while (!isalnum(s[down]) && up < down)
            {
                down--;
            }
            if ((isalpha(s[up]) && isdigit(s[down])) ||
                (isalpha(s[down]) && isdigit(s[up])))
            {
                return false;
            }
            if (isdigit(s[up]) && isdigit(s[down]))
            {
                if (s[up] != s[down])
                {
                    return false;
                }
                up++;
                down--;
            }
            if (isalpha(s[up]) && isalpha(s[down]))
            {
                if (s[up] == s[down] || s[up] == s[down] + 32
                    || s[up] == s[down] - 32)
                {
                    up++;
                    down--;
                }
                else
                {
                    return false;
                }
                
            }
        }
        return true;
        */
        
        //2
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto left = s.begin();
        auto right = prev(s.end());
        while (left < right)
        {
            if (!isalnum(*left))
            {
                left++;
            }
            else if (!isalnum(*right))
            {
                right--;
            }
            else if (*left != *right)
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }
};

406 和大于S的最小子数组   Minimum Size Subarray Sum

给定一个由 n 个整数组成的数组和一个正整数 s ，请找出该数组中满足其和 ≥ s 的最小长度子数组。如果无解，则返回 -1。
样例
给定数组 [2,3,1,2,4,3] 和 s = 7, 子数组 [4,3] 是该条件下的最小长度子数组。

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
        //1
        
        if (accumulate(nums.begin(), nums.end(), 0) < s)
        {
            return -1;
        }
        int nums_size = nums.size();
        int min = nums_size;
        for (int i = 0; i < nums_size; i++)
        {
            int sum = 0;
            for (int j = i; j < nums_size; j++)
            {
                sum += nums[j];
                if (sum >= s)
                {
                    if (j - i + 1 < min)
                    {
                        min = j -i + 1;
                    }
                    break;
                }
            }
        }
        return min;
        
        
        //2
        /*
        int min_length = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;
        int nums_size = nums.size();
        while (right < nums_size)
        {
            sum += nums[right];
            if (sum >= s)
            {
                min_length = min(min_length, right - left + 1);
                while (sum >= s && left <= right)
                {
                    sum -= nums[left];
                    min_length = min(min_length, right - left + 1);
                    left++;
                    
                }
            }
            right++;
        }
        return min_length == INT_MAX ? -1 : min_length;
        */
    }
};


200. 最长回文子串   longestPalindrome
给出一个字符串（假设长度最长为1000），求出它的最长回文子串，你可以假定只有一个满足条件的最长回文串。
挑战 
O(n2) 时间复杂度的算法是可以接受的，如果你能用 O(n) 的算法那自然更好。

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        // 1  O(n^3)
        /*
        int length = s.size();
        string longest_palindrome;
        int longest_palindrome_length = 0;
        if (0 == length || 1 == length)
        {
            return s;
        }
        int end = length;
        for (int i = 0; i < end; i++)
        {
            for (int j = i; j < end; j++)
            {
                string substring = s.substr(i, j - i + 1);
                if (IsPalindrome(substring))
                {
                    if (substring.size() > longest_palindrome_length)
                    {
                        longest_palindrome_length = substring.size();
                        longest_palindrome = substring;
                    }
                }
            }
        }
        return longest_palindrome;
        */
        
        
        // 2 O(n^2)
        int string_length = s.size();
        if (string_length <= 1)
        {
            return s;
        }
        int start = 0;
        int longest_palindrome_length = 0;
        for (int i = 1; i < string_length; i++)
        {
            int low;
            int high;
            // 以i - 1, i为中点的偶数长度的回文
            low = i - 1;
            high = i;
            while (low >= 0 && high < string_length && s[low] == s[high])
            {
                low--;
                high++;
            }
            if (high - low - 1 > longest_palindrome_length)
            {
                longest_palindrome_length = high - low - 1;
                start = low + 1;
            }
            // 以i为中心的奇数长度的回文
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < string_length && s[low] == s[high])
            {
                low--;
                high++;
            }
            if (high - low - 1 > longest_palindrome_length)
            {
                longest_palindrome_length = high - low - 1;
                start = low + 1;
            }
        }
        return s.substr(start, longest_palindrome_length);
    }
    
    bool IsPalindrome(const string& s)
    {
        int length = s.size();
        if (0 == length)
        {
            return true;
        }
        int up = 0;
        int down = length - 1;
        while (up < down)
        {
            if (s[up] != s[down])
            {
                return false;
            }
            up++;
            down--;
        }
        return true;
    }
};



190 下一个排列   next Permutation

给定一个若干整数的排列，给出按正数大小进行字典序从小到大排序后的下一个排列。

如果没有下一个排列，则输出字典序最小的序列。

您在真实的面试中是否遇到过这个题？ Yes
样例
左边是原始排列，右边是对应的下一个排列。

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

挑战 
不允许使用额外的空间。


class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: return nothing (void), do not return anything, modify nums in-place instead
     */
    void nextPermutation(vector<int> &nums) {
        // write your code here
        // 1
        /*
        next_permutation(nums.begin(), nums.end());
        */
        
        //2 分析：从后往前找，找到第一对(i,j)，使得nums[i]<num[j],然后将两者兑换后，后面部分排序即可。
        int nums_size = nums.size();
        for (int i = nums_size - 1; i >= 0; i--)
        {
            for (int j = nums_size - 1; j > i; j--)
            {
                if (nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        sort(nums.begin(), nums.end());
    }
};


109 数字三角形
给定一个数字三角形，找到从顶部到底部的最小路径和。每一步可以移动到下面一行的相邻数字上。

 注意事项

如果你只用额外空间复杂度O(n)的条件下完成可以获得加分，其中n是数字三角形的总行数。

您在真实的面试中是否遇到过这个题？ Yes
样例
比如，给出下列数字三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
从顶到底部的最小路径和为11 ( 2 + 3 + 5 + 1 = 11)。


解题思路：
笔记

代码1

设置buff[i][j]为：以元素(i,j)结尾的最小路径和。 
buff[i][j]应该是buff[i-1][j-1]和buff[i-1][j]中的较小值再加上当前的triangle[i][j]。 
则状态转移方程为： 
buff[i][j] = min(buff[i-1][j-1], buff[i-1][j]) + triangle[i][j] 
初始条件为： 
buff[0][0] = triangle[0][0]

注意

判断越界问题也用到了一个小技巧，忘了从哪学来的了。

//要取buff[i-1][j-1]，和buff[i-1][j]，但是要保证不越界。
//第i-1行的j的取值范围为[0, i-1]
int lo = max(0, j-1);//当j-1小于0的时候只取0，大于等于0的时候取自身。
int hi = min(j, i-1);//当j大于i-1的时候只取i-1，小于等于i-1的时候取自身。
1
2
3
4
代码2

题目要求优化空间复杂度。其实不需要用二维数组，因为每一行的值只与上一行的值相关，因此可以只用一行做缓存即可。（代码2） 
在这里用到了背包问题中的小技巧，每一行从后往前更新，以防覆盖前面要使用的值。

注意

看来，要将二维空间节省成一维空间的时候，都要考虑一下从后往前向前更新这一小技巧。


class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        int total = 0;
        const int triangle_size = triangle.size();
        vector<int> min_path_sum(triangle_size);
        min_path_sum[0] = triangle[0][0];
        for (int i = 1; i < triangle_size; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                int low = max(0, j - 1);
                int high = min(j, i - 1);
                min_path_sum[j] = min(min_path_sum[low], min_path_sum[high]) + triangle[i][j];
            }
        }
        if (!min_path_sum.empty())
        {
            return *min_element(min_path_sum.begin(), min_path_sum.end());
        }
        
    }
};



158 两个字符串是变位词  anagram

出一个函数 anagram(s, t) 判断两个字符串是否可以通过改变字母的顺序变成一样的字符串。

您在真实的面试中是否遇到过这个题？ Yes
说明
What is Anagram?
- Two strings are anagram if they can be the same after change the order of characters.

样例
给出 s = "abcd"，t="dcab"，返回 true.
给出 s = "ab", t = "ab", 返回 true.
给出 s = "ab", t = "ac", 返回 false.

挑战 
O(n) time, O(1) extra space


class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        // 1
        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
        {
            return true;
        }
        else
        {
            return false;
        }
        */
        
        // 2
        /*
        if (s.length() != t.length())
        {
            return false;
        }
        char character_array[256];
        memset(character_array, 0, sizeof(character_array));
        for (int i = 0; i < s.length(); i++)
        {
            character_array[s[i]]++;
            character_array[t[i]]--;
        }
        for (int i = 0; i < sizeof(character_array); i++)
        {
            if (character_array[i] != 0)
            {
                return false;
            }
        }
        return true;
        */
        
        // 3
        if (s.length() != t.length())
        {
            return false;
        }
        map<char, int> char_num_map;
        for (int i = 0; i < s.length(); i++)
        {
            char_num_map[s[i]]++;
            char_num_map[t[i]]--;
        }
        for (auto it = char_num_map.begin(); it != char_num_map.end(); it++)
        {
            if (it->second != 0)
            {
                return false;
            }
        }
        return true;
        
    }
};

56 两数之和  two Sum


给一个整数数组，找到两个数使得他们的和等于一个给定的数 target。

你需要实现的函数twoSum需要返回这两个数的下标, 并且第一个下标小于第二个下标。注意这里下标的范围是 1 到 n，不是以 0 开头。

 注意事项

你可以假设只有一组答案。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 numbers = [2, 7, 11, 15], target = 9, 返回 [1, 2].

挑战 
Either of the following solutions are acceptable:

O(n) Space, O(nlogn) Time
O(n) Space, O(n) Time


class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        // 1
        /*
        for (int i = 0; i != nums.size(); i++)
        {
            for (int j = i + 1; j != nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return vector<int>({i + 1, j + 1});
                }
            }
        }
        */
        
        // 2
        /*
        unordered_map<int, int> value_index_map;
        for (int i = 0; i < nums.size(); i++)
        {
            value_index_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            if (value_index_map.find(temp) != value_index_map.end())
            {
                return vector<int>{i + 1, value_index_map[temp] + 1};
            }
        }
        */
        
        // 3
        unordered_map<int, int> value_index_map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (value_index_map.count(target - nums[i]))
            {
                return vector<int>{value_index_map[target - nums[i]] + 1, i + 1};
            }
            value_index_map[nums[i]] = i;
        }    
    }       
}; 



517 丑数

写一个程序来检测一个整数是不是丑数。

丑数的定义是，只包含质因子 2, 3, 5 的正整数。比如 6, 8 就是丑数，但是 14 不是丑数以为他包含了质因子 7。
自己理解：一个数分解后，只能是2，3,5之中的数

 注意事项

可以认为 1 是一个特殊的丑数。

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 num = 8，返回 true。
给出 num = 14，返回 false。


class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        // 1
        /*
        if (1 == num || 2 == num || 3 == num || 5 == num)
        {
            return true;
        }
        if (4 == num || num <= 0)
        {
            return false;
        }
        for (int i = 6; i <= num; i++)
        {
            if (0 == num % i && IsPrime(i))
            {
                return false;
            }
        }
        return true;
        */
        
        // 2
        if (num <= 0) return false;  
        if (num == 1) return true;  
          
        while (num >= 2 && num % 2 == 0) num /= 2;  
        while (num >= 3 && num % 3 == 0) num /= 3;  
        while (num >= 5 && num % 5 == 0) num /= 5;  
          
        return num == 1;  
    }



    bool IsPrime(int n)
    {
        int k = sqrt(n);
        for (int i = 2; i <= k; i++)
        {
            if (0 == n % i)
            {
                return false;
            }
        }
        return true;
    }
};




157 判断字符串是否没有重复字符   unique characters

实现一个算法确定字符串中的字符是否均唯一出现

您在真实的面试中是否遇到过这个题？ Yes
样例
给出"abc"，返回 true

给出"aab"，返回 false

挑战 
如果不使用额外的存储空间，你的算法该如何改变？


class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        
        // 1
        /*
        set<char> char_set(str.begin(), str.end());
        if (char_set.size() == str.size())
        {
            return true;
        }
        else
        {
            return false;
        }
        */
        
        // 2  思想重要
        /*
        char ch[128] = {0};
        for (int i = 0; i < str.length(); i++)
        {
            if (ch[str[i]] != 0)
            {
                return false;
            }
            else
            {
                ch[str[i]] = 1;
            }
        }
        return true;
        */
        
        
        // 3
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = i + 1; j < str.length(); j++)
            {
                if (str[i] == str[j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};


114 不同的路径  uniquePaths
有一个机器人的位于一个 m × n 个网格左上角。

机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角。

问有多少条不同的路径？

 注意事项

n和m均不超过100

您在真实的面试中是否遇到过这个题？ Yes
样例
给出 m = 3 和 n = 3, 返回 6.
给出 m = 4 和 n = 5, 返回 35.

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        int path_nums_array[m][n];
        for (int i = 0; i < m; i++)
        {
            path_nums_array[i][0] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            path_nums_array[0][i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                path_nums_array[i][j] = path_nums_array[i][j - 1] +
                    path_nums_array[i - 1][j];
            }
        }
        return path_nums_array[m - 1][n - 1];
    }
};


115 不同的路径 II   uniquePathsWithObstacles
"不同的路径" 的跟进问题：

现在考虑网格中有障碍物，那样将会有多少条不同的路径？

网格中的障碍和空位置分别用 1 和 0 来表示。

 注意事项

m 和 n 均不超过100

您在真实的面试中是否遇到过这个题？ Yes
样例
如下所示在3x3的网格中有一个障碍物：

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
一共有2条不同的路径从左上角到右下角。

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int path_nums_array[m][n];
        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] != 1)
            {
                path_nums_array[i][0] = 1;
            }
            else
            {
                for (; i < m; i++)
                {
                    path_nums_array[i][0] = 0;
                }
                break;
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] != 1)
            {
                path_nums_array[0][i] = 1;
            }
            else
            {
                for (; i < n; i++)
                {
                    path_nums_array[0][i] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    path_nums_array[i][j] = 0;
                }
                else
                {
                    path_nums_array[i][j] = path_nums_array[i][j - 1] +
                        path_nums_array[i - 1][j];
                }
            }
        }
        return path_nums_array[m - 1][n - 1];
    }
};


423. 有效的括号序列
给定一个字符串所表示的括号序列，包含以下字符： '(', ')', '{', '}', '[' and ']'， 判定是否是有效的括号序列。

您在真实的面试中是否遇到过这个题？ Yes
样例
括号必须依照 "()" 顺序表示， "()[]{}" 是有效的括号，但 "([)]"则是无效的括号。

解题思路就是借用栈这个数据结构来解此题。
1. 遇到左括号，全部压入栈中；
2. 遇到右括号，判断栈顶的元素是否是相对应的左括号，若是则弹出栈顶元素，若不是则返回false，若栈为空，也返回false；


class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> char_stack;
        int string_length = s.size();
        for (int i = 0; i < string_length; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                char_stack.push(s[i]);
            }
            else
            {
                if (char_stack.empty())
                {
                    return false;
                }
                else
                {
                    if (s[i] == ')')
                    {
                        if (char_stack.top() != '(')
                        {
                            return false;
                        }
                        else
                        {
                            char_stack.pop();
                        }
                    }
                    if (s[i] == '}')
                    {
                        if (char_stack.top() != '{')
                        {
                            return false;
                        }
                        else
                        {
                            char_stack.pop();
                        }
                    }
                    if (s[i] == ']')
                    {
                        if (char_stack.top() != '[')
                        {
                            return false;
                        }
                        else
                        {
                            char_stack.pop();
                        }
                    }
                }
            }
        }
        if (char_stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


389. 判断数独是否合法  Valid Sudoku

请判定一个数独是否有效。

该数独可能只填充了部分数字，其中缺少的数字用 . 表示。

 注意事项

一个合法的数独（仅部分填充）并不一定是可解的。我们仅需使填充的空格有效即可。

您在真实的面试中是否遇到过这个题？ Yes
说明
什么是 数独？

http://sudoku.com.au/TheRules.aspx
http://baike.baidu.com/subview/961/10842669.htm

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool used[9];  // 数组下标对应1-9,9个数字，数组中的值表明下标数字是否存在
        for (int i = 0; i < 9; i++)
        {
            // 检查行
            fill(begin(used), end(used), false);
            for (int j = 0; j < 9; j++)
            {
                if (!check(board[i][j], used))
                {
                    return false;
                }
            }
            // 检查列
            fill(begin(used), end(used), false);
            for (int j = 0; j < 9; j++)
            {
                if (!check(board[j][i], used))
                {
                    return false;
                }
            }
        }
        for (int i = 0; i <= 6; i = i + 3)
        {
            for (int j = 0; j <= 6; j = j + 3)
            {
                fill(begin(used), end(used), false);
                for (int row = i; row < i + 3; row++)
                {
                    for (int column = j; column < j + 3; column++)
                    {
                        if (!check(board[row][column], used))
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
        
    }
    
    bool check(char ch, bool used[9])
    {
        if (ch == '.')
        {
            return true;
        }
        if (used[ch - '1'] == true)
        {
            return false;
        }
        else
        {
            used[ch - '1'] = true;
            return true;
        }
    }
    
};


13 字符串查找 strstr

对于一个给定的 source 字符串和一个 target 字符串，你应该在 source 字符串中找出 target 字符串出现的第一个位置(从0开始)。如果不存在，则返回 -1。

您在真实的面试中是否遇到过这个题？ Yes
说明
在面试中我是否需要实现KMP算法？

不需要，当这种问题出现在面试中时，面试官很可能只是想要测试一下你的基础应用能力。当然你需要先跟面试官确认清楚要怎么实现这个题。
样例
如果 source = "source" 和 target = "target"，返回 -1。

如果 source = "abcdabcdefg" 和 target = "bcd"，返回 1。

挑战 
O(n2)的算法是可以接受的。如果你能用O(n)的算法做出来那更加好。（提示：KMP）

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        // 1 
        /*
        if (NULL == source || NULL == target)
        {
            return -1;
        }
        string first(source);
        string second(target);
        if (first.empty() && second.empty())
        {
            return 0;
        }
        auto tail = search(first.begin(), first.end(), second.begin(), second.end());
        if (tail != first.end())
        {
            return tail - first.begin();
        }
        else
        {
            return -1;
        }
        */
        
        // 2
        /*
        if (NULL == source || NULL == target)
        {
            return -1;
        }
        if (*source == '\0' && *target == '\0')
        {
            return 0;
        }
        if (*source == '\0')
        {
            return -1;
        }
        if (*target == '\0')
        {
            return 0;
        }
        const char *first = source;
        const char *second = target;
        while (*first != '\0')
        {
            if (*first != *second)
            {
                first++;
            }
            else
            {
                while (*first != '\0' && *second != '\0')
                {
                    if (*first == *second)
                    {
                        first++;
                        second++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (*second == '\0')
                {
                    return first - source - strlen(target);
                }
                else
                {
                    second = target;
                }
            }
        }
        return -1;
        */
        // 3
        /*
        if (NULL == source || NULL == target)
        {
            return -1;
        }
        
        auto head = strstr(source, target);
        if (head != NULL)
        {
            return head - source;
        }
        else
        {
            return -1;
        }
        */
        
        // 4
    if (source == NULL || target == NULL)
    {
        return -1;
    }
    int target_size = strlen(target);
    int source_size = strlen(source);
    int i, j;
    for (i = 0; i < source_size - target_size + 1; i++)
    {
        for (j = 0; j < target_size; j++)
        {
            if (source[i + j] != target[j])
            {
                break;
            }
        }
        if (j == target_size)
        {
            return i;
        }
    }
    return -1;
    }
};


57 三数之和
给出一个有n个整数的数组S，在S中找到三个整数a, b, c，找到所有使得a + b + c = 0的三元组。

 注意事项

在三元组(a, b, c)，要求a <= b <= c。

结果不能包含重复的三元组。

您在真实的面试中是否遇到过这个题？ Yes
样例
如S = {-1 0 1 2 -1 -4}, 你需要返回的三元组集合的是：

(-1, 0, 1)

(-1, -1, 2)

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
     class COMPARE
     {
         public:
         bool operator() (const vector<int> &a, const vector<int> &b)
         {
             return a < b;
         }
     };
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        // 1
        /*
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++)
        {
            for (int j = i + 1; j < nums_size; j++)
            {
                for (int k = j + 1; k < nums_size; k++)
                {
                    if (0 == (nums[i] + nums[j] + nums[k]))
                    {
                        result.insert(vector<int>{nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
        */
            
    // 2        
    vector<vector<int> > result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        int head = i + 1;
        int tail = nums.size() - 1;
        int target = -nums[i];
        while (head < tail)
        {
            if (head > i + 1 && nums[head] == nums[head - 1])
            {
                ++head;
                continue;
            }
            if (nums[head] + nums[tail] < target)
            {
                ++head;
            }
            else if (nums[head] + nums[tail] > target)
            {
                --tail;
            }
            else
            {
                result.push_back(vector<int>{nums[i], nums[head], nums[tail]});
                ++head;
            }
        }
    }
    return result;
    }
};


59. 最接近的三数之和  3Sum Closest 


给一个包含 n 个整数的数组 S, 找到和与给定整数 target 最接近的三元组，返回这三个数的和。
注意事项

只需要返回三元组之和，无需返回三元组本身
您在真实的面试中是否遇到过这个题？
样例

例如 S = [-1, 2, 1, -4] and target = 1. 和最接近 1 的三元组是 -1 + 2 + 1 = 2.
挑战

O(n^2) 时间, O(1) 额外空间。


class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i)
        {
            int head = i + 1;
            int tail = nums.size() - 1;
            while (head < tail)
            {
                int sum = nums[i] + nums[head] + nums[tail];
                if (abs(closest_sum - target) > abs(sum - target))
                {
                    closest_sum = sum;
                }
                if (sum < target)
                {
                    ++head;
                }
                else
                {
                    --tail;
                }
            }
        }
        return closest_sum;
    }
};


58. 四数之和



给一个包含n个数的整数数组S，在S中找到所有使得和为给定整数target的四元组(a, b, c, d)。
注意事项

四元组(a, b, c, d)中，需要满足a <= b <= c <= d

答案中不可以包含重复的四元组。
您在真实的面试中是否遇到过这个题？
样例

例如，对于给定的整数数组S=[1, 0, -1, 0, -2, 2] 和 target=0. 满足要求的四元组集合为：

(-1, 0, 0, 1)

(-2, -1, 1, 2)

(-2, 0, 0, 2)


class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        // 1
        
        
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        for (int i = 0; i < (nums.size() - 3); ++i)
        {
            for (int j = i + 1; j < (nums.size() - 2); ++j)
            {
                int head = j + 1;
                int tail = nums.size() - 1;
                while (head < tail)
                {
                    if (head > j + 1 && nums[head] == nums[head - 1])
                    {
                        ++head;
                        continue;
                    }
                    int temp = nums[i] + nums[j] + nums[head] + nums[tail];
                    if (temp == target)
                    {
                        result.insert(vector<int>{nums[i], nums[j], nums[head], nums[tail]});
                        ++head;
                        --tail;
                    }
                    else if (temp < target)
                    {
                        ++head;
                    }
                    else
                    {
                        --tail;
                    }
                }
            }
        }
        return vector<vector<int>>(result.begin(), result.end());
        
        
    }
};


171. 乱序字符串
给出一个字符串数组S，找到其中所有的乱序字符串(Anagram)。如果一个字符串是乱序字符串，那么他存在一个字母集合相同，但顺序不同的字符串也在S中。

 注意事项

所有的字符串都只包含小写字母

您在真实的面试中是否遇到过这个题？ Yes
样例
对于字符串数组 ["lint","intl","inlt","code"]

返回 ["lint","inlt","intl"]

挑战 
What is Anagram?
- Two strings are anagram if they can be the same after change the order of characters.


class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        map<string, int> strs_map;
        for (auto s : strs)
        {
            sort(s.begin(), s.end());
            strs_map[s]++;
        }
        vector<string> result;
        for (auto s : strs)
        {
            auto temp = s;
            sort(temp.begin(), temp.end());
            if (strs_map[temp] > 1)
            {
                result.push_back(s);
            }
        }
        return result;
    }
};


208 赋值运算符重载    Assignment Operator Overloading


实现赋值运算符重载函数，确保：

    新的数据可准确地被复制
    旧的数据可准确地删除/释放
    可进行 A = B = C 赋值

您在真实的面试中是否遇到过这个题？
说明

本题只适用于C++，因为 Java 和 Python 没有对赋值运算符的重载机制。
样例

如果进行 A = B 赋值，则 A 中的数据被删除，取而代之的是 B 中的数据。

如果进行 A = B = C 赋值，则 A 和 B 都复制了 C 中的数据。
挑战

充分考虑安全问题，并注意释放旧数据。


class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        
        if (this !=&object)
        {
            delete m_pData;
            m_pData == NULL;
            if (NULL != object.m_pData)
            {
                m_pData = new char[strlen(object.m_pData) + 1];
                strcpy(m_pData, object.m_pData);
            }
        }
        return *this;
    }
};

92. 背包问题 backPack


在n个物品中挑选若干物品装入背包，最多能装多满？假设背包的大小为m，每个物品的大小为A[i]
注意事项

你不可以将物品进行切割。
您在真实的面试中是否遇到过这个题？
样例

如果有4个物品[2, 3, 5, 7]

如果背包的大小为11，可以选择[2, 3, 5]装入背包，最多可以装满10的空间。

如果背包的大小为12，可以选择[2, 3, 7]装入背包，最多可以装满12的空间。

函数需要返回最多能装满的空间大小。
挑战

O(n x m) time and O(m) memory.

O(n x m) memory is also acceptable if you do not know how to optimize memory.


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        //1  内存超过限制
        
        
        int thing_nums = A.size();
        //int dp[thing_nums][m + 1];
        vector<vector<int>> dp(thing_nums, vector<int>(m + 1));
        for (int i = 0; i < thing_nums; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < m + 1; j++)
        {
            if (A[0] > j)
            {
                dp[0][j] = 0;
            }
            else
            {
                dp[0][j] = A[0];
            }
            for (int i = 1; i < thing_nums; i++)
            {
                if (A[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j - A[i]] + A[i], dp[i - 1][j]);
                }
            }
        }
        return dp[thing_nums - 1][m];
        
        
        //2
        /*
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = m; j > 0; j--)
            {
                if (A[i] <= j)
                {
                    dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
                }
            }
        }
        return dp[m];
        */
        
    }
};


125 背包问题 II 


给出n个物品的体积A[i]和其价值V[i]，将他们装入一个大小为m的背包，最多能装入的总价值有多大？
注意事项

A[i], V[i], n, m均为整数。你不能将物品进行切分。你所挑选的物品总体积需要小于等于给定的m。
您在真实的面试中是否遇到过这个题？
样例

对于物品体积[2, 3, 5, 7]和对应的价值[1, 5, 2, 4], 假设背包大小为10的话，最大能够装入的价值为9。
挑战

O(n x m) memory is acceptable, can you do it in O(m) memory?


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        // 1
        /*
        int stuff_nums = A.size();
        int dp[stuff_nums][m + 1];
        fill((int *)dp, (int *)dp + stuff_nums * (m + 1), 0);
        //dp[i][j]为价值为最大价值, i为第i个物品，j为背包容量为j
        //vector<vector<int>> dp(stuff_nums, vector<int>(m + 1, 0));  
        for (int i = 0; i < stuff_nums; ++i)
        {
            dp[i][0] = 0;
        }
        for (int j = 1; j < m + 1; ++j)
        {
            if (A[0] > j)
            {
                dp[0][j] = 0;
            }
            else
            {
                dp[0][j] = V[0];
            }
            for (int i = 1; i < stuff_nums; ++i)
            {
                if (A[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j -A[i]] + V[i], dp[i - 1][j]);
                }
            }
        }
        return dp[stuff_nums - 1][m];
        */
        
        //2
        int stuff_nums = A.size();
        int dp[m + 1];
        fill(dp, dp + m + 1, 0);
        for (int i = 0; i < stuff_nums; ++i)
        {
            for (int j = m; j > 0; --j)
            {
                if (A[i] <= j)
                {
                    dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
                }
            }
        }
        return dp[m];
    }
};


564 背包问题 VI 
http://www.cnblogs.com/grandyang/p/5743719.html
http://www.cnblogs.com/grandyang/p/5705750.html

 背包问题 VI

    描述
    笔记
    数据
    评测

给出一个都是正整数的数组 nums，其中没有重复的数。从中找出所有的和为 target 的组合个数。
注意事项

一个数可以在组合中出现多次。
数的顺序不同则会被认为是不同的组合。
您在真实的面试中是否遇到过这个题？
样例

给出 nums = [1, 2, 4], target = 4
可能的所有组合有：

[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]

返回 6


这道题可以转换成一种背包问题。给一个数组表示n个物品每个数表示每个物品的重量， 物品可重复使用。如果有一个背包容量是w，让你找出恰好装满的所有可能性的数量。 抽象成dp公式就和numbers combination一样了。

我们需要一个一维数组dp，其中dp[i]表示目标数为i的解的个数，然后我们从1遍历到target，对于每一个数i，遍历nums数组，如果i>=x, dp[i] += dp[i - x]。这个也很好理解，比如说对于[1,2,3] 4，这个例子，当我们在计算dp[3]的时候，3可以拆分为1+x，而x即为dp[2]，3也可以拆分为2+x，此时x为dp[1]，3同样可以拆为3+x，此时x为dp[0]，我们把所有的情况加起来就是组成3的所有情况了

class Solution {
public:
    /**
     * @param nums an integer array and all positive numbers, no duplicates
     * @param target an integer
     * @return an integer
     */
    int backPackVI(vector<int>& nums, int target) {
        // Write your code here
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  //target为0时有一中组合，空数组
        for (int i = 1; i < target + 1; ++i)
        {
            for (auto each : nums)
            {
                if (each <= i)
                {
                    dp[i] += dp[i - each];
                }
            }
        }
        return dp.back();
    }
};


149 买卖股票的最佳时机
http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock/

    描述
    笔记
    数据
    评测

假设有一个数组，它的第i个元素是一支给定的股票在第i天的价格。如果你最多只允许完成一次交易(例如,一次买卖股票),设计一个算法来找出最大利润。
您在真实的面试中是否遇到过这个题？
样例

给出一个数组样例 [3,2,3,1,2], 返回 1 

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        // 1 超时
        /*
        int max_profit = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] - prices[i] > max_profit)
                {
                    max_profit = prices[j] - prices[i];
                }
            }
        }
        return max_profit;
        */
        
        // 2
        if (0 == prices.size())
        {
            return 0;
        }
        int max_profit = 0;
        int buy_prices = prices[0];
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] - buy_prices < 0)
            {
                buy_prices = prices[i];
            }
            else
            {
                if (prices[i] - buy_prices > max_profit)
                {
                    max_profit = prices[i] - buy_prices;
                }
            }
        }
        return max_profit;
    }
};

150  买卖股票的最佳时机 II

    描述
    笔记
    数据
    评测

假设有一个数组，它的第i个元素是一个给定的股票在第i天的价格。设计一个算法来找到最大的利润。你可以完成尽可能多的交易(多次买卖股票)。然而,你不能同时参与多个交易(你必须在再次购买前出售股票)。
您在真实的面试中是否遇到过这个题？
样例

给出一个数组样例[2,1,2,0,1], 返回 2

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (0 == prices.size())
        {
            return 0;
        }
        int max_profit = 0;
        int buy_prices = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] - buy_prices < 0)
            {
                buy_prices = prices[i];
            }
            else
            {
                max_profit += prices[i] - buy_prices;
                buy_prices = prices[i];
            }
        }
        return max_profit;
    }
};



151. 买卖股票的最佳时机 III 

 描述
 笔记
 数据
 评测
假设你有一个数组，它的第i个元素是一支给定的股票在第i天的价格。设计一个算法来找到最大的利润。你最多可以完成两笔交易。

 注意事项

你不可以同时参与多笔交易(你必须在再次购买前出售掉之前的股票)

您在真实的面试中是否遇到过这个题？ Yes
样例
给出一个样例数组 [4,4,6,1,1,4,2,5], 返回 6

http://blog.csdn.net/dr_unknown/article/details/51939121

分析：动态规划法。以第i天为分界线，计算第i天之 前 进行一次交易的最大收益preProfit[i]，和第i天之 后 进行一次交易的最大收益postProfit[i]，最后遍历一遍，max{preProfit[i] + postProfit[i]} (0≤i≤n-1)就是最大收益。第i天之前和第i天之后进行一次的最大收益求法同Best Time to Buy and Sell Stock I。

代码：时间O(n)，空间O(n)。

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int length = prices.size();
        if (0 == length)
        {
            return 0;
        }
        int pre_max_profit[length];  // 第一笔交易的最大收入
        int post_max_profit[length];  // 第二笔交易的最大收入
        fill(pre_max_profit, pre_max_profit + length, 0);
        fill(post_max_profit, post_max_profit + length, 0);
        int cur_min = prices[0];
        for (int i = 1; i < length; ++i)
        {
            cur_min = min(cur_min, prices[i]);
            pre_max_profit[i] = max(pre_max_profit[i - 1], prices[i] - cur_min);
        }
        int cur_max = prices[length - 1];
        for (int i = length - 2; i >= 0; --i)
        {
            cur_max = max(cur_max, prices[i]);
            post_max_profit[i] = max(post_max_profit[i + 1], cur_max - prices[i]);
        }
        int max_profit = 0;
        for (int i = 0; i < length; ++i)
        {
            max_profit = max(max_profit, pre_max_profit[i] + post_max_profit[i]);
        }
        return max_profit;
    }
};

69. 二叉树的层次遍历  Binary Tree Level Order Traversal


给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）
您在真实的面试中是否遇到过这个题？
样例

给一棵二叉树 {3,9,20,#,#,15,7} ：

  3
 / \
9  20
  /  \
 15   7

返回他的分层遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

挑战

挑战1：只使用一个队列去实现它

挑战2：用DFS算法来做


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int>> result;
        if (NULL == root)
        {
            return result;
        }
        queue<TreeNode *> treenode_queue;
        treenode_queue.push(root);
        while (!treenode_queue.empty())
        {
            int queue_size = treenode_queue.size();
            vector<int> temp_vector;
            for (int i = 0; i < queue_size; ++i)
            {
                TreeNode *temp_node = treenode_queue.front();
                treenode_queue.pop();
                temp_vector.push_back(temp_node->val);
                if (NULL != temp_node->left)
                {
                    treenode_queue.push(temp_node->left);
                }
                if (NULL != temp_node->right)
                {
                    treenode_queue.push(temp_node->right);
                }
            }
            result.push_back(temp_vector);
        }
        return result;
    }
};


70 二叉树的层次遍历 II Binary Tree Level Order Traversal II


给出一棵二叉树，返回其节点值从底向上的层次序遍历（按从叶节点所在层到根节点所在的层遍历，然后逐层从左往右遍历）
您在真实的面试中是否遇到过这个题？
样例

给出一棵二叉树 {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

按照从下往上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
 
 
class Solution {
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        //1
        /*
        vector<vector<int>> result;
        if (NULL == root)
        {
            return result;
        }
        queue<TreeNode *> treenode_queue;
        treenode_queue.push(root);
        while (!treenode_queue.empty())
        {
            int queue_size = treenode_queue.size();
            vector<int> temp_vector;
            for (int i = 0; i < queue_size; ++i)
            {
                TreeNode *temp_node = treenode_queue.front();
                treenode_queue.pop();
                temp_vector.push_back(temp_node->val);
                if (NULL != temp_node->left)
                {
                    treenode_queue.push(temp_node->left);
                }
                if (NULL != temp_node->right)
                {
                    treenode_queue.push(temp_node->right);
                }
            }
            result.push_back(temp_vector);
        }
        reverse(result.begin(), result.end());
        return result;
        */
        
        //2
        
        vector<vector<int>> result;
        if (NULL == root)
        {
            return result;
        }
        queue<TreeNode *> treenode_queue;
        treenode_queue.push(root);
        while (!treenode_queue.empty())
        {
            int queue_size = treenode_queue.size();
            vector<int> temp_vector;
            for (int i = 0; i < queue_size; ++i)
            {
                TreeNode *temp_node = treenode_queue.front();
                treenode_queue.pop();
                temp_vector.push_back(temp_node->val);
                if (NULL != temp_node->left)
                {
                    treenode_queue.push(temp_node->left);
                }
                if (NULL != temp_node->right)
                {
                    treenode_queue.push(temp_node->right);
                }
            }
            result.insert(result.begin(), temp_vector);
        }
        return result;
        
    }
};


94 二叉树中的最大路径和  Binary Tree Maximum Path Sum


给出一棵二叉树，寻找一条路径使其路径和最大，路径可以在任一节点中开始和结束（路径和为两个节点之间所在路径上的节点权值之和）
您在真实的面试中是否遇到过这个题？
样例

给出一棵二叉树：

       1
      / \
     2   3

返回 6



思路：
分析：每条最长路径都肯定会以某个顶点为跟，然后两边是以那个节点为跟到叶子节点的最长路径
http://blog.csdn.net/wangyuquanliuli/article/details/45897297
http://blog.csdn.net/zhaopengnju/article/details/51759938

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int result = INT_MIN;
        MaxSinglePathSum(root, result);
        return result;
    }
    
    // 返回从当前节点到叶子节点的最大路径和
    
    int MaxSinglePathSum(TreeNode *root, int &result)
    {
        if (NULL == root)
        {
            return 0;
        }
        int left_max_sum = MaxSinglePathSum(root->left, result);
        int right_max_sum = MaxSinglePathSum(root->right, result);
        result = max(result, max(0, left_max_sum) + max(0, right_max_sum) +
                    root->val);
        return max(0, max(left_max_sum, right_max_sum)) + root->val;
    }
    
};

394 硬币排成线 coins-in-a-line



有 n 个硬币排成一条线。两个参赛者轮流从右边依次拿走 1 或 2 个硬币，直到没有硬币为止。拿到最后一枚硬币的人获胜。

请判定 第一个玩家 是输还是赢？
您在真实的面试中是否遇到过这个题？
样例

n = 1, 返回 true.

n = 2, 返回 true.

n = 3, 返回 false.

n = 4, 返回 true.

n = 5, 返回 true.
挑战

O(1) 时间复杂度且O(1) 存储。

http://blog.csdn.net/waltonhuang/article/details/52040596
http://blog.csdn.net/wangyuquanliuli/article/details/47361395



class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        
        //1
        /*
        if (0 == n)
        {
            return false;
        }
        if (1 == n || 2 == n)
        {
            return true;
        }
        vector<bool> win_lose(n + 1);
        win_lose[0] = false;  // 0个硬币，输
        win_lose[1] = true;   // 1个硬币，赢
        win_lose[2] = true;
        for (int i = 3; i <= n; ++i)
        {
            win_lose[i] = !(win_lose[i - 1] && win_lose[i - 2]);
        }
        return win_lose[n];
        */
        
        //2
        /*
        if (n == 0)
            return false;
        if (n == 1 || n == 2)
            return true;
        bool pre = true;
        bool now = true;
        for (int i = 3; i <= n; i++)
        {
            bool tmp = now;
            now = !(pre && now);
            pre = tmp;
        }
        return now;
        */

        //3
        return n % 3 != 0;
    }
};


512 解码方法 Decode Ways


有一个消息包含A-Z通过以下规则编码

'A' -> 1
'B' -> 2
...
'Z' -> 26

现在给你一个加密过后的消息，问有几种解码的方式
您在真实的面试中是否遇到过这个题？
样例

给你的消息为12，有两种方式解码 AB(12) 或者 L(12). 所以返回 2

http://www.cnblogs.com/grandyang/p/4313384.html
http://www.jiuzhang.com/solution/decode-ways/

类似斐波那契数列
dp[s.size()]
如果s[i] 为‘0’，则无法解码，dp[i] = 0, 否则， dp[i] = dp[i - 1]
继续计算dp[i]
若s[i - 1] 与 s[i]构成的数字可以解码，则dp[i] 再加上dp[i - 2],即：
dp[i] += dp[i - 2]

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        if (s.size() == 0)
        {
            return 0;
        }
        else if (s.size() == 1)
        {
            return s[0] == '0' ? 0 : 1;
        }
        if (s[0] == '0')
        {
            return 0;
        }
        vector<int> dp(s.size());
        dp[0] = 1;
        dp[1] = (s[1] == '0') ? 0 : dp[0];
        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6'))
        {
            dp[1] += 1;
        }
        for (int i = 2; i < s.size(); ++i)
        {
            dp[i] = (s[i] == '0') ? 0 :dp[i - 1];
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
            {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp.back();
        
    }
};



118  不同的子序列

给出字符串S和字符串T，计算S的不同的子序列中T出现的个数。

子序列字符串是原始字符串通过删除一些(或零个)产生的一个新的字符串，并且对剩下的字符的相对位置没有影响。(比如，“ACE”是“ABCDE”的子序列字符串,而“AEC”不是)。 
您在真实的面试中是否遇到过这个题？
样例

给出S = "rabbbit", T = "rabbit"

返回 3
挑战

Do it in O(n2) time and O(n) memory.

O(n2) memory is also acceptable if you do not know how to optimize memory.

http://blog.csdn.net/cumt_cx/article/details/47926381


class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (S.size() < T.size())
        {
            return 0;
        }
        if (T.size() == 0)
        {
            return 1;
        }
        // dp[S.size()][T.size()], S中，前i个字符，转化为T中，前j个字符的方法个数
        vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= S.size(); ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= S.size(); ++i)
        {
            for (int j = 1; j <= T.size(); ++j)
            {
                dp[i][j] = dp[i - 1][j] + (S[i - 1] == T[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[S.size()][T.size()];
    }
};


77 最长公共子序列 longestCommonSubsequence
给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度。

 说明

最长公共子序列的定义：

    最长公共子序列问题是在一组序列（通常2个）中找到最长公共子序列（注意：不同于子串，LCS不需要是连续的子串）。该问题是典型的计算机科学问题，是文件差异比较程序的基础，在生物信息学中也有所应用。
    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

样例

给出"ABCD" 和 "EDCA"，这个LCS是 "A" (或 D或C)，返回1

给出 "ABCD" 和 "EACB"，这个LCS是"AC"返回 2


http://blog.csdn.net/v_july_v/article/details/6695482
http://blog.csdn.net/waltonhuang/article/details/52032463


class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        /*
        if (A.empty() || B.empty())
        {
            return 0;
        }
        */
        int dp[A.size() + 1][B.size() + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= A.size(); ++i)
        {
            for (int j = 1; j <= B.size(); ++j)
            {
                if (A[i - 1] == B[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i -1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[A.size()][B.size()];
    }
};

76 最长上升子序列

给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。
您在真实的面试中是否遇到过这个题？
说明

最长上升子序列的定义：

最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。
https://en.wikipedia.org/wiki/Longest_increasing_subsequence
样例

给出 [5,4,1,2,3]，LIS 是 [1,2,3]，返回 3
给出 [4,2,4,5,3,7]，LIS 是 [2,4,5,7]，返回 4

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        /*
        if (nums.empty())
        {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        int longest_num = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(1, dp[j] + 1);
                }
            }
            longest_num = max(longest_num, dp[i]);
        }
        return longest_num;
        */
        int f[nums.size()];

        int max = 0;

        for (int i = 0; i < nums.size(); i++) {

            f[i] = 1;

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    f[i] = f[i] > f[j] + 1 ? f[i] : f[j] + 1;

                }

            }

            if (f[i] > max) {

                max = f[i];

            }

        }

        return max;

        
    }
};



135  数字组合

给出一组候选数字(C)和目标数字(T),找到C中所有的组合，使找出的数字和为T。C中的数字可以无限制重复被选取。

例如,给出候选数组[2,3,6,7]和目标数字7，所求的解为：

[7]，

[2,2,3]
注意事项

    所有的数字(包括目标数字)均为正整数。
    元素组合(a1, a2, … , ak)必须是非降序(ie, a1 ≤ a2 ≤ … ≤ ak)。
    解集不能包含重复的组合。 

您在真实的面试中是否遇到过这个题？
样例

给出候选数组[2,3,6,7]和目标数字7

返回 [[7],[2,2,3]]

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
     vector<vector<int>> result;
     vector<int> temp;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        sort(candidates.begin(), candidates.end());
        vector<int>::iterator last = unique(candidates.begin(), candidates.end());
        candidates.erase(last, candidates.end());
        Search(candidates, target, 0);
        return result;
    }
    
    void Search(vector<int> &candidate, int target, int begin_index)
    {
        if (target == 0)
        {
            result.push_back(temp);
        }
        else
        {
            for (int i = begin_index; i < candidate.size(); ++i)
            {
                if (candidate[i] <= target)
                {
                    temp.push_back(candidate[i]);
                    Search(candidate, target -candidate[i], i);
                    temp.pop_back();
                }
            }
        }
    }
};
