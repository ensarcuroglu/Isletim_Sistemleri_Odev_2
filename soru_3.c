#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h> 

// Çoklu Programlama
void multiprogramming() {
    printf("Coklu Programlama (Multiprogramming) Basladi");
    for (int i = 0; i < 5; i++) {
        printf("Program 1 (Multiprogramming): Adim %d. PID: %d\n", i + 1, getpid());
        sleep(1); // bekleme
        printf("Program 2 (Multiprogramming): Adim %d. PID: %d\n", i + 1, getpid());
        sleep(1); // bekleme
    }
    printf("Coklu Programlama (Multiprogramming) Tamamlandi");
}

// Çoklu Ýþlemci
void multiprocessing() {
    printf("Coklu Islemci (Multiprocessing) Basladi");
    pid_t pid1, pid2;

    // Islem 1
    pid1 = fork();
    if (pid1 == 0) {
    	// Process 1
        for (int i = 0; i < 5; i++) {
            printf("Process 1 (Multiprocessing): Adim %d. PID: %d\n", i + 1, getpid());
            sleep(1);
        }
        return;
    }

    // Islem 2
    pid2 = fork();
    if (pid2 == 0) {
        // Process 2
        for (int i = 0; i < 5; i++) {
            printf("Process 2 (Multiprocessing): Adim %d. PID: %d\n", i + 1, getpid());
            sleep(1);
        }
        return;
    }

    // Ana islem
    wait(NULL);
    wait(NULL);
    printf("Coklu Islemci (Multiprocessing) Tamamlandi");
}

int main() {
    printf("Coklu Programlama ve Coklu Islemci Basladi. Ana PID: %d\n", getpid());

    
    multiprogramming();

    multiprocessing();

    printf("Coklu Programlama ve Coklu Islemci Tamamlandi.\n");
    return 0;
}

