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

int cariusername(Akun data[], int jumlah, string targetNama, int index = 0)
{
    if (index >= jumlah)
        return -1;
    if (data[index].nama == targetNama)
        return index;
    return cariusername(data, jumlah, targetNama, index + 1);
}

int cariIDMember(Akun data[], int jumlah, string targetID)
{
    for (int i = 0; i < jumlah; i++)
    {
        if (data[i].role == "member" && data[i].ID == targetID)
            return i;
    }
    return -1;
}

void login(Akun data[], int jumlah, bool &statusLogin, string &namaLogin, string &roleLogin)
{
    system("cls");
    cout << "------------------------------------------\n";
    cout << "               LAMAN LOGIN\n";
    cout << "------------------------------------------\n";

    string inputNama, inputID;
    int kesempatan = 3;

    while (kesempatan > 0)
    {
        cin.ignore(1000, '\n');
        cout << "Masukkan Nama (Username) : ";
        getline(cin, inputNama);
        cout << "Masukkan Password (ID)   : ";
        cin >> inputID;

        int index = cariusername(data, jumlah, inputNama);
        if (index != -1 && data[index].ID == inputID)
        {
            statusLogin = true;
            namaLogin = data[index].nama;
            roleLogin = data[index].role;
            cout << "\nLogin berhasil. Halo " << namaLogin << " sebagai " << roleLogin << "!\n";
            system("pause");
            return;
        }
        else
        {
            kesempatan--;
            if (kesempatan > 0)
            {
                cout << "\nLogin Gagal! Nama atau ID salah.\n";
                cout << "Sisa kesempatan: " << kesempatan << "\n\n";
            }
            else
            {
                cout << "\nKesempatan Anda Habis. Annyeong\n";
                system("pause");
            }
        }
    }
}

void registrasi(Akun data[], int &jumlah, int maxKapasitas)
{
    system("cls");
    cout << "------------------------------------------\n";
    cout << "              REGISTRASI AKUN\n";
    cout << "------------------------------------------\n";
    cin.ignore(1000, '\n');
    if (jumlah >= maxKapasitas)
    {
        cout << "Kapasitas penuh!\n";
        return;
    }

    string namaBaru, IDBaru, kelasBaru;
    cout << "Masukkan Nama (Username) : ";
    getline(cin, namaBaru);
    if (cariusername(data, jumlah, namaBaru) != -1)
    {
        cout << "\nUsername sudah terdaftar. Silakan gunakan username yang lain.\n";
        return;
    }
    cout << "Masukkan Password (ID)   : ";
    cin >> IDBaru;
    cout << "Pilih Kelas (private/reguler): ";
    cin >> kelasBaru;

    if (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE" ||
        kelasBaru == "reguler" || kelasBaru == "Reguler" || kelasBaru == "REGULER")
    {
        data[jumlah].nama = namaBaru;
        data[jumlah].ID = IDBaru;
        data[jumlah].role = "member";
        data[jumlah].kelas.jenis = kelasBaru;
        data[jumlah].kelas.harga = (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE") ? 1000000 : 450000;
        jumlah++;
        cout << "\nRegistrasi berhasil! Silakan Login.\n";
    }
    else
    {
        cout << "\nGagal! Kelas tidak valid.\n";
    }
}

void tambahMember(Akun data[], int &jumlah, int maxKapasitas)
{
    system("cls");
    cout << "==========================================\n";
    cout << "              TAMBAH MEMBER\n";
    cout << "==========================================\n";
    cin.ignore(1000, '\n');
    if (jumlah >= maxKapasitas)
    {
        cout << "Kapasitas penuh!\n";
        return;
    }

    string namaBaru, IDBaru, kelasBaru;

    cout << "Nama Member : ";
    getline(cin, namaBaru);

    if (cariusername(data, jumlah, namaBaru) != -1)
    {
        cout << "\nUsername sudah terdaftar.\n";
        return;
    }

    cout << "Password (ID) Member    : ";
    cin >> IDBaru;
    cout << "Kelas (private/reguler) : ";
    cin >> kelasBaru;

    if (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE" ||
        kelasBaru == "reguler" || kelasBaru == "Reguler" || kelasBaru == "REGULER")
    {
        data[jumlah].nama = namaBaru;
        data[jumlah].ID = IDBaru;
        data[jumlah].role = "member";
        data[jumlah].kelas.jenis = kelasBaru;
        data[jumlah].kelas.harga = (kelasBaru == "private" || kelasBaru == "Private" || kelasBaru == "PRIVATE") ? 1000000 : 450000;
        jumlah++;
        cout << "\nMember berhasil ditambahkan oleh admin!\n";
    }
    else
    {
        cout << "\nGagal! Kelas tidak valid.\n";
    }
}

void lihatMember(Akun data[], int jumlah)
{
    cout << "=================================================================\n";
    cout << "                       DAFTAR MEMBER\n";
    cout << "=================================================================\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "ID" << setw(15) << "Kelas" << "Harga" << endl;
    cout << "=================================================================\n";
    int nomor = 1;
    for (int i = 0; i < jumlah; i++)
    {
        if (data[i].role == "member")
        {
            cout << left << setw(5) << nomor << setw(20) << data[i].nama << setw(15) << data[i].ID << setw(15) << data[i].kelas.jenis << "Rp " << data[i].kelas.harga << "\n";
            nomor++;
        }
    }
    cout << "=================================================================\n";
}

void updateMember(Akun data[], int jumlah)
{
    lihatMember(data, jumlah);
    string cariID;
    cout << "\nMasukkan ID member yang ingin diubah: ";
    cin >> cariID;

    int index = cariIDMember(data, jumlah, cariID);
    if (index != -1)
    {
        cin.ignore(1000, '\n');
        cout << "Username Baru : ";
        getline(cin, data[index].nama);
        cout << "Kelas Baru (private/reguler): ";
        cin >> data[index].kelas.jenis;

        if (data[index].kelas.jenis == "private" || data[index].kelas.jenis == "Private")
        {
            data[index].kelas.harga = 1000000;
            cout << "\nData berhasil diupdate!\n";
        }
        else if (data[index].kelas.jenis == "reguler" || data[index].kelas.jenis == "Reguler")
        {
            data[index].kelas.harga = 450000;
            cout << "\nData berhasil diupdate!\n";
        }
        else
        {
            cout << "\nKelas salah! Gagal update data.\n";
        }
    }
    else
    {
        cout << "\nError: Member dengan ID tersebut tidak ditemukan!\n";
    }
}

void hapusMember(Akun data[], int &jumlah)
{
    lihatMember(data, jumlah);
    string hapusID;
    cout << "\nMasukkan ID member yang ingin dihapus: ";
    cin >> hapusID;

    int index = cariIDMember(data, jumlah, hapusID);
    if (index != -1)
    {
        for (int j = index; j < jumlah - 1; j++)
            data[j] = data[j + 1];
        jumlah--;
        cout << "\nData member berhasil dihapus!\n";
    }
    else
    {
        cout << "\nError: Member dengan ID tersebut tidak ditemukan!\n";
    }
}

void lihatProfil(Akun data[], int jumlah, string namaLogin)
{
    system("cls");
    int index = cariusername(data, jumlah, namaLogin);

    if (index != -1)
    {
        cout << "==========================================\n";
        cout << "              PROFIL ANDA\n";
        cout << "==========================================\n";
        cout << left << setw(10) << "Nama" << ": " << data[index].nama << endl;
        cout << left << setw(10) << "ID" << ": " << data[index].ID << endl;
        cout << left << setw(10) << "Kelas" << ": " << data[index].kelas.jenis << endl;
        cout << left << setw(10) << "Harga" << ": Rp " << data[index].kelas.harga << endl;
        cout << "==========================================\n";
    }
    else
    {
        cout << "Profil tidak ditemukan.\n";
    }
}

void cariKelas(Akun data[], int jumlah)
{
    string cariK;
    cout << "================================================================\n";
    cout << "                   PENCARIAN KELAS\n";
    cout << "================================================================\n";
    cout << "Masukkan kelas yang ingin dicari (private/reguler): ";
    cin >> cariK;
    cout << "\n================================================================\n";
    cout << left << setw(5) << "No" << setw(20) << "Nama" << setw(15) << "Kelas" << endl;
    cout << "================================================================\n";
    int nomor = 1;
    bool adaData = false;
    for (int i = 0; i < jumlah; i++)
    {
        if (data[i].role == "member" && data[i].kelas.jenis == cariK)
        {
            cout << left << setw(5) << nomor << setw(20) << data[i].nama << setw(15) << data[i].kelas.jenis << "\n";
            nomor++;
            adaData = true;
        }
    }
    if (!adaData)
        cout << "Tidak ada data member yang ditemukan di kelas ini.\n";
    cout << "================================================================\n";
}

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
                login(dataAkun, jumlah, statusLogin, namaLogin, roleLogin);
            }
            else if (pilihan == 2)
            {
                registrasi(dataAkun, jumlah, MAX);
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
                cout << "              MENU ADMIN\n";
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
                    tambahMember(dataAkun, jumlah, MAX);
                    system("pause");
                }
                else if (pilihan == 2)
                {
                    system("cls");
                    lihatMember(dataAkun, jumlah);
                    system("pause");
                }
                else if (pilihan == 3)
                {
                    system("cls");
                    updateMember(dataAkun, jumlah);
                    system("pause");
                }
                else if (pilihan == 4)
                {
                    system("cls");
                    hapusMember(dataAkun, jumlah);
                    system("pause");
                }
                else if (pilihan == 5)
                {
                    statusLogin = false;
                    namaLogin = "";
                    roleLogin = "";
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
                cout << "              MENU MEMBER\n";
                cout << "==========================================\n";
                cout << "1. Lihat Profil Saya\n";
                cout << "2. Cari Kelas\n";
                cout << "3. Logout\n";
                cout << "------------------------------------------\n";
                cout << "Pilih menu (1/2/3): ";
                cin >> pilihan;

                if (pilihan == 1)
                {
                    lihatProfil(dataAkun, jumlah, namaLogin);
                    system("pause");
                }
                else if (pilihan == 2)
                {
                    system("cls");
                    cariKelas(dataAkun, jumlah);
                    system("pause");
                }
                else if (pilihan == 3)
                {
                    statusLogin = false;
                    namaLogin = "";
                    roleLogin = "";
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