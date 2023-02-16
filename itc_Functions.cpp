#include "sortic.h"

int itc_len(string str){
    long long kol = 0;
    for(long long i = 0; str[i] != '\0'; i++){
        kol++;
    }
    return kol;
}

long long itc_toInt(string s){
    long long num = 0;
    for(long long i = 0; i < itc_len(s); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            return 0;
        num += s[i] - 48;
        num *= 10;
    }
    num /= 10;
    return num;
}
