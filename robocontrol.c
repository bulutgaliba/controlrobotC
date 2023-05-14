#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Robotun mevcut konumunu tutan yapı (struct)
typedef struct {
    int x;
    int y;
} Konum;

// Robot hareketleri
typedef enum {
    Ileri,
    Geri,
    SolaDon,
    SagaDon
} Hareket;

// Robotun hareket etmesini sağlayan fonksiyon
void hareketEt(Konum *konum, Hareket hareket) {
    switch (hareket) {
        case Ileri:
            konum->y += 1;
            break;
        case Geri:
            konum->y -= 1;
            break;
        case SolaDon:
            konum->x -= 1;
            break;
        case SagaDon:
            konum->x += 1;
            break;
        default:
            printf("Hatali giris.\n");
    }
}

// Function that prints the current position of the robot to the screen
void konumYazdir(Konum konum) {
    printf("Robotun konumu: (%d, %d)\n", konum.x, konum.y);
}

int main() {
    Konum konum = {0, 0};  // Initial position of the robot
    srand(time(NULL));  // Random number generation for random movement selection
    bool devam = true;  // Whether the movement of the robot will continue
    int adimSayisi = 0;  // How many steps the robot takes

    while (devam) {
        int rastgeleSayi = rand() % 4;  // Generate a random number between 0-3
        Hareket hareket = rastgeleSayi;  // Convert random number to movement enum
        hareketEt(&konum, hareket);  // Move the robot
        konumYazdir(konum);  // Print the current position of the robot to the screen
        adimSayisi++;  // print the number of names

        if (adimSayisi == 10) {
            printf("Robot hareket etmeyi durdurdu.\n");
            devam = false;
        }
    }

    return 0;
}
