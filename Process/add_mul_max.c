/* COMMAND LINE CALCULATOR */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(int argc, char * argv[]){
    if(argc < 4){
        printf("Usage error , Usage %s [operation] [num1] [num2]\n",argv[0]);
        return 1;
    }
    int a = atoi(argv[2]) , b = atoi(argv[3]);
    if(strcmp(argv[1],"add")==0){
        printf("Sum = %d\n",a+b);
    }
    else if(strcmp(argv[1],"mul")==0){
        printf("Product = %d\n",a*b);
    }
    else if(strcmp(argv[1],"max")==0){
        if(a>b)
            printf("Maximum = %d\n",a);
        else
            printf("Maximum = %d\n",b);
    }
    else{
        printf("Invalid operation !! (add/mul/max)\n");
        return 1;
    }
    return 0;
}