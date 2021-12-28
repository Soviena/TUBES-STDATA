#include "header.h"



// void create_list(adrList &L){
//     L->firstGenre = NULL;
//     L->firstItem = NULL;
//     L->firstRelation = NULL;
// }

// adrGenre createGenre(adrList L, string name){
//     adrGenre G;
//     G->genre_name = name;
//     G->lists = L;
//     G->next = NULL;
//     return G;
// }

// adrItem createItem(adrList L, string title, int episode){
//     adrItem I;
//     I->title = title;
//     I->episode = episode;
//     I->next = NULL;
//     I->finished = false;
//     return I;
// }

// void insert_parent(adrList &L, adrGenre G){
//     if (L->firstGenre == NULL){
//         L->firstGenre = G;
//     } else {
//         adrGenre P = L->firstGenre;
//         while (P->next != NULL){
//             P = P->next;
//         }
//         P->next = G;
//     }
// }

// adrGenre delete_parent(adrList &L, adrGenre G){
//     if (L->firstGenre == NULL) return NULL;
//     if (L->firstGenre == G){
//         L->firstGenre = NULL;
//     }
//     adrGenre P = L->firstGenre;
//     while (P->next != G){
//         P = P->next;
//     }
//     P->next = G->next;
//     G->next = NULL;
//     return G;
// }

// void showParent(adrList L){
//     adrGenre P = L->firstGenre;
//     while (P != NULL){
//         cout << P->genre_name << endl;
//         P = P->next;
//     } 
// }

// adrGenre findParent(adrList L, string G){
//     adrGenre P = L->firstGenre;
//     while (P->genre_name != G){
//         P = P->next;
//         if(P->genre_name == G){
//             return P;
//         }
//     }
//     return NULL;
// }

// void menu(int input){
//     cout << "" << endl;
//     cout << "[1] Tambah genre" << endl;
//     cout << "[2] Hapus genre" << endl;
//     cout << "[3] Tambah Item" << endl;
//     cout << "[4] Hapus Item" << endl;
// }