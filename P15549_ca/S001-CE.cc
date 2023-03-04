#include<iostream>
using namespace std;
void ordena_per_bombolla(vector<double>& v){
   int i, j,temp,pass=0;
   for(i = 0; i<10; i++) {
    for(j = i+1; j<10; j++)
    {
         if(a[j] < a[i]) {
           temp = v[i];
           v[i] = v[j];
          v[j] = temp;
        }
    }
   pass++;
   for(i = 0; i<10; i++) {
   cout <<a[i]<<endl;
   }
   return 0;
}

int main (){
   double v;
   while(cin>>v){
      ordena_per_bombolla(v);
   }
}