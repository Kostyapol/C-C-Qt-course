#include <stdio.h>
int main(){
    int n;
    int i = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    do {
        i++;
        printf("i=%d\n" ,i);
        int j = 0;
            while (j<n){
            j+=i+1;
            printf("j=%d\n" ,j);
                for (int k=1;k<j; k++,printf("Cycle 'for'\n")){
                }
           }
    }
    while (i<n);  
return 0;
} 

