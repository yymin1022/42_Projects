/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:43:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/01/30 19:43:22 by yonyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq_header.h"

int	get_size(char *str)
{
	int		fd;
	int		len;
	char	c;

	len = 0;
	fd = open(str, O_RDONLY);
	while (0 < read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		len++;
	}
	return (len);
}

int	get_col(char *str)
{
	int		fd;
	int		len;
	int		i;
	char	c;

	len = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	while (0 < read(fd, &c, 1))
	{
		if (i == 1 && c != '\n')
			len++;
		if (c == '\n')
			i++;
		if (i == 2)
			break ;
	}
	close(fd);
	return (len);
}

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	idx;

	*(src) = '.';
	idx = 1;
	while (*(src + idx) && idx < n + 1)
	{
		*(dest + idx) = *(src + idx);
		idx++;
	}
	*(dest + idx) = '.';
	*(dest + idx + 1) = '\0';
	return (dest);
}

char	*get_info(char *str)
{
	int		fd;
	char	*info;
	int		buffer;

	buffer = get_size(str);
	info = (char *)malloc(buffer);
	fd = open(str, O_RDONLY);
	read(fd, info, buffer);
	close(fd);
	return (info);
}

long long	get_row(char *str, int	len)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while (i < len)
	{
		res = res * 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

void	init_arr(char **map_char, int **map_cnt, long long row, long long col)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		*(map_char + i) = (char *)malloc(sizeof(char) * row);
		*(map_cnt + i) = (int *)malloc(sizeof(int) * row);
		j = 0;
		while (j < col)
		{
			*(*(map_char + i) + j) = '.';
			*(*(map_cnt + i) + j) = 0;
			j++;
		}
		i++;
	}
}

void	init_board(char *file_name, char **map_char, long long col, int size_data)
{
	char	*file_buf;
	int		i;
	int		file_read;

	file_buf = (char *)malloc(sizeof(char) * (col));
	file_read = open(file_name, O_RDONLY);
	read(file_read, file_buf, size_data);
	i = 1;
	while (0 < read(file_read, file_buf, col - 1))
	{
		ft_strncpy(*(map_char + i), file_buf, col);
		i++;
	}
}

void	convert_arr(char **map_char, int **map_cnt, char *file_info, long long row, long long col)
{
	int	i;
	int	j;

	i = 1;
	while (i < row - 1)
	{
		j = 1;
		while (j < col - 1)
		{
			if (map_char[i][j] == file_info[0])
				map_cnt[i][j] = 0;
			else if (map_char[i][j] == file_info[1])
				map_cnt[i][j] = -1;
			else
				printf("ERROR MAP\n");
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*file_name;
	char	*file_info;
	char	**map_char;
	int		**map_cnt;
	int		size_data;
	int		idx;

	if (argc < 2)
	{
		printf("No Input\n");
		return (0);
	}
	idx = 1;
	while (idx < argc)
	{
		file_name = *(argv + idx);
		file_info = get_info(file_name);
		size_data = get_size(file_name);
		printf("%s\n", file_info);
		t_point	cord = {get_row(file_info, size_data - 3) + 2, get_col(file_name) + 2};
		map_char = (char **)malloc(sizeof(char *) * cord.x);
		map_cnt = (int **)malloc(sizeof(int *) * cord.x);
		init_arr(map_char, map_cnt, cord.x, cord.y);
		init_board(file_name, map_char, cord.y, size_data);
		convert_arr(map_char, map_cnt, file_info + size_data - 3, cord.x, cord.y);
		if (!print_answer(map_cnt, map_char, cord, 'x'))
		{
			write(2, "no\n", 3);
			return (0);
		}
		idx++;
	}

	/* 1. 파일 정보 받기 
	 * get_info를 사용해서 맵의 첫줄 뽑기 (정보가 담겨있음)
	 * 정보 : (숫자)(빈 문자 1개)(장애물 문자 1개)(채워야하는 문자 1개)
	 *
	 * get_size는 첫줄 정보를 받기 위한 동적할당 크기를 구하는 함수
	 * get_row는 맵의 가로줄 수, get_col은 맵의 세로줄 수
	 * 
	 * %%%% get_row의 len 매개변수.%%%
	 * info의 맨 뒤 3개가 무조건 문자 정보이기 때문에 
	 * 최종 길이 -3개의 문자를 atol하면 된다.
	 *
	 * 이 값을 t_point에 넣어서{get_row, get_col}
	 * print_answer에 넘기기.
	 *
	 * print_answer(int **, char **, t_point, char)
	 * 1) int **
	 * 이때 주의할 점은 인자 첫번째가 맵을 정수로 바꾼 배열이라는 점.
	 * 가로와 세로에 크기를 2개 더 줘서 오류처리 편하게하기. 여기에는 0을 넣음.
	 * 즉 빈 문자에는 0, 장애물 문자는 -1로 치환한 결과값이 필요
	 *
	 *2) char **
	 맵 파일에서 파싱한 문자열, 단 마찬가지로 가로 세로에 크기를 2 더주고, 거기에
	 빈 문자열이 필요
	 *
	 *3) t_point 해당 맵의 가로 세로 길이, 단 마찬가지로 가로 세로에 크기 2 더 주기
	 *
	 *4) char - 채워야하는 문자 get_info를 사용하기,
	 *
	 *
	 *5) 반환값... 
	 * 1 이면 정상 출력, 0이면 모두 장애물로 채워져서 답이 없는 경우.
	 * 이럴때는 에러 출력.
	 */
	/* int	arr[11][29] = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0},
		{0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
		{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0}
	};
	char	cd[11][29] = {
		".............................",
		".............................",
	   	".....o.......................",
	   	".............o...............",
		".............................",
		".....o.......................",
	   	"................o............",
	   	".............................",
	   	".......o..............o......",
		"...o.......o.................",
		"............................."
	}; */
}
