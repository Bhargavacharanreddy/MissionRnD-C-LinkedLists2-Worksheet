/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int num;
	struct node *next;
};
struct node * Node(int num)/*creating a new node*/
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}
struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K < 0)
		return NULL;
	struct node *temp = head;
	struct node *prev = NULL;
	int len = 0;
	while (temp != NULL)
	{
		len++;
		prev = temp;
		temp = temp->next;
	   if (len % K == 0)
		{
			struct node *newNode = Node(K);
		   prev->next = newNode;
			newNode->next = temp;
		}
	}

	return head;
}
