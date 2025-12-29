#include "mll.h"

int main(){
    listAlbum L;
    createListAlbum(L);
    adrLagu lagu;
    adrAlbum album;
    bool active = true;
    int opsi;
    initDataDummy(L);
    while(active){
        welcomePage();
        fiturPage();
        cout << "Pilih fitur: ";
        cin >> opsi;
        if(opsi == 0){
            active = false;
            goodBy();   
        }else{            
            executeOpsi(L, album,lagu,opsi);
        }
    }
    return 0;
}