#include <iostream>
#include <deque>

// Ваш код будет вставлен сюда

class Water {
public:
    Water(int i) {
        temperature = i;
    }
    int get_temperature(){
        return temperature;
    }
private:
    int temperature;
};

class Teapot {
public:
    Teapot(Water my_water) {
        temp_at_the_moment = my_water.get_temperature();
    }

    bool is_boiling() {
        if (temp_at_the_moment >= 100) {
            return true;
        }
        return false;
    }
    void heat_up(int value) {
        temp_at_the_moment += value;
    }

private:
    int temp_at_the_moment;
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;

    Water water(temperature);
    Teapot teapot(water);

    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }

    for(auto t : heat) std::cout << t << ' ';
}