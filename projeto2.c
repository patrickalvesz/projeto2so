#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ll long long
#define maxn 100005

int n;
int stp = 0;
int stage = 0;
int num = 0;
int a[maxn] = {0};
int b[maxn] = {0};
bool w[10] = {false};

int main() {

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    num = 1;
    for(int i = 1; i <= maxn; i++) {
        if(i == a[num]) {
            if(i >= stp){
                stp = i+10;
                stage = b[num];
            }else {
                if(stage == b[num])stp = i+10;
                else w[b[num]] = true;
            }
            num++;
        }
        if(i >= stp) {
            if(w[stage^1]){
                w[stage^1] = false;
                stage ^= 1;
                stp = i+10;
            }
        }
    }
    printf("%d\n", stp);

    return 0;
}
