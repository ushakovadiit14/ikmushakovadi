#include <iostream>  // для ввода-вывода
#include <string>    // для работы со строками
#include <algorithm> // для функции
#include <cctype>    // для функции 
#include "Header.h" // для хедера

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU"); // устанавливаем русский язык
    string chislo_a, chislo_b; // создаем переменные для хранения чисел

    cout << "Добро пожаловать!"<< endl;
    cout << "Эта программа делит нацело число a на число b, " << endl << "если a, b — многозначные числа(количество знаков больше 10)."<< endl;

    // вводим первое число до тех пор, пока не будут учтены все условия
    do
    {
        cout << "Введите первое большое число a (больше 10 цифр, не начиная с 0): ";
        cin >> chislo_a; // ввод первого числа

        // проверяем, чтобы все условия выполнились
        if (!oshibki(chislo_a))
        {
            cout << "Ошибка! введите корректное число (только цифры, длинной больше 10 и чтобы оно не начиналось с 0!) " << endl << "Попробуйте еще раз!)" << endl;
        }
    } 
    while (!oshibki(chislo_a)); // цикл будет, пока есть ошибки при вводе

    //  вводим второе число до тех пор, пока не будут учтены все условия
    do
    {
        cout << "Введите второе большое число b (больше 10 цифр, не начиная с 0): ";
        cin >> chislo_b; // ввод второго числа

        // проверяем, чтобы все условия выполнились
        if (!oshibki(chislo_b))
        {
            cout << "Ошибка! введите корректное число (только цифры, длинной больше 10 и  чтобы оно не начиналось с 0!) " << endl << "Попробуйте еще раз!)" << endl ;
        }
    }
    while (!oshibki(chislo_b)); // цикл будет, пока есть ошибки при вводе

    // выполняем деление и удаляем знак, если он есть
    string result = delenie(neminus(chislo_a), neminus(chislo_b));

    // определяем итоговый знак 
    bool otricresult = (chislo_a[0] == '-') ^ (chislo_b[0] == '-'); // исключающее ИЛИ

    // если результат должен быть с "-" и не равен "0"
    if ( otricresult && result != "0")
    {
        result = "-" + result; // то добавляем знак "-"
    }

    // вывод результата
    cout << "Результат целочисленного деления " << chislo_a << " на " << chislo_b << " равен " << result << endl;

    return 0; // завершение программы
}
