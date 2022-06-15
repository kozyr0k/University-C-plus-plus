#define _CRT_SECURE_NO_WARNINGS 
#include "conio.h" 
#include "locale.h" 
#include "windows.h" 
#include <iostream>
#include "matrix.h"

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "*********Перевірка функціоналу класу для матриць*********" << std::endl;

    std::array<int, 3> sizesAndNumber;
    sizesAndNumber[0] = 3;
    sizesAndNumber[1] = 3;
    sizesAndNumber[2] = 5;

    std::cout << "Матриця №1 після створення розміром 2x3:" << std::endl;
    matrix<int> matrix1(2, 3);
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Матриця №1 після зміни її розмірів та ініціалізації елементів числом 5:" << std::endl;
    matrix1 = sizesAndNumber;
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Матриця №2, яка утворена як копія матриці №1:" << std::endl;
    matrix<int> matrix2(matrix1);
    matrix2.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Матриця №2 після зміни її розмірів та ініціалізації елементів 0:" << std::endl;
    std::array<int, 2> sizes;
    sizes[0] = 3;
    sizes[1] = 2;
    matrix2 = sizes;
    matrix2.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Транспонована матриця №1 після заміни елементу у комірці [2][2] на 10:" << std::endl;
    matrix1.SetMatrixElement(2, 2, 10);
    ~matrix1;
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Результат множення матриць №1 та №2:" << std::endl;
    matrix1*matrix2;
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Результат додавання матриць №1 та №2 після задання їх елементам деяких значень:" << std::endl;
    matrix1.SetMatrixElement(1, 1, 4);
    matrix1.SetMatrixElement(0, 1, 3);
    matrix2.SetMatrixElement(1, 0, 5);
    matrix1 + matrix2;
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Результат віднімання матриць №1 та №2:" << std::endl;
    matrix1.SetMatrixElement(1, 1, 4);
    matrix1.SetMatrixElement(0, 1, 3);
    matrix2.SetMatrixElement(1, 0, 5);
    matrix1 - matrix2;
    matrix1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Максимальний елемент у матриці №1: " << matrix1.GetMaximumAbs() << std::endl << std::endl;

    std::cout << "Матриця №3, яка утворена як копія матриці №1 за допомогою динамічного присвоювання:" << std::endl;
    matrix<int> matrix3;
    matrix3 = matrix1;
    matrix3.Print();
    std::cout << std::endl << std::endl;

    std::cout << "*********Перевірка функціоналу класу для векторів*********" << std::endl;

    std::cout << "Вектор №1 після створення з кількістю комірок 3:" << std::endl;
    vector<int> vector1(3);
    vector1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Вектор №1 після зміни кількості комірок та ініціалізації його елементів 5:" << std::endl;
    std::array<int, 2> sizeAndNumber;
    sizeAndNumber[0] = 4;
    sizeAndNumber[1] = 5;
    vector1 = sizeAndNumber;
    vector1.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Вектор №2 після створення його як копії вектора №1:" << std::endl;
    vector<int> vector2(vector1);
    vector2.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Вектор №3 після створення його як копії вектора №2 за допомогою динамічного присвоювання:" << std::endl;
    vector<int> vector3;
    vector3 = vector2;
    vector3.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Результат додавання векторів №2 та №3:" << std::endl;
    vector3 + vector2;
    vector3.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Результат віднімання векторів №2 та №3:" << std::endl;
    vector3 - vector2;
    vector3.Print();
    std::cout << std::endl << std::endl;

    std::cout << "Максимальний елемент у векторі №3: " << vector3.GetMaximumAbs() << std::endl << std::endl;

    std::cout << "Вектор №3 після зміни кількості елементів на 2 та обнуління їх:" << std::endl;
    vector3 = 2;
    vector3.Print();
}