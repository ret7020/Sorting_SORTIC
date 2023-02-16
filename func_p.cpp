#include "sortic.h"

void pa(vector<int> &a, vector<int> &b)
{
    int a1 = a.size(), b1 = b.size();
    vector<int> del;
    vector<int> newA;
    if(b1 > 0){
        newA.push_back(b[0]);
        for(int i = 0; i < a1; i++)
            newA.push_back(a[i]);
        for(int i = 1; i < b1; i++)
            del.push_back(b[i]);
        b = del;
        a = newA;
    }
}

void pb(vector<int> &b, vector<int> &a)
{
    pa(b, a);
}


