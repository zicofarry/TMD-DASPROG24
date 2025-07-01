/*Saya Muhammad 'Azmi Salam mengerjakan evaluasi Tugas Masa
Depan dalam mata kuliah Dasar-dasar Pemrograman untuk
keberkahanNya maka saya tidak melakukan kecurangan seperti
yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>   // deklarasi library yang akan digunakan
#include <string.h>  // deklarasi library yang akan digunakan

// DEKLARASI MAKRO
// ANSI escape codes untuk mengubah warna teks dan latar belakang
#define RESET               "\033[0m"      // Reset warna ke default
#define BLACK               "\033[30m"     // Teks hitam
#define RED                 "\033[31m"     // Teks merah
#define GREEN               "\033[32m"     // Teks hijau
#define YELLOW              "\033[33m"     // Teks kuning
#define BLUE                "\033[34m"     // Teks biru
#define MAGENTA             "\033[35m"     // Teks magenta
#define PINK                "\033[1;35m"   // Teks pink
#define CYAN                "\033[36m"     // Teks cyan
#define WHITE               "\033[37m"     // Teks putih
#define BOLD                "\033[1m"      // Membuat teks tebal
#define BRIGHT_RED          "\033[91m"     // Merah Terang
#define BRIGHT_GREEN        "\033[92m"     // Hijau Terang
#define BRIGHT_YELLOW       "\033[93m"     // Kuning Terang
#define BRIGHT_BLUE         "\033[94m"     // Biru Terang
#define BRIGHT_CYAN         "\033[96m"     // Cyan Terang
// Untuk menampilkan sesuai kursor yang diinginkan
#define ZCFRY               "\033[1;1H"    // Line 1
#define INPUT               "\033[1;22H"   // Line Input
#define LINE2               "\033[2;1H"    // Line 2
#define RESULT              "\033[4;3H"    // Line Resulit
#define TABEL               "\033[7;1H"    // Line Tabel

// deklarasi tipe bungkusan data
typedef struct{// Untuk Data Kasus
    //kode primary
    char idKasus[5];
    char idSin[5];
    char idHakim[5];
    char idGedung[5];
    //nama
    char nama[51];
    char kejahatan[51];
    char hukuman[51];
    char hakim[51];
    char gedung[51];
} data;

typedef struct{// Untuk Data Sin
    char kode[5];
    char kejahatan[51];
    char hukuman[51];
} sin;

typedef struct{// Untuk Data Hakim/ Gedung
    char kode[5];
    char nama[51];
} hg;

typedef struct{// Untuk Tabel
    int idKasus;
    int idSin;
    int idHakim;
    int idGedung;
    int nama;
    int kejahatan;
    int hukuman;
    int hakim;
    int gedung;
}tabel;


// DEKLARASI VARIABEL GLOBAL
int idx;                // Index dari karakter terakhir pada kata
int wlen;               // Panjang kata (word length)
char cc;                // Karakter saat ini (current character)
char cw[50];            // Kata saat ini (current word)
int nonterm;            // Mode Saat ini (Terminal/ Non-Terminal)
char tape[501];         // Pita Masukan

// Fungsi Mesin Karakter
int EOP();
void START(char pita[]);
void INC(char pita[]);
char GETCC();

// Fungsi Mesin Kata
int eop(char pita[]);
void start(char pita[]);
void reset();
void inc(char pita[]);
void dec(char pita[]);
char* getcw();
int getlen();
int countw(char pita[]);
int wordnow(char pita[]);
int cekEOP(char pita[]);
int lastw(char pita[]);

// Fungsi Mesin Pita (Untuk Multiple Query)
int ctape(char pita[]);
void pisahtape(char pita[], char tmp[51][101]);

// Fungsi Write File
void write_IdKasus(int n, data source[], char fileName[]);
void write_Kasus(int n, data source[], char fileName[]);
void write_IdKasus_Kasus(int n, data source[], char fileName[]);
void write_Sin(int n, sin source[], char fileName[]);
void write_HG(int n, hg source[], char fileName[]);

// Fungsi Read File
void read_IdKasus(int *n, data source[], char fileName[]);
void read_Kasus(int *n, data source[], char fileName[]);
void read_IdKasus_Kasus(int *n, data source[], char fileName[]);
void read_Sin(int *n, sin source[], char fileName[]);
void read_HG(int *n, hg source[], char fileName[]);

// Prosedur Menampilkan Success/ Error
void SUCCESS(int n);
void ERROR(int n);

// Fungsi Memodifikasi Data
void modify_Sin(char str[], sin *tmp, int *n, data kasus[], int k);
void modify_HG(char str[], hg *tmp, int *n, data kasus[], int k);
void modify_Kasus(char str[], data *kasus, int *k, sin sin[], int s, hg hakim[], int h, hg gedung[], int g);

// Fungsi Join
void join(int k, data kasus[], int s, sin sin[], int h, hg hakim[], int g, hg gedung[]);

// Fungsi Mengubah String Number Menjadi Int dan Panjang Int
int str_to_int(char str[]);
int intlen(int n);

// Prosedur Menampilkan Tabel
void clear();
void tabel_Sin(char pita[], int n, sin *str);
void tabel_HG(char pita[], int n, hg *str);
void tabel_Kasus(char pita[], int k, data kasus[], int s, sin sin[], int h, hg idHakim[], int g, hg idGedung[]);
void tabel_KasusComplete(char pita[], int n, data *str);

// Prosedur Proses Query Pita
void query(char tape[]);
void dbms();