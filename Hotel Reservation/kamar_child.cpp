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

void deleteFirstKamar(List_kamar &L, adr_kamar &P){
    P = first(L);
    if (first(L) == NULL && last(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (first(L) == last(L)) {
        first(L) = NULL;
        last(L) = NULL;
    }else {
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
}

void deleteLastKamar(List_kamar &L, adr_kamar &P){
    P = last(L);
    if (first(L) == NULL && last(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (first(L) == last(L)) {
        first(L) = NULL;
        last(L) = NULL;
    }else {
        last(L) = prev(P);
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
}

void deleteAfterKamar(List_kamar &L, adr_kamar Prec, adr_kamar &P){
    P = next(Prec);
    if ((first(L) == NULL && last(L) == NULL) || (next(Prec) == NULL)) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (next(Prec) == last(L)) {
        last(L) = Prec;
        next(last(L)) = NULL;
        prev(P) = NULL;
    }else {
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        prev(P) = NULL;
        next(P) = NULL;
    }
}

adr_kamar alokasiKamar(string noKamar, string jenisKamar, string harga, string status){
    adr_kamar P = new elm_kamar;
    info(P).noKamar = noKamar;
    info(P).jenisKamar = jenisKamar;
    info(P).harga = harga;
    info(P).status = status;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

adr_kamar findElm(List_kamar L, string anak){
    adr_kamar P = first(L);
    while(P != NULL) {
        if(info(P).noKamar == anak) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void printInfo(List_kamar L){
    cout<<"===================================================================="<<endl;
    if (first(L) == NULL) {
        cout<<"data tidak ada";
    }else {
        adr_kamar P = first(L);
        while (P != NULL) {
            cout<<"No Kamar            : "<<info(P).noKamar<<endl;
            cout<<"Jenis Kamar         : "<<info(P).jenisKamar<<endl;
            cout<<"Harga               : "<<info(P).harga<<endl;
            cout<<"Status              : "<<info(P).status<<endl;
            cout<<endl;
            P = next(P);
       }
    }
    cout<<"===================================================================="<<endl;
    cout<<endl;
}
