#include <iostream>
#include <string> 
#include <cstdlib>;
#include <windows.h>;
using namespace std;

struct Unic
{
    char name[20];
    char surname[20];
    char patronymic[20];
    char dolznost[20];
    char otdel[20];
    char date[5];
    int score[5];
    int itog;
};
bool check(int size, int arr[], int index) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == index) {
            return false;
            break;
        }
    }
    return true;
}
void ShowandSort(Unic person[], int size) {
    int min = 0;
    int* check = new int[size];
    for (int i = 1; i < size; i++)
    {
        if (person[min].date < person[i].date && check)
        {
            min = i;
        }
        check[i - 1] = min;
        cout << person[min].date << " data " << endl;
        cout << "фамилию сотрудника:"; cout << person[min].name;
        cout << "имя сотрудника:"; cout << person[min].surname;
        cout << "отчество сотрудника:"; cout << person[min].patronymic;
        cout << "должность сотрудника :"; cout << person[min].dolznost;
        cout << "отдел,в котором работает сотрудник:"; cout << person[min].otdel;
        cout << "дату начала работы сотрудника:"; cout << person[min].date;
    }
}
int main(void)
{
    setlocale(LC_ALL, "ru");

    int arr[4] = { -11,232,32,-234 };
    int min = 0;
    int* checks = new int[4];
    for (int i = 0; i < 4; i++)
    {
        checks[i] = -1;
    }
    for (int j = 0; j < 4; j++) {
        min = 0;
        for (int i = 0; i < 4; i++)
            if (arr[min] > arr[i] && check(4, checks, i)) {
                min = i;
            }
        checks[j] = arr[min];
        cout << arr[min] << " min " << endl;
    }
    while (true)
    {
        int task;

        cout << "Выберите задачу:" << endl <<
            "1. Информация о сотрудниках предприятия содержит ФИО, номер отдела,должность, дату начала работы и вывести список сотрудников заданного отдела в порядке убывания стажа." << endl <<
            "2. Выйти из меню." << endl;
        cin >> task;
        cout << " another thing ";
        switch (task)
        {
        case 1:
        {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);

            int n, average;
            cout << "Введите количество сотрудников:"; cin >> n;
            cout << endl;

            Unic* unic = new Unic[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Введите фамилию сотрудника:"; cin >> unic[i].name;
                cout << "Введите имя сотрудника:"; cin >> unic[i].surname;
                cout << "Введите отчество сотрудника:"; cin >> unic[i].patronymic;
                cout << "Введите должность сотрудника :"; cin >> unic[i].dolznost;
                cout << "Введите отдел,в котором работает сотрудник:"; cin >> unic[i].otdel;
                cout << "Введите дату начала работы сотрудника:"; cin >> unic[i].date;
            }
            ShowandSort(unic, n);
        }
        }
    }
}