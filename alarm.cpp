// ALARM 
// 21:04
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <sstream>
using namespace std;
class ALARM{
    public:
        tm alarmtime,presenttime,differancetime;
        time_t now;
        ALARM(){ // constractor
            now = time(0);
            presenttime= *localtime(&now);
            alarmtime = presenttime;
            alarmtime.tm_sec = 0;
        }
        void GetTime(){
            string time;
            cout<<"Enter What Time Do You Want To Remember You\nin 24-hours format [HH:MM] : "<<endl;
            getline(cin,time);
            int pos = 0,h;
            while((pos=time.find(':')) != string::npos){
                string token = time.substr(0,pos);
                stringstream convert(token);
                convert >> alarmtime.tm_hour;
                time.erase(0,pos+1);
            }
            stringstream convert(time);
            convert >> alarmtime.tm_min;
        }
        void TimeDiff(){
            int sec = difftime(mktime(&alarmtime),now);
            differancetime.tm_min = sec / 60;
            differancetime.tm_hour = differancetime.tm_min / 60;
            differancetime.tm_min = differancetime.tm_min % 60;
            differancetime.tm_sec = sec % 60;
            if (sec<0){
                differancetime.tm_hour = 24 + differancetime.tm_hour-1;
                differancetime.tm_min = 0 - differancetime.tm_min;
                differancetime.tm_sec = 0 - differancetime.tm_sec;
            }

        }
        void StartAlarm(){
            while (true){
                system("cls");
                now = time(0);
                presenttime= *localtime(&now);
                TimeDiff();
                cout << "Time Running:    " << differancetime.tm_hour<<":"<< differancetime.tm_min<<":"<<differancetime.tm_sec;
                if(differancetime.tm_hour==0 && differancetime.tm_min==0 && differancetime.tm_sec==0){
                    cout<<"Time Is Ended ....."<<endl;
                    system("pause");
                    break;

                }
            }
        }
};
int main(){
    ALARM a;
    a.GetTime();
    a.StartAlarm();
    for(int i;;i=i+50){
        Beep(i, 1000);
    }
    return 0;
}