/* Nama : putri nabila
   Kelas : A
   NPM   : 140810180007
   tanggal : 15 APRIL 2019*/
   

#include<iostream>
#include<string.h>
using namespace std;
struct kontak{
	char nama[20];
	char nomor[12];
	kontak* nextkontak;
};
struct index{
	char info[5];
	kontak* FirstKontak;
	index* next;
};
typedef index* pointerIndex;
typedef kontak* pointerKontak;
typedef pointerIndex list;

void createList(list& First){
	First=NULL;
}
void createElmtIndex(pointerIndex& pBaru){
	pBaru = new index;
	cout<<"Masukan index :"; cin>>pBaru->info;
	pBaru->next=NULL;
	pBaru->FirstKontak=NULL;
	
}
void createElmtKontak(pointerKontak& pBaru){
	pBaru= new kontak;
	cout<<"Masukan Nama KONTAK:"; cin>>pBaru->nama;
	cout<<"Masukan Nomor KONTAK:"; cin>>pBaru->nomor;
	pBaru->nextkontak=NULL;
}
void insertFirstIndex(list& First,pointerIndex pBaru){
	if(First==NULL){
		First=pBaru;
	}
	else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversalIndex(list First){
	pointerIndex pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout<<"Index :"<<pBantu->info<<",";
		pBantu=pBantu->next;
	}
}
void linearSearch(list First,char key[5],int& status,pointerIndex& pCari){
	status=0;
	pCari=First;
	while(status==0 && pCari!=NULL){
		if(strcmp(pCari->info,key)==0){
			status=1;
		}
		else{
			pCari=pCari->next;
		}
	}
}
void insertFirstKontak(list& First,char key[5],pointerKontak pBaru){
	pointerIndex pIn;
	int ketemu;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
	if(ketemu){
		cout<<"Ditemukan Index :"<<pIn->info<<endl;
		if(pIn->FirstKontak==NULL){
			pIn->FirstKontak=pBaru;
		}
		else{
			pBaru->nextkontak=pIn->FirstKontak;
			pIn->FirstKontak=pBaru;
	}
	}
	else{
		cout<<"Index  tidak di temukan"<<endl;
	}
}
void deleteFirstKontak(list& First,char key[5],pointerKontak& pHapus ){
	int ketemu;
	pointerIndex pIn;
	cout<<"Masukan Index yang di cari: "; cin>>key;
	linearSearch(First,key,ketemu,pIn);
		if(ketemu){
		cout<<"Ditemukan INdex :"<<pIn->info;
		if(pIn->FirstKontak==NULL){
			cout<<"Tidak ada yang di hapus"<<endl;
		}
		else if(pIn->FirstKontak->nextkontak==NULL){
			pHapus=pIn->FirstKontak;
			pIn->FirstKontak=NULL;
		}
		else{
			pHapus=pIn->FirstKontak;
			pIn->FirstKontak=pIn->FirstKontak->nextkontak;
			pHapus->nextkontak=NULL;
			
		}
	}
	else{
		cout<<"Index tidak di temukan"<<endl;
	}
	
}
void traversalIndexKontak(list First){
	pointerIndex pBantuIndex;
	pointerKontak pBantuKontak;
	cout<<"Traversal Divisi"<<endl;
	pBantuIndex=First;
	while (pBantuIndex!=NULL){ 
	cout<<"Index ="<<pBantuIndex->info <<endl;
	pBantuKontak=pBantuIndex->FirstKontak;
	while (pBantuKontak!=NULL) { 
	cout<<pBantuKontak->nama<<" / "<<pBantuKontak->nomor<<endl;
	pBantuKontak=pBantuKontak->nextkontak;
	}
	pBantuIndex=pBantuIndex->next;
	}
}
void updateKontak(list First,char key[10],int& status,pointerIndex& pIndex){
	status=0;

	pointerKontak pK,pb;
	pIndex=First;
	pK=pIndex->FirstKontak;
	cout<<"Masukan Nama KONTAK :"; cin>>key;
	while(pIndex!=NULL){
		while(status== 0 && pK!=NULL){
			if(strcmp(pK->nama,key)==0){
				cout<<"Masukan Nama KONTAK :"; cin>>pK->nama;
				cout<<"Masukan Nomor KONTAK :"; cin>>pK->nomor;
			status=1;
			}
			else if(pK->nextkontak==NULL){
				status=1;
			}
			else {
				pK=pK->nextkontak;
			}
			
		}
			pIndex=pIndex->next;
		}
	}
	

main(){
	pointerIndex pI;
	pointerKontak pK,phk;
	list q;
	char key[5],nama[10];
	int ni,nk,ketemu;
	createList(q);
	cout<<"Masukan Banyak index :"; cin>>ni;
	for(int i=0;i<ni;i++){
		createElmtIndex(pI);
		insertFirstIndex(q,pI);
	}
	cout<<"Masukan banyak kontak :"; cin>>nk;
	for(int i=0;i<nk;i++){
		createElmtKontak(pK);
		insertFirstKontak(q,key,pK);
	}
		traversalIndexKontak(q);
	updateKontak(q,nama,ketemu,pI);
	traversalIndexKontak(q);
}

