#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
// struktur MLL
struct album{
    string judulAlbum;
    string artis;
    int tahunRilis;
    string genre;
};

struct lagu{
    string judulLagu;
    float durasi;
    int pendengar;
};

typedef album infotypeAlbum;
typedef lagu infotypeLagu;

typedef struct elmAlbum *adrAlbum;

typedef struct elmLagu *adrLagu;

struct elmAlbum{
    infotypeAlbum infoAlbum;
    adrAlbum nextAlbum;
    adrAlbum prevAlbum;
    adrLagu firstLagu;
};

struct elmLagu{
    infotypeLagu infoLagu;
    adrLagu nextLagu;
    adrLagu prevLagu;
};

struct listAlbum{
    adrAlbum first;
    adrAlbum last;
};
// end struktur MLL

void initDataDummy(listAlbum &L);


// procedure tampilan
void welcomePage();
void fiturPage();
void goodBy();
void displayListAlbum(listAlbum L);
void displayListLagu(listAlbum L);
// end procedure tampilan

// utils 
void executeOpsi(listAlbum &L,adrAlbum album,adrLagu lagu,int opsi);
void createListAlbum(listAlbum &L);
bool isEmptyAlbum(listAlbum L);
bool isEmptyLagu(adrAlbum p);
bool isAlbumExists(listAlbum L, string judulAlbum);
adrAlbum createElementAlbum(string judulAlbum,string artis,int tahunRilis,string genre);
adrLagu createElementLagu(string judulLagu,float durasi,int pendengar);
// end utils


// Masukkan Data album dan lagu
void insertDataAlbum(listAlbum &L, adrAlbum p); // insert last
void insertDatalagu(adrAlbum &q, adrLagu p ); // insert last
// end masukkan data album dan lagu

// Hapus data album dan lagu
void deleteDataAlbumByJudul(listAlbum &L,string judulAlbum); // delte after
void deleteDataLaguByJudul(listAlbum &L, adrLagu laguFound, adrAlbum almbFound); // delete after
void deleteLastDataAlbum(listAlbum &L,adrAlbum p);
void deleteFirstDataAlbum(listAlbum &L,adrAlbum p);
void deleteLastDataLagu(adrAlbum &q,adrLagu p);
void deleteFirstDataLagu(adrAlbum &q,adrLagu p);
// end Hapus data album dan lagu

// Edit data album dan lagu
void editDataAlbum(listAlbum &L,string judulAlbum);
void editDataLagu(listAlbum &L, string judulAlbum, string judulLaguLama);
// end Edit data album dan lagu


// cari album dan lagu 
adrAlbum searchAlbum(listAlbum L, string judulAlbum);
adrLagu searchLagu(adrAlbum p, string judulLagu);
// end cari album dan lagu 

// sorting album dan lagu
void sortDataAlbumByTahunAsc(listAlbum &L);
void sortDataAlbumByTahunDesc(listAlbum &L);
void sortDataLaguByDurasiAsc(adrAlbum &p);
void sortDataLaguByDurasiDesc(adrAlbum &p);
void sortDataLaguByPendengariAsc(adrAlbum &p);
void sortDataLaguByPendengariDesc(adrAlbum &p);

// end sorting album dan lagu

// Statistik album
float AverageSongsDurationByAlbum(listAlbum L,adrAlbum p);
int AverageListensByAlbum(listAlbum L,adrAlbum p);
float MaxDurationSongByALbum(listAlbum L, adrAlbum p);
float MinDurationSongByALbum(listAlbum L, adrAlbum p);
int MaxListensSongByALbum(listAlbum L, adrAlbum p);
int MinListensSongByALbum(listAlbum L, adrAlbum p);
adrLagu mostListenedSongTitle(listAlbum L, adrAlbum p);
adrLagu leastSongTitle(listAlbum L, adrAlbum p);
adrLagu longestDurationSongTitle(listAlbum L, adrAlbum p);
adrLagu shortesDurationSongTitle(listAlbum L, adrAlbum a);
void exportToFile(listAlbum L);
void topFiveSong(listAlbum L);
// end Statistik album

// hitung total album dan lagu
int totalAlbum(listAlbum L);
int totalLagu(listAlbum L);
// end hitung total album dan lagu
#endif // TREE_H_INCLUDED