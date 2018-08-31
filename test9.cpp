#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int test9(int argc, char *argv[])
{
	 string pathIn="G:/F/MTCNN/mtcnn-master2/服务器-车辆样板本/晚上-挑选/0-Path_Images.txt";
	 string pathTxt="G:/F/MTCNN/mtcnn-master2/服务器-车辆样板本/晚上-挑选.txt";
	 fstream fin(pathIn,ios::in);
	 if(!fin.is_open())
	 {
		  printf("读txt有误!\n");
		   system("pause");
	 }
		
	  fstream fout(pathTxt,ios::out);
	 if(!fout.is_open())
	 {
		  printf("写txt有误!\n");
		   system("pause");
	 }

	   char temp[256];
	   string nameJpg;
	 while(getline(fin,nameJpg))
	 //while(fin.getline(temp,sizeof(temp)))
	 {
		string temp=nameJpg;

		temp.erase(0, temp.find_first_not_of(" \t"));
		temp.erase(temp.find_last_not_of(" \t") + 1);

		 nameJpg=temp;

		temp.replace(temp.find_last_of("."), 4,".txt");

		
		fstream fin1(temp,ios::in);
		if(!fin1.is_open())
		{
			printf("读txt1有误!\n");
			system("pause");
		}

		  string carName;int label; int x1;int y1;int x2;int y2;

		 fin1>>carName>>label>>x1>>y1>>x2>>y2;

		 fout<<nameJpg<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		 fin1.close();

	 }

	 fin.close();
	 fout.close();

	return 0;
}