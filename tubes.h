#ifndef TUBES_STD_TUBES_H
#define TUBES_STD_TUBES_H
#define nextM(P) P->nextM
#define nextD(P) P->nextD
#define nextR(P) P->nextR
#define infoM(P) P->infoM
#define infoD(P) P->infoD
#define rel(P) P->rel
#define link(P) P->link
#define first_Matkul(L) L.first_Matkul
#define first_Dosen(L) L.first_Dosen
#define last_Matkul(L) L.last_Matkul
#define last_Dosen(L) L.last_Dosen
#define NIL NULL

#include <iostream>
#include <cstddef>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;

typedef string infotype;
typedef struct mataKuliah *address_matKul;
typedef struct relasi *address_relasi;
typedef struct Dosen *address_Dosen;

struct mataKuliah{
    infotype infoM;
    address_matKul nextM;
    address_relasi rel;
};
struct relasi{
    address_relasi nextR;
    address_Dosen link;
};
struct Dosen{
    infotype infoD;
    address_Dosen nextD;
};
struct multiList{
    address_matKul first_Matkul;
    address_matKul last_Matkul;
    address_Dosen first_Dosen;
    address_Dosen last_Dosen;
};

void createList(multiList &L);
address_matKul allocatedMatkul(infotype X);
address_Dosen allocatedDosen(infotype X);
address_relasi allocatedRel();
void insertMatkul(address_matKul P, multiList &L);
void insertDosen(address_Dosen P, multiList &L);
address_matKul searchMatkul(infotype X,multiList L);
address_Dosen searchDosen(infotype X,multiList L);
bool cekRelasi(address_matKul M, address_Dosen D);
void addRelasi(multiList &L);
void tambahDosen(multiList &L);
void tambahMatkul(multiList &L);
void HapusMatkul(multiList &L);
void HapusRelasi(address_matKul &M, address_Dosen D);
void HapusDosen(multiList &L);
void TampilMataKuliahDanDosennya(multiList L);
void tampilPengajarMatkulterbanyak(multiList L);
void tampilPengajarMatkul(multiList L);
int cek3matkul(address_matKul M, address_Dosen D);
void tampilDosen3Matkul(multiList L);
void tampilSemuaMatkul(multiList L);
void tampilSemuaDosen(multiList L);
void menuHapusRelasi(multiList &L);
#endif //TUBES_STD_TUBES_H
