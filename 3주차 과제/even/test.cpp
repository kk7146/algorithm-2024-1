#include <algorithm>
#include <math.h>
#include <iostream>
using namespace std;
int cnt;
int n = 5, r = 3, a[5] = {1, 2, 3, 4, 5};


int main(){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                cout << i << " " << j << " " << k << '\n';
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}