/*Saya Muhammad 'Azmi Salam mengerjakan evaluasi Tugas Masa
Depan dalam mata kuliah Dasar-dasar Pemrograman untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.*/

#include "header.h"     // Mengincludekan library yang diinginkan
#include "animasi.h"    // Mengincludekan library yang diinginkan

// Prosedur Untuk Menampilkan Buku Panduan
void panduan(){
    printf(CYAN"============================================================================\n");
    printf("|+------------------------------------------------------------------------+|\n");
    printf("||                                                                        ||\n");
    printf("||     <<<<<<<<<<<<<  BUKU PANDUAN MENGGUNAKAN KODE  >>>>>>>>>>>>>        ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"1. SETIAP PERINTAH WAJIB DIAKHIRI DENGAN TITIK KOMA (;)."CYAN"           ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"2. Pilih Masukan Perintah Dengan Format Seperti Di Bawah."CYAN"          ||\n");
    printf("||        "RED"CASE SENSITIVE!!!!"CYAN"                                              ||\n");
    printf("||        "RED"Perhatikan Huruf Besar Kecilnya!!"CYAN"                               ||\n");
    printf("||        "BRIGHT_CYAN"a. Perintah Langsung:"CYAN"                                           ||\n");
    printf("||           "GREEN"HELP;"CYAN"                                                        ||\n");
    printf("||           "BRIGHT_YELLOW"-Berfungsi Untuk Menampilkan Buku Panduan."CYAN"                   ||\n");
    printf("||           "GREEN"EXIT;"CYAN"                                                        ||\n");
    printf("||           "BRIGHT_YELLOW"-Berfungsi Untuk Mengakhiri Program."CYAN"                         ||\n");
    printf("||           "GREEN"ON/ OFF;"CYAN"                                                     ||\n");
    printf("||           "BRIGHT_YELLOW"-Berfungsi Untuk Masuk/ Keluar Dari Mode Non-Terminal."CYAN"       ||\n");
    printf("||                                                                        ||\n");
    printf("||        "BRIGHT_CYAN"b. Perintah Data:"CYAN"                                               ||\n");
    printf("||                 "BRIGHT_YELLOW"+----------+   +-------------------+"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"| PERINTAH |   |       DATA        |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"+----------+   +-------------------+"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"|   SHOW   |   |        Sin        |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"|   JOIN   |   |       Hakim       |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"|  INSERT  |   |      Gedung       |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"|  UPDATE  |   |       Kasus       |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"|  DELETE  |   |   KasusComplete   |"CYAN"                   ||\n");
    printf("||                 "BRIGHT_YELLOW"+----------+   +-------------------+"CYAN"                   ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"3. Jika Anda Memilih SHOW, Maka Anda Akan Dapat Melihat Data"CYAN"       ||\n");
    printf("||        "BRIGHT_CYAN"Pada Tabel. "RED"(Query SHOW Hanya Boleh 2 Kata!)"CYAN"                    ||\n");
    printf("||        "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                                  ||\n");
    printf("||        "GREEN"SHOW ["BRIGHT_YELLOW"Data"GREEN"];"CYAN"                                                    ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"4. Jika Anda Memilih JOIN, Maka Anda Akan Dapat Melihat Tabel"CYAN"      ||\n");
    printf("||        "BRIGHT_CYAN"JOIN. "RED"(Query JOIN Hanya Boleh Dilakukan Pada Data Kasus!)"CYAN"       ||\n");
    printf("||        "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                                  ||\n");
    printf("||         "BRIGHT_CYAN"a. Jika Ingin Menjoinkan 1 Data"CYAN"                                ||\n");
    printf("||            "GREEN"JOIN Kasus ["BRIGHT_YELLOW"Data1"GREEN"];"CYAN"                                         ||\n");
    printf("||         "BRIGHT_CYAN"b. Jika Ingin Menjoinkan 2 Data"CYAN"                                ||\n");
    printf("||            "GREEN"JOIN Kasus ["BRIGHT_YELLOW"Data1"GREEN"] ["BRIGHT_YELLOW"Data2"GREEN"];"CYAN"                                 ||\n");
    printf("||         "BRIGHT_CYAN"c. Jika Ingin Menjoinkan 3 Data"CYAN"                                ||\n");
    printf("||            "GREEN"JOIN Kasus ["BRIGHT_YELLOW"Data1"GREEN"] ["BRIGHT_YELLOW"Data2"GREEN"] ["BRIGHT_YELLOW"Data3"GREEN"];"CYAN"                         ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"5. Jika Anda Memilih INSERT/ UPDATE, Tulis ID dan Nama"CYAN"             ||\n");
    printf("||        "BRIGHT_CYAN"Jenisnya. "RED"(Jika Masukan Nama Lebih Dari 1 Kata/ Mengandung"CYAN"      ||\n");
    printf("||        "RED"Mengandung Spasi, Maka Wajib Diapit Dengan Tanda Petik Dua"CYAN"      ||\n");
    printf("||        "RED"CTH: \"Nama Panjang\")"CYAN"                                            ||\n");
    printf("||        "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                                  ||\n");
    printf("||         "BRIGHT_CYAN"a. Jika Hakim/ Gedung"CYAN"                                          ||\n");
    printf("||            "GREEN"["BRIGHT_YELLOW"PERINTAH"GREEN"] ["BRIGHT_YELLOW"Data"GREEN"] ["BRIGHT_YELLOW"IdData"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"                          ||\n");
    printf("||         "BRIGHT_CYAN"b. Jika Sin"CYAN"                                                    ||\n");
    printf("||            "GREEN"["BRIGHT_YELLOW"PERINTAH"GREEN"] Sin ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"Kejahatan"GREEN"] ["BRIGHT_YELLOW"Hukuman"GREEN"];"CYAN"               ||\n");
    printf("||         "BRIGHT_CYAN"c. Jika Kasus"CYAN"                                                  ||\n");
    printf("||            "GREEN"["BRIGHT_YELLOW"PERINTAH"GREEN"] Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"] ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"IdHakim"GREEN"]"CYAN"         ||\n");
    printf("||            "GREEN"["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"                                                 ||\n");
    printf("||         "BRIGHT_CYAN"d. Jika KasusComplete"CYAN"                                          ||\n");
    printf("||            "RED"Anda Tidak Bisa Melakukan INSERT/ UPDATE Dalam"CYAN"              ||\n");
    printf("||            "RED"KasusCompelete"CYAN"                                              ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"6. Jika Anda Memilih DELETE, Cukup Tulis ID Nya Saja."CYAN"              ||\n");
    printf("||        "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                                  ||\n");
    printf("||         "BRIGHT_CYAN"a. Jika Kasus/ Sin/ Hakim/ Gedung"CYAN"                              ||\n");
    printf("||            "GREEN"DELETE ["BRIGHT_YELLOW"Data"GREEN"] ["BRIGHT_YELLOW"IdData"GREEN"];"CYAN"                                     ||\n");
    printf("||         "BRIGHT_CYAN"b. Jika KasusCompelete"CYAN"                                         ||\n");
    printf("||            "RED"Anda Tidak Bisa Melakukan DELETE Dalam KasusCompelete"CYAN"       ||\n");
    printf("||                                                                        ||\n");
    printf("||     "BRIGHT_CYAN"7. Perintah Untuk Melakukan MULTIPLE QUERY"CYAN"                         ||\n");
    printf("||        "BRIGHT_YELLOW"FORMAT MULTIPLE QUERY :"CYAN"                                         ||\n");
    printf("||        "GREEN"["BRIGHT_YELLOW"\"Query1\\;\""GREEN"] ["BRIGHT_YELLOW"\"Query2\\;\""GREEN"] ["BRIGHT_YELLOW"\"Query3\\;\""GREEN"];"CYAN"                         ||\n");
    printf("||                                                                        ||\n");
    printf("||                                                                        ||\n");
    printf("|+------------------------------------------------------------------------+|\n");
    printf("============================================================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help Insert
void help_insert(){
    printf(CYAN"===================================================================\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("||                 <<<<<<<  HELP INSERT  >>>>>>>                 ||\n");
    printf("||                                                               ||\n");
    printf("||    "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                             ||\n");
    printf("||     "BRIGHT_CYAN"1. Jika Hakim/ Gedung"CYAN"                                     ||\n");
    printf("||        "GREEN"INSERT ["BRIGHT_YELLOW"Data"GREEN"] ["BRIGHT_YELLOW"IdData"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"                         ||\n");
    printf("||     "BRIGHT_CYAN"2. Jika Sin"CYAN"                                               ||\n");
    printf("||        "GREEN"INSERT Sin ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"Kejahatan"GREEN"] ["BRIGHT_YELLOW"Hukuman"GREEN"];"CYAN"              ||\n");
    printf("||     "BRIGHT_CYAN"3. Jika Kasus"CYAN"                                             ||\n");
    printf("||        "GREEN"INSERT Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"] ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"IdHakim"GREEN"]"CYAN"        ||\n");
    printf("||        "GREEN"["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"                                            ||\n");
    printf("||                                                               ||\n");
    printf("||    "YELLOW"Jika Masukan Nama Lebih Dari 1 Kata/ Mengandung Spasi,"CYAN"     ||\n");
    printf("||    "YELLOW"Maka Wajib Diapit Dengan Tanda Petik Dua (;)."CYAN"              ||\n");
    printf("||    "YELLOW"CTH: \"Nama Aku Panjang\""CYAN"                                    ||\n");
    printf("||                                                               ||\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("===================================================================\n\n"RESET);
}

void help_insert_kasus(){
    printf(CYAN"===================================================================\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("||                 <<<<<  HELP INSERT KASUS >>>>>                ||\n");
    printf("||                                                               ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                               ||\n");
    printf("||  "GREEN"INSERT Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"] ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"IdHakim"GREEN"]"CYAN" "GREEN"["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"  ||\n");
    printf("||                                                               ||\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("===================================================================\n\n"RESET);
}

void help_insert_sin(){
    printf(CYAN"=================================================\n");
    printf("|+---------------------------------------------+|\n");
    printf("||        <<<<<  HELP INSERT SIN >>>>>         ||\n");
    printf("||                                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                             ||\n");
    printf("||  "GREEN"INSERT Sin ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"Kejahatan"GREEN"] ["BRIGHT_YELLOW"Hukuman"GREEN"];"CYAN"  ||\n");
    printf("||                                             ||\n");
    printf("|+---------------------------------------------+|\n");
    printf("=================================================\n\n");
}

void help_insert_hakim(){
    printf(CYAN"======================================\n");
    printf("|+----------------------------------+|\n");
    printf("||    <<<  HELP INSERT HAKIM >>>    ||\n");
    printf("||                                  ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                  ||\n");
    printf("||  "GREEN"INSERT HAKIM ["BRIGHT_YELLOW"IdHakim"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"  ||\n");
    printf("||                                  ||\n");
    printf("|+----------------------------------+|\n");
    printf("======================================\n\n"RESET);
}

void help_insert_gedung(){
    printf(CYAN"========================================\n");
    printf("|+------------------------------------+|\n");
    printf("||    <<<  HELP INSERT GEDUNG >>>     ||\n");
    printf("||                                    ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                    ||\n");
    printf("||  "GREEN"INSERT GEDUNG ["BRIGHT_YELLOW"IdGedung"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"  ||\n");
    printf("||                                    ||\n");
    printf("|+------------------------------------+|\n");
    printf("========================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help Update
void help_update(){
    printf(CYAN"===================================================================\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("||                 <<<<<<<  HELP UPDATE  >>>>>>>                 ||\n");
    printf("||                                                               ||\n");
    printf("||    "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                             ||\n");
    printf("||     "BRIGHT_CYAN"1. Jika Hakim/ Gedung"CYAN"                                     ||\n");
    printf("||        "GREEN"UPDATE ["BRIGHT_YELLOW"Data"GREEN"] ["BRIGHT_YELLOW"IdData"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"                         ||\n");
    printf("||     "BRIGHT_CYAN"2. Jika Sin"CYAN"                                               ||\n");
    printf("||        "GREEN"UPDATE Sin ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"Kejahatan"GREEN"] ["BRIGHT_YELLOW"Hukuman"GREEN"];"CYAN"              ||\n");
    printf("||     "BRIGHT_CYAN"3. Jika Kasus"CYAN"                                             ||\n");
    printf("||        "GREEN"UPDATE Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"] ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"IdHakim"GREEN"]"CYAN"        ||\n");
    printf("||        "GREEN"["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"                                            ||\n");
    printf("||                                                               ||\n");
    printf("||    "YELLOW"Jika Masukan Nama Lebih Dari 1 Kata/ Mengandung Spasi,"CYAN"     ||\n");
    printf("||    "YELLOW"Maka Wajib Diapit Dengan Tanda Petik Dua (;)."CYAN"              ||\n");
    printf("||    "YELLOW"CTH: \"Nama Aku Panjang\""CYAN"                                    ||\n");
    printf("||                                                               ||\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("===================================================================\n\n"RESET);
}

void help_update_kasus(){
    printf(CYAN"===================================================================\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("||                 <<<<<  HELP UPDATE KASUS >>>>>                ||\n");
    printf("||                                                               ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                               ||\n");
    printf("||  "GREEN"UPDATE Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"] ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"IdHakim"GREEN"]"CYAN" "GREEN"["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"  ||\n");
    printf("||                                                               ||\n");
    printf("|+---------------------------------------------------------------+|\n");
    printf("===================================================================\n\n"RESET);
}

void help_update_sin(){
    printf(CYAN"=================================================\n");
    printf("|+---------------------------------------------+|\n");
    printf("||        <<<<<  HELP UPDATE SIN >>>>>         ||\n");
    printf("||                                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                             ||\n");
    printf("||  "GREEN"UPDATE Sin ["BRIGHT_YELLOW"IdSin"GREEN"] ["BRIGHT_YELLOW"Kejahatan"GREEN"] ["BRIGHT_YELLOW"Hukuman"GREEN"];"CYAN"  ||\n");
    printf("||                                             ||\n");
    printf("|+---------------------------------------------+|\n");
    printf("=================================================\n\n"RESET);
}

void help_update_hakim(){
    printf(CYAN"======================================\n");
    printf("|+----------------------------------+|\n");
    printf("||    <<<  HELP UPDATE HAKIM >>>    ||\n");
    printf("||                                  ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                  ||\n");
    printf("||  "GREEN"UPDATE HAKIM ["BRIGHT_YELLOW"IdHakim"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"  ||\n");
    printf("||                                  ||\n");
    printf("|+----------------------------------+|\n");
    printf("======================================\n\n"RESET);
}

void help_update_gedung(){
    printf(CYAN"========================================\n");
    printf("|+------------------------------------+|\n");
    printf("||    <<<  HELP UPDATE GEDUNG >>>     ||\n");
    printf("||                                    ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                    ||\n");
    printf("||  "GREEN"UPDATE GEDUNG ["BRIGHT_YELLOW"IdGedung"GREEN"] ["BRIGHT_YELLOW"Nama"GREEN"];"CYAN"  ||\n");
    printf("||                                    ||\n");
    printf("|+------------------------------------+|\n");
    printf("========================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help Delete
void help_delete(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||    <<<< HELP DELETE >>>>    ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"DELETE ["BRIGHT_YELLOW"Data"GREEN"] ["BRIGHT_YELLOW"IdData"GREEN"];"CYAN"    ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

void help_delete_kasus(){
    printf(CYAN"===============================\n");
    printf("|+---------------------------+|\n");
    printf("||  << HELP DELETE KASUS >>  ||\n");
    printf("||                           ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"           ||\n");
    printf("||  "GREEN"DELETE Kasus ["BRIGHT_YELLOW"IdKasus"GREEN"];"CYAN"  ||\n");
    printf("||                           ||\n");
    printf("|+---------------------------+|\n");
    printf("===============================\n\n"RESET);
}

void help_delete_sin(){
    printf(CYAN"===========================\n");
    printf("|+-----------------------+|\n");
    printf("|| << HELP DELETE SIN >> ||\n");
    printf("||                       ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"       ||\n");
    printf("||  "GREEN"DELETE Sin ["BRIGHT_YELLOW"IdSin"GREEN"];"CYAN"  ||\n");
    printf("||                       ||\n");
    printf("|+-----------------------+|\n");
    printf("===========================\n\n"RESET);
}

void help_delete_hakim(){
    printf(CYAN"===============================\n");
    printf("|+---------------------------+|\n");
    printf("||  << HELP DELETE HAKIM >>  ||\n");
    printf("||                           ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"           ||\n");
    printf("||  "GREEN"DELETE Hakim ["BRIGHT_YELLOW"IdHakim"GREEN"];"CYAN"  ||\n");
    printf("||                           ||\n");
    printf("|+---------------------------+|\n");
    printf("===============================\n\n"RESET);
}

void help_delete_gedung(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("|| <<< HELP DELETE GEDUNG >>>  ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"DELETE Gedung ["BRIGHT_YELLOW"IdGedung"GREEN"];"CYAN"  ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help Show
void help_show(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||     <<<< HELP SHOW >>>>     ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"SHOW ["BRIGHT_YELLOW"Data"GREEN"];"CYAN"               ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

void help_show_kasus(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||     <<<< HELP SHOW >>>>     ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"SHOW Kasus;"CYAN"                ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

void help_show_sin(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||     <<<< HELP SHOW >>>>     ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"SHOW Sin;"CYAN"                  ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

void help_show_hakim(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||     <<<< HELP SHOW >>>>     ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"SHOW Hakim;"CYAN"                ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

void help_show_gedung(){
    printf(CYAN"=================================\n");
    printf("|+-----------------------------+|\n");
    printf("||     <<<< HELP SHOW >>>>     ||\n");
    printf("||                             ||\n");
    printf("||  "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"             ||\n");
    printf("||  "GREEN"SHOW Gedung;"CYAN"               ||\n");
    printf("||                             ||\n");
    printf("|+-----------------------------+|\n");
    printf("=================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help Join
void help_join(){
    printf(CYAN"=================================================================\n");
    printf("|+-------------------------------------------------------------+|\n");
    printf("||                     <<<< HELP JOIN >>>>                     ||\n");
    printf("||                                                             ||\n");
    printf("||   "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                            ||\n");
    printf("||   "GREEN"JOIN Kasus ["BRIGHT_YELLOW"Data1"GREEN"] ["BRIGHT_YELLOW"Data2"GREEN"] ["BRIGHT_YELLOW"Data3"GREEN"];"CYAN"                       ||\n");
    printf("||                                                             ||\n");
    printf("||   "YELLOW"Join Hanya Bisa Dilakukan Pada Tabel Kasus,"CYAN"               ||\n");
    printf("||   "YELLOW"Data Yang Sudah Dijoinkan Tidak Bisa Dijoinkan Kembali."CYAN"   ||\n");
    printf("|+-------------------------------------------------------------+|\n");
    printf("=================================================================\n\n"RESET);
}

void help_join_kasus(){
    printf(CYAN"=================================================================\n");
    printf("|+-------------------------------------------------------------+|\n");
    printf("||                  <<<< HELP JOIN KASUS >>>>                  ||\n");
    printf("||                                                             ||\n");
    printf("||   "BRIGHT_YELLOW"FORMAT QUERY :"CYAN"                                            ||\n");
    printf("||   "GREEN"JOIN Kasus ["BRIGHT_YELLOW"Data1"GREEN"] ["BRIGHT_YELLOW"Data2"GREEN"] ["BRIGHT_YELLOW"Data3"GREEN"];"CYAN"                       ||\n");
    printf("||                                                             ||\n");
    printf("||   "YELLOW"Join Hanya Bisa Dilakukan Pada Tabel Kasus,"CYAN"               ||\n");
    printf("||   "YELLOW"Data Yang Sudah Dijoinkan Tidak Bisa Dijoinkan Kembali."CYAN"   ||\n");
    printf("|+-------------------------------------------------------------+|\n");
    printf("=================================================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Help MultiQuery
void help_multiquery(){
    printf(CYAN"=======================================================================\n");
    printf("|+-------------------------------------------------------------------+|\n");
    printf("||                   <<<< HELP MULTIPLE QUERY >>>>                   ||\n");
    printf("||                                                                   ||\n");
    printf("||   "BRIGHT_CYAN"Perintah Untuk Melakukan MULTIPLE QUERY"CYAN"                         ||\n");
    printf("||   "BRIGHT_YELLOW"FORMAT MULTIPLE QUERY :"CYAN"                                         ||\n");
    printf("||   "GREEN"["BRIGHT_YELLOW"\"Query1\\;\""GREEN"] ["BRIGHT_YELLOW"\"Query2\\;\""GREEN"] ["BRIGHT_YELLOW"\"Query3\\;\""GREEN"];"CYAN"                         ||\n");
    printf("||                                                                   ||\n");
    printf("||   "YELLOW"Multiquery Dapat Dilakukan Terus Menerus Tanpa Batas Maksimal,"CYAN"  ||\n");
    printf("||   "YELLOW"Setiap Query Yang Ingin Dilakukan Wajib Diapit Dengan Tanda"CYAN"     ||\n");
    printf("||   "YELLOW"Petik Dua (\") Dan Diakhiri Dengan Backslash Titik Koma (\\;)."CYAN"    ||\n");
    printf("||                                                                   ||\n");
    printf("|+-------------------------------------------------------------------+|\n");
    printf("=======================================================================\n\n"RESET);
}

// Prosedur Untuk Menampilkan Intro
void intro(){
    system("start wmplayer \"D:\\Muhammad 'Azmi Salam\\Kuliah\\Dasar-Dasar Pemrograman\\Tugas Masa Depan\\Tugas Masa Depan 24\\Faint - Linkin Park.mp3\"");

    // sin 1
    printf(ZCFRY);
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("     Q                                      \n");
    printf("    /|\\    ______                           \n");
    printf("#\"==(_/o).Z     _)                          \n");
    printf("    / \\        Z__                          \n");
    printf("   /  /        |()|   ♫Em7                  \n");
    printf("  ~   ~        |__|                         \n");
    
    // sin 2
    usleep(500000);
    printf(ZCFRY);
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("     Q                                      \n");
    printf("    /|\\    ______                           \n");
    printf("#\"==(_-o).Z     _)                          \n");
    printf("    / \\        Z__          ♫Em7            \n");
    printf("   /  /        |()|   ♫G7                   \n");
    printf("  ~   ~        |__|                         \n");
    
    
    // sin 3
    usleep(500000);
    printf(ZCFRY);
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("                                            \n");
    printf("     Q                                      \n");
    printf("    /|\\    ______                           \n");
    printf("#\"==(_|o).Z     _)                ♫Em7      \n");
    printf("    / \\        Z__           ♫G7            \n");
    printf("   /  /        |()|   ♫Cjm97                \n");
    printf("  ~   ~        |__|                         \n");

    // sin 4
    usleep(500000);
    printf(ZCFRY);
    printf("                                                      \n");
    printf("                                                      \n");
    printf("                                                      \n");
    printf("                                                      \n");
    printf("                                                      \n");
    printf("     Q                                 ♫Em7           \n");
    printf("    /|\\    ______                   ♫G7               \n");
    printf("#\"==(_/o).Z     _)                                     \n");
    printf("    / \\        Z__          ♫Cjm97                     \n");
    printf("   /  /        |()|   ♫Dmaj7                            \n");
    printf("  ~   ~        |__|                                   \n");
    
    // sin 5
    usleep(500000);
    printf(ZCFRY);
    printf("                                                          \n");
    printf("                                                          \n");
    printf("                                                          \n");
    printf("                                       ♫Em7               \n");
    printf("                                                          \n");
    printf("     Q                                    ♫G7             \n");
    printf("    /|\\    ______                   ♫Cjm97                \n");
    printf("#\"==(_-o).Z     _)                                        \n");
    printf("    / \\        Z__          ♫Dmaj7                        \n");
    printf("   /  /        |()|   ♫Em7                                \n");
    printf("  ~   ~        |__|                                       \n");
    
    
    // sin 6
    usleep(500000);
    printf(ZCFRY);
    printf("                                                              \n");
    printf("                                      ♫Em7                    \n");
    printf("                                           ♫G7                \n");
    printf("                                                              \n");
    printf("                                             ♫Cjm97           \n");
    printf("     Q                                                        \n");
    printf("    /|\\    ______                           ♫Dmaj7            \n");
    printf("#\"==(_|o).Z     _)                 ♫Em7                       \n");
    printf("    / \\        Z__           ♫G7                              \n");
    printf("   /  /        |()|   ♫Cjm97                                  \n");
    printf("  ~   ~        |__|                                           \n");

    // sin 7
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7                    \n");
    printf("                                           ♫G7                \n");
    printf("                                               ♫Cjm97         \n");
    printf("                                                              \n");
    printf("                                                 ♫Dmaj7             \n");
    printf("     Q                                       ♫Em7             \n");
    printf("    /|\\    ______                                             \n");
    printf("#\"==(_/o).Z     _)                     ♫G7                    \n");
    printf("    / \\        Z__              ♫Cjm97                        \n");
    printf("   /  /        |()|   ♫Dmaj7                                  \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 8
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7                   \n");
    printf("                                               ♫Cjm97            \n");
    printf("                                                ♫Dmaj7        \n");
    printf("                                                              \n");
    printf("                                              ♫Em7                \n");
    printf("     Q                                                    \n");
    printf("    /|\\    ______                         ♫G7                    \n");
    printf("#\"==(_-o).Z     _)                   ♫Cjm97                      \n");
    printf("    / \\        Z__             ♫Dmaj7                      \n");
    printf("   /  /        |()|    ♫Em7                                 \n");
    printf("  ~   ~        |__|                                           \n");
    
    
    // sin 9
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                                        \n");
    printf("                                            ♫Em7                  \n");
    printf("                                        ♫G7                      \n");
    printf("     Q                                                    \n");
    printf("    /|\\    ______                    ♫Cjm97                         \n");
    printf("#\"==(_|o).Z     _)                       ♫Dmaj7                  \n");
    printf("    / \\        Z__                ♫Em7                   \n");
    printf("   /  /        |()|    ♫G7                                 \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 10
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                            ♫Em7            \n");
    printf("                                        ♫G7                      \n");
    printf("                                      ♫Cjm97                        \n");
    printf("     Q                                   ♫Dmaj7                 \n");
    printf("    /|\\    ______                                             \n");
    printf("#\"==(_/o).Z     _)                         ♫Em7                \n");
    printf("    / \\        Z__                 ♫G7                  \n");
    printf("   /  /        |()|    ♫Cjm97                                 \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 11
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                            ♫Em7            \n");
    printf("                                        ♫G7                      \n");
    printf("                                      ♫Cjm97                        \n");
    printf("     Q                             ♫Dmaj7 ♫Em7                     \n");
    printf("    /|\\    ______                          ♫G7                   \n");
    printf("#\"==(_-o).Z     _)                   ♫Cjm97                      \n");
    printf("    / \\        Z__                                   \n");
    printf("   /  /        |()|      ♫Dmaj7                               \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 12
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                            ♫Em7            \n");
    printf("                                        ♫G7                      \n");
    printf("                                      ♫Cjm97                        \n");
    printf("     Q                             ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("    /|\\    ______                                             \n");
    printf("#\"==(_|o).Z     _)                                         \n");
    printf("    / \\        Z__                                   \n");
    printf("   /  /        |()|      ♫Dmaj7                               \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 13
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                            ♫Em7            \n");
    printf("                                        ♫G7                      \n");
    printf("                                      ♫Cjm97                        \n");
    printf("     Q                             ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("    /|\\    ______                                             \n");
    printf("#\"==(_/o).Z     _)                                         \n");
    printf("    \\ \\        Z__                                   \n");
    printf("   /  /        |()|      ♫Dmaj7                               \n");
    printf("  ~   ~        |__|                                           \n");
    
    // sin 14
    usleep(500000);
    printf(ZCFRY);
    printf("                                      ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                               ♫Dmaj7            \n");
    printf("                                            ♫Em7            \n");
    printf("                                        ♫G7                      \n");
    printf("     Q                                ♫Cjm97                        \n");
    printf("    /|\\    ______                  ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("#\"==(_-o).Z      \\      ♫Dmaj7                                              \n");
    printf("    | |           |       ,;;;,;                  \n");
    printf("    | |          Z__      `;;;;'                         \n");
    printf("    ~  ~        |()|                                     \n");
    printf("                |__|                                        \n");
    
    // sin 15
    usleep(500000);
    printf(ZCFRY);
    printf("                                          ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("                                                   ♫Dmaj7            \n");
    printf("     Q                                          ♫Em7               \n");
    printf("    /|\\    ______                           ♫G7                      \n");
    printf("#\"==(_-o).Z      \\      ♫Dmaj7          ♫Cjm97                        \n");
    printf("    | |           \\           ;  '      ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("    | |            \\          ;                                              \n");
    printf("    ~  ~           __)    ,;;;,;                                                          \n");
    printf("                Z__       `;;;;'                                              \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 16
    usleep(500000);
    printf(ZCFRY);
    printf("     Q_/                       ;                 ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("    /|     ______              ;;                         ♫Dmaj7            \n");
    printf("#\"==(_-o).Z      \\             ;';.                       ♫Em7               \n");
    printf("    / \\           \\            ;  ;;                   ♫G7                      \n");
    printf("   /   \\           \\           ;  ;'             ♫Cjm97                        \n");
    printf("   ~    ~          |           ;  '           ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("                   /           ;                                                \n");
    printf("                 __)      ,;;;,;                                                           \n");
    printf("                Z__       `;;;;'                                                \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 17
    usleep(2000000);
    printf(ZCFRY);
    printf("     Q                            ;              ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("    /|\\    ______                 ;;                      ♫Dmaj7            \n");
    printf("#\"==(_/o).Z      \\                ;';.                    ♫Em7               \n");
    printf("    / \\           \\               ;  ;;                ♫G7                      \n");
    printf("   /   \\           \\              ;  ;'          ♫Cjm97                        \n");
    printf("   ~    ~          |              ;  '        ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("                   /              ;                                             \n");
    printf("                 __)         ,;;;,;                                                        \n");
    printf("                Z__          `;;;;'                                             \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 18
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                               ;           ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("    /|\\    ______                    ;;                   ♫Dmaj7            \n");
    printf("#\"==(_-o).Z      \\                   ;';.                 ♫Em7               \n");
    printf("    / \\           \\                  ;  ;;             ♫G7                      \n");
    printf("   /   \\           \\                 ;  ;'       ♫Cjm97                        \n");
    printf("   ~    ~          |                 ;  '     ♫Dmaj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("                   /                 ;                                          \n");
    printf("                 __)            ,;;;,;                                                     \n");
    printf("                Z__             `;;;;'                                          \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 19
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                   ;       ♫Em7 ♫G7 ♫Cjm97                  \n");
    printf("    /|\\    ______                        ;;               ♫Dmaj7            \n");
    printf("#\"==(_|o).Z      \\                       ;';.             ♫Em7               \n");
    printf("    / \\           \\                      ;  ;;         ♫G7                      \n");
    printf("   /   \\           \\                     ;  ;'   ♫Cjm97                        \n");
    printf("   ~    ~          |                     ;  '   maj7 ♫Em7 ♫G7 ♫Cjm97                   \n");
    printf("                   /                     ;                                      \n");
    printf("                 __)                ,;;;,;                                                 \n");
    printf("                Z__                 `;;;;'                                      \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 20
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒██"RESET";  7 ♫G7 ♫Cjm97                  \n");
    printf("    /|\\    ______                         "PINK"▒ ▒"RESET";;           ♫Dmaj7            \n");
    printf("#\"==(_/o).Z      \\                        "PINK"░ ▒"RESET";';.         ♫Em7               \n");
    printf("    / \\           \\                         "PINK"▄"RESET";  ;;     ♫G7                      \n");
    printf("   /   \\           \\                      "PINK"▒██"RESET";  ;'Cjm97                        \n");
    printf("   ~    ~          |                      "PINK"░▒▒"RESET";  ' Em7 ♫G7 ♫Cjm97                   \n");
    printf("                   /                      "PINK"░░▒"RESET";                                  \n");
    printf("                 __)                    ,;;;,;                                             \n");
    printf("                Z__                     `;;;;'                                  \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 21
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒██████"RESET"; 7 ♫Cjm97                  \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄"RESET";;       ♫Dmaj7            \n");
    printf("#\"==(_-o).Z      \\                        "PINK"░ ▒ ▄▀▒"RESET";';.     ♫Em7               \n");
    printf("    / \\           \\                         "PINK"▄▀▒"RESET"  ;  ;; ♫G7                      \n");
    printf("   /   \\           \\                      "PINK"▒██████"RESET";  ;'7                        \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒"RESET";  ' ♫G7 ♫Cjm97                   \n");
    printf("                   /                      "PINK"░░▒ ▒ ░"RESET";                              \n");
    printf("                 __)                      "PINK"░░"RESET",;;;,;                                         \n");
    printf("                Z__                       "PINK"░"RESET" `;;;;'                              \n");
    printf("                |()|                                               \n");
    printf("                |__|                                                 \n");
    
    // sin 22
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄█"RESET";  7 7                  \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██"RESET";;    aj7            \n");
    printf("#\"==(_|o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█"RESET";';. Em7               \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓"RESET";  ;;                     \n");
    printf("   /   \\           \\                     "PINK" ▒███████▒▒ ▓"RESET";  ;'                    \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░"RESET";  '  Cjm97                   \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░"RESET";                         \n");
    printf("                 __)                      "PINK"░ ░ ░ ░"RESET",;;;,;                                    \n");
    printf("                Z__                         "PINK"░ ░"RESET"  `;;;;'                         \n");
    printf("                |()|                      "PINK"░"RESET"                        \n");
    printf("                |__|                                                  \n");
    
    // sin 23
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄"RESET" ;             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█"RESET" ;;              \n");
    printf("#\"==(_/o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄"RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██"RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀"RESET" ;  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒"RESET"  ;  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒"RESET"  ;                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░"RESET"  ,;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░"RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░"RESET"               \n");
    printf("                |__|                                                \n");
    
    // sin 24
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █"RESET" ;             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██ "RESET";;              \n");
    printf("#\"==(_-o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒███"RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒"RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░"RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░"RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░  "RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░     "RESET"  ,;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░     "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░     "RESET"               \n");
    printf("                |__|                                                \n");
    
    // sin 25
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █████▒██▀"RESET";             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ "RESET";;              \n");
    printf("#\"==(_|o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ "RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀"RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓"RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓"RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒"RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░         ░ ░"RESET"  ,;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░            "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░            "RESET"                    \n");
    printf("                |__|                                                                               \n");
    
    // sin 26
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █████▒██▀███ ▓██"RESET";             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ ▒ ██▒▒█"RESET";;              \n");
    printf("#\"==(_/o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ ░▄█ ▒ ▒"RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀▀█▄   ░"RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓ ▒██▒ ░"RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓ ░▒▓░  "RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒ ░ ▒░▓█"RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░         ░ ░     ░░"RESET"  ,;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░                ░  "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░                     "RESET"                    \n");
    printf("                |__|                                                                               \n");
    
    // sin 27
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █████▒██▀███ ▓██   ██▓   ▓████"RESET";             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ ▒ ██▒▒██  ██▒   ▒██▀ "RESET";;              \n");
    printf("#\"==(_-o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ ░▄█ ▒ ▒██ ██░   ░██  "RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀▀█▄   ░ ▐██▓░   ░▓█▄ "RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓ ▒██▒ ░ ██▒▓░   ░▒███"RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒▓ "RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒ ░ ▒░▓██ ░▒░     ░ ▒ "RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░         ░ ░     ░░   ░ ▒ ▒ ░░     "RESET",;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░                ░     ░ ░        "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░                        ░ ░        "RESET"                   \n");
    printf("                |__|                                                                                                 \n");
    
    // sin 28
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █████▒██▀███ ▓██   ██▓   ▓█████▄  ▄▄▄"RESET";             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ ▒ ██▒▒██  ██▒   ▒██▀ ██▌▓███"RESET";;              \n");
    printf("#\"==(_|o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ ░▄█ ▒ ▒██ ██░   ░██   █▌▒██▒"RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀▀█▄   ░ ▐██▓░   ░▓█▄   ▌▒██░"RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓ ▒██▒ ░ ██▒▓░   ░▒████▓ ░▓█ "RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒▓  ▒ ░▒▓█"RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒ ░ ▒░▓██ ░▒░     ░ ▒  ▒ ▒░▒ "RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░         ░ ░     ░░   ░ ▒ ▒ ░░      ░ ░  ░"RESET",;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░                ░     ░ ░           ░   "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░                        ░ ░         ░     "RESET"                   \n");
    printf("                |__|                                                                                                 \n");
    
    // sin 29
    usleep(750000);
    printf(ZCFRY);
    printf("     Q                                    "PINK"▒███████▒ ▄████▄    █████▒██▀███ ▓██   ██▓   ▓█████▄  ▄▄▄▄        "RESET";             \n");
    printf("    /|\\    ______                         "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ ▒ ██▒▒██  ██▒   ▒██▀ ██▌▓█████▄      "RESET";;              \n");
    printf("#\"==(_/o).Z      \\                        "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ ░▄█ ▒ ▒██ ██░   ░██   █▌▒██▒ ▄██     "RESET";';.              \n");
    printf("    / \\           \\                         "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀▀█▄   ░ ▐██▓░   ░▓█▄   ▌▒██░█▀       "RESET";  ;;                \n");
    printf("   /   \\           \\                      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓ ▒██▒ ░ ██▒▓░   ░▒████▓ ░▓█  ▀█▓     "RESET";  ;'               \n");
    printf("   ~    ~          |                      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒▓  ▒ ░▒▓███▀▒     "RESET";  '                     \n");
    printf("                   /                      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒ ░ ▒░▓██ ░▒░     ░ ▒  ▒ ▒░▒   ░      "RESET";                    \n");
    printf("                 __)                      "PINK"░ ░ ░ ░ ░░         ░ ░     ░░   ░ ▒ ▒ ░░       ░ ░    ░    ░ "RESET",;;;,;                               \n");
    printf("                Z__                         "PINK"░ ░    ░ ░                ░     ░ ░            ░    ░      "RESET"`;;;;'                    \n");
    printf("                |()|                      "PINK"░        ░                        ░ ░          ░           ░ "RESET"                   \n");
    printf("                |__|                                                                                                 \n");
    
    // sin 30
    system("cls");
    printf(ZCFRY);
    printf(""PINK"====================================      "PINK"▒███████▒ ▄████▄    █████▒██▀███ ▓██   ██▓   ▓█████▄  ▄▄▄▄           ;"RESET"             \n");
    printf(""PINK"|+--------------------------------+|      "PINK"▒ ▒ ▒ ▄▀░▒██▀ ▀█  ▓██   ▒▓██ ▒ ██▒▒██  ██▒   ▒██▀ ██▌▓█████▄         ;;"RESET"              \n");
    printf(""PINK"||                                ||      "PINK"░ ▒ ▄▀▒░ ▒▓█    ▄ ▒████ ░▓██ ░▄█ ▒ ▒██ ██░   ░██   █▌▒██▒ ▄██        ;';."RESET"              \n");
    printf(""PINK"||   "BRIGHT_YELLOW"WELCOME TO ZICOFARRY DBMS"PINK"    ||        "PINK"▄▀▒   ░▒▓▓▄ ▄██▒░▓█▒  ░▒██▀▀█▄   ░ ▐██▓░   ░▓█▄   ▌▒██░█▀          ;  ;;"RESET"                \n");
    printf(""PINK"||       "BRIGHT_YELLOW"TUGAS MASA DEPAN"PINK"         ||      "PINK"▒███████▒▒ ▓███▀ ░░▒█░   ░██▓ ▒██▒ ░ ██▒▓░   ░▒████▓ ░▓█  ▀█▓        ;  ;'"RESET"               \n");
    printf(""PINK"||    "BRIGHT_YELLOW"DASAR-DASAR PEMROGRAMAN"PINK"     ||      "PINK"░▒▒ ▓░▒░▒░ ░▒ ▒  ░ ▒ ░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒▓  ▒ ░▒▓███▀▒        ;  '"RESET"                     \n");
    printf(""PINK"||             "BRIGHT_YELLOW"2024"PINK"               ||      "PINK"░░▒ ▒ ░ ▒  ░  ▒    ░       ░▒ ░ ▒░▓██ ░▒░     ░ ▒  ▒ ▒░▒   ░         ;"RESET"                    \n");
    printf(""PINK"||                                ||      "PINK"░ ░ ░ ░ ░░         ░ ░     ░░   ░ ▒ ▒ ░░       ░ ░    ░    ░    ,;;;,;"RESET"                               \n");
    printf(""PINK"|+--------------------------------+|        "PINK"░ ░    ░ ░                ░     ░ ░            ░    ░         `;;;;'"RESET"                    \n");
    printf(""PINK"====================================      "PINK"░        ░                        ░ ░          ░           ░    "RESET"                   \n");
    printf("                                                                                 \n");



    sleep(1);
    panduan();
}

// Prosedur Untuk Menampilkan Outro
void outro(){
    printf(BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+"BRIGHT_BLUE"~"BRIGHT_RED"+\n");
    usleep(500000);
    printf(" "BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-"GREEN"-"BRIGHT_YELLOW"-\n");
    usleep(500000);
    printf(PINK"  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    usleep(500000);
    printf("   \\\\        "BRIGHT_YELLOW"SELAMAT TINGGAL DI ZICOFARRY DBMS"PINK"        //\n");
    usleep(500000);
    printf("    \\\\         "BRIGHT_YELLOW"TUGAS MASA DEPAN DASAR-DASAR"PINK"          //\n");
    usleep(500000);
    printf("     \\\\           "BRIGHT_YELLOW"PEMROGRAMAN, DEMI MASA"PINK"            //\n");
    usleep(500000);
    printf("      \\\\             "BRIGHT_YELLOW"DEPAN YANG LEBIH"PINK"              //\n");
    usleep(500000);
    printf("       \\\\                 "BRIGHT_YELLOW"CERAH!!"PINK"                 // \n");
    usleep(500000);
    printf(PINK"        vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"RESET);
    usleep(500000);
    printf(CYAN"         -----------------------------------------\n");
    usleep(500000);
    printf(RED"          ~+~+~+~~+~ "BRIGHT_YELLOW"SEMOGA KITA SEMUA"RED" +~+~+~+~+~\n");
    usleep(500000);
    printf(GREEN"           ~+~+~+~+~+~+ "BRIGHT_YELLOW"MASUK SURGA"GREEN" +~+~+~+~+~+~\n");
    usleep(500000);
    printf(BLUE"            ~+~+~+~+~+~+~+ "BRIGHT_YELLOW"AAMIIN"BLUE" ~+~+~+~+~+~+~\n");
    usleep(500000);
    printf(CYAN"              --------------------------------\n");
    usleep(500000);
    printf(BRIGHT_YELLOW"                vvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
    usleep(500000);
    printf("                  \\\\\\\\\\\\\\\\\\\\\\\\////////////\n");
    usleep(500000);
    printf("                             \\/\n");
    usleep(500000);
    printf("                               \n");
    usleep(500000);
    printf("                             ❤\n"RESET);
}