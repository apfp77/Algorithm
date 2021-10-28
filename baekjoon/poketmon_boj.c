#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hash *hash_node;
int p_i;

struct hash
{
	struct n_node *head;
	int count;
};


struct n_node
{
	char key[21];
	int index;
	struct n_node *next;
};

int hash_function(char key)
{
	int hash_index;
	if (key >64 && key < 91)
		hash_index = (int)(key - 65);
	else
		hash_index = (int)(key - 65 - 6);
	return hash_index;
}

struct n_node* create(char *key, int index)
{
	struct n_node *node = (struct n_node *)malloc(sizeof(struct n_node));
	int size = strlen(key);
	for (int i = 0; i < size; i++)
	{
		node->key[i] = key[i];
	}
	node->index = index;
	node->next = NULL;
	return node;
}

void insert(char *key, int index)
{
	int hash_index = hash_function(key[0]);
	struct n_node *node = create(key, index);
	if (hash_node[hash_index].count == 0)
	{
		hash_node[hash_index].head = node; 
		hash_node[hash_index].count = 1;
	}
	else
	{
		node->next = hash_node[hash_index].head;
		hash_node[hash_index].head = node;
		hash_node[hash_index].count++;
	}
}

int search_key(char *key)
{
	int hash_index = hash_function(key[0]);
	int flag = 0;
	struct n_node *node = hash_node[hash_index].head;
	struct n_node *n_buf;
	if (node == NULL)
		return (0);

	while (node != NULL)
	{
		if (!strcmp(node->key, key))
		{
			flag = 1;
			break;
		}
		node = node->next;
	}
	return node->index;
}

int char_integer(char *arr)
{
	int num = 0;
	int size = strlen(arr);
	for (int i = 0; i < size; i++)
		num = num * 10 + (arr[i] - '0');
	return (num);
}

void integer_char(int j, char *print)
{
	int temp = j % 10;
	if (j == 0)
		return;
	integer_char(j / 10, print);
	print[++p_i] = temp + '0';
}

int	main(void)
{
	hash_node = (struct hash *)malloc(sizeof(struct hash) * 52);
	int n, m;
	scanf("%d %d", &n, &m);
	char arr[n][21];
	char qa[m][21];
	char **print = (char **)malloc(sizeof(char *) * m);
	int buf = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
		insert(arr[i], i);
	}
	
	for (int i = 0; i < m; i++)
	{
		scanf("%s", qa[i]);
		print[i] = (char *)malloc(sizeof(char) * 21);
		if (qa[i][0] >= '1' && qa[i][0] <= '9')
		{
			buf = char_integer(qa[i]) - 1;
			print[i] = arr[buf];
		}
		else
		{
			buf = search_key(qa[i]) + 1;
			p_i = -1;
			integer_char(buf, print[i]);
		}
	}

	for (int i = 0; i < m; i++)
		printf("%s\n", print[i]);
}