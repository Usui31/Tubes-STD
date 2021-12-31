#include <iostream>
#include <windows.h>
using namespace std;
#include "child.h"
#include "parent.h"
#include "relasi.h"

int main()
{
    List_customer K;
    List_kamar L;
    List_relasi M;
    adr_kamar C;
    adr_customer P1 ;
    adr_relasi R;

    createList(K);
    createList(L);
    createList(M);
    cout<<"| | =====================================SELAMAT DATANG============================================ | |"<<endl;
    cout<<"| | ======================================DI HOTEL================================================= | |"<<endl;
    cout<<endl;
    menuUtama:
    string pilih;
    cout<<"| | ======================================MENU-MENU NYA============================================ | |"<<endl;
    cout<<"| | a. Penambahan data customer.                                                                   | |"<<endl;
    cout<<"| | b. Penambahan data kamar.                                                                        | |"<<endl;
    cout<<"| | c. Penentuan relasi antara customer dan kamar).                        | |"<<endl;
    cout<<"| | d. Menghapus data customer tertentu.                                                           | |"<<endl;
    cout<<"| | e. Manghapus data kamar tertentu.                                                                | |"<<endl;
    cout<<"| | f. Menampilkan data keseluruhan kamar dan customer.                                      | |"<<endl;
    cout<<"| | g. Menampilkan data kamar yang di miliki oleh customer tertentu.                                | |"<<endl;
    cout<<"| | h. Menampilkan data customer tertentu yang memiliki kamar tertentu.                             | |"<<endl;
    cout<<"| | i. Menampilkan data customer yang memiliki jumlah kamar paling banyak dan juga paling sedikit.  | |"<<endl;
    cout<<"| | j. Keluar                                                                                       | |"<<endl;
    cout<<"| | =============================================================================================== | |"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    cin.ignore();
    while(pilih!="a" && pilih!="b" && pilih!="c" && pilih!="d" && pilih!="e" && pilih!="f" && pilih!="g" && pilih!="h" && pilih!="i" && pilih!="j"){
        system ("CLS");
        cout<<"|| =======================Mohon Pilih Menu yang valid!!!======================= ||"<<endl;
        system ("pause");
        system ("CLS");
        cout<<"| | ======================================MENU-MENU NYA============================================ | |"<<endl;
        cout<<"| | a. Penambahan data customer.                                                                   | |"<<endl;
        cout<<"| | b. Penambahan data kamar.                                                                        | |"<<endl;
        cout<<"| | c. Penentuan relasi antara customer dan kamar ).                        | |"<<endl;
        cout<<"| | d. Menghapus data customer tertentu.                                                           | |"<<endl;
        cout<<"| | e. Manghapus data kamar tertentu.                                                                | |"<<endl;
        cout<<"| | f. Menampilkan data keseluruhan kamar beserta customer.                                      | |"<<endl;
        cout<<"| | g. Menampilkan data kamar yang di miliki oleh customer tertentu.                                | |"<<endl;
        cout<<"| | h. Menampilkan data customer tertentu yang memiliki kamar tertentu.                             | |"<<endl;
        cout<<"| | i. Menampilkan data customer yang memiliki jumlah kamar paling banyak dan juga paling sedikit.  | |"<<endl;
        cout<<"| | j. Keluar                                                                                       | |"<<endl;
        cout<<"| | =============================================================================================== | |"<<endl;
        cout<<"Pilih Menu : ";
        cin>>pilih;
        cin.ignore();
    }
    system("pause");
    system("CLS");
    if(pilih=="a"){
        /** insert parent */
        string nama, usia, noHp, tanggalBooking, totalHarga;
        cout<<"Nama : ";
        getline(cin, nama);
        cout<<"Usia : ";
        getline(cin, usia);
        cout<<"no HP : ";
        getline(cin, noHp);
        cout<<"Tanggal Booking: ";
        getline(cin, tanggalBooking);
        cout<<"Total Harga : ";
        getline(cin, totalHarga);
        P1 = alokasiCutomer(nama, usia, noHp, tanggalBooking, totalHarga);
        insertLast(K, P1);
        cout<<"List Parent"<<endl;
        cout<<endl;
        printInfo(K);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if (pilih=="b") {
        string noKamar, jenisKamar, harga, status;
        cout<<"No kamar : ";
        getline(cin, noKamar);
        cout<<"Jenis Kamar : ";
        getline(cin, jenisKamar);
        cout<<"Harga : ";
        getline(cin, harga);
        cout<<"Status: ";
        getline(cin, status);
        C = alokasiKamar(noKamar, jenisKamar, harga, status);
        insertFirst(L, C);
        cout<<"List Child"<<endl;
        cout<<endl;
        printInfo(L);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if (pilih=="c") {
        menu:
        string x, y;
        cout<<"nama customer yang dicari : ";
        getline(cin, x);
        cout<<"nama kamar yang dicari : ";
        getline(cin, y);
        P1 = findElm(K, x);
        C = findElm(L, y);
        while ((P1 == NULL) || (C == NULL)) {
            cout<<"ada data yang tidak ada"<<endl;
            cout<<endl;
            goto menu;
        }
        R = alokasi(P1,C);
        insertLast(M,R);
        cout<<endl;
        printAllInfo(M);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if (pilih=="d") {
        string x1,y1;
        cout<<"Nama customer yang akan dihapus: "<<endl;
        cout<<"Nama : "<<endl;
        getline(cin, x1);
        //deleteParent(K, M, L, x1);
        printAllInfo(M);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if (pilih=="e") {
        string anak2;
        cout<<"Nama kamar yang akan dihapus: "<<endl;
        getline(cin, anak2);
        //deleteAnak(K, M, L, anak2);
        printAllInfo(M);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if (pilih=="f") {
        printAllInfo(M);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if(pilih=="g") {
        string customer;
        cout<<"Nama customer yang Dicari "<<endl;
        cout<<"Nama :";
        getline(cin, customer);
        printInfoChild(M, customer);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if(pilih=="h") {
        string anak;
        cout<<"Nama kamar yang Dicari : "<<endl;
        getline(cin, anak);
        printInfoParent(M, anak);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if(pilih=="i") {
        //printIndukMax(M);
        //printIndukMin(M);
        system("pause");
        system("CLS");
        goto menuUtama;
    }else if(pilih=="j") {
        cout<<"| | =======================================TERIMA KASIH=============================================== | | "<<endl;
        cout<<"| | =====================================TELAH MENGGUNAKAN============================================ | | "<<endl;
        cout<<"| | =======================================LAYANAN KAMI=============================================== | | "<<endl;
    }


    return 0;

}
