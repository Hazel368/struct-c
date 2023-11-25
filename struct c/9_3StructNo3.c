#include <stdio.h>
#include <stdlib.h>
#define MAX 3

struct Mahasiswa
{
    char nama[30];
    int tugas, uts, uas;
} data[MAX]; // by reference --> ada pointer

// input data
void masukkanData(struct Mahasiswa *data, int N) // --> pointer
{
    int i = 0;
    puts("\nMasukkan Data Mahasiswa");
    while (i < N)
    {
        printf("\nMahasiswa ke-%d\n", i + 1);
        printf("Nama : ");
        fflush(stdin);
        gets(data[i].nama);

        printf("Nilai Tugas : ");
        scanf("%d", &data[i].tugas);
        printf("Nilai UTS : ");
        scanf("%d", &data[i].uts);
        printf("Nilai UAS : ");
        scanf("%d", &data[i].uas);
        i++;
    }
}

// menghitung rata-rata
double hitungRata(struct Mahasiswa *data, int indeks) // --> pointer
{
    return (0.2 * data[indeks].tugas + 0.3 * data[indeks].uts + 0.5 * data[indeks].uas);
}

// mengelompokkan nilai
char dapatkanGrade(double nilai)
{
    if (nilai >= 90)
        return 'A';
    else if (nilai >= 80)
        return 'B';
    else if (nilai >= 70)
        return 'C';
    else if (nilai >= 50)
        return 'D';
    else
        return 'E';
}

// kondisi untuk nilai rata-rata
int dapatkanIndeksMaksimum(struct Mahasiswa *data, int N) // --> pointer 
{
    int i = 0, hasil = 0;
    double maksimum = 0;
    while (i < N)
    {
        if (hitungRata(data, i) > maksimum)
        {
            maksimum = hitungRata(data, i);
            hasil = i;
        }
        i++;
    }
    return hasil;
}

// mencetak tabel
void cetak(struct Mahasiswa *data, int N) // --> pointer 
{
    system("cls");
    puts("DAFTAR NILAI");
    puts("MATAKULIAH KONSEP PEMROGAMAN");
    puts("==========================================================================");
    printf("No\t Nama\t\t\t Nilai\t\t\t Grade\n");
    printf("\t Mahasiswa\t Tugas\t UTS\t UAS\t Akhir\n");
    puts("==========================================================================");
    int i = 0;
    while (i < N)
    {
        printf("%d\t %s\t\t %-2d\t %-2d\t %-2d\t %-4.2lf\t   %c\n", i + 1, data[i].nama, data[i].tugas, data[i].uts, data[i].uas, hitungRata(data, i),
               dapatkanGrade(hitungRata(data, i)));
        i++;
    }
    puts("==========================================================================");
    printf("Total Mahasiswa = %d\n", i);
    printf("\nNilai Tertinggi\n");
    printf("Nama : %s\n", data[dapatkanIndeksMaksimum(data, N)].nama);
    printf("Nilai : %4.2lf\n", hitungRata(data, dapatkanIndeksMaksimum(data, N)));
}

int main()
{
    masukkanData(data, MAX);
    cetak(data, MAX);
    return 0;
}
