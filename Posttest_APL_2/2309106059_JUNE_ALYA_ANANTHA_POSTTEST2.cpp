#include <iostream>

using namespace std;

    string Ikan_Hias[100] = {"Ikan Mas", "Ikan Koi", "Ikan Arwana", "Ikan Cupang"};
    string Harga_Ikan_Hias[100] = {"2.000.000", "4.000.000", "40.000.000", "10.000"};
    int jml_data = 0;
    int indx, idx;

void Lihat_Data() {

        cout << "Berikut Data Ikan Hias Available Beserta Harganya." << endl;
        for (int i = 0; i < jml_data && !Ikan_Hias[i].empty(); i++) {
            cout << i+1 << ". " << Ikan_Hias[i] << " | " << Harga_Ikan_Hias[i] << "/Ekor." << endl;
        }
    cout << "" << endl;

}

void Tambah_Data() {

    string nama_ikan_hias;
    string harga_ikan_hias;
    cout << "Masukkan Nama Ikan Hias: ";
    cin.ignore();
    getline(cin, nama_ikan_hias);
    cout <<"Masukkan Harga Ikan Hias: ";
    fflush(stdin);
    getline(cin, harga_ikan_hias);
    Ikan_Hias[indx] = nama_ikan_hias;
    Harga_Ikan_Hias[indx] = harga_ikan_hias;
    indx++;
    cout << "" << endl;

}

void Ubah_Data() {

    string nama_ikan_hias;
    string harga_ikan_hias;
    Lihat_Data();
    cout << "Masukkan urutan data yang ingin diubah: " << endl;
    cin >> idx;
    cout << "Masukkan nama ikan hias yang ingin diubah: " << endl;
    cin.ignore();
    getline(cin, nama_ikan_hias);
    cout << "Masukkan harga ikan hias yang ingin diubah: " << endl;
    fflush(stdin);
    getline(cin, harga_ikan_hias);
    Ikan_Hias[idx-1] = nama_ikan_hias;
    Harga_Ikan_Hias[idx-1] = harga_ikan_hias;
    cout << "" << endl;

}

void Hapus_Data() {

    Lihat_Data();
    cout << "Masukkan urutan data yang ingin dihapus: " << endl;
    cin >> idx;

    for (int i = idx-1; i < indx; i++) {
        Ikan_Hias[i] = Ikan_Hias[i+1];
        Harga_Ikan_Hias[i] = Harga_Ikan_Hias[i+1];
    }
    indx--;
    cout << "" << endl;

}

void menu() {

    cout << "1. Lihat Data" << endl;
    cout << "2. Tambah Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Berhenti" << endl;

    int pilih;
    bool lanjut;
    cout << "Silahkan pilih menu (1/2/3/4/5): " << endl;
    cin >> pilih;

        switch(pilih) {

        case 1:
            Lihat_Data();
            break;
        case 2:
            Tambah_Data();
            break;
        case 3:
            Ubah_Data();
            break;
        case 4:
            Hapus_Data();
            break;
        case 5:
            cout << "Program dihentikan." << endl;
            lanjut = false;
            return;
        default:
            cout << "Pilihan tidak tersedia." << endl;

        } 

    menu();

}

void login_admin () {

    int hitung = 0;
    string username = "June Alya Anantha";
    string password = "2309106059";
    string inputan_username, inputan_password;
    
    while (hitung < 3) {
            cout << "Masukkan Username : ";
            getline(cin, inputan_username);
            cout << "Masukkan Password : ";
            getline(cin, inputan_password);

            if (inputan_username == username && inputan_password == password) {
                cout << "Login Berhasil!!!" << endl;
                menu();
                break;
            } else {
                cout << "Username atau password salah. Coba lagi." << endl;
            }
            hitung++;
        
        if (hitung == 3) {
            cout << "Percobaan login telah mencapai batas, coba lagi nanti." << endl;
            break;
        }
    }
    
}

int main() {

    jml_data = sizeof(Ikan_Hias)/sizeof(Ikan_Hias[0]);
    for (int i = 0; i < jml_data && !Ikan_Hias[i].empty(); i++) {
        indx++;
        }

    login_admin();

}