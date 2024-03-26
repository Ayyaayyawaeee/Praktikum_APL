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

void Tambah_Data()
{

    Lihat_Data();
    string nama_ikan_hias;
    string harga_ikan_hias;
    string jenis_ikan;
    cin.ignore();
    cout << "Jenis Ikan Hias yang Ingin Diubah (Besar/Kecil): ";
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
    }
    else
    {
        cout << "Input tidak valid!" << endl; // Error Handling
    }

    cout << "" << endl;
}

int hasil_penjualan(int harga_barang, int jumlah_penjualan)
{

    if (jumlah_penjualan == 1)
    {
        return harga_barang;
    }

    else
    {
        return harga_barang + hasil_penjualan(harga_barang, jumlah_penjualan - 1);
    }
}

void menu()
{

    cout << "1. Lihat Data" << endl;
    cout << "2. Tambah Data" << endl;
    cout << "3. Ubah Data" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Kalkulasi Hasil Penjualan" << endl;
    cout << "6. Berhenti" << endl;

    string pilih;
    bool lanjut;
    cout << "Silahkan pilih menu (1/2/3/4/5): " << endl;
    cin >> pilih;

    if (pilih == "1")
    {
        Lihat_Data();
    }
    else if (pilih == "2")
    {
        Tambah_Data();
    }
    else if (pilih == "3")
    {
        Ubah_Data();
    }
    else if (pilih == "4")
    {
        Hapus_Data();
    }
    else if (pilih == "5")
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
            Harga_Barang = stoi(ikan[idx - 1].ikan_besar.harga);
            hasil = hasil_penjualan(Harga_Barang, jmlh);
            cout << "Hasil Penjualan : " << hasil << endl;
        }
        else if (jenis_ikan == "KECIL")
        {
            Harga_Barang = stoi(ikan[idx - 1].ikan_kecil.harga);
            hasil = hasil_penjualan(Harga_Barang, jmlh);
            cout << "Hasil Penjualan : " << hasil << endl;
        }
    }
    else if (pilih == "6")
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