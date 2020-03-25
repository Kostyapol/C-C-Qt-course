#include <stdio.h>
int main(){
    int a;
    printf("Enter number (0-6):");
    scanf("%d", &a);
    if (a<=6 && a>=0){   
        switch (a) {
            case 1:
                printf("First letter of %d: 'O'\n",a);
                break;
            case 2:
                printf("First letter of %d: 'T'\n",a);
                break;
            case 3:
                printf("First letter of %d: 'T'\n",a);
                break;
       	    case 4:
                printf("First letter of %d: 'F'\n",a);
                break;
            case 5:
                printf("First letter of %d: 'F'\n",a);
                break;
            case 6:
                printf("First letter of %d: 'S'\n",a);
                break;
            default: 
                printf("Error!\n",a);
                break;
       };
    };
    else
    printf("Number is not correct!\n");
return 0;
}
