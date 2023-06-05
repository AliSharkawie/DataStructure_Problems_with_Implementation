#include <iostream>
#include<string>
#include <stack>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : data('0'), left(nullptr), right(nullptr) {}
    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(char x, TreeNode *left, TreeNode *right) : data(x), left(left),right(right) {}

};

class Tree{
private:

    TreeNode* root;
public:
    void generateTree(string exp)
    {
        stack<TreeNode*>stk;
        for(int i = exp.size()-1; i>=0 ;i--){

            if(!isdigit(exp[i]))
            {

                TreeNode* leftNode = stk.top();
                stk.pop();
                TreeNode* rigthNode =stk.top();
                stk.pop();

                TreeNode* newnode = new TreeNode(exp[i],leftNode,rigthNode);
                stk.push(newnode);

            }
            else
            {
                TreeNode* newnode = new TreeNode(exp[i]);
                stk.push(newnode);
            }

        }
        root = stk.top();
        stk.pop();
    }

     TreeNode* get_root(){
        return root;
    }



};
string Prefix;
string get_prefix(TreeNode* root)
{
    Prefix += (root->data);

    if (root->left)
        get_prefix(root->left);

    if (root->right)
        get_prefix(root->right);

    return Prefix;


}



int evaluatePrefix(string exp)
{
    stack<int> Stack;

    for (int i = exp.size() - 1; i >= 0; i--) {

        // To convert exp[i] to digit subtract '0' from exp[i]
        if (isdigit(exp[i]))
            Stack.push(exp[i] - '0');

        else {

            double left = Stack.top();
            Stack.pop();
            double right = Stack.top();
            Stack.pop();

            switch (exp[i]) {
                case '+':
                    Stack.push(left + right);
                    break;
                case '-':
                    Stack.push(left - right);
                    break;
                case '*':
                    Stack.push(left * right);
                    break;
                case '/':
                    Stack.push(left / right);
                    break;
            }
        }
    }
    Prefix = "";  // to make it empty for the next time
    return Stack.top();

}

void print(){
    cout << "\n";
    for(int i=0; i <10 ; i++)
        cout << "-";
}



int main()
{
    double result;
    string prefix;


    Tree t1;
    t1.generateTree("+3*4/82");

    prefix = get_prefix(t1.get_root());
    result = evaluatePrefix(prefix);
    cout << result;
    print();




    Tree t2;
    t2.generateTree("/82");

    prefix = get_prefix(t2.get_root());
    result = evaluatePrefix(prefix);

    cout << "\n" << result;
    print();




    Tree t3;
    t3.generateTree("+4/84");

    prefix = get_prefix(t3.get_root());
    result = evaluatePrefix(prefix);

    cout << "\n"<< result;
    print();





    Tree t4;
    t4.generateTree("*44");

    prefix = get_prefix(t4.get_root());
    result = evaluatePrefix(prefix);

    cout << "\n"<< result;
    print();




    Tree t5;
    t5.generateTree("-5*4/42");

    prefix = get_prefix(t5.get_root());
    result = evaluatePrefix(prefix);

    cout << "\n"<< result;



    return 0;
}

