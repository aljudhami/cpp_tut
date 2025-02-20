#include <iostream>
#include <string>
using namespace std;
// Note: This project demonstrates how user-defined type conversion occurs in source or destination objects: time12 is set as the destination and time24 is set as the source
/* For converion to take place in the destination
class time24{
private:
    int hr;
    int mt;
    int sc;
public:
    time24(): hr(0), mt(0), sc(0){};
    time24(int hour, int minute, int second): hr(hour), mt(minute), sc(second){}
    int get_hr() const{return hr;}   //defined getter functions to grant time12 access to time24 data members
    int get_min() const{return mt;}
    int get_sec() const{return sc;}
    void display(){
        if(hr<10){cout<<"0";}
        cout<<hr<<":";
        if(mt<10){cout<<"0";}
        cout<<mt<<":";
        if(sc<10){cout<<"0";}
        cout<<sc;
    }
};
class time12{
private:
    int hr;
    int mt;
    bool pm;
public:
    time12(): hr(0), mt(0), pm(true){}
    time12(int hour, int minute, bool period): hr(hour), mt(minute), pm(period){}
    time12 (const time24 t24){                                                    //conversion takses place here using a one-arg cstor
        int hr24=t24.get_hr();
        mt=(t24.get_sec()>30)? (t24.get_min())+1:t24.get_min();
        if(mt==60){
            hr24++;
            mt=0;
        }
        hr24=(hr24==24)?hr24=0: hr24;
        pm=(hr24<12)?false: true;
        hr=(hr24<13)?hr24:hr24-12;
        hr=(hr24==0)?12:hr;
    }
    void display(){
        if(hr<10){cout<<"0";}
        cout<<hr<<":";
        if(mt<10){cout<<"0";}
        cout<<mt<<" ";
        string per;
        if (pm){
            per="p.m.";
        }
        else per="a.m";

        cout<<" "<<per;
    }
};
*/
/* Conversion takes place using the operator time12 defined in time24 class */
class time12{
	private:
	    bool pm;
	    int hrs, mins;
	public:
	    time12(): pm(true), hrs(0), mins(0){}
	    time12(bool ap, int h, int m): pm(ap), hrs(h), mins(m){}
	    void display() const{  //format: 11:59 p.m.
	        cout<<hrs<<":";
	        if(mins<10)
	            cout<<'0';
	        cout<<mins<<" ";
	        string am_pm= pm? "p.m.": "a.m.";
	        cout<<am_pm;
	    }
};
class time24{
	private:
	    int hours;
	    int minutes;
	    int seconds;
	public:
	    time24(): hours(0), minutes(0), seconds(0){}
	    time24(int h, int m, int s): hours(h), minutes(m), seconds(s){}
	    void display () const{
	        if(hours<10) cout<<"0";
	        cout<<hours<<":";
	        if(minutes<10) cout<<"0";
	        cout<<minutes<<":";
	        if(seconds<10) cout<<"0";
	        cout<<seconds;
	    }
	    operator time12() const;    //conversion takes place using this operator function
};
time24::operator time12() const{
    int hrs24= hours;
    bool pm = hours<12 ? false: true;
    int roundminutes= seconds<30? minutes: minutes+1;
    if(roundminutes==60){
        ++hrs24;
        roundminutes=0;
        if(hrs24==12 || hrs24==24){
            pm=(pm)? false: true;
        }
    }
    int hrs12= (hrs24<13)? hrs24: hrs24-12;
    if(hrs12==0){
        hrs12=12; pm=false;
    }
    return time12(pm, hrs12, roundminutes);
}
/*Here ends the class defintions in which conversion operation is defined to take place in the source object (of class time24)*/
int main(){
    int h, m, s;
    while(true){
        cout<<"Enter 24-hour time: \n";
        cout<<"     hour(0 to 23): "; cin>>h;
        if(h>23)
            return(1);
        cout<<"     minutes: "; cin>>m;
        cout<<"     seconds: ";cin>>s;
        time24 t24(h, m, s);
        cout<<"You entered: ";
        t24.display();
        time12 t12=t24; //convert time24 to time12
        cout<<"\n12-hour time: ";
        t12.display();
        cout<<"\n\n";
    }
    return 0;
}
