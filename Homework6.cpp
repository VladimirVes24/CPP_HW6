//1) Выделить в памяти динамический одномерный массив типа int.Размер массива запросить у пользователя.Инициализировать его
//  числами степенями двойки : 1, 2, 4, 8, 16, 32, 64, 128 … Вывести массив на экран.Не забыть освободить память. = ) Разбить
//   программу на функции.
//2) Динамически выделить матрицу 4х4 типа int.Инициализировать ее псевдослучайными числами через функцию rand.Вывести на экран.
//   Разбейте вашу программу на функции которые вызываются из main.
//3) Написать программу, которая создаст два текстовых файла(*.txt), примерно по 50 - 100 символов в каждом(особого значения не 
//   имеет с каким именно содержимым).Имена файлов запросить у польлзователя.
//4) * Написать функцию, «склеивающую» эти файлы в третий текстовый файл(имя файлов спросить у пользователя).
//5) * Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле(для простоты работаем только с латиницей).
//   Используем функцию find которая есть в строках std::string.

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

void Task1();
void Task2();
void Task3();
void Task4();
void Task5();

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
    Task5();
}

void Task1()
{
    int n;

    std::cout << "Enter array size:";
    std::cin >> n;
    std::cout << "\nYour array is:\n";

    int* pArr = new (std::nothrow) int[n];

    if (pArr != nullptr)
    {

        for (int i = 0; i < n; i++)
        {
            pArr[i] = static_cast<int>(pow(2, i));
            std::cout << pArr[i] << "  ";
        }

        std::cout << "\n";

        delete[] pArr;
        pArr = nullptr;
    }
    else std::cout << "NULL";
}

void Task2()
{
    
    std::cout << "\nTask 2.\n" << "Your array:\n";

    int** pArr;
    int m = 4, n = 4;

    pArr = new int* [m];

    for (int i = 0; i < m; i++)
    {
        pArr[i] = new int[n];
    }

    srand(static_cast<uint16_t>(time(NULL)));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pArr[i][j] = rand() % 100;
            std::cout << pArr[i][j] << "  ";
        }

        std::cout << "\n";
    }


    for (int i = 0; i < m; i++)
    {
        delete[] pArr[i];
    }
    delete[] pArr;
    pArr = nullptr;
}

void Task3()
{
    
    std::string fileName1 = "", fileName2 = "";

    std::cout << "\nTask 3.";
    std::cout << "\nEnter first file name:";
    std::cin >> fileName1;
    std::cout << "Enter second file name:";
    std::cin >> fileName2;
    std::cout << "\n";

    std::ofstream firstFile(fileName1);
    firstFile.clear();

    int columnCount = 0;
    for (int i = 0; i < 100; i++)
    {
        if (columnCount == 10)
        {
            columnCount = 0;
            firstFile << "\n";
        }
            
        firstFile << "1  ";
        columnCount++;

    }
    firstFile.close();

    std::ofstream secondFile(fileName2);
    secondFile.clear();


    columnCount = 0;
    for (int i = 0; i < 100; i++)
    {
        if (columnCount == 10)
        {
            columnCount = 0;
            secondFile << "\n";
        }

        secondFile << "2  ";
        columnCount++;

    }

    secondFile.close();
}

void Task4()
{
    bool success1 = false, success2 = false;
    std::string buf, fileName1, fileName2, fileName3 = "Result";
    std::cout << "\nEnter name of the first file:";
    std::cin >> fileName1;
    std::cout << "Enter name of the second file:";
    std::cin >> fileName2;


    std::ofstream resultFile(fileName3);
    resultFile.clear();

    std::ifstream firstFile(fileName1);

    if (firstFile.is_open())
    {
        success1 = true;
        while (!firstFile.eof())
        {
            getline(firstFile, buf);
            resultFile << buf <<"\n";
        }
        firstFile.close();
    }
    
    if (!success1) std::cout << "File 1 not fould!\n";

    std::ifstream secondFile(fileName2);

    if (secondFile.is_open())
    {
        success2 = true;
        while (!secondFile.eof())
        {
            getline(secondFile, buf);
            resultFile << buf << "\n";
        }
        secondFile.close();
    }
    
    if (!success2) std::cout << "File 2 not fould!\n";

    resultFile.close();

    if (success1 && success2) std::cout << "Successful merge into Result!\n";
}

void Task5()
{
    std::string buffer, word;
    bool found = false;

    std::cout << "\nEnter the word:";
    std::cin >> word;

    std::ifstream sourceFile("Source_File");

    if (sourceFile.is_open())
    {
        while (!sourceFile.eof())
        {
            getline(sourceFile, buffer);
            if (buffer.find(word) != std::string::npos)
            {
                std::cout << "The word is found!\n";
                found = true;
            }
        }
    }
    else std::cout << "File not found!";

    if (!found) std::cout << "\nCould not find the word.";
}