#include <unistd.h>

void ft_putchar(char c);

int main(){
	ft_putchar('c');

	return 0;
}

void ft_putchar(char c){
	write(1, &c, 1);
}
