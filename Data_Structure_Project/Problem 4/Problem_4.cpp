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

class BinaryTree {
private:
    TreeNode* Root;
public:
    bool is_mirror(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;

        if (!left && right || left && !right || left->data != right->data)
            return false;


        return is_mirror(left->left, right->right) && is_mirror(left->right, right->left);
    }

    bool is_Symmetric(TreeNode* root) {
        Root = root;
        return is_mirror(Root->left, Root->right);

    }
};


int main (){


    BinaryTree T1;

    TreeNode* root = new TreeNode(1);   // -------[1,2,2,3,4,4,3]------->Symmetric
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (T1.is_Symmetric(root))
        cout << "The Tree is Symmetric";
    else
        cout << "The Tree is Not Symmetric";



    BinaryTree T2;

    TreeNode* root2 = new TreeNode(1);  // -------[1,2,2,null,3,null,3]------->Not Symmetric
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(NULL);
    root2->left->right = new TreeNode(3);
    root2->right->left = new TreeNode(NULL);
    root2->right->right = new TreeNode(3);

    if (T2.is_Symmetric(root2))
        cout << "\nThe Tree is Symmetric";
    else
        cout << "\nThe Tree is Not Symmetric";



    return 0;


}