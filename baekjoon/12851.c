//숨바꼭질2
#include <stdio.h>
#include <stdlib.h>

struct Node *node_m;
int n, k;

struct Node
{
	int val;
	int time;
	struct Node *next;
};

struct Node *create(int val, int time)
{
	struct Node *node_c = (struct Node*)malloc(sizeof(struct Node));
	node_c->val = val;
	node_c->time = time;
	node_c->next = NULL;
	return node_c;
}

void insert(int val, int time)
{
	struct Node *node_i = create(val, time);

	if (node_m->next != NULL)
	{
		while (node_m->next)
		{
			
		}		
	}

}


int	main(void)
{
	scanf("%d %d", &n, &k);

	node_m = (struct Node *)malloc(sizeof(struct Node));


	// node_m
	// struct Node node_m = create(n, 0);


}