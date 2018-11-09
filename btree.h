//Aubrey Jenkins
/*This is an implementation of a binary tree that can take in any type except CStrings becasue that
makes the everything change into the last thing inputted*/
#ifndef btree_h
#define btree_h
#include <iostream>
#include <stddef.h>
#include <cstddef>
#include<string>
using namespace std;
template<class t>
class Node
{
	private:
	t data;
  Node<t>* right;
  Node<t>* left;
 	public:
		// Constructors
		Node();
		Node(t V);
		Node(t V, Node<t> *l);
    Node(t V, Node<t> *l,Node<t> *r );

		// Set methods
		void setItem( t v);
		void setRight(Node<t> *n);
    void setLeft(Node<t> *n);
		// Get Methods
		Node<t> * getRight();
    Node<t> * getLeft();
		t  getItem();
};
// create all constructors
template<class t>
Node<t>::Node()
{
 right=NULL;
 left=NULL;
}

template<class t>
Node<t>::Node(t anItem)
{
 data=anItem;
 right=NULL;
 left=NULL;
}

template<class t>
Node<t>::Node( t  anItem, Node<t>* LeftPtr)
{
 data=anItem;
 left=LeftPtr;
 right=NULL;
}
template<class t>
Node<t>::Node( t  anItem, Node<t>* LeftPtr,Node<t>* RightPtr)
{
 data=anItem;
 left=LeftPtr;
 right=RightPtr;
}
// Set methods
template<class t>
void Node<t> :: setItem ( t  anItem)
{
 data=anItem;
}

template<class t>
void Node<t>:: setLeft (Node<t>* LeftPtr)
{
 left=LeftPtr;
}
template<class t>
void Node<t>:: setRight (Node<t>* RightPtr)
{
 right=RightPtr;
}
// Get methods
template<class t>
t Node<t>::getItem()
{
 return data;
}
template<class t>
Node<t>*  Node<t>::getLeft()
{
 return left;
}
template<class t>

Node<t>*  Node<t>::getRight()
{
 return right;
}

template<class t>
class Btree
{
private:
	Node<t>* root;//This variable represents the top of the tree
	/*This is The insert that the function calls to acuallly put things into the tree it is recursive
	 it takes in a node pointer , value to be inserted and a compare to know how to move through the tree*/
	void insertHelper(Node<t>* N,t item,int (*cmp)(t first, t second))
	{
		if(cmp(N->getItem(),item)==2)//if the function returns a 2 if
			{
				if(N->getRight()!=NULL)
				insertHelper(N->getRight(),item,cmp);
				else
					N->setRight(new Node<t>(item));
			}
			else if(cmp(N->getItem(),item)==1)
			{
				if(N->getLeft()!=NULL)
				insertHelper(N->getLeft(),item,cmp);
				else
				N->setLeft(new Node<t>(item));
			}
			else if(cmp(N->getItem(),item)==0)
			{
				if(N->getLeft()!=NULL)
				insertHelper(N->getLeft(),item,cmp);
				else
				N->setLeft(new Node<t>(item));
			}
			root=N;
	}
/*prints the tree inorder */
	void inorder(Node<t>* r)
	{
		if (r==NULL) return;
		inorder(r->getLeft());
		visit(r);
		inorder(r->getRight());
	}
	/*prints the root then the child of each  subtree*/
	void preorder(Node<t>* r)
	{
		if (r==NULL) return;
		visit(r);
		preorder(r->getLeft());
		preorder(r->getRight());
	}
	/*prints the childern then the root of each subtree*/
	void postorder(Node<t>*r)
	{
		if (r==NULL) return;
		postorder(r->getLeft());
		postorder(r->getRight());
		visit(r);
	}
	/*This is the find that the function calls to acuallly find thing that are in the tree
	 it takes in a node pointer , value to be found and a compare to know how to move through the tree*/
	bool findHelper(Node<t>* N,t item,int (*cmp)(t first, t second))
	{
		if(cmp(N->getItem(),item)==0)
		{
			return true;
		}
		else if((cmp(N->getItem(),item)!=0)&&(N->getRight()==NULL)&&(N->getLeft()==NULL))
		{
			return false;
		}
		if(cmp(N->getItem(),item)==2)
		findHelper(N->getRight(),item,cmp);
		else if(cmp(N->getItem(),item)==1)
		findHelper(N->getLeft(),item,cmp);
	}
	/*This is The removee that the function calls to acuallly take things out of the tree
	 it takes in a node pointer , value to be removed and a compare to know how to move through the tree*/
	bool removehelp(Node<t>* N,t item,int (*cmp)(t first, t second))
	{
			if(root==NULL)
			{
				return false;
			}
			else if((N->getItem()==root->getRight()->getItem())&&(N->getRight()->getRight()==NULL)&&(N->getRight()->getLeft()==NULL))
			{
				cout<<"I gotn Here"<<endl;
				Node<t>* temp;
				temp=N->getRight();
				N->getRight()==NULL;
				delete temp;
				return true;
			}
			else if((N->getItem()==root->getLeft()->getItem())&&(N->getLeft()->getRight()==NULL)&&(N->getLeft()->getLeft()==NULL))
			{
				Node<t>* temp;
				temp=N->getRight();
				N->getRight()==NULL;
				delete temp;
				return true;
			}
			else
			{
				cout<<"I did Not code for what you are trying to do becasue I am a bad coder"<<endl;
			}

	}
public:
	/*This is the constructor is sets root equal to NUll*/
	Btree()
	{
		root=NULL;
	}

	Btree(t item)
	{
		root=new Node<t>(item);
	}
	/*This is the insert that the main calls it takes the item to be inserted and the
	compare function that is used */
	void insert(t item,int (*cmp)(t first, t second))
	{
		if(root==NULL)
		{
			root= new Node<t>(item);
			return;
		}
		insertHelper(root,item,cmp);
	}

	/*This is the preorder traversal that the main calls it should print in order*/
	void inorder()
	{
		inorder(root);
	}

	/*This is the preorder traversal that the main calls it should print by */
	void preorder()
	{
		preorder(root);
	}

	/*This is the postorder that the main calls*/
	void postorder()
	{
		postorder(root);
	}

	/*This is the find that the main calls it takes the item to be found and the
	compare function that is used */
	bool find(t item,int (*cmp)(t first, t second))
	{
		 return findHelper(root,item,cmp);
	}
	/*This is the removee that the main calls it takes the item to be removed and the
	compare function that is used */
	bool removee(t item,int (*cmp)(t first, t second))
	{
		if(findHelper(root,item,cmp)== false)
		{
		 return false;
	 }
	 else
			return removehelp(root,item,cmp);
	}
	/*This is used to output whatever is in the what r is set too*/
	void visit(Node<t>* v)
	{
		cout<<v->getItem()<<endl;
	}
};
#endif
