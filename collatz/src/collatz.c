#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3) /*check if the programm has the correct amount of arguments*/
        printf("Programm needs to be called as : ./Collatz left_limit right_limit"); /*print error message*/

    int left_limit = atoi(argv[1]);
    int right_limit = atoi(argv[2]);
    int *array = malloc(sizeof(int) * 100000000); /*array declaration in dynamic format*/

    if (left_limit < 1 || right_limit < 1)
    { /*If one of the limits is non-positive the programm prints "0" and terminates*/

        printf("0\n");
        return 1;
    }
    long long n;
    int max_counter, temp_counter, i;/*declaration of a temporary counter for the collatz sequence and of a max counter to save the max of all the temporary counters*/
    max_counter = 1;
    for (i = left_limit; i <= right_limit; i++)
    {/*creation of a loop that checks every value in the range of the given limits*/
        temp_counter = 1;
        n = i;/*n is a temporary variable which takes the value of i and undergoes collatz sequence*/

        while (n != 1)
        {/*creation of a loop to apply collatz sequence on the variable n*/
            if (n<100000000 && array[n] != 0)/*check if n is below 100000000 (which is the given limit for the programm's arguments) and if so check if we have already saved the collatz number for the current value of n from previous loops*/
            {
                temp_counter = array[n] + temp_counter - 1;
                break;
            }

            if (n % 2 == 0)
                n = n / 2;
            else
            {
                n = 3 * n + 1;
                n = n / 2;/*if n is odd we can do two steps at once and add an extra unit to the temorary counter to skip some loops*/
                temp_counter++;
            }
            temp_counter++;
        }
        
        array[i] = temp_counter;/*we save the value of the temporary counter to this array so that we have it available for the next numbers that we are goint to check. Thus, we skip some loops. */
        if (temp_counter > max_counter)/*we give the biggest value of all temporary counters to to the max counter*/
            max_counter = temp_counter;
    }
    printf("%d\n", max_counter);/*we print the max counter*/
    return 0;
}
