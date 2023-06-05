#include <iostream>
using namespace std ;


struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
                                                       right(right) {}
};

class  Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;

        if (!p && q || p && !q || p->data != q->data)
            return false;


        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main (){

    //Input:p = [1,2,3], q = [1,2,3]
    //Output: true

    Solution s;

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);


    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);


    if (s.isSameTree(p,q))
        cout << "The Trees are the same";
    else
        cout << "The Trees are not the same";


    //Input: p = [1,2,1], q = [1,1,2]
   //Output: false

    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(1);


    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(1);
    q1->right = new TreeNode(2);

    if (s.isSameTree(p1,q1))
        cout << "\nThe Trees are the same";
    else
        cout << "\nThe Trees are not the same";



    // Input: p = [1,2], q = [1,null,2]
    //Output: false

    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    if (s.isSameTree(p2,q2))
        cout << "\nThe Trees are the same";
    else
        cout << "\nThe Trees are not the same";




    return 0;


}