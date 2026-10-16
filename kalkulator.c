#include <stdio.h>

#define PI 3.14159265358979

/* ---------- Fungsi-fungsi operasi ---------- */
double tambah(double a, double b) {
    return a + b;
}

double kurang(double a, double b) {
    return a - b;
}

double kali(double a, double b) {
    return a * b;
}

double bagi(double a, double b) {
    return a / b;
}

double luas_lingkaran(double r) {
    return PI * r * r;
}

/* ---------- Fungsi tampilan menu ---------- */
void tampilkan_menu() {
    printf("\n===== KALKULATOR =====\n");
    printf("1. Penjumlahan\n");
    printf("2. Pengurangan\n");
    printf("3. Perkalian\n");
    printf("4. Pembagian\n");
    printf("5. Luas Lingkaran\n");
    printf("0. Keluar\n");
}

void input_dua_angka(double *a, double *b) {
    printf("Masukkan angka pertama : ");
    scanf("%lf", a);
    printf("Masukkan angka kedua   : ");
    scanf("%lf", b);
}

/* ---------- Program utama ---------- */
int main() {
    int pilihan;
    double a, b, r, hasil;

    do {
        tampilkan_menu();
        printf("Pilih menu (0-5): ");
        if (scanf("%d", &pilihan) != 1) {
            /* input bukan angka: buang sisa input lalu ulangi */
            while (getchar() != '\n');
            printf("Input harus berupa angka!\n");
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
            case 1:
                input_dua_angka(&a, &b);
                hasil = tambah(a, b);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 2:
                input_dua_angka(&a, &b);
                hasil = kurang(a, b);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 3:
                input_dua_angka(&a, &b);
                hasil = kali(a, b);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 4:
                input_dua_angka(&a, &b);
                if (b == 0) {
                    printf("Error: pembagian dengan nol tidak diperbolehkan\n");
                } else {
                    hasil = bagi(a, b);
                    printf("Hasil: %.2f\n", hasil);
                }
                break;
            case 5:
                printf("Masukkan jari-jari (r): ");
                scanf("%lf", &r);
                hasil = luas_lingkaran(r);
                printf("Hasil: %.2f\n", hasil);
                break;
            case 0:
                printf("Terima kasih, program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    } while (pilihan != 0);

    return 0;
}