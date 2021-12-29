#include "header.h"

void create_list(list &L){
    L.firstGenre = NULL;
    L.firstItem = NULL;
    L.firstRelation = NULL;
}

adrGenre createGenre(list L, string name){
    adrGenre G = new genre;
    G->genre_name = name;
    G->lists = L;
    G->next = NULL;
    return G;
}

adrItem createItem(list L, string title, int episode){
    adrItem I = new item;
    I->title = title;
    I->episode = episode;
    I->next = NULL;
    I->finished = false;
    return I;
}

void insert_parent(list &L, adrGenre G){
    if (L.firstGenre == NULL){
        L.firstGenre = G;
    } else {
        adrGenre P = L.firstGenre;
        while (P->next != NULL){
            P = P->next;
        }
        P->next = G;
    }
}

adrGenre delete_parent(list &L, adrGenre G){
    if (L.firstGenre == NULL) return NULL;
    if (L.firstGenre == G){
        L.firstGenre = NULL;
    }
    adrGenre P = L.firstGenre;
    while (P->next != G){
        P = P->next;
    }
    P->next = G->next;
    G->next = NULL;
    return G;
}

void showParent(list L){
    adrGenre P = L.firstGenre;
    while (P != NULL){
        cout << P->genre_name << endl;
        P = P->next;
    } 
}

adrGenre findParent(list L, string G){
    adrGenre P = L.firstGenre;
    while (P != NULL){
        if(P->genre_name == G){
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void menu(int input, list &L){
    switch (input){
    case 1:
        cout << endl << "Daftar genre" << endl;
        showParent(L);
        break;
    case 2:
        string genre;
        cout << endl << "Nama Genre : "; cin >> genre;
        adrGenre G = createGenre(L,genre);
        insert_parent(L, G);
        break;
    }
    
}