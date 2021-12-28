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
    string title;
    int episode; // total episode atau volume pada title
    bool finished;
};

struct elm_relation{
    adrItem item;
    adrRelation next;
};

struct list{
    adrGenre firstGenre;
    adrItem firstItem;
    adrRelation firstRelation;
};

void create_list(list &L);
adrGenre createGenre(string name);
adrItem createItem(string title, int episode);

void insert_parent(list &L, adrGenre G);
adrGenre delete_parent(list &L, adrGenre G);
void showParent(list L);
adrGenre findParent(list L, string G);

void insert_child(list &L, adrItem I);
adrItem delete_child(list &L, adrItem I);
void showChild(list L);
adrItem findChild(list L, string genre, string title);

void makeRelation(list &L, string genre, string title);
void deleteRelation(list &L, string genre, string title);

// pengolahan data //
void showTitleGenre(list L, string title);
// Menampilkan semua genre dari suatu title
void markFinished(list L, string title);
// Menandai suatu title bahwa title itu sudah dibaca atau ditonton
void deleteFinished(list L);
// Cari semua item yang telah ditandai finished lalu hapus item tersebut
void totalEpisode(list L, string genreName);

/*
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