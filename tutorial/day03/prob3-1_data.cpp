#include "prob3-1_data.h"

void CData::init(){
    number=0;
    comment = "";
}

void CData::setNumber(int n){
    number = n;
}

void CData::setComment(string s){
    comment = s;
}

int CData::getNumber(){
    return number;
}

string CData::getComment(){
    return comment;
}

