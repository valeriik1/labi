#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

int main() {
    string input; // вводим строку
    int start, end; // объявляем переменные начала и конца

    cout << "Введите строку: "; 
    getline(cin, input); // чтение строки из стандартного ввода

    // ввод и проверка ввода
    cout << "Введите начальный номер цифыры для ввода: "; 
    while (!(cin >> start) || start <= 0) { 
        cout << "ERROR: Требуется ввести положительное целое число \n"; 
        cin.clear(); //
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //
    }
    
    // ввод и проверка ввода
    cout << "Введите конечный номер цифры для ввода: ";
    while (!(cin >> end) || end <= 0 || end < start) {
        cout << "ERROR: Требуется ввести положительное целое число, которое будет не меньше начального \n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int count = 0; // вводим счетчик
    bool flag = false; // водим флаг
    cout << "Цифры в диапазоне от " << start << " до " << end << ":\n"; // выводим диапазон

    for (char c : input) { // приходим к каждому символу в строке
        if (isdigit(c)) { // функция isdigit(c) проверяет, является ли символ c цифрой
            count++; // увеличиваем счетчик на 1, каждый раз, когда находим цифру
            if (count >= start && count <= end) { // проверяет, попадает ли текущая цифра в заданный диапазон от start до end
                cout << "Цифрой номер " << count << " является " << c << endl; 
                flag = true; // устанавливает флаг flag в true, если хотя бы одна цифра была найдена в заданном диапазоне
            }
            if (count > end) break; // прерывает цикл, если счетчик превышает вырхнюю границу
        }
    }
    if (!flag) {  // если флаг flag равен false, это означает, что в заданном диапазоне не было найдено ни одной цифры
        cout << "\n В строке недостаточно цифр в нужном диапазоне! \n";
        return 1;
    }
    cout << endl;
    return 0;
}