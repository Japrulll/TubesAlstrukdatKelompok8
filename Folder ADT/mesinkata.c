#include <stdio.h>

#include "boolean.h"
#include "mesinkarakter.h"
#include "ADTItem.h"
#include "mesinkata.h"

boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   // hanya untuk awal kata saja, blank di dalam kalimat tetap terbaca */
   while (currentChar == BLANK){
        ADV();
    }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
   //IgnoreBlanks();
   if ( currentChar == MARK ){
        EndWord = true;
   }
   else{
        EndWord = false;
        CopyWord();
   }
}

void CopyWord(){
    int idx = 0;
    while ((currentChar != MARK) && (idx < NMax)){
        CurrentWord.TabWord[idx] = GetCC();
        ADV();
        idx++;
    } 
    CurrentWord.Length = idx;
    
//    CurrentWord.Length = idx;
}
boolean isWordEqual(Word word, char* str) {
    int i = 0;
    while (i < word.Length && str[i] != '\0') {
        if (word.TabWord[i] != str[i]) {
            return false;
        }
        i++;
    }
    return (i == word.Length && str[i] == '\0');
}

boolean isIn(Word word, DinamicItemList list_barang) {
    for (int i = 0; i < Length(list_barang); i++) {
        int j = 0;
        boolean match = true;
        while (j < word.Length && list_barang.items[i].name[j] != '\0') {
            if (word.TabWord[j] != list_barang.items[i].name[j]) {
                match = false;
                break;
            }
            j++;
        }
        if (match && j == word.Length && list_barang.items[i].name[j] == '\0') {
            return true;
        }
    }
    return false;
}





// int main() {
//     // Memulai pembacaan kata
//     STARTWORD();
//     while (!EndWord) {
//         ADVWORD();
//     }
//     printf("%s", CurrentWord.TabWord);

//     // Memberi tahu bahwa proses selesai
//     //printf("End of input reached.\n");

//     return 0;
// }