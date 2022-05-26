//created by liel ferber and ori dekel in 22/05/2022
#include "HealthPoints.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


//constractur
HealthPoints::HealthPoints(int maxHealthPoints):
m_currentHealthPoints(maxHealthPoints),
m_maxHealthPoints(maxHealthPoints)
{
    if(maxHealthPoints<=0)
    {
        throw HealthPoints::InvalidArgument();
    }
    cout << "ctor" << endl;
} 


//assignment operators
void HealthPoints::operator=(const HealthPoints& healthPoints)
{
    this->m_currentHealthPoints = healthPoints.m_currentHealthPoints;
    this->m_maxHealthPoints = healthPoints.m_maxHealthPoints;
}

void HealthPoints::operator=(const int healthPointsValue)
{
    this->m_currentHealthPoints = healthPointsValue;
    this->m_maxHealthPoints = healthPointsValue;
}

//adding operators
HealthPoints& operator+(const HealthPoints& healthPoints, int healthPointsValue)
{
    HealthPoints tempHealthPoints(DEFAULT_MAX_HEALTH);
    HealthPoints& healthPointsResult = tempHealthPoints;
    healthPointsResult.operator=(healthPoints);
    healthPointsResult.operator+=(healthPointsValue);
    return healthPointsResult;
}

HealthPoints& operator+(int healthPointsValue, const HealthPoints& healthPoints)
{
    return operator+(healthPoints, healthPointsValue);
}

//subtraction  operator
HealthPoints& operator-(const HealthPoints& healthPoints, int healthPointsValue)
{
    return operator+(healthPoints, -healthPointsValue);
}

//+= operator
HealthPoints& HealthPoints::operator+=(int healthPointsValue) 
{
    this->m_currentHealthPoints += healthPointsValue;
    if(this->m_currentHealthPoints < 0)
    {
        this->m_currentHealthPoints = 0;
    }
    if(this->m_currentHealthPoints > this->m_maxHealthPoints)
    {
        this->m_currentHealthPoints = this->m_maxHealthPoints;
    }
    return *this;
}

//-= operator
HealthPoints& HealthPoints::operator-=(int healthPointsValue) 
{
    return HealthPoints::operator+=(-healthPointsValue);
}

//comparison operator
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(healthPoints1.m_currentHealthPoints == healthPoints2.m_currentHealthPoints)
    {
        return true;
    }
    return false;
}

//> operator
bool operator>(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(healthPoints1.m_currentHealthPoints > healthPoints2.m_currentHealthPoints)
    {
        return true;
    }
    return false;
}

//!= operator
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !operator==(healthPoints1, healthPoints2);
}

//>= operator
bool operator>=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(operator==(healthPoints1, healthPoints2) || operator>(healthPoints1, healthPoints2))
    {
        return true;
    }
    return false;
}

//<= operator
bool operator<=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(operator==(healthPoints1, healthPoints2) || !operator>(healthPoints1, healthPoints2))
    {
        return true;
    }
    return false;
}


//< operator
bool operator<(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(!operator>=(healthPoints1, healthPoints2))
    {
        return true;
    }
    return false;
}

//printing operator
std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints)
{
    os << healthPoints.m_currentHealthPoints << "(" << healthPoints.m_maxHealthPoints << ")";
    return os;
}

int printing(const HealthPoints& hp1)
{
    return hp1.m_currentHealthPoints;
}

int printingmax(const HealthPoints& hp2)
{
    return hp2.m_maxHealthPoints;
}



int main()
{
    HealthPoints Hp1 = 100;
    HealthPoints Hp2(150);
    HealthPoints hp1 = Hp1;
    HealthPoints hp2 = Hp2;
    HealthPoints hp3 = hp2;
    cout << "hp3:" << printing(hp3) <<endl;
    hp1 -= 20; /* now has 80 points out of 100 */
    cout << "hp1:" << printing(hp1) <<endl;
    hp1 +=100; /* now has 100 points out of 100 */
    cout << "hp1:" << printing(hp1) <<endl;
    hp1 -= 150; /* now has 0 points out of 100 */
    cout << "hp1:" << printing(hp1) <<endl;
    hp2 = hp2 - 160; /* now has 0 points out of 150 */
    cout << "hp2:" << printing(hp2) <<endl;
    hp2 = 160 + hp1;
    cout << "hp2:" << printing(hp2) << " , " << printingmax(hp2) <<endl;
    return 0;
}