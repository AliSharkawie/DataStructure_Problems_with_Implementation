#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//function that search for the index of a tree/subtree root in the inOrder string "array of chars"
int elemSearch(char inOrder[], char root, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(inOrder[i] == root) //if found the element "character"
            return i;  //returns the element index in the inOrder
    }
    return -1;
}


void postOrderFun(char inOrder[], char preOrder[], int s)
{
    int rootIndex = elemSearch(inOrder, preOrder[0], s); //to get inOrder index of the tree root

    if(rootIndex != 0)
        postOrderFun(inOrder, preOrder + 1, rootIndex); //recursive for the left subtree if it's not empty

    if(rootIndex != s - 1)  //recursive for the right subtree if it's not empty
        postOrderFun(inOrder + rootIndex + 1, preOrder + rootIndex + 1, s - rootIndex - 1);

    cout << preOrder[0] ;
}


void printPostOrder(string preorder, string inorder)
{
    int len = inorder.length();  //get size of the tree we have
    char pre[len + 1]; //array of chars to store the preOrder
    char in[len + 1];

    strcpy(pre, preorder.c_str()); //convert the string preOrder to array of chars
    strcpy(in, inorder.c_str()); //convert the string inOrder to array of chars

    postOrderFun(in, pre, len);

}

int main()
{
    //1st test case
    cout << "The postOrder of the 1st test case: " << endl;
    printPostOrder("ABFGC", "FBGAC");  //expected: FGBCA
    cout << endl << endl;

    //2nd test case
    cout << "The postOrder of the 2nd test case: " << endl;
    printPostOrder("CDFJE", "FDJCE");  //expected: FJDEC
    cout << endl << endl;

    //3rd test case
    cout << "The postOrder of the 3rd test case: " << endl;
    printPostOrder("HSMYZA", "MSHZYA"); //expected: MSZAYH
    cout << endl << endl;

    //4th test case
    cout << "The postOrder of the 4th test case: " << endl;
    printPostOrder("DABXC", "ABDXC"); //expected: BACXD
    cout << endl << endl;

    //5th test case
    cout << "The postOrder of the 5th test case: " << endl;
    printPostOrder("BNMAOC", "MNABCO"); //expected: MANCOB
    cout << endl;

    return 0;
}