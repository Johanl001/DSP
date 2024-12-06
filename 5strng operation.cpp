#include <iostream>
#include <cstring>
using namespace std;

class Str {
private:
    char s1[100] = "Sanjivani";
    char s2[100] = "Kopargaon";

public:
    void copyString();
    void cmpString();
    void stringlen();
    void concatenate();
    void toUppercase();
    void toLowercase();
    void countDuplicates(const char s[]);
    const char* getS1(); // Getter method for s1
} S;

void Str::copyString() {
    char s3[100];
    int i = 0;
    while (s1[i] != '\0') {
        s3[i] = s1[i];
        i++;
    }
    s3[i] = '\0';
    cout << "Copied String: " << s3 << endl;
}

void Str::cmpString() {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            cout << "Strings are not equal." << endl;
            return;
        }
        i++;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        cout << "Strings are equal." << endl;
    } else {
        cout << "Strings are not equal." << endl;
    }
}

void Str::stringlen() {
    int len1 = 0, len2 = 0;
    while (s1[len1] != '\0') len1++;
    while (s2[len2] != '\0') len2++;

    cout << "Length of s1: " << len1 << endl;
    cout << "Length of s2: " << len2 << endl;
}

void Str::concatenate() {
    char result[200];
    int len1 = 0, len2 = 0, i;

    while (s1[len1] != '\0') len1++;
    while (s2[len2] != '\0') len2++;

    for (i = 0; i < len1; i++) {
        result[i] = s1[i];
    }
    for (int j = 0; j <= len2; j++, i++) {
        result[i] = s2[j];
    }

    cout << "Concatenated String: " << result << endl;
}

void Str::toUppercase() {
    char upper[100];
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            upper[i] = s1[i] - 32;
        } else {
            upper[i] = s1[i];
        }
        i++;
    }
    upper[i] = '\0';
    cout << "Uppercase s1: " << upper << endl;
}

void Str::toLowercase() {
    char lower[100];
    int i = 0;
    while (s1[i] != '\0') {
        if (s1[i] >= 'A' && s1[i] <= 'Z') {
            lower[i] = s1[i] + 32;
        } else {
            lower[i] = s1[i];
        }
        i++;
    }
    lower[i] = '\0';
    cout << "Lowercase s1: " << lower << endl;
}

void Str::countDuplicates(const char s[]) {
    int count[256] = {0}, i = 0;
    while (s[i] != '\0') {
        count[s[i]]++;
        i++;
    }
    cout << "Duplicate characters:" << endl;
    for (i = 0; i < 256; i++) {
        if (count[i] > 1) {
            cout << (char)i << ": " << count[i] << endl;
        }
    }
}

const char* Str::getS1() {
    return s1;
}

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Copy String\n";
        cout << "2. Compare Strings\n";
        cout << "3. String Length\n";
        cout << "4. Concatenate Strings\n";
        cout << "5. Convert to Uppercase\n";
        cout << "6. Convert to Lowercase\n";
        cout << "7. Count Duplicate Characters in s1\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: S.copyString(); break;
            case 2: S.cmpString(); break;
            case 3: S.stringlen(); break;
            case 4: S.concatenate(); break;
            case 5: S.toUppercase(); break;
            case 6: S.toLowercase(); break;
            case 7: S.countDuplicates(S.getS1()); break; // Access s1 using getter
            case 8: return 0;
            default: cout << "Invalid choice. Try again." << endl;
        }
    }
}
