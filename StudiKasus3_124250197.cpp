#include <iostream>
using namespace std;

void BubbleSort(string array[], int n) {
    string temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void  QuickSort(string array[], int awal, int akhir) {
    int low = awal, high = akhir;
    string pivot = array[(awal + akhir) / 2];
    
    do {
        while (array[low] > pivot) {
            low++;
        }
        while (array[high] < pivot) {
            high--;
        }
        if (low <= high) {
            swap(array[low], array[high]);
            low++;
            high--;
        }
    } while (low <= high);
    if (awal < high) QuickSort (array, awal, high);
    if (low < akhir) QuickSort (array, low, akhir);
}
int main() {
    int n;

    cout << "~~~ PENGURUTAN DATA MAHASISWA ~~~ " << endl;
    cout << "masukkan jumlah mahasiswa: ";
    cin >> n;
    cin.ignore();

    string Namamhs[n];
    string MhsQs[n];

    cout << "========== INPUT NAMA MAHASISWA ==========" << endl;
    for (int i = 0; i < n; i++) {
        cout << "masukkan nama mahasiswa ke- " << (i + 1) << " : ";
        getline(cin, Namamhs[i]);
        MhsQs[i] = Namamhs[i];
    }
    cout << "========== HASIL BUBBLE SORT =============" << endl;
    BubbleSort (Namamhs, n);
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << Namamhs[i] << endl;
    }
    cout << "========== HASIL QUICK SORT ==============" << endl;
    QuickSort(MhsQs, 0, n - 1); 
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " << MhsQs[i] << endl;
    } 
    return 0;
}
