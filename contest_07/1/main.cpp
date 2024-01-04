#include <iostream>

struct Time{
    short hours;
    short minutes;
    short seconds;

    void addSeconds(short count){
        seconds += count;
        if (seconds >= 60){
            count = seconds / 60;
            seconds %= 60;
        } else return;

        minutes += count;
        if (minutes >= 60){
            count = minutes / 60;
            minutes %= 60;
        } else return;

        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs){
    return lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs){
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable{
public:
    virtual void run() = 0;
};

class IClock{
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

// Ваш код здесь

#include <queue>

using namespace std;

class OSUpdater: public IRunnable {
public:
    void run() override{
        cout << "OSUpdater" << endl;
    }
};

class Alarm: public IRunnable {
public:
    void run() override {
        cout << "Alarm" << endl;
    }
};

class ActivityChecker: public IRunnable {
public:
    void run() override {
        cout << "ActivityChecker" << endl;
    }
};

class Clock: public IClock,public IRunnable {
private:
    queue<pair<Time,IRunnable*>> timer;
public:
    void add(IRunnable* client, Time time) override{
        timer.push({time, client});
    }
    bool next() override{
        if (timer.empty()) {
            return false;
        }
        auto pointer = timer.front();
        timer.pop();

        string minutes,hours,seconds;

        if (pointer.first.hours < 10) {
            hours = "0";
        }
        hours += to_string(pointer.first.hours);

        if (pointer.first.minutes < 10) {
            minutes = "0";
        }
        minutes += to_string(pointer.first.minutes);

        if (pointer.first.seconds < 10) {
            seconds = "0";
        }
        seconds += to_string(pointer.first.seconds);

        cout << hours << ":" << minutes << ":" << seconds << " ";
        pointer.second->run();
        return true;
    }
    void run() override {
        while(next());
    }
};

int main(){
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность

    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;

    Time t = {0, 0, 0}, midnight = {0, 0, 0};

    do{
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    }while(t != midnight);

    timer->run();
}
