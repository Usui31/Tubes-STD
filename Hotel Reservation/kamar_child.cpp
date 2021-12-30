#include "child.h"

void createList(List_kamar &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertFirst(List_kamar &L, adr_kamar P){
    if ((first(L) == NULL) && (last(L) == NULL)) {
        first(L) = P;
        last(L) = P;
    }else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteFirstKamar(List_kamar &L, adr_kamar &P);
void deleteLastKamar(List_kamar &L, adr_kamar &P);
void deleteAfterKamar(List_kamar &L, adr_kamar Prec, adr_kamar &P);
