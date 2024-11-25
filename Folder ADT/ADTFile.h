#ifndef USER_ITEM_H
#define USER_ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include "ADTUser.h"
#include "ADTItem.h"

#define MAX_LEN 100

void copyString(char* src, char* dest);
/*menyalin string dari source ke destination sebagai pengganti strcpy
  I.S. src merupakan source dan dest merupakan destination dari source
  F.S. src telah disalin ke dest*/

void display(DinamicItemList *itemlist, StaticUserList *userlist);
/*fungsi untuk menampilkan isi daftar barang dan user ke layar*/

void constructfilepath(char*filepath, char*basepath, char*filename);
//fungsi constructfilepath berfungsi untuk menggabungkan dua string dan membentuk path file*/

void readline(FILE *file, char *buffer);
/*fungsi readline berfungsi untuk membaca file ke buffer string*/

void writeToFile(FILE *file, DinamicItemList *itemList, StaticUserList *userList);
/*fungsi ini berfungsi untuk menyimpan data dari DinamicItemList dan StaticUserList ke file
ditulis detail barang dan detail user ke file*/

#endif