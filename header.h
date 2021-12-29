#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <conio.h>
#include <iostream>
using namespace std;

typedef struct genre *adrGenre;
typedef struct item *adrItem;
typedef struct elm_relation *adrRelation;

struct list{
    adrGenre firstGenre;
    adrItem firstItem;
    adrRelation firstRelation;
};

struct genre /* Genre */{
    string genre_name;
    adrGenre next;
    list lists;
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

void create_list(list &L);
adrGenre createGenre(list L, string name);
adrItem createItem(list L, string title, int episode);

void insert_parent(list &L, adrGenre G);
adrGenre delete_parent(list &L, adrGenre G);
void showParent(list L);
adrGenre findParent(list L, string G);

void insert_child(list &L, adrItem I);
adrItem delete_child(list &L, adrItem I);
void showChild(list L);
adrItem findChild(list L, string title);

void makeRelation(list &L, string genre, string title);
void deleteRelation(list &L, string genre, string title);

// pengolahan data //
void showTitleGenre(list L, string title);
// Menampilkan semua genre dari suatu title
void markFinished(list L, string title);
// Menandai suatu title bahwa title itu sudah dibaca atau ditonton
void deleteFinished(list L);
// Cari semua item yang telah ditandai finished lalu hapus item tersebut
int totalEpisode(list L, string genreName);

void menu(int input, list &L);

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