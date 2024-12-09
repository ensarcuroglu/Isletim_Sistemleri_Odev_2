#include <stdio.h>
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

// Islem 1
void process1() {
    printf("Process 1 calisiyor. PID: %d\n", getpid());
    sleep(2); // bekleme
    printf("Process 1 tamamlandi. PID: %d\n", getpid());
}

// Islem 2
void process2() {
    printf("Process 2 calisiyor. PID: %d\n", getpid());
    sleep(2); // bekleme
    printf("Process 2 tamamlandi. PID: %d\n", getpid());
}

int main() {
    pid_t pid1, pid2;

    printf("Multiprocessing Simulasyonu Basladi. Ana PID: %d\n", getpid());

    
    pid1 = fork(); // Ýlk islem
    if (pid1 == 0) {
        process1();
        return 0;
    }

    pid2 = fork(); // Ikinci islem
    if (pid2 == 0) {
        process2();
        return 0;
    }
    
    wait(NULL); 
    wait(NULL); 

    printf("Multiprocessing Simulasyonu Tamamlandi. Ana PID: %d\n", getpid());
    return 0;
}

