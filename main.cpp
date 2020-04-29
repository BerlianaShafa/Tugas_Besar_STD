#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "listParent.h"
#include "listChild.h"
#include "listRelasi.h"

using namespace std;

int main()
{
    int choose;
    listParent L1;
    createListParent(L1);
    listChild L2;
    createListChild(L2);
    listRelasi L3;
    createListRelasi(L3);
    while ( choose != 0 )
    {
        cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=| MENU |=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl
            <<"| 0. exit                                                      |"<<endl
            <<"| 1. Memasukkan Data Penyewa                                   |"<<endl
            <<"| 2. Memasukkan Data Busana                                    |"<<endl
            <<"| 3. Menampilkan Daftar Penyewa                                |"<<endl
            <<"| 4. Menampilkan Daftar Busana                                 |"<<endl
            <<"| 5. Mencari data peminjam dengan ID penyewa atau kode busana  |"<<endl
            <<"| 6. Menampilkan Semua Data Peminjaman                         |"<<endl
            <<"| 7. Penyewaan Busana                                          |"<<endl
            <<"| 8. Pengembalian Busana                                       |"<<endl
            <<"| 9. Hapus Data Penyewa                                        |"<<endl
            <<"| 10.Hapus Data Busana                                         |"<<endl
            <<"| 11.Menampilkan Total Peminjam Busana                         |"<<endl
            <<"| 12.Menampilkan Total Busana yang dipinjam                    |"<<endl
            <<"| 13.Menampilkan Rata-rata Peminjaman Busana                   |"<<endl
            <<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
        cout<<"Choose The Menu : ";
        cin>>choose;
        cout<<endl<<endl;
        switch(choose)
        {
        case 1 :
        {
            string nama, alamat;
            int age, id;
            cout<<"|=|=|=|=|=|=|=|=|=|=|= INPUT DATA PENYEWA =|=|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"| ID Penyewa : ";
            cin>>id;
            cout<<"                                                               |"<<endl;
            addressParent Q = searchElmParent(L1, id);
            if ( Q != NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=|=| Anda Telah Terdaftar |=|=|=|=|=|=|=|=|=|=|"<<endl;
                cout<<endl<<endl;
            }
            else
            {
                cout<<"| Nama Penyewa : ";
                cin>>nama;
                cout<<"                                                               |"<<endl;
                cout<<"| Umur Penyewa : ";
                cin>>age;
                cout<<"                                                               |"<<endl;
                cout<<"| Alamat Penyewa : ";
                cin>>alamat;
                cout<<"                                                               |"<<endl;
                addressParent R = allocateParent(id, alamat, nama, age);
                insertSortParent(L1,R);
                cout<<"|=|=|=|=|=|=|=|=|=|=|= INPUT DATA SELESAI =|=|=|=|=|=|=|=|=|=|=|"<<endl;
                cout<<endl<<endl;
            }
            break;
        }
        case 2 :
        {
            int kodeB,jum;
            string Size,jenis;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=| INPUT DATA BUSANA|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"| ID/Kode Busana : ";
            cin>>kodeB;
            cout<<"                                                               |"<<endl;
            addressChild Q = searchElmChild(L2, kodeB);
            if ( Q != NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=|=|Busana Telah Terdaftar|=|=|=|=|=|=|=|=|=|=|"<<endl;
            }
            else
            {
                cout<<"| Jenis Busana : ";
                cin>>jenis;
                cout<<"                                                               |"<<endl;
                cout<<"| Ukuran Busana(S/M/L/XL/XXL): ";
                cin>>Size;
                cout<<"                                                               |"<<endl;
                cout<<"| Jumlah Busana : ";
                cin>>jum;
                cout<<"                                                               |"<<endl;
                addressChild R = allocateChild(kodeB,jenis,Size,jum);
                insertSortChild(L2,R);
                cout<<"|=|=|=|=|=|=|=|=|=|=|= INPUT DATA SELESAI =|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
            }
            break;
        }
        case 3:
        {
            printinfoParent(L1);
            break;
        }
        /*case 4:
        {
            printinfoChild(L2);
            break;
        }
        case 5:
        {
            searchElmRelasi(L3);
            break;
        }*/
        case 6:
        {
            printinfoRelasi(L3);
            break;
        }
        case 7:
        {
            int ID, kodeBusana;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|= PENYEWAAN BUSANA =|=|=|=|=|=|=|=|=|=|=|"<<endl;
            if (firstParent(L1)==NULL && firstChild(L2)==NULL)
            {
                cout<<"|                                                              |"<<endl;
                cout<<"|                                                              |"<<endl;
                cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|= LIST  KOSONG =|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            }
            else
            {
                cout<<"| Masukkan ID : ";
                cin>>ID;
                cout<<"                                                               |"<<endl;
                addressParent P = searchElmParent(L1,ID);
                while (P == NULL)
                {
                    cout<<"|=|=|=|=|=|=|=|=|=|= MAAF ID  TIDAK DITEMUKAN =|=|=|=|=|=|=|=|=|"<<endl;
                    cout<<"                                                               |"<<endl;
                    cout<<"| Silahkan Masukkan kembali ID Anda : ";
                    cin>>ID;
                    cout<<"                                                               |"<<endl;
                    P = searchElmParent(L1,ID);
                }
                cout<<" Masukkan Kode Busana : ";
                cin>>kodeBusana;
                cout<<"                                                               |"<<endl;
                addressChild Q = searchElmChild(L2,kodeBusana);
                while (Q == NULL)
                {
                    cout<<"|=|=|=|=|=|=|=|=|=| MAAF KODE  TIDAK DITEMUKAN |=|=|=|=|=|=|=|=|"<<endl;
                    cout<<"                                                               |"<<endl;
                    cout<<"| Silahkan Masukkan kembali kode busana : ";
                    cin>>kodeBusana;
                    cout<<"                                                               |"<<endl;
                    Q = searchElmChild(L2,kodeBusana);
                }
                addressRelasi R = searchElmRelasi(L3, ID, kodeBusana);
                if (R == NULL)
                {
                    insertRelasi(L3,R);
                }
                else
                {
                    cout<<"|=|=|=|=|=|=|=|=|=| ANDA TELAH  MENYEWA BUSANA |=|=|=|=|=|=|=|=|"<<endl;
                }
            }
            break;
        }
        case 8:
        {
            int ID, kodeBusana;
            cout<<"|=|=|=|=|=|=|=|=|=|=|= PENGEMBALIAN  BUSANA =|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"| Masukkan ID : ";
            cin>>ID;
            cout<<"                                                               |"<<endl;
            addressParent P = searchElmParent(L1,ID);
            while (P == NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=|= MAAF ID  TIDAK DITEMUKAN =|=|=|=|=|=|=|=|=|"<<endl;
                cout<<"                                                               |"<<endl;
                cout<<"| Silahkan Masukkan kembali ID Anda : ";
                cin>>ID;
                cout<<"                                                               |"<<endl;
                P = searchElmParent(L1,ID);
            }
            cout<<" Masukkan Kode Busana : ";
            cin>>kodeBusana;
            cout<<"                                                               |"<<endl;
            addressChild Q = searchElmChild(L2,kodeBusana);
            while (Q == NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=| MAAF KODE  TIDAK DITEMUKAN |=|=|=|=|=|=|=|=|"<<endl;
                cout<<"                                                               |"<<endl;
                cout<<"| Silahkan Masukkan kembali kode busana : ";
                cin>>kodeBusana;
                cout<<"                                                               |"<<endl;
                Q = searchElmChild(L2,kodeBusana);
            }
            addressRelasi R = searchElmRelasi(L3, ID, kodeBusana);
            if (R == NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|= TIDAK ADA  RIWAYAT PENYEWAAN =|=|=|=|=|=|=|=|"<<endl;
            }
            else
            {
                if (firstRelasi(L3) == R)
                {
                    deleteFirstRelasi(L3,R);
                }
                else if (nextRelasi(R) == NULL)
                {
                    deleteLastRelasi(L3,R);
                }
                else
                {
                    addressRelasi S = firstRelasi(L3);
                    while (nextRelasi(nextRelasi(S)) != R)
                    {
                        S = nextRelasi(S);
                    }
                    S = nextRelasi(S);
                    deleteAfterRelasi(L3, S, R);
                }
                cout<<"|=|=|=|=|=|=|=|= ANDA TELAH MENGEMBALIKAN  BUSANA =|=|=|=|=|=|=|"<<endl;
            }
            break;
        }
        case 9:
        {
            int ID;
            cout<<"|=|=|=|=|=|=|=|=|=|=| PENGHAPUSAN  DATA DIRI |=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"| Masukkan ID : ";
            cin>>ID;
            cout<<"                                                               |"<<endl;
            addressParent P = searchElmParent(L1,ID);
            while (P == NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=|= MAAF ID  TIDAK DITEMUKAN =|=|=|=|=|=|=|=|=|"<<endl;
                cout<<"                                                               |"<<endl;
                cout<<"| Silahkan Masukkan kembali ID Anda : ";
                cin>>ID;
                cout<<"                                                               |"<<endl;
                P = searchElmParent(L1,ID);
            }
            if (firstParent(L1) == P)
            {
                deleteFirstParent(L1,P);
            }
            else if (nextParent(P) == NULL)
            {
                deleteLastParent(L1,P);
            }
            else
            {
                addressParent Q = firstParent(L1);
                while (nextParent(nextParent(Q)) != P)
                {
                    Q = nextParent(Q);
                }
                Q = nextParent(Q);
                deleteAfterParent(L1, Q, P);
            }
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|= BERHASIL =|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl<<endl;
            break;
        }
        case 10:
        {
            cout<<"|=|=|=|=|=|=|=|=|=|= PENGHAPUSAN  DATA BUSANA =|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"|                                                              |"<<endl;
            int kodeBusana;
            cout<<" Masukkan Kode Busana : ";
            cin>>kodeBusana;
            cout<<"                                                               |"<<endl;
            cout<<"|                                                              |"<<endl;
            addressChild Q = searchElmChild(L2,kodeBusana);
            while (Q == NULL)
            {
                cout<<"|=|=|=|=|=|=|=|=|=| MAAF KODE  TIDAK DITEMUKAN |=|=|=|=|=|=|=|=|"<<endl;
                cout<<"|                                                              |"<<endl;
                cout<<"| Silahkan Masukkan kembali kode busana : ";
                cin>>kodeBusana;
                cout<<"                                                               |"<<endl;
                cout<<"|                                                              |"<<endl;
                Q = searchElmChild(L2,kodeBusana);
            }
            if (firstChild(L2) == Q)
            {
                deleteFirstChild(L2,Q);
            }
            else if (nextChild(Q) == firstChild(L2))
            {
                deleteLastChild(L2,Q);
            }
            else
            {
                addressChild T = firstChild(L2);
                while (nextChild(nextChild(T)) != Q)
                {
                    T = nextChild(T);
                }
                T = nextChild(T);
                deleteAfterChild(L2, T, Q);
            }
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|= BERHASIL =|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            break;
        }
        case 11:
        {
            cout<<"|=|=|=|=|=|=|=|=|=|= TOTAL PEMINJAM  BUSANA =|=|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"| Saat ini terdapat "<<totalPeminjaman(L3)<<" |"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            break;
        }
        case 12:
        {
            cout<<"|=|=|=|=|=|=|=|=|= TOTAL BUSANA Yang DIPINJAM =|=|=|=|=|=|=|=|=|"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"| Saat ini busana yang sedang dipinjam berjumlah "<<totalPinjamBusana(L3)<<" |"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            break;
        }
        case 13:
        {
            cout<<"|=|=|=|=|=|=|=|=| RATA RATA PEMINJAMAN  BUSANA |=|=|=|=|=|=|=|=|"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"| Rata- rata peminjaman saat ini adalah "<<ratarataPinjaman(L3)<<" |"<<endl;
            cout<<"|                                                              |"<<endl;
            cout<<"|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|=||=|=|=|=|=|=|=|=|=|=|=|=|=|=|=|"<<endl;
            break;
        }
    }
}
        cout<<endl;
        system("PAUSE");
        system("CLS");
    return 0;

}
