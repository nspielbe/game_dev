#include <iostream>


class Time
{
    public:
        void Init(int hour, int minute, int second);
        void Display_12();
        void Display_24();

    private:
        int _hour;
        int _minute;
        int _second;
};

void Time::Init(int hour, int minute, int second)
{
    _hour = hour;
    _minute = minute;
    _second = second;
}

void Time::Display_24()
{
    std::cout << "The Time in 24 Hour Format is: "
    << _hour << ":" << _minute << ":" << _second << std::endl;
}

void Time::Display_12()
{
    int remainder = _hour % 12;

    if (_hour > 11 and _hour < 24) 
    {

        std::cout << "The Time in 12 Hour Format is: "
    << (remainder == 0 ? 12 : remainder) << ":" << _minute << ":" << _second <<  " pm " << std::endl;
    
    }

    else{

         std::cout << "The Time in 12 Hour Format is: "
    << (_hour == 24 ? 12 : _hour)  << ":" << _minute << ":" << _second <<  " am " << std::endl;
    
    }
}

int main(){
    Time time;
    time.Init(24, 2, 1);
    time.Display_24();
    time.Display_12();

    return 0;
}