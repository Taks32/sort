#include <stdio.h>

// フェルマー素数
#define N ((1<<16)+1)

int A[N];

/*
A[0], A[1], ..., A[n-1] の中でk+1番目に小さい値を返す関数
ただし、Aの中身は書き換えてしまう。
*/
int quick_select(int A[], int n, int k){
  int h, i, j, tmp, pivot;

// 先頭の要素をピボットとする
  pivot = A[0];
  for(h = i = j = 1; i < n; i++){
    if(A[i] < pivot){
      tmp = A[j];
      A[j] = A[i];
      A[i] = tmp;
      j++;
    }else if (A[i] == pivot) {
      A[i] = A[j];
      A[j] = A[h];
      h++;
      j++;
    }
  }

  if(j - h < k + 1 && k + 1 <= j) return pivot;
  else if(j < k+1) return quick_select(A+j, n-j, k-j);
  else return quick_select(A+h, j-h, k);
}

int main(){
  int i;
  A[0] = 0;
  A[1] = 3; //原始元
  for(i=2;i<N;i++){
    A[i] = (long long int) A[i-1] * A[1] % N;
  }

// すべての要素が同じ場合でも計算が早く終わるか確認する
  for(i=0;i<N;i++){
    if(quick_select(A, N, i) != i) printf("%d th element is %d\n", i, quick_select(A, N, i));
  }
}
