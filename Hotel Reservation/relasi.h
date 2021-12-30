#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

using namespace std;

#define next(P) P->next
#define first(L) L.first
#define kamar(P) P->kamar
#define customer(P) P->customer
#define Nil NULL

typedef struct elmlist_relasi *adr_relasi;

struct elmlist_relasi{
    adr_relasi next;
    adr_kamar kamar;
    adr_customer customer;
};

struct List_relasi{
    adr_relasi first;
};

void createList(List_relasi &L);
void insertLast(List_relasi &L, adr_relasi P);
void deleteFirstRelasi(List_relasi &L, adrrelasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P);
#endif // RELASI_H_INCLUDED
