#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(){
	char *line;

	int fd = open("hello.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
		printf("%s\n", line);
}
