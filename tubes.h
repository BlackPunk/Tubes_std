//
// Created by jesbuz on 17/04/19.
//

#ifndef TUBES_STD_TUBES_H
#define TUBES_STD_TUBES_H
#define nextM(P) P->nextM
#define nextD(P) P->nextD
#define nextR(P) P->nextR
#define prevM(P) P->prevM
#define prevD(P) P->prevD
#define infoM(P) P->infoM
#define infoD(P) P->infoD
#define relasi(P) P->relasi
#define link(P) P->link
#define first_Matkul(L) L.first_Matkul
#define first_Dosen(L) L.first_Dosen
#define NIL NULL

#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

typedef string infotype;
typedef struct mataKuliah *address_matKul;
typedef struct relasi *address_relasi;
typedef struct Dosen *address_Dosen;

struct mataKuliah{
    infotype infoM;
    address_matKul nextM;
    address_matKul prevM;
    address_relasi relasi;
};
struct relasi{
    address_relasi nextR;
    address_Dosen link;
};
struct Dosen{
    infotype infoD;
    address_Dosen nextD;
    address_Dosen prevD;
};
struct MultiList{
    address_matKul first_Matkul;
    address_Dosen first_Dosen;
};

void createList(MultiList &L);
address_matKul allocatedMatkul(infotype X);
address_Dosen allocatedDosen(infotype X);
address_relasi allocatedRel(infotype X);

#endif //TUBES_STD_TUBES_H
