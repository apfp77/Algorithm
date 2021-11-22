//숨바꼭질 3

#include <stdio.h>
#include <stdlib.h>

typedef struct Check_temp
{
	int visit;
	int time;
	int cnt;
}ch;

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

void push_front(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->befor = NULL;
	node->val = val;
	if (!deque.cnt)
	{
		node -> next = NULL;
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
	deque.front->befor=NULL;
	return (1);
}



//곱하기가 나온다면 deque를 이용하여 풀어본다
//똑같은 곳은 방문하지 않는다
int main(void)
{
	int n, k;

	scanf("%d %d", &n, &k);

	return 0;
}

