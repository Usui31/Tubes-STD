#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "child.h"
#include "parent.h"
#include "relasi.h"
#include <iostream>
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
void deleteFirstRelasi(List_relasi &L, adr_relasi &P);
void deleteLastRelasi(List_relasi &L, adr_relasi &P);
void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P);


adr_relasi alokasi(adr_customer P, adr_kamar C);
void printAllInfo(List_relasi &L);
void printInfoChild(List_relasi L, string customer);
void printInfoParent(List_relasi L, string x);
void printIndukMax(List_relasi &L);
void printIndukMin(List_relasi &L);
void deleteAnak(List_customer &K, List_relasi &L, List_kamar &M, string anak);
void deleteParent(List_customer &K, List_relasi &L, List_kamar &M, string customer);
#endif // RELASI_H_INCLUDED
