#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur bankaccount
struct bankaccount {
    char nama[15];
    char AccountNo[10];
    double datebirthday;
};

int main() {
    // Mendeklarasikan variabel bertipe struct bankaccount
    struct bankaccount user;

    // Mengisi nilai variabel-variabel dalam struct
    strcpy(user.nama, "John Doe");
    strcpy(user.AccountNo, "1234567");
    user.datebirthday = 22.0;

    // Menampilkan nilai dari struct
    printf("Nama: %s\n", user.nama);
    printf("Account no : %s\n", user.AccountNo);
    printf("Tanggal lahir: %.2f\n", user.datebirthday);

    return 0;
}
