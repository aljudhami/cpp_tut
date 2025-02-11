//CARDOBJ
#include <iostream>
using namespace std;

enum Suit{Clubs, Hearts, Diamonds, Spades};
const int jack=11;
const int queen =12;
const int king=13;
const int ace= 14;

class card{
private:
    int number;
    Suit suit;
public:
    card(){}
    card(int n, Suit s): number(n), suit(s){}
    int display();
    bool isEqual(card);
    void switcher(card&);
};

int card::display(){
    if(number>=2 && number <=10){
        cout<< number <<" of ";
    }
    else{
        switch(number){
            case jack: cout<<"jack of "; break;
            case queen: cout<<"queen of "; break;
            case king: cout<<"king of "; break;
            case ace: cout<<"ace of "; break;
            default: cout<<"NO valid value"; return -1;
        }
    }
    switch(suit){
        case Clubs: cout<<"clubs"; break;
        case Hearts: cout<<"hearts"; break;
        case Diamonds: cout<<"Diamonds"; break;
        case Spades: cout<<"spades"; break;
    }
return 0;
}
bool card::isEqual(card c2){
    return ((number==c2.number) && (suit==c2.suit))? true: false;
}
void card::switcher(card& c){
    card temp;
    temp.number=c.number;
    temp.suit=c.suit;
    c.number=number;
    c.suit=suit;
    number=temp.number;
    suit=temp.suit;
}

int main(){
    card chosen, prize;
    int position;
    card card1(7, Clubs);
    cout<<"Card 1 is the: ";
    card1.display();
    card card2(jack, Hearts);
    cout<<"\nCard 2 is the: ";
    card2.display();
    card card3(ace, Spades);
    cout<<"\ncard 3 is the: ";
    card3.display();

    prize=card3;
    cout<<"\nI'm swapping card 3 with card 1"<<endl;
    card3.switcher(card1);

    cout<<"I'm swapping card 2 with card 3"<<endl;
    card2.switcher(card3);

    cout<<"I'm swapping card 1 with card 2"<<endl;
    card1.switcher(card2);

    cout<<"I'm swapping card 1 with card 3"<<endl;
    card1.switcher(card3);

    cout<<"Now you choose which card is ";
    prize.display();
    cout<<"(1, 2, or 3)?"<<endl;
    cin>>position;
    while(!(position<4 && position>0)){
        cout<<"Enter a valid number"<<endl;
        cin>>position;
    }
    switch(position){
        case 1: chosen=card1; break;
        case 2: chosen=card2; break;
        case 3: chosen=card3; break;
    }

    if(chosen.isEqual(prize)){
        cout<<"\nYou won!"<<endl;
    }
    else{
        cout<<"\nSorry you lose"<<endl;
    }
    return 0;
}
