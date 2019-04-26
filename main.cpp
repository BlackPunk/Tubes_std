#include "tubes.h"

int main() {
    multiList L;
    createList(L);
    int Pil;
    do{
        system("CLS");
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"|                    *  SISTEM PERKULIAHAN  *                       |\n";
        cout<<"+-------------------------------------------------------------------+\n";
        cout<<"| 1.  Tambahkan Matakuliah                                          |\n";
        cout<<"| 2.  Tambahkan Dosen                                               |\n";
        cout<<"| 3.  Hubungkan Dosen dengan Matakuliah                             |\n";
        cout<<"| 4.  Hapus Mata Kuliah                                             |\n";
        cout<<"| 5.  Hapus Dosen                                                   |\n";
        cout<<"| 6.  Menampilkan semua Matakuliah beserta dosennya                 |\n";
        cout<<"| 7.  Menampilkan Matakuliah yang diajarkan sebagian besar Dosen    |\n";
        cout<<"| 8.  Menampilkan Dosen yang mengajar Matakuliah tertentu           |\n";
        cout<<"| 9.  Menampilkan Dosen yang mengajar lebih dari tiga kursus        |\n";
        cout<<"| 10. Hapus relasi                                                  |\n";
        cout<<"| 99. Keluar                                                        |\n";
        cout<<"+___________________________________________________________________+\n";
        cout<<"\nMasukkan Pilihan : ";cin>>Pil;
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
                system("CLS");
                cout<<"+------------- DAFTAR MATAKULIAH BESERTA DOSEN PENGAJARNYA -------------+\n\n";
                TampilMataKuliahDanDosennya(L);
                cout<<"\n\nEnter untuk kembali...";
                getch();
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
            case 10:
                menuHapusRelasi(L);
                break;
            case 99:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                getch();
        }
    }while (Pil!=99);
    return 0;
}
