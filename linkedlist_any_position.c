#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert_at_end(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int delete_at_end()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=NULL;
		return val;
	}
}
void display()
{
	node *temp;
	if(head==NULL)
	{
		printf("NO NODES\n");
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
	}
}
void insert_at_head(int val)
{
	node *nn;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		nn->next=head;
		head=nn;
	}
}
int delete_at_head()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		temp=temp->next;
		head->next=NULL;
		val=head->data;
		head=temp;
		return val;
	}
}
void insert_at_pos(int val,int pos)
{
	node *temp,*nn;
	int c=1,i;//to count number of nodes
	//as temp is at head position, the default count is 1
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(head==NULL)
	{
		head=nn;
	}
	else if(pos==1)//inserting at head
	{
		insert_at_head(val);
	}
	else if(c<pos)
	{
		insert_at_end(val);//inserting value at very end of linked list
	}
	else//c>pos
	{
		temp=head;
		for(i=1;i<pos-1;i++)//stop at position-1
		{
			temp=temp->next;
		}
		nn->next=temp->next;
		temp->next=nn;
	}
}
int delete_at_pos(int pos)
{
	node *temp=head;
	int c=1,val,i;
	if(head==NULL)
	{
		return -1;
	}
	else if(pos==1)
	{
		return delete_at_head();
	}
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	if(c<=pos)
	{
		return delete_at_end();
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=temp->next->next;
		return val;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
			insert_at_end(val);
		}
		else if(ch==2)
		{
			val=delete_at_end();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			scanf("%d",&val);
			insert_at_head(val);
		}
		else if(ch==5)
		{
			val=delete_at_head();
			if(val==-1)
			{
				printf("NO NODES TO DELETE\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else if(ch==6)
		{
			//insert at postion
			scanf("%d%d",&val,&pos);
			insert_at_pos(val,pos);
		}
		else if(ch==7)
		{
			//delete at position
			scanf("%d",&pos);
			val=delete_at_pos(pos);
			if(val==-1)
			{
				printf("NO NODES TO DELETE AT THAT POSITION\n");
			}
			else
			{
				printf("%d\n",val);
			}
		}
		else
		{
			break;
		}
	}
}
/*1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
1
23
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
1
34
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
1
34
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
1
45
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
1
56
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
2
56
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
3
8066064 23 8066096
8066096 34 8066128
8066128 34 8066160
8066160 45 0
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
6
2
34
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
3
8066064 23 8066096
8066096 34 8066128
8066128 34 8066160
8066160 45 8066256
8066256 2 0
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
7
1
23
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
3
8066096 34 8066128
8066128 34 8066160
8066160 45 8066256
8066256 2 0
1)Insert at end 2)Delete at end 3)Display 4)Insert at head 5)Delete at head 6)Insert at position 7)Delete at position 8)Exit
8

--------------------------------*/
