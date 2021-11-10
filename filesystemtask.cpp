// Mata kuliah : Pemrograman Dasar
// Tugas       : Pengolahan File Teks
// Author      : Maulana Anjari Anggorokasih
// NIM         : 21/477748/TK/52619
// Kelas       : B
#include <iostream> // include library untuk input output
#include <fstream>  // include library untuk pengolahan file
#include <string>   // include library untuk penggunaan string
using namespace std;
int main() // aplikasi utama
{
    // stream untuk mengakses file
    fstream log, error, warning, information;
    // buka semua file, jika file tidak ditemukan maka file akan otomatis dibuat
    log.open("event_log.txt", ios::in); // hanya read file
    information.open("information.txt", ios::out); // write file
    warning.open("warning.txt", ios::out); // write file
    error.open("error.txt", ios::out); // write file
    if(!log.fail()){ // fail() -> untuk memeriksa suatu kesalahan pada operasi file
        string line; // untuk menampung baris dari fungsi getline
        // while untuk loop isi text per baris dari file log
        while (getline(log, line)){ // fungsi getline untuk membaca semua baris file satu-persatu sampai akhir
                // bagian ini untuk mencari suatu kata di tiap baris, fungsinya untuk memilah
                size_t info = line.find("Information,");
                size_t warn = line.find("Warning,");
                size_t err = line.find("Error,");
                // cek apakah di baris itu benar ada kata Information
                if(info!=string::npos)
                {
                    // cek apakah file information.txt benar dibuka
                    if(information.is_open()){ 
                        // jika benar maka tulis isi satu baris file log terpilih ke file information.txt
                        // akan terus diulangi sesuai while diatas
                        information<<line<<endl; 
                    }else{
                        // jika file information.txt tidak benar dibuka
                        cout<<"File information tidak ditemukan"<<endl;
                    }
                }
                // cek apakah di baris itu benar ada kata Warning
                if(warn!=string::npos)
                {
                    // cek apakah file warning.txt benar dibuka
                    if(warning.is_open()){ 
                        // jika benar maka tulis isi satu baris file log terpilih ke file warning.txt
                        // akan terus diulangi sesuai while diatas
                        warning<<line<<endl;
                    }else{
                        // jika file warning.txt tidak benar dibuka
                        cout<<"File warning tidak ditemukan"<<endl;
                    }
                }
                // cek apakah di baris itu benar ada kata Error
                if (err!=string::npos)
                {
                    if(error.is_open()){ // cek apakah file error.txt benar dibuka
                        // jika benar maka tulis isi satu baris file log terpilih ke file error.txt
                        // akan terus diulangi sesuai while diatas
                        error<<line<<endl;
                    }else{
                        // jika file error.txt tidak benar dibuka
                        cout<<"File error tidak ditemukan"<<endl;
                    }
                }
        }
        // tutup semua file
        warning.close();
        error.close();
        information.close();
    }else{
        // jika file log gagal dibuka
        cout<<"File Log tidak ditemukan"<<endl;
    }
    // tutup file event_log
    log.close();
    // program berakhir
    system("pause>0");
}
