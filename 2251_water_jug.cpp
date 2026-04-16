// BOJ 2251 물통 | 그래프 탐색, BFS, 상태 탐색 | 2018-10-06 11:23:57
#include<stdio.h>

int A,B,C;
int ck[211][211][211];
void water(int &x,int &y,int &z,int X,int Y,int Z){
    if(x+y<=Y)y = x+y, x = 0;
    else x = (x+y)-Y, y = Y;
}
void dfs(int a,int b,int c){
    if(ck[a][b][c])return;
    ck[a][b][c]=1;
    int aa,bb,cc;
    aa=a;bb=b,cc=c;
    water(aa,bb,cc,A,B,C);
    dfs(aa,bb,cc);
    aa=a;bb=b,cc=c;
    water(aa,cc,bb,A,C,B);
    dfs(aa,bb,cc);
    aa=a;bb=b,cc=c;
    water(bb,aa,cc,B,A,C);
    dfs(aa,bb,cc);
    aa=a;bb=b,cc=c;
    water(bb,cc,aa,B,C,A);
    dfs(aa,bb,cc);
    aa=a;bb=b,cc=c;
    water(cc,aa,bb,C,A,B);
    dfs(aa,bb,cc);
    aa=a;bb=b,cc=c;
    water(cc,bb,aa,C,B,A);
    dfs(aa,bb,cc);
}
int ans[211];
int main(){
    scanf("%d%d%d",&A,&B,&C);
    dfs(0,0,C);
    int i,j,k;
    for(i=0;i<=200;i++){
        for(j=0;j<=200;j++){
            if(ck[0][i][j])ans[j]=1;
        }
    }
    for(i=0;i<=200;i++)if(ans[i])printf("%d ",i);
    return 0;
}
