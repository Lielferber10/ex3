//created by liel ferber and ori dekel in 22/05/2022

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Queue
{
    struct Node
    {
        Node *previous;
        Node *next;
        int value;
    }
    public:
    
    explicit HealthPoints(int maxHealthPoints = 100); //constractur
    HealthPoints(const HealthPoints& healthPoints); //copy constractur
    ~HealthPoints() = default; //destractur
    void operator=(const HealthPoints& healthPoints); //assignment operator
    void operator=(const int healthPointsValue); //assignment operator
    HealthPoints& operator+=(const int healthPointsValue); //+= operator
    HealthPoints& operator-=(const int healthPointsValue); //-= operator
    class InvalidArgument {};
    


    private:

    Node first;
    Node last;

    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //== operator
    friend bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //> operator
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints); //printing operator


};
HealthPoints& operator+(const HealthPoints& healthPoints, int healthPointsValue); //+ operator
HealthPoints& operator+(int healthPointsValue, const HealthPoints& healthPoints); //+ operator
HealthPoints& operator-(const HealthPoints& healthPoints, const int healthPointsValue); //- operator
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //!= operator
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //>= operator
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //<= operator
bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //< operator
void healthPointsBounds(int currentHealthPoints, int maxHealthPoints);