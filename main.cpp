#include "header.h"

int main(){
    list L;
    create_list(L);
    adrGenre  G;
    adrItem I;

    G = createGenre(L, "api");
    insert_parent(L, G);
    G = L.firstGenre;
    cout<<(G->genre_name)<<endl;

    G = createGenre(L, "air");
    insert_parent(L, G);
    G = L.firstGenre;
    cout<<(G->next)->genre_name<<endl;

    I = createItem(L, "1", 12);
    insert_child(L,I);
    I = L.firstItem;
    cout<<"["<<(I->title);
    cout<<"-"<<(I->episode)<<"-";
    cout<<(I->finished)<<" ]"<<endl;

    I = createItem(L, "2", 24);
    insert_child(L,I);
    I = L.firstItem;
    cout<<"["<<((I->next)->title);
    cout<<"-"<<((I->next)->episode)<<"-";
    cout<<((I->next)->finished)<<" ]"<<endl;
    
    // int inputMenu = 1;
    // cout <<"\n\t\033[31m██████╗  ██████╗  ██████╗ ██╗  ██╗███╗   ███╗ █████╗ ██████╗ ██╗  ██╗" << endl;
    // cout <<"\t██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝████╗ ████║██╔══██╗██╔══██╗██║ ██╔╝" << endl;
    // cout <<"\t██████╔╝██║   ██║██║   ██║█████╔╝ ██╔████╔██║███████║██████╔╝█████╔╝ " << endl;
    // cout <<"\t██╔══██╗██║   ██║██║   ██║██╔═██╗ ██║╚██╔╝██║██╔══██║██╔══██╗██╔═██╗ " << endl;
    // cout <<"\t██████╔╝╚██████╔╝╚██████╔╝██║  ██╗██║ ╚═╝ ██║██║  ██║██║  ██║██║  ██╗" << endl;
    // cout <<"\t╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝" << endl << endl;
    // while (inputMenu != 0){
    //     cout << "\t\t\t\033[1;91m|\\/|  _. o ._    ._ _   _  ._      " << endl;
    //     cout << "\t\t\t|  | (_| | | |   | | | (/_ | | |_| " << endl << endl;
    //     cout << "\t\033[37m[1] Lihat bookmark" <<endl; // Show child
    //     cout << "\t[2] Tambah Genre" <<endl; // Add parent
    //     cout << "\t[3] Tambah bookmark baru" << endl; // Add child to parent
    //     cout << "\t[4] Tandai selesai" << endl; // Mark finished
    //     cout << "\t[5] Hapus yg sudah tamat dari bookmark" << endl; // Delete finished
    //     cout << "\t[0] Keluar" << endl << endl;
    //     cout << "\tMasukkan input : \033[0m";
    //     cin >> inputMenu;
    //     menu(inputMenu,L);   
    // }

    return 0;
}