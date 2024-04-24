#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

struct ikan_hias_kecil
{
    string nama;
    string harga;
};

struct ikan_hias_besar
{
    string nama;
    string harga;
};

struct ikan_hias
{
    ikan_hias_kecil ikan_kecil;
    ikan_hias_besar ikan_besar;
};
ikan_hias ikan[100];

int jml_data = 0;
int indx_besar, indx_kecil, idx;

void SelectionSortIkanBesar(struct ikan_hias ikan[], int n) { // Untuk mengurutkan Data Ikan Besar dengan selection sort secara Descending
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ikan[j].ikan_besar.nama > ikan[max_idx].ikan_besar.nama) {
                max_idx = j;
            }
        }
        swap(ikan[max_idx], ikan[i]);
    }
}

void SelectionSortIkanKecil(struct ikan_hias ikan[], int n) {// Untuk mengurutkan Data Ikan Kecil dengan selection sort secara Descending
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (ikan[j].ikan_kecil.nama > ikan[min_idx].ikan_kecil.nama) {
                min_idx = j;
            }
        }
        swap(ikan[min_idx], ikan[i]);
    }
}

void BubbleSortIkanBesarAscending(struct ikan_hias ikan[], int n) { // Untuk mengurutkan Data Ikan Besar berdasarkan harganya secara Ascending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!ikan[j].ikan_besar.nama.empty() && !ikan[j + 1].ikan_besar.nama.empty()) {
                if (stoi(ikan[j].ikan_besar.harga) > stoi(ikan[j + 1].ikan_besar.harga)) {
                    swap(ikan[j], ikan[j + 1]);
                }
            }
        }
    }
}

void BubbleSortIkanKecilAscending(struct ikan_hias ikan[], int n) { // Untuk mengurutkan Data Ikan Kecil berdasarkan harganya secara Ascending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!ikan[j].ikan_kecil.nama.empty() && !ikan[j + 1].ikan_kecil.nama.empty()) {
                if (stoi(ikan[j].ikan_kecil.harga) > stoi(ikan[j + 1].ikan_kecil.harga)) {
                    swap(ikan[j], ikan[j + 1]);
                }
            }
        }
    }
}

void BubbleSortIkanBesarDescending(struct ikan_hias ikan[], int n) { // Untuk mengurutkan Data Ikan Besar berdasarkan harganya secara Descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!ikan[j].ikan_besar.nama.empty() && !ikan[j + 1].ikan_besar.nama.empty()) {
                if (stoi(ikan[j].ikan_besar.harga) < stoi(ikan[j + 1].ikan_besar.harga)) {
                    swap(ikan[j], ikan[j + 1]);
                }
            }
        }
    }
}

void BubbleSortIkanKecilDescending(struct ikan_hias ikan[], int n) { // Untuk mengurutkan Data Ikan Kecil berdasarkan harganya secara Descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (!ikan[j].ikan_kecil.nama.empty() && !ikan[j + 1].ikan_kecil.nama.empty()) {
                if (stoi(ikan[j].ikan_kecil.harga) < stoi(ikan[j + 1].ikan_kecil.harga)) {
                    swap(ikan[j], ikan[j + 1]);
                }
            }
        }
    }
}

void BinarySearch() {
    cout << "Jenis Ikan yang Ingin Dicari: " << endl;
    cout << "1. Ikan Kecil" << endl;
    cout << "2. Ikan Besar" << endl;
    cout << "Pilihan Anda: ";
    int pilihan;
    cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        BubbleSortIkanKecilAscending(ikan, jml_data); // Mengurutkan data secara Ascensing lebih dulu
        cout << "Masukkan Nama Ikan Kecil: ";
        string nama;
        getline(cin, nama);

        int awal = 0;
        int akhir = jml_data - 1;
        int tengah;

        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if (nama == ikan[tengah].ikan_kecil.nama) {
                cout << "Ikan tersebut available dengan harga " << ikan[tengah].ikan_kecil.harga << endl;
                return;
            } else if (nama < ikan[tengah].ikan_kecil.nama) {
                akhir = tengah - 1;
            } else {
                awal = tengah + 1;
            }
        }
        cout << "Nama tidak ditemukan" << endl;
    } else if (pilihan == 2) { 
        BubbleSortIkanBesarAscending(ikan, jml_data); // Mengurutkan data secara Ascensing lebih dulu
        cout << "Masukkan Nama Ikan Besar: ";
        string nama;
        getline(cin, nama);

        int awal = 0;
        int akhir = jml_data - 1;
        int tengah;

        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if (nama == ikan[tengah].ikan_besar.nama) {
                cout << "Ikan tersebut available dengan harga " << ikan[tengah].ikan_besar.harga << endl;
                return;
            } else if (nama < ikan[tengah].ikan_besar.nama) {
                akhir = tengah - 1;
            } else {
                awal = tengah + 1;
            }
        }
        cout << "Nama tidak ditemukan" << endl;
    } else {
        cout << "Pilihan tidak valid" << endl;
    }

}

void Lihat_Data()
{
    cout << "Berikut Data Ikan Hias Besar Available Beserta Harganya." << endl;
    for (int i = 0; i < jml_data && !ikan[i].ikan_besar.nama.empty(); i++)
    {
        cout << i + 1 << ". " << ikan[i].ikan_besar.nama << " | " << ikan[i].ikan_besar.harga << "/Ekor." << endl;
    }

    cout << "" << endl;

    cout << "Berikut Data Ikan Hias Kecil Available Beserta Harganya." << endl;
    for (int i = 0; i < jml_data && !ikan[i].ikan_kecil.nama.empty(); i++)
    {
        cout << i + 1 << ". " << ikan[i].ikan_kecil.nama << " | " << ikan[i].ikan_kecil.harga << "/Ekor." << endl;
    }
    cout << "" << endl;
}

void Lihat_Data_Berdasarkan_Harga()
{
    string pilih;
    cout << "Lihat Harga Berdasarkan: " << endl;
    cout << "1. Harga Termurah" << endl;
    cout << "2. Harga Termahal" << endl;
    cin.ignore();
    getline (cin, pilih);
    if (pilih == "1")
    {
        BubbleSortIkanBesarAscending(ikan, jml_data);
        cout << "" << endl;
        cout << "Berikut Data Ikan Hias Besar Available Beserta Harganya." << endl;
        for (int i = 0; i < jml_data && !ikan[i].ikan_besar.nama.empty(); i++)
        {
            cout << i + 1 << ". " << ikan[i].ikan_besar.nama << " | " << ikan[i].ikan_besar.harga << "/Ekor." << endl;
        }

        cout << "" << endl;

        BubbleSortIkanKecilAscending(ikan, jml_data);
        cout << "Berikut Data Ikan Hias Kecil Available Beserta Harganya." << endl;
        for (int i = 0; i < jml_data && !ikan[i].ikan_kecil.nama.empty(); i++)
        {
            cout << i + 1 << ". " << ikan[i].ikan_kecil.nama << " | " << ikan[i].ikan_kecil.harga << "/Ekor." << endl;
        }
        cout << "" << endl;
    }
    else if (pilih == "2")
    {
        BubbleSortIkanBesarDescending(ikan, jml_data);
        cout << "" << endl;
        cout << "Berikut Data Ikan Hias Besar Available Beserta Harganya." << endl;
        for (int i = 0; i < jml_data && !ikan[i].ikan_besar.nama.empty(); i++)
        {
            cout << i + 1 << ". " << ikan[i].ikan_besar.nama << " | " << ikan[i].ikan_besar.harga << "/Ekor." << endl;
        }

        cout << "" << endl;

        BubbleSortIkanKecilDescending(ikan, jml_data);
        cout << "Berikut Data Ikan Hias Kecil Available Beserta Harganya." << endl;
        for (int i = 0; i < jml_data && !ikan[i].ikan_kecil.nama.empty(); i++)
        {
            cout << i + 1 << ". " << ikan[i].ikan_kecil.nama << " | " << ikan[i].ikan_kecil.harga << "/Ekor." << endl;
        }
        cout << "" << endl;
    }
    else
    {
        cout << "Pilihan tidak tersedia." << endl;
        return;
    }

}

void Tambah_Data()
{

    Lihat_Data();
    string nama_ikan_hias;
    string harga_ikan_hias;
    string jenis_ikan;
    cin.ignore();
    cout << "Jenis Ikan Hias yang Ingin Ditambahkan (Besar/Kecil): ";
    getline(cin, jenis_ikan);

    transform(jenis_ikan.begin(), jenis_ikan.end(), jenis_ikan.begin(), ::toupper); // error handling
    if (jenis_ikan == "BESAR")
    {
        cout << "Masukkan Nama Ikan Hias: ";
        getline(cin, nama_ikan_hias);
        cout << "Masukkan Harga Ikan Hias: ";
        fflush(stdin);
        getline(cin, harga_ikan_hias);
        fflush(stdin);
        ikan[indx_besar].ikan_besar.nama = nama_ikan_hias;
        ikan[indx_besar].ikan_besar.harga = harga_ikan_hias;
        indx_besar++;
        SelectionSortIkanBesar(ikan, jml_data);

    }
    else if (jenis_ikan == "KECIL")
    {
        cout << "Masukkan Nama Ikan Hias: ";
        getline(cin, nama_ikan_hias);
        cout << "Masukkan Harga Ikan Hias: ";
        fflush(stdin);
        getline(cin, harga_ikan_hias);
        fflush(stdin);
        ikan[indx_kecil].ikan_kecil.nama = nama_ikan_hias;
        ikan[indx_kecil].ikan_kecil.harga = harga_ikan_hias;
        indx_kecil++;
        SelectionSortIkanKecil(ikan, jml_data);
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }
    jml_data++;

    cout << "" << endl;
}

void Ubah_Data()
{

    string nama_ikan_hias;
    string harga_ikan_hias;
    string jenis_ikan;
    Lihat_Data();
    cout << "Jenis Ikan Hias yang Ingin Diubah (Besar/Kecil): ";
    cin.ignore();
    getline(cin, jenis_ikan);

    transform(jenis_ikan.begin(), jenis_ikan.end(), jenis_ikan.begin(), ::toupper);
    if (jenis_ikan == "BESAR")
    {
        cout << "Masukkan urutan data yang ingin diubah: " << endl;
        cin >> idx;
        cout << "Masukkan nama ikan hias yang ingin diubah: " << endl;
        cin.ignore();
        getline(cin, nama_ikan_hias);
        cout << "Masukkan harga ikan hias yang ingin diubah: " << endl;
        fflush(stdin);
        getline(cin, harga_ikan_hias);
        fflush(stdin);
        ikan[idx - 1].ikan_besar.nama = nama_ikan_hias;
        ikan[idx - 1].ikan_besar.harga = harga_ikan_hias;
        SelectionSortIkanBesar(ikan, jml_data);
    }
    else if (jenis_ikan == "KECIL")
    {
        cout << "Masukkan urutan data yang ingin diubah: " << endl;
        cin >> idx;
        cout << "Masukkan nama ikan hias yang ingin diubah: " << endl;
        cin.ignore();
        getline(cin, nama_ikan_hias);
        cout << "Masukkan harga ikan hias yang ingin diubah: " << endl;
        fflush(stdin);
        getline(cin, harga_ikan_hias);
        fflush(stdin);
        ikan[idx - 1].ikan_kecil.nama = nama_ikan_hias;
        ikan[idx - 1].ikan_kecil.harga = harga_ikan_hias;
        indx_kecil++;
        SelectionSortIkanKecil(ikan, jml_data);
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }

    cout << "" << endl;
}

void Hapus_Data()
{
    Lihat_Data();
    string jenis_ikan;
    cout << "Jenis Ikan Hias yang Ingin Dihapus (Besar/Kecil): ";
    cin.ignore();
    getline(cin, jenis_ikan);
    transform(jenis_ikan.begin(), jenis_ikan.end(), jenis_ikan.begin(), ::toupper); // Error Handling
    if (jenis_ikan == "BESAR")
    {
        cout << "Masukkan urutan data yang ingin dihapus: " << endl;
        cin >> idx;
        for (int i = idx - 1; i < indx_besar; i++)
        {
            ikan[i].ikan_besar.nama = ikan[i + 1].ikan_besar.nama;
            ikan[i].ikan_besar.harga = ikan[i + 1].ikan_besar.harga;
            ikan[indx_besar].ikan_besar.nama = "";
            ikan[indx_besar].ikan_besar.harga = "";
            indx_besar--;
        }
        SelectionSortIkanBesar(ikan, jml_data);
    }
    else if (jenis_ikan == "KECIL")
    {
        cout << "Masukkan urutan data yang ingin dihapus: " << endl;
        cin >> idx;
        for (int i = idx - 1; i < indx_kecil; i++)
        {
            ikan[i].ikan_kecil.nama = ikan[i + 1].ikan_kecil.nama;
            ikan[i].ikan_kecil.harga = ikan[i + 1].ikan_kecil.harga;
            ikan[i + 1].ikan_kecil.nama = "";
            ikan[i + 1].ikan_kecil.harga = "";
            indx_kecil--;
        }
        SelectionSortIkanKecil(ikan, jml_data);
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }

    cout << "" << endl;
}

int hasil_penjualan(int *harga_barang, int &jumlah_penjualan)
{

    if (jumlah_penjualan == 1)
    {
        return *harga_barang;
    }

    else
    {
        jumlah_penjualan = jumlah_penjualan - 1;
        return *harga_barang + hasil_penjualan(harga_barang, jumlah_penjualan);
    }
}

void menu()
{

    cout << "1. Cari Data" << endl;
    cout << "2. Lihat Data" << endl;
    cout << "3. Lihat Data Terurut Berdasarkan Harga" << endl;
    cout << "4. Tambah Data" << endl;
    cout << "5. Ubah Data" << endl;
    cout << "6. Hapus Data" << endl;
    cout << "7. Kalkulasi Hasil Penjualan" << endl;
    cout << "8. Berhenti" << endl;

    string pilih;
    bool lanjut;
    cout << "Silahkan pilih menu (1/2/3/4/5/6/7/8): " << endl;
    cin >> pilih;
    cout << "" << endl;

    if (pilih == "1")
    {
        BinarySearch();
    }
    else if (pilih == "2")
    {
        Lihat_Data();
    }
    else if (pilih == "3")
    {
        Lihat_Data_Berdasarkan_Harga();
    }
    else if (pilih == "4")
    {
        Tambah_Data();
    }
    else if (pilih == "5")
    {
        Ubah_Data();
    }
    else if (pilih == "6")
    {
        Hapus_Data();
    }
    else if (pilih == "7")
    {
        Lihat_Data();
        int jmlh, Harga_Barang, hasil;
        string jenis_ikan;
        cout << "Jenis Ikan Hias yang di hitung (Besar/Kecil): ";
        cin.ignore();
        getline(cin, jenis_ikan);

        transform(jenis_ikan.begin(), jenis_ikan.end(), jenis_ikan.begin(), ::toupper);
        if (jenis_ikan == "BESAR")
        {
            cout << "Masukkan Urutan Ikan Hias : " << endl;
            cin >> idx;
            cout << "Masukkan Jumlah Penjualan : " << endl;
            cin >> jmlh;
            Harga_Barang = stoi(ikan[idx - 1].ikan_besar.harga);
            hasil = hasil_penjualan(&Harga_Barang, jmlh);
            cout << "Hasil Penjualan : " << hasil << endl;
        }
        else if (jenis_ikan == "KECIL")
        {
            cout << "Masukkan Urutan Ikan Hias : " << endl;
            cin >> idx;
            cout << "Masukkan Jumlah Penjualan : " << endl;
            cin >> jmlh;
            Harga_Barang = stoi(ikan[idx - 1].ikan_kecil.harga);
            hasil = hasil_penjualan(&Harga_Barang, jmlh);
            cout << "Hasil Penjualan : " << hasil << endl;
        }
    }
    else if (pilih == "8")
    {
        cout << "Program dihentikan." << endl;
        lanjut = false;
        return;
    }
    else
    {
        cout << "Input tidak valid." << endl; // Error Handling
    }

    menu();
}

bool login_admin()
{

    int hitung = 0;
    string username = "June Alya Anantha";
    string password = "2309106059";
    string inputan_username, inputan_password;

    while (hitung < 3)
    {
        cout << "Masukkan Username : ";
        getline(cin, inputan_username);
        cout << "Masukkan Password : ";
        getline(cin, inputan_password);

        if (inputan_username == username && inputan_password == password)
        {
            cout << "Login Berhasil!!!" << endl;
            return true;
        }
        else
        {
            cout << "Username atau password salah. Coba lagi." << endl;
        }
        hitung++;

        if (hitung == 3)
        {
            return false;
        }
    }
}

int main()
{
    ikan[0].ikan_kecil.nama = "Ikan Mas";
    ikan[0].ikan_kecil.harga = "2000000";

    ikan[1].ikan_kecil.nama = "Ikan Koi";
    ikan[1].ikan_kecil.harga = "4000000";

    ikan[0].ikan_besar.nama = "Ikan Arwana";
    ikan[0].ikan_besar.harga = "40000000";

    ikan[2].ikan_kecil.nama = "Ikan Cupang";
    ikan[2].ikan_kecil.harga = "10000000";

    jml_data = sizeof(ikan) / sizeof(ikan[0]);
    for (int i = 0; i < jml_data && !ikan[i].ikan_besar.nama.empty(); i++)
    {
        indx_besar++;
    }
    for (int i = 0; i < jml_data && !ikan[i].ikan_kecil.nama.empty(); i++)
    {
        indx_kecil++;
    }

    if (login_admin())
    {
        menu();
    }
    else
    {
        cout << "Gagal Login Silahkan Restart Program!!!" << endl;
    };
}