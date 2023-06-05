//alie
#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
#include <cmath> 
#include <string>
#include<cstring>
#include <cassert>

template <class T>
class linked_Queue
{
	struct node {
		T item ;
		node * next ;
	};
	node *front ,*rear ;
	int length ;
	
public:
	linked_Queue()
	{
		front = rear = NULL;
		length =0 ;			
	}
	bool isEmpty()
	{
		return length ==0 ;
	
		return rear==NULL ;
		
	}
	
	void enQueue(T element) 
	{
		node * newN = new node ;
		newN->item = element ;
		newN->next = NULL ;
		if (isEmpty())
		{
			front = rear = newN ;	
		}
		else 
		{
			rear->next = newN ;
			rear = newN ;
		}
		length ++ ;
	}	
	T deQueue()
	{
		if (isEmpty())
		{
			cout << "empty queue so can't deQueue... \n   " ;
			return  -1;
		}
		else 
		{
			T x ;
			if (front == rear)
			{
				x=front->item ;
				front = rear =NULL ;
				length -- ;	
			}
			else 
			{
				node * ptr = front ;
				x = front->item ;
				front = front->next ;
				delete ptr ;
			}
			return x;
		}
	}
	int get_length()
	{
		return length ;
	}
	void deQueue(T & element)
	{
		if (isEmpty())
		{
			cout << "empty queue so can't deQueue... \n   " ;
		}
		else 
		{
			if (front == rear)
			{
				element = front->item ;
				front = rear =NULL ;
			}
			else 
			{
				node * ptr = front ;
				element = front->item ;
				front = front->next ;
				delete ptr ;
			}
			length -- ;
		}
	}
	T getFront()
	{
		if (isEmpty()) return ;
		//assert(isEmpty()) ;
		return front->item ;	
	} 
	T getRear()
	{
		if (isEmpty()) return ;
		//assert(isEmpty()) ;
		return rear->item ;	
	} 

	void clear ()
	{
		node *ptr ;
		while (front!=NULL)
		{
			ptr = front ;
			front = front->next ;
			delete ptr ;		
		}
		length =0 ;	
		rear =NULL ;	
	}
	void print()
	{
		node *ptr = front ;
		while (ptr!=NULL)
		{
			cout << ptr->item << " " ;
			ptr =ptr->next ;
		}
		cout << "\n" ;
	}	 	 
};

int main()
{
//	ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;
	int n ;cout << "enter number of array size \n " ;cin >> n ;
	int arr [n] ;
	linked_Queue<int> Q ;
	for (int i=0 ;i<n ;i++)
	{
		cin >> arr[i] ;
		Q.enQueue(i) ;
	}
	int key ; cout << "\n enter key \n " ;cin >> key ;
	int count =0 , pos=0;
	while ( !(Q.isEmpty()) && pos>=0 && Q.get_length()>0)
	{
		//	cout << " suo\n " ; 
			Q.deQueue(pos) ;
			if (arr[pos]> 0 )
			{
				count ++ ;
				arr[pos]-- ;
				Q.enQueue(pos) ;
			}
			if(arr[key]==0)
			{
				break ;
			}
	}	
	cout << count << "\n " ;
//	Q.print() ;
	return 0 ;
/*
	cout << Q.deQueue() << "\n" ;
	cout << Q.deQueue() <<"\n" ;
	cout << Q.deQueue() <<"\n" ;
	cout << Q.deQueue() << "\n" ;
	cout << Q.deQueue() <<"\n" ;
	cout << Q.deQueue() <<"\n" ;
	Q.enQueue(50) ;
	cout << Q.deQueue() << "\n" ;
	cout <<"______________________________________\n" ;
	Q.print() ;
	
/*
	linked_Queue<int> Q ;
	Q.enQueue(1) ;
	Q.enQueue(1) ;
	Q.enQueue(1) ;
	int x ,y;
	Q.deQueue(x) ;
	y=Q.deQueue() ;
	Q.print();
	cout << x <<"\t " << y <<endl ; 
	//////////////////////////////////////////////////////////////////////////////////////// 
	while ( !(Q.isEmpty()))
	{
		cout << " haland \n "; 
			int pos = Q.deQueue() ;
			count ++ ;
			arr[pos]-- ;
			if ((arr[pos]>0) )
			{
				Q.enQueue(pos) ;
			}
			
			if(arr[key]==0)
			
			{
				break ;
			}
	}
*/	
	
}
