#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING // ��� ���������� ������ ���������� experimental/filesystem
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <windows.h>
#include <algorithm>
#include <cstdio>
#include <string>
#include<direct.h> // ���������� �������������� � ������������.

using namespace std;
namespace fs = experimental::filesystem; // ��� ��� ���� ���� �� ������ ������� �������� ��� ������ ������� � ����������.

void ChapterOne(); 
// ����� �� ������ ������ ��� ��������� ���������� � ���������� ����������, ��������� � ��������� ������������������� ������,
// ��� �� ����� ��� ��������� ���������� � ����� ���������� �� ���������, � ����� � ������� ����� ��������� ������������� ����.

void ChapterTwo(); 
// ����� �� ������ ��������� (�����������) � �������� �������.
// �������� ������������ ���� � ������, �����������.
// ������ ���� � �����, ������������ ����, �������� �����, ���������� �����.

void ChapterThree(); 
// �������� ����������.
// ���������������� �������� ���������� ���� � ����� � ��������� ��������� ���� �����.

void ChapterFour(); 
// �������� ����������.

void ChapterFive(); 
// ����� ���������� ���������� ������ � ���������� ����������� � ����� ��� �� �����.

void VisionFile();
// ������� ������ �������� �� �����.

string CreatedFile(string path, ofstream& fout);
// ������� �������� ����� � �������� �������� �� ��.

void VisionCurrentDirectory();
// ���������� � ����� ��������� ���������� �� ���������

void RemoveFile(); 
// ������� ��� �������� �����.

vector<string> getDirectoryFiles(const fs::path& dir, const vector<string>& ext);

void VisionAllFile(); 
// ����� ������ ��� ����� � ������� ��������.

void RenameFile(); 
// ������� ��� ��������� �������� �����.

int DeleteDirectory();
// ������� �������� ����������. � ������� ��������. ( �� ����� ��������� ������ ���� ���� ������� ��� ������� ������ ��� ����������)


int MakeDirectory();
// ������� �������� ����������. � ������� ��������. ( �� ����� ��������� ������ ���� ���� ������� ��� ������� ������ ��� ����������)]

void MovedOnFileSystem();
// ������� ����������� �� �������� �������. 

void MovedFile();
// ����������� ���� � ������ ����������.