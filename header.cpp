#include "header.h"

void create_list(list &L){
    L.firstGenre = NULL;
    L.firstItem = NULL;
    L.firstRelation = NULL;
}
adrGenre createGenre(list L, string name){
    adrGenre G;
    G->genre_name = name;
    G->list = L;
    G->next = NULL;
    return G;
}

adrItem createItem(list L, string title, int episode){
    adrItem I;
    I->title = title;
    I->episode = episode;
    I->next = NULL;
    I->finished = false;
    return I;
}

void insert_parent(list &L, adrGenre G){

}

adrGenre delete_parent(list &L, adrGenre G){

}

void showParent(list L){

}

adrGenre findParent(list L, string G){
    
}