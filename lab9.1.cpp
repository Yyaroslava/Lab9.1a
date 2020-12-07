#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>  // ������������ ����������� ��������

using namespace std; 

enum Spesialnist { KN, INF, ME, FI, TN };

string spesialnistStr[] = { "��������� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

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
    // ������������ ����������� ��������:
    SetConsoleCP(1251);       // ������������ ������� win-cp1251 � ���� �����
    SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
    
    int N;
    cout << "������ ������� ��������: ";
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
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();  // ������� ����� ���������, �� ����������� �������
        cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
        cout << "    �������: "; 
        getline(cin, p[i].prizv);
        cout << "    ����: "; 
        cin >> p[i].kurs;
        cout << "   ������������: (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������,";
        cout << " 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> spes_number;
        p[i].spesialnist = (Spesialnist)spes_number;
        cout << "    ������ � ������: ";
        cin >> p[i].mark_phys;
        cout << "    ������ � ����������: ";
        cin >> p[i].mark_math;
        cout << "    ������ � �����������: ";
        cin >> p[i].mark_inf;
        cout << endl;
    }
} 

void Print(Student *p, const int N, Marks &marks, double proc_55) {
    cout << "===========================================================================================" << endl;
    cout << "| � |   �������   |  ����  |      ������������      | Գ���� | ���������� | ����������� |" << endl;
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

    cout << "ʳ������ ������ ""�����"" � ������: " << marks.phys << endl;
    cout << "ʳ������ ������ ""�����"" � ����������: " << marks.math << endl;
    cout << "ʳ������ ������ ""�����"" � �����������: " << marks.inf << endl;

    cout << "������� ��������, �� �������� � � ������, � � ���������� ������ ""5"": " << proc_55 << "%" << endl;
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
