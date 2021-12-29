#include "header.h"

int main(){
    list L;
    create_list(L);
    adrGenre  G;
    int inputMenu = 1;
    cout <<"\n\t\033[31m ______      ___      ___   ___  ____   ____    ____       _       _______     ___  ____  " << endl;
    cout <<"\t|_   _ \\   .'   `.  .'   `.|_  ||_  _| |_   \\  /   _|     / \\     |_   __ \\   |_  ||_  _| " << endl;
    cout <<"\t  | |_) | /  .-.  \\/  .-.  \\ | |_/ /     |   \\/   |      / _ \\      | |__) |    | |_/ /   " << endl;
    cout <<"\t  |  __'. | |   | || |   | | |  __'.     | |\\  /| |     / ___ \\     |  __ /     |  __'.   " << endl;
    cout <<"\t _| |__) |\\  `-'  /\\  `-'  /_| |  \\ \\_  _| |_\\/_| |_  _/ /   \\ \\_  _| |  \\ \\_  _| |  \\ \\_ " << endl;
    cout <<"\t|_______/  `.___.'  `.___.'|____||____||_____||_____||____| |____||____| |___||____||____|" << endl << endl;
    while (inputMenu != 0){
        cout << "\t\t\t\t\033[1;91m|\\/|  _. o ._    ._ _   _  ._      " << endl;
        cout << "\t\t\t\t|  | (_| | | |   | | | (/_ | | |_| " << endl << endl;
        cout << "\t\033[37m[1] Lihat bookmark" <<endl; // Show child
        cout << "\t[2] Tambah Genre" <<endl; // Add parent
        cout << "\t[3] Tambah bookmark baru" << endl; // Add child to parent
        cout << "\t[4] Tandai selesai" << endl; // Mark finished
        cout << "\t[5] Hapus yg sudah tamat dari bookmark" << endl; // Delete finished
        cout << "\t[6] Lihat daftar genre" << endl;
        cout << "\t[7] Lihat daftar buku / anime" << endl;
        cout << "\t[8] Hapus Genre" << endl;
        cout << "\t[9] Hapus Buku / Anime" << endl;
        cout << "\t[0] Keluar" << endl << endl;
        cout << "\tMasukkan input : \033[0m";
        cin >> inputMenu;
        menu(inputMenu,L);   
    }
    return 0;
}