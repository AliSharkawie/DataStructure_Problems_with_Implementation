//alie
//#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
#include<queue>
#include <cmath> 
#include <string>
#include<cstring>
template <class T >
class BSTFCI
{
	class BSTNode{
			public :
				T item ;
				BSTNode * left ;
				BSTNode* right ;
				BSTNode * parent ;
		};
		BSTNode * root ;
		int num ;
	
	public:
		
		BSTFCI ()
		{
		//	root->left = NULL ;
		//	root->right = NULL ;
		//	root->parent = NULL ;
			root = NULL ;
			num = 0 ;
		}
		bool isEmpty()
		{
			return root== NULL ;
		}
		BSTNode* getroot()
		{
			return root ;
		}
		void preOrderALL()
		{
			preOrder(root) ;
		}
		void postOrderALL()
		{
			postOrder(root) ;
		}
		void inOrderALL()
		{
			inOrder(root) ;
		}
		void preOrder(BSTNode * N)
		{
			if (N != NULL )
			{
				cout << N->item << "   " ; 
				preOrder(N->left) ;
				preOrder(N->right) ; 
			}
		}
		void inOrder(BSTNode * N)
		{
			if (N != NULL )
			{
				inOrder(N->left) ;
				cout << N->item << "   " ; 
				inOrder(N->right) ; 
			}
		}
		void postOrder(BSTNode * N)
		{
			if (N != NULL )
			{
				postOrder(N->left) ;
				postOrder(N->right) ;
				cout << N->item << "   " ;  
			}
		}
		
		void breadthOreder(BSTNode *ptr) // for all tree make ptr = root 
		{
			if (ptr==NULL)
				return ;
				
			queue<BSTNode*> Q ;
			Q.push_back(ptr) ;
			
			while (!Q.empty())
			{
				BSTNode * curr = Q.front ;
				cout << curr->item << " " ;
				if (curr->left!=NULL)
					Q.push_back(curr->left) ;
				if (curr->right!=NULL)
					Q.push_back(curr->right) ;
				Q.popfront() ;	
			}	
		}
		void clear (BSTNode * & p) //node * & p
		{
			if(p!=NULL)
			{
				clear(p->left);
				clear(p->right) ;
				delete p ;
				p=0 ;
			} 
		}
		void clearAll()
		{
			clear(root) ;
		}
		
		void insert(T element )
		{
			BSTNode * newN = new BSTNode ;
			newN->item = element ;
			newN->left = NULL ;
			newN->right =NULL ;
			newN->parent =NULL ;
			
			if (root == NULL )
			{
				root=newN  ;
			}
			else 
			{
				
				BSTNode  *p =root , * prev  = root ;
				while (p!=NULL)
				{
					prev = p ;
					if (element <= p->item)
						p = p->left ;
					else 
						p=p->right ;
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
		
		int height(BSTNode * p)
		{
			if (p==NULL)
				return 0 ;
			else 
			{
				return 1+ max(height(p->left) ,height(p->right)) ;
			}
		}
		int max(T x , T y)
		{
			if (x>=y)
				return x ;
			else 
				return y ;
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// our functions from here 
		bool inner_isBalance(BSTNode * ptr)
		{
			if(ptr==NULL)
				return 1 ;
				
			if(abs(height(ptr->left)-height(ptr->right))<=1 && inner_isBalance(ptr->left) && inner_isBalance(ptr->right) )
				return 1 ;
				
			return 0 ;
			
		}
		bool isBalance()
		{
			return inner_isBalance(root) ;
		}
		
		bool isSubTree(BSTFCI tree1 , BSTFCI tree2 ) 
		{
			BSTNode* t1 , * t2 ;
			t1 = tree1.getroot() ;
			t2 = tree2.getroot() ;
			return isSubTree1(t1,t2) ;
		}
//________________________________________________________________________________________________________________________________________//					
		bool isSubTree1(BSTNode* t1 , BSTNode* t2 ) 
		{
		/*	if (t1==NULL && t2 == NULL)
				return 1 ;
		*/	if (t1==NULL && t2 != NULL)
				return 0 ;
			if (t2==NULL && t1 != NULL)
				return 1 ;
			
			if(inner_isSubTree(t1,t2))
				return true ;
			
			if(isSubTree1(t1->left , t2) || isSubTree1(t1->left , t2) )   // t1->right 
				return true ;
			else 
				return false ;			
		}
		bool inner_isSubTree(BSTNode* t1, BSTNode* t2)
		{
			if (t1 == NULL && t2==NULL)
				return true ;
			if (t1==NULL)
				return false ;
			if (t2==NULL) 
				return false ;
				
			if(t1->item==t2->item && inner_isSubTree(t1->left , t2->left) && inner_isSubTree(t1->right , t2->right))
				return true ;
			else 
				return false ;
		}
//________________________________________________________________________________________________________________________________________//				
		void printRange (T x , T y) 
		{
			inner_printRange(root , x , y) ;
		}
		void inner_printRange(BSTNode * N , int x , int y)
		{
			if(N==NULL)
				return ;
			
			if (N->item > x )
				inner_printRange(N->left ,x,y) ;
			
			if (N->item>=x && N->item <=y )
				cout << N->item <<" " ;
			
			if (N->item < y)
				inner_printRange(N->right ,x,y) ;
			
//			cout << " " ;
		}
		
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// search for me in my tree rakkz ya ali 
		T* search(T element ) 
		{
			BSTNode * curr = root ;
			while (curr!=NULL)
			{
				if (curr->item == element )
					return curr ;
				else if (curr->item > element )
					curr = curr->left ;
				else 
					curr = curr->right ;
			}	
			return NULL  ;
		}
		T search_Main(T element) // search in main by element 
		{
			BSTNode * curr = root ;
			while (curr!=NULL)
			{
				if (curr->item == element )
					return curr->item ;
				else if (curr->item > element )
					curr = curr->left ;
				else 
					curr = curr->right ;
			}	
		//	cout << "not found \n " ;
			return -1  ;
		}
		 void deleteNode(T & element )
		{
			BSTNode * ptr = search(element) ;
			if (ptr==NULL)
				return ;
			if (ptr->left == NULL && ptr->right==NULL)
				{
					delete ptr ;
					ptr =0 ;
				}
			else if (ptr->left == NULL || ptr->right==NULL) // 1 child  --> link parent our node with it's child
				{
					BSTNode * curr = ptr ;
					if (curr->parent->left == curr )
						{
							if (curr->right ==NULL)
							{
								curr->parent->left = curr->left  ;
								delete ptr ; 
								ptr= 0 ;
							}
							else 
							{
								curr->parent->left = curr->right  ;
								delete ptr ; 
								ptr= 0 ;
							}
						}
					
					else if (curr->parent->right == curr )
						{
							if ( curr->left ==NULL )
							{
								curr->parent->right = curr->right ;
								delete ptr ; 
								ptr= 0 ;
							}
							else 
							{
								curr->parent->left = curr->left  ;
								delete ptr ; 
								ptr= 0 ;
							}
							
						}
						else {
						}
				}
				
				else  // tow child  //  error here !!!!?
				{
					BSTNode * successor = min(ptr->right) ; // max lefr is the predecessor 
					ptr = successor ;
					delete successor ;
					successor = 0 ;
				}
		num-- ;
		}
		
		BSTNode* min (BSTNode *NODE)
		{
			BSTNode * prev , *p = NODE;
			while (p!= NULL)
				{
					prev = p ; 
					p=p->left ;
				}
			return prev ;	
		}
		BSTNode* max (BSTNode *NODE)
		{
			BSTNode * prev , *p = NODE;
			while (p!= NULL)
				{
					prev = p ; 
					p=p->right  ;
				}
			return prev ;	
		}		
};

//#################################################################################################################//
int main()
{
	ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;

	BSTFCI<int> a;   
    a.insert(20);
    a.insert(10);
    a.insert(7);
    a.insert(6);
    a.insert(3);
    a.insert(2);
    BSTFCI<int> a2;
    a2.insert(20);
    a2.insert(10);
    a2.insert(7);
    a2.insert(6);
    a2.insert(3);
    a2.insert(2);
    if (a.isBalance()) // it work great ya alie 
    	cout << " yes balanced \n\n ";
    else 
    	cout << " not balanced \n\n " ;
    
	if (a.isSubTree(a,a2))
		cout << " tree1 is sub tree from tree2 \n\n ";
	else 
		cout << " tree1 isn't sub tree \n \n ";	
    
    cout << " the result of ptint range  function \t " ;
	a.printRange(2,5) ;
	cout << "\n____________________________________________________________\n  " ;
	cout << "########################################################### " ;
	cout << "\n____________________________________________________________\n \n " ;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//		
	
	
	
	BSTFCI<int> b;   
    b.insert(50);
    b.insert(40);
    b.insert(60);
    b.insert(30);
    b.insert(35);
    b.insert(70);
    b.insert(65);
    b.insert(55);
    b.insert(45);
    BSTFCI<int> b2;
    b2.insert(20);
    b2.insert(10);
    b2.insert(7);
    b2.insert(6);
    b2.insert(3);
    b2.insert(2);
    if (b.isBalance()) // it work great ya alie 
    	cout << " yes balanced \n\n ";
    else 
    	cout << " not balanced \n\n " ;
    
	if (b.isSubTree(b,b2))
		cout << " tree1 is sub tree from tree2 \n\n ";
	else 
		cout << " tree1 isn't sub tree \n \n ";	
    
    cout << " the result of ptint range  function \t " ;
	b.printRange(30,50) ;
	cout << "\n____________________________________________________________\n  " ;
	cout << "########################################################### " ;
	cout << "\n____________________________________________________________\n \n " ;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//	


	BSTFCI<int> c;   
    c.insert(50);
    c.insert(60);
    c.insert(30);
    c.insert(40);
    c.insert(20);
    BSTFCI<int> c2;
    c.insert(30);
    c.insert(40);
    c.insert(20);
    if (c.isBalance()) // it work great ya alie 
    	cout << " yes balanced \n\n ";
    else 
    	cout << " not balanced \n\n " ;
    
	if (c.isSubTree(c,c2))
		cout << " tree1 is sub tree from tree2 \n\n ";
	else 
		cout << " tree1 isn't sub tree \n \n ";	
    
    cout << " the result of ptint range  function \t " ;
	c.printRange(20,40) ;
	cout << "\n____________________________________________________________\n  " ;
	cout << "########################################################### " ;
	cout << "\n____________________________________________________________\n \n " ;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//	


	
	BSTFCI<int> d;   
    d.insert(100);
    d.insert(10);
    d.insert(7);
    d.insert(120);
    d.insert(30);
    d.insert(9);
    d.insert(130);
    BSTFCI<int> d2;
    d2.insert(45);
    d2.insert(12);
    d2.insert(60);
    d2.insert(25);
    if (d.isBalance()) // it work great ya alie 
    	cout << " yes balanced \n\n ";
    else 
    	cout << " not balanced \n\n " ;
    
	if (d.isSubTree(d,d2))
		cout << " tree1 is sub tree from tree2 \n\n ";
	else 
		cout << " tree1 isn't sub tree \n \n ";	
    
    cout << " the result of ptint range  function \t " ;
	d.printRange(12,13) ;
	cout << "\n____________________________________________________________\n  " ;
	cout << "########################################################### " ;
	cout << "\n____________________________________________________________\n \n " ;	
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$//		



	BSTFCI<int> e;   
    e.insert(5);
    e.insert(10);
    e.insert(3);
    BSTFCI<int> e2;
    e2.insert(20);
    e2.insert(10);
    e2.insert(7);
    e2.insert(6);
    e2.insert(3);
    e2.insert(2);
    if (e.isBalance()) // it work great ya alie 
    	cout << " yes balanced \n\n ";
    else 
    	cout << " not balanced \n\n " ;
    
	if (e.isSubTree(e,e2))
		cout << " tree1 is sub tree from tree2 \n\n ";
	else 
		cout << " tree1 isn't sub tree \n \n ";	
    
    cout << " the result of ptint range  function \t " ;
	e.printRange(12,13) ;
	cout << "\n____________________________________________________________\n  " ;
	cout << "########################################################### " ;
	cout << "\n____________________________________________________________\n \n " ;

    
//	b.inOrderALL() ;
	cout << "\n" ;

}


