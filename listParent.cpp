#include "listParent.h"

void createListParent(listParent &L){
    firstParent(L) = NULL;
}

addressParent allocateParent(infoParent x){
    addressParent P = NULL;
  
    P = new elmlistParent;
    info(P).idPenyewa = x.idPenyewa;
    info(P).alamatPenyewa = x.alamatPenyewa;
    info(P).namaPenyewa = x.namaPenyewa;
    info(P).umurPenyewa = x.umurPenyewa;
    next(P) = NULL;

    return P;
}

void insertFirstParent(listParent &L, addressParent P){
    if(firstParent(L)!=NULL){
        next(P)=firstParent(L);
    }
    firstParent(L)=P;
}

void insertAfterParent(listParent &L, addressParent prec, addressParent P){
    if (next(prec)!=NULL){
        next(P)=next(prec);
    }
    next(prec)=P;
}

void insertLastParent(listParent &L, addressParent P){
   addressParent prec;

    prec=first(L);
    if (first(L)== NULL){
        insertFirstParent(L,P);
    }else {
        while (next(prec) != NULL){
            prec=next(prec);
        }
        insertAfterParent(L,prec,P);
    }
}

void deleteFirstParent(listParent &L, addressParent &P){
    P=firstParent(L);
    if (next(P) != NULL){
        firstParent(L)=next(P);
    } else {
        firstParent(L)=NULL;
    }
}

void deleteAfterParent(listParent &L, addressParent prec, addressParent &P){
    P=next(prec);
    if (next(P)!=NULL){
        next(prec)=next(P);
    } else{
        next(prec)=NULL;
    }
}

void deleteLastParent(listParent &L, addressParent &P){
    addressParent prec;

    prec=firstParent(L);
    if (next(prec)== NULL){
        firstParent(L) = NULL;
    } else {
        while (next(next(prec)) != NULL){
               prec=next(prec);
        }
        P = next(prec);
        next(prec) = NULL;
    }
}

void printinfoParent(listParent L){
    addressParent P;

    P = firstParent(L);
    while(P != NULL){
        cout<< P <<", ";
        P = next(P);
    }
    cout<<endl;
}

addressParent searchElmParent(listParent &L, string ID){
    infoParent x;
    addressParent P;
    
    P=firstParent(L);
    while(P!=NULL && info(P)!=ID){
        P=next(P);
    }
    
    return P;
}