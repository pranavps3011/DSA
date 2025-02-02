/*Beginning with an empty binary search tree, construct binary search tree by inserting the values in
the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree.*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct node
{	int a;
	struct node *left,*right;
}node;

struct node *root=NULL;

class BST
{

	int count;
	struct node *temp=NULL,*t1=NULL,*s=NULL, *t=NULL;
	public:
	BST()
	{
		count=0;
	}
	struct node *create();
	void insert();
	int height(struct node*,int c);
	int findmin(struct node*);
	
	void display(struct node*);
	
};

int main()
{
	BST b;
	int x, m, c=0,cnt,min,fl;
	do
	{
		cout<<"\n enter your choice";
		cout<<"\n 1.insert";
		cout<<"\n 2.No of nodes in longest path";
		cout<<"\n 3.Minimum value";
		cout<<"\n 4.display";
		cout<<"\n 5.exit";
		cin>>x;
		switch(x)
		{
			case 1: 
				b.insert();
				break;
			case 2: 
				cnt=b.height(root, c);
				cout<<"\n No of nodes in longest path="<<cnt;
				break;
			case 3: 
				min=b.findmin(root);
				cout<<"\n Minimum value = "<<min;
				break;
			case 4 :
				b.display(root);
				break;
			case 5:
				exit(0);
		}
	}while(x!=5);
	return 0;
}

struct node *BST::create()
{
	node *p=new(struct node);
	p->left=NULL;
	p->right=NULL;
	cout<<"\n enter the data";
	cin>>p->a;
	return p;
}

void BST::insert()
{	
	temp=create();
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		t1=root;
		while(t1!=NULL)
		{
			s=t1;
			if((temp->a)>(t1->a))
			{
				t1=t1->right;
			}
			else
			{
				t1=t1->left;
			}
		}
		if((temp->a)>(s->a))
		{
			s->right=temp;
		}
		else
		{
			s->left=temp;
		}
	}
}

int BST::height(struct node *q,int c)
{
	if(root==NULL)
	{
		cout<<"\n tree not exist";
	}
	else
	{
		c++;
		if(q->left!=NULL)
		{
			height(q->left,c);
		}
		if(q->right!=NULL)
		{
			height(q->right,c);
		}
		if(count<c)
		{
			count=c;
		}
	}
	return count;
}

int BST::findmin(node *T)
{
	while(T->left!=NULL)
	{
		T=T->left;
	}
	return T->a;
}
void BST::display(struct node *q)
{
	if(q==NULL)
	{
		cout<<"\n tree not exist";
	}
	else
	{
		cout<<"\n*"<<q->a;
		if(q->left!=NULL)
		{
			display(q->left);
		}
		if(q->right!=NULL)
		{
			display(q->right);
		}
	}
}