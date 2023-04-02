#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING // для стабильной работы библиотеки experimental/filesystem
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <windows.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include<direct.h> // библиотека взаимодействия с директориями.

using namespace std;
namespace fs = experimental::filesystem; // это для того чтоб не писать длинное название для вызова функций с библиотеки.

void ChapterOne(); 
// Здесь мы увидим методы для просмотра информации о количестве занимаемой, свободной и свободной непривилегированной памяти,
// так же метод для просмотра информации в какой директории мы находимся, и метод в котором можно прописать относительный путь.

void ChapterTwo(); 
// Здесь мы увидим сепаратор (разделитель) в файловой системе.
// варианты формирования пути к файлам, директориям.
// полный путь к файлу, родительский путь, название файла, расширение файла.

void ChapterThree(); 
// создание директорий.
// последовательное создание директорий друг в друге в конкретно указанном нами месте.

void ChapterFour(); 
// удаление директорий.

void ChapterFive(); 
// поиск конкретных расширений файлов в конкретных директориях и вывод это на экран.

void VisionFile();
// функция вывода значений на экран.

string CreatedFile(string path, ofstream& fout);
// функция создания файла и проверки создался ли он.

void VisionCurrentDirectory();
// показывает в какой конкретно директории мы находимся

void RemoveFile(); 
// функция для удаления файла.

vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext);

void VisionAllFile(); 
// чтобы видеть все файлы в текущем каталоге.

void RenameFile(); 
// функция для изменения названия файла.

int DeleteDirectory();
// функция удаления директории. В текущем каталоге. ( но можно прописать полный путь куда создать при просьбе ввести имя директории)


int MakeDirectory();
// функция создания директории. В текущем каталоге. ( но можно прописать полный путь куда создать при просьбе ввести имя директории)]

void MovedOnFileSystem();
// функция перемещения по файловой системе. 

void MovedFile();
// переместить файл в другую директорию.