#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

struct Kitap {
    string ad;
    string yazar;
    int yil;
    float fiyat;
};

class Kutuphane {
private:
    string dosya_adi;
public:

    int kitap_listele() {
        ifstream dosya("kitaplar.txt");

        if (!dosya.is_open()) {
            cout << "Dosya açılamadı!" << endl;
            return 1;
        }
        int satirNo = 1;

        string satir;
        while (getline(dosya, satir)) {
            cout << satirNo << ". " << satir << endl;
            satirNo++;
        }

        dosya.close();
    }

    void kitap_ekle(Kitap yeni_kitap) {
        cout << "Kitap Adı: ";
        getline(cin, yeni_kitap.ad);

        cout << "Yazar: ";
        getline(cin, yeni_kitap.yazar);

        cout << "Yıl: ";
        cin >> yeni_kitap.yil;

        cout << "Fiyat: ";
        cin >> yeni_kitap.fiyat;

        cin.ignore();
        ofstream dosya("kitaplar.txt", ios::app);

        if (!dosya.is_open()) {
            cout << "Dosya açılamadı!" << endl;
            return;
        }

        dosya << yeni_kitap.ad << ", " << yeni_kitap.yazar << ", " << yeni_kitap.yil << ", " << yeni_kitap.fiyat << endl;
        dosya.close();

        cout << "Kitap başarıyla eklendi. Güncel kitap listesi:" << endl;
        kitap_listele();
    }
};

class Otomasyon : public Kutuphane {
public:
    void menu_goster() {
        cout << "====================" << endl;
        cout << "1. Kitapları Listele" << endl;
        cout << "2. Kitap Ekle" << endl;
        cout << "3. Çıkış" << endl;
        cout << "====================" << endl;

        int secim;
        cout << "Seçiminizi yapın: ";
        cin >> secim;
        cin.ignore();
        system("cls");

        switch (secim) {
        case 1:
            this->kitap_listele();
            break;
        case 2:
        {
            Kitap yeni_kitap;
            this->kitap_ekle(yeni_kitap);
        }
        break;
        case 3:
            cout << "Programdan çıkılıyor..." << endl;
            return;
            break;
        default:
            cout << "Geçersiz seçim! Lütfen tekrar deneyin." << endl;
            break;
        }
    }

    void calistir() {
        while (true) {
            menu_goster();
        }
    }
};

int main() {
    setlocale(LC_ALL, "Turkish");
    Otomasyon otomasyon;
    otomasyon.calistir();
    return 0;
}
