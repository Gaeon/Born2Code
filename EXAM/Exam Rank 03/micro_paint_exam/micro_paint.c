#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int		W;		// draw zone width
int		H;		// draw zone height
char	BC;		// draw character
char	**TAB;	// result

typedef struct s_dw
{
	char	t;	// type
	float	x;	// x
	float	y;	// y
	float	w;	// width
	float	h;	// height
	char	c;	// character
}	t_dw;

int	error(FILE *fd, int err)
{
	if (err == 2 && (err = 1))
		write (1, "Error: Operation file corrupted\n", 32);
	else if (err == 1)
		write (1, "Error: argument\n", 16);
	else
	{
		for (int i = 0; i < H; i++)
		{
			write(1, TAB[i], W);
			write(1, "\n", 1);
		}
	}
	if (fd)
		fclose(fd);
	return (err);
}

int in_rect(float x, float y, t_dw dw)
{
	// 사각형의 외부
	if (y - dw.x < 0 || dw.x + dw.w - y < 0 || x - dw.y < 0 || dw.y + dw.h - x < 0)
		return (0);
	// 사각형의 경계
	if (y - dw.x < 1 || dw.x + dw.w - y < 1 || x - dw.y < 1 || dw.y + dw.h - x < 1)
		return (1);
	// 사각형의 내부
	return (2);
}

int	main(int ac, char **av)
{
	t_dw	dw;
	FILE	*fd;
	int		rect;
	int		res;

	fd = NULL;
	if (ac != 2)
		return (error(fd, 1));
	if ((fd = fopen(av[1], "r")))
	{
		if ((res = fscanf(fd, "%d %d %c", &W, &H, &BC)) == 3)	
		{
			if (W > 0 && W <= 300 && H > 0 && H <= 300)
			{
				TAB = malloc(sizeof(char *) * H);
				for (int i = 0; i < H; i++)
				{
					TAB[i] = malloc(sizeof(char) * W);
					memset(TAB[i], BC, W);
				}
				while (1)
				{
					res = fscanf(fd, "\n%c %f %f %f %f %c", &dw.t, &dw.x, &dw.y, &dw.w, &dw.h, &dw.c);
					// 종료
					if (res == -1)
						return (error(fd, 0));
					// 에러
					if (res != 6 || dw.w <= 0 || dw.h <= 0 || (dw.t != 'r' && dw.t != 'R'))
						break ;
					// 사각형 그리기
					for (int line = 0; line < H; line++)
					{
						for (int col = 0; col < W; col++)
						{
							rect = in_rect(line, col, dw);
							if (rect == 1 || ((rect == 1 || rect == 2) && dw.t == 'R'))
								TAB[line][col] = dw.c;
						}
					}
				}
			}
		}
	}
	return (error(fd, 2));
}
