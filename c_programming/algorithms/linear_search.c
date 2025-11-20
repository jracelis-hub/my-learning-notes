#include <stdio.h>
#include <string.h>

int linear_search(const char *word, char target)
{
    int index = 0;
    while (*word != '\0') 
    {
        if (*word == target) 
        {
            return index;
        }
        index++;
        word++;
    }
}

int main() 
{
    const char *sentence = "Jarron Racelis";

    int index = linear_search(sentence, 'R');

    printf("Index = %d\n", index);

    return 0;
}