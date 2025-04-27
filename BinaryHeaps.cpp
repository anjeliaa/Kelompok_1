#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string npm;

    // Constructor kosong (dibutuhkan oleh priority_queue)
    Mahasiswa() {}

    Mahasiswa(string nama, string npm) : nama(nama), npm(npm) {}
};

// Custom comparator untuk priority_queue (supaya min-heap berdasarkan NPM)
struct CompareMahasiswa {
    bool operator()(const Mahasiswa& a, const Mahasiswa& b) {
        return a.npm > b.npm; // NPM kecil lebih prioritas
    }
};

int main() {
    priority_queue<Mahasiswa, vector<Mahasiswa>, CompareMahasiswa> heap;

    // Masukkan data mahasiswa
    heap.push(Mahasiswa("Anjelia Febiliyanti", "G1A024053"));
    heap.push(Mahasiswa("Nurmelizah", "G1A024023"));
    heap.push(Mahasiswa("Ikhsan Rihan Farli", "G1A024083"));
    heap.push(Mahasiswa("M. Iqbal Zafarullah", "G1A024007"));
    heap.push(Mahasiswa("Ali Akbar Bermano", "G1A024041"));

    // Tampilkan mahasiswa berdasarkan NPM terkecil
    cout << "Mahasiswa berdasarkan NPM terkecil:\n";
    while (!heap.empty()) {
        Mahasiswa mhs = heap.top();
        cout << mhs.nama << " (" << mhs.npm << ")" << endl;
        heap.pop();
    }

    return 0;
}