#include "header.h"

int main(){
    list L;
    create_list(L);
    adrGenre  G = createGenre(L,"Action");
    insert_parent(L,G);
    G = createGenre(L, "Horror");
    G = createGenre(L, "Fantasy");
    showParent(L);
    return 0;
}