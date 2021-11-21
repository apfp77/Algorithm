//숨바꼭질2
#include <stdio.h>
#include <stdlib.h>

struct Node *head;
struct Node *head_final;
int check[100100][3];
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
	struct Node *list = head_final;

		if (!(head->next))
	{
		head-> next = node_i;
		head_final = node_i;
	}
	else
	{
		list->next = node_i;
		head_final = node_i;
	}
}


int	main(void)
{
	scanf("%d %d", &n, &k);

	head = (struct Node *)malloc(sizeof(struct Node));
	head_final = (struct Node *)malloc(sizeof(struct Node));
	head->val = n;
	head->time = 0;
	struct Node *list = head;
	int mx = 100000;
	int test=0;

	//1은 time, 2는 개수, 0은 인덱스 값의 상태를 체크
	//1(time)의 인덱스가 현재값보다 높은 수가 들어온다면 val은 1로 변환
	//time이 0이 아니면 실행하면서 같은 값의 val이면서 time <= 면 실행
	if (list->val == k)
	{
		printf("0\n1\n");
		return (0);
	}

	while (1)
	{
		if (mx < list->time)
			break;

		if (list->val == k)
		{
			mx = list->time;
			test = list->time;
		}
		
		if (list->val + 1 <= k)
		{
			if (!check[list->val + 1][1] || list->time + 1 <= check[list->val + 1][1])
			{
				check[list->val+1][1] = list->time + 1;
				check[list->val + 1][2]++;
				insert(list->val + 1, list->time + 1);
			}
			else
				check[list->val + 1][1] = 1;
		}

		if (list->val - 1 >= 0)
		{
			if (!check[list->val - 1][1] || list->time + 1 <= check[list->val - 1][1])
			{
				check[list->val - 1][1] = list->time + 1;
				check[list->val - 1][2]++;
				insert(list->val - 1, list->time + 1);
			}
			else
				check[list->val - 1][1] = 1;
			// insert(list->val - 1, list->time + 1);
		}

		if (list->val * 2 <= 100000)
		{
			if (!check[list->val * 2][1] || list->time + 1 <= check[list->val * 2][1])
			{
				check[list->val * 2][1] = list->time + 1;
				check[list->val * 2][2]++;
				insert(list->val * 2, list->time + 1);
			}
			else
				check[list->val * 2][1] = 1;
			// insert(list->val * 2, list->time + 1);
		}
		if (list->next == NULL)
			break;
		list = list->next;
	}
	printf("%d\n%d\n", test, check[k][2]);
}
