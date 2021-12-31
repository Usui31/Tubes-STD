#include "parent.h"

void createList(List_customer &L){
    first(L) = NULL;
    last(L) = NULL;
}

void insertLast(List_customer &L, adr_customer P){
    if(first(L) == NULL && last(L) == NULL) {
        first(L) = P;
        last(L) = P;
    }else {
        next(last(L)) = P;
        next (P) = first(L);
        last(L) = P;
    }
}

void deleteFirstCustomer(List_customer &L, adr_customer &P){
    P = first(L);
    if (first(L) == NULL && last(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (first(L) == last(L)) {
        first(L) = NULL;
        last(L) = NULL;
    }else {
        first(L) = next(P);
        next(last(L)) = first(L);
        next(P) = NULL;
    }
}

void deleteLastCustomer(List_customer &L, adr_customer &P){
    P = last(L);
    if (first(L) == NULL && last(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (first(L) == last(L)) {
        first(L) = NULL;
        last(L) = NULL;
    }else {
        adr_customer Q = first(L);
        do {
            Q = next(Q);
        }while (next(Q) != P);
        next(Q) = first(L);
        last(L) = Q;
        next(P) = NULL;
    }
}

void deleteAfterCustomer(List_customer &L, adr_customer Prec, adr_customer &P){
    P = next(Prec);
    if ((first(L) == NULL && last(L) == NULL) || (next(Prec) == NULL)) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (next(Prec) == last(L)) {
        next(Prec) = first(L);
        last(L) = Prec;
        next(P) = NULL;
    }else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

adr_customer alokasiCutomer(string nama, string
                             usia, string noHp, string tanggalBooking, string totalHarga){
    adr_customer P;

    P = new elm_customer;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).noHp = noHp;
    info(P).tanggalBooking = tanggalBooking;
    info(P).totalHarga = totalHarga;
    next(P) = NULL;
    return P;
}

adr_customer findElm(List_customer L, string x){
    adr_customer P = first(L);
    do {
        if(info(P).nama == x){
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return NULL;
}

void printInfo(List_customer L){
    adr_customer P = first(L);
    cout<<"===================================================================="<<endl;
    if (first(L) == NULL) {
        cout<<"data tidak ada";
    }else {
        do {
            cout<<"Nama                : "<<info(P).nama<<endl;
            cout<<"Usia                : "<<info(P).usia<<endl;
            cout<<"no HP               : "<<info(P).noHp<<endl;
            cout<<"Tanggal Booking     : "<<info(P).tanggalBooking<<endl;
            cout<<"Total Harga         : "<<info(P).totalHarga<<endl;
            cout<<endl;
            P = next(P);
       }while (P != first(L));
    }
    cout<<"===================================================================="<<endl;
    cout<<endl;
}
