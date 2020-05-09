#include<iostream>
#include<stdlib.h>
#define null 0
using namespace std;
class node
{
 public :
 int data;
 node *next;
};
class SLL
{
private:
node *list;
public:
SLL()
{
list=null;
}
 void create(void);
 void insertfirst(int);
 void insertlast(int );
  void reverse(void);
 void insertat(int ,int );
 void display(void);
 void sort(void);
 void count(void);
 void search(int );
 void Delete(int );
};

void SLL::create(void)
{
 node *p,*q;
 char cho;
 list=new node;
 p=list;
 do
 {
  cout<<"enter ele";
  cin>>p->data;
  cout<<" u want other(y/n)..";
  cin>>cho;
  if(cho=='y')
  {
   q=new node;
   p->next=q;
   p=q;
  }
 }while(cho=='y');
 p->next=null;
 return;
}

void SLL:: insertfirst(int x)
{
 node *p;
 p=new node;
 p->data=x;
 p->next=list;
 list=p;
}

void SLL::insertlast(int x)
{
 node *p,*q;
 p=new node;
 p->data=x;
 p->next=null;
 if(list==null)
 {
  list=p;
  return;
 }
 q=list;
 while(q->next!=null)
 q=q->next;
 q->next=p;
}

void SLL::reverse()
{
 node *p,*q,*r,*m;
 p=list;
 q=null;
 if(list==null)
 cout<<"list does not exists";
 else
 {
  while(p!=null)
  {
   r=q;
   q=p;
   p=p->next;
   q->next=r;
  }
 list=m=q;
  cout<<"reverse of list is\n";
  while(m!=null)
  {
   cout<<"%d->",m->data;
   m=m->next;
  }
  cout<<"NULL";
 }
}

void SLL::insertat(int x,int pos)
{
 node *p,*q;
 int i;
 if(pos==1)
 insertfirst(x);
 else
 {
  p=new node;
  p->data=x;
  q=list;
  for(i=1;i<pos-1;i++)
  q=q->next;
  p->next=q->next;
  q->next=p;
 }
}

void SLL::display()
{
 node *q;
 if(list==null)
 cout<<"list does not exists";
 else
 {
  q=list;
  while(q!=null)
  {
   cout<<q->data<<"->";
   q=q->next;
  }
  cout<<"NULL\n";
 }

}

void SLL::sort()
{
 node *p,*q;
 int temp;
 for(p=list;p!=NULL;p=p->next)
 for(q=p->next;q!=NULL;q=q->next)
 if(p->data > q->data)
 {
  temp=p->data;
  p->data=q->data;
  q->data=temp;
 }
}

void SLL:: count()
{
 node *p;
 int i=0;
 if(list==null)
 cout<<"list does not exists";
 else
 {
  for(p=list;p!=NULL;p=p->next)
  i++;
  cout<<"no of nodes in the list are "<<i;
 }
}

void SLL::search(int d)
{
 node *p;
 int f=0,pos=1;
 p=list;
 while(p!=null && f==0)
 {
  if(p->data==d)
  f=1;
  else
  {
   pos++;
   p=p->next;
  }
 }
 if(f==1)cout<<"ele found at "<<pos<< "position\n";
 else cout<<"ele is not found\n";
}

void SLL::Delete(int x)
{
 node *p,*k;
 int f=0;
 p=list;

 if(list->data==x)
 {
  list=list->next;
  free(p);
  f=1;
 }

 while(p!=null && f==0)
 {
  if(p->data==x)
  {
   k->next=p->next;
   free(p);
   f=1;
  }
 else
 {
  k=p;
  p=p->next;
 }
  }
 if(f==1)
 cout<<"element deleted\n";
 else cout<<"element not found";
}

main()
{
	SLL s;
 int ch,ele,pos;
  do
 {
  cout<<"\n*** single linked list ***\n";
  cout<<"\n1.create\t";
  cout<<"2.insertfirst\t";
  cout<<"3.insertlast\n";
  cout<<"4.insert at \t";
  cout<<"5.display\t";
  cout<<"6.count\n";
  cout<<"7.sort\t\t";
  cout<<"8.search\t";
  cout<<"9.delete\n";
  cout<<"10.reverse\t";
  cout<<"11.exit\t\n";
  cout<<"enter u r choice......";
  cin>>ch;
  switch(ch)
  {
   case 1:
   s.create();
   break;
   case 2:
   cout<<"enter element";
   cin>>ele;
   s.insertfirst(ele);break;
   case 3:
   cout<<"enter element";
   cin>>ele;
   s.insertlast(ele);break;
   case 4:
   cout<<"enter element\n";
   cin>>ele;
   cout<<"enter position\n";
   cin>>pos;
   s.insertat(ele,pos);
   break;
   case 5:
   s.display();
   break;
   case 6: s.count();break;
   case 7:s.sort();break;
   case 8:
   cout<<"enter element to be searched";
   cin>>ele;
   s.search(ele);
   break;
   case 9:
   cout<<"enter element to be deleted";
   cin>>ele;
   s.Delete(ele);
   break;
   case 10:
   s.reverse();break;
   case 11:
   exit(0);
   break;
  }
 }while(ch<=11);
}
