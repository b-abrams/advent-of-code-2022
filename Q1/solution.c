#include <stdlib.h>
#include <stdio.h>

int main()
{
    FILE *fp = fopen("input.txt", "r");
    const int LINE_BUFF = 256;
    char line[LINE_BUFF];

    int currentElf = 1, currentCalories = 0, highestElf = 1, highestCalories = 0;

    while (fgets(line, LINE_BUFF, fp))
    {
        int number = atoi(line);
        if (number == 0)
        {
            if (currentCalories > highestCalories)
            {
                highestElf = currentElf;
                highestCalories = currentCalories;
            }
            currentElf++;
            currentCalories = 0;
            continue;
        }
        currentCalories += number;
    }

    printf("Elf with highest calories: %d\nCalorie count: %d\n", highestElf, highestCalories);

    fclose(fp);
    return 0;
}