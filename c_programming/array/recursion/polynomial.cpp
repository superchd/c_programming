#include <cstdio>
#include <stdbool.h>
#include <iostream>
#define N 100000000

using namespace std;

int             n;

void    my_input(void){
        cin >> n;
        return;
}

bool    check(long long int num){
        long long int fin;

        fin = num * num + num;
        if (fin > n) {return (true);}
        else             {return (false);}
}

void    my_sol(void){

        int               start = 1;
        long long int end   = N;
        long long int mid;

        while (start + 1 < end){
                mid = (start + end) / 2;
                if (check(mid)) end   = mid;
                else                    start = mid;
        }
        cout << start << endl;
        return ;

}

int     main(){
        my_input();
        my_sol();
        return 0;
}
