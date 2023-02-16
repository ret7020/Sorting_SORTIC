#include "sortic.h"

void rra(vector<int> &a){
    int buffer;
    if(a.size() > 1){
        buffer = a[0];
        for(long long i = 0; i < a.size() - 1; i++){
            a[i] = a[i + 1];
        }
        a[a.size() - 1] = buffer;
    }
}

void rrb(vector<int> &b){
    rra(b);
}

void rrr(vector<int> &a, vector<int> &b){
    rra(a);
    rrb(b);
}
