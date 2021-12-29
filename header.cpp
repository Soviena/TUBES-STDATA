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
        L.firstGenre = G->next;
        G->next = NULL;
        return G;
    }
    adrGenre P = L.firstGenre;
    while (P->next != NULL){
        if(P->next == G) break;
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
        L.firstItem = I->next;
        I->next = NULL;
        deleteChildfromAllGenre(L,I);
        return I;
    }
    adrItem P = L.firstItem;
    while (P->next != NULL){
        if(P->next == I) break;
        P = P->next;
    }
    P->next = I->next;
    I->next = NULL;
    deleteChildfromAllGenre(L,I);
    return I;
}

void deleteChildfromAllGenre(list &L, adrItem I){
    adrGenre G = L.firstGenre;
    while(G != NULL){
        deleteRelation(L,G,I);
        G = G->next;
    }
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


void deleteRelation(list &L, adrGenre G, adrItem I){
    adrRelation P = G->lists.firstRelation;
    if(P == NULL) return;
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
            adrItem I;
            int i = 1;
            int eps;
            cout << "\nInput tanpa spasi, gunakan -";
            cout << "\nJudul Buku / Anime\t: "; cin >> title;
            cout << "Volume / Episode\t: "; cin >> eps;
            if(findChild(L,title) == NULL){
                I = createItem(L,title,eps);
                insert_child(L,I);
            }else{
                I = findChild(L,title);
                I->episode = eps;
                cout << "Episode / Volume telah di update!\n";
                break;
            }
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
        case 4:{
            string title;
            cout << "Daftar Buku / Anime\t: ";showChild(L);
            cout << "\nJudul Buku / Anime\t: "; cin >> title;
            markFinished(L,title);
            break;
        }
        case 5:{
            deleteFinished(L);
            cout << "\nBuku / Anime yang sudah tamat telah dihapus!\n";
            break;
        }
        case 6:{
            cout << "\nDaftar genre : ";showParent(L);
            cout << "\n\tPRESS [ENTER] TO CONTINUE\n";
            getch();
            break;
        }
        case 7:{
            cout << "\nDaftar genre : ";showChild(L);
            cout << "\n\tPRESS [ENTER] TO CONTINUE\n";
            getch();
            break;     
        }
        case 8:{
            string genre;
            cout << "Daftar genre : "; showParent(L);
            cout << "\nGenre yang dihapus : ";cin >> genre;
            adrGenre G = findParent(L,genre);
            G = delete_parent(L,G);
            cout << "Genre " << G->genre_name << " Telah dihapus !!\n";
            break;
        }
        case 9:{
            string title;
            cout << "Daftar Buku / Anime : "; showChild(L);
            cout << "\nBuku / Anime yang dihapus : ";cin >> title;
            adrItem I = findChild(L,title);
            I = delete_child(L,I);
            cout << I->title << " Telah dihapus !!\n";
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
    while(P != NULL){
        if(P->finished){
            delete_child(L,P);
        }
        P = P->next;
    }
}

int totalEpisode(list L, adrGenre G){
    adrRelation R = G->lists.firstRelation;
    int total = 0;
    while(R != NULL){
        total += R->item->episode;
        R = R->next;
    }
    return total;
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
            cout << "\t" << i << ". " << R->item->title << " Episode / Volume - " << R->item->episode;
            if(R->item->finished) cout << " SELESAI";
            cout << "\n";
            i++;
            R = R->next;
        }
        cout << "\tTotal Episode / Volume : "<< totalEpisode(L,G) << "\n";
        G = G->next;
    }
}