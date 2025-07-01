/*Saya Muhammad 'Azmi Salam mengerjakan evaluasi Tugas Masa
Depan dalam mata kuliah Dasar-dasar Pemrograman untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.*/

#include "header.h"     // Mengincludekan library yang diinginkan
#include "animasi.h"    // Mengincludekan library yang diinginkan

// fungsi untuk memeriksa akhir dari proses (End of Process)
int EOP(){
    if(cc == ';'){ // jika cc saat ini ';'
        return 1; // kembalikan nilai 1 (marking eop true)
    }
    else{ // jika tidak
        return 0; // kembalikan nilai 0
    }
}

// prosedur untuk memulai mesin karakter
void START(char pita[]){
    // memulai pembacaan mesin karakter
    idx = 0; // index pasti dimulai dari 0
    cc = pita[idx]; // cc adalah pita inputan ke idx = 0
}

// prosedur untuk memajukan karakter pada pita
void INC(char pita[]){
    // menambah nilai indeks dan mengatur karakter yang dibaca
    idx++;
    cc = pita[idx];
}

// fungsi untuk mendapatkan karakter pita saat ini
char GETCC(){
    return cc;
}

// cek eop
int eop(char pita[]){
    if(pita[idx] == ';'){ // jika ';' return 1
        return 1;
    }
    else{
        return 0; // jika bukan ';' kembalikan 0
    }
}

// memulai mesin
void start(char pita[]){
    // set index dan panjang kata menjadi 0
    idx = 0;
    wlen = 0;

    if(pita[idx] == '"'){ // kondisi jika nama mengandung spasi, maka harus diapit dengan tanda petik 2
        idx++;
        while(((pita[idx] != '"') && (eop(pita) == 0)) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
            if(pita[idx] == '\\' ){
                idx++;
            }
            
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0';
        idx++;
    }else{
        // masukkan kata baru
        while ((pita[idx] != ' ') && (eop(pita) == 0)){
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0'; // akhiri lagi
    }
}

// reset current word
void reset(){
    wlen = 0; // kembalikan panjang kata menjadi 0
    cw[wlen] = '\0'; // set current word menjadi null (siap diisi)
}


// pindah next kata
void inc(char pita[]){
    wlen = 0; // set panjang kata jadi 0 (memastikan)


    while (pita[idx] == ' '){ // ignore blank
        idx++;
    }
    
    if(pita[idx] == '"'){ // kondisi jika nama mengandung spasi, maka harus diapit dengan tanda petik 2
        idx++;
        while(((pita[idx] != '"') && (eop(pita) == 0)) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
            if(pita[idx] == '\\' ){
                idx++;
            }
            
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0';
        idx++;
    }else{ // kondisi kata biasa
        // masukkan kata baru
        while ((pita[idx] != ' ') && (eop(pita) == 0)){
            cw[wlen] = pita[idx];
            wlen++;
            idx++;
        }
        cw[wlen] = '\0'; // akhiri lagi
    }

}

// pindah ke kata sebelumnya
void dec(char pita[]){
    if(idx > 0){

        while (idx >= 0 && (pita[idx] == ' ' || pita[idx] == ';')){ // ignore blank
            idx--;
        }

        if(pita[idx] == '"'){
            idx--;
            //memundurkan indeks ke kata sebelumnya
            while (idx >= 0 && (pita[idx] != '"') && (eop(pita) == 0) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
                idx--;
            }
            idx--;
            idx--;
        }else{
            //memundurkan indeks ke kata sebelumnya
            while (idx >= 0 && (pita[idx] != ' ') && (eop(pita) == 0)){
                idx--;
            }
            idx--;
        }
        
        
        wlen = 0; // set panjang kata jadi 0 (memastikan)
        
        if(pita[idx] == '"'){ // kondisi jika nama mengandung spasi, maka harus diapit dengan tanda petik 2
            idx--;
            int lastc = idx;
            // menghitung panjang kata
            while (idx >= 0 && (pita[idx] != '"') && (eop(pita) == 0) || ((pita[idx-1] == '\\') && (eop(pita) == 0))){
                if(pita[idx] == '\\' ){
                    idx--;
                }
                
                wlen++;
                idx--;
            }
            // printf("|%d|", wlen);
            idx++; // masuk ke awal kata
            
            for(int i = 0; i < wlen; i++){
                if(pita[idx] == '\\' ){
                    idx++;
                }
                cw[i] = pita[idx++];
            }
            cw[wlen] = '\0'; // akhiri lagi
            idx++;
        }else{
            int lastc = idx;
            // menghitung panjang kata
            while (idx >= 0 && (pita[idx] != ' ') && (eop(pita) == 0)){
                wlen++;
                idx--;
            }
            idx++; // masuk ke awal kata
            
            for(int i = 0; i < wlen; i++){
                cw[i] = pita[idx++];
            }
            cw[wlen] = '\0'; // akhiri lagi
        }
    }
}


// mengembalikan current word
char* getcw(){
    return cw;
}


// mengembalikan panjang current word
int getlen(){
    return wlen;
}


// menghitung jumlah kata pada suatu string
int countw(char pita[]){
    char tmp[51];
    strcpy(tmp, getcw());

    int jkata = 0;
    start(pita);// mulai kata
    while(eop(pita) == 0){ // loop selama belum bertemu eop
        jkata++; // jumlah kata bertambah
        inc(pita); // maju ke kata selanjutnya
    }

    // menghitung sisa kata yang memiliki eop
    if(getlen() > 0){
        jkata++;
    }

    //mengembalikan indeks kata
    start(pita);
    while(strcmp(tmp, getcw()) != 0){
        inc(pita);
    }

    
    return jkata;
}

// menghitung sekarang ada di kata keberapa pada suatu string
int wordnow(char pita[]){
    char tmp[51];
    strcpy(tmp, getcw());

    int jkata = 1;
    start(pita);// mulai kata
    while(strcmp(getcw(), tmp) != 0){ // loop selama belum bertemu kata sekarang
        jkata++; // jumlah kata bertambah
        inc(pita); // maju ke kata selanjutnya
    }
    
    return jkata;
}

// Mengecek apakah dalam pita tersebut memiliki EOP (;) atau tidak
int cekEOP(char pita[]){
    START(pita);
    int i = 0;
    while (i < strlen(pita) - 1){
        INC(pita);
        i++;
    }

    if(GETCC() == ';'){
        return 1;
    }else{
        return 0;
    }
}

// Mengecek apakah kata saat ini merupakan kata terakhir
int lastw(char pita[]){
    if(wordnow(pita) == countw(pita)){
        return 1;
    }else{
        return 0;
    }
}

// Menghitung jumlah pita di dalam pita masukan 
int ctape(char pita[]){
    int i = 0;
    int tape = 0;
    while(i < strlen(pita) - 1){
        if(pita[i] == '\\' && pita[i + 1] == ';'){
            tape++;
        }
        i++;
    }

    return tape;
}

// Memisahkan Multi Pita Ke Dalam Array Of Pita
void pisahtape(char pita[], char tmp[51][101]){
    start(pita);
    int i = 0;
    while(eop(pita) == 0){
        strcpy(tmp[i], getcw());
        i++;
        inc(pita);
    }
    strcpy(tmp[i], getcw());
}

// Prosedur Write Untuk Id Kasus
void write_IdKasus(int n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fKasus, "%s|%s|%s|%s|%s\n", source[i].idKasus, source[i].nama, source[i].idSin, source[i].idHakim, source[i].idGedung);
    }
        fprintf(fKasus, "%s|%s|%s|%s|%s\n", "####", "####", "####", "####", "####");

        fclose(fKasus);
}

// Prosedur Write Untuk Kasus
void write_Kasus(int n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fKasus, "%s|%s|%s|%s|%s|%s\n", source[i].idKasus, source[i].nama, source[i].kejahatan, source[i].hukuman, source[i].hakim, source[i].gedung);
    }
        fprintf(fKasus, "%s|%s|%s|%s|%s|%s\n", "####", "####", "####", "####", "####", "####");

        fclose(fKasus);
}

// Prosedur Write Untuk Id Kasus dan Kasus
void write_IdKasus_Kasus(int n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fKasus, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n", source[i].idKasus, source[i].nama, source[i].idSin, source[i].kejahatan, source[i].hukuman, source[i].idHakim, source[i].hakim, source[i].idGedung, source[i].gedung);
    }
        fprintf(fKasus, "%s|%s|%s|%s|%s|%s|%s|%s|%s\n", "####", "####", "####", "####", "####", "####", "####", "####", "####");

        fclose(fKasus);
}

// Prosedur Write Untuk Data Sin
void write_Sin(int n, sin source[], char fileName[]){
    FILE *fsin;
    fsin = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fsin, "%s|%s|%s\n", source[i].kode, source[i].kejahatan, source[i].hukuman);
    }
        fprintf(fsin, "%s|%s|%s\n", "####", "####", "####");

        fclose(fsin);
}

// Prosedur Write Untuk Data Hakim/ Gedung
void write_HG(int n, hg source[], char fileName[]){
    FILE *fhg;
    fhg = fopen(fileName, "w");

    for(int i = 0; i < n; i++){
        fprintf(fhg, "%s|%s\n", source[i].kode, source[i].nama);
    }
        fprintf(fhg, "%s|%s\n", "####", "####");

        fclose(fhg);
}

// Prosedur Read Untuk Id Kasus
void read_IdKasus(int *n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fKasus, " %4[^|]|%50[^|]|%4[^|]|%4[^|]|%4[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].idSin, source[*n].idHakim, source[*n].idGedung);

    if(strcmp(source[*n].idKasus, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].idKasus, "####") != 0){
            *n = *n + 1;
            fscanf(fKasus, " %4[^|]|%50[^|]|%4[^|]|%4[^|]|%4[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].idSin, source[*n].idHakim, source[*n].idGedung);
        }
    }

    fclose(fKasus);
}

// Prosedur Read Untuk Kasus
void read_Kasus(int *n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fKasus, " %4[^|]|%50[^|]|%50[^|]|%50[^|]|%50[^|]|%50[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].kejahatan, source[*n].hukuman, source[*n].hakim, source[*n].gedung);

    if(strcmp(source[*n].idKasus, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].idKasus, "####") != 0){
            *n = *n + 1;
            fscanf(fKasus, " %4[^|]|%50[^|]|%50[^|]|%50[^|]|%50[^|]|%50[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].kejahatan, source[*n].hukuman, source[*n].hakim, source[*n].gedung);
        }
    }

    fclose(fKasus);
}

// Prosedur Read Untuk Kasus dan Id Kasus
void read_IdKasus_Kasus(int *n, data source[], char fileName[]){
    FILE *fKasus;
    fKasus = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fKasus, " %4[^|]|%50[^|]|%4[^|]|%50[^|]|%50[^|]|%4[^|]|%50[^|]|%4[^|]|%50[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].idSin, source[*n].kejahatan, source[*n].hukuman, source[*n].idHakim, source[*n].hakim, source[*n].idGedung, source[*n].gedung);

    if(strcmp(source[*n].idKasus, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].idKasus, "####") != 0){
            *n = *n + 1;
            fscanf(fKasus, "  %4[^|]|%50[^|]|%4[^|]|%50[^|]|%50[^|]|%4[^|]|%50[^|]|%4[^|]|%50[^\n]s", source[*n].idKasus, source[*n].nama, source[*n].idSin, source[*n].kejahatan, source[*n].hukuman, source[*n].idHakim, source[*n].hakim, source[*n].idGedung, source[*n].gedung);
        }
    }

    fclose(fKasus);
}

// Prosedur Read Untuk Data Sin
void read_Sin(int *n, sin source[], char fileName[]){
    FILE *fsin;
    fsin = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fsin, " %4[^|]|%50[^|]|%50[^\n]s", source[*n].kode, source[*n].kejahatan, source[*n].hukuman);

    if(strcmp(source[*n].kode, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].kode, "####") != 0){
            *n = *n + 1;
            fscanf(fsin, " %4[^|]|%50[^|]|%50[^\n]s", source[*n].kode, source[*n].kejahatan, source[*n].hukuman);
        }
    }

    fclose(fsin);
}

// Prosedur Read Untuk Data Hakim/ Gedung
void read_HG(int *n, hg source[], char fileName[]){
    FILE *fhg;
    fhg = fopen(fileName, "r");//r untuk operator read file

    int returnVal = fscanf(fhg, " %4[^|]|%50[^\n]s", source[*n].kode, source[*n].nama);

    if(strcmp(source[*n].kode, "####") == 0 || returnVal == EOF) printf("File Kosong\n");
    else{
        while(strcmp(source[*n].kode, "####") != 0){
            *n = *n + 1;
            fscanf(fhg, " %4[^|]|%50[^\n]s", source[*n].kode, source[*n].nama);
        }
    }

    fclose(fhg);
}

// Prosedur Untuk Menampilkan Query Success
void SUCCESS(int n){
    if(nonterm){
        printf(LINE2"//===================================================================================================\\\\\n");
        printf("|+---------------------------------------YOUR QUERY RESULT-------------------------------------------+|\n");
        printf("||                                                                                                   ||\n");
        printf("|+---------------------------------------------------------------------------------------------------+|\n");
        printf("\\\\===================================================================================================//\n");
        printf(RESULT);
    }
    if(n == 1){
        printf(GREEN "SUCCESS: INSERT Berhasil, lalala yeyeyeye~\n" RESET);
    }else if(n == 2){
        printf(GREEN "SUCCESS: UPDATE Berhasil, lalala yeyeyeye~\n" RESET);
    }else if(n == 3){
        printf(GREEN "SUCCESS: DELETE Berhasil, lalala yeyeyeye~\n" RESET);
    }else if(n == 4){
        printf(GREEN "SUCCESS: Masukan Berhasil, Menampilkan Data Yang Anda Minta!\n" RESET);
    }else if(n == 5){
        printf(GREEN "SUCCESS: Masukan Berhasil, Anda Akan Masuk Ke Mode Non-Terminal 3 Detik Lagi!\n" RESET);
    }else if(n == 6){
        printf(GREEN "SUCCESS: Masukan Berhasil, Anda Akan Keluar Dari Mode Non-Terminal 3 Detik Lagi!\n" RESET);
    }
}

// Prosedur Untuk Menampilkan Query Error atau Error Handling
void ERROR(int n){
    if(nonterm){
        printf(LINE2"//===================================================================================================\\\\\n");
        printf("|+---------------------------------------YOUR QUERY RESULT-------------------------------------------+|\n");
        printf("||                                                                                                   ||\n");
        printf("|+---------------------------------------------------------------------------------------------------+|\n");
        printf("\\\\===================================================================================================//\n");
        printf(RESULT);
    }
    if(n == 1){
        printf(RED "ERROR: QUERY TIDAK DIAKHIRI DENGAN TITIK KOMA (;)!!!!!!\n" RESET);
    }else if(n == 2){
        printf(RED "ERROR: Query Perintah \"%s\" Tidak Dapat Dikenali!\n" RESET, getcw());
    }else if(n == 3){
        printf(RED "ERROR: KAMU MAU %s APASIH, GAK SESUAI FORMAT PENULISANNYA!!!!\n" RESET, getcw());
    }else if(n == 4){
        printf(RED "ERROR: KAMU MAU NGELIAT TABEL APASIH, GAK SESUAI FORMAT PENULISANNYA!!!!\n" RESET);
    }else if(n == 5){
        printf(RED "ERROR: MASUKAN PERINTAH TIDAK SESUAI FORMAT!!!!!\n" RESET);
    }else if(n == 6){
        printf(RED "ERROR: Perintah %s hanya boleh 3 kata!!!!\n" RESET, getcw());
    }else if(n == 7){
        printf(RED "ERROR: Kode primary tidak sesuai format!!!\n" RESET);
    }else if(n == 8){
        printf(RED "ERROR: Kode Primary harus berisi 4 digit!!\n" RESET);
    }else if(n == 9){
        printf(RED "ERROR: Primary key sedang digunakan dalam tabel kasus, TIDAK BISA DIHAPUS!!!\n" RESET);
    }else if(n == 10){
        printf(RED "ERROR: Tidak ada kode primary serupa yang bisa dihapus!!\n" RESET);
    }else if(n == 11){
        printf(RED "ERROR: Tidak ada kode primary serupa yang bisa diupdate!!\n" RESET);
    }else if(n == 12){
        printf(RED "ERROR: KODE PRIMARY SUDAH DIGUNAKAN!!\n" RESET);
    }else if(n == 13){
        printf(RED "ERROR: Tidak bisa melakukan INSERT/ UPDATE/ DELETE pada tabel KasusComplete!!!\n" RESET);
    }else if(n == 14){
        printf(RED "ERROR: Kode primary (Sin/ Hakim/ Gedung) ada yang tidak sesuai format!!!\n" RESET);
    }else if(n == 15){
        printf(RED "ERROR: IdSin tidak ada dalam tabel Sin!\n" RESET);
    }else if(n == 16){
        printf(RED "ERROR: IdHakim tidak ada dalam tabel Hakim!\n" RESET);
    }else if(n == 17){
        printf(RED "ERROR: IdGedung tidak ada dalam tabel Gedung!\n" RESET);
    }else if(n == 18){
        printf(RED "ERROR: IdSin dan IdHakim tidak ada dalam tabelnya!\n" RESET);
    }else if(n == 19){
        printf(RED "ERROR: IdSin dan IdGedung tidak ada dalam tabel!\n" RESET);
    }else if(n == 20){
        printf(RED "ERROR: IdHakim dan IdGedung tidak ada dalam tabelnya!\n" RESET);
    }else if(n == 21){
        printf(RED "ERROR: IdSin, IdHakim, dan IdGedung tidak ada dalam tabelnya!\n" RESET);
    }else if(n == 22){
        printf(RED "ERROR: Data Yang Ingin Dilihat Ada Yang Tidak Dikenali!!\n" RESET);
    }else if(n == 23){
        printf(RED "ERROR: HANYA BOLEH MENAMPILKAN TABEL KASUS/ SIN/ HAKIM/ GEDUNG SATU KALI SAJA!!!\n" RESET);
    }else if(n == 24){
        printf(RED "ERROR: Perintah %s hanya boleh 4 kata!!!!\n" RESET, getcw());
    }else if(n == 25){
        printf(RED "ERROR: Perintah %s hanya boleh 7 kata!!!!\n" RESET, getcw());
    }else if(n == 26){
        printf(RED "ERROR: Perintah %s hanya boleh 5 kata!!!!\n" RESET, getcw());
    }else if(n == 27){
        printf(RED "ERROR: Perintah SHOW %s hanya boleh 2 kata!!!!\n" RESET, getcw());
    }else if(n == 28){
        printf(RED "ERROR: JOIN TABLE HANYA BISA DILAKUKAN PADA TABEL KASUS!!!\n" RESET);
    }else if(n == 29){
        printf(RED "ERROR: Perintah SHOW Kasus hanya boleh 2 kata! Gunakan Perintah Join Jika Ingin Melihat Tabel Join.\n" RESET);
    }else if(n == 30){
        printf(RED "ERROR: PERINTAH JOIN TIDAK LENGKAP!! KAMU MAU JOIN APA??\n" RESET);
    }else if(n == 31){
        printf(RED "ERROR: FORMAT PENULISAN MULTIPLE QUERY ADA YANG TIDAK SESUAI!!!\n" RESET);
    }else if(n == 32){
        printf(RED "ERROR: Perintah HELP \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }else if(n == 33){
        printf(RED "ERROR: Perintah HELP INSERT \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }else if(n == 34){
        printf(RED "ERROR: Perintah HELP UPDATE \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }else if(n == 35){
        printf(RED "ERROR: Perintah HELP DELETE \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }else if(n == 36){
        printf(RED "ERROR: Perintah HELP SHOW \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }else if(n == 37){
        printf(RED "ERROR: Anda Belum Masuk Ke Mode Non-Terminal!!!\n" RESET, getcw());
    }else if(n == 38){
        printf(RED "ERROR: Anda Sedang Berada Di Mode Non-Terminal!!!\n" RESET, getcw());
    }else if(n == 39){
        printf(RED "ERROR: Perintah HELP JOIN \"%s\" Tidak Dikenali!!!\n" RESET, getcw());
    }
}

// Prosedur Untuk Memodifikasi Data Sin
void modify_Sin(char str[], sin *tmp, int *n, data kasus[], int k){
    //memulai mesin kata
    start(str);
    inc(str);
    char mode[51];
    strcpy(mode, getcw());

    start(str);
    if(strcmp(getcw(), "INSERT") == 0 || strcmp(getcw(), "UPDATE") == 0){
        if(countw(str) == 5){
            inc(str);
            inc(str);

            if(mode[0] == getcw()[0] && 
                (getcw()[1] >= '0' && getcw()[1] <= '9') &&
                (getcw()[2] >= '0' && getcw()[2] <= '9') &&
                (getcw()[3] >= '0' && getcw()[3] <= '9')){
                if(strlen(getcw()) == 4){
                    start(str);
                    if(strcmp(getcw(), "INSERT") == 0){
                        inc(str);
                        inc(str);
                        int ada = 0;
                        for(int i = 0; i < *n; i++){//cek apakah primary key nya udah kepake atau belum
                            if(strcmp(tmp[i].kode, getcw()) == 0){
                                ada = 1;
                            }
                        }

                        if(!ada){
                            //kondisi memasukan ke dalam array
                            if(strcmp(getcw(), tmp[0].kode) < 0){//rekaman baru paling depan
                                //geser semua isi array belakang
                                int i;
                                for(i = *n-1; i >= 0; i--){
                                    strcpy(tmp[i+1].kode, tmp[i].kode);
                                    strcpy(tmp[i+1].kejahatan, tmp[i].kejahatan);
                                    strcpy(tmp[i+1].hukuman, tmp[i].hukuman);
                                }
                                (*n)++;
                                strcpy(tmp[0].kode, getcw());
                                inc(str);
                                strcpy(tmp[0].kejahatan, getcw());
                                inc(str);
                                strcpy(tmp[0].hukuman, getcw());
                            }else if(strcmp(getcw(), tmp[*n-1].kode) > 0){//rekaman baru di belakang
                                strcpy(tmp[*n].kode, getcw());
                                inc(str);
                                strcpy(tmp[*n].kejahatan, getcw());
                                inc(str);
                                strcpy(tmp[*n].hukuman, getcw());
                                (*n)++;
                            }else{//rekaman baru memiliki posisi di tengah
                                int i = 0;
                                int stop = 0;
                                //cari posisi
                                while((i < *n) && (stop == 0)){
                                    if(strcmp(tmp[i].kode, getcw()) > 0){
                                        stop = 1;
                                    }else{
                                        i++;
                                    }
                                }

                                int j;
                                for(j = *n-1; j >= i; j--){
                                    strcpy(tmp[j+1].kode, tmp[j].kode);
                                    strcpy(tmp[j+1].kejahatan, tmp[j].kejahatan);
                                    strcpy(tmp[j+1].hukuman, tmp[j].hukuman);
                                }
                                strcpy(tmp[i].kode, getcw());
                                inc(str);
                                strcpy(tmp[i].kejahatan, getcw());
                                inc(str);
                                strcpy(tmp[i].hukuman, getcw());
                                (*n)++;   
                            }
                            SUCCESS(1);
                        }else{
                            ERROR(12);
                        }
                    }else if(strcmp(getcw(), "UPDATE") == 0){
                        inc(str);
                        inc(str);
                        int stop = 0;
                        for(int i = 0; i < *n; i++){
                            if(strcmp(tmp[i].kode, getcw()) == 0){
                                strcpy(tmp[i].kode, getcw());
                                inc(str);
                                strcpy(tmp[i].kejahatan, getcw());
                                inc(str);
                                strcpy(tmp[i].hukuman, getcw());
                                stop = 1;
                            }
                        }

                        if(!stop){
                            ERROR(11);
                        }else{
                            SUCCESS(2);
                        }
                    }
                }else{
                    ERROR(8);
                }
            }else{
                ERROR(7);
            }
        }else{
            ERROR(26);
        }
    }else if(strcmp(getcw(), "DELETE") == 0){
        if(countw(str) == 3){
            inc(str);
            inc(str);

            if(mode[0] == getcw()[0]){
                if(strlen(getcw()) == 4){
                    int i = 0;
                    int adak = 0;
                    if(strcmp(mode, "Sin") == 0){
                        //cari posisi
                        while((i < k) && (adak == 0)){
                            if(strcmp(kasus[i].idSin, getcw()) == 0){
                                adak = 1;
                            }else{
                                i++;
                            }
                        }
                    }

                    if(!adak){
                        int i = 0;
                        int stop = 0;
                        //cari posisi
                        while((i < *n) && (stop == 0)){
                            if(strcmp(tmp[i].kode, getcw())== 0){
                                stop = 1;
                            }else{
                                i++;
                            }
                        }

                        if(stop){
                            int j;
                            for(j = i; j < *n; j++){
                                strcpy(tmp[j].kode, tmp[j+1].kode);
                                strcpy(tmp[j].kejahatan, tmp[j+1].kejahatan);
                                strcpy(tmp[j].hukuman, tmp[j+1].hukuman);
                            }
                            (*n)--;
                            SUCCESS(3);
                        }else{
                            ERROR(10);
                        } 
                    }else{
                        ERROR(9);
                    }
                }else{
                    ERROR(8);
                }
            }else{
                ERROR(7);
            }
        }else{
            ERROR(6);
        }
    }else{
        ERROR(5);
    }

    start(str);
    inc(str);
    write_Sin(*n, tmp, "Sin.txt");
}

// Prosedur Untuk Memodifikasi Data Hakim/ Gedung
void modify_HG(char str[], hg *tmp, int *n, data kasus[], int k){
    //memulai mesin kata
    start(str);
    inc(str);
    char mode[51];
    strcpy(mode, getcw());

    start(str);
    if(strcmp(getcw(), "INSERT") == 0 || strcmp(getcw(), "UPDATE") == 0){
        if(countw(str) == 4){
            inc(str);
            inc(str);

            if(mode[0] == getcw()[0] && 
                (getcw()[1] >= '0' && getcw()[1] <= '9') &&
                (getcw()[2] >= '0' && getcw()[2] <= '9') &&
                (getcw()[3] >= '0' && getcw()[3] <= '9')){
                if(strlen(getcw()) == 4){
                    start(str);
                    if(strcmp(getcw(), "INSERT") == 0){
                        inc(str);
                        inc(str);
                        int ada = 0;
                        for(int i = 0; i < *n; i++){//cek apakah primary key nya udah kepake atau belum
                            if(strcmp(tmp[i].kode, getcw()) == 0){
                                ada = 1;
                            }
                        }

                        if(!ada){
                            //kondisi memasukan ke dalam array
                            if(strcmp(getcw(), tmp[0].kode) < 0){//rekaman baru paling depan
                                //geser semua isi array belakang
                                int i;
                                for(i = *n-1; i >= 0; i--){
                                    strcpy(tmp[i+1].kode, tmp[i].kode);
                                    strcpy(tmp[i+1].nama, tmp[i].nama);
                                }
                                (*n)++;
                                strcpy(tmp[0].kode, getcw());
                                inc(str);
                                strcpy(tmp[0].nama, getcw());
                            }else if(strcmp(getcw(), tmp[*n-1].kode) > 0){//rekaman baru di belakang
                                strcpy(tmp[*n].kode, getcw());
                                inc(str);
                                strcpy(tmp[*n].nama, getcw());
                                (*n)++;
                            }else{//rekaman baru memiliki posisi di tengah
                                int i = 0;
                                int stop = 0;
                                //cari posisi
                                while((i < *n) && (stop == 0)){
                                    if(strcmp(tmp[i].kode, getcw()) > 0){
                                        stop = 1;
                                    }else{
                                        i++;
                                    }
                                }

                                int j;
                                for(j = *n-1; j >= i; j--){
                                    strcpy(tmp[j+1].kode, tmp[j].kode);
                                    strcpy(tmp[j+1].nama, tmp[j].nama);
                                }
                                strcpy(tmp[i].kode, getcw());
                                inc(str);
                                strcpy(tmp[i].nama, getcw());
                                (*n)++;   
                            }
                            SUCCESS(1);
                        }else{
                            ERROR(12);
                        }
                    }else if(strcmp(getcw(), "UPDATE") == 0){
                        inc(str);
                        inc(str);
                        int stop = 0;
                        for(int i = 0; i < *n; i++){
                            if(strcmp(tmp[i].kode, getcw()) == 0){
                                strcpy(tmp[i].kode, getcw());
                                inc(str);
                                strcpy(tmp[i].nama, getcw());
                                stop = 1;
                            }
                        }

                        if(!stop){
                            ERROR(11);
                        }else{
                            SUCCESS(2);
                        }
                    }
                }else{
                    ERROR(8);
                }
            }else{
                ERROR(7);
            }
        }else{
            ERROR(24);
        }
    }else if(strcmp(getcw(), "DELETE") == 0){
        if(countw(str) == 3){
            inc(str);
            inc(str);

            if(mode[0] == getcw()[0]){
                if(strlen(getcw()) == 4){
                    int i = 0;
                    int adak = 0;
                    if(strcmp(mode, "Hakim") == 0){
                        //cari posisi
                        while((i < k) && (adak == 0)){
                            if(strcmp(kasus[i].idHakim, getcw()) == 0){
                                adak = 1;
                            }else{
                                i++;
                            }
                        }
                    }else if(strcmp(mode, "Gedung") == 0){
                        //cari posisi
                        while((i < k) && (adak == 0)){
                            if(strcmp(kasus[i].idGedung, getcw()) == 0){
                                adak = 1;
                            }else{
                                i++;
                            }
                        }
                    }

                    if(!adak){
                        int i = 0;
                        int stop = 0;
                        //cari posisi
                        while((i < *n) && (stop == 0)){
                            if(strcmp(tmp[i].kode, getcw())== 0){
                                stop = 1;
                            }else{
                                i++;
                            }
                        }

                        if(stop){
                            int j;
                            for(j = i; j < *n; j++){
                                strcpy(tmp[j].kode, tmp[j+1].kode);
                                strcpy(tmp[j].nama, tmp[j+1].nama);
                            }
                            (*n)--;
                            SUCCESS(3);
                        }else{
                            ERROR(10);
                        } 
                    }else{
                        ERROR(9);
                    }
                }else{
                    ERROR(8);
                }
            }else{
                ERROR(7);
            }
        }else{
            ERROR(6);
        }
    }else{
        ERROR(5);
    }

    start(str);
    inc(str);
    if(strcmp(getcw(), "Hakim") == 0){
        write_HG(*n, tmp, "Hakim.txt");
    }else if(strcmp(getcw(), "Gedung") == 0){
        write_HG(*n, tmp, "Gedung.txt");
    }
}


// Prosedur Untuk Memodifikasi Data Kasus
void modify_Kasus(char str[], data *kasus, int *k, sin sin[], int s, hg hakim[], int h, hg gedung[], int g){
    //memulai mesin kata
    start(str);
    inc(str);
    char mode[51];
    
    strcpy(mode, getcw());
    if(strcmp(mode, "Kasus") == 0){
        start(str);
        if(strcmp(getcw(), "INSERT") == 0 || strcmp(getcw(), "UPDATE") == 0){
            if(countw(str) == 7){
                inc(str);
                inc(str);
                if(mode[0] == getcw()[0] &&
                    (getcw()[1] >= '0' && getcw()[1] <= '9') &&
                    (getcw()[2] >= '0' && getcw()[2] <= '9') &&
                    (getcw()[3] >= '0' && getcw()[3] <= '9')){
                    if(strlen(getcw()) == 4){
                        inc(str);

                        //maju ke kode sin
                        inc(str);
                        int is = 0;
                        int adas = 0;
                        //cari posisi
                        while((is < s) && (adas == 0)){
                            if(strcmp(sin[is].kode, getcw()) == 0){
                                adas = 1;
                            }else{
                                is++;
                            }
                        }
                        
                        //maju ke kode hakim
                        inc(str);
                        int ih = 0;
                        int adah = 0;
                        //cari posisi
                        while((ih < h) && (adah == 0)){
                            if(strcmp(hakim[ih].kode, getcw()) == 0){
                                adah = 1;
                            }else{
                                ih++;
                            }
                        }
                        
                        //maju ke kode gedung
                        inc(str);
                        int ig = 0;
                        int adag = 0;
                        //cari posisi
                        while((ig < g) && (adag == 0)){
                            if(strcmp(gedung[ig].kode, getcw()) == 0){
                                adag = 1;
                            }else{
                                ig++;
                            }
                        }

                        //mengecek apakah tiap kode primarynya sudah sesuai
                        int sesuai;
                        start(str);
                        inc(str);
                        inc(str);
                        inc(str);
                        inc(str);
                        if(getcw()[0] == 'S'){
                            inc(str);
                            if(getcw()[0] == 'H'){
                                inc(str);
                                if(getcw()[0] == 'G'){
                                    sesuai = 1;
                                }else{
                                    sesuai = 0;
                                }
                            }else{
                                sesuai = 0;
                            }
                        }else{
                            sesuai = 0;
                        }

                        if(sesuai){
                            if(adas == 1 & adah == 1 && adag == 1){
                                start(str);
                                if(strcmp(getcw(), "INSERT") == 0){
                                    inc(str);
                                    inc(str);
                                    int ada = 0;
                                    for(int i = 0; i < *k; i++){//cek apakah primary key nya udah kepake atau belum
                                        if(strcmp(kasus[i].idKasus, getcw()) == 0){
                                            ada = 1;
                                        }
                                    }

                                    if(!ada){
                                        //kondisi memasukan ke dalam array
                                        if(strcmp(getcw(), kasus[0].idKasus) < 0){//rekaman baru paling depan
                                            //geser semua isi array belakang
                                            int i;
                                            for(i = *k-1; i >= 0; i--){
                                                strcpy(kasus[i+1].idKasus, kasus[i].idKasus);
                                                strcpy(kasus[i+1].nama, kasus[i].nama);
                                                strcpy(kasus[i+1].idSin, kasus[i].idSin);
                                                strcpy(kasus[i+1].idHakim, kasus[i].idHakim);
                                                strcpy(kasus[i+1].idGedung, kasus[i].idGedung);
                                            }
                                            (*k)++;
                                            strcpy(kasus[0].idKasus, getcw());
                                            inc(str);
                                            strcpy(kasus[0].nama, getcw());
                                            inc(str);
                                            strcpy(kasus[0].idSin, getcw());
                                            inc(str);
                                            strcpy(kasus[0].idHakim, getcw());
                                            inc(str);
                                            strcpy(kasus[0].idGedung, getcw());
                                        }else if(strcmp(getcw(), kasus[*k-1].idKasus) > 0){//rekaman baru di belakang
                                            strcpy(kasus[*k].idKasus, getcw());
                                            inc(str);
                                            strcpy(kasus[*k].nama, getcw());
                                            inc(str);
                                            strcpy(kasus[*k].idSin, getcw());
                                            inc(str);
                                            strcpy(kasus[*k].idHakim, getcw());
                                            inc(str);
                                            strcpy(kasus[*k].idGedung, getcw());
                                            (*k)++;
                                        }else{//rekaman baru memiliki posisi di tengah
                                            int i = 0;
                                            int stop = 0;
                                            //cari posisi
                                            while((i < *k) && (stop == 0)){
                                                if(strcmp(kasus[i].idKasus, getcw()) > 0){
                                                    stop = 1;
                                                }else{
                                                    i++;
                                                }
                                            }

                                            int j;
                                            for(j = *k-1; j >= i; j--){
                                                strcpy(kasus[j+1].idKasus, kasus[j].idKasus);
                                                strcpy(kasus[j+1].nama, kasus[j].nama);
                                                strcpy(kasus[j+1].idSin, kasus[j].idSin);
                                                strcpy(kasus[j+1].idHakim, kasus[j].idHakim);
                                                strcpy(kasus[j+1].idGedung, kasus[j].idGedung);
                                            }
                                            strcpy(kasus[i].idKasus, getcw());
                                            inc(str);
                                            strcpy(kasus[i].nama, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idSin, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idHakim, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idGedung, getcw());
                                            (*k)++;   
                                        }
                                        SUCCESS(1);
                                    }else{
                                        ERROR(12);
                                    }
                                }else if(strcmp(getcw(), "UPDATE") == 0){
                                    inc(str);
                                    inc(str);
                                    int stop = 0;
                                    for(int i = 0; i < *k; i++){
                                        if(strcmp(kasus[i].idKasus, getcw()) == 0){
                                            strcpy(kasus[i].idKasus, getcw());
                                            inc(str);
                                            strcpy(kasus[i].nama, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idSin, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idHakim, getcw());
                                            inc(str);
                                            strcpy(kasus[i].idGedung, getcw());
                                            stop = 1;
                                        }
                                    }
                                    if(!stop){
                                        ERROR(11);
                                    }else{
                                        SUCCESS(2);
                                    }
                                }
                            }else if(adas == 0 && adah == 1 && adag == 1){
                                ERROR(15);
                            }else if(adas == 1 && adah == 0 && adag == 1){
                                ERROR(16);
                            }else if(adas == 1 && adah == 1 && adag == 0){
                                ERROR(17);
                            }else if(adas == 0 && adah == 0 && adag == 1){
                                ERROR(18);
                            }else if(adas == 0 && adah == 1 && adag == 0){
                                ERROR(19);
                            }else if(adas == 1 && adah == 0 && adag == 0){
                                ERROR(20);
                            }else if(adas == 0 && adah == 0 && adag == 0){
                                ERROR(21);
                            }
                        }else{
                            ERROR(14);
                        }
                    }else{
                        ERROR(8);
                    }
                }else{
                    ERROR(7);
                }
            }else{
                ERROR(25);
            }
        }else if(strcmp(getcw(), "DELETE") == 0){
            if(countw(str) == 3){
                inc(str);
                inc(str);
                if(mode[0] == getcw()[0]){
                    if(strlen(getcw()) == 4){
                        int i = 0;
                        int stop = 0;
                        //cari posisi
                        while((i < *k) && (stop == 0)){
                            if(strcmp(kasus[i].idKasus, getcw())== 0){
                                stop = 1;
                            }else{
                                i++;
                            }
                        }

                        if(stop){
                            int j;
                            for(j = i; j < *k; j++){
                                strcpy(kasus[j].idKasus, kasus[j+1].idKasus);
                                strcpy(kasus[j].nama, kasus[j+1].nama);
                                strcpy(kasus[j].idSin, kasus[j+1].idSin);
                                strcpy(kasus[j].idHakim, kasus[j+1].idHakim);
                                strcpy(kasus[j].idGedung, kasus[j+1].idGedung);
                            }
                            (*k)--;
                            SUCCESS(3);
                        }else{
                            ERROR(10);
                        }
                    }else{
                        ERROR(8);
                    }
                }else{
                    ERROR(7);
                }
            }else{
                ERROR(6);
            }
        }else{
            ERROR(5);
        }
        write_IdKasus(*k, kasus, "Kasus.txt");
    }else if(strcmp(mode, "KasusComplete") == 0){
        ERROR(13);
    }
}

// Prosedur Untuk Menjoinkan Data Sin, Hakim, dan Gedung Ke dalam data Kasus
void join(int k, data kasus[], int s, sin sin[], int h, hg hakim[], int g, hg gedung[]){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < s; j++){
            if(strcmp(kasus[i].idSin, sin[j].kode) == 0){
                strcpy(kasus[i].kejahatan, sin[j].kejahatan);
                strcpy(kasus[i].hukuman, sin[j].hukuman);
            }
        }

        for(int j = 0; j < h; j++){
            if(strcmp(kasus[i].idHakim, hakim[j].kode) == 0){
                strcpy(kasus[i].hakim, hakim[j].nama);
            }
        }
        
        for(int j = 0; j < g; j++){
            if(strcmp(kasus[i].idGedung, gedung[j].kode) == 0){
                strcpy(kasus[i].gedung, gedung[j].nama);
            }
        }
    }
}

// Fungsi Untuk Mengubah String Angka Menjadi Integer
int str_to_int(char str[]){
    int n;
    for(int i = 0; i < str[i] != '\0'; i++){
        n = n * 10 + (str[i] - '0');
    }

    return n;
}

// Fungsi Untuk Menghitung Jumlah Digit Pada Suatu Integer
int intlen(int n){//membuat fungsi untuk menghitung jumlah digit
    int count = 0;//count dimulai dari 0
    if(n == 0){//jika angka nya 0 
        count = 1;//maka dihitung sebanyak 1 digit
    }else{//jika lebih dari 0
        while (n != 0){//loop while selama angkanya tidak 0
            n /= 10;//angka dibagi 10
            count++;//setiap dibagi 10, count bertambah 1
        }
    }

    return count;//mengembalikan nilai count
}

// Prosedur Untuk Melakukan Flush Pada Tabel Yang Sudah Ditampilkan (Untuk Mode Non-Terminal)
void clear(){
    printf(TABEL"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
    printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          \n");
}

// Prosedur Untuk Menampilkan Tabel Dinamis Untuk Data Sin
void tabel_Sin(char pita[], int n, sin *str){
    if(countw(pita) == 2){
        start(tape);
        if(!((strcmp(getcw(), "SHOW") != 0) && (strcmp(getcw(), "JOIN") != 0) && nonterm)){
            SUCCESS(4);
        }
        /*mendeklarasikan variabel untuk menampung nilai
        i = counting untuk loop for
        j = counting untuk loop for di dalam loop for
        count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
        int i, j;
        int count = 0;
        tabel max;
        tabel space;
        char mode[51];

        start(pita);
        inc(pita);

        strcpy(mode, getcw());

        for(i = 0; i < strlen(mode); i++){
            if(mode[i] >= 'a' && mode[i] <= 'z'){
                mode[i] -= 32;
            }
        }

        if(nonterm){
            clear();
            printf(TABEL"\n<<< TABEL %s >>>\n", mode);
        }else{
            printf("\n<<< TABEL %s >>>\n", mode);
        }
        
        //memprint baris atas
        printf("+----+------+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string kejahatan yang ada dalam bungkusan
        space.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string kejahatan yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen kejahatan yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");
        
        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string hukuman yang ada dalam bungkusan
        space.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string hukuman yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen hukuman yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+\n");
        
        //memprint bagian judul
        printf("| No | Kode | Kejahatan");
        
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen kejahatan yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }
        space.kejahatan = max.kejahatan - 9;//spasi didapatkan dari panjang maksimal dikurang 9
        if(space.kejahatan < 1) space.kejahatan = 0;//jika spasinya negatif, maka spasinya 0
        for(i = 0; i < space.kejahatan; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        
        printf(" | Hukuman");
        
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen hukuman yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }
        space.hukuman = max.hukuman - 7;//spasi didapatkan dari panjang maksimal dikurang 7
        if( space.hukuman < 1)  space.hukuman = 0;//jika spasinya negatif, maka spasinya 0
        for(i = 0; i <  space.hukuman; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" |\n");


        //memprint bagian bawah judul
        printf("+----+------+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string kejahatan yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen kejahatan yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");
        
        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string hukuman yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen hukuman yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+\n");

        //print isi tabel
        for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
            //memprint no rank leaderboard
            if(i > 8){//jika no nya lebih dari 1 digit
                printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
            }else{//jika hanya 1 digit
                printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
            }
            printf("%s | %s", str[i].kode, str[i].kejahatan);


            if(max.kejahatan > 9){//jika panjang maksimal stringnya lebih dari 9, maka;
                space.kejahatan = max.kejahatan - strlen(str[i].kejahatan);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.kejahatan < 1) space.kejahatan = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j < space.kejahatan; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 9, maka;
                space.kejahatan = 9 - strlen(str[i].kejahatan);//spasi didapatkan dari 9 dikurang panjang string indeks i
                if(space.kejahatan < 1) space.kejahatan = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j < space.kejahatan; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            printf(" | %s", str[i].hukuman);


            if(max.hukuman > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                space.hukuman =  max.hukuman - strlen(str[i].hukuman);//spasi didapatkan dari max string dikurangi string indeks i
                if( space.hukuman < 1)  space.hukuman = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j <  space.hukuman; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                space.hukuman = 7 - strlen(str[i].hukuman);//spasi didapatkan dari 7 dikurang panjang string indeks i
                if( space.hukuman < 1)  space.hukuman = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j <  space.hukuman; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            printf(" |\n");
        }


        //memprint bagian bawah tabel
        printf("+----+------+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string kejahatan yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen kejahatan yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");
        
        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string hukuman yang ada dalam bungkusan
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen hukuman yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+\n");
    }else{
        ERROR(27);
    }

}

// Prosedur Untuk Menampilkan Tabel Dinamis Untuk Data Hakim/ Gedung
void tabel_HG(char pita[], int n, hg *str){
    if(countw(pita) == 2){
        start(tape);
        if(!((strcmp(getcw(), "SHOW") != 0) && (strcmp(getcw(), "JOIN") != 0) && nonterm)){
            SUCCESS(4);
        }
        /*mendeklarasikan variabel untuk menampung nilai
        i = counting untuk loop for
        j = counting untuk loop for di dalam loop for
        count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
        int i, j;
        int count = 0;
        int max;
        int space;
        char mode[51];

        start(pita);
        inc(pita);

        strcpy(mode, getcw());

        for(i = 0; i < strlen(mode); i++){
            if(mode[i] >= 'a' && mode[i] <= 'z'){
                mode[i] -= 32;
            }
        }
        if(nonterm){
            clear();
            printf(TABEL"\n<<< TABEL %s >>>\n", mode);
        }else{
            printf("\n<<< TABEL %s >>>\n", mode);
        }
        
        //memprint baris atas
        printf("+----+------+-");
        
        max = 0;//membuat variabel untuk menampung panjang maksimal dari string nama yang ada dalam bungkusan
        space = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max < strlen(str[i].nama)){//jika ada strlen nama yang lebih panjang
                max = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+\n");
        
        //memprint bagian judul
        printf("| No | Kode | Nama");
        space = max - 4;//spasi didapatkan dari panjang maksimal dikurang 4
        if(space < 1) space = 0;//jika spasinya negatif, maka spasinya 0
        for(i = 0; i < space; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" |\n");


        //memprint bagian bawah judul
        printf("+----+------+-");
        max = 0;//membuat variabel untuk menampung panjang maksimal dari string nama yang ada dalam bungkusan
        space = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max < strlen(str[i].nama)){//jika ada strlen nama yang lebih panjang
                max = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+\n");

        //print isi tabel
        for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
            //memprint no rank leaderboard
            if(i > 8){//jika no nya lebih dari 1 digit
                printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
            }else{//jika hanya 1 digit
                printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
            }
            printf("%s | %s", str[i].kode, str[i].nama);


            if(max > 4){//jika panjang maksimal stringnya lebih dari 4, maka;
                space = max - strlen(str[i].nama);//spasi didapatkan dari max string dikurangi string indeks i
                if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j < space; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 4, maka;
                space = 4 - strlen(str[i].nama);//spasi didapatkan dari 4 dikurang panjang string indeks i
                if(space < 1) space = 0;//jika spasinya negatif maka spasinya 0
                for(j = 0; j < space; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            printf(" |\n");
        }


        //memprint bagian bawah tabel
        printf("+----+------+-");
        max = 0;//membuat variabel untuk menampung panjang maksimal dari string nama yang ada dalam bungkusan
        space = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max < strlen(str[i].nama)){//jika ada strlen nama yang lebih panjang
                max = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+\n");
    }else{
        ERROR(27);
    }

}

// Prosedur Untuk Menampilkan Tabel Dinamis Untuk Data Kasus
void tabel_Kasus(char pita[], int k, data kasus[], int s, sin sin[], int h, hg idHakim[], int g, hg idGedung[]){
    int sesuai = 1;
    int beda = 1;

    start(pita);
    inc(pita);
    if(!lastw(pita)){
        char tmp[51];
        char tmp1[51];
        char tmp2[51];
        strcpy(tmp, getcw());
        
        inc(pita);
        while(!lastw(pita) && beda == 1){
            if(strcmp(getcw(), tmp) == 0 || strcmp(getcw(), tmp1) == 0 || strcmp(getcw(), tmp2) == 0){
                beda = 0;
            }
            if(strcmp(getcw(), "Sin") != 0 && strcmp(getcw(), "Hakim") != 0 &&
                strcmp(getcw(), "Gedung") != 0){
                sesuai = 0;
            }
            if(wordnow(pita) == 3){
                strcpy(tmp, getcw());
            }else if(wordnow(pita) == 4){
                strcpy(tmp1, getcw());
            }else if(wordnow(pita) == 5){
                strcpy(tmp2, getcw());
            }
            inc(pita);
        }
        if(strcmp(getcw(), tmp) == 0 || strcmp(getcw(), tmp1) == 0 || strcmp(getcw(), tmp2) == 0){
            beda = 0;
        }
        if(strcmp(getcw(), "Sin") != 0 && strcmp(getcw(), "Hakim") != 0 && strcmp(getcw(), "Gedung") != 0){
            sesuai = 0;
        }
    }

    if(beda){
        if(sesuai){
            start(tape);
            if(!((strcmp(getcw(), "SHOW") != 0) && (strcmp(getcw(), "JOIN") != 0) && nonterm)){
                SUCCESS(4);
            }
            tabel max;
            tabel space;
            
            start(pita);
            inc(pita);
            //MEMPRINT HEADER TABLE
            if(nonterm){
                clear();
                printf(TABEL"\n<<< TABEL ");
            }else{
                printf("\n<<< TABEL ");
            }
            char mode1[51];
            while(!lastw(pita)){
                int j = 0;
                for(int i = 0; i < getlen(); i++){
                    if((getcw()[i] >= 'A' && getcw()[i] <= 'Z') && i != 0 && (getcw()[i-1] >= 'a' && getcw()[i-1] <= 'z')){
                        mode1[j++] = ' ';

                    }
                    mode1[j++] = getcw()[i];
                }
                mode1[j] = '\0';

                for(int i = 0; i < strlen(mode1); i++){
                    if(mode1[i] >= 'a' && mode1[i] <= 'z'){
                        mode1[i] -= 32;
                    }
                }
                printf("%s ", mode1);
                inc(pita);
            }
            int j = 0;
            for(int i = 0; i < getlen(); i++){
                if((getcw()[i] >= 'A' && getcw()[i] <= 'Z') && i != 0 && (getcw()[i-1] >= 'a' && getcw()[i-1] <= 'z')){
                    mode1[j++] = ' ';

                }
                mode1[j++] = getcw()[i];
            }
            mode1[j] = '\0';

            for(int i = 0; i < strlen(mode1); i++){
                if(mode1[i] >= 'a' && mode1[i] <= 'z'){
                    mode1[i] -= 32;
                }
            }
            printf("%s ", mode1);    
            printf(">>>\n");
            
                    
            //memprint baris atas
            start(pita);
            inc(pita);
            printf("+----+------+-");
            
            max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
            space.nama = 0;//membuat variabel untuk menampung jumlah spasi
            for(int i = 0; i < k; i++){
                if(max.nama < strlen(kasus[i].nama)){//jika ada strlen jenis yang lebih panjang
                    max.nama = strlen(kasus[i].nama);//maka update nilai max nya
                }
            }

            if(max.nama > 4){//jika maksimalnya lebih dari 4
                for(int i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                    printf("-");
                }
                
            }else{//jika kurang atau sama dengan 4
                for(int i = 0; i < 4; i++){
                    printf("-");//maka print '-' sebanyak 4 kali
                }
            }
            printf("-+-");

            if(lastw(pita)){
                max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                        max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                    }
                }

                if(max.idSin > 5){//jika maksimalnya lebih dari 5
                    for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 5
                    for(int i = 0; i < 5; i++){
                        printf("-");//maka print '-' sebanyak 5 kali
                    }
                }
                printf("-+-");
                
                max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                        max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                    }
                }

                if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                    for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 7
                    for(int i = 0; i < 7; i++){
                        printf("-");//maka print '-' sebanyak 7 kali
                    }
                }
                printf("-+-");
                
                max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                        max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                    }
                }

                if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                    for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 8
                    for(int i = 0; i < 8; i++){
                        printf("-");//maka print '-' sebanyak 8 kali
                    }
                }
                printf("-+\n");
            }else{
                inc(pita);
                while(!lastw(pita)){
                    if(strcmp(getcw(), "Sin") == 0){
                        //print strip id sin
                        max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                                max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                            }
                        }

                        if(max.idSin > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");

                        //print strip kejahatan
                        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                                max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                            }
                        }
                        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                            for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 9
                            for(int i = 0; i < 9; i++){
                                printf("-");//maka print '-' sebanyak 9 kali
                            }
                        }
                        printf("-+-");
                        
                        //printf strip hukuman
                        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                                max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                            }
                        }

                        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Hakim") == 0){
                        //print strip id hakim
                        max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                                max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                            }
                        }

                        if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");

                        //print strip hakim
                        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                                max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                            }
                        }

                        if(max.hakim > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Gedung") == 0){
                        max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                                max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                            }
                        }

                        if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                            for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 8
                            for(int i = 0; i < 8; i++){
                                printf("-");//maka print '-' sebanyak 8 kali
                            }
                        }
                        printf("-+-");
                        
                        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                                max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                            }
                        }

                        if(max.gedung > 6){//jika maksimalnya lebih dari 6
                            for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 6
                            for(int i = 0; i < 6; i++){
                                printf("-");//maka print '-' sebanyak 6 kali
                            }
                        }
                        printf("-+-");
                    }
                    inc(pita);
                }
                
                if(strcmp(getcw(), "Sin") == 0){
                    //print strip id sin
                    max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                            max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                        }
                    }

                    if(max.idSin > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+-");

                    //print strip kejahatan
                    max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                            max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                        }
                    }

                    if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                        for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 9
                        for(int i = 0; i < 9; i++){
                            printf("-");//maka print '-' sebanyak 9 kali
                        }
                    }
                    printf("-+-");
                    
                    //printf strip hukuman
                    max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                            max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                        }
                    }

                    if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Hakim") == 0){
                    //print strip id hakim
                    max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                            max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                        }
                    }

                    if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+-");

                    //print strip hakim
                    max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                            max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                        }
                    }

                    if(max.hakim > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Gedung") == 0){
                    //print strip idgedung
                    max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                            max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                        }
                    }

                    if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                        for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 8
                        for(int i = 0; i < 8; i++){
                            printf("-");//maka print '-' sebanyak 8 kali
                        }
                    }
                    printf("-+-");
                    
                    //print strip gedung
                    max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                            max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                        }
                    }

                    if(max.gedung > 6){//jika maksimalnya lebih dari 6
                        for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 6
                        for(int i = 0; i < 6; i++){
                            printf("-");//maka print '-' sebanyak 6 kali
                        }
                    }
                    printf("-+\n");
                }
            }

                    
            //memprint bagian judul
            start(pita);
            inc(pita);
            printf("| No | Kode | Nama");
            space.nama = max.nama - 4;//spasi didapatkan dari panjang maksimal dikurang 12
            if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
            for(int i = 0; i < space.nama; i++){
                printf(" ");//print ' ' sebanyak jumlah spasi
            }
            printf(" | ");
                
            if(lastw(pita)){
                printf("IdSin");
                space.idSin = max.idSin - 5;//spasi didapatkan dari panjang maksimal dikurang 5
                if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                for(int i = 0; i < space.idSin; i++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
                printf(" | ");
                
                printf("IdHakim");
                space.idHakim = max.idHakim - 7;//spasi didapatkan dari panjang maksimal dikurang 7
                if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                for(int i = 0; i < space.idHakim; i++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
                printf(" | ");
                
                printf("IdGedung");
                space.idGedung = max.idGedung - 8;//spasi didapatkan dari panjang maksimal dikurang 8
                if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                for(int i = 0; i < space.idGedung; i++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
                printf(" |\n");
            }else{
                inc(pita);
                while(!lastw(pita)){
                    if(strcmp(getcw(), "Sin") == 0){
                        printf("IdSin");
                        space.idSin = max.idSin - 5;//spasi didapatkan dari panjang maksimal dikurang 5
                        if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.idSin; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");

                        printf("Kejahatan");
                        space.kejahatan = max.kejahatan - 9;//spasi didapatkan dari panjang maksimal dikurang 9
                        if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.kejahatan; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");

                        printf("Hukuman");
                        space.hukuman = max.hukuman - 7;//spasi didapatkan dari panjang maksimal dikurang 7
                        if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.hukuman; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");
                    }else if(strcmp(getcw(), "Hakim") == 0){
                        printf("IdHakim");
                        space.idHakim = max.idHakim - 7;//spasi didapatkan dari panjang maksimal dikurang 7
                        if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.idHakim; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");
                        
                        printf("Hakim");
                        space.hakim = max.hakim - 5;//spasi didapatkan dari panjang maksimal dikurang 5
                        if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.hakim; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");
                    }else if(strcmp(getcw(), "Gedung") == 0){
                        printf("IdGedung");
                        space.idGedung = max.idGedung - 8;//spasi didapatkan dari panjang maksimal dikurang 8
                        if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.idGedung; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");
                
                        printf("Gedung");
                        space.gedung = max.gedung - 6;//spasi didapatkan dari panjang maksimal dikurang 6
                        if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                        for(int i = 0; i < space.gedung; i++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                        printf(" | ");
                    }
                    inc(pita);
                }
                if(strcmp(getcw(), "Sin") == 0){
                    printf("IdSin");
                    space.idSin = max.idSin - 5;//spasi didapatkan dari panjang maksimal dikurang 5
                    if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.idSin; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" | ");

                    printf("Kejahatan");
                    space.kejahatan = max.kejahatan - 9;//spasi didapatkan dari panjang maksimal dikurang 9
                    if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.kejahatan; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" | ");

                    printf("Hukuman");
                    space.hukuman = max.hukuman - 7;//spasi didapatkan dari panjang maksimal dikurang 7
                    if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.hukuman; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" |\n");
                }else if(strcmp(getcw(), "Hakim") == 0){
                    printf("IdHakim");
                    space.idHakim = max.idHakim - 7;//spasi didapatkan dari panjang maksimal dikurang 7
                    if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.idHakim; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" | ");
                    
                    printf("Hakim");
                    space.hakim = max.hakim - 5;//spasi didapatkan dari panjang maksimal dikurang 5
                    if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.hakim; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" |\n");
                }else if(strcmp(getcw(), "Gedung") == 0){
                    printf("IdGedung");
                    space.idGedung = max.idGedung - 8;//spasi didapatkan dari panjang maksimal dikurang 8
                    if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.idGedung; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" | ");
            
                    printf("Gedung");
                    space.gedung = max.gedung - 6;//spasi didapatkan dari panjang maksimal dikurang 6
                    if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
                    for(int i = 0; i < space.gedung; i++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                    printf(" |\n");
                }
            }


            //memprint bagian bawah judul
            start(pita);
            inc(pita);
            printf("+----+------+-");
            
            max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
            space.nama = 0;//membuat variabel untuk menampung jumlah spasi
            for(int i = 0; i < k; i++){
                if(max.nama < strlen(kasus[i].nama)){//jika ada strlen jenis yang lebih panjang
                    max.nama = strlen(kasus[i].nama);//maka update nilai max nya
                }
            }

            if(max.nama > 4){//jika maksimalnya lebih dari 4
                for(int i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                    printf("-");
                }
                
            }else{//jika kurang atau sama dengan 4
                for(int i = 0; i < 4; i++){
                    printf("-");//maka print '-' sebanyak 4 kali
                }
            }
            printf("-+-");

            if(lastw(pita)){
                max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                        max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                    }
                }

                if(max.idSin > 5){//jika maksimalnya lebih dari 5
                    for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 5
                    for(int i = 0; i < 5; i++){
                        printf("-");//maka print '-' sebanyak 5 kali
                    }
                }
                printf("-+-");
                
                max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                        max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                    }
                }

                if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                    for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 7
                    for(int i = 0; i < 7; i++){
                        printf("-");//maka print '-' sebanyak 7 kali
                    }
                }
                printf("-+-");
                
                max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                        max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                    }
                }

                if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                    for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 8
                    for(int i = 0; i < 8; i++){
                        printf("-");//maka print '-' sebanyak 8 kali
                    }
                }
                printf("-+\n");
            }else{
                inc(pita);
                while(!lastw(pita)){
                    if(strcmp(getcw(), "Sin") == 0){
                        //print strip id sin
                        max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                                max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                            }
                        }

                        if(max.idSin > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");

                        //print strip kejahatan
                        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                                max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                            }
                        }
                        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                            for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 9
                            for(int i = 0; i < 9; i++){
                                printf("-");//maka print '-' sebanyak 9 kali
                            }
                        }
                        printf("-+-");
                        
                        //printf strip hukuman
                        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                                max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                            }
                        }

                        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Hakim") == 0){
                        //print strip id hakim
                        max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                                max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                            }
                        }

                        if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");

                        //print strip hakim
                        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                                max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                            }
                        }

                        if(max.hakim > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Gedung") == 0){
                        max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                                max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                            }
                        }

                        if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                            for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 8
                            for(int i = 0; i < 8; i++){
                                printf("-");//maka print '-' sebanyak 8 kali
                            }
                        }
                        printf("-+-");
                        
                        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                                max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                            }
                        }

                        if(max.gedung > 6){//jika maksimalnya lebih dari 6
                            for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 6
                            for(int i = 0; i < 6; i++){
                                printf("-");//maka print '-' sebanyak 6 kali
                            }
                        }
                        printf("-+-");
                    }
                    inc(pita);
                }
                
                if(strcmp(getcw(), "Sin") == 0){
                    //print strip id sin
                    max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                            max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                        }
                    }

                    if(max.idSin > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+-");

                    //print strip kejahatan
                    max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                            max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                        }
                    }

                    if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                        for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 9
                        for(int i = 0; i < 9; i++){
                            printf("-");//maka print '-' sebanyak 9 kali
                        }
                    }
                    printf("-+-");
                    
                    //printf strip hukuman
                    max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                            max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                        }
                    }

                    if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Hakim") == 0){
                    //print strip id hakim
                    max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                            max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                        }
                    }

                    if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+-");

                    //print strip hakim
                    max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                            max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                        }
                    }

                    if(max.hakim > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Gedung") == 0){
                    //print strip idgedung
                    max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                            max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                        }
                    }

                    if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                        for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 8
                        for(int i = 0; i < 8; i++){
                            printf("-");//maka print '-' sebanyak 8 kali
                        }
                    }
                    printf("-+-");
                    
                    //print strip gedung
                    max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                            max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                        }
                    }

                    if(max.gedung > 6){//jika maksimalnya lebih dari 6
                        for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 6
                        for(int i = 0; i < 6; i++){
                            printf("-");//maka print '-' sebanyak 6 kali
                        }
                    }
                    printf("-+\n");
                }
            }

            //PRINT ISI TABEL
            for(int i = 0; i < k; i++){//melakukan loop sebanyak jumlah array nya
                start(pita);
                inc(pita);
                //print no, primary, dan nama
                if(i > 8){//jika no nya lebih dari 1 digit
                    printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
                }else{//jika hanya 1 digit
                    printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
                }
                printf("%s | %s", kasus[i].idKasus, kasus[i].nama);
                if(max.nama > 4){//jika panjang maksimal stringnya lebih dari 4, maka;
                    space.nama = max.nama - strlen(kasus[i].nama);//spasi didapatkan dari max string dikurangi string indeks i
                    if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                    for(j = 0; j < space.nama; j++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                }else{//jika panjang maksimal stringnya kurang / sama dengan 4, maka;
                    space.nama = 4 - strlen(kasus[i].nama);//spasi didapatkan dari 12 dikurang panjang string indeks i
                    if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                    for(j = 0; j < space.nama; j++){
                        printf(" ");//print ' ' sebanyak jumlah spasi
                    }
                }
                
                if(lastw(pita)){
                    //print idSin
                    printf(" | %s", kasus[i].idSin);
                    if(max.idSin > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                        space.idSin = max.idSin - strlen(kasus[i].idSin);//spasi didapatkan dari max string dikurangi string indeks i
                        if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idSin; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                        space.idSin = 5 - strlen(kasus[i].idSin);//spasi didapatkan dari 5 dikurang panjang string indeks i
                        if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idSin; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }

                    //print idHakim
                    printf(" | %s", kasus[i].idHakim);
                    if(max.idHakim > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                        space.idHakim = max.idHakim - strlen(kasus[i].idHakim);//spasi didapatkan dari max string dikurangi string indeks i
                        if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idHakim; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                        space.idHakim = 7 - strlen(kasus[i].idHakim);//spasi didapatkan dari 7 dikurang panjang string indeks i
                        if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idHakim; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }

                    //print idGedung
                    printf(" | %s", kasus[i].idGedung);
                    if(max.idGedung > 8){//jika panjang maksimal stringnya lebih dari 8, maka;
                        space.idGedung = max.idGedung - strlen(kasus[i].idGedung);//spasi didapatkan dari max string dikurangi string indeks i
                        if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idGedung; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }else{//jika panjang maksimal stringnya kurang / sama dengan 8, maka;
                        space.idGedung = 8 - strlen(kasus[i].idGedung);//spasi didapatkan dari 8 dikurang panjang string indeks i
                        if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                        for(j = 0; j < space.idGedung; j++){
                            printf(" ");//print ' ' sebanyak jumlah spasi
                        }
                    }
                    
                    printf(" |\n");
                }else{
                    inc(pita);
                    // printf("|%d|\n", lastw(pita));
                    while(!lastw(pita)){
                        if(strcmp(getcw(), "Sin") == 0){
                            //print idSin
                            printf(" | %s", kasus[i].idSin);
                            if(max.idSin > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                                space.idSin = max.idSin - strlen(kasus[i].idSin);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idSin; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                                space.idSin = 5 - strlen(kasus[i].idSin);//spasi didapatkan dari 5 dikurang panjang string indeks i
                                if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idSin; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }

                            //print kejahatan
                            printf(" | %s", kasus[i].kejahatan);
                            if(max.kejahatan > 9){//jika panjang maksimal stringnya lebih dari 9, maka;
                                space.kejahatan = max.kejahatan - strlen(kasus[i].kejahatan);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.kejahatan; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 9, maka;
                                space.kejahatan = 9 - strlen(kasus[i].kejahatan);//spasi didapatkan dari 9 dikurang panjang string indeks i
                                if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.kejahatan; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }

                            //print hukuman
                            printf(" | %s", kasus[i].hukuman);
                            if(max.hukuman > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                                space.hukuman = max.hukuman - strlen(kasus[i].hukuman);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.hukuman; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                                space.hukuman = 7 - strlen(kasus[i].hukuman);//spasi didapatkan dari 7 dikurang panjang string indeks i
                                if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.hukuman; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }
                        }else if(strcmp(getcw(), "Hakim") == 0){
                            //print idHakim
                            printf(" | %s", kasus[i].idHakim);
                            if(max.idHakim > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                                space.idHakim = max.idHakim - strlen(kasus[i].idHakim);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idHakim; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                                space.idHakim = 7 - strlen(kasus[i].idHakim);//spasi didapatkan dari 7 dikurang panjang string indeks i
                                if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idHakim; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }
            
                            //print hakim
                            printf(" | %s", kasus[i].hakim);
                            if(max.hakim > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                                space.hakim = max.hakim - strlen(kasus[i].hakim);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.hakim; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                                space.hakim = 5 - strlen(kasus[i].hakim);//spasi didapatkan dari 5 dikurang panjang string indeks i
                                if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.hakim; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }

                        }else if(strcmp(getcw(), "Gedung") == 0){
                            //print idGedung
                            printf(" | %s", kasus[i].idGedung);
                            if(max.idGedung > 8){//jika panjang maksimal stringnya lebih dari 8, maka;
                                space.idGedung = max.idGedung - strlen(kasus[i].idGedung);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idGedung; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 8, maka;
                                space.idGedung = 8 - strlen(kasus[i].idGedung);//spasi didapatkan dari 8 dikurang panjang string indeks i
                                if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.idGedung; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }
                            
            
                            //print gedung
                            printf(" | %s", kasus[i].gedung);
                            if(max.gedung > 6){//jika panjang maksimal stringnya lebih dari 6, maka;
                                space.gedung = max.gedung - strlen(kasus[i].gedung);//spasi didapatkan dari max string dikurangi string indeks i
                                if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.gedung; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }else{//jika panjang maksimal stringnya kurang / sama dengan 6, maka;
                                space.gedung = 6 - strlen(kasus[i].gedung);//spasi didapatkan dari 6 dikurang panjang string indeks i
                                if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                                for(j = 0; j < space.gedung; j++){
                                    printf(" ");//print ' ' sebanyak jumlah spasi
                                }
                            }
                            
                        }

                        inc(pita);
                    }
                    if(strcmp(getcw(), "Sin") == 0){
                        //print idSin
                        printf(" | %s", kasus[i].idSin);
                        if(max.idSin > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                            space.idSin = max.idSin - strlen(kasus[i].idSin);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idSin; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                            space.idSin = 5 - strlen(kasus[i].idSin);//spasi didapatkan dari 5 dikurang panjang string indeks i
                            if(space.idSin < 1) space.idSin = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idSin; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }

                        //print kejahatan
                        printf(" | %s", kasus[i].kejahatan);
                        if(max.kejahatan > 9){//jika panjang maksimal stringnya lebih dari 9, maka;
                            space.kejahatan = max.kejahatan - strlen(kasus[i].kejahatan);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.kejahatan; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 9, maka;
                            space.kejahatan = 9 - strlen(kasus[i].kejahatan);//spasi didapatkan dari 9 dikurang panjang string indeks i
                            if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.kejahatan; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }

                        //print hukuman
                        printf(" | %s", kasus[i].hukuman);
                        if(max.hukuman > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                            space.hukuman = max.hukuman - strlen(kasus[i].hukuman);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.hukuman; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                            space.hukuman = 7 - strlen(kasus[i].hukuman);//spasi didapatkan dari 7 dikurang panjang string indeks i
                            if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.hukuman; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }
                        printf(" |\n");
                    }else if(strcmp(getcw(), "Hakim") == 0){
                        //print idHakim
                        printf(" | %s", kasus[i].idHakim);
                        if(max.idHakim > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                            space.idHakim = max.idHakim - strlen(kasus[i].idHakim);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idHakim; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                            space.idHakim = 7 - strlen(kasus[i].idHakim);//spasi didapatkan dari 7 dikurang panjang string indeks i
                            if(space.idHakim < 1) space.idHakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idHakim; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }
                        //print hakim
                        printf(" | %s", kasus[i].hakim);
                        if(max.hakim > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                            space.hakim = max.hakim - strlen(kasus[i].hakim);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.hakim; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                            space.hakim = 5 - strlen(kasus[i].hakim);//spasi didapatkan dari 5 dikurang panjang string indeks i
                            if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.hakim; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }

                        printf(" |\n");
                    }else if(strcmp(getcw(), "Gedung") == 0){
                        //print idGedung
                        printf(" | %s", kasus[i].idGedung);
                        if(max.idGedung > 8){//jika panjang maksimal stringnya lebih dari 8, maka;
                            space.idGedung = max.idGedung - strlen(kasus[i].idGedung);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idGedung; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 8, maka;
                            space.idGedung = 8 - strlen(kasus[i].idGedung);//spasi didapatkan dari 8 dikurang panjang string indeks i
                            if(space.idGedung < 1) space.idGedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.idGedung; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }
                        

                        //print gedung
                        printf(" | %s", kasus[i].gedung);
                        if(max.gedung > 6){//jika panjang maksimal stringnya lebih dari 6, maka;
                            space.gedung = max.gedung - strlen(kasus[i].gedung);//spasi didapatkan dari max string dikurangi string indeks i
                            if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.gedung; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }else{//jika panjang maksimal stringnya kurang / sama dengan 6, maka;
                            space.gedung = 6 - strlen(kasus[i].gedung);//spasi didapatkan dari 6 dikurang panjang string indeks i
                            if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                            for(j = 0; j < space.gedung; j++){
                                printf(" ");//print ' ' sebanyak jumlah spasi
                            }
                        }
                        
                        printf(" |\n");

                    }
                }
            }

            //memprint bagian bawah tabel
            start(pita);
            inc(pita);
            printf("+----+------+-");
            
            max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
            space.nama = 0;//membuat variabel untuk menampung jumlah spasi
            for(int i = 0; i < k; i++){
                if(max.nama < strlen(kasus[i].nama)){//jika ada strlen jenis yang lebih panjang
                    max.nama = strlen(kasus[i].nama);//maka update nilai max nya
                }
            }

            if(max.nama > 4){//jika maksimalnya lebih dari 4
                for(int i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                    printf("-");
                }
                
            }else{//jika kurang atau sama dengan 4
                for(int i = 0; i < 4; i++){
                    printf("-");//maka print '-' sebanyak 4 kali
                }
            }
            printf("-+-");

            if(lastw(pita)){
                max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                        max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                    }
                }

                if(max.idSin > 5){//jika maksimalnya lebih dari 5
                    for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 5
                    for(int i = 0; i < 5; i++){
                        printf("-");//maka print '-' sebanyak 5 kali
                    }
                }
                printf("-+-");
                
                max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                        max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                    }
                }

                if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                    for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 7
                    for(int i = 0; i < 7; i++){
                        printf("-");//maka print '-' sebanyak 7 kali
                    }
                }
                printf("-+-");
                
                max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                for(int i = 0; i < k; i++){
                    if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                        max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                    }
                }

                if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                    for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                        printf("-");
                    }
                    
                }else{//jika kurang atau sama dengan 8
                    for(int i = 0; i < 8; i++){
                        printf("-");//maka print '-' sebanyak 8 kali
                    }
                }
                printf("-+\n");
            }else{
                inc(pita);
                while(!lastw(pita)){
                    if(strcmp(getcw(), "Sin") == 0){
                        //print strip id sin
                        max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                                max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                            }
                        }

                        if(max.idSin > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");

                        //print strip kejahatan
                        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                                max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                            }
                        }
                        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                            for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 9
                            for(int i = 0; i < 9; i++){
                                printf("-");//maka print '-' sebanyak 9 kali
                            }
                        }
                        printf("-+-");
                        
                        //printf strip hukuman
                        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                                max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                            }
                        }

                        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Hakim") == 0){
                        //print strip id hakim
                        max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                                max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                            }
                        }

                        if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                            for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 7
                            for(int i = 0; i < 7; i++){
                                printf("-");//maka print '-' sebanyak 7 kali
                            }
                        }
                        printf("-+-");

                        //print strip hakim
                        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                                max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                            }
                        }

                        if(max.hakim > 5){//jika maksimalnya lebih dari 5
                            for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 5
                            for(int i = 0; i < 5; i++){
                                printf("-");//maka print '-' sebanyak 5 kali
                            }
                        }
                        printf("-+-");
                    }else if(strcmp(getcw(), "Gedung") == 0){
                        max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                                max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                            }
                        }

                        if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                            for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 8
                            for(int i = 0; i < 8; i++){
                                printf("-");//maka print '-' sebanyak 8 kali
                            }
                        }
                        printf("-+-");
                        
                        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                        for(int i = 0; i < k; i++){
                            if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                                max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                            }
                        }

                        if(max.gedung > 6){//jika maksimalnya lebih dari 6
                            for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                                printf("-");
                            }
                            
                        }else{//jika kurang atau sama dengan 6
                            for(int i = 0; i < 6; i++){
                                printf("-");//maka print '-' sebanyak 6 kali
                            }
                        }
                        printf("-+-");
                    }
                    inc(pita);
                }
                
                if(strcmp(getcw(), "Sin") == 0){
                    //print strip id sin
                    max.idSin = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idSin = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idSin < strlen(kasus[i].idSin)){//jika ada strlen jenis yang lebih panjang
                            max.idSin = strlen(kasus[i].idSin);//maka update nilai max nya
                        }
                    }

                    if(max.idSin > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.idSin; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+-");

                    //print strip kejahatan
                    max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.kejahatan < strlen(kasus[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                            max.kejahatan = strlen(kasus[i].kejahatan);//maka update nilai max nya
                        }
                    }

                    if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
                        for(int i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 9
                        for(int i = 0; i < 9; i++){
                            printf("-");//maka print '-' sebanyak 9 kali
                        }
                    }
                    printf("-+-");
                    
                    //printf strip hukuman
                    max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hukuman < strlen(kasus[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                            max.hukuman = strlen(kasus[i].hukuman);//maka update nilai max nya
                        }
                    }

                    if(max.hukuman > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Hakim") == 0){
                    //print strip id hakim
                    max.idHakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idHakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idHakim < strlen(kasus[i].idHakim)){//jika ada strlen jenis yang lebih panjang
                            max.idHakim = strlen(kasus[i].idHakim);//maka update nilai max nya
                        }
                    }

                    if(max.idHakim > 7){//jika maksimalnya lebih dari 7
                        for(int i = 0; i < max.idHakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 7
                        for(int i = 0; i < 7; i++){
                            printf("-");//maka print '-' sebanyak 7 kali
                        }
                    }
                    printf("-+-");

                    //print strip hakim
                    max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.hakim < strlen(kasus[i].hakim)){//jika ada strlen jenis yang lebih panjang
                            max.hakim = strlen(kasus[i].hakim);//maka update nilai max nya
                        }
                    }

                    if(max.hakim > 5){//jika maksimalnya lebih dari 5
                        for(int i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 5
                        for(int i = 0; i < 5; i++){
                            printf("-");//maka print '-' sebanyak 5 kali
                        }
                    }
                    printf("-+\n");
                }else if(strcmp(getcw(), "Gedung") == 0){
                    //print strip idgedung
                    max.idGedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.idGedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.idGedung < strlen(kasus[i].idGedung)){//jika ada strlen jenis yang lebih panjang
                            max.idGedung = strlen(kasus[i].idGedung);//maka update nilai max nya
                        }
                    }

                    if(max.idGedung > 8){//jika maksimalnya lebih dari 8
                        for(int i = 0; i < max.idGedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 8
                        for(int i = 0; i < 8; i++){
                            printf("-");//maka print '-' sebanyak 8 kali
                        }
                    }
                    printf("-+-");
                    
                    //print strip gedung
                    max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
                    space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
                    for(int i = 0; i < k; i++){
                        if(max.gedung < strlen(kasus[i].gedung)){//jika ada strlen jenis yang lebih panjang
                            max.gedung = strlen(kasus[i].gedung);//maka update nilai max nya
                        }
                    }

                    if(max.gedung > 6){//jika maksimalnya lebih dari 6
                        for(int i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                            printf("-");
                        }
                        
                    }else{//jika kurang atau sama dengan 6
                        for(int i = 0; i < 6; i++){
                            printf("-");//maka print '-' sebanyak 6 kali
                        }
                    }
                    printf("-+\n");
                }
            }
        }else{
            ERROR(22);
        }
    }else{
        ERROR(23);
    }
}

// Prosedur Untuk Menampilkan Tabel Dinamis Untuk Data KasusComplete
void tabel_KasusComplete(char pita[], int n, data *str){
    if(countw(pita) == 2){
        /*mendeklarasikan variabel untuk menampung nilai
        i = counting untuk loop for
        j = counting untuk loop for di dalam loop for
        count = counting untuk mengecek jumlah dari array bungkusan (cek sampai ketemu marking -1)*/
        int i, j;
        int count = 0;
        tabel max;
        tabel space;
        char mode[51];
        char mode1[51];

        start(pita);
        inc(pita);
        strcpy(mode, getcw());

        //memprint tabel
        j = 0;
        for(i = 0; i < strlen(mode); i++){
            if((mode[i] >= 'A' && mode[i] <= 'Z') && i != 0 && (mode[i-1] >= 'a' && mode[i-1] <= 'z')){
                mode1[j++] = ' ';
                // printf("masok\n");
            }
            mode1[j++] = mode[i];
        }
        mode1[j] = '\0';
        // strcpy(mode1, mode);

        for(i = 0; i < strlen(mode1); i++){
            if(mode1[i] >= 'a' && mode1[i] <= 'z'){
                mode1[i] -= 32;
            }
        }

        if(nonterm){
            clear();
            printf(TABEL"\n<<< TABEL %s >>>\n", mode1);
        }else{
            printf("\n<<< TABEL %s >>>\n", mode1);
        }
        
        //memprint baris atas
        printf("+----+------+-");
        
        max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.nama = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.nama < strlen(str[i].nama)){//jika ada strlen jenis yang lebih panjang
                max.nama = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max.nama > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");

        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+-");
        
        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hakim < strlen(str[i].hakim)){//jika ada strlen jenis yang lebih panjang
                max.hakim = strlen(str[i].hakim);//maka update nilai max nya
            }
        }

        if(max.hakim > 5){//jika maksimalnya lebih dari 5
            for(i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 5
            for(i = 0; i < 5; i++){
                printf("-");//maka print '-' sebanyak 5 kali
            }
        }
        printf("-+-");
        
        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.gedung < strlen(str[i].gedung)){//jika ada strlen jenis yang lebih panjang
                max.gedung = strlen(str[i].gedung);//maka update nilai max nya
            }
        }

        if(max.gedung > 6){//jika maksimalnya lebih dari 6
            for(i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 6
            for(i = 0; i < 6; i++){
                printf("-");//maka print '-' sebanyak 6 kali
            }
        }
        printf("-+\n");

        
        //memprint bagian judul
        printf("| No | Kode | Nama");
        space.nama = max.nama - 4;//spasi didapatkan dari panjang maksimal dikurang 12
        if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
        for(i = 0; i < space.nama; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" | ");
        
        printf("Kejahatan");
        space.kejahatan = max.kejahatan - 9;//spasi didapatkan dari panjang maksimal dikurang 9
        if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
        for(i = 0; i < space.kejahatan; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" | ");
        
        printf("Hukuman");
        space.hukuman = max.hukuman - 7;//spasi didapatkan dari panjang maksimal dikurang 7
        if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
        for(i = 0; i < space.hukuman; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" | ");
        
        printf("Hakim");
        space.hakim = max.hakim - 5;//spasi didapatkan dari panjang maksimal dikurang 5
        if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
        for(i = 0; i < space.hakim; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" | ");
        
        printf("Gedung");
        space.gedung = max.gedung - 6;//spasi didapatkan dari panjang maksimal dikurang 6
        if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif, maka spakejahatanya 0
        for(i = 0; i < space.gedung; i++){
            printf(" ");//print ' ' sebanyak jumlah spasi
        }
        printf(" |\n");


        //memprint bagian bawah judul
        printf("+----+------+-");
        
        max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.nama = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.nama < strlen(str[i].nama)){//jika ada strlen jenis yang lebih panjang
                max.nama = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max.nama > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");

        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+-");
        
        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hakim < strlen(str[i].hakim)){//jika ada strlen jenis yang lebih panjang
                max.hakim = strlen(str[i].hakim);//maka update nilai max nya
            }
        }

        if(max.hakim > 5){//jika maksimalnya lebih dari 5
            for(i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 5
            for(i = 0; i < 5; i++){
                printf("-");//maka print '-' sebanyak 5 kali
            }
        }
        printf("-+-");
        
        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.gedung < strlen(str[i].gedung)){//jika ada strlen jenis yang lebih panjang
                max.gedung = strlen(str[i].gedung);//maka update nilai max nya
            }
        }

        if(max.gedung > 6){//jika maksimalnya lebih dari 6
            for(i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 6
            for(i = 0; i < 6; i++){
                printf("-");//maka print '-' sebanyak 6 kali
            }
        }
        printf("-+\n");

        //print isi tabel
        for(i = 0; i < n; i++){//melakukan loop sebanyak jumlah array nya
            //print no, primary, dan nama
            if(i > 8){//jika no nya lebih dari 1 digit
                printf("| %d | ", i + 1);//maka print tanpa spasi setelahnya
            }else{//jika hanya 1 digit
                printf("| %d  | ", i + 1);//maka print dengan spasi setelahnya agar rata
            }
            printf("%s | %s", str[i].idKasus, str[i].nama);
            if(max.nama > 4){//jika panjang maksimal stringnya lebih dari 4, maka;
                space.nama = max.nama - strlen(str[i].nama);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.nama; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 4, maka;
                space.nama = 4 - strlen(str[i].nama);//spasi didapatkan dari 12 dikurang panjang string indeks i
                if(space.nama < 1) space.nama = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.nama; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            //print kejahatan
            printf(" | %s", str[i].kejahatan);
            if(max.kejahatan > 9){//jika panjang maksimal stringnya lebih dari 9, maka;
                space.kejahatan = max.kejahatan - strlen(str[i].kejahatan);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.kejahatan; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 9, maka;
                space.kejahatan = 9 - strlen(str[i].kejahatan);//spasi didapatkan dari 9 dikurang panjang string indeks i
                if(space.kejahatan < 1) space.kejahatan = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.kejahatan; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }
            
            //print hukumanan
            printf(" | %s", str[i].hukuman);
            if(max.hukuman > 7){//jika panjang maksimal stringnya lebih dari 7, maka;
                space.hukuman = max.hukuman - strlen(str[i].hukuman);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.hukuman; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 7, maka;
                space.hukuman = 7 - strlen(str[i].hukuman);//spasi didapatkan dari 7 dikurang panjang string indeks i
                if(space.hukuman < 1) space.hukuman = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.hukuman; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            //print hakim
            printf(" | %s", str[i].hakim);
            if(max.hakim > 5){//jika panjang maksimal stringnya lebih dari 5, maka;
                space.hakim = max.hakim - strlen(str[i].hakim);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.hakim; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 5, maka;
                space.hakim = 5 - strlen(str[i].hakim);//spasi didapatkan dari 5 dikurang panjang string indeks i
                if(space.hakim < 1) space.hakim = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.hakim; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }

            //print gedung
            printf(" | %s", str[i].gedung);
            if(max.gedung > 6){//jika panjang maksimal stringnya lebih dari 6, maka;
                space.gedung = max.gedung - strlen(str[i].gedung);//spasi didapatkan dari max string dikurangi string indeks i
                if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.gedung; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }else{//jika panjang maksimal stringnya kurang / sama dengan 6, maka;
                space.gedung = 6 - strlen(str[i].gedung);//spasi didapatkan dari 6 dikurang panjang string indeks i
                if(space.gedung < 1) space.gedung = 0;//jika spakejahatanya negatif maka spakejahatanya 0
                for(j = 0; j < space.gedung; j++){
                    printf(" ");//print ' ' sebanyak jumlah spasi
                }
            }
            
            printf(" |\n");
        }

        //memprint bagian bawah tabel
        printf("+----+------+-");
        
        max.nama = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.nama = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.nama < strlen(str[i].nama)){//jika ada strlen jenis yang lebih panjang
                max.nama = strlen(str[i].nama);//maka update nilai max nya
            }
        }

        if(max.nama > 4){//jika maksimalnya lebih dari 4
            for(i = 0; i < max.nama; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 4
            for(i = 0; i < 4; i++){
                printf("-");//maka print '-' sebanyak 4 kali
            }
        }
        printf("-+-");
        
        max.kejahatan = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.kejahatan = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.kejahatan < strlen(str[i].kejahatan)){//jika ada strlen jenis yang lebih panjang
                max.kejahatan = strlen(str[i].kejahatan);//maka update nilai max nya
            }
        }

        if(max.kejahatan > 9){//jika maksimalnya lebih dari 9
            for(i = 0; i < max.kejahatan; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 9
            for(i = 0; i < 9; i++){
                printf("-");//maka print '-' sebanyak 9 kali
            }
        }
        printf("-+-");

        max.hukuman = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hukuman = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hukuman < strlen(str[i].hukuman)){//jika ada strlen jenis yang lebih panjang
                max.hukuman = strlen(str[i].hukuman);//maka update nilai max nya
            }
        }

        if(max.hukuman > 7){//jika maksimalnya lebih dari 7
            for(i = 0; i < max.hukuman; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 7
            for(i = 0; i < 7; i++){
                printf("-");//maka print '-' sebanyak 7 kali
            }
        }
        printf("-+-");
        
        max.hakim = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.hakim = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.hakim < strlen(str[i].hakim)){//jika ada strlen jenis yang lebih panjang
                max.hakim = strlen(str[i].hakim);//maka update nilai max nya
            }
        }

        if(max.hakim > 5){//jika maksimalnya lebih dari 5
            for(i = 0; i < max.hakim; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 5
            for(i = 0; i < 5; i++){
                printf("-");//maka print '-' sebanyak 5 kali
            }
        }
        printf("-+-");
        
        max.gedung = 0;//membuat variabel untuk menampung panjang maksimal dari string jenis yang ada dalam bungkusan
        space.gedung = 0;//membuat variabel untuk menampung jumlah spasi
        for(i = 0; i < n; i++){
            if(max.gedung < strlen(str[i].gedung)){//jika ada strlen jenis yang lebih panjang
                max.gedung = strlen(str[i].gedung);//maka update nilai max nya
            }
        }

        if(max.gedung > 6){//jika maksimalnya lebih dari 6
            for(i = 0; i < max.gedung; i++){//maka print '-' sebanyak panjang maksimalnya
                printf("-");
            }
            
        }else{//jika kurang atau sama dengan 6
            for(i = 0; i < 6; i++){
                printf("-");//maka print '-' sebanyak 6 kali
            }
        }
        printf("-+\n");
    }else{
        ERROR(27);
    }

}

// Prosedur Untuk Memproses Input Ke Dalam Program Yang Telah Dibuat
void query(char tape[]){
    if((strcmp(getcw(), "INSERT") == 0) || (strcmp(getcw(), "UPDATE") == 0) ||
        (strcmp(getcw(), "DELETE") == 0) || (strcmp(getcw(), "SHOW") == 0) ||
        (strcmp(getcw(), "JOIN") == 0) || (strcmp(getcw(), "HELP") == 0)){
        int k = 0;
        data kasus[51];
        read_IdKasus(&k, kasus, "Kasus.txt");

        int kk = 0;
        data kasuss[51];
        read_IdKasus_Kasus(&kk, kasuss, "Kasuss.txt");

        int k1 = 0;
        data kasusCom[51];
        read_Kasus(&k1, kasusCom, "KasusComplete.txt");

        int s = 0;
        sin sin[51];
        read_Sin(&s, sin, "Sin.txt");

        int h = 0;
        hg hakim[51];
        read_HG(&h, hakim, "Hakim.txt");
        
        int g = 0;
        hg gedung[51];
        read_HG(&g, gedung, "Gedung.txt");


        start(tape);
        if(strcmp(getcw(), "INSERT") == 0 || strcmp(getcw(), "UPDATE") == 0 || strcmp(getcw(), "DELETE") == 0){
            inc(tape);
            if(strcmp(getcw(), "Kasus") == 0){
                modify_Kasus(tape, kasuss, &kk, sin, s, hakim, h, gedung, g);
                if(nonterm){
                    tabel_Kasus("SHOW Kasus;", kk, kasuss, s, sin, h, hakim, g, gedung);
                }
            }else if(strcmp(getcw(), "KasusComplete") == 0){
                modify_Kasus("SHOW KasusComplete;", kasusCom, &k1, sin, s, hakim, h, gedung, g);
                if(nonterm){
                    tabel_KasusComplete(tape, k1, kasusCom);
                }
            }else if(strcmp(getcw(), "Sin") == 0){
                modify_Sin(tape, sin, &s, kasus, k);
                if(nonterm){
                    tabel_Sin("SHOW Sin;", s, sin);
                }
            }else if(strcmp(getcw(), "Hakim") == 0){
                modify_HG(tape, hakim, &h, kasus, k);
                if(nonterm){
                    tabel_HG("SHOW Hakim;", h, hakim);
                }
            }else if(strcmp(getcw(), "Gedung") == 0){
                modify_HG(tape, gedung, &g, kasus, k);
                if(nonterm){
                    tabel_HG("SHOW Gedung;", g, gedung);
                }
            }else{
                start(tape);
                ERROR(3);
            }
        }else if(strcmp(getcw(), "SHOW") == 0){
            inc(tape);
            if(strcmp(getcw(), "Kasus") == 0){
                if(countw(tape) == 2){
                    tabel_Kasus(tape, kk, kasuss, s, sin, h, hakim, g, gedung);
                }else{
                    ERROR(29);
                }
            }else if(strcmp(getcw(), "KasusComplete") == 0){
                tabel_KasusComplete(tape, k1, kasusCom);
            }else if(strcmp(getcw(), "Sin") == 0){
                tabel_Sin(tape, s, sin);
            }else if(strcmp(getcw(), "Hakim") == 0){
                tabel_HG(tape, h, hakim);
            }else if(strcmp(getcw(), "Gedung") == 0){
                tabel_HG(tape, g, gedung);
            }else{
                ERROR(4);
            }
        }else if(strcmp(getcw(), "JOIN") == 0){
            inc(tape);
            if(strcmp(getcw(), "Kasus") == 0){
                if(countw(tape) >= 3){
                    tabel_Kasus(tape, kk, kasuss, s, sin, h, hakim, g, gedung);
                }else{
                    ERROR(30);
                }
            }else{
                ERROR(28);
            }
        }else if(strcmp(getcw(), "HELP") == 0){
            if(lastw(tape)){
                panduan();
            }else{
                inc(tape);
                if(strcmp(getcw(), "INSERT") == 0){
                    if(lastw(tape)){
                        help_insert();
                    }else{
                        inc(tape);
                        if(strcmp(getcw(), "Kasus") == 0){
                            help_insert_kasus();
                        }else if(strcmp(getcw(), "Sin") == 0){
                            help_insert_sin();
                        }else if(strcmp(getcw(), "Hakim") == 0){
                            help_insert_hakim();
                        }else if(strcmp(getcw(), "Gedung") == 0){
                            help_insert_gedung();
                        }else{
                            ERROR(33);
                        }
                    }
                }else if(strcmp(getcw(), "UPDATE") == 0){
                    if(lastw(tape)){
                        help_update();
                    }else{
                        inc(tape);
                        if(strcmp(getcw(), "Kasus") == 0){
                            help_update_kasus();
                        }else if(strcmp(getcw(), "Sin") == 0){
                            help_update_sin();
                        }else if(strcmp(getcw(), "Hakim") == 0){
                            help_update_hakim();
                        }else if(strcmp(getcw(), "Gedung") == 0){
                            help_update_gedung();
                        }else{
                            ERROR(34);
                        }
                    }
                }else if(strcmp(getcw(), "DELETE") == 0){
                    if(lastw(tape)){
                        help_delete();
                    }else{
                        inc(tape);
                        if(strcmp(getcw(), "Kasus") == 0){
                            help_delete_kasus();
                        }else if(strcmp(getcw(), "Sin") == 0){
                            help_delete_sin();
                        }else if(strcmp(getcw(), "Hakim") == 0){
                            help_delete_hakim();
                        }else if(strcmp(getcw(), "Gedung") == 0){
                            help_delete_gedung();
                        }else{
                            ERROR(35);
                        }
                    }
                }else if(strcmp(getcw(), "SHOW") == 0){
                    if(lastw(tape)){
                        help_show();
                    }else{
                        inc(tape);
                        if(strcmp(getcw(), "Kasus") == 0){
                            help_show_kasus();
                        }else if(strcmp(getcw(), "Sin") == 0){
                            help_show_sin();
                        }else if(strcmp(getcw(), "Hakim") == 0){
                            help_show_hakim();
                        }else if(strcmp(getcw(), "Gedung") == 0){
                            help_show_gedung();
                        }else{
                            ERROR(36);
                        }
                    }
                }else if(strcmp(getcw(), "JOIN") == 0){
                    if(lastw(tape)){
                        help_join();
                    }else{
                        inc(tape);
                        if(strcmp(getcw(), "Kasus") == 0){
                            help_join_kasus();
                        }else{
                            ERROR(39);
                        }
                    }
                }else if(strcmp(getcw(), "MultiQuery") == 0){
                    help_multiquery();
                }else{
                    ERROR(32);
                }
            }
        }

        join(kk, kasuss, s, sin, h, hakim, g, gedung);
        write_IdKasus_Kasus(kk, kasuss, "Kasuss.txt");
        write_IdKasus(kk, kasuss, "Kasus.txt");
        write_Kasus(kk, kasuss, "KasusComplete.txt");
    }else{
        ERROR(2);
    }
    
}

// Prosedur Untuk Menampilkan DBMS Warna-Warni 
void dbms(){
    printf(RED "Z" GREEN"C" YELLOW "F" BLUE "R" MAGENTA"Y"BRIGHT_GREEN " ON ");
}