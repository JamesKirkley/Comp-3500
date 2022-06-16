#include <iostream>

using namespace std;

int main()
{
   int arr[100];
   int group[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   int start = -1;

 

   //part a taking input
   cout<<"Enter 100 digits under the range 0 to 99"<<endl;
   
   for(int i = 0 ; i< 100; i++)
   {
       cin>>arr[i];
   }
   //end part a;

 

   //part b 
   for(int i = 0 ; i< 100; i++)
   {
      if(0 <= arr[i] && arr[i] < 10)
       {
           group[0]++;
       }
       if(10 <= arr[i] && arr[i] < 20)
       {
           group[1]++;
       }
       if(20 <= arr[i] && arr[i] < 30)
       {
           group[2]++;
       }
       if(30 <= arr[i] && arr[i] < 40)
       {
           group[3]++;
       }
       if(40 <= arr[i] && arr[i] < 50)
       {
           group[4]++;
       }
       if(50 <= arr[i] && arr[i] < 60)
       {
           group[5]++;
       }
       if(60 <= arr[i] && arr[i] < 70)
       {
           group[6]++;
       }
       if(70 <= arr[i] && arr[i] < 80)
       {
           group[7]++;
       }
       if(80 <= arr[i] && arr[i] < 90)
       {
           group[8]++;
       }
       if(90 <= arr[i] && arr[i] < 100)
       {
           group[9]++;
       }
   }
   //end part b

 

   //part c
   for(int j = 0 ; j < 10 ; j++)
   {
       start = start+1;
       cout<<"Group "<<j+1<<" ("<<start<<".."<<start+9<<")"<<group[j]<<endl;
       start = start+9;
   }
   //end part c
   return 0;
}