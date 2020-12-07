#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>  // забезпечення відображення кирилиці

using namespace std; 

enum Spesialnist { KN, INF, ME, FI, TN };

string spesialnistStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string prizv;
    int kurs;
    Spesialnist spesialnist;
    int mark_math;
    int mark_phys;
    int mark_inf; 
};

struct Marks {
    int math;
    int phys;
    int inf;
};

void Create(Student *p, const int N);
void Print(Student *p, const int N, Marks &marks, double proc_55);
void Count_4(Student* p, const int N, Marks &marks);
double Proc_55(Student* p, const int N);

int main() {
    // забезпечення відображення кирилиці:
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
    
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;
    Student *p = new Student[N];
    Marks marks = {0, 0, 0};

    Create(p, N);
    double proc_55 = Proc_55(p, N);
    Count_4(p, N, marks);
    Print(p, N, marks, proc_55);

    delete[] p;
   
    return 0;
}

void Create(Student* p, const int N) {
    int spes_number;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();  // очищуємо буфер клавіатури, бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
        cout << "    прізвище: "; 
        getline(cin, p[i].prizv);
        cout << "    курс: "; 
        cin >> p[i].kurs;
        cout << "   спеціальність: (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка,";
        cout << " 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> spes_number;
        p[i].spesialnist = (Spesialnist)spes_number;
        cout << "    оцінка з фізики: ";
        cin >> p[i].mark_phys;
        cout << "    оцінка з математики: ";
        cin >> p[i].mark_math;
        cout << "    оцінка з інформатики: ";
        cin >> p[i].mark_inf;
        cout << endl;
    }
} 

void Print(Student *p, const int N, Marks &marks, double proc_55) {
    cout << "===========================================================================================" << endl;
    cout << "| № |   Прізвище   |  Курс  |      Спеціальність      | Фізика | Математика | Інформатика |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << i + 1 << " ";
        cout << "| " << setw(12) << left << p[i].prizv << " ";
        cout << "|    " << p[i].kurs << "   ";
        cout << "| " << setw(23) << left << spesialnistStr[p[i].spesialnist] << " ";
        cout << "| " << setw(6) << right << p[i].mark_phys << " ";
        cout << "| " << setw(10) << right << p[i].mark_math << " ";
        cout << "| " << setw(11) << right << p[i].mark_inf << " ";
        cout << "|" << endl; 
    }   
    cout << "===========================================================================================" << endl;
    cout << endl;

    cout << "Кількість оцінок ""добре"" з фізики: " << marks.phys << endl;
    cout << "Кількість оцінок ""добре"" з математики: " << marks.math << endl;
    cout << "Кількість оцінок ""добре"" з інформатики: " << marks.inf << endl;

    cout << "Процент студентів, які отримали і з фізики, і з математики оцінку ""5"": " << proc_55 << "%" << endl;
}

void Count_4(Student* p, const int N, Marks &marks) {
    for (int i = 0; i < N; i++) {
        if (p[i].mark_phys == 4) marks.phys++;
        if (p[i].mark_math == 4) marks.math++;
        if (p[i].mark_inf == 4) marks.inf++;
    }
}

double Proc_55(Student* p, const int N) {
    int count_55 = 0;
    for (int i = 0; i < N; i++) {
        if (p[i].mark_phys == 5 && p[i].mark_math == 5) count_55++;
    }
    return 100.0 * count_55 / N;
}
