// C++ program to generate random numbers
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <fstream> 
using namespace std;

void ganarate_random_number(int number_of_genarations,int low,int up,string filename){
   
  // int arr[],
    int a= 200000;
    int array[a];
    int array_length=0;
    //  int up = 100;
    //   int low = 90;
    srand(time(0));
    fstream myFile;
    myFile.open(filename, ios::out);// write
    if (myFile.is_open())
    {
      cout <<  "file has been created \n\n";
      for (int i = 0; i < number_of_genarations; i++){
        array[array_length]= rand()%(up-low) +low;
        myFile<<array[array_length]<<"\n";
        array_length +=1;
        //cout <<  array[array_length] << " ";
    }
    myFile.close();
    }
    
    


  //return 0;
}
 
int main()
{
  int a=1;

  do
   {cout<<"enter 1 generate a data set:\nenter 2 to stope the program:\n";
  cin>>a;

  
  if (a==1)
  {    
      int number_of_genarations;
   int low;
   int up;
   string filename;
   cout<<"enter the number of data set you want to generate (it must be in 1 to 200000): ";
   cin>>number_of_genarations;
    cout<<"enter the  loest number you waht to start with: ";
   cin>>low;
    cout<<"enter the  hiest number you waht to start with: ";
   cin>>up;
    cout<<"enter the file name (it must have [.text] at the end): ";
   cin>>filename;
   ganarate_random_number( number_of_genarations, low, up,filename);
   //ganarate_random_number(int number_of_genarations,int low,int up,string filename)

  }
  
else if (a==2)
{
  exit(0);
}
   
   } while (a == 1);
  
    return 0;
}