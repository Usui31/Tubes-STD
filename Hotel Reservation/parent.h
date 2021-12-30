#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED
#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
#define nil NULL

struct customer{
    string nama;
    int usia;
    string noHp;
    string tanggalBooking;
    string totalHarga;
};

typedef customer infotype;
typedef struct elm_customer *adr_customer;

struct elm_customer{
    infotype info;
    adr_customer next;
};

struct List_customer{
    adr_customer first;
    adr_customer last;
};

void createList(List_customer &L);
void insertLast(List_customer &L, adr_customer P, adr_customer Q);
void deleteFirstCustomer(List_customer &L, adr_customer &P);
void deleteLastCustomer(List_customer &L, adr_customer &P);
void deleteAfterCustomer(List_customer &L, adr_customer Prec, adr_customer &P);

adr_customer alokasiCutomer(string nama, int usia, string noHP, string tanggalBooking, string totalHarga);
adr_customer findElm(List_customer L, string x);
void printInfo(List_customer L);

#endif // PARENT_H_INCLUDED
