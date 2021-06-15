#include <stdio.h>

int main() {
    char str[1000];
    for(;;) {
        getline(str, 1000); 
        printf("格納した文字列:%s\n", str);

        if(str == "exit") {
            return 0;
        }
    }
}

void getline(char s[], int lim){  
    int c, i;   //getcharの受け取り用変数c、ループ用変数i  
      
    for (i = 0; i < lim - 1 && (c = getchar()) != '\n'; ++i)  
        s[i] = c;  
      
    s[i] = '\0';  
}  