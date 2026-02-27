#include <iostream>
using namespace std;

struct Buku {
    string nama;
    int harga;
};

int main() {

    Buku data[6] = {
        {"bahasa inggris", 25000},
        {"bahasa indonesia", 28000},
        {"pkn", 110000},
        {"pemrograman web", 120000},
        {"algoritma", 205000}
    }; 
    // indeks ke-5 untuk sentinel

    int jumlahBuku = 5;
    int pilihan, subPilihan;
    string cari;
    char ulang;
    bool found = false;
    int i = 0;
    int kiri = 0, kanan = jumlahBuku - 1, tengah; // Binary Search

    do {

        cout << "\n===== MENU PENCARIAN =====\n";
        cout << "1. Sequential Search\n";
        cout << "2. Binary Search\n";
        cout << "Pilih metode (1-2): ";
        cin >> pilihan;

        if(pilihan == 1) {

            cout << "\n-- Pilih Jenis Sequential --\n";
            cout << "1. Tanpa Sentinel\n";
            cout << "2. Dengan Sentinel\n";
            cout << "Pilihan (1-2): ";
            cin >> subPilihan;
            cin.ignore();

            cout << "\n===== DAFTAR BUKU =====\n";
            for(int i = 0; i < jumlahBuku; i++) {
                cout << i+1 << ". " << data[i].nama << endl;
            }

            cout << "Masukkan nama buku yang dicari: ";
            getline(cin, cari);

            if(subPilihan == 1) {
                // Sequential tanpa Sentinel
                while (i < jumlahBuku && !found) {
                    if (data[i].nama == cari)
                        found = true;
                    else
                        i++;
                }

                if (found)
                    cout << "Buku ditemukan. Harga: Rp "
                         << data[i].harga << endl;
                else
                    cout << "Buku tidak ditemukan.\n";
            }
            else if(subPilihan == 2) {
                // Sequential dengan Sentinel
                data[jumlahBuku].nama = cari; // pasang sentinel
                i = 0;

                while (data[i].nama != cari) {
                    i++;
                }

                if (i < jumlahBuku)
                    cout << "Buku ditemukan. Harga: Rp "
                         << data[i].harga << endl;
                else
                    cout << "Buku tidak ditemukan.\n";
            }
            else {
                cout << "Pilihan sequential tidak tersedia!\n";
            }

        }
        else if(pilihan == 2) {

            cin.ignore();
            cout << "Masukkan nama buku yang dicari: ";
            getline(cin, cari);

            while (!found && kiri <= kanan) {
                tengah = (kiri + kanan) / 2;

                if (data[tengah].nama == cari) {
                    found = true;
                }
                else if (cari < data[tengah].nama) {
                    kanan = tengah - 1;
                }
                else {
                    kiri = tengah + 1;
                }
            }

            if (found)
                cout << "Buku ditemukan. Harga: Rp "
                     << data[tengah].harga << endl;
            else
                cout << "Buku tidak ditemukan.\n";
        }
        else {
            cout << "Pilihan metode tidak tersedia!\n";
        }

        cout << "\nMau cari buku lagi? (y/t): ";
        cin >> ulang;

    } while(ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih sudah mencari buku.\n";
    return 0;
}