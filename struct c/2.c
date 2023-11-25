#include <stdio.h>
#include <string.h>

struct StudentRecord 
{
    char Name[15];
    char Id[15];
    char Dept[10];
    char Gender[10];
};

int main() {
    struct StudentRecord student;

    // Mengisi nilai variabel-variabel dalam struct
    strcpy(student.Name, "Dio Ramadhan");
    strcpy(student.Id, "1234567");
    strcpy(student.Dept, "DTIK");
    strcpy(student.Gender, "Pria");

    // Menampilkan nilai dari struct
    printf("Nama: %s\n", student.Name);
    printf("Id : %s\n", student.Id);
    printf("Dept : %s\n", student.Dept);
    printf("Gender : %s\n", student.Gender);

    return 0;
}