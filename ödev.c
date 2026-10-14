#include <stdio.h>

int main() {
    float urun_tutari, odenen_para;
    
    printf("Urun tutarini giriniz (TL): ");
    scanf("%f", &urun_tutari);
    
    printf("Odenen parayi giriniz (TL): ");
    scanf("%f", &odenen_para);
    
    if (odenen_para < urun_tutari) {
        printf("Hata: Odenen para urun tutarindan kucuk olamaz!\n");
        return 1;
    }
    
    int para_ustu_kurus = (int)((odenen_para - urun_tutari) * 100 + 0.5);
    int toplam_kupur = 0;
    int miktar;
    
    printf("\n--- PARA USTU DETAYLARI ---\n");
    printf("Verilecek Toplam Para Ustu: %.2f TL (%d kurus)\n\n", (float)para_ustu_kurus / 100, para_ustu_kurus);
    
    int kupurler[] = {20000, 10000, 5000, 2000, 1000, 500, 100, 50, 25, 10, 5, 1};
    char *isimler[] = {
        "200 TL Banknot", "100 TL Banknot", "50 TL Banknot", "20 TL Banknot", 
        "10 TL Banknot", "5 TL Banknot", "1 TL Madeni Para", 
        "50 Kurus Madeni Para", "25 Kurus Madeni Para", "10 Kurus Madeni Para", 
        "5 Kurus Madeni Para", "1 Kurus Madeni Para"
    };
    
    int i; // Değişkeni döngünün dışında tanımladık
    for (i = 0; i < 12; i++) {
        if (para_ustu_kurus >= kupurler[i]) {
            miktar = para_ustu_kurus / kupurler[i];
            para_ustu_kurus %= kupurler[i];
            toplam_kupur += miktar;
            printf("%d adet %s\n", miktar, isimler[i]);
        }
    }
    
    printf("\nMusteriye Verilen Toplam Kupur/Madeni Para Sayisi: %d\n", toplam_kupur);
    
    return 0;
}
