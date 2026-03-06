#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Kelas
{
    string jenis;
    int harga;
};

struct Akun
{
    string nama;
    string ID;
    string role;
    Kelas kelas;
};

int main()
{
    const int MAX = 20;
    Akun dataAkun[MAX];
    int jumlah = 2;

    dataAkun[0] = {"annisa", "078", "admin", {"", 0}};
    dataAkun[1] = {"juun", "0412", "member", {"reguler", 450000}};

    bool programAktif = true;
    bool statusLogin = false;
    string namaLogin = "";
    string roleLogin = "";
    int pilihan;

    while (programAktif)
    {
        if (!statusLogin)
        {
            system("cls");
            cout << "==========================================\n";
            cout << "             STUDIO PILATES H2H\n";
            cout << "==========================================\n";
            cout << "1. Login\n";
            cout << "2. Register\n";
            cout << "3. Keluar\n";
            cout << "------------------------------------------\n";
            cout << "Pilih menu (1/2/3): ";
            cin >> pilihan;

            if (pilihan == 1)
            {
                system("cls");
                cout << "------------------------------------------\n";
                cout << "               LAMAN LOGIN\n";
                cout << "------------------------------------------\n";
                string inputNama, inputID;
                int kesempatan = 3;
                bool berhasil = false;
                while (kesempatan > 0)
                {
                    cin.ignore();
                    cout << "Masukkan Nama (Username) : ";
                    getline(cin, inputNama);
                    cout << "Masukkan Password (ID)   : ";
                    cin >> inputID;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (inputNama == dataAkun[i].nama && inputID == dataAkun[i].ID)
                        {
                            statusLogin = true;
                            namaLogin = dataAkun[i].nama;
                            roleLogin = dataAkun[i].role;
                            berhasil = true;
                            break;
                        }
                    }
                    if (berhasil)
                    {
                        cout << "\nLogin berhasil. Halo " << namaLogin << " sebagai " << roleLogin << "!\n";
                        system("pause");
                        break;
                    }
                    kesempatan--;
                    if (kesempatan > 0)
                    {
                        cout << "\nLogin Gagal! Nama atau ID salah.\n";
                        cout << "Sisa kesempatan: " << kesempatan << "\n\n";
                    }
                    else
                    {
                        cout << "\nKesempatan Anda Habis. Annyeong\n";
                        return 0;
                    }
                }
            }

            else if (pilihan == 2)
            {
                system("cls");
                cout << "------------------------------------------\n";
                cout << "              REGISTRASI AKUN\n";
                cout << "------------------------------------------\n";
                if (jumlah < MAX)
                {
                    cin.ignore();
                    string namaBaru, IDBaru, kelasBaru;
                    cout << "Masukkan Nama (Username) : ";
                    getline(cin, namaBaru);
                    cout << "Masukkan Password (ID)   : ";
                    cin >> IDBaru;
                    bool idSudahAda = false;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].ID == IDBaru)
                        {
                            idSudahAda = true;
                            break;
                        }
                    }
                    if (idSudahAda)
                    {
                        cout << "\nID sudah terdaftar. Silakan gunakan ID lain.\n";
                    }
                    else
                    {
                        cout << "Pilih Kelas (private/reguler): ";
                        cin >> kelasBaru;
                        if (kelasBaru != "private" && kelasBaru != "Private" && kelasBaru != "PRIVATE" && kelasBaru != "reguler" && kelasBaru != "Reguler" && kelasBaru != "REGULER")
                        {
                            cout << "\nGagal! Kelas tidak valid.\n";
                        }
                        else
                        {
                            dataAkun[jumlah].nama = namaBaru;
                            dataAkun[jumlah].ID = IDBaru;
                            dataAkun[jumlah].role = "member";
                            dataAkun[jumlah].kelas.jenis = kelasBaru;
                            if (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE")
                            {
                                dataAkun[jumlah].kelas.harga = 1000000;
                            }
                            else
                            {
                                dataAkun[jumlah].kelas.harga = 450000;
                            }
                            jumlah++;
                            cout << "\nPendaftaran berhasil! Silakan Login.\n";
                        }
                    }
                }
                else
                {
                    cout << "Yaahhh Kapasitas penuh!.\n";
                }
                system("pause");
            }
            else if (pilihan == 3)
            {
                programAktif = false;
                cout << "Terima kasih telah berkunjung!\n";
            }
            else
            {
                cout << "Pilihan tidak valid!\n";
                system("pause");
            }
        }
        else
        {
            if (roleLogin == "admin")
            {
                system("cls");
                cout << "==========================================\n";
                cout << "              MENU ADMIN" << endl;
                cout << "==========================================\n";
                cout << "1. Tambah Member (Create)\n";
                cout << "2. Lihat Member (Read)\n";
                cout << "3. Update Member (Update)\n";
                cout << "4. Hapus Member (Delete)\n";
                cout << "5. Logout\n";
                cout << "------------------------------------------\n";
                cout << "Pilih menu (1-5): ";
                cin >> pilihan;

                if (pilihan == 1)
                {
                    system("cls");
                    cout << "==========================================\n";
                    cout << "              TAMBAH MEMBER" << endl;
                    cout << "==========================================\n";
                    if (jumlah < MAX)
                    {
                        cin.ignore();
                        string namaBaru, IDBaru, kelasBaru;
                        cout << "Masukkan Nama Member : ";
                        getline(cin, namaBaru);
                        cout << "Masukkan ID Member   : ";
                        cin >> IDBaru;
                        bool idSudahAda = false;
                        for (int i = 0; i < jumlah; i++)
                        {
                            if (dataAkun[i].ID == IDBaru)
                            {
                                idSudahAda = true;
                                break;
                            }
                        }
                        if (idSudahAda)
                        {
                            cout << "\nError: Member dengan ID tersebut sudah ada!\n";
                        }
                        else
                        {
                            cout << "Kelas (private/reguler): ";
                            cin >> kelasBaru;
                            if (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE" || kelasBaru == "reguler" || kelasBaru == "Reguler" || kelasBaru == "REGULER")
                            {
                                dataAkun[jumlah].nama = namaBaru;
                                dataAkun[jumlah].ID = IDBaru;
                                dataAkun[jumlah].role = "member";
                                dataAkun[jumlah].kelas.jenis = kelasBaru;
                                if (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE")
                                    dataAkun[jumlah].kelas.harga = 1000000;
                                else
                                    dataAkun[jumlah].kelas.harga = 450000;
                                jumlah++;
                                cout << "\nMember berhasil ditambahkan!\n";
                            }
                            else
                            {
                                cout << "\nKelas salah! Gagal menambahkan member.\n";
                            }
                        }
                    }
                    else
                    {
                        cout << "Yaahhh Kapasitas penuh!.\n";
                    }
                    system("pause");
                }

                else if (pilihan == 2)
                {
                    system("cls");
                    cout << "=================================================================\n";
                    cout << "                       DAFTAR MEMBER\n";
                    cout << "=================================================================\n";
                    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "ID" << setw(15) << "Kelas" << setw(10) << "Harga" << endl;
                    cout << "=================================================================\n";
                    int nomor = 1;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member")
                        {
                            cout << left << setw(5) << nomor << setw(20) << dataAkun[i].nama << setw(15) << dataAkun[i].ID << setw(15) << dataAkun[i].kelas.jenis << "Rp " << dataAkun[i].kelas.harga << "\n";
                            nomor++;
                        }
                    }
                    cout << "=================================================================\n";
                    system("pause");
                }
                else if (pilihan == 3)
                {
                    system("cls");
                    cout << "=================================================================\n";
                    cout << "                   DAFTAR MEMBER SAAT INI\n";
                    cout << "=================================================================\n";
                    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NIM" << setw(15) << "Kelas" << setw(10) << "Harga" << endl;
                    cout << "=================================================================\n";
                    int nomor = 1;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member")
                        {
                            cout << left << setw(5) << nomor << setw(20) << dataAkun[i].nama << setw(15) << dataAkun[i].ID << setw(15) << dataAkun[i].kelas.jenis << "Rp " << dataAkun[i].kelas.harga << "\n";
                            nomor++;
                        }
                    }
                    cout << "=================================================================\n";
                    string cariID;
                    cout << "\nMasukkan ID member yang ingin diubah: ";
                    cin >> cariID;
                    bool ditemukan = false;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member" && dataAkun[i].ID == cariID)
                        {
                            ditemukan = true;
                            cin.ignore();
                            cout << "Username Baru (" << dataAkun[i].nama << "): ";
                            getline(cin, dataAkun[i].nama);
                            cout << "Kelas Baru (private/reguler): ";
                            cin >> dataAkun[i].kelas.jenis;
                            if (dataAkun[i].kelas.jenis == "private" || dataAkun[i].kelas.jenis == "Private" || dataAkun[i].kelas.jenis == "PRIVATE" || dataAkun[i].kelas.jenis == "reguler" || dataAkun[i].kelas.jenis == "Reguler" || dataAkun[i].kelas.jenis == "REGULER")
                            {
                                if (dataAkun[i].kelas.jenis == "private" || dataAkun[i].kelas.jenis == "Private" || dataAkun[i].kelas.jenis == "PRIVATE")
                                    dataAkun[i].kelas.harga = 1000000;
                                else
                                    dataAkun[i].kelas.harga = 450000;
                                cout << "\nData berhasil diupdate!\n";
                                break;
                            }
                            else
                            {
                                cout << "\nKelas salah! Gagal update data.\n";
                                break;
                            }
                        }
                    }
                    if (!ditemukan)
                        cout << "\nError: Member dengan ID tersebut tidak ditemukan!\n";
                    system("pause");
                }
                else if (pilihan == 4)
                {
                    system("cls");
                    cout << "=================================================================\n";
                    cout << "                   DAFTAR MEMBER SAAT INI\n";
                    cout << "=================================================================\n";
                    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "NIM" << setw(15) << "Kelas" << setw(10) << "Harga" << endl;
                    cout << "=================================================================\n";
                    int nomor = 1;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member")
                        {
                            cout << left << setw(5) << nomor << setw(20) << dataAkun[i].nama << setw(15) << dataAkun[i].ID << setw(15) << dataAkun[i].kelas.jenis << "Rp " << dataAkun[i].kelas.harga << "\n";
                            nomor++;
                        }
                    }
                    cout << "=================================================================\n";
                    string hapusID;
                    cout << "\nMasukkan ID member yang ingin dihapus: ";
                    cin >> hapusID;
                    bool ditemukan = false;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member" && dataAkun[i].ID == hapusID)
                        {
                            ditemukan = true;
                            for (int j = i; j < jumlah - 1; j++)
                            {
                                dataAkun[j] = dataAkun[j + 1];
                            }
                            jumlah--;
                            cout << "\nData member berhasil dihapus!\n";
                            break;
                        }
                    }
                    if (!ditemukan)
                        cout << "\nError: Member dengan ID tersebut tidak ditemukan!\n";
                    system("pause");
                }
                else if (pilihan == 5)
                {
                    statusLogin = false;
                    cout << "Berhasil Logout!\n";
                    system("pause");
                }
                else
                {
                    cout << "\nPilihan tidak valid!\n";
                    system("pause");
                }
            }
            else if (roleLogin == "member")
            {
                system("cls");
                cout << "==========================================\n";
                cout << "              MENU MEMBER" << endl;
                cout << "==========================================\n";
                cout << "1. Lihat Profil Saya\n";
                cout << "2. Cari Kelas\n";
                cout << "3. Logout\n";
                cout << "------------------------------------------\n";
                cout << "Pilih menu (1/2/3): ";
                cin >> pilihan;

                if (pilihan == 1)
                {
                    system("cls");
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].nama == namaLogin)
                        {
                            cout << "==========================================\n";
                            cout << "              PROFIL ANDA" << endl;
                            cout << "==========================================\n";
                            cout << left << setw(10) << "Nama" << ": " << dataAkun[i].nama << endl;
                            cout << left << setw(10) << "NIM" << ": " << dataAkun[i].ID << endl;
                            cout << left << setw(10) << "Kelas" << ": " << dataAkun[i].kelas.jenis << endl;
                            cout << left << setw(10) << "Harga" << ": Rp " << dataAkun[i].kelas.harga << endl;
                            break;
                        }
                    }
                    system("pause");
                }

                else if (pilihan == 2)
                {
                    system("cls");
                    string cariKelas;
                    cout << "================================================================\n";
                    cout << "                   PENCARIAN KELAS\n";
                    cout << "================================================================\n";
                    cout << "Masukkan kelas yang ingin dicari (private/reguler): ";
                    cin >> cariKelas;
                    cout << "\n\n================================================================\n";
                    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "Kelas" << endl;
                    cout << "================================================================\n";
                    int nomor = 1;
                    bool adaData = false;
                    for (int i = 0; i < jumlah; i++)
                    {
                        if (dataAkun[i].role == "member" && dataAkun[i].kelas.jenis == cariKelas)
                        {
                            cout << left << setw(5) << nomor << setw(20) << dataAkun[i].nama << setw(15) << dataAkun[i].kelas.jenis << "\n";
                            nomor++;
                            adaData = true;
                        }
                    }
                    if (!adaData)
                    {
                        cout << "Tidak ada data member yang ditemukan di kelas ini.\n";
                    }
                    cout << "================================================================\n";
                    system("pause");
                }
                else if (pilihan == 3)
                {
                    statusLogin = false;
                    cout << "Berhasil Logout!\n";
                    system("pause");
                }
                else
                {
                    cout << "\nPilihan tidak valid!\n";
                    system("pause");
                }
            }
        }
    }
    return 0;
}