#include <iostream>
using namespace std;

void gerak(int &x, int &y, int &baterai, int arah)
{
    if (baterai <= 0)
    {
        cout << "Baterai habis! Robot tidak bisa bergerak." << endl;
        return;
    }

    if (arah == 1)
    {
        x++;
        cout << "Robot bergerak ke kanan" << endl;
    }
    else if (arah == 2)
    {
        x--;
        cout << "Robot bergerak ke kiri" << endl;
    }
    else if (arah == 3)
    {
        y++;
        cout << "Robot bergerak ke atas" << endl;
    }
    else if (arah == 4)
    {
        y--;
        cout << "Robot bergerak ke bawah" << endl;
    }
    else
    {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }
    baterai = baterai - 10;
}

int main()
{
    int x = 0;
    int y = 0;
    int baterai = 100;
    int pilihan;
    cout << "==========================================\n";
    cout << "Posisi awal : (" << x << ", " << y << ") | Baterai : " << baterai << "%" << endl;
    cout << "==========================================\n";

    while (true)
    {
        cout << "1. Gerak Kanan" << endl;
        cout << "2. Gerak Kiri" << endl;
        cout << "3. Gerak Atas" << endl;
        cout << "4. Gerak Bawah" << endl;
        cout << "5. Keluar" << endl;
        cout << "==========================================\n";
        cout << "Masukkan Pilihanmu : ";
        cin >> pilihan;

        if (pilihan == 5)
        {
            cout << "Game Over." << endl;
            break;
        }

        gerak(x, y, baterai, pilihan);
        cout << "Posisi : (" << x << ", " << y << ") | Baterai : " << baterai << "%" << endl;
        system("pause");
    }

    return 0;
}