/*
Данные будут храниться в бинарных файлах.
Для взаимодействия с ними будет использоваться только функционал класса Tape.
В оперативной памяти будем хранить максимум массив длинны М, не считая одиночных переменных.
Основной смысл алгоритма в нахождении наименьших М-1 элементов при проходе по ленте на каждом шаге и исключении их из дальнейшего рассмотрения.
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <windows.h>
#include <algorithm>
#include "myTape.h"
#include "mysort.h"

int main()
{
    //создаем свой конфигурационный файл
    std::fstream output1("settings.txt", std::ios::out | std::ios::binary);
    if (output1.is_open())
    {
        int c = 0;
        output1.write((char*)&c, sizeof(c));
        output1.write((char*)&c, sizeof(c));
        output1.write((char*)&c, sizeof(c));
    }
    output1.close();

    std::remove("tmp.txt");
    std::remove("startfile.txt");
    std::remove("finishfile.txt");

    {
        //создаем свою входную ленту.
        int a[11];
        for (int i = 0; i < 11; i++) {
            a[i] = 6;
        }
        std::fstream output("startfile.txt", std::ios::out | std::ios::binary);
        if (output.is_open())
        {
            for (int i = 0; i < 11; i++) {
                output.write((char*)&a[i], sizeof(a[i]));
            }
        }
        output.close();
        std::fstream input("startfile.txt", std::ios::in | std::ios::binary);
        if (input.is_open())
        {
            std::cout << "Test 1 (N=4)";
            std::cout << '\n';
            for (int i = 0; i < 11; i++) {
                input.seekp(i * sizeof(int), std::ios_base::beg);
                input.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                std::cout << std::to_string(a[i]) + ' ';
            }
            input.close();
        }
        std::cout << '\n';
        mysort("startfile.txt", 4, "finishfile.txt", "settings.txt");//применяем функцию
        //выводим результат
        std::fstream input2("finishfile.txt", std::ios::in | std::ios::binary);
        if (input2.is_open())
        {
            for (int i = 0; i < 11; i++) {
                input2.seekp(i * sizeof(int), std::ios_base::beg);
                input2.read(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
                std::cout << std::to_string(a[i]) + ' ';
            }
            input2.close();
        }
        std::cout << '\n';
    }

    std::remove("tmp.txt");
    std::remove("startfile.txt");
    std::remove("finishfile.txt");

    {
        //создаем свою входную ленту.
        int b[20];
        for (int i = 0; i < 20; i++) {
            b[i] = 25 - i;
        }
        std::fstream output("startfile.txt", std::ios::out | std::ios::binary);
        if (output.is_open())
        {
            for (int i = 0; i < 20; i++) {
                output.write((char*)&b[i], sizeof(b[i]));
            }
        }
        output.close();
        std::fstream input("startfile.txt", std::ios::in | std::ios::binary);
        if (input.is_open())
        {
            std::cout << "Test 2 (N=4)";
            std::cout << '\n';
            for (int i = 0; i < 20; i++) {
                input.seekp(i * sizeof(int), std::ios_base::beg);
                input.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input.close();
        }
        std::cout << '\n';
        mysort("startfile.txt", 4, "finishfile.txt", "settings.txt");//применяем функцию
        //выводим результат
        std::fstream input2("finishfile.txt", std::ios::in | std::ios::binary);
        if (input2.is_open())
        {
            for (int i = 0; i < 20; i++) {
                input2.seekp(i * sizeof(int), std::ios_base::beg);
                input2.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input2.close();
        }
        std::cout << '\n';
    }

    std::remove("tmp.txt");
    std::remove("startfile.txt");
    std::remove("finishfile.txt");

    {
        //создаем свою входную ленту.
        int b[20];
        for (int i = 0; i < 20; i++) {
            b[i] = (25 - i);
        }
        std::fstream output("startfile.txt", std::ios::out | std::ios::binary);
        if (output.is_open())
        {
            for (int i = 0; i < 20; i++) {
                output.write((char*)&b[i], sizeof(b[i]));
            }
        }
        output.close();
        std::fstream input("startfile.txt", std::ios::in | std::ios::binary);
        if (input.is_open())
        {
            std::cout << "Test 3 (N=14)";
            std::cout << '\n';
            for (int i = 0; i < 20; i++) {
                input.seekp(i * sizeof(int), std::ios_base::beg);
                input.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input.close();
        }
        std::cout << '\n';
        mysort("startfile.txt", 14, "finishfile.txt", "settings.txt");//применяем функцию
        //выводим результат
        std::fstream input2("finishfile.txt", std::ios::in | std::ios::binary);
        if (input2.is_open())
        {
            for (int i = 0; i < 20; i++) {
                input2.seekp(i * sizeof(int), std::ios_base::beg);
                input2.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input2.close();
        }
        std::cout << '\n';
    }

    std::remove("tmp.txt");
    std::remove("startfile.txt");
    std::remove("finishfile.txt");

    {
        //создаем свою входную ленту.
        int b[20];
        for (int i = 0; i < 20; i++){
            b[i] = (25 - i) / 6;
        }
        std::fstream output("startfile.txt", std::ios::out | std::ios::binary);
        if (output.is_open())
        {
            for (int i = 0; i < 20; i++) {
                output.write((char*)&b[i], sizeof(b[i]));
            }
        }
        output.close();
        std::fstream input("startfile.txt", std::ios::in | std::ios::binary);
        if (input.is_open())
        {
            std::cout << "Test 4 (N=4)";
            std::cout << '\n';
            for (int i = 0; i < 20; i++){
                input.seekp(i * sizeof(int), std::ios_base::beg);
                input.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input.close();
        }
        std::cout << '\n';
        mysort("startfile.txt", 4, "finishfile.txt", "settings.txt");//применяем функцию
        //выводим результат
        std::fstream input2("finishfile.txt", std::ios::in | std::ios::binary);
        if (input2.is_open())
        {
            for (int i = 0; i < 20; i++) {
                input2.seekp(i * sizeof(int), std::ios_base::beg);
                input2.read(reinterpret_cast<char*>(&b[i]), sizeof(b[i]));
                std::cout << std::to_string(b[i]) + ' ';
            }
            input2.close();
        }
        std::cout << '\n';
    }

    std::cout << "Write file name of setting file, input file, output file and M:";
    std::string d[3];
    std::getline(std::cin, d[0]);
    std::getline(std::cin, d[1]);
    std::getline(std::cin, d[2]);
    int myM;
    std::cin >> myM;
    mysort(d[1],myM,d[2],d[0]);
}