#pragma once
using namespace std;

// функция для вычитания двух чисел
string vichitanie(const string& a, const string& b);

// функция для деления двух чисел
string delenie(const string& a, const string& b);

// функция, чтобы проверить на ошибки при вводи чисел
bool oshibki(const string& input);

// функция, чтобы убрать знак минус (если он вообще есть)
string neminus(const string& input);
