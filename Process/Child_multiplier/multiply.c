/*PROGRAM TO MULTIPLY TWO NUMBERS TAKEN VIA THE COMMAND LINE*/

# include <stdio.h>
# include <stdlib.h>
int main(int argc ,char * argv[]){
    int a , b;
    if(argc != 3){
        printf("Incorrect usage !! Usage -> %s [num1] [num2]",argv[0]);
        return 1;
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    printf("Product = %d\n",a*b);
    return 0;
}