#include <stdio.h>

// 素数
#define N 2999

int A[N];

// *p と *q の値を入れ替える関数
void swap(int *p, int *q) {
  int tmp;
  tmp = *p;
  *p = *q;
  *q = tmp;
}

int bubble(int A[], int n, int k) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (A[i] > A[j]) {
        swap(A + i, A + j);
      }
    }
  }
  return A[k];
}

int quick_select(int A[], int n, int k) {
  int i, j, pivot;

  if (n <= 5) {
    return bubble(A, n, k);
  } else {
    int Aa[N];
    for (int i = 0; i < n / 5; i++) {
      Aa[i] = bubble(A + i * 5, 5, 2);
    }
    pivot = quick_select(Aa, n / 5, n / 10);
    j = 0;
    for (i = 0; i < n; i++) {
      if (A[i] <= pivot) {
        swap(A + i, A + j);
        j++;
      }
    }
    if (j == k + 1) {
      return pivot;
    } else if (j < k + 1) {
      return quick_select(A + j, n - j, k - j);
    } else {
      return quick_select(A, j, k);
    }
  }
}

int main() {
  int i;
  A[0] = 0;
  A[1] = 17; //原始元
  for (i = 2; i < N; i++) {
    A[i] = (long long int)A[i - 1] * A[1] % N;
  }
  for (i = 0; i < N; i++) {
    if (quick_select(A, N, i) != i)
      printf("ERROR %d %d\n", i, quick_select(A, N, i));
    //    printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
