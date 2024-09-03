#include "pref.h"

int main(){
    int x;
    string infix;
    int pilihan = 0;

    cout << "=================== KALKULATOR A ===================" << endl << endl;
    cout << "\t\tDisusun Oleh : " << endl <<endl;
    cout << "1. Fadhillah Maulana - 1303210039" << endl;
    cout << "2. Irfan Zharauri Nanda Sudiyanto - 1303210006" << endl << endl;

    pilihan = selectMenu();

    while (pilihan != 0) {
        if (pilihan == 1) {
            cout << "Ekspresi Yang Bisa Digunakan (+) - (-) - (*) - (/) - (^) - (%)" << endl;
            cout << "Masukkan Ekspresi Infix Yang Diinginkan : "; cin >> infix;

            // Ada Kondisi Untuk Membatasi Inputan

            for (int i = 0; i < infix.length(); i++) {
                if (!isOperator(infix[i]) && !isdigit(infix[i])) {
                    {
                        cout << endl;
                        cout << "Ekspresi Tidak Valid" << endl;
                        break;
                    }
                }
            }

            cout << endl;
            char masukkan_1;
            cout << "Kembali Ke Menu Utama? (Y/N) : "; cin >> masukkan_1;
            system("CLS");

            if (masukkan_1 == 'Y' || masukkan_1 == 'y') {
                pilihan = selectMenu();
            } else {
                break;
            }

        } else if (pilihan == 2) {
            cout << "Ekspresi Prefix Setelah Konversi :  " << infixToPrefix(infix) << endl << endl;

            char masukkan_2;
            cout << "Kembali Ke Menu Utama? (Y/N) : "; cin >> masukkan_2;
            system("CLS");

            if (masukkan_2 == 'Y' || masukkan_2 == 'y') {
                pilihan = selectMenu();
            } else {
                break;
            }

        } else if (pilihan == 3) {
            // Keluarkan hasil ekspresi prefix dengan 2 angka di belakang koma
            printf("Hasil Operasi Aritmatika : %.2f", calculatePrefix(infixToPrefix(infix)));
            cout << endl << endl;

            char masukkan_3;
            cout << "Kembali Ke Menu Utama? (Y/N) : "; cin >> masukkan_3;
            system("CLS");

            if (masukkan_3 == 'Y' || masukkan_3 == 'y') {
                pilihan = selectMenu();
            } else {
                break;
            }
        }
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;

    return 0;
}
