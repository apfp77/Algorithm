#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_temp
{
	int val;
	struct Node_temp *next;
	struct Node_temp *befor;
}Node;

typedef struct Deque_link
{
	int cnt;
	Node *front;
	Node *end;
}deque_link;

deque_link deque;

void push_front(int val)
{
	Node *node = (Node *)(malloc)(sizeof (Node));
	node->val = val;
	node->befor = NULL;
	
	//사이즈가 0이면
	if (!deque.cnt)
	{
		node->next = NULL;
		deque.end = node;
	}
	else
	{
		node->next = deque.front;
		deque.front->befor = node;
	}
	deque.front = node;
	deque.cnt++;
}

void push_back(int val)
{
	Node *node = (Node *)(malloc)(sizeof (Node));
	node->val = val;
	node->next = NULL;
	
	if (!deque.cnt)
	{
		node->befor = NULL;
		deque.front = node;
	}
	else
	{
		node->befor = deque.end;
		deque.end->next = node;
	}
		deque.end = node;
		deque.cnt++;
}

int pop_front()
{
	if (!deque.cnt)
		return -1;
	
	int buf = deque.front->val;
	if (deque.front->next != NULL)
		deque.front = deque.front->next;
	deque.front->befor = NULL;
	deque.cnt--;
	return (buf);
}

int pop_back()
{
	if (!deque.cnt)
		return -1;

	int buf = deque.end->val;
	if (deque.end->befor != NULL)
		deque.end = deque.end->befor;
	deque.end->next = NULL;
	deque.cnt--;
	return (buf);
}

int size()
{
	return (deque.cnt);
}

int empty()
{
	if (!deque.cnt)
		return 1;
	return 0;
}

int front()
{
	if (!deque.cnt)
		return -1;
	return deque.front->val;
}

int back()
{
	if (!deque.cnt)
		return -1;	
	return deque.end->val;
}



int	main(void)
{
	int n;
	int i = -1;
	int data;
	char str[15];


	scanf("%d", &n);
	while (++i < n)
	{
		scanf("%s", str);
		if (!strcmp("push_front",str))
		{
			scanf("%d", &data);
			push_front(data);
		}
		else if (!strcmp("push_back",str))
		{
			scanf("%d", &data);
			push_back(data);
		}
		else if (!strcmp("pop_front", str))
			printf("%d\n", pop_front());
		else if (!strcmp("pop_back", str))
			printf("%d\n", pop_back());
		
		else if (!strcmp("size", str))
			printf("%d\n", size());

		else if (!strcmp("empty", str))
			printf("%d\n", empty());

		else if (!strcmp("front", str))
			printf("%d\n", front());

		else if (!strcmp("back", str))
			printf("%d\n", back());
	}
}