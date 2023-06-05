//alie
//#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
#include<queue>
#include <cmath> 
#include <string>
#include<cstring>
template <class T >
class BinaryTree
{
	class node{
			public :
				T item ;
				node * left ;
				node* right ;
				node * parent ;
		};
		node * root ;
		int num ;
	
	public:
		
		BinaryTree()
		{
		//	root->left = NULL ;
		//	root->right = NULL ;
		//	root->parent = NULL ;
			root = NULL ;
		//	root->order =1 ;
			num = 0 ;
		}
		bool isEmpty()
		{
			return root== NULL ;
		}
		
		void inOrderALL()
		{
			inOrder(root) ;
		}
		void inOrder(node * N)
		{
			if (N != NULL )
			{
				inOrder(N->left) ;
				cout << N->item << "   " ; 
				inOrder(N->right) ; 
			}
		}
		
		void insert(T element )
		{
			node * newN = new node ;
			newN->item = element ;
			newN->left = NULL ;
			newN->right =NULL ;
			newN->parent =NULL ;
		//	newN->oredr = 1 ;
			
			if (root == NULL )
			{
				root=newN  ;
			}
			else 
			{
				
				node  *p =root , * prev  = root ;
				while (p!=NULL)
				{
					prev = p ;
					if (element <= p->item)
					{
					//	p->order ++ ;
						p = p->left ;	
					}
					else 
					{
						p=p->right ;
					}
				}
				if (element <= prev->item )
				{
					newN->parent = prev ;
					prev->left = newN ;	
				}
				else 
				{
					newN->parent = prev ;
					prev->right = newN ;	
				}
				
			}
			num ++ ;
			
		}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
		int get_LessThanValues(int key )
		{
			int count = 0 ;
			innerget_LessThanValues( root , count , key );
		}
		int innerget_LessThanValues(node * ptr , int &count , int key )
		{
			if (count > key)
				return 0 ;
			if (ptr ==NULL)
				return 0 ;
			
			int result = innerget_LessThanValues(ptr->left , count , key ) ;
			if (count>=key)
				return result ;	
			
			result += ptr->item ;
			count ++ ;
			
			if (count >= key )
				return result ; 
			
			return result + innerget_LessThanValues(ptr->right , count , key ) ;
				
		}
		
};

int main()
{
//	ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;
	
	BinaryTree<int> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    cout << a.get_LessThanValues(3)  << " \n this case is in assignment enter more test cases \n"  ; 
    // 52+51+49 =152
    
    BinaryTree<int> b;
    b.insert(25);
    b.insert(20);
    b.insert(30);
    b.insert(35);
    b.insert(33);
    b.insert(22);
    cout << b.get_LessThanValues(2)  << " \n second  test case \n"   ; 
    // 20+22 =42 
    
    BinaryTree<int> c;
    c.insert(100);
    c.insert(120);
    c.insert(130);
    c.insert(110);
    c.insert(75);
    c.insert(81);
    cout << c.get_LessThanValues(3)  <<" \n third  test case \n"  ; 
    // 75+81+100 = 265 
    BinaryTree<int> d;
    d.insert(50);
    d.insert(55);
    d.insert(45);
    d.insert(40);
    d.insert(60);
    d.insert(70);
    cout << d.get_LessThanValues(4)  << " \n forth  test case \n"  ;
    // 40+45+50+55= 190
    
    BinaryTree<int> e;
    e.insert(7);
    e.insert(8);
    e.insert(6);
    e.insert(5);
    e.insert(10);
    e.insert(1);
    cout << e.get_LessThanValues(3)  <<"\n fifth  test case \n" ;
    // 1+5+6 = 12 
    
	return 0 ;
}


/*
//////////////////////////////////////////// another 4 test cases and elements from user     
	int t = 4 ;
	int num ;
	while (t--)
	{
		cout << "\n ___________________________________________________\n " ;
		cout << " enter size  for number of elements \n " ;
		int size ; cin >> size ;
		BinaryTree<int> B;
		for (int i=0 ; i< size ; i++ )
		{
			cout << " enter element \n " ;
			cin >> num ; 
		    B.insert(num);
		}
		cout << "\n enter smallest num  \n " ;
	    int k ;  cin >> k ;
	    cout << B.get_LessThanValues(k) ;
	}

	return 0;
}





/*
	BinaryTree<int> b;
	cout << "\n ____________________________________ \n  enter element \n " ;
	cin >> n ; 
    b.insert(n);
    cout << " enter element \n " ;
	cin >> n ; 
    b.insert(n);
    cout << " enter element \n " ;
	cin >> n ; 
    b.insert(n);
    cout << " enter element \n " ;
	cin >> n ; 
    b.insert(n);
    cout << " enter element \n " ;
	cin >> n ; 
    b.insert(n);
    
    cout << "\n enter key \n " ;
    int k ;  cin >> k ;
    cout << b.get_LessThanValues(k) ;
	}
*/
