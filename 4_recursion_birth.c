#include <stdio.h>
int sum (int a);

int main (){
    int date = 0;
    printf("Enter your date of birth (ddmmyy):");
	scanf("%d", &date); 
    int sum_date = 	sum (date);
	printf("Sum  date of birth numbers:%d\n",sum_date);
}

int sum (int a){
	if (a == 0) return 0;
	else return a%100 + sum(a/100); 
}
