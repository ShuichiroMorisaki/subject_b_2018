// pch.cpp: プリコンパイル済みヘッダーに対応するソース ファイル。コンパイルが正常に実行されるために必要です

#include "pch.h"
#include<stdio.h>
#include <math.h>
#include <stdlib.h>

int distance(double x1, double y1, double x2, double y2) {
	double dx = pow(x1 - x2, 2.0);
	double dy = pow(y1 - y2, 2.0);
	return (int)(sqrt(dx + dy) + 0.5);
}

int distance2(int *p, double *x, double *y, int i,int k) {
	double dx = pow(x[p[i]-1] - x[p[k]-1], 2.0);
	double dy = pow(y[p[i]-1] - y[p[k]-1], 2.0);
	return (int)(sqrt(dx + dy) + 0.5);
}

void swap(int *p, int b, int a) {
	int j = *(p + b);
	*(p + b) = *(p + a);
	*(p + a) = j;
}

void minimum_distance(bool *frag1, double *x, double *y,int *p,int n,int j,int *m,int *md) {
	int i;
	bool frag = false;
	for (i = 0;i < n;i++) {
		if (frag == false && frag1[i] == false) {
			*md = distance(x[p[j] - 1], y[p[j] - 1], x[i], y[i]);
			*m = i;
			frag = true;
		}
		else if (frag == 0 && frag1[i] == true) {
			;
		}
		else if (frag1[i] == false) {
			if (*md > distance(x[p[j] - 1], y[p[j] - 1], x[i], y[i])) {
				*md = distance(x[p[j] - 1], y[p[j] - 1], x[i], y[i]);
				*m = i;
			}
		}
	}
}

void renew_array(int *p, int *last, int c) {
	int *dest;
	for (dest = last - 1;dest >= p;dest--) {
		*(dest + 1) = *dest;
	}
	*p = c;
}

bool random() {
	if (rand() % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool two_opt(int *p,double *x,double *y,int n) {
	int i, k, b, a;
	int m, l;
	bool frag = false;
	
	for (m = 0;m < n-2;m++) {
		for (l = m + 3;l < n+1;l++) {
			b = distance2(p, x, y, m, m + 1) + distance2(p, x, y, (l - 1)%n, l%n);
			a = distance2(p, x, y, m, (l - 1)%n) + distance2(p, x, y, m + 1, l%n);
			if (b > a) {
				i = m;
				k = l;
				frag = true;
				goto OUT;
			}
		}
	}
OUT:
	if (frag) {
		if ((k - i) % 2 == 0) {
			do {
				i++;
				k--;
				swap(p, i%n, k%n);
			} while ((k - i) != 2);
		}
		else if ((k-i) % 2 == 1) {
			do{
				i++;
				k--;
				swap(p, i%n, k%n);
			} while ((k - i) != 1);
		}
		else {
			;
		}
	}
	else {
		;
	}
	return frag;
}

int measure(int *p,double *x,double *y,int n) {
	int i,m=0;
	for (i = 0; i < n - 1; i++) {
		m += distance2(p, x, y, i, i + 1);
	}
	return m;
}

void create_graph(double *x, double *y,int n) {
	int i,j;
	bool flag = true;

	for (i = 0;i < n;i++) {
		while (flag) {
			*(x + i) = (double)(rand() % 1000);
			*(y + i) = (double)(rand() % 1000);
			flag = false;
			for (j = 0;j < i;j++) {
				if (*(x + j) == *(x + i) && *(y + j) == *(y + i)) {
					flag = true;
					break;
				}
			}
		}
		flag = true;
	}
}

void necklace_permutation_recursive(int *p, bool *used, int n, int m, bool cond) {
	bool flag = true;
	if (m == n) {
		//puts("b");
		flag = false;
		for (int i = 0;i < n;i++) {
			printf("%d,%d\n", p[i],i);
		}
		puts("end");
	}
	if (flag) {
		for (int i = 1;cond ? i <= n / 2  : i < n ;i++) {
			if (*(used + i)) {
				continue;
			}
			//printf("%d,%d\n",i,m);
			*(p + m) = i;
			used[i] = true;
			necklace_permutation_recursive(p, used, n, m + 1, false);
			used[i] = false;
		}
	}
}


void necklace_permutation(int *p, bool *used, int n, int m, bool cond) {
	bool flag = true;
	if (m == n) {
		//puts("b");
		flag = false;
	}
	if (flag) {
		for (int i = 1;i <= n / 2;i++) {
			if (*(used + i)) {
				continue;
			}
			//printf("%d,%d\n",i,m);
			*(p + m) = i;
			used[i] = true;
			necklace_permutation_recursive(p, used, n, m + 1, i == n / 2 && n % 2 == 0 ? true : false);
			used[i] = false;
		}
	}
}

void enumerate(int *p, double *x, double *y, int n) {
	*(p + 0) = 0;
}
// 一般に、このファイルは無視できますが、プリコンパイル済みヘッダーを使用している場合は保持します。
