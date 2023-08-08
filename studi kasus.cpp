#include <iostream>
#include <string>

using namespace std;

const int JUMLAH_WARNA_MAKS = 6;  // Jumlah maksimum warna yang tersedia
const int JUMLAH_KOMBINASI_MAKS = 20;  // Jumlah maksimum kombinasi warna yang dihasilkan

// Fungsi untuk menghasilkan kombinasi warna
void hasilkanKombinasiWarna(string warna[], int n, int r, string kombinasi[][3], int& jumlahKombinasi, int start, string kombinasiSaatIni[]) {
    if (r == 0) {
        for (int i = 0; i < n; i++) {
            kombinasi[jumlahKombinasi][i] = kombinasiSaatIni[i];
        }
        jumlahKombinasi++;
        return;
    }

    for (int i = start; i <= n - r; i++) {
        kombinasiSaatIni[r - 1] = warna[i];
        hasilkanKombinasiWarna(warna, n, r - 1, kombinasi, jumlahKombinasi, i + 1, kombinasiSaatIni);
    }
}

int main() {
    string warna[JUMLAH_WARNA_MAKS] = { "Merah", "Biru", "Kuning", "Hijau", "Ungu", "Hitam" };
    int jumlahWarnaDipilih = 3;  // Jumlah warna yang akan dipilih untuk setiap kombinasi

    string kombinasiWarna[JUMLAH_KOMBINASI_MAKS][3];
    int jumlahKombinasi = 0;
    string kombinasiSaatIni[JUMLAH_WARNA_MAKS];

    hasilkanKombinasiWarna(warna, JUMLAH_WARNA_MAKS, jumlahWarnaDipilih, kombinasiWarna, jumlahKombinasi, 0, kombinasiSaatIni);

    cout << "Kombinasi warna yang mungkin:" << endl;
    for (int i = 0; i < jumlahKombinasi; i++) {
        cout << i + 1 << ". ";
        for (int j = 0; j < jumlahWarnaDipilih; j++) {
            cout << kombinasiWarna[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
