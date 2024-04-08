#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* passwordGenerator(int max)
{
    if(max > 48)
    {
        printf("You can't provide a number higher than 48");
        return NULL;
    }
    int random;
    int maxGen = max;
    char pass[maxGen];


    int i = 0;
    while(i < maxGen)
    {
        srand(time(NULL) + i); // Edit random seed to current timestamp
        random = rand() % 127; // Generate a random in ASCII range
        random = random < 33 ? random + 33 : random; // Append the case we don't have a descent caracter
        char ascii = random; // we transfert the random ascii to character
        pass[i] = ascii;
        i++;
    }

    char* pointer = pass;
    return pointer;
}

int main()  {
    printf("How long you password must be ? \n Password length : ");
    int input;
    scanf("%i", &input);

    if(input)
    {
        char *password = passwordGenerator(input);
        if(password)
        {
            printf("Your generated password is : %s", password);
            return 0;
        }
        return 1;
    }
    return 1;
}


