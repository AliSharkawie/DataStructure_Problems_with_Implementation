#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;
};

Node* createNode(int element)
{
    Node* node = new Node();
    node->data = element;
    node->right = nullptr;
    node->left = nullptr;
    return node;
}

//flipping the tree from any node
void flip(Node* p)
{
    if(p == nullptr)
        return;

    else
    {
        Node* temp; //pointer to store the left pointer
        flip(p->left); //recursive to invert all left subtrees
        flip(p->right); //recursive to invert all right subtrees

        temp = p->left;
        p->left = p->right;
        p->right = temp;
    }
}



////print in order
void printInOrder(Node* p) //prints: left-> value -> right
{
    if(p != nullptr)
    {
        printInOrder(p->left);
        cout << p->data << " ";
        printInOrder(p->right);
    }
}



int main() {
    //creating a tree .. 1st test case
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);


    cout << "The tree of the 1st case inOrder: " << endl; //expected: 4 2 5 1 3
    printInOrder(root);
    flip(root);
    cout << endl;
    cout << "The flipped tree inOrder: " << endl; //expected: 3 1 5 2 4
    printInOrder(root);
    cout << endl << endl << endl;


    //2nd test case
    Node *p = createNode(10);
    p->left = createNode(9);
    p->right = createNode(15);
    p->left->left = createNode(14);
    p->right->left = createNode(3);


    cout << "The tree of the 2nd case inOrder: " << endl; //expected: 14 9 10 3 15
    printInOrder(p);
    flip(p);
    cout << endl;
    cout << "The flipped tree inOrder: " << endl; //expected: 15 3 10 9 14
    printInOrder(p);
    cout << endl << endl << endl;


    //3rd test case
    Node *node = createNode(5);
    node->left = createNode(9);
    node->right = createNode(8);
    node->left->left = createNode(2);
    node->left->right = createNode(6);
    node->right->left = createNode(3);


    cout << "The tree of the 3rd case inOrder: " << endl; //expected: 2 9 6 5 3 8
    printInOrder(node);
    flip(node->left);  //start flipping from the 1st left child
    cout << endl;
    cout << "The flipped tree inOrder: " << endl; //expected: 6 9 2 5 3 8
    printInOrder(node);
    cout << endl << endl << endl;


    //4th test case
    Node *n = createNode(2);
    n->left = createNode(5);
    n->right = createNode(8);
    n->left->left = createNode(10);
    n->right->right = createNode(3);
    n->right->left = createNode(11);
    n->right->left->left = createNode(12);
    n->right->left->right = createNode(7);


    cout << "The tree of the 4th case inOrder: " << endl; //expected: 10 5 2 12 11 7 8 3
    printInOrder(n);
    flip(n->right->left);  //start flipping from the 1st left child from the right
    cout << endl;
    cout << "The flipped tree inOrder: " << endl; //expected: 10 5 2 7 11 12 8 3
    printInOrder(n);
    cout << endl << endl << endl;


    //5th test case
    Node *np = createNode(12);
    np->right = createNode(1);
    np->left = createNode(5);
    np->left->right = createNode(11);
    np->left->right->left = createNode(2);
    np->left->right->right = createNode(30);
    np->left->right->right->left = createNode(10);



    cout << "The tree of the 5th case inOrder: " << endl; //expected: 5 2 11 10 30 12 1
    printInOrder(np);
    flip(np->left->right);  //start flipping from the 1st right child from the left
    cout << endl;
    cout << "The flipped tree inOrder: " << endl; //expected: 5 30 10 11 2 12 1
    printInOrder(np);
    cout << endl << endl << endl;
    return 0;

}