#include <stdio.h>
#include <unistd.h> 

// Program 1
void program1() {
    printf("Program 1 calisiyor...\n");
    sleep(1);
}

// Program 2
void program2() {
    printf("Program 2 calisiyor...\n");
    sleep(1);
}

int main() {
    
    int i;
	printf("Coklu Programlama Basladi\n");

    for (i = 0; i < 5; i++) {
        program1(); // Program 1 çalýþýyor
        program2(); // Program 2 çalýþýyor
    }

    printf("Coklu Programlama Simulasyonu Tamamlandi.\n");
    return 0;
}
