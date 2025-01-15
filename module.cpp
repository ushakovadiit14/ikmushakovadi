#include <iostream>  // для ввода-вывода
#include <string>    // для работы со строками
#include <algorithm> // для функции
#include <cctype>    // для функции 
#include "Header.h"  // для заголовочного файла

using namespace std;

// функция для вычетания двух чисел
string vichitanie(const string& a, const string& b)
{
    // проверяем, число a меньше b по длине или по значению
    if (a.length() < b.length() || (a.length() == b.length() && a < b))
    {
        return "Невозможно вычесть";  // если вычесть нельзя, то сообщаем об ошибке
    }

    string result; // для хранения результата вычитания
    string n1 = a; // первое число для вычитания
    string n2 = b; // второе число для вычитания

    // добавляем ведущие нули
    n2.insert(0, n1.length() - n2.length(), '0');

    int perenos = 0; // перенос при вычитании

    // проходимся по цифрам справа налево
    for (int i = n1.length() - 1; i >= 0; --i)
    {
        int cifra1 = n1[i] - '0'; //переделываем символ в целое число
        int cifra2 = n2[i] - '0' + perenos; // переделываем и добавляем перенос

        // если текущая цифра из n1 меньше цифры из n2, нужно занять
        if (cifra1 < cifra2)
        {
            cifra1 += 10; // Заносим 10
            perenos = 1; // делаем перенос
        }
        else
        {
            perenos = 0; // или нет переноса
        }

        // считаем результат для текущей цифры
        result.push_back((cifra1 - cifra2) + '0');
    }

    // Убираем ведущие нули из результата
    while (result.length() > 1 && result.back() == '0')
    {

        result.erase(result.size() - 1); // удаляем, указав позицию символа
    }

    reverse(result.begin(), result.end()); // переворачиваем, так как результат записан задом наперед
    return result; // возвращаем результат
}

// функция для деления двух чисел
string delenie(const string& a, const string& b)
{
    // проверяем деление на ноль (на 0 делить нельзя)
    if (b == "0")
    {
        return "ошибке (делить на ноль нельзя)"; // сообщаем что делить на ноль нельзя
    }

    string result; // результат деления
    string ost = "0"; // остаток при делении

    // обрабатываем каждую цифру числа a
    for (char digit : a)
    {
        ost = vichitanie(ost + digit, "0"); // добавляем текущую цифру к остатку

        // проверяем, есть ли ошибка
        if (ost == "Невозможно вычесть")
        {
            return "Ошибка при выполнении вычитания"; // сообщаем об ошибке
        }

        int count = 0; // смотрим сколько раз b помещается в остаток

        // проверяем, можно ли вычесть b из остатка
        while (ost.length() > b.length() || (ost.length() == b.length() && ost >= b))
        {
            ost = vichitanie(ost, b); // вычитаем b из остатка

            // проверяем, есть ли ошибка
            if (ost  == "Невозможно вычесть")
            {
                return "Ошибка при выполнении вычитания"; // сообщаем об ошибке
            }
            count++; // увеличиваем счетчик
        }

        result.push_back(count + '0'); // записываем результат деления
    }
    // удаляем ведущие нули из результата
    while (result.length() > 1 && result[0] == '0')
    {
        result.erase(result.begin());
    }
    return result.empty() ? "0" : result; // возвращаем результат, если нет, возвращаем "0"
}
// функция, чтобы проверить на ошибки при вводи чисел
bool oshibki (const string& input) {
    // проверяем длинну: либо просто 0, либо другое число, но длинна тогда должна быть больше 10
    if (input != "0" && input.length() < 11) {
        return false;
    }
    // Число не может начинаться с "0" (если это не сам 0). например: 0000566445656
    if (input.length() > 1 && input[0] == '0') {
        return false; // начинается с 0, но при этом не 0
    }
    // проверка на цифры и знак
    if (input[0] == '-' && input.length() == 1)
    {
        return false; // только знак 
    }
    // В числе не может быть букв и каких то других символов, кроме минуса вначале. например: 345677ваап56898
    for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); ++i)
    {
        if (!isdigit(input[i]))
        {
            return false; // не является цифрой
        }
    }
    return true; // все символы - цифры
}

// функция, чтобы убрать знак минус (если он вообще есть)
string neminus(const string& input)
{
    return input[0] == '-' ? input.substr(1) : input; // если есть минус, убираем его
}
