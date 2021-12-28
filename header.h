#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using std::string, std::cout, std::cin, std::endl;

typedef struct genre *adrGenre;
typedef struct item *adrItem;
typedef struct elm_relation *adrRelation;

struct genre /* Genre */{
    string genre_name;
    adrGenre next;
    list list;
};
struct item /* Buku atau anime */{ 
    adrItem next;
    string ttle;
};

struct elm_relation{
    adrGenre nextGenre;
    adrRelation next;
};

struct list{
    adrGenre firstGenre;
    adrItem firstItem;
    adrRelation firstRelation;
};

list create_list(list &L);
adrGenre createGenre(string name);
adrItem createItem(string title);



/*
○ Insert Parent (5 Poin)
○ Delete Parent (10 Poin)
○ Show Parent (5 Poin)
○ Find Parent (5 Poin)
○ Insert Child of parent X (5 Poin)
○ Delete Child of parent X(10 Poin)
○ Show Child of parent X (5 Poin)
○ Find Child of parent X (5 Poin)
○ Membuat relasi antara parent dan child (15 poin)
○ Menghapus relasi antara parent dan child (15 poin)
○ 2 jenis pengolahan data yang melibatkan child dan parent (total 20 poin),
misal :
    ■ Min/Max from all data parent and child,
    ■ count something from all data parent and child,
    ■ sum something from all data parent and child,
    ■ find child from all data parent,
    ■ update some data from all data parent and child,
    ■ show some data from all data parent and child,
    ■ Dll
*/




#endif // HEADER_H_INCLUDED