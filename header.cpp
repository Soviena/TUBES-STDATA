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

void makeRelation(list &L, string genre, string title){
    adrGenre G = findParent(L,genre);
    adrItem I = findChild(L, title);

    adrRelation P = G->lists.firstRelation;
    adrRelation R = new elm_relation;
    R->item = I;
    R->next = NULL;
    
    if(P == NULL){
        G->lists.firstRelation = R;
    }else{
        while (P->next != NULL){
            P = P->next;
        }
        P->next = R;
    }
    
}

void deleteRelation(list &L, string genre, string title){
    adrGenre G = findParent(L,genre);
    adrRelation P = G->lists.firstRelation;
    if(P == NULL) return;
    adrItem I = findChild(L, title);
    if(I == NULL) return;

    if(P->item == I){
        G->lists.firstRelation = P->next;
        P->next = NULL;    
    }else{
        while(P->next != NULL){
            if(P->next->item == I){
                adrRelation J = P->next;
                P->next = J->next;
                J->next = NULL;
            }else{
                P = P->next;
            }
        }    
    }
}

void menu(int input, list &L){
    switch (input){
    case 1:
        cout << endl << "Daftar genre" << endl;
        showParent(L);
        getch();
        break;
    case 2:
        string genre;
        cout << endl << "Nama Genre : "; cin >> genre;
        adrGenre G = createGenre(L,genre);
        insert_parent(L, G);
        break;
    }
    
}