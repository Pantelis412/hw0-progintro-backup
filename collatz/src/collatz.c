#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
    if (argc != 3)
        printf("Programm needs to be called as : ./Collatz left_limit right_limit");

int left_limit = atoi(argv[1]);           
int right_limit = atoi(argv[2]);

if (left_limit < 1 || right_limit < 1){     /*If one of the limits is non-positive the programm prints "0" and terminates*/

    printf("0\n");
    return 1;
}
long long n;
int max_counter, temp_counter, i;
max_counter = 1;
for (i = left_limit ; i <= right_limit ; i++ ){
    temp_counter = 1;
    n = i;

    while (n != 1){
        if (n%2==0)
            n=n/2;
        else{
            n=3*n+1;
            n=n/2;
            temp_counter++;
        }temp_counter++;
    
   } 
   if (temp_counter > max_counter)
        max_counter = temp_counter;
}
printf("%d\n", max_counter);
return 0;
}