#include<iostream>
using namespace std;
 
struct Mahasiswa{
    string npm, nama;
    int nilai;
};

void countingSort(Mahasiswa mhs[], int n){
    const int max_nilai = 100;
    int count[max_nilai + 1] = {0};
    Mahasiswa  output[n];

    for(int i = 0;i < n;i++) count[mhs[i].nilai]++;
    for(int i = 1;i<= max_nilai; i++) count[i]+= count[i-1];
    for(int i = n - 1;i>=0;i--) 
      output[--count[mhs[i].nilai]] = mhs[i];
    for(int i = 0;i < n; i++) mhs[i] = output[i];
}

void print(Mahasiswa mhs[], int n){
    for (int i = 0;i < n; i++)
    cout << mhs[i].npm << "-" << 
mhs[i].nama << "-" << mhs[i].nilai <<endl;
} 

int main(){
    Mahasiswa mhs[] = {
        {"G1A024001", "LUDVIE", 87},
        {"G1A024002", "AHSAN", 98},
        {"G1A024003", "AGRA", 89},
        {"G1A024004", "AZKA", 78},
        {"G1A024005", "FEBRIYAN", 90},
        {"G1A024006", "FADLI", 88},
        {"G1A024007", "IQBAL", 91},
        {"G1A024008", "SULTHON", 95},
        {"G1A024OO9", "RAYYAN", 93},
        {"G1A024010", "RAFI", 85}
    };

    int n = sizeof(mhs)/sizeof(mhs[0]);
    countingSort(mhs, n);
    cout << "\nData berdasarkan nilai terkecil sampai terbesar:\n";
    print(mhs, n);

    return 0;
}