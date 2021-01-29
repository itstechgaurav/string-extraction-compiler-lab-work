#include <stdio.h>
#include<string.h>

int isop(char op) {
  char ops[] = "+-*/!&<>=%|";
  int res = 0, i = 0;
  while(ops[i]) if(ops[i++] == op) res = 1;
  return res;
}

int isnum(char n) {
  return n >= '0' && n <= '9';
}

int ischar(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    char mystr[200], substr[200];
    int identifiers = 0, others = 0, numbers = 0, operators = 0, ch = 0, si = 0;
    int counts[6] = {0};
    printf("Enter a string: \n");
    gets(mystr);
    strcat(mystr, " ");
    while(mystr[ch]) {
        char current = mystr[ch];
        if(current != ' ') {
            if(ischar(current)) identifiers = 1;
            else if(isnum(current)) numbers = 1;
            else if(isop(current)) operators = 1;
            else others = 1;
            substr[si] = current;
            si++;
        } else {
            char msg[200];
            int isidenti = (identifiers || numbers) && (ischar(substr[0]) || substr[0] == '_') && !operators && !others;
            if(isidenti) {
              strcpy(msg, "identifiers");
              counts[0]++;
            }
            else if(numbers && (!operators && !identifiers && !others)) {
              strcpy(msg, "numbers");
              counts[1]++;
            }else if((identifiers && numbers) && !isidenti) {
              strcpy(msg, "alpha numeric");
              counts[2]++;
            }
            else if(operators && (!numbers && !identifiers && !others)) {
              strcpy(msg, "oprators");
              counts[3]++;
            }
            else {
              strcpy(msg, "others");
              counts[4]++;
            }
            substr[si] = 0;
            printf("%s - %s\n", substr, msg);
            si = current = operators = others = numbers = identifiers = 0;
            counts[5]++; // increasing spaces
        }
        ch++;
    }
    printf("\n\nTotal report:\n\n");
    printf("identifiers = %d\n", counts[0]);
    printf("numbers = %d\n", counts[1]);
    printf("alphanumeric = %d\n", counts[2]);
    printf("operators = %d\n", counts[3]);
    printf("others = %d\n", counts[4]);
    printf("spaces = %d\n", counts[5] - 1);
    return 0;
}
