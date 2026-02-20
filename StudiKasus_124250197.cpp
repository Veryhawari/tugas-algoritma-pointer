#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "masukan jumlah elemen array yang diinginkan : ";
    cin >> n;

    int angka[n];     
    int *ptr = angka;

    cout << "masukan angka yang diinginkan " << n << " angka : ";
    for (int i = 0; i < n; i++) {
        cin >> *(ptr + i);
    }
    int max = *ptr;
    int min = *ptr;
    int sum = *ptr;
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
        
        sum += *(ptr + i);
    }
    
    float avg = (float)sum / n;
	
    cout << "Nilai Max = " << max << endl;
    cout << "Nilai Min = " << min << endl;
    cout << "Ratarata = " << avg << endl;
    
    return 0;
}
