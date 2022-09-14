#include<iostream>
#include<string>
using namespace std;

//doubleDigit function is an utility function to get the sum of digits of double digit numbers. 
int doubleDigit(int digit) {
    if(digit<9) return digit;
    return digit%10+digit/10;
}

//checkValid function is used to check whether the card number is valid or not using Luhn's Algorithm.   
bool checkValid(long const num) {
    string numString=to_string(num);
    int n=numString.length();
    int evenSum=0, oddSum=0;
    for(int i=1; i<=n; i++) {
        if(i%2!=0) {
            oddSum+=doubleDigit(int(numString[i-1]-'0')*2);
        }
        else {
            evenSum+=numString[i-1]-'0';
        }
    }
    if((evenSum+oddSum)%10) return true;
    return false;
}

//cardNetwork function checks various conditions of different card networks. 
string cardNetwork(long const num) {
    string numString=to_string(num);
    if(numString[0]=='4' && (numString.length()==16 ^ numString.length()==13)) return "VISA";
    else if(numString.length()==16 && numString[0]=='5') return "MASTERCARD";
    else if(numString.length()==16 && numString[0]=='6') return "DISCOVER";
    else if(numString.length()==15 && numString[0]=='3' && (numString[1]=='4' ^ numString[1]=='7')) return "AMERICAN EXPRESS";
    else return "NETWORK NOT FOUND";
}

int main() {
    cout<<"Enter your Card Number: ";
    long cardNumber;
    cin>>cardNumber;
    if(checkValid(cardNumber)) {
        cout<<"Invalid Card";
        return 0;
    }
    cout<<cardNetwork(cardNumber)<<endl;
}