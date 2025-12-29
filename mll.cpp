#include "mll.h"
// procedure tampilan
void welcomePage(){
    cout << endl<< "===================================================" << endl;
    cout << "      SELAMAT DATANG DI ALBUM TRACK      " << endl;
    cout << "                MANAGER                  " << endl;
    cout << "===================================================" << endl;
};

void fiturPage(){
    cout << "              MENU FITUR                " << endl;
    cout << "===================================================" << endl;
    cout << "1. Masukkan Data Album(W)" << endl;
    cout << "2. Masukkan Data Lagu(W)" << endl;
    cout << "3. Lihat List Album(W)" << endl;
    cout << "4. Lihat List lagu(W)" << endl;
    cout << "5. Hapus Data Album(W)" << endl;
    cout << "6. Hapus Data Lagu(W)" << endl;
    cout << "7. Update Data Album(W)" << endl;
    cout << "8. Update Data lagu(W)" << endl;
    cout << "9. Cari Album(W)" << endl;
    cout << "10. Cari Lagu(W)" << endl;
    cout << "11. Urutkan Album(O)" << endl;
    cout << "12. Urutkan Lagu per Album(O)" << endl;
    cout << "13. Total Album(W) " << endl;
    cout << "14. Total Lagu(W)" << endl;
    cout << "15. Statistik ALbum(W) " << endl;
    cout << "16. Export data ke file(O) " << endl;
    cout << "0. Keluar" << endl;
    cout << "===================================================" << endl;
};

void goodBy(){
    cout << endl<< "===================================================" << endl;
    cout << "      TERIMAKASIH SUDAH MEMBUKA ALBUM TRACK      " << endl;
    cout << "                MANAGER                  " << endl;
    cout << "===================================================" << endl<<endl;

};

void displayListAlbum(listAlbum L){
    adrAlbum p =L.first;
    cout << endl;
    cout << "===================[LIST ALBUM]===================="<<endl;
    while(p!= nullptr){
        cout << "Judul Album            : ";
        cout << p->infoAlbum.judulAlbum << endl;
        cout << "Artis                  : ";
        cout << p->infoAlbum.artis << endl;
        cout << "Genre                  : ";
        cout << p->infoAlbum.genre << endl;
        cout << "Tahun Rilis            : ";
        cout << p->infoAlbum.tahunRilis << endl;
        p= p->nextAlbum;
        cout << endl;
    }
};

void displayListLagu(listAlbum L) {
    cout << "===================[LIST SEMUA LAGU]====================" << endl;
    
    if (isEmptyAlbum(L)) {
        cout << "Tidak ada Album" << endl;
        return;
    }
    
    adrAlbum album = L.first;
    bool adaLagu = false;
    
    while (album != nullptr) {
        adrLagu lagu = album->firstLagu;
        
        if (lagu != nullptr) {
            adaLagu = true;
            
            cout << "\n--------------------------------------------------------\n";
            cout << "Album : " << album->infoAlbum.judulAlbum 
                 << " | Artis : " << album->infoAlbum.artis << endl;
            cout << "--------------------------------------------------------\n";
            cout << "No | Judul Lagu                         | Durasi  | Pendengar" << endl;
            cout << "---------------------------------------------------------------" << endl;
            int counter = 1; 
            while (lagu != nullptr) {
                cout << setw(2) << right << counter << " | "
                     << setw(34) << left << lagu->infoLagu.judulLagu << " | "
                     << fixed << setprecision(2) << setw(6) << lagu->infoLagu.durasi << " | "
                     << setw(9) << lagu->infoLagu.pendengar << endl;
                lagu = lagu->nextLagu;
                counter++;
            }
        }
        album = album->nextAlbum;
    }
    if (!adaLagu) {
        cout << "Tidak ada lagu" << endl;
    }
}
// end procedure tampilan

// utils
void executeOpsi(listAlbum &L,adrAlbum album,adrLagu lagu,int opsi){
    infotypeAlbum inputAlbum;
    infotypeLagu inputLagu;
    bool isExists;
    adrAlbum newAlbm;
    adrLagu newLagu;
    adrAlbum found;
    string pilihan;
    adrAlbum foundAlbm;
    adrLagu foundLagu;
    adrLagu p;
    int pendengar;
    float durasi;
    int tahun;
    int count;
    switch (opsi) {
        case 1 :
            count = 1;
            cout << endl;
            cout << "================[INSERT DATA ALBUM]================"<< endl;
            cout << "Judul Album            : ";
            cin >> inputAlbum.judulAlbum;
            isExists = isAlbumExists(L,inputAlbum.judulAlbum);
            count =1;
            while(isExists && count < 3){
                cout << "ERROR!! album dengan judul "<< inputAlbum.judulAlbum << " sudah ada, masukan judul yang lain"<< endl;
                cout << "Judul Album            : ";
                cin >> inputAlbum.judulAlbum;
                isExists = isAlbumExists(L,inputAlbum.judulAlbum);
                count++;
            }if(count < 3){
                cout << "Artis                  : ";
                cin >> inputAlbum.artis;
                cout << "Tahun Rilis(1901-2025) : ";
                cin >> inputAlbum.tahunRilis;
                while((inputAlbum.tahunRilis < 1091 || inputAlbum.tahunRilis > 2025) && count < 3){
                    cout << "Tahun Rilis Tidak valid\n";
                    cout << "Tahun Rilis(1901-2025) : ";
                    cin >> inputAlbum.tahunRilis;
                    count++;
                }
                if(count < 3){
                    cout << "Genre                  : ";
                    cin >> inputAlbum.genre;
                    newAlbm = createElementAlbum(inputAlbum.judulAlbum,inputAlbum.artis,inputAlbum.tahunRilis,inputAlbum.genre);
                    insertDataAlbum(L,newAlbm);
                    cout << "SUKESS!! Album berhasil di tambahkan";
                }else{
                    cout << "percobaan habis coba lagi\n";
                }
            }else{
                cout << "percobaan habis coba lagi\n";
            }
            break;
        case 2 :
            count = 1;
            cout << endl;
            cout << "================[INSERT DATA LAGU]================"<< endl;
            cout << "Judul Lagu             : ";
            cin >> inputLagu.judulLagu;
            cout << "Durasi(min 0.10)       : ";
            cin >> inputLagu.durasi;
            while(inputLagu.durasi <= 0.10 && count <3){
                cout << "Minimal Durasi tidak terpenuhi\n";
                cout << "Durasi(min 0.10)   : ";
                cin >> inputLagu.durasi;
                count++;
            }
            if(count < 3){
                cout << "Pendengar              : ";
                cin >> inputLagu.pendengar;
                cout << "Masukkan ke Album      : ";
                cin >> inputAlbum.judulAlbum;
                found = searchAlbum(L,inputAlbum.judulAlbum);
                while(found == nullptr){
                    cout << "album " << inputAlbum.judulAlbum << " tidak ada"<<endl;
                    cout << "ingin masukan ke album lain? y/n  : ";
                    cin >> pilihan;
                    if(pilihan == "y" || pilihan == "Y"){
                        cout << "Masukkan ke Album      : ";
                        cin >> inputAlbum.judulAlbum;
                        found = searchAlbum(L,inputAlbum.judulAlbum);
                    }else{
                        cout << "Penambahan data lagu baru dibatalkan";
                        break;
                    }
                }
                if(found!= nullptr){
                    newLagu = createElementLagu(inputLagu.judulLagu,inputLagu.durasi,inputLagu.pendengar);
                    insertDatalagu(found,newLagu);
                }
            }else{
                cout << "percobaan habis coba lagi\n";
            }
            break;
        case 3 :
            displayListAlbum(L);
            break;
        case 4 :
            displayListLagu(L);
            break;
        case 5 : 
            cout << "DELETE DATA ALBUM BERDASARKAN" << endl;
            cout << "1.Judul" << endl;
            cout << "2.First" << endl;
            cout << "3.Last" << endl;
            cout << "Input: ";
            count =1;
            cin >> opsi;
            if(opsi == 1){
                cout << "Masukkan judul album yang akan di hapus: ";
                cin >> inputAlbum.judulAlbum;
                adrAlbum albmFound=searchAlbum(L,inputAlbum.judulAlbum);
                while(albmFound == nullptr && count < 3){
                    cout << "Album tidka ditemukan\n";
                    cout << "Masukkan judul album yang akan di hapus: ";
                    cin >> inputAlbum.judulAlbum;
                    albmFound = searchAlbum(L,inputAlbum.judulAlbum);
                    count++;
                }
                if(count < 3){
                    deleteDataAlbumByJudul(L,inputAlbum.judulAlbum);
                }else{
                    cout <<"percobaan anda habis coba lagi\n";
                }
            }else if(opsi == 2){
                foundAlbm = L.first;
                deleteFirstDataAlbum(L,foundAlbm);
            }else if(opsi == 3){
                foundAlbm = L.last;
                deleteLastDataAlbum(L,foundAlbm);
            }else{
                cout << "Input tidak valid"<< endl;
            }
            break;
        case 6 : 
            cout << "DELETE DATA LAGU BERDASARKAN" << endl;
            cout << "1.Judul" << endl;
            cout << "2.First" << endl;
            cout << "3.Last" << endl;
            cout << "Input: ";
            cin >> opsi;
            count = 1;
            if(opsi == 1){
                cout << "Masukkan album lagu tersebut   : ";
                cin >> inputAlbum.judulAlbum;
                adrAlbum foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
                while(foundAlbm == nullptr && count <3){
                    cout << "Album tidak ditemukan\n";
                    cout << "Masukkan album lagu tersebut   : ";
                    cin >> inputAlbum.judulAlbum;
                    foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
                    count++;
                }
                if(count < 3){
                    cout << "Masukkan judul Lagu            : ";
                    cin >> inputLagu.judulLagu;
                    adrLagu foundLagu = searchLagu(foundAlbm,inputLagu.judulLagu);
                    while(foundLagu == nullptr && count < 3){
                        cout << "lagu tidak ditemukan\n";
                        cout << "Masukkan judul Lagu            : ";
                        cin >> inputLagu.judulLagu;
                        foundLagu = searchLagu(foundAlbm, inputLagu.judulLagu);
                        count++;
                    }
                    if(count < 3){
                        deleteDataLaguByJudul(L,foundLagu,foundAlbm);               
                    }else{
                        cout << "percobaan anda habis coba lagi\n";
                    }
                }else{
                    cout << "percobaan anda habis coba lagi\n";

                }
            }else if(opsi == 2){
                cout <<  "Masukkan album yang first lagu  yang ingin dihapus"<< endl;
                cout <<  "Masukkan album                :  ";
                cin >> inputAlbum.judulAlbum;
                foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
                foundLagu = foundAlbm->firstLagu;
                deleteFirstDataLagu(foundAlbm,foundLagu);
            }else if(opsi == 3){
                cout <<  "Masukkan album yang last lagu  yang ingin dihapus"<< endl;
                cout <<  "Masukkan album                :  ";
                cin >> inputAlbum.judulAlbum;
                foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
                foundLagu = foundAlbm->firstLagu;
                deleteLastDataLagu(foundAlbm,foundLagu);
            }else{
                cout << "Input tidak valid" << endl;
            }
            break;
        case 7 : 
            cout << "Masukkan Judul Album: ";
            cin >> inputAlbum.judulAlbum;
            editDataAlbum(L,inputAlbum.judulAlbum);
            break;
        case 8 :
            cout << "Masukkan Album dari lagu yang akan di update\n";
            cout << "Judul Album: ";
            cin >> inputAlbum.judulAlbum;
            cout << "Judul Lagu: ";
            cin >> inputLagu.judulLagu;
            editDataLagu(L,inputAlbum.judulAlbum,inputLagu.judulLagu);
            break;
        case 9 : 
            cout << "Masukkan judul Album: ";
            cin >> inputAlbum.judulAlbum;
            foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
            if(foundAlbm != nullptr){
                cout << "Berhasil ditemukan\n\n";
                cout << "Judul Album            : ";
                cout << foundAlbm->infoAlbum.judulAlbum << endl;
                cout << "Artis                  : ";
                cout << foundAlbm->infoAlbum.artis << endl;
                cout << "Genre                  : ";
                cout << foundAlbm->infoAlbum.genre << endl;
                cout << "Tahun Rilis            : ";
                cout << foundAlbm->infoAlbum.tahunRilis << endl;
                cout << endl;
            }else{
                cout << "Gagal ditemukan\n";
            }
            break;
        case 10 :
            cout << "Masukkan judul: ";
            cin >> inputLagu.judulLagu;
            cout << "Masukkan Album: ";
            cin >> inputAlbum.judulAlbum;
            foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
            if( foundAlbm != nullptr){
                foundLagu = searchLagu(foundAlbm,inputLagu.judulLagu);
                if(foundLagu != nullptr){
                    cout << "Berhasil ditemukan\n\n";
                    cout << "Judul              :";
                    cout << foundLagu->infoLagu.judulLagu<<endl;
                    cout << "Artis              :";
                    cout << foundAlbm->infoAlbum.artis<<endl;
                    cout << "Jumlah Pendengar   :";
                    cout << foundLagu->infoLagu.pendengar<<endl;
                    cout << "Durasi             :";
                    cout << foundLagu->infoLagu.durasi<<endl;
                }else{
                    cout << "Lagu: "<<inputLagu.judulLagu<< " tidak ditemukan di album: "<<inputAlbum.judulAlbum<< endl;
                }
            }else{
                cout << "Album: "<< inputAlbum.judulAlbum << " tidak ditemukan\n";
            }
            break;
            case 11 : 
                cout << "1.Ascending\n";
                cout << "2.Descending\n";
                cout << "Pilih: ";
                cin >> opsi;
                if(opsi == 1){
                    sortDataAlbumByTahunAsc(L);
                    cout << "Data berhasil diurutkan\n";
                }else if(opsi == 2){
                    sortDataAlbumByTahunDesc(L);
                    cout << "Data berhasil diurutkan\n";
                }else{
                    cout << "Input tidak valid\n";
                }
            break;
        case 12 : 
            cout << "Masukkan Judul Album: ";
            cin >> inputAlbum.judulAlbum;
            foundAlbm = searchAlbum(L,inputAlbum.judulAlbum);
            if(foundAlbm!=nullptr){
                cout << "Urutkan berdasarkan\n";
                cout << "1.Durasi\n";
                cout << "2.Pendengar\n";
                cout << "Pilih : ";
                cin >> opsi;
                if(opsi == 1){
                    cout << "1.Ascending\n";
                    cout << "2.Descending\n";
                    cout << "Pilih: ";
                    cin >> opsi;
                    if(opsi == 1){
                        sortDataLaguByDurasiAsc(foundAlbm);
                        cout << "Data berhasil di urutkan berdasarkan Durasi";
                    }else if(opsi == 2){
                        sortDataLaguByDurasiDesc(foundAlbm);
                        cout << "Data berhasil di urutkan berdasarkan Durasi";
                    }else{
                        cout << "Input tidak valid";
                    }
                }else if(opsi == 2){
                    cout << "1.Ascending\n";
                    cout << "2.Descending\n";
                    cout << "Pilih: ";
                    cin >> opsi;
                    if(opsi == 1){
                        sortDataLaguByPendengariAsc(foundAlbm);
                        cout << "Data berhasil di urutkan berdasarkan Pendengar";
                    }else if(opsi == 2){
                        sortDataLaguByPendengariDesc(foundAlbm);
                        cout << "Data berhasil di urutkan berdasarkan Pendenger";
                    }else{
                        cout << "Input tidak valid";
                    }
                }else{
                    cout << "Pilihan tidak valid\n";
                }
            }else{
                cout << "Album tidak ditemukan\n";
            }
            break;
        case 13 : 
            cout << "\nTotal Album: ";
            cout << totalAlbum(L);
            break;
        case 14 : 
            cout << "\nTotal Lagu: ";
            cout << totalLagu(L);
            break;
        case 15 :
            count = 1;
            cout << "Judul ALbum: ";
            cin >> inputAlbum.judulAlbum;
            found = searchAlbum(L,inputAlbum.judulAlbum);
            while(found == nullptr && count < 3){
                cout << "Album tidak ditemukan\n";
                cout << "Judul Album: ";
                cin >> inputAlbum.judulAlbum;
                found = searchAlbum(L,inputAlbum.judulAlbum);
                count++;
            }
            if(count < 3){
                cout << "====== Statistik Album "<< inputAlbum.judulAlbum<< " ======\n";
                cout << "\nRata-Rata Durasi     :"<< AverageSongsDurationByAlbum(L, found);
                p = longestDurationSongTitle(L,found);
                cout << "\nDurasi Terpanjang    :"<< p->infoLagu.judulLagu << " - " << MaxDurationSongByALbum(L,found);
                p = shortesDurationSongTitle(L,found);
                cout << "\nDurasi Terpendek    :"<< p->infoLagu.judulLagu << " - " << MinDurationSongByALbum(L,found);
                
                cout << "\n \nRata-Rata Pendengar  :" << AverageListensByAlbum(L,found);
                p = mostListenedSongTitle(L,found);
                cout << "\nPendengar Terbanyak  :" << p->infoLagu.judulLagu << " - " << MaxListensSongByALbum(L,found);
                p = leastSongTitle(L,found);
                cout << "\nPendengar Terdikit   :" << p->infoLagu.judulLagu << " - "<< MinListensSongByALbum(L,found);
            }else{
                cout << "percobaan anda habis coba lagi\n";
            }
            break;
        case 16:
            exportToFile(L);
            break;
        default: cout << "Masukkan 1-15!!!";
    }

};

void createListAlbum(listAlbum &L){
    L.first = nullptr;
    L.last = nullptr;
};

bool isEmptyAlbum(listAlbum L){
    return L.first == nullptr && L.last == nullptr;
};

bool isEmptyLagu(adrAlbum p){
    return p->firstLagu == nullptr;
};

bool isAlbumExists(listAlbum L, string judulAlbum){
    adrAlbum p = L.first;
    while(p!= nullptr){
        if(p->infoAlbum.judulAlbum == judulAlbum){
            return true;
        }
        p=p->nextAlbum;
    }
    return false;
};

adrAlbum createElementAlbum(string judulAlbum,string artis,int tahunRilis,string genre){
    adrAlbum p = new elmAlbum;
    p->infoAlbum.artis = artis;
    p->infoAlbum.genre = genre;
    p->infoAlbum.judulAlbum = judulAlbum;
    p->infoAlbum.tahunRilis = tahunRilis;
    p->firstLagu = nullptr;
    p->nextAlbum = nullptr;
    p->prevAlbum = nullptr;
    return p;
    
};

adrLagu createElementLagu(string judulLagu,float durasi,int pendengar){
    adrLagu p = new elmLagu;
    p->infoLagu.judulLagu = judulLagu;
    p->infoLagu.durasi = durasi;
    p->infoLagu.pendengar = pendengar;
    p->nextLagu = nullptr;
    p->prevLagu = nullptr;
    return p;
};

// end utils

// masukkan data lagu dan album
void insertDataAlbum(listAlbum &L, adrAlbum p){
    if(isEmptyAlbum(L)){
        L.first = p;
        L.last = p;
        p->nextAlbum = nullptr;
        p->prevAlbum = nullptr;
    }else{
        adrAlbum q = L.last;
        q->nextAlbum = p;
        p->prevAlbum = q;
        p->nextAlbum = nullptr;
        L.last = p;
    }
};

void insertDatalagu(adrAlbum &q, adrLagu p ){
    if(isEmptyLagu(q)){
        q->firstLagu = p;
        p->nextLagu = nullptr;
        p->prevLagu = nullptr;
    }else{
        adrLagu r = q->firstLagu;
        while(r->nextLagu != nullptr){
            r =r->nextLagu; 
        }
        r->nextLagu = p;
        p->prevLagu = r;
        p->nextLagu = nullptr;
    }
};
// end masukkan data lagu dan album

// Hapus data album dan lagu 
void deleteDataAlbumByJudul(listAlbum &L,string judulAlbum){
    if(!isEmptyAlbum(L)){
        adrAlbum p = searchAlbum(L,judulAlbum);
        if(!isEmptyLagu(p)){
            if(p == L.first && p == L.last){
               L.first = nullptr;
               L.last = nullptr;
               cout << "Data berhasil dihapus" << endl;
            }else if(p ==L.first){
               L.first = p->nextAlbum;
               if(p->nextAlbum != nullptr){
                    p->nextAlbum->prevAlbum = nullptr;
               }
               p->nextAlbum = nullptr;
               cout << "Data berhasil dihapus";
            }else if(p == L.last){
              L.last = p->prevAlbum;
              if(p->prevAlbum != nullptr){
                p->prevAlbum->nextAlbum = nullptr;
              }  
              p->prevAlbum->nextAlbum = nullptr;
              p->prevAlbum = nullptr;
              cout << "Data berhasil dihapus" << endl;
            }else{
                p->prevAlbum->nextAlbum = p->nextAlbum;
                p->nextAlbum->prevAlbum = p->prevAlbum;
                cout << "Data berhasil dihapus" << endl;
            }
        }else{
            cout << "Album tidak ditemukan"<< endl;
        }
    }else{
        cout << "List album kosong" << endl;
    }
};

void deleteDataLaguByJudul(listAlbum &L, adrLagu laguFound, adrAlbum almbFound){
    if(laguFound == almbFound->firstLagu){
        if(laguFound->nextLagu != nullptr){
            almbFound->firstLagu = laguFound->nextLagu;
            almbFound->firstLagu->prevLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            almbFound->firstLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }
    }else{
        if(laguFound->nextLagu == nullptr){
            laguFound->prevLagu->nextLagu = nullptr;
            laguFound->prevLagu =nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            laguFound->prevLagu->nextLagu = laguFound->nextLagu;
            laguFound->nextLagu->prevLagu = laguFound->prevLagu;
            cout << "Data berhasil dihapus"<< endl;
        }
    }
    
    
}; // delete after

void deleteLastDataAlbum(listAlbum &L,adrAlbum p){
    if(!isEmptyAlbum(L)){
        if(L.first != L.last){
            L.last = p->prevAlbum;
            p->prevAlbum->nextAlbum = nullptr;
            p->prevAlbum = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            L.first =  nullptr;
            L.last =  nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }
    }else{
        cout << "List album kosong" << endl;
    }
};

void deleteFirstDataAlbum(listAlbum &L,adrAlbum p){
    if(!isEmptyAlbum(L)){
        if(L.first != L.last){
            L.first = p->nextAlbum;
            p->nextAlbum = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            L.first =  nullptr;
            L.last =  nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }
    }else{
        cout << "List album kosong" << endl;
    }
};

void deleteLastDataLagu(adrAlbum &q,adrLagu p){
    if(!isEmptyLagu(q)){
        if(q->firstLagu->nextLagu == nullptr){
            q->firstLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            adrLagu firstLagu = q->firstLagu;
            while(firstLagu->nextLagu!=nullptr){
                firstLagu = firstLagu->nextLagu;
            }
            firstLagu->prevLagu->nextLagu = nullptr;
            firstLagu->prevLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }
    }else{
        cout << "Lagu pada Album: " << q->infoAlbum.judulAlbum << "kosong"; 
    }
};

void deleteFirstDataLagu(adrAlbum &q,adrLagu p){
    if(!isEmptyLagu(q)){
        if(q->firstLagu->nextLagu == nullptr){
            q->firstLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }else{
            adrLagu r = q->firstLagu;
            q->firstLagu = r->nextLagu;
            q->firstLagu->prevLagu = nullptr;
            r->nextLagu = nullptr;
            r->prevLagu = nullptr;
            cout << "Data berhasil dihapus"<< endl;
        }
    }else{
        cout << "Lagu pada Album: " << q->infoAlbum.judulAlbum << "kosong"; 
    }
};

// end Hapus data album dan lagu

adrAlbum searchAlbum(listAlbum L, string judulAlbum){
    adrAlbum p = L.first;
    while(p!=nullptr){
        if(p->infoAlbum.judulAlbum == judulAlbum){
            return p;
        }
        p=p->nextAlbum;
    }
    return nullptr;
};

adrLagu searchLagu(adrAlbum p, string judulLagu){
    if(p->firstLagu != nullptr){
        adrLagu q = p->firstLagu;
        while(q!=nullptr){
            if(q->infoLagu.judulLagu == judulLagu){
                return q;
            }
            q=q->nextLagu;
        }
    }
    return nullptr;
};

void sortDataAlbumByTahunAsc(listAlbum &L){
    if(!isEmptyAlbum || L.first->nextAlbum != nullptr){
        adrAlbum p = L.first;
        while(p!=nullptr){
            adrAlbum min = p;
            adrAlbum temp = p->nextAlbum;
            while(temp != nullptr){
                if(temp->infoAlbum.tahunRilis < min->infoAlbum.tahunRilis){
                    min = temp;
                }
                temp = temp->nextAlbum;
            }
            if(min != p){
                infotypeAlbum tempInfo = p->infoAlbum;
                p->infoAlbum = min->infoAlbum;
                min->infoAlbum = tempInfo   ;

                adrLagu tempLagu = p->firstLagu;
                p->firstLagu = min->firstLagu;
                min->firstLagu = tempLagu;
            }
            p=p->nextAlbum;
        }
    }    
};

void sortDataAlbumByTahunDesc(listAlbum &L){
    if(!isEmptyAlbum || L.first->nextAlbum != nullptr){
        adrAlbum p = L.first;
        while(p!=nullptr){
            adrAlbum max = p;
            adrAlbum temp = p->nextAlbum;
            while(temp != nullptr){
                if(temp->infoAlbum.tahunRilis > max->infoAlbum.tahunRilis){
                    max = temp;
                }
                temp = temp->nextAlbum;
            }
            if(max != p){
                infotypeAlbum tempInfo = p->infoAlbum;
                p->infoAlbum = max->infoAlbum;
                max->infoAlbum = tempInfo   ;

                adrLagu tempLagu = p->firstLagu;
                p->firstLagu = max->firstLagu;
                max->firstLagu = tempLagu;
            }
            p=p->nextAlbum;
        }
    }    
};

void sortDataLaguByDurasiAsc(adrAlbum &p){
    if(!isEmptyLagu(p) || p->firstLagu != nullptr || p->firstLagu->nextLagu != nullptr){
        adrLagu q = p->firstLagu;
        while (q!=nullptr){
            adrLagu min = q;
            adrLagu temp = q->nextLagu;
            
            while(temp != nullptr){
                if(temp->infoLagu.durasi < min->infoLagu.durasi){
                    min = temp;
                }
                temp = temp->nextLagu;
            }
            
            if(min !=q){
                infotypeLagu tempLagu = q->infoLagu;
                q->infoLagu = min->infoLagu;
                min->infoLagu = tempLagu;
            }
            q=q->nextLagu;
        }
        
    }
};

void sortDataLaguByDurasiDesc(adrAlbum &p){
     if(!isEmptyLagu(p) || p->firstLagu != nullptr || p->firstLagu->nextLagu != nullptr){
        adrLagu q = p->firstLagu;
        while (q!=nullptr){
            adrLagu max = q;
            adrLagu temp = q->nextLagu;
            
            while(temp != nullptr){
                if(temp->infoLagu.durasi > max->infoLagu.durasi){
                    max = temp;
                }
                temp = temp->nextLagu;
            }
            
            if(max !=q){
                infotypeLagu tempLagu = q->infoLagu;
                q->infoLagu = max->infoLagu;
                max->infoLagu = tempLagu;
            }
            q=q->nextLagu;
        }
        
    }
};

void sortDataLaguByPendengariAsc(adrAlbum &p){
     if(!isEmptyLagu(p) || p->firstLagu != nullptr || p->firstLagu->nextLagu != nullptr){
        adrLagu q = p->firstLagu;
        while (q!=nullptr){
            adrLagu min = q;
            adrLagu temp = q->nextLagu;
            
            while(temp != nullptr){
                if(temp->infoLagu.pendengar < min->infoLagu.pendengar){
                    min = temp;
                }
                temp = temp->nextLagu;
            }
            
            if(min !=q){
                infotypeLagu tempLagu = q->infoLagu;
                q->infoLagu = min->infoLagu;
                min->infoLagu = tempLagu;
            }
            q=q->nextLagu;
        }
        
    }
};

void sortDataLaguByPendengariDesc(adrAlbum &p){
     if(!isEmptyLagu(p) || p->firstLagu != nullptr || p->firstLagu->nextLagu != nullptr){
        adrLagu q = p->firstLagu;
        while (q!=nullptr){
            adrLagu max = q;
            adrLagu temp = q->nextLagu;
            
            while(temp != nullptr){
                if(temp->infoLagu.pendengar > max->infoLagu.pendengar){
                    max = temp;
                }
                temp = temp->nextLagu;
            }
            
            if(max !=q){
                infotypeLagu tempLagu = q->infoLagu;
                q->infoLagu = max->infoLagu;
                max->infoLagu = tempLagu;
            }
            q=q->nextLagu;
        }
        
    }
};


int totalAlbum(listAlbum L){
    int total = 0;    
    if (!isEmptyAlbum(L)) {
        adrAlbum p = L.first;
        while (p != nullptr) {
            total++;
            p = p->nextAlbum;
        }
    }
    
    return total;
};

int totalLagu(listAlbum L){
    int total = 0;
    adrAlbum album = L.first;
    while (album != nullptr) {
        adrLagu lagu = album->firstLagu;
        while (lagu != nullptr) {
            total++;
            lagu = lagu->nextLagu;
        }
        
        album = album->nextAlbum;
    }
    
    return total;
};

void editDataAlbum(listAlbum &L,string judulAlbum){
    if(!isEmptyAlbum(L)){
        adrAlbum p = searchAlbum(L,judulAlbum);
        if(p!=nullptr){
            cout << "\n======== EDIT DATA ALBUM ========" << endl;
            cout << "Judul Album    : "<< p->infoAlbum.judulAlbum<< endl;
            cout << "Artis          : "<< p->infoAlbum.artis<< endl;
            cout << "Tahun Rilis    : "<< p->infoAlbum.tahunRilis<< endl;
            cout << "Genre          : "<< p->infoAlbum.genre<< endl;
            
            infotypeAlbum input;
            cout << "\nMasukkan data baru\n(isi dengan - jika tidak ingin diubah!!):" << endl;
            cout << "Judul Album    : ";
            cin >> input.judulAlbum;
            if(input.judulAlbum == "-"){
                cout << "akan di isi dengan yang sebelumnya\n";
            }else{
                p->infoAlbum.judulAlbum = input.judulAlbum;
            }
            cout << "Artis          : ";
            cin >> input.artis;
            if(input.artis == "-"){
                cout << "akan di isi dengan yang sebelumnya\n";
            }else{
                p->infoAlbum.artis = input.artis;
            }
            cout << "Tahun Rilis(1901-2026): ";
            cin >> input.tahunRilis;
            if(input.tahunRilis < 1901 || input.tahunRilis > 2025){
                cout << "Tahun tidak valid, akan di isi dengan yang sebelumnya\n";
            }else{
                p->infoAlbum.tahunRilis = input.tahunRilis;
            }
            
            cout << "Genre          : ";
            cin >> input.genre;
            if(input.genre == "-"){
                cout << "akan di isi dengan yang sebelumnya\n";
            }else{
                p->infoAlbum.genre = input.genre;
            }
            cout << "\nData Berhasil diperbaruhi\n";
        }else{
            cout << "Album tidak ditemukan\n";
        }
    }else{
        cout << "List kosong";
    }
};

void editDataLagu(listAlbum &L, string judulAlbum, string judulLaguLama){
    if(!isEmptyAlbum(L)){
        adrAlbum foundAlbm = searchAlbum(L,judulAlbum);
        if(!isEmptyLagu(foundAlbm)){
            adrLagu foundlagu = searchLagu(foundAlbm,judulLaguLama);
            if(foundlagu != nullptr){
                cout << "\n======== EDIT DATA LAGU ========" << endl;
                cout << "Judul Lagu         : "<< foundlagu->infoLagu.judulLagu<< endl;
                cout << "Durasi             : "<< foundlagu->infoLagu.durasi<< endl;
                cout << "Jumlah Pendengar   : "<< foundlagu->infoLagu.pendengar<< endl;
                
                infotypeLagu input;
                cout << "\nMasukkan data baru\n(isi dengan - jika tidak ingin diubah):" << endl;
                cout << "Judul Lagu     : ";
                cin >> input.judulLagu;
                if(input.judulLagu == "-"){
                    cout << "akan di isi denga yang sebelumnya\n";
                }else{
                    foundlagu->infoLagu.judulLagu = input.judulLagu;
                }

                cout << "Durasi(min 0.15): ";
                cin >> input.durasi;
                if(input.durasi < 0.15){
                    cout << "Durasi tidak valid,akan di isi dengan yang sebelumnya\n";
                }else{
                    foundlagu->infoLagu.durasi = input.durasi;
                }

                cout << "Jumlah Pendengar: ";
                cin >> input.pendengar;
                if(input.pendengar < 0 ){
                    cout << "Pendengar tidak valid, akan di isi dengan yang sebelumnya\n";
                }else{
                    foundlagu->infoLagu.pendengar = input.pendengar;
                }
                cout << "\nData Berhasil diperbaruhi\n";
            }else{
                cout << "Lagu tidak ditemukan\n";
            }
        }else{
            cout << "Album tidak ditemukan\n";
        }
    }

};

float AverageSongsDurationByAlbum(listAlbum L,adrAlbum p){
    float avg = 0;
    int count = 0;
    adrLagu q = p->firstLagu;
    while(q!=nullptr){
        avg += q->infoLagu.durasi;
        q = q->nextLagu; 
        count++;
    }
    return avg/float(count);
};

int AverageListensByAlbum(listAlbum L,adrAlbum p){
    int avg = 0;
    int count = 0;
    adrLagu q = p->firstLagu;
    while(q!= nullptr){
        avg += q->infoLagu.pendengar;
        q =q->nextLagu;
        count++;
    } 
    return avg/count;
};

float MaxDurationSongByALbum(listAlbum L, adrAlbum p){
    float max = p->firstLagu->infoLagu.durasi;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(max < q->infoLagu.durasi){
            max = q->infoLagu.durasi;
        }
        q =q->nextLagu;
    } 
    return max;
    
};

float MinDurationSongByALbum(listAlbum L, adrAlbum p){
    float min = p->firstLagu->infoLagu.durasi;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(min > q->infoLagu.durasi){
            min = q->infoLagu.durasi;
        }
        q =q->nextLagu;
    } 
    return min;
};

int MaxListensSongByALbum(listAlbum L, adrAlbum p){
    int max = p->firstLagu->infoLagu.pendengar;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(max < q->infoLagu.pendengar){
            max = q->infoLagu.pendengar;
        }
        q =q->nextLagu;
    } 
    return max;
};

int MinListensSongByALbum(listAlbum L, adrAlbum p){
    int min = p->firstLagu->infoLagu.pendengar;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(min > q->infoLagu.pendengar){
            min = q->infoLagu.pendengar;
        }
        q =q->nextLagu;
    } 
    return min;
};

adrLagu mostListenedSongTitle(listAlbum L, adrAlbum p){
    adrLagu mostListened = p->firstLagu;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(mostListened->infoLagu.pendengar < q->infoLagu.pendengar){
            mostListened = q;
        }
        q =q->nextLagu;
    } 
    return mostListened;
};

adrLagu leastSongTitle(listAlbum L, adrAlbum p){
    adrLagu leastListened = p->firstLagu;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(leastListened->infoLagu.pendengar > q->infoLagu.pendengar){
            leastListened = q;
        }
        q =q->nextLagu;
    } 
    return leastListened;
};

adrLagu longestDurationSongTitle(listAlbum L, adrAlbum p){
    adrLagu maxDuration = p->firstLagu;
    adrLagu q = p->firstLagu->nextLagu;
    while(q!= nullptr){
        if(maxDuration->infoLagu.durasi < q->infoLagu.durasi){
            maxDuration = q;
        }
        q =q->nextLagu;
    } 
    return maxDuration;
};

adrLagu shortesDurationSongTitle(listAlbum L, adrAlbum a){
    adrLagu minDuration = a->firstLagu;
    adrLagu q = a->firstLagu->nextLagu;
    while(q!= nullptr){
        if(minDuration->infoLagu.durasi > q->infoLagu.durasi){
            minDuration = q;
        }
        q =q->nextLagu;
    } 
    return minDuration;
};


void exportToFile(listAlbum L) {
    ofstream file("data_album.txt");
    
    adrAlbum album = L.first;
    while(album != nullptr) {
        file << "ALBUM: " << album->infoAlbum.judulAlbum << endl;
        file << "Artis: " << album->infoAlbum.artis << endl;
        file << "Tahun: " << album->infoAlbum.tahunRilis << endl;
        file << "Genre: " << album->infoAlbum.genre << endl;
        
        adrLagu lagu = album->firstLagu;
        while(lagu != nullptr) {
            file << "  - " << lagu->infoLagu.judulLagu 
                 << " | " << lagu->infoLagu.durasi 
                 << " | " << lagu->infoLagu.pendengar << endl;
            lagu = lagu->nextLagu;
        }
        file << endl;
        album = album->nextAlbum;
    }
    file.close();
    cout << "Data berhasil diexport ke data_album.txt\n";
}

void initDataDummy(listAlbum &L) {
    // --- Album: The Best of Dewa 19 (Dewa 19) ---
    adrAlbum a2 = new elmAlbum;
    a2->infoAlbum.judulAlbum = "The-Best-of-Dewa-19";
    a2->infoAlbum.artis = "Dewa-19";
    a2->infoAlbum.genre = "Pop-Rock";
    a2->infoAlbum.tahunRilis = 2004;
    insertDataAlbum(L, a2);

    // Lagu-lagu Album The Best of Dewa 19
    adrLagu l10 = new elmLagu;
    l10->infoLagu.judulLagu = "Kangen";
    l10->infoLagu.durasi = 4.19;
    l10->infoLagu.pendengar = 1000000;
    insertDatalagu(a2, l10);

    adrLagu l11 = new elmLagu;
    l11->infoLagu.judulLagu = "Roman-Picisan";
    l11->infoLagu.durasi = 4.02;
    l11->infoLagu.pendengar = 2500000;
    insertDatalagu(a2, l11);

    adrLagu l12 = new elmLagu;
    l12->infoLagu.judulLagu = "Cinta-Kan-Membawamu-Kembali";
    l12->infoLagu.durasi = 4.30;
    l12->infoLagu.pendengar = 1200000;
    insertDatalagu(a2, l12);

    adrLagu l13 = new elmLagu;
    l13->infoLagu.judulLagu = "Aku-Disini-Untukmu";
    l13->infoLagu.durasi = 4.15;
    l13->infoLagu.pendengar = 900000;
    insertDatalagu(a2, l13);

    adrLagu l14 = new elmLagu;
    l14->infoLagu.judulLagu = "Pupus";
    l14->infoLagu.durasi = 4.20;
    l14->infoLagu.pendengar = 2000000;
    insertDatalagu(a2, l14);

    adrLagu l15 = new elmLagu;
    l15->infoLagu.judulLagu = "Mistikus-Cinta";
    l15->infoLagu.durasi = 4.08;
    l15->infoLagu.pendengar = 12300;
    insertDatalagu(a2, l15);

    adrLagu l16 = new elmLagu;
    l16->infoLagu.judulLagu = "Dewi";
    l16->infoLagu.durasi = 4.35;
    l16->infoLagu.pendengar = 1300000;
    insertDatalagu(a2, l16);

    adrLagu l17 = new elmLagu;
    l17->infoLagu.judulLagu = "Kamulah-Satu-Satunya";
    l17->infoLagu.durasi = 4.25;
    l17->infoLagu.pendengar = 3000000;
    insertDatalagu(a2, l17);
}