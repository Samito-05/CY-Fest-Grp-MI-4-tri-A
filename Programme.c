#include <stdio.h>

int coefbi(int n,int p){
  if(p==0){
    return 1;
  }
  if(p==n){
    return 1;
  }
  else{
    return coefbi(n-1,p-1) + coefbi(n-1,p);
  }
}

int main(){
  printf("%d\n",coefbi(10,3));
  printf("roms");
  return 0;
}
//caca prout