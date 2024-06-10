# sifreleme

PROGRAM DETAYI:
|  1  |  A  | 11  |  I  | 21  |  Q  |
|  2  |  B  | 12  |  İ  | 22  |  R  |
|  3  |  C  | 13  |  J  | 23  |  S  |
|  4  |  Ç  | 14  |  K  | 24  |  T  |
|  5  |  D  | 15  |  L  | 25  |  U  |
|  6  |  E  | 16  |  M  | 26  |  V  |
|  7  |  F  | 17  |  N  | 27  |  W  |
|  8  |  G  | 18  |  O  | 28  |  X  |
|  9  |  Ğ  | 19  |  Ö  | 29  |  Y  |
| 10  |  H  | 20  |  P  | 30  |  Z  |

Şifreleme işlemi tablodaki harfin sayısal değerinin girilen sayı kadar artırılması ile ulaşılan sayının karşılık geldiği harfin önceki harf ile değiştirilmesi şeklinde yapılmaktadır. 
A harfinin sayısal değeri 1’dir. Eğer A harfini 4 ile şifrelersek 1+4=5 olduğundan tabloda 5’e karşılık gelen D harfi, A harfinin 4 ile şifrelenmesi sonucu oluşan şifrelenmiş harftir.
A harfinin sayısal değeri 1’dir. Eğer A harfini 32 ile şifrelersek 32+1=33 olduğundan ve tablo şifreleme yaparken son sayıdan sonra başa döndüğünden tabloda 3’e karşılık gelen C harfi, A harfinin 32 ile şifrelenmesi sonucu oluşan şifrelenmiş harftir. 

Şifre çözme işlemi tablodaki harfin sayısal değerinin girilen sayı kadar azaltılması ile ulaşılan sayının karşılık geldiği harfin önceki harf ile değiştirilmesi şeklinde yapılmaktadır.
E harfinin sayısal değeri 6’dır. Eğer E harfini 3 ile şifre çözme yaparsak 6-3=3 olduğundan tabloda 3’e karşılık gelen C harfi, E harfinin 3 ile şifresinin çözülmesi sonucu oluşan çözülmüş harftir.
E harfinin sayısal değeri 6’dır. Eğer E harfini 10 ile şifre çözme yaparsak 6-10=-4 olduğundan ve tablo şifre çözme yaparken 1 den geriye giderken 30 a geçtiğinden tabloda 30-4’e karşılık gelen 26 yani V harfi, E harfinin 10 ile şifresinin çözülmesi sonucu oluşan çözülmüş harftir.

Program akışı
1) Kullanıcıya şifrelememi yapacağı, şifrelenmiş metin mi çözeceği sorulacaktır.
2) Kullanıcıdan bir metin yazması istenecektir. (Şifrelenecek veya şifresi çözülecek metin)
3) Kullanıcıdan bir sayı yazması istenecektir. (Öteleme veya geri öteleme miktarı)
4) Ekranda ilk birinci adımdaki seçime göre şifrelenmiş metin veya şifresi çözülmüş metin gösterilecektir.

   Örnek Akış 1:
Bilgisayar:
Şifreleme yapacaksanız 1, şifre çözecekseniz 2 giriniz.

Kullanıcı:
1

Bilgisayar:
Şifrelenecek metin girin.

Kullanıcı:
FURKAN

Bilgisayar:
Şifreleme sayısını girin.

Kullanıcı:
2

Bilgisayar:
ĞWTMCÖ


```
#define _CRT_SECURE_NO_WARNINGS // Uyarıyı devre dışı bırakır

#include <stdio.h>

#include <stdlib.h>

#include <locale.h>


// Harfler ve değerleri eşleştiren diziler oluşturmak
char harfler[] = { 'A', 'B', 'C', 'Ç', 'D', 'E', 'F', 'G', 'Ğ', 'H',
                  'I', 'İ', 'J', 'K', 'L', 'M', 'N', 'O', 'Ö', 'P',
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
    return -1; // Bulunamazsa -1 döner
}

void sifrele(char kelime[100],int sayi) {
    

    // Yeni kelimeyi oluşturmak için bir değişken tanımlayalım
    char yeniKelime[100];
    int i = 0;

    // Her harfi dönüştürmek
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
            if (kelime[i] == 'š') {
                yeniKelime[i] = 'Ü';
                
            }
            else if (kelime[i] == -98) {
                yeniKelime[i] = 'Ş';
                
            }
            else {
                yeniKelime[i] = kelime[i];
            }
            
        }
        i++;
    }
    yeniKelime[i] = 0;

    // Yeni kelimeyi ekrana yazdırmak
    printf("Sifrelenmis kelimeniz: %s\n", yeniKelime);
}

void sifrecozme() {
    // Kullanıcıdan kelime ve sayı almak
    char kelime[100];
    int sayi;

    printf("Sifreli bir kelime giriniz: ");
    scanf("%s", kelime);
    printf("Sifre sayisini giriniz: ");
    scanf("%d", &sayi);

    // Yeni kelimeyi oluşturmak için bir değişken tanımlayalım
    char yeniKelime[100];
    int i = 0;

    // Her harfi dönüştürmek
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
            if (kelime[i] == 'š') {
                yeniKelime[i] = 'Ü';

            }
            else if (kelime[i] == -98) {
                yeniKelime[i] = 'Ş';

            }
            else {
                yeniKelime[i] = kelime[i];
            }
        }
        i++;
    }
    yeniKelime[i] = 0;

    // Yeni kelimeyi ekrana yazdırmak
    printf("Sifresi cozulmus kelimeniz: %s\n", yeniKelime);
}

int main() {
    // Türkçe karakterler için locale ayarı
    setlocale(LC_ALL, "Turkish");

    int a = 0;
    while (a != 9) {
        printf("Şifreleme yapacaksanız -->1\nŞifre çözecekseniz ------>2\nÇıkış için -------------->9\nGiriniz  :");
        scanf("%d", &a);
        switch (a) {
        case 1:
            // Kullanıcıdan kelime ve sayı almak
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
```
