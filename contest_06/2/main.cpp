#include<iostream>
#include<string>
#include<map>

std::map<std::string, double> bonuses;

// Ваш код здесь

using namespace std;

class Employee {
protected:
    string name, position;
    int salary;

public:
    Employee(string name, string position, int salary) {
        this->name = name;
        this->position = position;
        this->salary = salary;
    }
    virtual int bonus(double percent) const {
        int init_int = (salary * percent) + 0.50;
        return init_int;
    }
    friend ostream& operator<<(ostream& ostr, const Employee& empl) {
        ostr << empl.name << " (" << empl.position << "): " << empl.salary + empl.bonus(bonuses[empl.position]);
        return ostr;
    }
};

class Manager : public Employee {
public:
    Manager(string name, int salary = 16242) : Employee(name, "manager", salary){}

    int bonus(double percent) const {
        if (percent < 0.10) {
            percent = 0.10;
        }
        int init_int = (salary * percent) + 0.50;
        return init_int;
    }
};

class Boss: public Employee{
public:
    Boss(std::string name, int money = 16242)
            :Employee(name, "boss", money){
    }
};

int main(){
    double boss_bonus, manager_bonus;
    std::cin >> boss_bonus >> manager_bonus;
    bonuses["manager"] = manager_bonus;
    bonuses["boss"] = boss_bonus;

    int john_money, bob_money, alice_money;
    std::cin >> john_money >> bob_money >> alice_money;
    Boss john("John", john_money);
    Manager bob("Bob", bob_money);
    Manager alice("Alice", alice_money);

    std::cout << john << '\n' << bob << '\n' << alice << std::endl;
}