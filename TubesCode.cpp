//
// Created by jesbuz on 17/04/19.
//
#include "tubes.h"

void createList(multiList &L){
    first_Matkul(L) = NIL;
    first_Dosen(L) = NIL;
}
address_matKul allocatedMatkul(infotype X){
    auto P = new mataKuliah;
    infoM(P) = X;
    nextM(P) = NIL;
    rel(P) = NIL;
    return  P;
}
address_Dosen allocatedDosen(infotype X){
    auto P = new Dosen;
    infoD(P) = X;
    nextD(P) = NIL;
    return P;
}
address_relasi allocatedRel(){
    auto P = new relasi;
    nextR(P) = NIL;
    link(P) = NIL;
    return P;
}
void insertMatkul(address_matKul P, multiList &L){
    if (first_Matkul(L)==NIL){
        first_Matkul(L) = P;
        last_Matkul(L) = P;
    } else {
        address_matKul Q = last_Matkul(L);
        nextM(Q) = P;
        last_Matkul(L) = P;
    }
}
void insertDosen(address_Dosen P, multiList &L){
    if (first_Dosen(L)==NIL){
        first_Dosen(L) = P;
        last_Dosen(L) = P;
    }else{
        address_Dosen Q = last_Dosen(L);
        nextD(Q) = P;
        last_Dosen(L) = P;
    }
}
address_matKul searchMatkul(infotype X,multiList L){
    auto P = first_Matkul(L);
    while (infoM(P)!=X && P!=NIL)
        P = nextM(P);
    return P;
}
address_Dosen searchDosen(infotype X,multiList L){
    auto P = first_Dosen(L);
    while (infoD(P)!=X && P!=NIL)
        P = nextD(P);
    return P;
}
bool cekRelasi(address_matKul M, address_Dosen D){
    bool valid = false;
    address_relasi R = rel(M);
    while (R != NIL && link(R)!=D){
        R = nextR(R);
    }
    if (link(R)==D)
        valid = true;
    return valid;
}
void addRelasi(multiList &L){
    infotype input;
    address_matKul P;
    address_Dosen Q;
    bool valid = false;
    while (!valid){
        cout<<"Masukkan nama Mata kuliah (kosongkan untuk kembali): "; cin>>input;
        P = searchMatkul(input,L);
        if (input == "" || P != NIL){
            valid = true;
        }else {
            cout<<"Mata kuliah tidak tersedia.\n";
        }
    }
    valid = false;
    while (!valid && input != ""){
        cout<<"Masukkan nama Dosen (kosongkan untuk kembali): "; cin>>input;
        Q = searchDosen(input,L);
        if (input == "" || Q != NIL){
            valid = true;
        }else{
            cout<<"Dosen tidak tersedia.\n";
        }
    }
    if (input != ""){
        if (!cekRelasi(P,Q)){
            address_relasi R = allocatedRel();
            if (rel(P)==NIL) {
                rel(P) = R;
            }else{
                address_relasi relation = rel(P);
                while (nextR(relation)!=NIL){
                    relation = nextR(relation);
                }
                nextR(relation) = R;
            }
            link(R) = Q;
            cout<<"Berhasil menghubungkan.\n";
        }else{
            cout<<"Dosen atas nama "<<infoD(Q)<<" sudah mengajar mata kuliah "<<infoM(P)<<"\n";
        }
    }


}