# TUBES-STDATA : Sistem Bookmark untuk Buku dan Anime
Menggunakan Multi Linked List jenis N ke N tipe 2

![NtoNtype2](https://github.com/Soviena/TUBES-STDATA/blob/main/img/NtoNtype2.png)


## Kelompok
1. Nama   : Muhammad Rovino Sanjaya - 1302204044
2. Nama   : Muhammad Rizqi Anshari - 1302204024

### Daftar fungsi yang dikerjakan
```cpp
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
void deleteRelation(list &L, adrGenre G, adrItem I);
void deleteChildfromAllGenre(list &L, adrItem I);
void showTitleGenre(list L, string title);
void markFinished(list L, string title);
void deleteFinished(list L);
int totalEpisode(list L, adrGenre G);
void menu(int input, list &L);
void printRelation(list L);
```
# Demo Aplikasi
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(1).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(2).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(3).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(4).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(5).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(6).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(7).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(8).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(9).png)
![Demo](https://github.com/Soviena/TUBES-STDATA/blob/main/img/demo%20(10).png)



