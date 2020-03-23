#include <stdio.h>
int main(){
	char s;
	printf("Enter symbol:\n");
	scanf("%c", &s);
	s = (int) s;
	int min_n = 127 - s + 1; // min step for overflow
	printf("Min step for overflow = %d\n",min_n);
	int n = min_n;
	printf("Enter step:\n");
	scanf("%d", &n);
	int s_final_int = s + n;
	char s_final_char = (char) s_final_int; // symbol after overflow
	printf("Number after overflow = %d\nSymbol after overflow = %c\n", 
	s_final_int, s_final_char);
	return 0;
}
	
