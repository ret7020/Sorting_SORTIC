#include "sortic.h"

void ra(vector<int> &a){
    int buffer;
    if(a.size() > 1){
        buffer = a[a.size() - 1];
        for(long long i = a.size() - 1; i > 0; i--){
            a[i] = a[i - 1];
        }
        a[0] = buffer;
    }
}

void rb(vector<int> &b){
    ra(b);
}

void rr(vector<int> &a, vector<int> &b){
    ra(a);
    rb(b);
}
