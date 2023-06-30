#include <stdio.h>

typedef long long ll;

void solve(int n, int m){
      int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i + j) % 2 == 0) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

// Do not edit the following code.
int main() {
  ll n,m;
  scanf("%lld %lld", &n, &m);
  solve(n, m);
  return 0;
}
