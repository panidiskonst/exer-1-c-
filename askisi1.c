#include <iostream>
#include <fstream>
#include <vector>
//#include "MyFunc.h"
using namespace std;


//!targetFile.eof()
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}
unsigned long long PrevLcm(unsigned long long *arr,int cell){
	unsigned long long  result =1;
	if(cell==0) return arr[cell];	//check if we are at border already

	for ( int i=0; i<cell; i++){
	        result = lcm(arr[i], result);
	    }
	    return result;
	}

unsigned long long AheadLcm(unsigned long long *arr,int cell,int size){
	unsigned long long  result =1;

	//cout<<" cell "<<cell<<" result: ";
	if(cell==size-1) {
		//cout<<"gotcha"<<endl;
		return arr[size];
	}

	for ( int i=size-1; i>cell; i--){
	        result = lcm(arr[i], result);
	    }
	    return result;
	}
unsigned long long lcm(unsigned long long a, unsigned long long b)
{
	unsigned long long temp = gcd(a, b);
	if(temp>0) return ((b/temp)* a );
		else return 0;
    //return temp ? (a / temp * b) : 0;
}
int main(int argc, char *argv[]) {
   if (argc > 1) {


	   ifstream targetFile;
	   targetFile.open(argv[1]); //open txt given as argument

	   if(targetFile.fail()){			//give error message in case file doesnt open
		   cout<<"Error opening File"<<endl;
		   exit(1);
	   }

	   int villages,tmp,counter=0;
	   unsigned long long *vill,*tmp2,*tmp3;


	   targetFile >>villages;		//get first char which just gives number of villages
	   vill= new unsigned long long[villages];
	   	  // cout<<villages<<endl;
	   cout<<"hello world"<<end;
	   	   tmp2=vill;

	   	   while(!targetFile.eof()){		//get each char till you reach eof

	   		   //cout<<"entered loop "<<endl;
	   		   targetFile>>tmp;
	   		   *tmp2=tmp; //cout<<"tmp"<<tmp<<" what we got "<<*tmp2<<" at counter "<<counter<<endl;
	   		   tmp2++;
	   		   //xi.push_back(tmp); cout<<counter<<" "<<endl; counter++;


	   	   }
	   	   cout<<endl;




	   unsigned long long tmp5,result=lcm(PrevLcm(vill,0),AheadLcm(vill,0,villages));
	   int pistolVillage=0;




	  // cout<<"0:"<<" gives "<<result<<endl;

for(int i=1;i<villages;i++){

	tmp5=lcm(PrevLcm(vill,i),AheadLcm(vill,i,villages));

	//cout<<"i:"<<i<<" gives "<<tmp5<<endl;

	if(result>tmp5){
		result=tmp5; pistolVillage=i;counter++;
	}


}
 if(counter==villages){
	 cout<<result<<" 0";

 }
 else cout<<result<<" "<<pistolVillage+1;
return 0;


   }

   return 1;
}
