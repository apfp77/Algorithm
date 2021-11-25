//토마토 (두번째)
#include <stdio.h>

int arr[10000][100];
int q[1000000][3];

int main(void) {
	int m, n, h, q_f, q_r;
    int mn = 0;
	scanf("%d %d %d", &m, &n, &h);
	
	for (int i = 0; i < n * h * m; i++)     
		for (int j = 0; j < 2; j++)
			q[i][j] = 0;

	q_f = q_r = 0;

	//q배열의 0은 세로 1은 가로
	for (int i = 0; i < n * h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				q[q_r][0] = i;
				q[q_r][1] = j;
                q[q_r][2] = 0;
                q_r++;
			}

		}
	}
    
	while (q_r != q_f)
	{
        int box_area = q[q_f][0] / n;
        //상
        if (q[q_f][0] - 1 >= n * box_area && arr[q[q_f][0]  - 1][q[q_f][1]] == 0)
        {
            arr[q[q_f][0] - 1][q[q_f][1]] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0] -1;
			q[q_r][1] = q[q_f][1];
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }

        //하
        if (q[q_f][0] + 1 < n * box_area + n && arr[q[q_f][0]  + 1][q[q_f][1]] == 0)
        {
            arr[q[q_f][0] + 1][q[q_f][1]] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0] + 1;
			q[q_r][1] = q[q_f][1];
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }
        

        //좌
        if (q[q_f][1] - 1 > -1 && arr[q[q_f][0]][q[q_f][1] - 1] == 0)
        {
            arr[q[q_f][0]][q[q_f][1] - 1] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0];
			q[q_r][1] = q[q_f][1] - 1;
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }

        //우
        if (q[q_f][1] + 1 < m && arr[q[q_f][0]][q[q_f][1] + 1] == 0)
        {
            arr[q[q_f][0]][q[q_f][1] + 1] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0];
			q[q_r][1] = q[q_f][1] + 1;
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }

        //아래 박스
        if (n * (box_area + 1) + n <= n * h && q[q_f][0] + n < n * (box_area + 1) + n &&arr[q[q_f][0] + n][q[q_f][1]] == 0)
        {
            arr[q[q_f][0] + n][q[q_f][1]] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0] + n;
			q[q_r][1] = q[q_f][1];
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }

        //위 박스
        if (q[q_f][0] - n > -1 && arr[q[q_f][0] - n][q[q_f][1]] == 0)
        {
            arr[q[q_f][0] - n][q[q_f][1]] = q[q_f][2] + 1;
            q[q_r][0] = q[q_f][0] - n;
			q[q_r][1] = q[q_f][1];
            q[q_r][2] = q[q_f][2] + 1;
            q_r++;
        }
        mn =  q[q_f][2] < mn ? mn : q[q_f][2];
        q_f++;
	}

    for (int i = 0; i < n * h; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!arr[i][j])
            {
                printf("-1\n");
                return (0);
            }
        }
    }
    printf("%d\n", mn);
	return 0;
}
