// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

#ifndef PCH_H
#define PCH_H

// TODO: ここでプリコンパイルするヘッダーを追加します
int distance(double x1, double y1, double x2, double y2);

int distance2(int *p,double *x, double *y, int i, int k);

void swap(int *p, int a, int b);

void minimum_distance(bool *frag1, double *x, double *y, int *p, int n, int j,int *m,int *md);

void renew_array(int *p,int *last,int c);

bool random();

bool two_opt(int *p,double *x,double *y,int n);

int measure(int *p, double *x, double *y, int n);

void create_graph(double *x, double *y,int n);

void necklace_permutation_recursive(int *p, bool *used, int n, int m, bool cond);

void necklace_permutation(int *p, bool *used, int n, int m, bool cond);

void enumerate(int *p, double *x, double *y, int n);
#endif //PCH_H
