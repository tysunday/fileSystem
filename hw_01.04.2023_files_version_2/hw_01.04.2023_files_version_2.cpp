//Реализовать такие возможности как :
//1. Создание нового файла в текущем каталоге.
//2. Удаление файла из текущего каталога.
//3. Переименование файла в текущем каталоге.
//4. Перемещение файла из текущего каталога в указанный
//пользователем каталог.
//5. Вывод содержимого указанного пользователем файла
//из текущего каталога на экран.

#include "Header.h"
ofstream fout; // глобальная переменная для записи в файлы.
ifstream fin; // глобальная переменная для чтения данных с файлов.
string path; // путь к файлу

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int answer = 0;
	do
	{
		cout << "Выберите вариант ответа:\n\n";
		cout << R"(
				   0 - ВЫЙТИ ИЗ ПРОГРАММЫ
				   1 - Создать что-либо в текущем каталоге.
				   2 - Удалить что-либо из текущего каталога.
				   3 - Переименовать файл в текущем каталоге.
				   4 - Переместить файл в другой каталог.
				   5 - Перемещение по файловой системе.)" << endl << endl;

		cin >> answer;
		VisionCurrentDirectory();
		cin.sync();
		switch (answer) {
		case 0:
			break;
		case 1:
			cout << R"(Что будем создавать?
				1 - файл
				2 - директорию)" << endl;
			cin >> answer;
			switch (answer) {
			case 1:
				CreatedFile(path, fout);
				break;
			case 2:
				MakeDirectory();
				break;
			}
			break;
		case 2:
			VisionAllFile();
			cout << R"(Что будем удалять?
				1 - файл
				2 - директорию)" << endl;
			cin >> answer;
			switch (answer)
			{
			case 1:
				RemoveFile();
				break;
			case 2:
				DeleteDirectory();
				break;
			}
			break;
		case 3:
			VisionAllFile();
			RenameFile();
			break;
		case 4:
			VisionAllFile();
			MovedFile();
			break;
		case 5:
			MovedOnFileSystem();
			break;
		default:
			cout << "Такого варианта нет, попробуйте ещё раз. \n\n";
			break;
		}
		system("pause");
		system("cls");
	} while (answer != 0);
}


