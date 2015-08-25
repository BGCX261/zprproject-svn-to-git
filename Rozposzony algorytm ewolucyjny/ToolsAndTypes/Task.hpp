//
//
//
//  @ Project : Rozproszony algorytm ewolucyjny
//  @ File Name : Task.hpp
//  @ Author : Pawe� Marchewka, Bogdan Jezierski
//
//


#if !defined(_TASK_H)
#define _TASK_H

#include <fstream>
#include <iostream>


namespace ToolsAndTypes {		//task TO DO
	class Task
	{
	public:
		Task()
		{

		}

//		Task (char* z)
//		{
//			readFromFile(z);
//		}

		Task (const std::string &ss)
		{
			task = ss;
		}

		void setTask (const std::string &ss)
		{
			task = ss;
		}

		std::string getTask ()
		{
			return task;
		}

		int readFromFile()
		{
			std::cout << "Read from file" << std::endl;
			std::ifstream in;
			std::string temp;
			//in.open("brak");
			in.open("100_max100.txt");


			if ( !in.is_open() )
			{
				std::cout << "Nie udalo otworzyc sie pliku" << std::endl;
				return 1;
			}

			  while(!in.eof())
			    {
			      getline(in, temp);
			      task += temp;
			    }

			in.close();
			return 0;

		}

	private:
		std::string task;

	};
}

#endif  //_TASK_H
