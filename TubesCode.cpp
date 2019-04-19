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
    tampilSemuaDosen(L);
    cout<<"Masukkan nama Dosen : ";cin>>nama;
    while(P != NIL && infoD(P)!=nama){
        P = nextD(P);
    }
    if (P==NIL || infoD(P)!=nama) {
        P = allocatedDosen(nama);
        insertDosen(P, L);
        cout<<"\n[+] Dosen atas nama "<<nama<<" berhasil di tambahkan\n";
    }else if (infoD(P)==nama){
        cout<<"\n[!] Dosen atas nama "<<nama<<" sudah terdaftar\n";
    }
    getch();
}
void tambahMatkul(multiList &L){
    infotype nama;
    address_matKul P = first_Matkul(L);
    tampilSemuaMatkul(L);
    cout<<"Masukkan nama Mata Kuliah : ";cin>>nama;
    while(P != NIL && infoM(P)!=nama){
        P = nextM(P);
    }
    if (P==NIL || infoM(P)!=nama) {
        P = allocatedMatkul(nama);
        insertMatkul(P, L);
        cout<<"\n[+] Mata Kuliah "<<nama<<" berhasil di tambahkan\n";
    }else if (infoM(P)==nama){
        cout<<"\n[!] Mata Kuliah "<<nama<<" sudah terdaftar\n";
    }
    getch();
}
void addRelasi(multiList &L){
    infotype input;
    address_matKul P = first_Matkul(L);
    address_Dosen Q = first_Dosen(L);
    bool valid = false;
    if (P==NIL || Q==NIL){
        if (P!=NIL && Q==NIL){
            cout<<"\n[!] Tidak ada Dosen yang tersedia";
        }else if (P==NIL && Q!=NIL){
            cout<<"\n[!] Tidak ada Mata kuliah yang tersedia";
        }else{
            cout<<"\n[!] Dosen dan Mata kuliah tidak tersedia";
        }
        getch();
    }else{
        while (!valid){
            tampilSemuaMatkul(L);
            cout<<"Masukkan nama Mata kuliah ('exit' untuk kembali): "; cin>>input;
            P = searchMatkul(input,L);
            if (input == "exit" || P != NIL){
                valid = true;
            }else {
                cout<<"[!] Mata kuliah tidak tersedia";
                getch();
            }
        }
        valid = false;
        while (!valid && input != "exit"){
            tampilSemuaDosen(L);
            cout<<"Masukkan nama Dosen ('exit' untuk kembali): "; cin>>input;
            Q = searchDosen(input,L);
            if (input == "exit" || Q != NIL){
                valid = true;
            }else{
                cout<<"[!] Dosen tidak tersedia";
                getch();
            }
        }
        if (input != "exit"){
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
                cout<<"\n[+] Berhasil menghubungkan";
            }else{
                cout<<"\n[!] Dosen atas nama "<<infoD(Q)<<" sudah mengajar mata kuliah "<<infoM(P);
            }
            getch();
        }
    }
}
void HapusMatkul(multiList &L) {
    infotype nama;
    address_matKul P = first_Matkul(L);
    if (P!=NIL){
        tampilSemuaMatkul(L);
        cout<<"Mata kuliah yang akan dihapus : ";
        cin>>nama;
        P = searchMatkul(nama, L);
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
            cout<<"\n[!] Mata kuliah berhasil di hapus";
        } else {
            cout<<"\n[!] Mata kuliah tidak tersedia";
        }
    }else{
        cout<<"\n[!] Mata kuliah kosong";
    }
    getch();
}
void tampilPengajarMatkul(multiList L) {
    infotype nama;
    address_matKul P = first_Matkul(L);
    if (P!=NIL){
        tampilSemuaMatkul(L);
        cout<<"Masukkan nama Mata kuliah : ";
        cin>>nama;
        P = searchMatkul(nama, L);
        if (P != NIL) {
            address_relasi Q = rel(P);
            if (Q != NIL) {
                cout << "\n[*] Dosen yang mengajar mata kuliah " << infoM(P) << " : \n";
                int i = 0;
                while (Q != NIL) {
                    if (link(Q) != NIL) {
                        i += 1;
                        cout << i << ". " << infoD(link(Q)) << endl;
                    }
                    Q = nextR(Q);
                }
            }else{
                cout<<"\n[!] Tidak ada dosen yang mengajar Mata kuliah ini";
            }
        } else {
            cout<<"\n[!] Mata kuliah tidak tersedia";
        }
    }else{
        cout<<"\n[!] Tidak ada mata kuliah yang tersedia";
    }
    getch();
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
    address_Dosen P = first_Dosen(L);
    if (P!=NIL){

        cout<<"Nama dosen yang akan dihapus : ";
        cin>>nama;
        P = searchDosen(nama, L);
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
            cout<<"\n[-] Dosen berhasil di hapus";
            delete P;
        } else {
            cout<<"\n[!] Dosen tidak ditemukan";
        }
    }else{
        cout<<"\n[!] Dosen kosong";
    }
    getch();
}
void TampilMataKuliahDanDosennya(multiList L){
    address_matKul P = first_Matkul(L);
    if (P!=NIL) {
        cout<<endl;
        while (P != NIL) {
            cout << "Mata Kuliah : " << infoM(P) << "\n";
            cout << "  [*] Dosen : ";
            address_relasi R = rel(P);
            if (R != NIL) {
                while (R != NIL) {
                    address_Dosen D = link(R);
                    if (D != NIL) {
                        cout << infoD(D) << ", ";
                    }
                    R = nextR(R);
                }
            } else {
                cout << "Tidak ada.";
            }
            cout<<endl;
            P = nextM(P);
        }
    }else{
        cout<<"\n[!] Tidak ada mata kuliah yang tersedia";
    }
    getch();
}
void tampilPengajarMatkulterbanyak(multiList L) {
    address_matKul M = first_Matkul(L);
    address_matKul Maks;
    address_relasi R;
    int MAX = 0;
    if (M!=NIL) {
        tampilSemuaMatkul(L);
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
            cout <<"[*] Mata kuliah yang diajarkan oleh sebagian besar dosen adalah " << infoM(Maks);
        else
            cout<<"[!] Semua Mata kuliah tidak mempunyai Dosen pengajar";
    }
    else
        cout<<"\n[!] Tidak ada Mata kuliah yang tersedia";
    getch();
}
int cek3matkul(address_matKul M, address_Dosen D){
    int count = 0;
    while (M!=NIL){
        if (cekRelasi(M,D)){
            count += 1;
        }
        M = nextM(M);
    }
    return count;
}
void tampilDosen3Matkul(multiList L){
    address_Dosen D = first_Dosen(L);
    address_matKul M = first_Matkul(L);
    if (D!=NIL){
        int i = 0;
        if (M!=NIL) {
            cout<<endl;
            cout << "Dosen yang mengajar lebih dari tiga kursus : \n";
            do {
                if (cek3matkul(M, D) > 3) {
                    i += 1;
                    cout << i << ". " << infoD(D) << endl;
                }
                D = nextD(D);
            } while (D != NIL);
            if (i == 0)
                cout << "\n[!] Tidak ada";
        } else
            cout<<"\n[!] Tidak ada Mata kuliah yang tersedia";
    }else{
        cout<<"\n[!] Tidak ada Dosen yang tersedia";
    }
    getch();
}
void tampilSemuaMatkul(multiList L){
    address_matKul M = first_Matkul(L);
    int i = 0;
    if (M!=NIL){
        cout<<"\nMata kuliah yang terdaftar :\n";
        do{
            i += 1;
            cout<<i<<". "<<infoM(M)<<endl;
            M = nextM(M);
        }while (M!=NIL);
        cout<<endl;
    }
}
void tampilSemuaDosen(multiList L){
    address_Dosen D = first_Dosen(L);
    int i = 0;
    if (D!=NIL){
        cout<<"\nDosen yang terdaftar :\n";
        do{
            i += 1;
            cout<<i<<". "<<infoD(D)<<endl;
            D = nextD(D);
        }while (D!=NIL);
        cout<<endl;
    }
}
