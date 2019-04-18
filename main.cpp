#include "tubes.h"

int main() {
    multiList L;
    createList(L);
    int Pil= -1;
    while (Pil != 99){
        cout<<"1. Tambahkan Mata Kuliah\n";
        cout<<"2. Tambahkan Dosen\n";
        cout<<"3. Hubungkan Dosen dengan Mata Kuliah\n";
        cout<<"4. Hapus Mata Kuliah\n";
        cout<<"5. Hapus Dosen\n";
        cout<<"6. Menampilkan semua Mata kuliah beserta dosennya\n";
        cout<<"8. Menampilkan dosen yang mengajar mata kuliah tertentu\n";
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
                TampilMataKuliah(L);
                break;
            case 8:
                tampilPengajarMatkul(L); break;
            case 99:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                cin.get();
        }
    }
    return 0;
}
