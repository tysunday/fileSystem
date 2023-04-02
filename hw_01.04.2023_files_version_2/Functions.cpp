#include "Header.h"


void ChapterOne()
{
	auto cur_p = fs::current_path(); // ��� ������� ���������� � ����� ���������� �� ������ ���������.
	cout << "current path - " << cur_p << endl << endl;

	auto root_p = fs::path("/"); // ������������� ����
	auto space = fs::space(root_p); // ���������� � ������� ����� ������ ����� ��� ��������� ������
	/* �apacity - total size of the filesystem, in bytes
	   free - free space on the filesystem, in the bytes
	   available - free space available to a non-privileged process - ��������� ��������� ������������ (�������� ��� ������������������� ���������)
								 (may be equal or less than free)*/

	cout << "Total: " << space.capacity / 1024 / 1024 / 1024 << "GB" << endl;
	cout << "Free: " << space.free / 1024 / 1024 / 1024 << "GB" << endl;
	cout << "Available: " << space.available / 1024 / 1024 / 1024 << "GB" << endl;
	cout << endl;
}

void ChapterTwo()
{
	// 1 ������� ������������ ����:
	fs::path aPath{ "D:/academy top/file.txt" }; // ����� ����� ���� �����
	cout << "Path to file: " << aPath << endl; // ���������� ������ ���� � �����
	cout << "Parent path: " << aPath.parent_path() << endl; // ���������� ������������ ���� �����
	cout << "Filename: " << aPath.filename() << endl; // ����� �������� ����� � ��� ����������
	cout << "Extension: " << aPath.extension() << endl; // ����� ���������� �����
	cout << endl;

	// 2 ������� ������������ ����: 
	fs::path root{ "/" }; // �������� �������� ����������
	fs::path dir{ "dev/db" }; // ������������� ����������
	fs::path db{ "database.db" }; // ������� ���� (����� ���� ������ ��� � ������� � ���������)

	fs::path pathToDB = root / dir / db; // ������ ���������� ������ � ����� � ������������ � ���������� � ������ ������ � �����.
	cout << pathToDB << endl; // ������� ���� ����


	cout << "Separator in my OC " << fs::path::preferred_separator << endl; // ����� ������ ���������� "//" � ��������� "92".
	// ��� ���������, �.�. ����������� � �������� �������.
}

void ChapterThree()
{
	auto cur_p = fs::current_path(); // ������� ���������� � ���������� � � ���� ������� ����������.
	fs::create_directory("tmp"); // �������� ����������.
	fs::create_directories(cur_p / "tmp" / "a"); /* ����� �������� ��������������� ���������� � ����������
												   (����������� ����� ��������� ��������� ����� ����)*/

	fs::create_directories(cur_p / "tmp/b"); // ������ ������� �������� ���������� � ����������.
	fs::create_directories(cur_p / "tmp/b" / "bb" / "bbb"); // ������ ����� ��������� ������� ������ ���� � �����.
}

void ChapterFour()
{
	auto cur_p = fs::current_path();
	fs::remove(cur_p / "tmp/b" / "bb" / "bbb"); // ������� ��������� ��������� ����������
	fs::remove_all(cur_p / "tmp"); // ������� ��������� ��������� ����������
}


vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext) // dir - ��� ���� �� ���������� ����������.	
{																		// ext - ��� ���������� �����.
	vector <string> files;
	for (auto& p : fs::recursive_directory_iterator(dir)) // "&p" - ��� ������ �� ���� � ���������� ����������,  
	{					// recursive_directory_iterator - ��������� ������������� �� ���� ������ � �������������� � �������� ����������.
		if (fs::is_regular_file(p)) // �������� �������� �� ���� ������ ��� ������� ��� ����������� ��� ���-�� ���.
		{
			if (ext.empty() // ��������� ������ �� ����������.
				|| // "���"
				find(ext.begin(), ext.end(), p.path().extension().string()) != ext.end()) // ��� �� ������ ���������� ���� ��� �� ��������.
				files.push_back(p.path().string()); // ���������� ����� ���������� � ������.
		}
	}
	return files; // ���������� ����� ��� ���� ���� ��������� �� � ������ � ����������.
}

void ChapterFive()
{
	auto res_dir = fs::current_path(); // ������ ���������� ������� ���������� � ����� ���������� �� ������ ���������.

	res_dir = res_dir / "res" / "pics"; // ������������ � res_dir ����� ���� ��� �������� ���������� "res" � ������������� "pics".
	fs::create_directories(res_dir); // ������ ����������.

	vector<string> res_files = // ��������� � ������ ���� ���� � ����� ����� ���������. 
	{ //(����������� ����������� ���� ��� �� ������, � �� ������ �������� ������, ����� �� ������� �� ���, ��� �� ��������� ������).
		"./res/pics/file.png",
		"./res/pics/file.jpg",
		"./res/pics/file.info"
	};

	for (auto& f : res_files)
		ofstream(f) << "data"; // ������ ����� � ����� ���� ������: "data".

	auto print_files = [](const auto& aVector) // �� �� ����� ������� ��� ��� ��������, �� ��� ������� ��������� ���� �����.
	{
		for (auto& f : aVector)
		{
			cout << f << endl;
			cout << endl;
		};
	};

	cout << "JPG filter" << endl; // ���������� ������������ ��� �����:
	auto files = getDirectoryFiles(res_dir, { ".jpg" }); // ��������� � files ������������ �������� � ������� ���� �������� ���� � ������ � ��� ��������� ������
	print_files(files); // � ������� �����-������� ������� ��, ��� �����

	cout << "INFO filter" << endl;
	files = getDirectoryFiles(res_dir, { ".info", ".jpg" });
	print_files(files);

	cout << "without filter" << endl;
	files = getDirectoryFiles(res_dir, {});
	print_files(files);
}

void VisionFile()
{
	cout << "����� � ������� ��������: " << endl;
	fs::path current_path = fs::current_path();
	// �������� �� ���� ������ � ����� � ��������
	for (const auto& entry : fs::directory_iterator(current_path)) {
		// ���������, �������� �� ���� ��������� ������
		if (entry.path().extension() == ".txt") {
			// ������� ��� ���������� ����� �� �����
			cout << entry.path().filename() << endl;
		}
	}
}

string CreatedFile(string path, ofstream& fout)
{
	cout << "������� �������� ����� ��� ��� ��������\n";
	cin >> path;
	string temp = path;
	path = path + ".txt";
	fout.open(path);
	path = temp;

	fout.is_open();
	if (!fout.is_open())
		cout << "���� �� ������. \n";
	else
		cout << "���� ������� ������\n";
	return path;
}

void VisionCurrentDirectory()
{
	auto cur_p = fs::current_path();
	cout << "\t\t������� ���������� - " << cur_p << endl << endl;
}

void RemoveFile()
{
	string nameRemoveFile;
	cout << "������� �������� ����� ������� �� ������ �������(� �����������)\n";
	cin.sync();
	cin >> nameRemoveFile;
	remove(nameRemoveFile.c_str()); // c_str ����� ��� �������������� ������� string � � - ������ �.�. ��������� �� ������ �������� ���� const char*
}

void VisionAllFile()
{
	cout << "����� � ������� ��������: " << endl;
	fs::path current_path = fs::current_path();
	// �������� �� ���� ������ � ����� � ��������
	for (const auto& entry : fs::directory_iterator(current_path)) {
		cout << entry.path().filename() << endl;
	}
	cout << "\n\n";
}

void RenameFile()
{
	string oldNameFile, newNameFile;
	cout << "������� ����� ���� �� ������ ������������� (� �����������): \n";
	cin >> oldNameFile;
	cout << "������� ����� ��� ��� ������ ���� (� �����������): \n";
	cin.sync();
	cin >> newNameFile;
	cin.sync();
	rename(oldNameFile.c_str(), newNameFile.c_str());
}

int DeleteDirectory()
{
	string pathToDirectory;
	cout << "������� �������� ����� ������� ������ �������:\n";
	cin.ignore();
	getline(cin, pathToDirectory);
#pragma warning(suppress : 4996) // ��������� ������ ��� ������������ ������ � ����. � ����� ������ ��� ���������� ������ rmdir
	int result = rmdir(pathToDirectory.c_str());
	if (result != 0) {
		std::perror("������ �������� ����������");
		return 1;
	}
	return 0;
}

int MakeDirectory()
{
	string directoryName;
	cout << "������� �������� ��� �����: \n";
	cin.ignore();
	getline(cin, directoryName);
#pragma warning(suppress : 4996) // ��������� ������ ��� ������������ ������ � ����. � ����� ������ ��� ���������� ������ mkdir
	int result = mkdir(directoryName.c_str());
	if (result != 0) {
		std::perror("������ �������� ����������");
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
	cout << "������� �������� ����� ������� �� ������ �����������(� �����������):\n";
	cout << "������: 1.txt\n";
	cin >> fileName;
	cout << "������� �������� ���������� � ������� �� ������ �������� ���� ����:\n";
	cout << "������: new/1.txt\n";
	cin >> directoryName;
	rename(fileName.c_str(), directoryName.c_str());
}
