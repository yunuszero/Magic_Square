#include<iostream>
using namespace std;
const int N = 15;
int n, num[N][N], temp, x[1010];
bool check = true;
int sumV[N], sumH[N], sumD, sumU;

int main() {
    scanf_s("%d", &n);
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            scanf_s("%d", &num[i][j]);
            sum += num[i][j];
            x[num[i][j]]++;
        }
        if (i == 1) {
            temp = sum;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sumV[i] += num[i][j];
            sumH[i] += num[j][i];
            if (x[num[i][j]] > 1) {
                check = false;
                break;
            }
        }
        if (sumV[i] != temp || sumH[i] != temp) {
            check = false;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i) {
                sumD += num[i][j];
                sumU += num[j][i];
            }
        }
    }

    if (sumD != temp || sumU != temp)
        check = false;

    if (check) printf("Yes");
    else printf("No");

    return 0;
}