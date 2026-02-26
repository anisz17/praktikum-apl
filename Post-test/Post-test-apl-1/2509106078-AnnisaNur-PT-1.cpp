#include <iostream>
using namespace std;

string nama = "annisa";
string nim = "078";

int bataspercobaan = 3;
int percobaan = 0;

int main()
{
    system("cls");
    cout << "===================================================\n";
    cout << "           PROGRAM KONVERSI PANJANG\n";
    cout << "===================================================\n";

    while (percobaan < bataspercobaan)
    {
        string username;
        string password;

        cout << "Percobaan Ke-" << percobaan + 1 << " dari " << bataspercobaan << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        if (username == nama && password == nim)
        {
            cout << "\nLOGIN BERHASIL!" << endl;
            cout << "Selamat Datang, " << nama << endl;
            cout << "\nTekan Enter untuk masuk ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
            break;
        }
        else
        {
            percobaan++;
            if (percobaan < bataspercobaan)
            {
                cout << "Login Gagal! Username atau Password Salah.\n";
                cout << "Sisa Percobaan: " << bataspercobaan - percobaan << endl
                     << endl;
            }
            else
            {
                cout << "\nLOGIN GAGAL!\n";
                cout << "Anda Telah Melebihi Batas Percobaan Login.\n";
                return 0;
            }
        }
    }

    while (true)
    {
        system("cls");
        cout << "==============================================================\n";
        cout << "                     MENU KONVERSI\n";
        cout << "==============================================================\n";
        cout << "1. Meter --> Kilometer & Centimeter\n";
        cout << "2. Kilometer --> Meter & Centimeter\n";
        cout << "3. Centimeter --> Meter & Kilometer\n";
        cout << "4. Keluar\n";
        cout << "--------------------------------------------------------------\n";

        int pilihan;
        cout << "Pilih Menu (1-4): ";
        cin >> pilihan;

        double hasil1 = 0;
        double hasil2 = 0;
        double nilai;

        if (pilihan == 1)
        {
            system("cls");
            cout << "--------------------------------------------------------------\n";
            cout << "                Meter --> Kilometer & Centimeter\n";
            cout << "--------------------------------------------------------------\n";
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            hasil1 = nilai / 1000;
            hasil2 = nilai * 100;

            cout << "\nMeter      : " << nilai << endl;
            cout << "Kilometer    : " << hasil1 << endl;
            cout << "Centimeter   : " << hasil2 << endl;
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        }
        else if (pilihan == 2)
        {
            system("cls");
            cout << "--------------------------------------------------------------\n";
            cout << "               Kilometer --> Meter & Centimeter\n";
            cout << "--------------------------------------------------------------\n";
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            hasil1 = nilai * 1000;
            hasil2 = nilai * 100000;

            cout << "\nKilometer  : " << nilai << endl;
            cout << "Meter        : " << hasil1 << endl;
            cout << "Centimeter   : " << hasil2 << endl;

            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        }
        else if (pilihan == 3)
        {
            system("cls");
            cout << "--------------------------------------------------------------\n";
            cout << "              Centimeter --> Meter & Kilometer\n";
            cout << "--------------------------------------------------------------\n";
            cout << "Masukkan Nilai: ";
            cin >> nilai;
            hasil1 = nilai / 100;
            hasil2 = nilai / 100000;

            cout << "\nCentimeter : " << nilai << endl;
            cout << "Meter        : " << hasil1 << endl;
            cout << "Kilometer    : " << hasil2 << endl;
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.ignore(1000, '\n');
            cin.get();
        }
        else if (pilihan == 4)
        {
            system("cls");
            cout << "\n============================================================\n";
            cout << "       Terima kasih telah menggunakan program ini!\n";
            cout << "============================================================\n";
            break;
        }
        else
        {
            cout << "\nError: Pilihan tidak valid! Pilih 1-4.\n";
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore(1000, '\n');
            cin.get();
        }
    }
    return 0;
}