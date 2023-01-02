#include "palindrome.h"

// primitif stack
void createStack(stack &s){
    top(s) = -1;
}

bool isEmptyStack(stack s){
    if (top(s) == -1){
        return true;
    } else {
        return false;
    }
}

bool isFullStack(stack s){
    if (top(s) == 20){
        return true;
    } else {
        return false;
    }
}

void push(stack &s, infotypeS x){
    if (isFullStack(s) == false){
        top(s)++;
        infoS(s)[top(s)] = x;
    }
}

infotypeS pop(stack &s){
    infotypeS x;
    x = infoS(s)[top(s)];
    top(s)--;
    return x;
}

infotypeS popAll(stack &s) {
    while (top(s) >= 0) {
        pop(s);
    }
}

void printStack(stack s){
    for (int i = top(s); i >= 1; i--){
        cout << infoS(s)[i] << " ";
    }
    cout << endl;
}

// queue
void createQueue(queue &q){
    head(q) = nil;
    tail(q) = nil;
}

void createElmQ(infotypeQ x, adrQ &pKata){
    pKata = new elmQ;
    infoQ(pKata) = x;
    next(pKata) = nil;
}
void enqueue(queue &q, adrQ pKata){
    if (head(q) == nil){
        head(q) = pKata;
        tail(q) = pKata;
    } else {
        next(tail(q)) = pKata;
        tail(q) = pKata;
    }
}

void dequeue(queue &q, adrQ &pKata){
    if (head(q) != nil){
        pKata = head(q);
        head(q) = next(pKata);
        next(pKata) = nil;
    } else {
        cout << "Antrian Kosong!" << endl;
    }
}

void printQueue(queue q){
    adrQ pKata = head(q);
    while (pKata != nil){
        cout << infoQ(pKata) << "\t";
        pKata = next(pKata);
    }
}

bool isPalindrome(stack &s) {
    stack tmpS, tmpS2;
    createStack(tmpS);
    createStack(tmpS2);
    int pos = top(s);
    int bottomPos = 0;
    bool palindrome = true;
    while (pos > bottomPos) {

        while (top(s) >= pos) {
            push(tmpS, infoS(s)[top(s)]);
            pop(s);
        }

        while (top(s) >= bottomPos) {
            push(tmpS2, infoS(s)[top(s)]);
            pop(s);
        }

        palindrome = palindrome && infoS(tmpS2)[top(tmpS2)] == infoS(tmpS)[top(tmpS)];

        if (palindrome == false) {
            return false;
        }

        while (top(tmpS2) >= 0) {
            push(s, infoS(tmpS2)[top(tmpS2)]);
            pop(tmpS2);
        }

        while (top(tmpS) >= 0) {
            push(s, infoS(tmpS)[top(tmpS)]);
            pop(tmpS);
        }

        pos--;
        bottomPos++;
    }

    return palindrome;
}

void cekAllQueue(queue q, stack &s) {
    if (head(q) == nil) {
        cout << "Antrian kosong" << endl;
    } else {
        adrQ pKata = head(q);
        while (pKata != nil) {
            infotypeS karakter;
            bool palindrome;
            for (int i=0;i<infoQ(pKata).length();i++) {
                karakter = infoQ(pKata)[i];
                push(s,karakter);
            }

            palindrome = isPalindrome(s);
            popAll(s);

            cout << "Apakah kata (" << infoQ(pKata) << ") merupakan palindrome? ";
            if (palindrome) {
                cout << "Iya" << endl;
            } else {
                cout << "Tidak" << endl;
            }
            pKata = next(pKata);
        }
    }
}
