#include "parent.h"

void createList(List_customer &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertLast(List_customer &L, adr_customer P, adr_customer Q){
    if(first(L) == NULL && last(L) == NULL) {
        first(L) = P;
        next(P) = Q;
        next(Q) = P;
        last(L) = Q;
    }else {
        next(last(L)) = P;
        next(P) = Q;
        next(Q) = first(L);
        last(L) = Q;
    }
}

void deleteFirstCustomer(List_customer &L, adr_customer &P);
void deleteLastCustomer(List_customer &L, adr_customer &P);
void deleteAfterCustomer(List_customer &L, adr_customer Prec, adr_customer &P);

adr_customer alokasiCutomer(string nama, int usia, string noHP, string tanggalBooking, string totalHarga);
adr_customer findElm(List_customer L, string x);
void printInfo(List_customer L);
