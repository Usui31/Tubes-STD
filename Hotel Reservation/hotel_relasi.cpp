#include "relasi.h"

void createList(List_relasi &L){
    first(L) = NULL;
}

void insertLast(List_relasi &L, adr_relasi P){
    if (first(L) == NULL) {
        first(L) = P;
    }else {
        address_relasi Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstRelasi(List_relasi &L, adrrelasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P);
