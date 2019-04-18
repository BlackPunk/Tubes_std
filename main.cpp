#include "tubes.h"

int main() {
    multiList L;
    createList(L);
    int Pil= -1;
    while (Pil != 99){
        cout<<"1. Tambahkan Dosen\n";
        cout<<"2. Tambahkan Mata Kuliah\n";
        cout<<"3. Hubungkan Dosen dengan Mata Kuliah\n";
        cout<<"4. Hapus Mata Kuliah\n";
        cout<<"5. Hapus Dosen\n";
        cout<<"99. Out\n";
        cout<<"Masukkan Pilihan : ";cin>>Pil;
        switch (Pil){
            case 1:
                tambahDosen(L);
                break;
            case 2:
                tambahMatkul(L);
                break;
            case 3:
                addRelasi(L);
                break;
            case 4:
                HapusMatkul(L); break;
            case 5:
                HapusDosen(L); break;
            case 99:
                break;
            default:
                cout<<"Pilihan tidak ada...\n";
                cin.get();
        }
    }
    return 0;
}
