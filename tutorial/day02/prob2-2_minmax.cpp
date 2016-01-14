#include "prob2-2_minmax.h"

// 最大値を返す
int MinMax::max(int n1, int n2, int n3){
    if(n1 > n2 && n1 > n3){
        return n1;
    }else if(n2 > n1 && n2 > n3){
      return n2;
    }else return n3;
}

//最小値を返す
int MinMax::min(int n1, int n2, int n3){
    return -max(-n1, -n2, -n3);
}

