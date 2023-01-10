#include <unistd.h>

void ft_print_alphabet(void);

int main(){
	ft_print_alphabet();

	return 0;
}

void ft_print_alphabet(){
	for(int i = 0; i <  26; i++){
		char alpha = i + 'a';
		write(1, &alpha, 1);
	}
}
