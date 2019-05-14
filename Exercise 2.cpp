/*
Nama		: Sheila Azhar Almufarida
NPM			: 140810180001
Kelas		: A
Tanggal		: 14 Mei 2019
Nama Program: Membalikkan huruf menggunakan Queue (Linked List)
*/

#include<iostream>

using namespace std;

struct ElemenQueue {
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};

void createList(Queue& Q){
	Q.Head = NULL;
    Q.Tail = NULL;
}

void createElemt(pointer& pBaru){
	pBaru=new ElemenQueue;
	cout<<"Masukkan satu huruf : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void cetak(Queue Q){
    pointer pBantu=Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL){
        cout << "\n\t***Data masih kosong***" << endl;
    }else{
        while(pBantu != NULL){
            cout << pBantu->info << " ";
            pBantu=pBantu->next;
        }
    }
}

void traversal(List First){
	pointer pBantu;
	if(First==NULL){
		cout << "List kosong"<<endl;
	}
	else{
		pBantu=First;
		do{
			cout << pBantu->info;
			pBantu= pBantu->next;
		}while(pBantu!=NULL);
	}
}

void insertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { 
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else { 
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus){
    if (Q.Head==NULL && Q.Tail==NULL) { 
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { 
        pHapus=Q.Head;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { 
        pHapus=Q.Head;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}

int main(){
    Queue Q;
    pointer p;
    List l;
    int n;

    createList(Q);
    cout<<"Masukkan Banyak elemen : ";cin>>n;
    for(int i = 0; i < n; i++)
    {
        createElemt(p);
        insertQueue(Q,p);
    }
    cout<<"Queue : ";cetak(Q);cout<<endl;

    deleteQueue(Q,p);
    cout<<"Dequeue : ";cetak(Q);cout<<endl;
}
