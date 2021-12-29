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
        cout << P->genre_name << ", ";
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

void insert_child(list &L, adrItem I){
    if (L.firstItem == NULL){
        L.firstItem = I;
    } else {
        adrItem P = L.firstItem;
        while (P->next != NULL){
            P = P->next;
        }
        P->next = I;
    }
}

adrItem delete_child(list &L, adrItem I){
    if (L.firstItem == NULL) return NULL;
    if (L.firstItem == I){
        L.firstItem = NULL;
    }
    adrItem P = L.firstItem;
    while (P->next != I){
        P = P->next;
    }
    P->next = I->next;
    I->next = NULL;
    return I;
}

void showChild(list L){
    adrItem P = L.firstItem;
    while (P != NULL){
        cout << P->title << ", ";
        P = P->next;
    } 
}

adrItem findChild(list L, string title){
    adrItem I = L.firstItem;
    while (I != NULL){
        if(I->title == title){
            return I;
        }
        I = I->next;
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
        case 1:{
            printRelation(L);
            cout << "\n\tPRESS [ENTER] TO CONTINUE\n";
            getch();
            break;
        }
        case 2:{
            string genre;
            cout << "\nInput tanpa spasi, gunakan -";
            cout << endl << "Nama Genre : "; cin >> genre;
            adrGenre G = createGenre(L,genre);
            insert_parent(L, G);
            break;
        }
        case 3:{
            string title;
            string genre;
            int i = 1;
            int eps;
            cout << "\nInput tanpa spasi, gunakan -";
            cout << "\nJudul Buku / Anime\t: "; cin >> title;
            cout << "Volume / Episode\t: "; cin >> eps;
            adrItem I = createItem(L,title,eps);
            insert_child(L,I);
            cout << "Input Genre, masukkan . untuk berhenti" << endl;
            cout << "Genre yang tersedia : "; showParent(L);
            cout << "\n";
            while(genre != "."){
                cout << "Genre "<<i<<"\t: "; cin >> genre;
                if(findParent(L,genre) == NULL){
                    cout << "Genre tidak ada !\n";
                }else{
                    makeRelation(L,genre,title);
                    i++;
                }
            }
            break;
        }
    }
}

void showTitleGenre(list L, string title){
    adrRelation R;
    adrItem I = findChild(L,title);
    if(I == NULL) return;
    adrGenre G = L.firstGenre;
    while(G != NULL){
        R = G->lists.firstRelation;
        while(R != NULL){
            if(R->item == I) cout << G->genre_name << " - ";
            R = R->next;
        }
        G = G->next;
    }
}

void markFinished(list L, string title){
    adrItem I = findChild(L,title);
    if(I == NULL) return;
    I->finished = true;
}

void deleteFinished(list L){
    adrItem P = L.firstItem;
    adrGenre G;
    while(P != NULL){
        G = L.firstGenre;
        if(P->finished){
            while (G != NULL){
                deleteRelation(L,G->genre_name,P->title);
                G = G->next;
            }
            adrItem Q = delete_child(L,P);
            delete Q;
        }
        P = P->next;
    }
}

int totalEpisode(list L, string genreName){
    adrGenre G = findParent(L,genreName);
    adrRelation R = G->lists.firstRelation;
    int totalEpisode = 0;
    while(R != NULL){
        totalEpisode += R->item->episode;
        R = R->next;
    }
    return totalEpisode;
}

void printRelation(list L){
    adrGenre G = L.firstGenre;
    if(G == NULL) return;
    adrRelation R;
    int i;
    while(G != NULL){
        cout << "\n\tGENRE : " << G->genre_name << "\n";
        R = G->lists.firstRelation;
        i = 1;
        while (R != NULL){   
            cout << "\t" << i << ". " << R->item->title << " Episode - " << R->item->episode;
            if(R->item->finished) cout << " SELESAI";
            cout << "\n";
            i++;
            R = R->next;
        }
        cout << "\n";
        G = G->next;
    }
}