#include "relasi.h"

void createList(List_relasi &L){
    first(L) = NULL;
}

void insertLast(List_relasi &L, adr_relasi P){
    if (first(L) == NULL) {
        first(L) = P;
    }else {
        adr_relasi Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void deleteFirstRelasi(List_relasi &L, adr_relasi &P){
    P = first(L);
    if (first(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (next(first(L)) == NULL) {
        first(L) = NULL;
    }else {
        first(L) = next(P);
        next(P) = NULL;
    }
}
void deleteLastRelasi(List_relasi &L, adr_relasi &P){
    adr_relasi Q;
    if (first(L) == NULL) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (next(first(L)) == NULL) {
        first(L) = NULL;
    }else {
        P = first(L);
        while (next(P) != NULL) {
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}
void deleteAfterRelasi(List_relasi &L, adr_relasi Prec, adr_relasi &P){
    P = next(Prec);
    if ((first(L) == NULL) || (Prec == NULL) || (next(Prec) == NULL)) {
        cout<<"tidak ada data yang bisa dihapus"<<endl;
    }else if (next(next(Prec)) == NULL) {
        next(Prec) = NULL;
    }else {
        next(Prec) = next(P);
        next(P) = NULL;
    }
}

adr_relasi alokasi(adr_customer P, adr_kamar C){
    adr_relasi Q = new elmlist_relasi;
    kamar(Q) = C;
    customer(Q) = P;
    next(Q) = NULL;
    return Q;
}

void printAllInfo(List_relasi &L){
    cout<<"===================================================================="<<endl;
    adr_relasi P;
    if (first(L) == NULL) {
        cout<<"data tidak ada"<<endl;
        cout<<"===================================================================="<<endl;
    }else {
        adr_relasi Z = first(L);
        cout<<"Nama                : "<<info(customer(Z)).nama<<endl;
        cout<<"Usia                : "<<info(customer(Z)).usia<<endl;
        cout<<"no HP               : "<<info(customer(Z)).noHp<<endl;
        cout<<"Tanggal Booking     : "<<info(customer(Z)).tanggalBooking<<endl;
        cout<<"Total Harga         : "<<info(customer(Z)).totalHarga<<endl;
        cout<<endl;
        cout<<"No Kamar            : "<<info(kamar(Z)).noKamar<<endl;
        cout<<"Jenis Kamar         : "<<info(kamar(Z)).jenisKamar<<endl;
        cout<<"Harga               : "<<info(kamar(Z)).harga<<endl;
        cout<<"Status              : "<<info(kamar(Z)).status<<endl;
        cout<<endl;
        while (next(Z) != NULL) {
            P = Z;
            Z = next(Z);
            if ((info(customer(P)).nama == info(customer(Z)).nama)) {
                    cout<<"No Kamar            : "<<info(kamar(Z)).noKamar<<endl;
                    cout<<"Jenis Kamar         : "<<info(kamar(Z)).jenisKamar<<endl;
                    cout<<"Harga               : "<<info(kamar(Z)).harga<<endl;
                    cout<<"Status              : "<<info(kamar(Z)).status<<endl;
                    cout<<endl;
            }else {
                cout<<"===================================================================="<<endl;
                cout<<"Nama                : "<<info(customer(Z)).nama<<endl;
                cout<<"Usia                : "<<info(customer(Z)).usia<<endl;
                cout<<"no HP               : "<<info(customer(Z)).noHp<<endl;
                cout<<"Tanggal Booking     : "<<info(customer(Z)).tanggalBooking<<endl;
                cout<<"Total Harga         : "<<info(customer(Z)).totalHarga<<endl;
                cout<<endl;
                cout<<"No Kamar            : "<<info(kamar(Z)).noKamar<<endl;
                cout<<"Jenis Kamar         : "<<info(kamar(Z)).jenisKamar<<endl;
                cout<<"Harga               : "<<info(kamar(Z)).harga<<endl;
                cout<<"Status              : "<<info(kamar(Z)).status<<endl;
                cout<<endl;
            }
        }

    }
    cout<<endl;
}

void printInfoChild(List_relasi L, string customer){
    adr_relasi P = first(L);
    cout<<"===================================================================="<<endl;
    while (P != NULL) {
        if ((info(customer(P)).nama == customer)) {
            cout<<"No Kamar            : "<<info(kamar(P)).noKamar<<endl;
            cout<<"Jenis Kamar         : "<<info(kamar(P)).jenisKamar<<endl;
            cout<<"Harga               : "<<info(kamar(P)).harga<<endl;
            cout<<"Status              : "<<info(kamar(P)).status<<endl;
            cout<<endl;
        }
        P = next(P);
    }
    cout<<"===================================================================="<<endl;
}

void printInfoParent(List_relasi L, string x){
    adr_relasi P = first(L);
    cout<<"===================================================================="<<endl;
    while (info(kamar(P)).noKamar != x) {
        P = next(P);
    }
    if (info(kamar(P)).noKamar == x) {
        cout<<"customer yang menempati kamar "<<x<<" adalah : "<<endl;
        cout<<endl;
        cout<<"Nama                : "<<info(customer(P)).nama<<endl;
        cout<<"Usia                : "<<info(customer(P)).usia<<endl;
        cout<<"no HP               : "<<info(customer(P)).noHp<<endl;
        cout<<"Tanggal Booking     : "<<info(customer(P)).tanggalBooking<<endl;
        cout<<"Total Harga         : "<<info(customer(P)).totalHarga<<endl;
        cout<<endl;
    }else {
        cout<<"Tidak ada customer yang memesan kamar tersebut"<<endl;
    }
    cout<<"===================================================================="<<endl;
}
void printIndukMax(List_relasi &L){

}

void printIndukMin(List_relasi &L);
void deleteAnak(List_customer &K, List_relasi &L, List_kamar &M, string anak);
void deleteParent(List_customer &K, List_relasi &L, List_kamar &M, string customer);
