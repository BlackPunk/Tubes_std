#include "tubes.h"

int main() {
    multiList L;
    createList(L);
    int Pil= -1;
    while (Pil != 99){
        system("CLS");
        cout<<"1. Tambahkan Mata Kuliah\n";
        cout<<"2. Tambahkan Dosen\n";
        cout<<"3. Hubungkan Dosen dengan Mata Kuliah\n";
        cout<<"4. Hapus Mata Kuliah\n";
        cout<<"5. Hapus Dosen\n";
        cout<<"6. Menampilkan semua Mata kuliah beserta dosennya\n";
        cout<<"7. Menampilkan Mata kuliah yang diajarkan sebagian besar Dosen\n";
        cout<<"8. Menampilkan Dosen yang mengajar mata kuliah tertentu\n";
        cout<<"9. Menampilkan Dosen yang mengajar lebih dari tiga kursus\n";
        cout<<"99. Keluar\n";
        cout<<"Masukkan Pilihan : ";cin>>Pil;
        switch (Pil){
            case 1:
                tambahMatkul(L);
                break;
            case 2:
                tambahDosen(L);
                break;
            case 3:
                addRelasi(L);
                break;
            case 4:
                HapusMatkul(L);
                break;
            case 5:
                HapusDosen(L);
                break;
            case 6:
                TampilMataKuliahDanDosennya(L);
                break;
            case 7:
                tampilPengajarMatkulterbanyak(L);
                break;
            case 8:
                tampilPengajarMatkul(L);
                break;
            case 9:
                tampilDosen3Matkul(L);
                break;
            case 99:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                getch();
        }
    }
    return 0;
}
