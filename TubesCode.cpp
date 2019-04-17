//
// Created by jesbuz on 17/04/19.
//
#include "tubes.h"

void createList(MultiList &L){
    first_Matkul(L) = NIL;
    first_Dosen(L) = NIL;
}
address_matKul allocatedMatkul(infotype X){
    auto P = new mataKuliah;
    infoM(P) = X;
    nextM(P) = NIL;
    prevM(P) = NIL;
    relasi(P) = NIL;
    return  P;
}
address_Dosen allocatedDosen(infotype X){
    auto P = new Dosen;
    infoD(P) = X;
    nextD(P) = NIL;
    prevD(P) = NIL;
    return P;
}
address_relasi allocatedRel(){
    auto P = new relasi;
    nextR(P) = NIL;
    link(P) = NIL;
    return P;
}
