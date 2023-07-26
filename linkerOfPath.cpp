// linkerOfPath.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <filesystem>


int debag = 2;
using namespace std;


void get_files(vector<string>& paths, const string&current_path) {

	for (const auto& file : filesystem::directory_iterator(current_path)) {
		if (filesystem::is_directory(file)) {
			get_files(paths, file.path().string());
		}
		else {
			paths.push_back(file.path().string());
		}

	}
}

int serchInFile(string curString)
{

	
	string character = { "I" }; //for searching by I
	string Document;
	string dirPathAndName;
	ifstream  in(curString); //Enter file
	ofstream  output_file;
	ofstream  output_file2;
	dirPathAndName = curString;

	//For name of new files ->
	int position2 = dirPathAndName.find("list_of_files");

	if (position2 != std::string::npos)// 23 not= -1/0
	{
		dirPathAndName.replace(position2, position2 + 13, "list_of_files_for_Zos.txt");

		string file_name = dirPathAndName;
		
		output_file.open(file_name.c_str());

		if (in.is_open())
		{
			while (getline(in, Document))// содержимое из папки в string
			{

				int position3 = Document.find("VCP");

				if (position3 != std::string::npos)
				{
					cout << "!!!I find vcp!2!! And delete|" << Document << endl;
					Document.erase(position3, position3 + 4);
				}


				std::string::size_type Id_literal = Document.find_first_of(character, 0); // поиск по первому символу

				if (Id_literal != std::string::npos) //нашел 1 символ внутри
				{
					// проверка по длинне символов... могут быть ошибки..
					// непонятно откуда стартует
					// далее поиск

					std::string serchName{ "IBD" };

					int position = Document.find(serchName);

					if (position != std::string::npos)
					{

						//cout << "!11!!I find it Name|" << Document << endl;
						int iter_npos_str = std::string::npos;

						//printf("!!!!! on %d position \n", position);
						//std::string::size_type  


						cout << "!!!I replace IBD on IBD40 !!33!!|" << Document << endl;
						Document.replace(position, iter_npos_str + 4, "IBD40");

						//cout << "!!!wrote to list_file string !4!!!!|" << Document << endl;
						output_file << Document.c_str() << endl;

						std::cout << " !555!string|" << Document << " |string|" << std::endl;

						//	std::cout << "box of replace and write to new file or enter to crul" << endl;
						//	replaceName(curString);
						printf("!6!! Next string of files!!!!!!!!! \n");
					}


				}
			}


		} in.close();
		output_file.close(); // файл записи закрыть
	
		cout << "Ошибка закрытия eof ChF закрытия" << endl;
		
	}
	return 0;
}




int main()
{
	cout << " Do you want to enter the path to the root of the directory ? = 1 \n"
		    " Or not(use recommended path D:\\src\\TRAN)=0 \n" << endl;
	
	int menu=0; 
	string PathRoot;

	cin >> menu ;

	if (menu == 1)
	{
		cout << "Enter your path \n" << endl;
		cin >> PathRoot;
	}
	
	else if (menu == 0)
	{
	     PathRoot = "D:\\src\\TRAN";
	}

	else { return 0; }

	setlocale(LC_ALL, "RUS");
	 
	int counter = 0;
	vector<string> paths;
	string fileFind = "list_of_files";

	get_files(paths, PathRoot); 


	// SEARCH OF FILES BY NAME OF FILES

	char buff[50];

	for (int i = 0; i < paths.size(); i++)
	{
	
		counter++;
		string curName;
        curName = paths[i];
		int position = paths[i].find(fileFind);
		
		if (position != std::string::npos)   
		{

			int exp_position = paths[i].find("list_of_files_for_Zos");

			if (exp_position != std::string::npos)
			{
				goto exiit; 
			}
			cout << "Addres  " << curName << endl;
			serchInFile(curName);

		}
	exiit:
		int r;
	}
	printf("!!!!count of elements %d \n", counter); // коли-во директорий и файлов
	system("pause");

}


