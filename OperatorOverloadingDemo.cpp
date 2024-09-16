#include <iostream>

//creating a struct so all member variables are public and accessible
struct coolKid{
    std::string name;
    int age;
    float money;

    //default constructor
    coolKid(){
        name = "Ferb";
        age = 23;
        money = 0;
    }

    //parameterized constructor
    coolKid(std::string name, int age, float money){
        this->name = name;
        this->age = age;
        this->money = money;
    }

    //copy assignment operator
    coolKid& operator=(const coolKid &example){
        this->name = example.name;
        this->age = example.age;
        this->money = example.money;
        return *this;
    }

    void operator+=(float num){
        money += num;
    }

    void operator+=(int num){ //parameter passed in is now int!
        age += num;
    }

    //parameter passed in is now string
    void operator+=(const std::string &lastName){ //const to ensure lastName passed in isn't changed
        name += " " + lastName;
    }

};

int main(){

    coolKid Perry("Perry", 20, 100.00f);
    std::cout << Perry.name << " is " << Perry.age << " and has $" << Perry.money << std::endl;

    //We want to give $50.00 to Perry
    Perry += 50.00f;
    std::cout << Perry.name << " now has $" << Perry.money << std::endl;
    //prints: "Perry now has $150" (IT WORKS!)


    Perry += 3; //change Perry's age from 20 to 23 by adding an int
    std::cout << Perry.name << " is now " << Perry.age << std::endl; //prints "Perry is now 23"
    std::cout << Perry.name << " still has $" << Perry.money << std::endl; //and his $150 money hasn't changed

    //we want to add a last name
    Perry += "THE PLATYPUS";
    std::cout << "PERRY?!! ... " << Perry.name << std::endl; //prints "PERRY?!! ... Perry THE PLATYPUS"
    //now we know his real identity

    return 0;
}