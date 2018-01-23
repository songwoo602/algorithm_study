#include <iostream>
#include <vector>

using namespace std;

int pow10(int n){
    int result[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    return result[n];
}


int checkzeroFunc(int num){
    int fn = 0;
    vector<int > convNum;
    if ( num == 7||num == 18|| num == 29|| num ==70|| num==81||num==92) {
        return 1;
    }
 
    if(num < 10){
        if ( num == 7) {
            return 1;
        }
        return 0;
    }
    
    
    while(num != 0){
        convNum.push_back(num % 10);
        num /= 10;
    }

    int subNum = 0;
    int sum = 0;
   
    for (vector<int>::iterator it = convNum.begin() +1; it != convNum.end(); ++it){
        subNum = (*it)-(*(it-1));
        if (subNum < 0) subNum*=(-1);
        sum += subNum*pow10((it-convNum.begin()-1));
    }
    return checkzeroFunc(sum);
}


int main(void){
    int min, max = 0;
    cin >>min>>max;
    int sum = 0;
    for (int i = min; i <= max; ++i){
        sum += checkzeroFunc(i);
    }
    cout <<sum<<endl;
    return 0; 
}
