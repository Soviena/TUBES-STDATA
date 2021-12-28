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
    listR itemList;
};
struct item /* Buku atau anime */{ 
    adrItem next;
    string ttle;
};
struct listR{
    adrRelation first;
};

struct elm_relation{
    adrGenre nextGenre;
    adrRelation next;
};




#endif // HEADER_H_INCLUDED