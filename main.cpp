#include "palindrome.h"

int main()
{
    char* huruf;
    infotypeS letter;
    infotypeQ kata;
    stack s;
    queue q;
    adrQ pKata;
    int n,i;
    string iKata;

    createStack(s);
    createQueue(q);

    cout << "Periksa apakah kata berikut palindrom?" << endl;
    cout << "===================================================" << endl;
    cout << "Masukkan jumlah kata yang ingin diperiksa: ";
    cin >> n;
    cout << endl;
    i = 1;
    while(n > 0){
        cout << "Kata ke-"<< i << ": ";
        cin >> iKata;
        createElmQ(iKata, pKata);
        enqueue(q, pKata);
        n--;
        i++;
    }

    cout << endl;
    cout << "=============Hasil Periksa Palindrome==============" << endl;
    cekAllQueue(q,s);
    cout << "===================================================" << endl;
}
