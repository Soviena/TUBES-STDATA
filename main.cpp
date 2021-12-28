#include "header.h"

int main(){
    relationList RL;
    genreList GL;
    itemList IL;
    createGenrelist(GL);
    createItemlist(IL);
    createRelationlist(RL);
    adrGenre  G = createGenre(RL,"Action");
    insert_parent(GL,G);
    G = createGenre(RL, "Horror");
    insert_parent(GL,G);
    G = createGenre(RL, "Fantasy");
    insert_parent(GL,G);
    showParent(GL);
    return 0;
}