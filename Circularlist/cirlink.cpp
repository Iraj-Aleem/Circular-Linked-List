#include "cirlink.h"
#include <iostream>



using namespace std;

void cirlink::create_list(long	long	int data)
{
	struct node *q,*tmp;
	tmp=new(struct node);
	tmp->info=data;

	if(last==NULL)
	{
	last=tmp;
	tmp->link=last;
	}
	else
	{
		tmp->link=last->link;	/*added at the end of list*/
		last->link=tmp;
		last=tmp;
	}
}

void cirlink::addatbeg(long		long	int data)
{
	struct node *tmp;
	tmp=new(struct node);
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
}

void cirlink::addafter(long	long	int data,long	long	int pos)
{
	struct node *tmp,*q;
	int i;
	q=last->link;
	for(i=0;i<pos;i++)
	{
		q=q->link;
		if(q==last->link)
		{
			cout<<"There are less than "<<pos<<" elements"<<endl;
			return;
		}
	}
	tmp=new(struct node);
	tmp->link=q->link;
	tmp->info=data;
	q->link=tmp;

	if(q==last)	last=tmp;	/*element inserted at the end*/
}

void cirlink::del(long	long	int data)
{
	struct node *tmp,*q;
	if(last->link==last&&last->info==data)	/*only one element*/
	{
		tmp=last;
		last=NULL;
		delete(tmp);
		return;
	}
	q=last->link;
	if(q->info==data)
	{
		tmp=q;
		last->link=q->link;
		delete(tmp);
		return;
	}
	while(q->link!=last)
	{
		if(q->link->info==data)	       /*element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			delete(tmp);
			cout<<"Deleted "<<data<<endl;
			return;
		}
		q=q->link;
	}
	if(q->link->info==data)		/*last element deleted q->link=last*/
	{
		tmp=q->link;
		q->link=last->link;
		delete(tmp);
		last=q;
		return;
	}
	cout<<"Element "<<data<<" not found"<<endl;
}

void cirlink::display()
{
	struct node *q;
	if(last==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	q=last->link;
	cout<<"List is:"<<endl;
	while(q!=last)
	{
		cout<<q->info<<"   ";
		q=q->link;
	}
	cout<<last->info<<endl;
}

