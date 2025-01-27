#ifndef setmap_H
#define setmap_H

#include "boolean.h"

#define NilMap 0
#define Undefined 0

typedef char keytype[100];
typedef int valuetype;
typedef int addressMap;

typedef struct {
	keytype nama_item;
	valuetype qty;
} infotype;

typedef struct {
	infotype Elements[100];
	addressMap Count;
} Map;


boolean string_compare(char *str1, char *str2);
void copy_string(char *from, char *to);
/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap (Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFullMap (Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Value(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void DeleteMap(Map *M, keytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

void UpdateMap(Map *M, keytype k, valuetype v);
/* Menambahkan elemen baru ke Map jika belum ada,
atau memperbarui nilai qty elemen yang ada jika ditemukan key yang cocok.*/

void bubbleSort_Map(Map *map);
/* Mengurutkan elemen Map berdasarkan qty secara descending*/

#endif