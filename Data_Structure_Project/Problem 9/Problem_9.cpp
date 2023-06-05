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

        if (!left && right || left && !right )
            return false;

        return is_mirror(left->left, right->right) && is_mirror(left->right, right->left);
    }

    bool is_Foldable(TreeNode* root) {
        Root = root;
        if (root == NULL) {    // if the tree is empty
            return true;
        }
        return is_mirror(Root->left, Root->right);

    }

};


int main (){


    BinaryTree T1;

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(5);

    if (T1.is_Foldable(root1))
        cout << "The Tree is Foldable";
    else
        cout << "The Tree is Not Foldable";



    BinaryTree T2;

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(3);

    if (T2.is_Foldable(root2))
        cout << "\nThe Tree is Foldable";
    else
        cout << "\nThe Tree is Not Foldable";




    BinaryTree T3;  //--------empty tree
    TreeNode* root3 = new TreeNode(NULL);

    if (T3.is_Foldable(root3))
        cout << "\nThe Tree is Foldable";
    else
        cout << "\nThe Tree is Not Foldable";


    BinaryTree T4;

    TreeNode* root4 = new TreeNode(1);
    root4->left = new TreeNode(2);
    root4->right = new TreeNode(3);
    root4->left->left = new TreeNode(4);
    root4->left->right = new TreeNode(6);
    root4->right->right = new TreeNode(5);

    if (T4.is_Foldable(root4))
        cout << "\nThe Tree is Foldable";
    else
        cout << "\nThe Tree is Not Foldable";



    BinaryTree T5;

    TreeNode* root5 = new TreeNode(1);
    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);
    root5->left->right = new TreeNode(6);
    root5->right->left = new TreeNode(5);

    if (T5.is_Foldable(root5))
        cout << "\nThe Tree is Foldable";
    else
        cout << "\nThe Tree is Not Foldable";


    return 0;


}