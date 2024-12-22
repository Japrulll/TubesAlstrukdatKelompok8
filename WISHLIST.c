#include <stdio.h>
#include "./Folder ADT/ADTLinkedList.h"
#include "./Folder ADT/mesinkarakter.h"
#include "./Folder ADT/mesinkata.h"
#include "./Folder ADT/ADTFile.h"
#include "./Folder ADT/ADTStack.h"


void WISHLISTADD (List *wishlist, DinamicItemList items){
    char barang[100];
    printf("Masukkan nama barang yang ingin ditambah : ");
    AS_WORDBLANKS();
    while ( !EndWord ) {
        ADVWORDBLANKS();
    }

    for (int i=0;i<CurrentWord.Length;i++){
        barang[i] = CurrentWord.TabWord[i];
    }
    barang[CurrentWord.Length] = '\0';

    if(!isIn(items,barang)){
        printf("Tidak ada barang dengan nama %s\n",barang);
    }
    else{
        if (IsEmptyLL(*wishlist)){
            InsVFirst(wishlist,barang);
            addressLink P = First(*wishlist);
            printf("Berhasil menambahkan ");
            printf("%s", Info(P));
            printf(" ke dalam wishlist!\n");
        }
        else {
            if((SearchLL(*wishlist, barang))==NilLL){
                InsVLast(wishlist,barang);
                addressLink P = SearchLL(*wishlist, barang);
                printf("Berhasil menambahkan ");
                printf("%s", Info(P));
                printf(" ke dalam wishlist.\n");
            }
            else{
                addressLink P = SearchLL(*wishlist, barang);
                printf("%s", Info(P));
                printf(" sudah ada di dalam wishlist!\n");
            }   
        }
    }
}


void WISHLISTREMOVE (List *wishlist){
    char barang[100];

    if(IsEmptyLL(*wishlist)){
        printf("Wishlist anda sudah kosong!\n");
    }
    else {
        printf("Anda dapat melakukan penghapusan barang yang ada pada wishlist.\n");
        printf("Ada 2 pilihan metode penghapusan :\n");
        printf("1. Dengan memasukkan nama barang yang ingin dihapus\n");
        printf("Atau\n");
        printf("2. Dengan memasukkan indeks barang dalam wishlist yang ingin dihapus\n");
        
        int pilihan=0;
        while(pilihan<1 || pilihan>2){
            printf("Masukkan pilihan anda (1) atau (2) : ");
            AS_WORD();
            // while ( !EndWord ) {
            //     ADVWORD();
            // }
            pilihan = StrToInt(CurrentWord.TabWord);
            if (pilihan<1 || pilihan>2){
                printf("Input tidak valid. Mohon ulangi! ");
            }
        }
        if (pilihan==1){
            printf("Masukkan nama barang yang ingin dihapus : ");
            AS_WORDBLANKS();
            while ( !EndWord ) {
                ADVWORD();
            }
            
            for (int i=0;i<CurrentWord.Length;i++){
                barang[i] = CurrentWord.TabWord[i];
            }
            barang[CurrentWord.Length] = '\0';
            
            if((SearchLL(*wishlist, barang))==NilLL){
                printf("Penghapusan gagal dilakukan! ");
                printf("%s", barang);
                printf(" tidak ditemukan di dalam wishlist.\n");
            }
            else{
                DelP(wishlist,barang);
                printf("%s", barang);
                printf(" berhasil dihapus dari wishlist!\n");
            }
        }
        else if (pilihan==2){
            int indeks = 0;
            while(indeks > NbElmt(*wishlist) || indeks < 1){
                printf("Masukkan indeks barang yang ingin dihapus : ");
                AS_WORD();
                while ( !EndWord ) {
                    ADVWORD();
                }
                indeks = StrToInt(CurrentWord.TabWord);
                if (indeks > NbElmt(*wishlist) || indeks < 1){
                    printf("Input anda tidak valid. Silakan ulang! ");
                }
            }
            addressLink P = First(*wishlist);
            int idx = 1;
            while (idx < indeks) {
                P = Next(P);
                idx++;
            }
            printf("%s", Info(P));
            printf(" berhasil dihapus dari wishlist!\n");
            DelP(wishlist,Info(P));
        }
    }
}


void WISHLISTSWAP (List *wishlist){
    int i=0,j=0;

    if(NbElmt(*wishlist) == 1 || NbElmt(*wishlist) == 0){
        printf("Anda tidak dapat melakukan wishlist swap saat ini\n");
        printf("karena wishlist anda kosong atau hanya berisi 1 barang!\n");
    }
    else{
        printf("Anda diminta memasukkan indeks barang yang ingin dilakukan swap! (i) dan (j)\n");
        while(i>NbElmt(*wishlist) || i<1 || j>NbElmt(*wishlist) || j<1){
            printf("Indeks (i) = ");
            AS_WORD();
            // while ( !EndWord ) {
            //     ADVWORD();
            // }
            i = StrToInt(CurrentWord.TabWord);
            
            printf("Indeks (j) = ");
            AS_WORD();
            while ( !EndWord ) {
                ADVWORD();
            }
            j = StrToInt(CurrentWord.TabWord);

            if(i>NbElmt(*wishlist) || i<1 || j>NbElmt(*wishlist) || j<1){
                printf("indeks i atau j atau keduanya tidak valid.\n");
                printf("Silakan masukkan lagi input indeks yang valid!");
            }
        }

        addressLink P1 = First(*wishlist);
        addressLink P2 = First(*wishlist);
        int idx = 1;

        // Temukan elemen ke-i
        while (P1 != NilLL && idx < i) {
            P1 = Next(P1);
            idx++;
        }

        // Reset indeks dan cari elemen ke-j
        idx = 1;
        while (P2 != NilLL && idx < j) {
            P2 = Next(P2);
            idx++;
        }
        char temp[100];
        int k;

        for (k = 0; k < 100; k++) {
            temp[k] = P1->info[k];
        }

        for (k = 0; k < 100; k++) {
            P1->info[k] = P2->info[k];
        }

        for (k = 0; k < 100; k++) {
            P2->info[k] = temp[k];
        }
        printf("Berhasil menukar barang pada indeks %d dan %d!\n", i, j);
    }
}


void WISHLISTCLEAR (List *wishlist){
    CreateEmptyLL (wishlist);
    printf("Wishlist telah dikosongkan!\n");
}


void WISHLISTSHOW (List *wishlist){
    if (IsEmptyLL(*wishlist)){
        printf("Wishlist kamu kosong!\n");
    }
    else{
        addressLink P = First(*wishlist);
        int nomor=1;
        printf("Berikut ini adalah isi wishlist kamu: \n");
        while (P != NilLL){
            printf("%d ",nomor);
            printf("%s\n", Info(P));
            nomor++;
            P = Next(P);
        }
    }
}


/*
int main(){
    List wishlist;
    CreateEmptyLL (&wishlist);
    int mulai = 1;
    while (mulai==1){
        int masukan;
        printf("mau apa? : ");
        scanf("%d",&masukan);
        getchar();
        if (masukan==1){
            WISHLISTADD (&wishlist);
        }
        else if (masukan==2){
            WISHLISTREMOVE (&wishlist);
        }
        else if (masukan==3){
            WISHLISTSHOW (&wishlist);
        }
        else if (masukan==4){
            WISHLISTSWAP (&wishlist);
        }
        else if (masukan==4){
            mulai = 0;
        }
        else{
            printf("input tidak valid. Masukkan ulang!");
        }
    }

    return 0;
}
*/
