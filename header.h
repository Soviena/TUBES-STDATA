#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct genre *adrGenre;
typedef struct item *adrItem;
typedef struct elm_relation *adrRelation;
typedef struct list *adrList;

struct genre /* Genre */{
    string genre_name;
    adrGenre next;
    adrList lists;
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

void create_list(adrList &L);
adrGenre createGenre(adrList L, string name);
adrItem createItem(adrList L, string title, int episode);

void insert_parent(adrList &L, adrGenre G);
adrGenre delete_parent(adrList &L, adrGenre G);
void showParent(adrList L);
adrGenre findParent(adrList L, string G);

void insert_child(adrList &L, adrItem I);
adrItem delete_child(adrList &L, adrItem I);
void showChild(adrList L);
adrItem findChild(adrList L, string genre, string title);

void makeRelation(adrList &L, string genre, string title);
void deleteRelation(adrList &L, string genre, string title);

// pengolahan data //
void showTitleGenre(adrList L, string title);
// Menampilkan semua genre dari suatu title
void markFinished(adrList L, string title);
// Menandai suatu title bahwa title itu sudah dibaca atau ditonton
void deleteFinished(adrList L);
// Cari semua item yang telah ditandai finished lalu hapus item tersebut
void totalEpisode(adrList L, string genreName);

void menu(int input);

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