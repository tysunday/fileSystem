#include "Header.h"


void ChapterOne()
{
	auto cur_p = fs::current_path(); // эта функция показывает в какой директории мы сейчас находимся.
	cout << "current path - " << cur_p << endl << endl;

	auto root_p = fs::path("/"); // относительный путь
	auto space = fs::space(root_p); // информация о размере общем объёме диска или доступном объёме
	/* сapacity - total size of the filesystem, in bytes
	   free - free space on the filesystem, in the bytes
	   available - free space available to a non-privileged process - доступное свободное пространство (доступно для непривелигированных процессов)
								 (may be equal or less than free)*/

	cout << "Total: " << space.capacity / 1024 / 1024 / 1024 << "GB" << endl;
	cout << "Free: " << space.free / 1024 / 1024 / 1024 << "GB" << endl;
	cout << "Available: " << space.available / 1024 / 1024 / 1024 << "GB" << endl;
	cout << endl;
}

void ChapterTwo()
{
	// 1 вариант формирования пути:
	fs::path aPath{ "D:/academy top/file.txt" }; // пишем здесь путь файла
	cout << "Path to file: " << aPath << endl; // показывает полный путь к файлу
	cout << "Parent path: " << aPath.parent_path() << endl; // показывает родительский путь файла
	cout << "Filename: " << aPath.filename() << endl; // пишет название файла и его расширение
	cout << "Extension: " << aPath.extension() << endl; // пишет расширение файла
	cout << endl;

	// 2 вариант формирования пути: 
	fs::path root{ "/" }; // пропишем корневую директорию
	fs::path dir{ "dev/db" }; // промежуточная директория
	fs::path db{ "database.db" }; // искомый файл (здесь база данных как в примере с интернета)

	fs::path pathToDB = root / dir / db; // делаем переменную класса и сразу её приравниваем к переменным с некими путями к файлу.
	cout << pathToDB << endl; // выводим этот путь


	cout << "Separator in my OC " << fs::path::preferred_separator << endl; // здесь должно выводиться "//" а выводится "92".
	// это сепаратор, т.е. разделитель в файловой системе.
}

void ChapterThree()
{
	auto cur_p = fs::current_path(); // сделаем переменную и приравняем её к пути текущей директории.
	fs::create_directory("tmp"); // создание директории.
	fs::create_directories(cur_p / "tmp" / "a"); /* здесь создание последовательно директории в директории
												   (обязательно нужно указывать сепаратор между ними)*/

	fs::create_directories(cur_p / "tmp/b"); // второй вариант создания директории в директории.
	fs::create_directories(cur_p / "tmp/b" / "bb" / "bbb"); // файлов можно указывать сколько угодно друг в друге.
}

void ChapterFour()
{
	auto cur_p = fs::current_path();
	fs::remove(cur_p / "tmp/b" / "bb" / "bbb"); // удаляет последнюю указанную директорию
	fs::remove_all(cur_p / "tmp"); // удаляет полностью указанную директорию
}


vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext) // dir - это путь на конкретную директорию.	
{																		// ext - это расширение файла.
	vector <string> files;
	for (auto& p : fs::recursive_directory_iterator(dir)) // "&p" - это ссылка на файл в конкретной директории,  
	{					// recursive_directory_iterator - позволяет итерироваться по всем файлам и поддиректориям в заданной директории.
		if (fs::is_regular_file(p)) // проверка является ли Файл файлом или ссылкой или директорией или чем-то ещё.
		{
			if (ext.empty() // проверяем пустая ли директория.
				|| // "или"
				find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end()) // идём по файлам директории пока они не кончатся.
				files.push_back(p.path().string()); // возвращаем файлы директории в вектор.
		}
	}
	return files; // возвращаем файлы для того чтоб сохранить их в вектор и отобразить.
}

void ChapterFive()
{
	auto res_dir = fs::current_path(); // создаём переменную которая показывает в какой директории мы сейчас находимся.

	res_dir = res_dir / "res" / "pics"; // приравниваем к res_dir новый путь для создания директория "res" и поддиректория "pics".
	fs::create_directories(res_dir); // создаём директории.

	vector<string> res_files = // Загружаем в вектор путь куда и какие файлы создавать. 
	{ //(обязательно прописываем путь где их создаём, а не только названия файлов, иначе он создаст их там, где мы находимся сейчас).
		"./res/pics/file.png",
		"./res/pics/file.jpg",
		"./res/pics/file.info"
	};

	for (auto& f : res_files)
		ofstream(f) << "data"; // создаём файлы и кладём туда данные: "data".

	auto print_files = [](const auto& aVector) // не до конца понимаю как это работает, но это выводит найденные нами файлы.
	{
		for (auto& f : aVector)
		{
			cout << f << endl;
			cout << endl;
		};
	};

	cout << "JPG filter" << endl; // показываем пользователю что нашли:
	auto files = getDirectoryFiles(res_dir, { ".jpg" }); // сохраняем в files возвращаемые значения с функции куда передали путь к файлам и что конкретно искать
	print_files(files); // с помощью лямба-функции выводим то, что нашли

	cout << "INFO filter" << endl;
	files = getDirectoryFiles(res_dir, { ".info", ".jpg" });
	print_files(files);

	cout << "without filter" << endl;
	files = getDirectoryFiles(res_dir, {});
	print_files(files);
}

void VisionFile()
{
	cout << "Файлы в текущем каталоге: " << endl;
	fs::path current_path = fs::current_path();
	// Проходим по всем файлам в папке с проектом
	for (const auto& entry : fs::directory_iterator(current_path)) {
		// Проверяем, является ли файл текстовым файлом
		if (entry.path().extension() == ".txt") {
			// Выводим имя текстового файла на экран
			cout << entry.path().filename() << endl;
		}
	}
}

string CreatedFile(string path, ofstream& fout)
{
	cout << "Введите название файла для его создания\n";
	cin >> path;
	string temp = path;
	path = path + ".txt";
	fout.open(path);
	path = temp;

	fout.is_open();
	if (!fout.is_open())
		cout << "Файл не открыт. \n";
	else
		cout << "Файл успешно создан\n";
	return path;
}

void VisionCurrentDirectory()
{
	auto cur_p = fs::current_path();
	cout << "\t\tТекущая директория - " << cur_p << endl << endl;
}

void RemoveFile()
{
	string nameRemoveFile;
	cout << "Введите название файла которое вы хотите удалить(с расширением)\n";
	cin.sync();
	cin >> nameRemoveFile;
	remove(nameRemoveFile.c_str()); // c_str нужен для преобразования объекта string в С - строку т.е. указатель на массив символов типа const char*
}

void VisionAllFile()
{
	cout << "Файлы в текущем каталоге: " << endl;
	fs::path current_path = fs::current_path();
	// Проходим по всем файлам в папке с проектом
	for (const auto& entry : fs::directory_iterator(current_path)) {
		cout << entry.path().filename() << endl;
	}
	cout << "\n\n";
}

void RenameFile()
{
	string oldNameFile, newNameFile;
	cout << "Введите какой файл вы хотите переименовать (с расширением): \n";
	cin >> oldNameFile;
	cout << "Введите какое имя ему хотите дать (с расширением): \n";
	cin.sync();
	cin >> newNameFile;
	cin.sync();
	rename(oldNameFile.c_str(), newNameFile.c_str());
}

int DeleteDirectory()
{
	string pathToDirectory;
	cout << "Введите название папки которую хотите удалить:\n";
	cin.ignore();
	getline(cin, pathToDirectory);
#pragma warning(suppress : 4996) // отключает ошибку для определенной строки в коде. В нашем случае для корректной работы rmdir
	int result = rmdir(pathToDirectory.c_str());
	if (result != 0) {
		std::perror("Ошибка удаления директории");
		return 1;
	}
	return 0;
}

int MakeDirectory()
{
	string directoryName;
	cout << "Введите название для папки: \n";
	cin.ignore();
	getline(cin, directoryName);
#pragma warning(suppress : 4996) // отключает ошибку для определенной строки в коде. В нашем случае для корректной работы mkdir
	int result = mkdir(directoryName.c_str());
	if (result != 0) {
		std::perror("Ошибка создания директории");
		return 1;
	}
	return 0;
}

void MovedOnFileSystem()
{
	cin.ignore();
	fs::path current_path = fs::current_path();
	cout << "Current path: " << current_path << '\n';

	while (true) {
		cout << "\nDirectories in current path:\n";
		int i = 0;
		for (auto& entry : fs::directory_iterator(current_path)) {
			if (is_directory(entry)) {
				cout << "[" << i++ << "] " << entry.path().filename() << '\n';
			}
			else
				cout << entry.path().filename() << "\n";
		}
		cout << "[" << i++ << "] Go back\n";
		cout << "[" << i << "] Exit\n";

		cout << "Enter choice: ";
		string choice;
		getline(std::cin, choice);

		try {
			int index = stoi(choice);
			if (index == i - 1) {
				current_path = current_path.parent_path();
			}
			else if (index == i) {
				break;
			}
			else if (index >= 0 && index < i - 1) {
				int j = 0;
				for (auto& entry : fs::directory_iterator(current_path)) {
					if (is_directory(entry)) {
						if (j++ == index) {
							current_path = entry.path();
							break;
						}
					}
				}
			}
		}
		catch (invalid_argument& e) {
			cout << "Invalid choice\n";
		}
		system("cls");
	}
}

void MovedFile()
{
	string fileName, directoryName;
	cout << "Введите название файла которое вы хотите переместить(с расширением):\n";
	cout << "Пример: 1.txt\n";
	cin >> fileName;
	cout << "Введите название директории в которую вы хотите положить этот файл:\n";
	cout << "Пример: new/1.txt\n";
	cin >> directoryName;
	rename(fileName.c_str(), directoryName.c_str());
}
