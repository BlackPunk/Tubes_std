#include "tubes.h"

void createList(multiList &L){
    first_Matkul(L) = NIL;
    first_Dosen(L) = NIL;
}
address_matKul allocatedMatkul(infotype X){
    address_matKul P = new mataKuliah;
    infoM(P) = X;
    nextM(P) = NIL;
    rel(P) = NIL;
    return  P;
}
address_Dosen allocatedDosen(infotype X){
    address_Dosen P = new Dosen;
    infoD(P) = X;
    nextD(P) = NIL;
    return P;
}
address_relasi allocatedRel(){
    address_relasi P = new relasi;
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
    address_matKul P = first_Matkul(L);
    while (P!=NIL && infoM(P)!=X )
        P = nextM(P);
    return P;
}
address_Dosen searchDosen(infotype X,multiList L){
    address_Dosen P = first_Dosen(L);
    while (P!=NIL && infoD(P)!=X )
        P = nextD(P);
    return P;
}
bool cekRelasi(address_matKul M, address_Dosen D){
    bool valid = false;
    address_relasi R = rel(M);
    while (R != NIL && !valid){
        if (link(R)==D){
            valid = true;
        }
        R = nextR(R);
    }
    return valid;
}
void tambahDosen(multiList &L){
    infotype nama;
    address_Dosen P = first_Dosen(L);
    cout<<"Masukkan nama Dosen : ";cin>>nama;
    while(P != NIL && infoD(P)!=nama){
        P = nextD(P);
    }
    if (P==NIL || infoD(P)!=nama) {
        P = allocatedDosen(nama);
        insertDosen(P, L);
        cout<<"Dosen atas nama "<<nama<<" berhasil di tambahkan...\n";
    }else if (infoD(P)==nama){
        cout<<"Dosen atas nama "<<nama<<" sudah terdaftar...\n";
    }
}
void tambahMatkul(multiList &L){
    infotype nama;
    address_matKul P = first_Matkul(L);
    cout<<"Masukkan nama Mata Kuliah : ";cin>>nama;
    while(P != NIL && infoM(P)!=nama){
        P = nextM(P);
    }
    if (P==NIL || infoM(P)!=nama) {
        P = allocatedMatkul(nama);
        insertMatkul(P, L);
        cout<<"Mata Kuliah "<<nama<<" berhasil di tambahkan...\n";
    }else if (infoM(P)==nama){
        cout<<"Mata Kuliah "<<nama<<" sudah terdaftar...\n";
    }
}
void addRelasi(multiList &L){
    infotype input;
    address_matKul P;
    address_Dosen Q;
    bool valid = false;
    while (!valid){
        cout<<"Masukkan nama Mata kuliah ('menu' untuk kembali): "; cin>>input;
        P = searchMatkul(input,L);
        if (input == "menu" || P != NIL){
            valid = true;
        }else {
            cout<<"Mata kuliah tidak tersedia.\n";
        }
    }
    valid = false;
    while (!valid && input != "menu"){
        cout<<"Masukkan nama Dosen ('menu' untuk kembali): "; cin>>input;
        Q = searchDosen(input,L);
        if (input == "menu" || Q != NIL){
            valid = true;
        }else{
            cout<<"Dosen tidak tersedia.\n";
        }
    }
    if (input != "menu"){
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
void HapusMatkul(multiList &L) {
    infotype nama;
    cout<<"Mata kuliah yang akan dihapus : ";
    cin>>nama;
    address_matKul P = searchMatkul(nama, L);
    if (P != NULL) {
        if (P == first_Matkul(L)) {
            first_Matkul(L) = nextM(P);
            nextM(P) = NIL;
        } else if (P == last_Matkul(L)) {
            address_matKul Q = first_Matkul(L);
            while (nextM(Q) != P) {
                Q = nextM(Q);
            }
            nextM(Q) = NIL;
            last_Matkul(L) = Q;
        } else {
            address_matKul Q = first_Matkul(L);
            while (nextM(Q) != P) {
                Q = nextM(Q);
            }
            nextM(Q) = nextM(P);
            nextM(P) = NIL;
        }
        delete P;
        cout<<"Mata kuliah berhasil di hapus.\n";
    } else {
        cout<<"Mata kuliah tidak ditemukan.\n";
    }
}
void tampilPengajarMatkul(multiList L) {
    infotype nama;
    cout<<"Mata kuliah yang dicari : ";
    cin>>nama;
    address_matKul P = searchMatkul(nama, L);
    if (P != NIL) {
        address_relasi Q = rel(P);
        cout<<"Dosen yang mengajar mata kuliah "<<infoM(P)<<" : \n";
        int c = 0;
        while (Q != NIL) {
            if (link(Q) != NIL) {
                c = c + 1;
                cout<<c<<". "<<infoD(link(Q))<<endl;
            }
            Q = nextR(Q);
        }
    } else {
        cout<<"Mata kuliah yang dicari tidak ditemukan.\n";
    }
}
void hapusRelasi(multiList &L,address_Dosen D){
    address_matKul M = first_Matkul(L);
    while(M!=NIL){
        if (cekRelasi(M,D)){
            address_relasi R = rel(M);
            if (link(R)==D){
                rel(M)=nextR(R);
                link(R)=NIL;
                delete R;
            }else {
                address_relasi R2 = nextR(R);
                while (link(R2) != D) {
                    R = nextR(R);
                    R2 = nextR(R2);
                }
                link(R2) = NIL;
                nextR(R) = nextR(R2);
                delete R2;
            }
        }
        M = nextM(M);
    }
}
void HapusDosen(multiList &L) {
    infotype nama;
    cout<<"Nama dosen yang akan dihapus : ";
    cin>>nama;
    address_Dosen P = searchDosen(nama, L);
    hapusRelasi(L,P);
    if (P != NULL) {
        if (P == first_Dosen(L)) {
            first_Dosen(L) = nextD(P);
            nextD(P) = NIL;
        } else if (P == last_Dosen(L)) {
            address_Dosen Q = first_Dosen(L);
            while (nextD(Q) != P) {
                Q = nextD(Q);
            }
            nextD(Q) = NIL;
            last_Dosen(L) = Q;
        } else {
            address_Dosen Q = first_Dosen(L);
            while (nextD(Q) != P) {
                Q = nextD(Q);
            }
            nextD(Q) = nextD(P);
            nextD(P) = NIL;
        }
        cout<<"Dosen berhasil di hapus.\n";
        delete P;
    } else {
        cout<<"Dosen tidak ditemukan.\n";
    }
}
void TampilMataKuliah(multiList L){
    address_matKul P = first_Matkul(L);
    if (P!=NIL) {
        while (P != NIL) {
            cout << "Mata Kuliah : " << infoM(P) << "\n";
            cout << "Dosen : ";
            address_relasi R = rel(P);
            if (R != NIL) {
                while (R != NIL) {
                    address_Dosen D = link(R);
                    if (D != NIL) {
                        cout << infoD(D) << ", ";
                    }
                    R = nextR(R);
                }
                cout<<endl;
            } else {
                cout << "Tidak ada.\n";
            }
            P = nextM(P);
        }
    }else{
        cout<<"Tidak ada mata kuliah yang tersedia.\n";
    }
}
void tampilPengajarMatkulterbanyak(multiList L) {
    address_matKul M = first_Matkul(L);
    address_matKul Maks;
    address_relasi R;
    int MAX = 0;
    if (M!=NIL) {
        while (M != NIL) {
            int Count = 0;
            R = rel(M);
            while (R != NIL) {
                Count += 1;
                R = nextR(R);
            }
            if (Count > MAX) {
                MAX = Count;
                Maks = M;
            }
            M = nextM(M);
        }
        if (MAX > 0)
            cout <<"Mata kuliah yang diajarkan oleh sebagian besar dosen adalah " << infoM(Maks) << endl;
        else
            cout<<"Semua Mata kuliah tidak mempunyai Dosen pengajar.\n";
    }
    else
        cout<<"Tidak ada Mata kuliah yang tersedia.\n";
}

