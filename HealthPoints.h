//created by liel ferber and ori dekel in 22/05/2022

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const int DEFAULT_MAX_HEALTH = 100;

class HealthPoints
{
    public:
    
    HealthPoints(int maxHealthPoints = DEFAULT_MAX_HEALTH); //constractur
    HealthPoints(const HealthPoints& healthPoints) = default; //copy constractur
    ~HealthPoints() = default; //destractur
    void operator=(const HealthPoints& healthPoints); //assignment operator
    void operator=(const int healthPointsValue); //assignment operator
    HealthPoints& operator+=(const int healthPointsValue); //+= operator
    HealthPoints& operator-=(const int healthPointsValue); //-= operator
    class InvalidArgument {};
    


    private:

    int m_currentHealthPoints;
    int m_maxHealthPoints;

    friend bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //>= operator
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints); //printing operator

};
HealthPoints& operator+(const HealthPoints& healthPoints, const int healthPointsValue); //+ operator
HealthPoints& operator+(const int healthPointsValue, const HealthPoints& healthPoints); //+ operator
HealthPoints& operator-(const HealthPoints& healthPoints, const int healthPointsValue); //- operator
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //>= operator
bool operator>=(const HealthPoints& healthPoints1, const int healthPointsValue); //>= operator
bool operator>=(const int healthPointsValue, const HealthPoints& healthPoints1); //>= operator
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //== operator
bool operator==(const HealthPoints& healthPoints1, const int healthPointsValue); //== operator
bool operator==(const int healthPointsValue, const HealthPoints& healthPoints1); //== operator
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //!= operator
bool operator!=(const HealthPoints& healthPoints1, const int healthPointsValue); //!= operator
bool operator!=(const int healthPointsValue, const HealthPoints& healthPoints1); //!= operator
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //<= operator
bool operator<=(const HealthPoints& healthPoints1, const int healthPointsValue); //<= operator
bool operator<=(const int healthPointsValue, const HealthPoints& healthPoints1); //<= operator
bool operator>(const HealthPoints& healthPoints1, const int healthPointsValue); //> operator
bool operator>(const int healthPointsValue, const HealthPoints& healthPoints1); //> operator
bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2); //< operator
bool operator<(const HealthPoints& healthPoints1, const int healthPointsValue); //< operator
bool operator<(const int healthPointsValue, const HealthPoints& healthPoints1); //< operator