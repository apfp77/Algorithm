//숨바꼭질 3

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_temp
{
	int val;
	struct Node_temp *befor;
	struct Node_temp *next;
}Node;


typedef struct Deque_struct
{
	int cnt;
	Node *front;
	Node *rear;
}Deque;

Deque deque;
int check[100001];

void push_front(int val);
void push_rear(int val);
int pop_front();

int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);
	push_rear(n);
	check[n] = 1;
	while (deque.cnt)
	{
		int buf = deque.front->val;
		pop_front();
		
		if (buf == k)
			break;

		if (buf * 2 < 100001 && !check[buf * 2])
		{
			push_front(buf * 2);
			check[buf * 2] = check[buf];
		}

		if (buf + 1 < 100001 && !check[buf + 1])
		{
			push_rear(buf + 1);
			check[buf + 1] = check[buf] + 1;
		}

		if (buf - 1 >= 0 && !check[buf - 1])
		{
			push_rear(buf - 1);
			check[buf - 1] = check[buf] + 1;
		}
	}
	printf("%d\n", check[k] - 1);

	return 0;
}

void push_front(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->befor = NULL;
	node->val = val;
	if (!deque.cnt)
	{
		node->next = NULL;
		deque.rear = node;
	}
	else
	{
		node->next = deque.front;
		deque.front->befor = node;
	}
	deque.front = node;
	deque.cnt++;
}


void push_rear(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->next = NULL;
	node->val = val;
	if (!deque.cnt)
	{
		node->befor = NULL;
		deque.front = node;
	}
	else
	{
		node->befor = deque.rear;
		deque.rear->next = node;
	}
	deque.rear = node;
	deque.cnt++;
}

int pop_front()
{
	if (!deque.cnt)
		return (0);
	if (deque.front->next != NULL)
		deque.front = deque.front->next;
	deque.cnt--;
	deque.front->befor = NULL;
	return (1);
}
