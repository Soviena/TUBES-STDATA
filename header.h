#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct genre *adrGenre;
typedef struct item *adrItem;
typedef struct elm_relation *adrRelation;
//tes
struct genre /* Genre */{
    string genre_name;
    adrGenre next;
    relationList lists;
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

struct relationList{
    adrRelation first;
};

struct genreList{
    adrGenre first;
};

struct itemList{
    adrItem first;
};

void createRelationlist(relationList &RL);
void createItemlist(itemList &IL);
void createGenrelist(genreList &GL);

adrGenre createGenre(genreList &GL, string name);
adrItem createItem(itemList &IL, string title, int episode);

void insert_parent(genreList &GL, adrGenre G);
adrGenre delete_parent(genreList &GL, adrGenre G);
void showParent(genreList GL);
adrGenre findParent(genreList L, string G);

void insert_child(itemList &IL, adrItem I);
adrItem delete_child(itemList &IL, adrItem I);
void showChild(itemList IL);
adrItem findChild(itemList IL, genreList GL, string genre, string title);

void makeRelation(relationList &RL, itemList IL, genreList GL, string genre, string title);
void deleteRelation(relationList &RL, itemList IL, genreList GL, string genre, string title);

// pengolahan data //
void showTitleGenre(itemList IL, genreList GL, string title);
// Menampilkan semua genre dari suatu title
void markFinished(itemList IL, string title);
// Menandai suatu title bahwa title itu sudah dibaca atau ditonton
void deleteFinished(itemList IL);
// Cari semua item yang telah ditandai finished lalu hapus item tersebut
void totalEpisode(genreList GL, string genreName);

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