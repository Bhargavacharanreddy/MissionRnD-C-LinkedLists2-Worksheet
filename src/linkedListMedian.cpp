/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
int linkedListMedian(struct node *head)
{
	if (head == NULL)
		return -1;
	int len = 0;
	struct node *temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	int count = 1;
	struct node *mid = head;

	while (head != NULL)
	{

		if (count & 1)
		{
			temp = mid;
			mid = mid->next;
		}

		count++;

		head = head->next;
	}


	if (len % 2 == 0)
	{

		return (((temp->num) + ((temp->next)->num)) / 2);
	}
	else
	{

		return (temp->num);

	}

}
