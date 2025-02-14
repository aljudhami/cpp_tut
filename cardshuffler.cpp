//Arrays of cards.cpp
#include <iostream>
#include <ctime>


using namespace std;
enum numbers{Jack=11, Queen, King, Ace};
enum Suit{clubs=1, diamonds, hearts, spades};
class card{
private:
    int number;
    Suit suit;
public:
    card(){};
    void setcard(int n, Suit s){
    suit=s; number=n;}
    void display();
};
void card::display(){
    if(number>=2 &&number<=10){
        cout<<number;
    }
    else
        switch(number){
            case Jack: cout<<"J"; break;
            case Queen: cout<<"Q"; break;
            case King: cout<<"K"; break;
            case Ace: cout<<"A"; break;
            default: cout<<"Enter a valid number";
        }
    switch(suit){
        case clubs: cout<<"\xE2\x99\xA3"; break;
        case diamonds: cout<<"\xE2\x99\xA6"; break;
        case hearts: cout<<"\xE2\x99\xA5"; break;
        case spades: cout<<"\xE2\x99\xA0"; break;
    }
}
int main(){
    card deck[52];
    int j;
    cout<<endl;
    for(j=0; j<52; j++){
        int num=(j%13)+2;
        Suit su=Suit((j/13)+1);
        deck[j].setcard(num, su);
    }
    cout<<"\nOrdered deck: \n";
    for(j=0; j<52;j++){
        deck[j].display();
        cout<<" ";
        if(!((j+1)%13))
            cout<<endl;
    }
    srand(time(NULL)); //seed random numbers with time
    for(j=0; j<52; j++){
        int k=rand()%52;
        card temp=deck[j];
        deck[j]=deck[k];
        deck[k]=temp;
    }
    cout<<"\nShuffled deck: \n";
    for(j=0; j<52; j++){
        deck[j].display();
        cout<<", ";
        if(!((j+1)%13))
            cout<<endl;
    }
return 0;
}
