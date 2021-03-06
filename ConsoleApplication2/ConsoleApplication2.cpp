// ConsoleApplication2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include"pch.h"
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define n 200
#define best_solution 29437

int main(void) {
  int i,j;
  int m=0;
  int md=0;
  double x[n];
  double y[n];
  int p[n];
  int rp = 0;
  bool frag1[n];
  FILE *fp;
  unsigned int now = (unsigned int)time(0);
  srand(now);
  if (fopen_s(&fp, "kroB200.tsp", "r") != 0){
	  puts("a file can not open");
	  exit(1);
  }

  for(i=0;i<n;i++){
	fscanf_s(fp,"%*lf %lf %lf",&x[i],&y[i]);
  }
  fclose(fp);

  for(i=0;i<n;i++){
	p[i]=0;
	frag1[i]=false;
  }

  p[0]=rand()%200+1;
  frag1[p[0]-1]=true;
  for(j=0;j<n-1;j++){
	  minimum_distance(frag1, x, y, p, n, j, &m, &md);
	if (j != n - 1) {
		p[j + 1] = m + 1;
		frag1[p[j + 1] - 1] = true;
	}
  }

  FILE *fp1;
  if (fopen_s(&fp1, "nearest_close.tsp", "w") != 0) {
	  puts("a file can not open.");
  }
  for(j=0;j<n;j++){
	fprintf(fp1,"%d %f %f\n",p[j],x[p[j]-1],y[p[j]-1]);
  }
  fprintf(fp1,"%d %lf %lf\n",p[0],x[p[0]-1],y[p[0]-1]);
  fclose(fp1);
  
  printf("%d\n", measure(p, x, y, n));

  for (i = 0,j=0;i < 100;i++) {
	  if (two_opt(p, x, y, n)) {
		  measure(p, x, y, n);
	  }
	  printf("%d\n", measure(p, x, y, n));
  }

  FILE *fp2;
  
  if (fopen_s(&fp2, "nearest_close_two_opt.tsp", "w") != 0) {
	  puts("a file do not open.");
  }

  FILE *fp3;
  if (fopen_s(&fp3, "nearest_opt_error_ration.tsp", "w") != 0) {
	  puts("a file can not open.");
  }

  for (j = 0;j < n;j++) {
	  fprintf(fp2, "%d %lf %lf\n", p[j], x[p[j] - 1], y[p[j] - 1]);
	  fprintf(fp3, "%d %lf", j, (double)((measure(p, x, y, n) - best_solution) / best_solution));
  }
  fprintf(fp2, "%d %lf %lf\n", p[0], x[p[0] - 1], y[p[0] - 1]);
  fclose(fp2);
  fclose(fp3);
  
  return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
