#include "boolean.h"
#include <stdio.h>
#include "ADTLinkedList.h"
#include <stdlib.h>
#include "ADTFile.h"
#include "ADTSetMap.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyLL (List L){
    return First(L) == NilList;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyLL (List *L){
    First(*L) = NilList;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
addressLL AlokasiLL (char* X){
    addressLL P = (addressLL)malloc(sizeof(ElmtList));
    if (P != NilList) {
        copyString(X, Info(P));
        Next(P) = NilList;
    }
    return P;
}
/* Mengirimkan addressLL hasil AlokasiLL sebuah elemen */
/* Jika AlokasiLL berhasil, maka addressLL tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika AlokasiLL gagal, mengirimkan Nil */
void DealokasiLL (addressLL *P){
    free(*P);
    *P = NilList;
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan d AlokasiLL/pengembalian addressLL P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressLL SearchLL (List L, char* X){
    addressLL P = First(L);
    while (P != NilList){
        if (compareStrings(Info(P), X)){
            return P;
        }
        P = Next(P);
    }
    return NilList;
}
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan addressLL elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, char* X){
    addressLL P = AlokasiLL(X);
    if (P != NilList){
        Next(P) = First(*L);
        First(*L) = P;
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan AlokasiLL sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika AlokasiLL berhasil */
void InsVLast (List *L, char* X){
    addressLL P = AlokasiLL(X);
    if (P != NilList){
        if (IsEmptyLL(*L)){
            First(*L) = P;
        } else {
            addressLL Last = First(*L);
            while(Next(Last) != NilList){
                Last = Next(Last);
            }
            Next(Last) = P;
        }
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan AlokasiLL sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika AlokasiLL berhasil. Jika AlokasiLL gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, char *X){
    if (!IsEmptyLL(*L)){
        addressLL P = First(*L);
        copyString(Info(P), X);
        First(*L) = Next(P);
        DealokasiLL(&P);
    }
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-d AlokasiLL */
void DelVLast (List *L, char *X){
    if (!IsEmptyLL(*L)){
        addressLL P = First(*L), Prec = NilList;
        while (Next(P) != NilList){
            Prec = P;
            P = Next(P);
        }
        copyString(Info(P),X);
        if (Prec == NilList){
            First(*L) = NilList;
        }
        else{
            Next(Prec) = NilList;
        }
        DealokasiLL(&P);
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-d AlokasiLL */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, addressLL P){
    Next(P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah d AlokasiLL  */
/* F.S. Menambahkan elemen ber-addressLL P sebagai elemen pertama */
void InsertAfter (List *L, addressLL P, addressLL Prec){
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah d AlokasiLL  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, addressLL P){
    if (IsEmptyLL(*L)){
        InsertFirst(L, P);
    }
    else {
        addressLL Last = First(*L);
        while (Next(Last) != NilList){
            Last = Next(Last);
        }
        Next(Last) = P;
    }
}
/* I.S. Sembarang, P sudah d AlokasiLL  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, addressLL *P){
    if(!IsEmptyLL(*L)){
        *P = First(*L);
        First(*L) = Next(*P);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, char*X){
    addressLL P = First(*L), Prec = NilList;
    while (P != NilList) {
        // Bandingkan string P->Info dengan X
        int i = 0;
        int isEqual = 1; // Flag untuk cek kesamaan
        while (X[i] != '\0' && Info(P)[i] != '\0') {
            if (X[i] != Info(P)[i]) {
                isEqual = 0;
                break;
            }
            i++;
        }
        if (X[i] != '\0' || Info(P)[i] != '\0') { // Pastikan panjangnya sama
            isEqual = 0;
        }
        
        if (isEqual) { // Jika string cocok
            break;
        }
        
        Prec = P;
        P = Next(P);
    }
    if (P != NilList){
        if (Prec == NilList){
            First(*L) = Next(P);
        } else {
            Next(Prec) = Next(P);
        }
        DealokasiLL(&P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddressLL P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-d AlokasiLL */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, addressLL *P){
    addressLL Last = First(*L), Prec = NilList;
    while(Next(Last) != NilList){
        Prec = Last;
        Last = Next(Last);
    }
    *P = Last;
    if (Prec == NilList){
        First(*L) = NilList;
    }
    else{
        Next(Prec) = NilList;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, addressLL *Pdel, addressLL Prec){
    *Pdel = Next(Prec);
    if (*Pdel != NilList){
        Next(Prec) = Next(*Pdel);
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L, FILE* file){
    //printf("[");
    addressLL P = First(L);
    while (P != NilList){
        fprintf(file, "%s\n", Info(P));
        P = Next(P);
        // if (P != Nil){
        //     printf(",");
        // }
    }
    //printf("]\n");

}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int NbElmt (List L){
    int count = 0;
    addressLL P = First(L);
    while (P != NilList){
        count++;
        P = Next(P);
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
void PrintInfoDebug (List L){
    printf("[");
    addressLL P = First(L);
    while (P != NilList){
        printf("%s", Info(P));
        P = Next(P);
        if (P != NilList){
             printf(",");
        }
    }
    printf("]\n");

}
