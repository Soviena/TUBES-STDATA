#include "header.h"

int main(){
    list L;
    create_list(L);
    adrGenre  G;
    int inputMenu = 1;
    cout <<"\n\t\033[31m██████╗  ██████╗  ██████╗ ██╗  ██╗███╗   ███╗ █████╗ ██████╗ ██╗  ██╗" << endl;
    cout <<"\t██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝████╗ ████║██╔══██╗██╔══██╗██║ ██╔╝" << endl;
    cout <<"\t██████╔╝██║   ██║██║   ██║█████╔╝ ██╔████╔██║███████║██████╔╝█████╔╝ " << endl;
    cout <<"\t██╔══██╗██║   ██║██║   ██║██╔═██╗ ██║╚██╔╝██║██╔══██║██╔══██╗██╔═██╗ " << endl;
    cout <<"\t██████╔╝╚██████╔╝╚██████╔╝██║  ██╗██║ ╚═╝ ██║██║  ██║██║  ██║██║  ██╗" << endl;
    cout <<"\t╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝" << endl << endl;
    while (inputMenu != 0){
        cout << "\t\t\t\033[1;91m|\\/|  _. o ._    ._ _   _  ._      " << endl;
        cout << "\t\t\t|  | (_| | | |   | | | (/_ | | |_| " << endl << endl;
        cout << "\t\033[37m[1] Lihat bookmark" <<endl; // Show child
        cout << "\t[2] Tambah Genre" <<endl; // Add parent
        cout << "\t[3] Tambah bookmark baru" << endl; // Add child to parent
        cout << "\t[4] Tandai selesai" << endl; // Mark finished
        cout << "\t[5] Hapus yg sudah tamat dari bookmark" << endl; // Delete finished
        cout << "\t[0] Keluar" << endl << endl;
        cout << "\tMasukkan input : \033[0m";
        cin >> inputMenu;
        menu(inputMenu,L);   
    }

    return 0;
}