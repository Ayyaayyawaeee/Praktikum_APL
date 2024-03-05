#include <iostream>

using namespace std;

void konversi_km () {

    float km_per_jam, cm_per_dtk, meter_per_dtk, mil_per_jam;

    cout << "Masukkan percepatan (km/jam): ";
    cin >> km_per_jam;
    cm_per_dtk = (km_per_jam*100000)/3600;
    meter_per_dtk = (km_per_jam*1000)/3600;
    mil_per_jam = km_per_jam*0.6213;
    cout << " " << endl;
    cout << km_per_jam << " kilometer/jam = " << endl;
    cout << cm_per_dtk << " centimeter/detik." << endl;
    cout << meter_per_dtk << " meter/detik." << endl;
    cout << mil_per_jam << " mil/jam." <<endl;
    cout << " " << endl;

}

void konversi_cm () {
    
    float km_per_jam, cm_per_dtk, meter_per_dtk, mil_per_jam;

    cout << "Masukkan percepatan (cm/detik): ";
    cin >> cm_per_dtk;
    km_per_jam = (cm_per_dtk/100000)*3600;
    meter_per_dtk = cm_per_dtk/100;
    mil_per_jam = cm_per_dtk*6.2137*3600;
    cout << " " << endl;
    cout << cm_per_dtk << " centimeter/detik = " << endl;
    cout << km_per_jam << " kilometer/jam." << endl;
    cout << meter_per_dtk << " meter/detik." << endl;
    cout << mil_per_jam << " mil/jam."<< endl;
    cout << " " << endl;

}

void konversi_meter () {
    
    float km_per_jam, cm_per_dtk, meter_per_dtk, mil_per_jam;

    cout << "Masukkan percepatan (m/detik): ";
    cin >> meter_per_dtk;
    km_per_jam = (meter_per_dtk/1000)*3600;
    cm_per_dtk = meter_per_dtk*100;
    mil_per_jam = meter_per_dtk*0,0006*3600;
    cout << " " << endl;
    cout << meter_per_dtk << " meter/detik = " << endl;
    cout << km_per_jam << " kilometer/jam." << endl;
    cout << cm_per_dtk << "centimeter/detik." << endl;
    cout << mil_per_jam << "mil/jam." <<endl;
    cout << " " << endl;

}

void konversi_mil () {
    
    float km_per_jam, cm_per_dtk, meter_per_dtk, mil_per_jam;

    cout << "Masukkan percepatan (mil/jam): ";
    cin >> mil_per_jam;
    km_per_jam = mil_per_jam/0.6213;
    cm_per_dtk = (mil_per_jam/6.2137)/3600;
    meter_per_dtk = (mil_per_jam/0.0006)/3600;
    cout << " " << endl;
    cout << mil_per_jam << " mil/jam = " << endl;
    cout << km_per_jam << " kilometer/jam." << endl;
    cout << cm_per_dtk << "centimeter/detik." << endl;
    cout << meter_per_dtk << "meter/detik." <<endl;
    cout << " " << endl;

}

void menu() {

    cout << "1. Konversi Kilometer/jam" << endl;
    cout << "2. Konversi Centimeter/detik" << endl;
    cout << "3. Konversi Meter/detik" << endl;
    cout << "4. Konversi Mil/jam" << endl;
    cout << "5. Berhenti" << endl;

    int pilih;
    bool lanjut;
    cout << "Silahkan pilih menu (1/2/3/4/5): " << endl;
    cin >> pilih;

        switch(pilih) {

        case 1:
            konversi_km();
            break;
        case 2:
            konversi_cm();
            break;
        case 3:
            konversi_meter();
            break;
        case 4:
            konversi_mil();
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

    login_admin();

}