452.ɾ��������ָ��Ԫ��  //Remove Linked List Elements
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
        // ����1
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
        
        // ����2
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




/// 1. A + B���⣬  ������������a��b, �����ǵĺ�, ������ʹ�� + ����ѧ�����

//����˼·��
//������ʾ��������Ҫ����λ����ģ��ӷ����㡣�����뵽����������㣬
//��λ������ģ��һ�ֲ���λ�ļӷ����㣬������Ƶ�11^10=01��
//ÿһλ��������ÿһλ�ļӷ�������ȱ����λ����ν����λ�������أ�
//���������������Ǻ����˽�λ����ôÿ���н�λ����ʱ����������൱�ں����˸�λ��һ��1��
//ʹ�ð�λ�롰&��������԰��������жϸ�λ�Ƿ��н�λ����11&11 =11��
//˵����λ�ڼ������ж������˽�λ1�����ڸý�λ�Ǽ��ڸ�λ�ϵģ�
//���Ժ���Ȼ���뵽�˰�������Ľ��������һλ���ٺ��������ӣ���Ϊ�������
//�������£�

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

/// 366. 쳲�������  ����쳲����������е� N ����

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


/// 408.���������

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


/// 167. ������ͣ�
//����������������������������ÿ���ڵ����һ�����֡�
//���ִ洢������ԭ���������෴��˳��ʹ�õ�һ������λ������Ŀ�ͷ��
//д��һ������������������ӣ���������ʽ���غ͡�
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



/// 66. ������ǰ�����
// ����һ�ö�������������ڵ�ֵ��ǰ�������

// �Լ���
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


// �����㷨
/**
 * �������ɾ����㷨�༭�ṩ��û�а�Ȩ��ӭת����
 * - �����㷨�����ڰ��������й����ҵ��õĹ�������ʦ�ŶӾ����Թ�Ⱥ͹��ڵ�һ�ߴ�˾��ְ����ʦ��
 * - ���е�������ѵ�γ̰����������㷨�࣬ϵͳ��ư࣬BAT���ڰ�
 * - ������������ٷ���վ��http://www.jiuzhang.com/
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


// 67. �������������
// ����һ�ö�����,�������������

// �Լ�

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


///  68.�������ĺ������
// ����һ�ö�������������ڵ�ֵ�ĺ��������

// �Լ�

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


/// 93.ƽ�������
// ����һ��������,ȷ�����Ǹ߶�ƽ��ġ������������,
//һ�ø߶�ƽ��Ķ������Ķ����ǣ�һ�ö�������ÿ���ڵ������������������ᳬ��1��

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


/// 480. ������������·��
// ��һ�ö��������ҳ��Ӹ��ڵ㵽Ҷ�ӽڵ������·����

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

/// 111. ��¥��
// ������������¥�ݣ���Ҫn������ܵ��ﶥ������ÿ����ֻ����һ�����������������ж����ֲ�ͬ�ķ�������¥������

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


/// 55. �Ƚ��ַ���
// �Ƚ������ַ���A��B��ȷ��A���Ƿ����B�����е��ַ����ַ���A��B�е��ַ����� ��д��ĸ
//ע������
//�� A �г��ֵ� B �ַ�������ַ�����Ҫ������������

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


/// 177.  ����������ת��Ϊ�߶���С�Ķ���������
// ��һ���������飨��С���󣩣�����ת��Ϊһ�ø߶���С�������������
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

/// 445.  �������ƶ�
///media/problem/cosine-similarity.png
//����������ͬ��С������ A B��������ǵ��������ƶ�
//���� 2.0000 ����������Ʋ��Ϸ� (���� A = [0] B = [0]).
// ����
// ���� A = [1, 2, 3], B = [2, 3 ,4].
// ���� 0.9926.
// ���� A = [0], B = [0].
// ���� 2.0000

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



/// 365. ���������ж��ٸ�1
// ������һ�� 32 λ�������Ķ����Ʊ�ʽ���ж��ٸ� 1

// ����1
// ���һ��������Ϊ0����ô�������������һλ��1��������ǰ����������1
// ����ôԭ�������������ұߵ�1�ͻ��Ϊ0��ԭ����1��������е�0������1(������ұߵ�1���滹��0�Ļ�)��
// ��������λ�������ܵ�Ӱ�졣�ٸ����ӣ�һ����������1100�����ұ��������λ�Ǵ������ұߵ�һ��1��
// ��ȥ1�󣬵���λ���0�����������λ0�����1����ǰ���1���ֲ��䣬��˵õ��Ľ����1011.
// ���Ƿ��ּ�1�Ľ���ǰ����ұߵ�һ��1��ʼ������λ��ȡ���ˡ�
// ���ʱ����������ٰ�ԭ���������ͼ�ȥ1֮��Ľ���������㣬��ԭ���������ұ�һ��1��һλ��ʼ����λ������0��
// ��1100&1011=1000.Ҳ����˵����һ��������ȥ1���ٺ�ԭ�����������㣬
// ��Ѹ��������ұ�һ��1���0.��ôһ�������Ķ������ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
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

// ����2
// ʹ�����Ʋ���, -1>>1֮����-1��Ҳ����˵������Ҫ���⴦��Ϊ�˽��������⣬ֻ��Ҫ��int��ת����unsigned int�͡�
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

// ����3
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

// ����4

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


/// 420. ����
//����ָ���ǣ��������е�������˳����б�����Ȼ��õ���һ������������ʾ��
//1, 11, 21, 1211, 111221, ...
//1 ���� "one 1" -> 11.
//11 ���� "two 1s" -> 21.
//21 ���� "one 2, then one 1" -> 1211.
//����һ������ n, ���� �� n ��˳��
// ע������
//������˳�򽫱�ʾΪһ���ַ�����
//����
//���� n = 5, ���� "111221".

// ����1 self
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

// ����2
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


/// 372. ��O(1)ʱ�临�Ӷ�ɾ������ڵ�
// ����һ���������е�һ���ȴ���ɾ���Ľڵ�(�Ǳ�ͷ���β)��������O(1)ʱ�临�Ӷ�ɾ��������ڵ㡣
// ����
// ���� 1->2->3->4���ͽڵ� 3��ɾ�� 3 ֮������Ӧ�ñ�Ϊ 1->2->4��
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



/// 14.���ֲ���
// ����һ��������������飨���򣩺�һ��Ҫ���ҵ�����target��
// ��O(logn)��ʱ����ҵ�target��һ�γ��ֵ��±꣨��0��ʼ�������target�������������У�����-1

// ����1
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

// ����2
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

// ����3
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


/// 375,��¡������
// ��ȸ���һ��������������һ��������������һ������ ��¡Ʒ 

// ����1��
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


// ����2��
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


/// 22. ƽ���б�
// ����һ���б����б��е�ÿ��Ҫ��Ҫô�Ǹ��б�Ҫô��������������һ��ֻ���������ļ��б�
 // ע������
// ����������б��е�Ҫ�ر���Ҳ��һ���б���ô��Ҳ���԰����б�
// ����
// ���� [1,2,[1,2]]������ [1,2,1,2]��
// ���� [4,[3,[2,[1]]]]������ [4,3,2,1]��
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



/// 128. ��ϣ����
// �����ݽṹ�У���ϣ������������һ���ַ��������κ��������ͣ�ת��ΪС�ڹ�ϣ���С�Ҵ��ڵ������������һ���õĹ�ϣ�������Ծ������ٵز�����ͻ��һ�ֹ㷺ʹ�õĹ�ϣ�����㷨��ʹ����ֵ33�������κ��ַ������ǻ���33��һ�������������磺
// hashcode("abcd") = (ascii(a) * 333 + ascii(b) * 332 + ascii(c) *33 + ascii(d)) % HASH_SIZE 
                              // = (97* 333 + 98 * 332 + 99 * 33 +100) % HASH_SIZE
                              // = 3595978 % HASH_SIZE
// ����HASH_SIZE��ʾ��ϣ��Ĵ�С(���Լ���һ����ϣ�����һ������0 ~ HASH_SIZE-1������)��
// ����һ���ַ�����Ϊkey��һ����ϣ��Ĵ�С����������ַ����Ĺ�ϣֵ��

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        /*  // ����ȷ
        int key_length = key.length();
        long long sum = 0;
        for (int i = key_length - 1; i != -1; i--)
        {
            sum += (int)(key[i]) * pow(33, i);
        }
        return sum % HASH_SIZE;
        */
        
        // ��ȷ
        int ans = 0;
        for(int i = 0; i < key.size();i++) {
            ans = (1LL * ans * 33 + key[i]) % HASH_SIZE; 
        }
	    return ans;
	    
    }
};


/// 469.�ȼ۶�����
// ������ö������Ƿ�ȼۡ��ȼ۵���˼��˵���������ö���������ӵ����ͬ�Ľṹ������ÿ����Ӧλ���ϵĽڵ��ϵ�������ȡ�

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


/// 30.��������
// ����һ�����ص��İ���������ʼ�˵�����������б�
// ���б��в���һ���µ����䣬��Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
// ������ʵ���������Ƿ�����������⣿ Yes
// ����
// ��������[2, 5] �� [[1,2], [5,9]]�����ǵõ� [[1,9]]��
// ��������[3, 4] �� [[1,2], [5,9]]�����ǵõ� [[1,2], [3,4], [5,9]]��
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

/// 85.�ڶ���������в���ڵ�
// ����һ�ö����������һ���µ����ڵ㣬���ڵ���뵽���С�
// ����Ҫ��֤������Ȼ��һ�ö����������


// ����1
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

// ����2
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


/// 173. �����������
// �ò����������������
// ˼·������һ���ƽڵ㣬 �������еĽڵ�һ��һ�������ƽڵ㿪ʼ�������У������ƽڵ�����

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
        
        ListNode *dummy = new ListNode; // ����һ�����ƽڵ�Ϊͷ�ڵ������
        ListNode *temp = nullptr;
        while (head != nullptr)
        {
            temp = dummy;
            ListNode *next = head->next;
            // ���ƽڵ�������Ѱ�Ҳ���ڵ㣬���ýڵ�������
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

// ��ͬ��������һ�ֱ�̱�ʾ
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        // ˼·������һ���ƽڵ㣬 �������еĽڵ�һ��һ�������ƽڵ㿪ʼ�������У������ƽڵ�����
        if (NULL == head)
        {
            return head;
        }
        ListNode dummy;// �ƽڵ�
        ListNode *temp;
        while (NULL != head)
        {
            temp = &dummy;
            // ����Դ������ͷ������һ���ڵ�
            ListNode *next = head->next;
            // ���ƽڵ�������Ѱ�Ҳ���ڵ㣬���ýڵ�������
            while (temp->next != NULL && temp->next->val < head->val)
            {
                temp = temp->next;
            }
            // ���ƽڵ��������ҵ������temp����temp֮�����head�ڵ㣬��Ҫ��temp֮�������ӵ�
            // head�ڵ�֮��
            head->next = temp->next;
            temp->next = head;
            head = next;
        }
        return dummy.next;
    }
};

/// 35. ��תһ������  Reverse Linked List
// ����һ������1->2->3->null�������ת�������Ϊ3->2->1->null

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
        // 1. ����ͷ�巨��ת
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
        
        // 2.��ԭ�����Ͻ��з�ת
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


/// 547. ������Ľ� the intersection of two arrays
// ������������Ľ�
// nums1 = [1, 2, 2, 1], nums2 = [2, 2], ���� [2]
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

		// ����2
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
        // ����3
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

/// 548.������Ľ� II
// ������������Ľ�
// ע������
// ÿ��Ԫ�س��ִ����ú���������һ��
// �𰸿���������˳�����

// ����
// nums1 = [1, 2, 2, 1], nums2 = [2, 2], ���� [2, 2].

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        // ����1
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
        
        // ����2
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
        // ����3
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


/// 175. ��ת������  Invert Binary Tree
// ��תһ�ö�����
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
        // ����1 �ݹ�
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
        
        // ����2 ����
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

/// 524. �����
// ʵ��һ��leftpad�⣬�����֪��ʲô��leftpad���Կ�����
// leftpad("foo", 5)
// >> "  foo"
// leftpad("foobar", 6)
// >> "foobar"
// leftpad("1", 2, "0")
// >> "01"

// ��ע��sizeС��originalStr����ʱ��ֱ�ӷ���originalStr

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

///. 422 ���һ�����ʵĳ���
// ����һ���ַ����� ������Сд��ĸ���ո�' '���뷵�������һ�����ʵĳ��ȡ�
// ������������һ�����ʣ��뷵�� 0 ��
 // ע������
// һ�����ʵĽ綨�ǣ�����ĸ��ɣ����������κεĿո�
// ���� s = "Hello World"������ 5��

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
		// ɾ�����һ�����ʺ�Ŀո�
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

///.397 ���������������

// ����һ���������飨�±�� 0 �� n-1�� n ��ʾ��������Ĺ�ģ�������ҳ��������е���������������С�����������������п��Զ���Ϊ���ҵ��������ҵ����С���
// ����
// ���� [5, 4, 2, 1, 3], ����������������У�LICS��Ϊ [5, 4, 2, 1], ���� 4.

// ���� [5, 1, 2, 3, 4], ����������������У�LICS��Ϊ [1, 2, 3, 4], ���� 4.


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

// �����㷨��
/**
 * �������ɾ����㷨�༭�ṩ��û�а�Ȩ��ӭת����
 * - �����㷨�����ڰ��������й����ҵ��õĹ�������ʦ�ŶӾ����Թ�Ⱥ͹��ڵ�һ�ߴ�˾��ְ����ʦ��
 * - ���е�������ѵ�γ̰����������㷨�࣬ϵͳ��ư࣬����ǿ���࣬Java����������㷨��
 * - ������������ٷ���վ��http://www.jiuzhang.com/
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


///. 133.�����
// ��һ���ʵ䣬�ҳ�����������ĵ��ʡ�
// �ڴʵ�

// {
  // "dog",
  // "google",
  // "facebook",
  // "internationalization",
  // "blabla"
// }
// ��, ��ĵ��ʼ���Ϊ ["internationalization"]

// �ڴʵ�

// {
  // "like",
  // "love",
  // "hate",
  // "yes"
// }
// �У���ĵ��ʼ���Ϊ ["like", "love", "hate"]

// ����1
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

// ����2
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


/// 46.��Ԫ��
// ����һ���������飬�ҳ���Ԫ�أ����������еĳ��ִ����ϸ��������Ԫ�ظ����Ķ���֮һ��
// ����
// ��������[1,1,1,1,2,2,2]������ 1

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


///��185 �����֮���ͱ���
// ����һ������ m x n ��Ԫ�صľ��� (m ��, n ��), ��þ����֮���ͱ���
// ����
// �������¾���

// [
  // [1, 2,  3,  4],
  // [5, 6,  7,  8],
  // [9,10, 11, 12]
// ]
// ���� [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

// ����1�� δ����

/**
 * �������ɾ����㷨�༭�ṩ��û�а�Ȩ��ӭת����
 * - �����㷨�����ڰ��������й����ҵ��õĹ�������ʦ�ŶӾ����Թ�Ⱥ͹��ڵ�һ�ߴ�˾��ְ����ʦ��
 * - ���е�������ѵ�γ̰����������㷨�࣬ϵͳ��ư࣬����ǿ���࣬Java����������㷨��
 * - ������������ٷ���վ��http://www.jiuzhang.com/
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

// ����2
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


/// 97.��������������
// ����һ�����������ҳ��������ȡ�
// �����������Ϊ���ڵ㵽��ԶҶ�ӽڵ�ľ��롣

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

/// 41.���������
// ����һ���������飬�ҵ�һ���������͵������飬���������͡�

 // ע������

// ���������ٰ���һ����
// ����
// ��������[?2,2,?3,4,?1,2,1,?5,3]������Ҫ���������Ϊ[4,?1,2,1]��������Ϊ6

// ����1 ʱ�临�Ӷȳ���Ҫ�� O(n2)
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
            //j <= nums_size�����еȺţ������޷���ȡ���һ��Ԫ��
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

// ����2  ԭ����
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

// ����3 ʱ�临�Ӷ� O��n��

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
     
        int size = nums.size();
        int cur_sum = nums[0];  // ���±�iΪ�������������
        int max_sum = nums[0];  // ǰi��Ԫ�ص�����������
        for (int i = 1; i < size; i++)
        {
            if (cur_sum < 0)
            {
                cur_sum = 0;
            }
            cur_sum += nums[i];
            if (cur_sum > max_sum)				//����ۼӺͳ���С��0�������������������п϶������ܰ���ǰ���Ԫ�أ�
            {                                   // ��ʱ���ۼӺ���0�����¸�Ԫ�����¿�ʼ�ۼ�
                max_sum = cur_sum;
            }
        }
        return max_sum;
        
    }
};


///. ��λ��
// ����һ��δ������������飬�ҵ�����λ����
// ��λ���������������м�ֵ���������ĸ�����ż�������򷵻����������ĵ�N/2������
// ��������[4, 5, 1, 2, 3]�� ���� 3
// ��������[7, 9, 4, 5]������ 5

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
		// ����1
        /*
        sort(nums.begin(), nums.end());
        int nums_length = nums.size();
        return nums[(nums_length - 1) / 2];
        */

		// ����2
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


///.156 �ϲ�����

// �������ɱպ����䣬�ϲ������ص��Ĳ��֡�
// �����������б� => �ϲ���������б�

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
        // ����1
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
        
        // ����2
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


///.6 �ϲ������������������A��B���һ���µ����顣
// ����A=[1,2,3,4]��B=[2,4,5,6]������ [1,2,2,3,4,4,5,6]

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        // ����1
        /*
        multiset<int> set_result(A.begin(), A.end());
        set_result.insert(B.begin(), B.end());
        vector<int> result(set_result.begin(), set_result.end());
        return result;
        */
        
        // ����2
        /*
        vector<int> result(A.begin(), A.end());
        result.insert(result.end(), B.begin(), B.end());
        sort(result.begin(), result.end());
        return result;
        */
        
        // ����3
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


///.64 �ϲ��������� II  Merge Sorted Array
// �ϲ������������������A��B���һ���µ����顣

 // ע������

// ����Լ���A�����㹻�Ŀռ䣨A����Ĵ�С���ڻ����m+n��ȥ���B�е�Ԫ�ء�
// ���� A = [1, 2, 3, empty, empty], B = [4, 5]

// �ϲ�֮�� A ����� [1,2,3,4,5]

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


/// 165.�ϲ�������������  Merge Two Sorted Lists

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
 // ����1
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
 
 // ����2
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

///155.����������С���
// ����һ�����������ҳ�����С��ȡ�

// ����������С���Ϊ���ڵ㵽���Ҷ�ӽڵ�ľ��롣
// ����һ�����µĶ�����:

        // 1

     // /     \ 

   // 2       3

          // /    \

        // 4      5  

// �������������С���Ϊ 2

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


110 ��С·����  Minimum Path Sum   // ����յ�Ҳ��·����Ҳ��Ҫ�ӽ�ȥ
����һ��ֻ���Ǹ�������m*n�����ҵ�һ�������Ͻǵ����½ǵĿ���ʹ���ֺ���С��·����

 ע������

����ͬһʱ��ֻ�����»��������ƶ�һ��

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
        int min_path[m][n];  // ����㵽ĳ�������С·����
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


44��С������
// ����һ���������飬�ҵ�һ��������С�͵������顣��������С�͡�

 // ע������
// ���������ٰ���һ������
// ����
// ��������[1, -1, -2, 1]������ -3


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


539. �ƶ���
��һ������ nums дһ�������� 0 �ƶ������������棬����Ԫ�ر���ԭ�����˳��

 // ע������

// 1.������ԭ�����ϲ���
// 2.��С��������
// ����
// ���� nums = [0, 1, 0, 3, 12], ���ú���֮��, nums = [1, 3, 12, 0, 0].

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        // Write your code here
        // ����1
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
        
        // ����2
        /*
        auto last = remove(nums.begin(), nums.end(), 0);
        for (auto &it = last; it != nums.end(); it++)
        {
            *it = 0;
        }
        */
        
        // ����3
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

	// ����4  �����
        int left = 0, right = 0;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            right++;
        }
    }
};



166.��������n���ڵ�
// �ҵ�����������n���ڵ㣬��֤�����нڵ����������Ϊn��

// ����
// �������� 3->2->1->5->null��n = 2�����ص����ڶ����ڵ��ֵ1.

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
        // ����1
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
        
        // ����2
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

433.����ĸ���
��һ��01������ͬ�ĵ���ĸ�����

0������1�������������1���ڣ���ô������1����ͬһ����������ֻ������������Ϊ���ڡ�

�ھ���

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


142.O(1)ʱ����2���ݴ�

�� O(1) ʱ�������� n �Ƿ��� 2 ���ݴΡ�

 ע������

O(1) ʱ�临�Ӷ�

n=4������ true;

n=5������ false.

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


514.դ��Ⱦɫ

������һ��դ��������n�����ӣ�����Ҫ������Ⱦɫ����k����ɫ����Ⱦ��
���뱣֤�����������ڵ�������ɫ��ͬ�����ж�����Ⱦɫ������

 ע������

n��k���ǷǸ�����

������ʵ���������Ƿ�����������⣿ Yes
����
n = 3, k = 2, return 6

      post 1,   post 2, post 3
way1    0         0       1 
way2    0         1       0
way3    0         1       1
way4    1         0       0
way5    1         0       1
way6    1         1       0


�������

��������

lintcode���������⣬ԭ���ǡ����뱣֤�����������ڵ�������ɫ��ͬ��Ӧ�ñ���Ϊ ����������������������ɫ��ͬ����

�ο�

LintCode:դ��Ⱦɫ 
�ο���ĵ��ı����о�Ҳ���ԣ�����Ӧ��˵����������������������ɫ��ͬ����

�ʼ�

�ڸĵ��������������£� 
����buff[i]Ϊ��i������ʱ��Ⱦɫ���������Է�Ϊ��������� 
1. �������������ɫ��ͬ�� 
ǰi-2�������Ѿ���buff[i-2]�ַ����ˣ���i-1���͵�i������ȡ��ͬ����ɫ������Ҫ��i-2�����Ӳ�ͬ���У�k-1����ȡ���� 
2. �������������ɫ��ͬ�� 
ǰi-1�����ӷ���Ҫ���Ѿ���buff[i-1]�ַ����ˣ���i�����ӵ���ɫҪ�͵�i-1��������ɫ��ͬ�����У�k-1���ַ����� 
�ɴˣ�״̬ת�Ʒ���Ϊ��

buff[i] = buff[i-1] * (k-1) + buff[i-2] * (k-1);

��ʼ������ 
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


373.��ż�ָ�����
�ָ�һ���������飬ʹ��������ǰż���ں�

����
���� [1, 2, 3, 4]������ [1, 3, 2, 4]��

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        // ����1
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
        
        // ����2
        
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
            if (j >= nums_size) // ��С���Ӷ�
            {
                return;
            }
        }
        
        
        // ����3
        //partition(nums.begin(), nums.end(), [](int &it) { return (it & 1);});
    }
};


96.������
����һ�����������ֵx����������ʹ������С��x�Ľڵ����ڴ��ڵ���x�Ľڵ�֮ǰ��

��Ӧ�ñ���������������ڵ�ԭ�е����˳��

����
�������� 1->4->3->2->5->2->null������ x=3

���� 1->2->2->4->3->5->null

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
        tail_larger->next = NULL;   // ���һ������x��������β�ڵ�
        tail_smaller->next = (&dummy_larger)->next;
        head = (&dummy_smaller)->next;
        return head;
        
    }
};

197.������� permutation-index

// ����1  ���� �۰�������򣨴Ӻ���ǰ����)����� 
1.���ȹ۲�һ��ȫ���У� ���磺95412 = X

����a.��Ŀת���ɰ����ֵ������ȫ����֮ǰ�ж��ٸ�ȫ���С�

����b.X��ǰ�������ȫ�����У�����λ��1�Ͽ�����5, 4, 1, 2����һ���������Ҷ�Ӧ��ȫ���еĻ�������4!����

����c.ͬ��λ��2, 3, 4, 5��Ӧ�Ļ����ֱ��ǣ�3����2����1����0��(0!==0)��

����d.�õ���λ�ö�Ӧ�Ļ�������ô��λ�ö�Ӧ���ٸ��ɱ����֣�9����λ�ö�Ӧ�Ŀɱ����ֵĸ���Ϊ4���ֱ���5,4,1,2��

������5����λ�ö�Ӧ�Ŀɱ�������4,1,2��4����λ�ö�Ӧ�Ŀɱ�������1,2,��1����λ�õĶ�Ӧ�Ŀɱ�����:�ޡ�2����λ��

����   ��Ӧ�ɱ���Ҳ���ޡ�

����e.���Եõ����ۣ�Xȫ����ĳ��λ���϶�Ӧ�Ŀɱ����ֵĸ��� == ����������ж��ٸ�����С�����ĸ�����

����f.Ϊ�˵õ�ĳ���������ж��ٸ�����С�����ĸ��������ǲ����۰�������򣨴Ӻ���ǰ���룩��


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
        for(int i=len-2; i>=0; --i){//ͳ��ÿ���������ж��ٸ�����С�����ĸ���
            vector<int>::iterator it = lower_bound(a.begin(), a.end(), A[i]);
            cnt[i] = it-a.begin();
            a.insert(it, A[i]);
        }
        
        long long ans=1, fac=1, c=1;//����fac��1��ʼ
        for(int i=len-2; i>=0; --i)
            ans += (fac*=c++)*cnt[i];
        return ans;
    }
};

// ����2  ����STL����ʱ
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


����3.
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
        long long ans=1, fac=1, c=1;//����fac��1��ʼ
        for(int i=len-2; i>=0; --i) // �ӵ����ڶ���Ԫ�ؿ�ʼ����
        {
            fac = fac * c;
            ans += fac * cnt[i];
            c++;
        }
           
        return ans;
    }
};


407.��һ
// ����һ���Ǹ�������ʾһ���������飬�ڸ����Ļ�����+1������һ���µ����顣

�����ְ��մ�С�������У����������б����ǰ�档

����
���� [1,2,3] ��ʾ 123, ���� [1,2,4].

���� [9,9,9] ��ʾ 999, ���� [1,0,0,0].

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


50.�����޳�Ԫ�غ�ĳ˻�  product of array exclude itself
����һ����������A��

����B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]�� ����B��ʱ���벻Ҫʹ�ó�����

����A=[1, 2, 3]������ BΪ[6, 3, 2]

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        // ����1
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
        
        // ����2
        /*
        vector<long long> result;
        int nums_size = nums.size();
        long long right[nums_size + 1]; //i��i�ĳ˻�
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
        
        // ����3
        vector<long long> result;
        int nums_size = nums.size();
        long long left[nums_size];  // i֮ǰԪ�صĻ���������i
        long long right[nums_size]; // i֮��Ԫ�صĻ���������i
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


39. �ָ���ת�������� Recover Rotated Sorted Array
����һ����ת�������飬��ԭ�ػָ�������

ʲô����ת���飿

���磬ԭʼ����Ϊ[1,2,3,4], ������ת���������[1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
����
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

100 ɾ�����������е��ظ�����  Remove Duplicate Numbers in Array
����һ���������飬��ԭ������ɾ���ظ����ֵ����֣�ʹ��ÿ��Ԫ��ֻ����һ�Σ����ҷ����µ�����ĳ��ȡ�
��Ҫʹ�ö��������ռ䣬������ԭ��û�ж���ռ����������ɡ�

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
        
        //method 2 ��ʱ
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

101 ɾ�����������е��ظ����� II  Remove Duplicates from Sorted Array II
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

112 ɾ�����������е��ظ�Ԫ��    Remove Duplicates from Sorted List
����һ����������ɾ�������ظ���Ԫ��ÿ��Ԫ��ֻ����һ����
����
���� 1->1->2->null������ 1->2->null
���� 1->1->2->3->3->null������ 1->2->3->null

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

172  ɾ��Ԫ��     Remove Element
����һ�������һ��ֵ����ԭ��ɾ����ֵ��ͬ�����֣�����������ĳ��ȡ�
Ԫ�ص�˳����Ըı䣬���Ҷ��µ����鲻����Ӱ�졣

����һ������ [0,4,4,0,0,2,4,4]����ֵ 4

���� 4 ����4��Ԫ�ص�������Ϊ[0,0,0,2]

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

174 ɾ�������е�����n���ڵ�     Remove Nth Node From End of List
����һ������ɾ�������е�����n���ڵ㣬���������ͷ�ڵ㡣
����
��������1->2->3->4->5->null�� n = 2.
ɾ�������ڶ����ڵ�֮������������1->2->3->5->null.

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
        for (int i = 1; i < the_node_num; i++)  // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
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
        for (int i = 0; i < n - 1; i++)  // p2ָ��������n���ڵ�
        {
            p2 = p2->next;
        }
        ListNode dummy;
        dummy.next = head;
        head = &dummy;
        while (p2->next != NULL)  // �ҵ�Ҫɾ���ڵ��ǰһ���ڵ�
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

413. ��ת����
��һ�������е����ֽ��еߵ������ߵ�����������ʱ������ 0 (���Ϊ 32 λ����)�� reverse Integer

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
        while (n != 0)   // n != 0 �����ж�����
        {
            result = 10 * temp + n % 10;
            n = n / 10;
            if (result / 10 != temp)
                return 0;
            temp = result;
        }
        return result;
        */
        
        //3 �ݹ�汾
        return Reverse(0, n);
        
    }
};

//53 ��ת�ַ��� Reverse Words in a String
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

˵��
���ʵĹ��ɣ��޿ո���ĸ����һ������
�����ַ����Ƿ����ǰ������β��ո񣿿��԰��������Ƿ�ת����ַ����ܰ���
��δ����������ʼ�Ķ���ո��ڷ�ת�ַ����м�ո���ٵ�ֻ��һ��
����


�ⷨ1��
����������Ƿ�ת�ַ����еĵ��ʣ���Ŀ�и�������д�ر�˵�����������֮����������ո�ֻ�ܷ���һ����������β�����е��ʣ����Ҷ�C���Գ���ԱҪ��ռ临�Ӷ�ΪO(1)����������ֻ�ܶ�ԭ�ַ���s֮�����޸ģ������������µ��ַ�������ô������η�ת�ַ����еĵ����أ����ǵ������ǣ��������ַ������巭תһ�Σ�Ȼ���ٷֱ�תÿһ�����ʣ������ȷֱ�תÿһ�����ʣ�Ȼ���������ַ������巭תһ�Σ�����ʱ���ܵõ�������Ҫ�Ľ���ˡ���ô����������Ҫ����һЩ�������������ǽ��⣬storeIndex��ʾ��ǰ�洢����λ�ã�nΪ�ַ����ĳ��ȡ������ȸ������ַ�����תһ�£�Ȼ�����ǿ�ʼѭ���������ո�ֱ������������Ƿǿո��ַ������Ǵ�ʱ��storeIndex�Ƿ�Ϊ0��Ϊ0�Ļ���ʾ��һ�����ʣ��������ӿո������Ϊ0��˵�����ǵ�һ�����ʣ���Ҫ�ڵ����м��һ���ո�Ȼ������Ҫ�ҵ���һ�����ʵĽ���λ��������һ��whileѭ��������һ��Ϊ�ո��λ�ã��ڴ˹����м�������ԭ�ַ������ҵ�����λ���ˣ����������ת������ʣ�Ȼ�����iΪ��βλ�ã����������������Ǽ���ԭ�ַ�����storeIndexλ�ã��Ϳ��Եõ�������Ҫ�Ľ�����������£�

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        
        // 1.ԭַ��ת
        
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
                // ����Ҫ�� ���׳��� j - i��ʾ���ʳ���
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        s.resize(storeIndex);
        return s;
       
    }
};

// �ⷨ2 ʹ��istringstream
class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        // ʹ��istringstream
        istringstream istr(s);
        string strTemp;
        istr >> s;   //s�����¸�ֵ��Ϊ��һ���ַ��� istr���Կ�ͷ�ո��ַ����Կո�ָ 
        while (istr >> strTemp)
        {
            s = strTemp + " " + s;
        }
        return s;   
    }
};


53 ��ת�ַ��� rotate String
����һ���ַ�����һ��ƫ����������ƫ������ת�ַ���(����������ת)

����
�����ַ��� "abcdefg".

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
        int i = iStrLength - offset;  // ��ʼ�������±�
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
        int i = iStrLength - offset;  // ��ʼ�������±�
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

60 ��������λ��    Search Insert Position

����һ�����������һ��Ŀ��ֵ��������������ҵ�Ŀ��ֵ�򷵻����������û�У����ص������ᱻ��˳������λ�á�

����Լ��������������ظ�Ԫ�ء�
����
[1,3,5,6]��5 �� 2

[1,3,5,6]��2 �� 1

[1,3,5,6]�� 7 �� 4

[1,3,5,6]��0 �� 0


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

28 ������ά����  Search a 2D Matrix
д��һ����Ч���㷨������ m �� n�����е�ֵ��

�����������������ԣ�

ÿ���е�����������������ġ�
ÿ�еĵ�һ����������һ�е����һ��������

����
�������о���

[
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
���� target = 3������ true


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
        
        //2 ��ά���鿴Ϊһά������ж��ֲ���
        
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


82  �䵥����  Single Number
����2*n + 1 �������֣�������һ������֮������ÿ�����־��������Σ��ҵ�������֡�

����
���� [1,2,2,1,3,4,3]������ 4
��ս 
һ�α������������Ķ���ռ临�Ӷ�


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
        
        //3 �����������е������������Ϊ��ͬ���������������Ϊ0���������õ������־��ǽ����������㽻����
        int ans = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            ans ^= A[i];
        }
        return ans;
    }
};


212  �ո��滻    space replacement
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


141  x��ƽ����  Sqrt(x)

ʵ�� int sqrt(int x) ���������㲢���� x ��ƽ������

������ʵ���������Ƿ�����������⣿ Yes
����
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
        // ���ַ�
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
       // return iRight;  //����iLeft����Ϊʲôһ��Ҫ����iRight
       return iLeft * iLeft - x < iRight * iRight - x ? iLeft : iRight;
    }
};


211 �ַ����û�  string Permutation


���������ַ����������һ���������ж�����һ���ַ����Ƿ�Ϊ��һ���ַ������û���

�û�����˼�ǣ�ͨ���ı�˳�����ʹ�������ַ�����ȡ�

����
"abc" Ϊ "cba" ���û���

"aabc" ���� "abcc" ���û���


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


138. ������֮�� subarraySum


����һ���������飬�ҵ���Ϊ��������顣��Ĵ���Ӧ�÷�������Ҫ������������ʼλ�úͽ���λ��
ע������

There is at least one subarray that it's sum equals to zero.

����

���� [-3, 1, 2, -3, 4]������[0, 2] ���� [1, 3].

����2����˼·��

�����������ǰ׺�ͣ�ͬʱִ�����²�����

�ٶ���ǰλ����i������i֮ǰλ�õ�ǰ׺�ͣ��Ƿ����jλ�ã�ʹ�ã�jλ�õ�ǰ׺�� ���� iλ�õ�ǰ׺�͡�

���У���j �� i ֮����������ĺ�Ϊ0,(i, j],���ұ�

ֱ���������������顣

ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n).


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
        unordered_map<int, int> sum_index_mapping;  // <sum, n>ǰn��Ԫ�صĺ�
        sum_index_mapping[0] = -1;  //�±�Ϊ-1��Ԫ�صĺ�Ϊ0
                                    // ��ֹ��Ϊ����������ôӵ�һ��Ԫ�ؿ�ʼ
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


245. ����
��������ͬ��С�Ķ��������� T1 ���ϰ���Ľڵ㣻 T2 �кü��ٵĽڵ㡣�����һ���㷨���ж� T2 �Ƿ�Ϊ T1��������

 ע������

�� T1 �д��ڴӽڵ� n ��ʼ�������� T2 ��ͬ�����ǳ� T2 �� T1 ��������Ҳ����˵������� T1 �ڵ� n ���������ϣ����ϵĲ��ֽ��� T2 ��ȫ��ͬ��

����
����������� T2 �� T1 ��������

       1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4
����������� T2 ���� T1 ��������

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
        //1 ��α���
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
        
        //2 �ݹ�
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


451 �������������еĽڵ�    Swap Nodes in Pairs

��һ�����������������еĽڵ㣬Ȼ�󷵻ؽ����������

����
���� 1->2->3->4, ��Ӧ�÷��ص������� 2->1->4->3��

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
            current->next = NULL;      // ԭ�����Ϊ��������,һ���ѽ����ã�һ��δ����
            remaining_list_head = temp;
        }
        if (NULL != remaining_list_head) // ʣ������ֻ��һ���ڵ�
        {
            current->next = remaining_list_head;
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

2. β������    Trailing Zeros
���һ���㷨�������n�׳���β����ĸ���

����
11! = 39916800�����Ӧ�÷��� 2

// ����˼·
��ĩβ0�ĸ����� 
����һ�����׳˵�ĩβ�ж��ٸ�0��0�ĸ���Ϊ�����еġ�/����ȡ���������� 
���ӣ�1000�Ľ׳�ĩβ0�ĸ��� 
1000/5 + 1000/25 + 1000/125 + 1000/625 
= 200 + 40 + 8 + 1 
= 249(��)

ԭ���ǣ� 
�������1 �� 2 ������ 4 ��������N��ÿһ�������ֽ���������������� 
1 �� 2 �� 3 �� (2 �� 2) �� 5 �� (2 �� 3) �� 7 �� (2 �� 2 ��2) ������ 
10��������β��ÿһ��0����ʾ��һ������10���ڡ����κν��ƶ�һ��������һ��M���Ƶ������ý�β��һ��0�͵ȼ��ڳ���M�� 
10���Էֽ�Ϊ2 �� 5�������ֻ������2��5����ܲ���0������κ�����������˶����ܲ���0������2��5���ֻ����һ��0�� 
���ԣ��ֽ�����������ʽ���ж��ٶ�(2, 5)������о��ж��ٸ�0�����ֽ�Ľ���У�2�ĸ�����Ȼ�Ƕ���5�ģ���ˣ��ж��ٸ�5�����ж��ٸ�(2, 5)�ԡ� 
���ԣ�����1000�Ľ׳˽�β�м���0�����⣬�ͱ�ת������1��1000������Щ�����������ֽ�ʽ�ж��ٸ�5�����⡣ 
5�ĸ��������������Ǹ�ʽ�����������1000�Ľ׳˽�β��249��0��

����Ϊʲô�����ʽ�ӣ����Լ������� 
��26�Ľ׳˵�β���ж��ٸ�0. 
26�� = 1 �� 2 ������ 4 �� 5 �� 6 �� 7 �� 8 �� 9 �� 10 �� 11 �� 12 �� 13�� 14 �� 15 �� 16 �� 17 �� 18 �� 19 �� 20 �� 21 �� 22 ��2���� 24 �� 25 �� 26 
���� 26/5 + 26/25 = 6������5��� 
��Ϊ25��ʵ���Էֽ��2��5��ˣ���26/5ֻ������һ��5����˻�Ҫ�ټ�26/25.

��5,10,15,20����ֻ��һ��5�����ӣ����count5++�Ϳ����ˣ�������25,50,75������������2��5�����ӣ����count5Ӧ�ü�2������125�Ⱥ�3��5�����ӣ�count5Ӧ�ü�3����ˣ����Բ���������㷨������105�Ľ׳ˣ�1~105��21���ܱ�5����������105/5=21��1~21����4���ܱ�5����������21/5=4��1~4��û�У�count5=21+4+0=25.����1~105������5=5*1,10=5*2��15=5*3,20=5*4,25=5*5,30=5*6...100=5*20,105=5*21��21�������ڴ���21�����������ܼ�����5������25,50,75,100���ĸ���

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        // 1 ��ʱ
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


415 ��Ч���Ĵ�  Valid Palindrome

����һ���ַ������ж����Ƿ�Ϊһ�����Ĵ���ֻ������ĸ�����֣����Դ�Сд��

 ע������

���Ƿ��ǹ����ַ����п����ǿ��ַ������������Թ����У����Թٳ������ʵ����⡣

�������Ŀ�У����ǽ����ַ����ж�Ϊ��Ч���ġ�

"A man, a plan, a canal: Panama" ��һ�����ġ�

"race a car" ����һ�����ġ�


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

406 �ʹ���S����С������   Minimum Size Subarray Sum

����һ���� n ��������ɵ������һ�������� s �����ҳ���������������� �� s ����С���������顣����޽⣬�򷵻� -1��
����
�������� [2,3,1,2,4,3] �� s = 7, ������ [4,3] �Ǹ������µ���С���������顣

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


200. ������Ӵ�   longestPalindrome
����һ���ַ��������賤���Ϊ1000�����������������Ӵ�������Լٶ�ֻ��һ����������������Ĵ���
��ս 
O(n2) ʱ�临�Ӷȵ��㷨�ǿ��Խ��ܵģ���������� O(n) ���㷨����Ȼ���á�

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
            // ��i - 1, iΪ�е��ż�����ȵĻ���
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
            // ��iΪ���ĵ��������ȵĻ���
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



190 ��һ������   next Permutation

����һ���������������У�������������С�����ֵ����С������������һ�����С�

���û����һ�����У�������ֵ�����С�����С�

������ʵ���������Ƿ�����������⣿ Yes
����
�����ԭʼ���У��ұ��Ƕ�Ӧ����һ�����С�

1,2,3 �� 1,3,2

3,2,1 �� 1,2,3

1,1,5 �� 1,5,1

��ս 
������ʹ�ö���Ŀռ䡣


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
        
        //2 �������Ӻ���ǰ�ң��ҵ���һ��(i,j)��ʹ��nums[i]<num[j],Ȼ�����߶һ��󣬺��沿�����򼴿ɡ�
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


109 ����������
����һ�����������Σ��ҵ��Ӷ������ײ�����С·���͡�ÿһ�������ƶ�������һ�е����������ϡ�

 ע������

�����ֻ�ö���ռ临�Ӷ�O(n)����������ɿ��Ի�üӷ֣�����n�����������ε���������

������ʵ���������Ƿ�����������⣿ Yes
����
���磬�����������������Σ�

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
�Ӷ����ײ�����С·����Ϊ11 ( 2 + 3 + 5 + 1 = 11)��


����˼·��
�ʼ�

����1

����buff[i][j]Ϊ����Ԫ��(i,j)��β����С·���͡� 
buff[i][j]Ӧ����buff[i-1][j-1]��buff[i-1][j]�еĽ�Сֵ�ټ��ϵ�ǰ��triangle[i][j]�� 
��״̬ת�Ʒ���Ϊ�� 
buff[i][j] = min(buff[i-1][j-1], buff[i-1][j]) + triangle[i][j] 
��ʼ����Ϊ�� 
buff[0][0] = triangle[0][0]

ע��

�ж�Խ������Ҳ�õ���һ��С���ɣ����˴���ѧ�����ˡ�

//Ҫȡbuff[i-1][j-1]����buff[i-1][j]������Ҫ��֤��Խ�硣
//��i-1�е�j��ȡֵ��ΧΪ[0, i-1]
int lo = max(0, j-1);//��j-1С��0��ʱ��ֻȡ0�����ڵ���0��ʱ��ȡ����
int hi = min(j, i-1);//��j����i-1��ʱ��ֻȡi-1��С�ڵ���i-1��ʱ��ȡ����
1
2
3
4
����2

��ĿҪ���Ż��ռ临�Ӷȡ���ʵ����Ҫ�ö�ά���飬��Ϊÿһ�е�ֵֻ����һ�е�ֵ��أ���˿���ֻ��һ�������漴�ɡ�������2�� 
�������õ��˱��������е�С���ɣ�ÿһ�дӺ���ǰ���£��Է�����ǰ��Ҫʹ�õ�ֵ��

ע��

������Ҫ����ά�ռ��ʡ��һά�ռ��ʱ�򣬶�Ҫ����һ�´Ӻ���ǰ��ǰ������һС���ɡ�


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



158 �����ַ����Ǳ�λ��  anagram

��һ������ anagram(s, t) �ж������ַ����Ƿ����ͨ���ı���ĸ��˳����һ�����ַ�����

������ʵ���������Ƿ�����������⣿ Yes
˵��
What is Anagram?
- Two strings are anagram if they can be the same after change the order of characters.

����
���� s = "abcd"��t="dcab"������ true.
���� s = "ab", t = "ab", ���� true.
���� s = "ab", t = "ac", ���� false.

��ս 
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

56 ����֮��  two Sum


��һ���������飬�ҵ�������ʹ�����ǵĺ͵���һ���������� target��

����Ҫʵ�ֵĺ���twoSum��Ҫ���������������±�, ���ҵ�һ���±�С�ڵڶ����±ꡣע�������±�ķ�Χ�� 1 �� n�������� 0 ��ͷ��

 ע������

����Լ���ֻ��һ��𰸡�

������ʵ���������Ƿ�����������⣿ Yes
����
���� numbers = [2, 7, 11, 15], target = 9, ���� [1, 2].

��ս 
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



517 ����

дһ�����������һ�������ǲ��ǳ�����

�����Ķ����ǣ�ֻ���������� 2, 3, 5 �������������� 6, 8 ���ǳ��������� 14 ���ǳ�����Ϊ�������������� 7��
�Լ���⣺һ�����ֽ��ֻ����2��3,5֮�е���

 ע������

������Ϊ 1 ��һ������ĳ�����

������ʵ���������Ƿ�����������⣿ Yes
����
���� num = 8������ true��
���� num = 14������ false��


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




157 �ж��ַ����Ƿ�û���ظ��ַ�   unique characters

ʵ��һ���㷨ȷ���ַ����е��ַ��Ƿ��Ψһ����

������ʵ���������Ƿ�����������⣿ Yes
����
����"abc"������ true

����"aab"������ false

��ս 
�����ʹ�ö���Ĵ洢�ռ䣬����㷨����θı䣿


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
        
        // 2  ˼����Ҫ
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


114 ��ͬ��·��  uniquePaths
��һ�������˵�λ��һ�� m �� n ���������Ͻǡ�

������ÿһʱ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǡ�

���ж�������ͬ��·����

 ע������

n��m��������100

������ʵ���������Ƿ�����������⣿ Yes
����
���� m = 3 �� n = 3, ���� 6.
���� m = 4 �� n = 5, ���� 35.

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


115 ��ͬ��·�� II   uniquePathsWithObstacles
"��ͬ��·��" �ĸ������⣺

���ڿ������������ϰ�����������ж�������ͬ��·����

�����е��ϰ��Ϳ�λ�÷ֱ��� 1 �� 0 ����ʾ��

 ע������

m �� n ��������100

������ʵ���������Ƿ�����������⣿ Yes
����
������ʾ��3x3����������һ���ϰ��

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
һ����2����ͬ��·�������Ͻǵ����½ǡ�

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


423. ��Ч����������
����һ���ַ�������ʾ���������У����������ַ��� '(', ')', '{', '}', '[' and ']'�� �ж��Ƿ�����Ч���������С�

������ʵ���������Ƿ�����������⣿ Yes
����
���ű������� "()" ˳���ʾ�� "()[]{}" ����Ч�����ţ��� "([)]"������Ч�����š�

����˼·���ǽ���ջ������ݽṹ������⡣
1. ���������ţ�ȫ��ѹ��ջ�У�
2. ���������ţ��ж�ջ����Ԫ���Ƿ������Ӧ�������ţ������򵯳�ջ��Ԫ�أ��������򷵻�false����ջΪ�գ�Ҳ����false��


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


389. �ж������Ƿ�Ϸ�  Valid Sudoku

���ж�һ�������Ƿ���Ч��

����������ֻ����˲������֣�����ȱ�ٵ������� . ��ʾ��

 ע������

һ���Ϸ�����������������䣩����һ���ǿɽ�ġ����ǽ���ʹ���Ŀո���Ч���ɡ�

������ʵ���������Ƿ�����������⣿ Yes
˵��
ʲô�� ������

http://sudoku.com.au/TheRules.aspx
http://baike.baidu.com/subview/961/10842669.htm

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        bool used[9];  // �����±��Ӧ1-9,9�����֣������е�ֵ�����±������Ƿ����
        for (int i = 0; i < 9; i++)
        {
            // �����
            fill(begin(used), end(used), false);
            for (int j = 0; j < 9; j++)
            {
                if (!check(board[i][j], used))
                {
                    return false;
                }
            }
            // �����
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


13 �ַ������� strstr

����һ�������� source �ַ�����һ�� target �ַ�������Ӧ���� source �ַ������ҳ� target �ַ������ֵĵ�һ��λ��(��0��ʼ)����������ڣ��򷵻� -1��

������ʵ���������Ƿ�����������⣿ Yes
˵��
�����������Ƿ���Ҫʵ��KMP�㷨��

����Ҫ�����������������������ʱ�����Թٺܿ���ֻ����Ҫ����һ����Ļ���Ӧ����������Ȼ����Ҫ�ȸ����Թ�ȷ�����Ҫ��ôʵ������⡣
����
��� source = "source" �� target = "target"������ -1��

��� source = "abcdabcdefg" �� target = "bcd"������ 1��

��ս 
O(n2)���㷨�ǿ��Խ��ܵġ����������O(n)���㷨�������Ǹ��Ӻá�����ʾ��KMP��

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


57 ����֮��
����һ����n������������S����S���ҵ���������a, b, c���ҵ�����ʹ��a + b + c = 0����Ԫ�顣

 ע������

����Ԫ��(a, b, c)��Ҫ��a <= b <= c��

������ܰ����ظ�����Ԫ�顣

������ʵ���������Ƿ�����������⣿ Yes
����
��S = {-1 0 1 2 -1 -4}, ����Ҫ���ص���Ԫ�鼯�ϵ��ǣ�

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


59. ��ӽ�������֮��  3Sum Closest 


��һ������ n ������������ S, �ҵ������������ target ��ӽ�����Ԫ�飬�������������ĺ͡�
ע������

ֻ��Ҫ������Ԫ��֮�ͣ����践����Ԫ�鱾��
������ʵ���������Ƿ�����������⣿
����

���� S = [-1, 2, 1, -4] and target = 1. ����ӽ� 1 ����Ԫ���� -1 + 2 + 1 = 2.
��ս

O(n^2) ʱ��, O(1) ����ռ䡣


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


58. ����֮��



��һ������n��������������S����S���ҵ�����ʹ�ú�Ϊ��������target����Ԫ��(a, b, c, d)��
ע������

��Ԫ��(a, b, c, d)�У���Ҫ����a <= b <= c <= d

���в����԰����ظ�����Ԫ�顣
������ʵ���������Ƿ�����������⣿
����

���磬���ڸ�������������S=[1, 0, -1, 0, -2, 2] �� target=0. ����Ҫ�����Ԫ�鼯��Ϊ��

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


171. �����ַ���
����һ���ַ�������S���ҵ��������е������ַ���(Anagram)�����һ���ַ����������ַ�������ô������һ����ĸ������ͬ����˳��ͬ���ַ���Ҳ��S�С�

 ע������

���е��ַ�����ֻ����Сд��ĸ

������ʵ���������Ƿ�����������⣿ Yes
����
�����ַ������� ["lint","intl","inlt","code"]

���� ["lint","inlt","intl"]

��ս 
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


208 ��ֵ���������    Assignment Operator Overloading


ʵ�ָ�ֵ��������غ�����ȷ����

    �µ����ݿ�׼ȷ�ر�����
    �ɵ����ݿ�׼ȷ��ɾ��/�ͷ�
    �ɽ��� A = B = C ��ֵ

������ʵ���������Ƿ�����������⣿
˵��

����ֻ������C++����Ϊ Java �� Python û�жԸ�ֵ����������ػ��ơ�
����

������� A = B ��ֵ���� A �е����ݱ�ɾ����ȡ����֮���� B �е����ݡ�

������� A = B = C ��ֵ���� A �� B �������� C �е����ݡ�
��ս

��ֿ��ǰ�ȫ���⣬��ע���ͷž����ݡ�


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

92. �������� backPack


��n����Ʒ����ѡ������Ʒװ�뱳���������װ���������豳���Ĵ�СΪm��ÿ����Ʒ�Ĵ�СΪA[i]
ע������

�㲻���Խ���Ʒ�����и
������ʵ���������Ƿ�����������⣿
����

�����4����Ʒ[2, 3, 5, 7]

��������Ĵ�СΪ11������ѡ��[2, 3, 5]װ�뱳����������װ��10�Ŀռ䡣

��������Ĵ�СΪ12������ѡ��[2, 3, 7]װ�뱳����������װ��12�Ŀռ䡣

������Ҫ���������װ���Ŀռ��С��
��ս

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
        //1  �ڴ泬������
        
        
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


125 �������� II 


����n����Ʒ�����A[i]�����ֵV[i]��������װ��һ����СΪm�ı����������װ����ܼ�ֵ�ж��
ע������

A[i], V[i], n, m��Ϊ�������㲻�ܽ���Ʒ�����з֡�������ѡ����Ʒ�������ҪС�ڵ��ڸ�����m��
������ʵ���������Ƿ�����������⣿
����

������Ʒ���[2, 3, 5, 7]�Ͷ�Ӧ�ļ�ֵ[1, 5, 2, 4], ���豳����СΪ10�Ļ�������ܹ�װ��ļ�ֵΪ9��
��ս

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
        //dp[i][j]Ϊ��ֵΪ����ֵ, iΪ��i����Ʒ��jΪ��������Ϊj
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


564 �������� VI 
http://www.cnblogs.com/grandyang/p/5743719.html
http://www.cnblogs.com/grandyang/p/5705750.html

 �������� VI

    ����
    �ʼ�
    ����
    ����

����һ������������������ nums������û���ظ������������ҳ����еĺ�Ϊ target ����ϸ�����
ע������

һ��������������г��ֶ�Ρ�
����˳��ͬ��ᱻ��Ϊ�ǲ�ͬ����ϡ�
������ʵ���������Ƿ�����������⣿
����

���� nums = [1, 2, 4], target = 4
���ܵ���������У�

[1, 1, 1, 1]
[1, 1, 2]
[1, 2, 1]
[2, 1, 1]
[2, 2]
[4]

���� 6


��������ת����һ�ֱ������⡣��һ�������ʾn����Ʒÿ������ʾÿ����Ʒ�������� ��Ʒ���ظ�ʹ�á������һ������������w�������ҳ�ǡ��װ�������п����Ե������� �����dp��ʽ�ͺ�numbers combinationһ���ˡ�

������Ҫһ��һά����dp������dp[i]��ʾĿ����Ϊi�Ľ�ĸ�����Ȼ�����Ǵ�1������target������ÿһ����i������nums���飬���i>=x, dp[i] += dp[i - x]�����Ҳ�ܺ���⣬����˵����[1,2,3] 4��������ӣ��������ڼ���dp[3]��ʱ��3���Բ��Ϊ1+x����x��Ϊdp[2]��3Ҳ���Բ��Ϊ2+x����ʱxΪdp[1]��3ͬ�����Բ�Ϊ3+x����ʱxΪdp[0]�����ǰ����е�����������������3�����������

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
        dp[0] = 1;  //targetΪ0ʱ��һ����ϣ�������
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


149 ������Ʊ�����ʱ��
http://www.lintcode.com/zh-cn/problem/best-time-to-buy-and-sell-stock/

    ����
    �ʼ�
    ����
    ����

������һ�����飬���ĵ�i��Ԫ����һ֧�����Ĺ�Ʊ�ڵ�i��ļ۸���������ֻ�������һ�ν���(����,һ��������Ʊ),���һ���㷨���ҳ��������
������ʵ���������Ƿ�����������⣿
����

����һ���������� [3,2,3,1,2], ���� 1 

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        // 1 ��ʱ
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

150  ������Ʊ�����ʱ�� II

    ����
    �ʼ�
    ����
    ����

������һ�����飬���ĵ�i��Ԫ����һ�������Ĺ�Ʊ�ڵ�i��ļ۸����һ���㷨���ҵ����������������ɾ����ܶ�Ľ���(���������Ʊ)��Ȼ��,�㲻��ͬʱ����������(��������ٴι���ǰ���۹�Ʊ)��
������ʵ���������Ƿ�����������⣿
����

����һ����������[2,1,2,0,1], ���� 2

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



151. ������Ʊ�����ʱ�� III 

 ����
 �ʼ�
 ����
 ����
��������һ�����飬���ĵ�i��Ԫ����һ֧�����Ĺ�Ʊ�ڵ�i��ļ۸����һ���㷨���ҵ�����������������������ʽ��ס�

 ע������

�㲻����ͬʱ�����ʽ���(��������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ)

������ʵ���������Ƿ�����������⣿ Yes
����
����һ���������� [4,4,6,1,1,4,2,5], ���� 6

http://blog.csdn.net/dr_unknown/article/details/51939121

��������̬�滮�����Ե�i��Ϊ�ֽ��ߣ������i��֮ ǰ ����һ�ν��׵��������preProfit[i]���͵�i��֮ �� ����һ�ν��׵��������postProfit[i]��������һ�飬max{preProfit[i] + postProfit[i]} (0��i��n-1)����������档��i��֮ǰ�͵�i��֮�����һ�ε����������ͬBest Time to Buy and Sell Stock I��

���룺ʱ��O(n)���ռ�O(n)��

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
        int pre_max_profit[length];  // ��һ�ʽ��׵��������
        int post_max_profit[length];  // �ڶ��ʽ��׵��������
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

69. �������Ĳ�α���  Binary Tree Level Order Traversal


����һ�ö�������������ڵ�ֵ�Ĳ�α��������������ҷ��ʣ�
������ʵ���������Ƿ�����������⣿
����

��һ�ö����� {3,9,20,#,#,15,7} ��

  3
 / \
9  20
  /  \
 15   7

�������ķֲ���������

[
  [3],
  [9,20],
  [15,7]
]

��ս

��ս1��ֻʹ��һ������ȥʵ����

��ս2����DFS�㷨����


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


70 �������Ĳ�α��� II Binary Tree Level Order Traversal II


����һ�ö�������������ڵ�ֵ�ӵ����ϵĲ�������������Ҷ�ڵ����ڲ㵽���ڵ����ڵĲ������Ȼ�����������ұ�����
������ʵ���������Ƿ�����������⣿
����

����һ�ö����� {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

���մ������ϵĲ�α���Ϊ��

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


94 �������е����·����  Binary Tree Maximum Path Sum


����һ�ö�������Ѱ��һ��·��ʹ��·�������·����������һ�ڵ��п�ʼ�ͽ�����·����Ϊ�����ڵ�֮������·���ϵĽڵ�Ȩֵ֮�ͣ�
������ʵ���������Ƿ�����������⣿
����

����һ�ö�������

       1
      / \
     2   3

���� 6



˼·��
������ÿ���·�����϶�����ĳ������Ϊ����Ȼ�����������Ǹ��ڵ�Ϊ����Ҷ�ӽڵ���·��
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
    
    // ���شӵ�ǰ�ڵ㵽Ҷ�ӽڵ�����·����
    
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

394 Ӳ���ų��� coins-in-a-line



�� n ��Ӳ���ų�һ���ߡ������������������ұ��������� 1 �� 2 ��Ӳ�ң�ֱ��û��Ӳ��Ϊֹ���õ����һöӲ�ҵ��˻�ʤ��

���ж� ��һ����� ���仹��Ӯ��
������ʵ���������Ƿ�����������⣿
����

n = 1, ���� true.

n = 2, ���� true.

n = 3, ���� false.

n = 4, ���� true.

n = 5, ���� true.
��ս

O(1) ʱ�临�Ӷ���O(1) �洢��

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
        win_lose[0] = false;  // 0��Ӳ�ң���
        win_lose[1] = true;   // 1��Ӳ�ң�Ӯ
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


512 ���뷽�� Decode Ways


��һ����Ϣ����A-Zͨ�����¹������

'A' -> 1
'B' -> 2
...
'Z' -> 26

���ڸ���һ�����ܹ������Ϣ�����м��ֽ���ķ�ʽ
������ʵ���������Ƿ�����������⣿
����

�������ϢΪ12�������ַ�ʽ���� AB(12) ���� L(12). ���Է��� 2

http://www.cnblogs.com/grandyang/p/4313384.html
http://www.jiuzhang.com/solution/decode-ways/

����쳲���������
dp[s.size()]
���s[i] Ϊ��0�������޷����룬dp[i] = 0, ���� dp[i] = dp[i - 1]
��������dp[i]
��s[i - 1] �� s[i]���ɵ����ֿ��Խ��룬��dp[i] �ټ���dp[i - 2],����
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



118  ��ͬ��������

�����ַ���S���ַ���T������S�Ĳ�ͬ����������T���ֵĸ�����

�������ַ�����ԭʼ�ַ���ͨ��ɾ��һЩ(�����)������һ���µ��ַ��������Ҷ�ʣ�µ��ַ������λ��û��Ӱ�졣(���磬��ACE���ǡ�ABCDE�����������ַ���,����AEC������)�� 
������ʵ���������Ƿ�����������⣿
����

����S = "rabbbit", T = "rabbit"

���� 3
��ս

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
        // dp[S.size()][T.size()], S�У�ǰi���ַ���ת��ΪT�У�ǰj���ַ��ķ�������
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


77 ����������� longestCommonSubsequence
���������ַ������ҵ������������(LCS)������LCS�ĳ��ȡ�

 ˵��

����������еĶ��壺

    �������������������һ�����У�ͨ��2�������ҵ�����������У�ע�⣺��ͬ���Ӵ���LCS����Ҫ���������Ӵ������������ǵ��͵ļ������ѧ���⣬���ļ�����Ƚϳ���Ļ�������������Ϣѧ��Ҳ����Ӧ�á�
    https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

����

����"ABCD" �� "EDCA"�����LCS�� "A" (�� D��C)������1

���� "ABCD" �� "EACB"�����LCS��"AC"���� 2


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

76 �����������

����һ���������У��ҵ�����������У�LIS��������LIS�ĳ��ȡ�
������ʵ���������Ƿ�����������⣿
˵��

����������еĶ��壺

�������������������һ������ĸ����������ҵ�һ�������ܳ����ɵ͵������е������У����������в�һ���������Ļ���Ψһ�ġ�
https://en.wikipedia.org/wiki/Longest_increasing_subsequence
����

���� [5,4,1,2,3]��LIS �� [1,2,3]������ 3
���� [4,2,4,5,3,7]��LIS �� [2,4,5,7]������ 4

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



135  �������

����һ���ѡ����(C)��Ŀ������(T),�ҵ�C�����е���ϣ�ʹ�ҳ������ֺ�ΪT��C�е����ֿ����������ظ���ѡȡ��

����,������ѡ����[2,3,6,7]��Ŀ������7������Ľ�Ϊ��

[7]��

[2,2,3]
ע������

    ���е�����(����Ŀ������)��Ϊ��������
    Ԫ�����(a1, a2, �� , ak)�����Ƿǽ���(ie, a1 �� a2 �� �� �� ak)��
    �⼯���ܰ����ظ�����ϡ� 

������ʵ���������Ƿ�����������⣿
����

������ѡ����[2,3,6,7]��Ŀ������7

���� [[7],[2,2,3]]

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
