/*Saya Muhammad 'Azmi Salam mengerjakan evaluasi Tugas Masa
Depan dalam mata kuliah Dasar-dasar Pemrograman untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.*/

#include "header.h"     // Mengincludekan library yang diinginkan
#include "animasi.h"    // Mengincludekan library yang diinginkan

int main(){
    int stop = 0;   // Mendeklarasikan Nilai Stop = 0, Program Dimulai Dengan Keadaan Tidak Berhenti
    nonterm = 0;    // Program Dimulai Dengan Mode Terminal
    system("cls");  // Membersihkan Layar Sebelum Intro Dimulai 
    intro();        // Memanggil Prosedur Intro Untuk Memulai Animasi Intro

    while(!stop){ // Loop Selama Nilai Stop = 0
        while(!nonterm && !stop){ // Loop Untuk Mode Terminal
            time_t now = time(NULL);
            struct tm *cur_time = localtime(&now);
            dbms(); // Memanggil DBMS Warna-Warni
            printf(BRIGHT_YELLOW "%02d:%02d:%02d >> " RESET, cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);
            scanf(" %500[^\n]s", &tape); // ada spasi sebelum simbol %
            if(ctape(tape) == 0){ // Proses Untuk Single Query
                if(cekEOP(tape)){ // Cek Apakah Memiliki EOP (;) atau Tidak
                    start(tape);
                    if(strcmp(getcw(), "ON") == 0){ // Kondisi Jika Masukan ON, Maka Masuk Ke Mode Non-Terminal
                        SUCCESS(5);
                        nonterm = 1;
                        sleep(3);
                    }else if(strcmp(getcw(), "OFF") == 0){ // Kondisi Jika Masukan OFF, Tidak Bisa Karena Masih Berada Di Mode Terminal
                        ERROR(37);
                    }else if((strcmp(getcw(), "EXIT") == 0) || (strcmp(getcw(), "babayy") == 0) ||
                        strcmp(tape, "jangan lupa bahagia hari ini;") == 0 || 
                        strcmp(tape, "aku adalah anak gembala selalu riang gembira;") == 0){ // Kondisi Untuk Keluar Dari Program
                        stop = 1;
                    }else{ // Kondisi Untuk Mulai Memproses Query
                        query(tape);
                    }
                }else{
                    ERROR(1);
                }
            }else{ // Proses Untuk Multiple Query
                int i = 0;
                char tmp[51][101];
                pisahtape(tape, tmp);
                if(ctape(tape) == countw(tape)){
                    while(i < ctape(tape)){
                        if(cekEOP(tmp[i])){
                            start(tmp[i]);
                            if(strcmp(getcw(), "ON") == 0){
                                SUCCESS(5);
                                nonterm = 1;
                                sleep(3);
                            }else if(strcmp(getcw(), "OFF") == 0){
                                ERROR(37);
                            }else if((strcmp(getcw(), "EXIT") == 0) || (strcmp(getcw(), "babayy") == 0) ||
                                strcmp(tmp[i], "jangan lupa bahagia hari ini;") == 0 || 
                                strcmp(tmp[i], "aku adalah anak gembala selalu riang gembira;") == 0){
                                stop = 1;
                            }else{
                                query(tmp[i]);
                            }
                        }else{
                            ERROR(1);
                        }
                        i++;
                    }
                }else{
                    ERROR(31);
                }
            }   
        }

        if(nonterm){ // Loop Untuk Mode Non-Terminal
            system("cls");
            int i = 0;
            while(nonterm && !stop){
                time_t now = time(NULL);
                struct tm *cur_time = localtime(&now);
                printf(ZCFRY RED "Z" GREEN"C" YELLOW "F" BLUE "R" MAGENTA"Y" /*BRIGHT_BLUE" [DBMS]"*/ BRIGHT_GREEN " ON "BRIGHT_YELLOW "%02d:%02d:%02d >> \n" RESET, cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec);
                if (kbhit()) {  // Mengecek apakah tombol ditekan
                    char ch = getch();  // Mengambil input tombol
                    if(ch == '\r'){
                        tape[i] = '\0';
                        i = 0;
                        if(ctape(tape) == 0){
                            if(cekEOP(tape)){
                                start(tape);
                                if(strcmp(getcw(), "OFF") == 0){
                                    SUCCESS(6);
                                    nonterm = 0;
                                    sleep(3);
                                }else if(strcmp(getcw(), "ON") == 0){
                                    ERROR(38);
                                }else if((strcmp(getcw(), "EXIT") == 0) || (strcmp(getcw(), "babayy") == 0) ||
                                    strcmp(tape, "jangan lupa bahagia hari ini;") == 0 || 
                                    strcmp(tape, "aku adalah anak gembala selalu riang gembira;") == 0){
                                    stop = 1;
                                }else{
                                    query(tape);
                                }
                            }else{
                                ERROR(1);
                            }
                        }else{
                            int i = 0;
                            char tmp[51][101];
                            pisahtape(tape, tmp);
                            if(ctape(tape) == countw(tape)){
                                while(i < ctape(tape)){
                                    if(cekEOP(tmp[i])){
                                        start(tmp[i]);
                                        if(strcmp(getcw(), "OFF") == 0){
                                            SUCCESS(6);
                                            nonterm = 0;
                                            sleep(3);
                                        }else if(strcmp(getcw(), "ON") == 0){
                                            ERROR(38);
                                        }else if((strcmp(getcw(), "EXIT") == 0) || (strcmp(getcw(), "babayy") == 0) ||
                                            strcmp(tmp[i], "jangan lupa bahagia hari ini;") == 0 || 
                                            strcmp(tmp[i], "aku adalah anak gembala selalu riang gembira;") == 0){
                                            stop = 1;
                                        }else{
                                            query(tmp[i]);
                                        }
                                    }else{
                                        ERROR(1);
                                    }
                                    i++;
                                }
                            }else{
                                ERROR(31);
                            }
                        }
                    }else if(ch == '\b'){
                        if (i > 0){
                            i--;
                            printf("\b \b");
                        }
                    }else{
                        // putchar(ch);
                        tape[i] = ch;
                        i++;
                    }
                    printf(INPUT"                                                                                                                         ");
                    printf(INPUT"%s\n", tape);
                    // tape[i++] = '\0';
                    // printf("%s\n", tape);
                }
            }
            system("cls");
        }
    }

    // Memanggil Prosedur Outro Untuk Menampilkan Animasi Outro
    outro();

    return 0;
}
//done