//alie
//#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
#include <cmath> 
#include <string>
#include<cstring>
template <class T >
class linked_stack 
{
	int size ;
	struct node{
		T item ;
		node * next ;
	};
	node * top ;
public :
	linked_stack()
	{
		top =NULL ;
		size = 0 ; // addition from me but we dont need 
	}
	bool isEmpty()
	{
		return top== NULL ;
		// return size ==0 ;
	}
	void push( T element )
	{
		node * newN = new node ;
		newN->item = element ;
		newN->next = top ;
		top = newN ;
		size ++ ;
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << " empty stack can't pop.. \n" ;
		}
		else 
		{
		node * ptr = top ;
		top = top->next  ; 
		delete ptr ; // if you want print you can do befor delete 
		size-- ;
		}
	}
	void pop(T & element )
	{
		if (isEmpty())
		{
			cout << " empty stack can't pop.. \n" ;
		}
		else 
		{
		node * ptr = top ;
		top = top->next  ;
		element = ptr->item ;
		delete ptr ;
		size-- ;
		}
	}
	T getTop()
	{
		if (isEmpty())
		{
			cout << " empty stack get top .. \n" ;
			return -1 ;
		}
		else 
		{
			return top->item ;
		}
	}
	void print()
	{
/*		void print()
	{
		node *ptr = top ;
		cout << " [ " ;
		while (ptr!=NULL)
		{
			cout << ptr->item << " " ;
			ptr =ptr->next ;
		}
		cout << " ] \n " ;
	}
*/
		string s ="" ;
		node *ptr = top ;
		while (ptr!=NULL)
		{
			s+=char(ptr->item) ;
			ptr =ptr->next ;
		}
		string final="" ;
		int i=int(s.length()-1) ;
		while (i>=0)
		{
			final+=s[i--] ;
		}
		cout << final << "\n" ;
	}

};

int main()
{
	ios_base::sync_with_stdio(0) , cin.tie(0) ,cout.tie(0) ;
	string input ;
	linked_stack<int> s;
	cin>> input ;

	s.push('/') ;
	for (int i=1 ;i<int(input.length()-1); i++)
	{
		if(input[i]=='.' && input[i+1]=='.')
		{
			if(input[i+2]=='.')
			{
				s.push('.') ;
				s.push('.') ;
				s.push('.') ;
				i++;
			}
			i++ ;
		}
		else if(input[i]=='/' && input[i+1]=='/')
		{
			s.push('/') ;
			i++ ;
		}
		else 
		{
			s.push(input[i]) ;
 		}
		
	}
	s.print() ;

	return 0 ;
}
