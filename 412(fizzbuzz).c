/* Given an integer n, return a string array answer (1-indexed) where:
** answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
** answer[i] == "Fizz" if i is divisible by 3.
** answer[i] == "Buzz" if i is divisible by 5.
** answer[i] == i (as a string) if none of the above conditions are true.
**
**
** Example 1:
**
** Input: n = 3
** Output: ["1","2","Fizz"]
** Example 2:
**
** Input: n = 5
** Output: ["1","2","Fizz","4","Buzz"]
** Example 3:
**
** Input: n = 15
** Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
**
**
** Constraints:
**
** 1 <= n <= 10^4
*/

/*------ SOLUTION 1 ------*/

#include <stdio.h>
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) 
{
    char **answer;
    int i;

    answer = (char**)malloc(n * sizeof(char*));
    if (!answer)
        return NULL;
    i = 1;
    while(i <= n)
    {
        if (i % 3 == 0 && i % 5 == 0) {
            answer[i - 1] = "FizzBuzz";
        } else if (i % 3 == 0) {
            answer[i - 1] = "Fizz";
        } else if (i % 5 == 0) {
            answer[i - 1] = "Buzz";
        } else {
            char* num = (char*)malloc(10 * sizeof(char));
            if (!num)
                return NULL;
            sprintf(num, "%d", i);
            answer[i - 1] = num;
        }
        i++;
    }
    *returnSize = n;
    return answer;
}

/*------ SOLUTION 2 ------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize) {
    char **answer; 
    int i;

    answer = (char**)malloc(n * sizeof(char*));
    if (!answer)
        return NULL;
    i = 1;
    while (i <= n) {
        answer[i - 1] = (char*)malloc(9 * sizeof(char));
        if (!answer[i - 1])
            return NULL;
        answer[i - 1][0] = '\0';
        if (i % 3 == 0)
            strcat(answer[i - 1], "Fizz");
        if (i % 5 == 0)
            strcat(answer[i - 1], "Buzz");
        if (strlen(answer[i - 1]) == 0)
            sprintf(answer[i - 1], "%d", i);
        i++;
    }
    *returnSize = n;
    return answer;
}

/*------ MAIN ------*/
int main() {
    int n;
    int returnSize;
    int i;
    char **result;

    n = 15;
    result = fizzBuzz(n, &returnSize);
    i = 0;
    while (i < returnSize) {
        printf("%s ", result[i]);
        i++;
    }
    printf("\n");
    return 0;
}
