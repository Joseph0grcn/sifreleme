#define _CRT_SECURE_NO_WARNINGS // Uyar�y� devre d��� b�rak�r
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Harfler ve de�erleri e�le�tiren diziler olu�turmak
char harfler[] = { 'A', 'B', 'C', '�', 'D', 'E', 'F', 'G', '�', 'H',
                  'I', '�', 'J', 'K', 'L', 'M', 'N', 'O', '�', 'P',
                  'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int harfDegerleri[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                       11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                       21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };



int harfIndexBul(char harf) {
    for (int i = 0; i < 30; ++i) {
        if (-90 == harf) {
            return 8;
        }
        else if (-104 == harf) {
            return 11;
        }
        else if (-103 == harf) {
            return 18;
        }
        else if (-128 == harf) {
            return 3;
        }
        else if(harfler[i] == harf){
            return i;
        }
    }
    return -1; // Bulunamazsa -1 d�ner
}

void sifrele(char kelime[100],int sayi) {
    

    // Yeni kelimeyi olu�turmak i�in bir de�i�ken tan�mlayal�m
    char yeniKelime[100];
    int i = 0;

    // Her harfi d�n��t�rmek
    while (kelime[i] != 0) {
        int index = harfIndexBul(kelime[i]);
        if (index != -1) {
            int yeniDeger = (harfDegerleri[index] + sayi) % 30;
            if (yeniDeger == 0) {
                yeniDeger = 30;
            }
            yeniKelime[i] = harfler[yeniDeger - 1];
        }
        else {
            if (kelime[i] == '�') {
                yeniKelime[i] = '�';
                
            }
            else if (kelime[i] == -98) {
                yeniKelime[i] = '�';
                
            }
            else {
                yeniKelime[i] = kelime[i];
            }
            
        }
        i++;
    }
    yeniKelime[i] = 0;

    // Yeni kelimeyi ekrana yazd�rmak
    printf("Sifrelenmis kelimeniz: %s\n", yeniKelime);
}

void sifrecozme() {
    // Kullan�c�dan kelime ve say� almak
    char kelime[100];
    int sayi;

    printf("Sifreli bir kelime giriniz: ");
    scanf("%s", kelime);
    printf("Sifre sayisini giriniz: ");
    scanf("%d", &sayi);

    // Yeni kelimeyi olu�turmak i�in bir de�i�ken tan�mlayal�m
    char yeniKelime[100];
    int i = 0;

    // Her harfi d�n��t�rmek
    while (kelime[i] != 0) {
        int index = harfIndexBul(kelime[i]);
        if (index != -1) {
            int yeniDeger = (harfDegerleri[index] - sayi) % 30;
            if (yeniDeger <= 0) {
                yeniDeger += 30;
            }
            yeniKelime[i] = harfler[yeniDeger - 1];
        }
        else {
            if (kelime[i] == '�') {
                yeniKelime[i] = '�';

            }
            else if (kelime[i] == -98) {
                yeniKelime[i] = '�';

            }
            else {
                yeniKelime[i] = kelime[i];
            }
        }
        i++;
    }
    yeniKelime[i] = 0;

    // Yeni kelimeyi ekrana yazd�rmak
    printf("Sifresi cozulmus kelimeniz: %s\n", yeniKelime);
}

int main() {
    // T�rk�e karakterler i�in locale ayar�
    setlocale(LC_ALL, "Turkish");

    int a = 0;
    while (a != 9) {
        printf("�ifreleme yapacaksan�z -->1\n�ifre ��zecekseniz ------>2\n��k�� i�in -------------->9\nGiriniz  :");
        scanf("%d", &a);
        switch (a) {
        case 1:
            // Kullan�c�dan kelime ve say� almak
            char kelime[100];
            int sayi;

            printf("Bir kelime giriniz: ");
            scanf("%s", kelime);
            printf("Bir sayi giriniz: ");
            scanf("%d", &sayi);
            sifrele(kelime,sayi);
            break;
        case 2:
            sifrecozme();
            break;
        case 9:
            exit(0);
        default:
            a = 0;
            break;
        }
    }
}