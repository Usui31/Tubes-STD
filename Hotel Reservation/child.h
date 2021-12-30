#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED
#include <iostream>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define nil NULL

struct kamar{
    string noKamar;
    string jenisKamar;
    string harga;
    string status;
};

typedef kamar infotype_kamar;
typedef struct elm_kamar *adr_kamar;

struct elm_kamar{
    infotype_kamar info;
    adr_kamar next;
    adr_kamar prev;
};

struct List_kamar{
    adr_kamar first;
    adr_kamar last;
};

void createList(List_kamar &L);
void insertFirst(List_kamar &L, adr_kamar P);
void deleteFirstKamar(List_kamar &L, adr_kamar &P);
void deleteLastKamar(List_kamar &L, adr_kamar &P);
void deleteAfterKamar(List_kamar &L, adr_kamar Prec, adr_kamar &P);


adr_kamar alokasiKamar(string noKamar, string jenisKamar, string harga, string status);
adr_kamar findElm(List_kamar L, string anak);
void printInfo(List_kamar L);

#endif // CHILD_H_INCLUDED
