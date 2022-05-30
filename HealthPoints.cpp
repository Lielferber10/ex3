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
HealthPoints& operator+(const HealthPoints& healthPoints, const int healthPointsValue)
{
    HealthPoints tempHealthPoints(DEFAULT_MAX_HEALTH);
    HealthPoints& healthPointsResult = tempHealthPoints;
    healthPointsResult.operator=(healthPoints);
    healthPointsResult.operator+=(healthPointsValue);
    return healthPointsResult;
}

HealthPoints& operator+(int const healthPointsValue, const HealthPoints& healthPoints)
{
    return operator+(healthPoints, healthPointsValue);
}


//subtraction operator
HealthPoints& operator-(const HealthPoints& healthPoints, const int healthPointsValue)
{
    return operator+(healthPoints, -healthPointsValue);
}


//+= operator
HealthPoints& HealthPoints::operator+=(const int healthPointsValue) 
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
HealthPoints& HealthPoints::operator-=(const int healthPointsValue) 
{
    return HealthPoints::operator+=(-healthPointsValue);
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

bool operator>(const HealthPoints& healthPoints1, const int healthPointsValue)
{
    HealthPoints tempHealthPoints(healthPointsValue);
    HealthPoints& healthPoints2 = tempHealthPoints; 
    return operator>(healthPoints1, healthPoints2);
}

bool operator>(const int healthPointsValue, const HealthPoints& healthPoints1)
{
    return operator>(healthPoints1, healthPointsValue);
}



//comparison operator
bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(!operator>(healthPoints1, healthPoints2) && !operator>(healthPoints2, healthPoints1))
    {
        return true;
    }
    return false;
}

bool operator==(const HealthPoints& healthPoints, const int healthPointsValue)
{
    if(!operator>(healthPoints, healthPointsValue) && !operator>(healthPointsValue, healthPoints))
    {
        return true;
    }
    return false;
}

bool operator==(const int healthPointsValue, const HealthPoints& healthPoints)
{
    return operator==(healthPoints, healthPointsValue);
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

bool operator>=(const HealthPoints& healthPoints, const int healthPointsValue)
{
    if(operator==(healthPoints, healthPointsValue) || operator>(healthPoints, healthPointsValue))
    {
        return true;
    }
    return false;
}

bool operator>=(const int healthPointsValue, const HealthPoints& healthPoints)
{
    return operator>=(healthPoints, healthPointsValue);
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

bool operator<=(const HealthPoints& healthPoints1, const int healthPointsValue)
{
    HealthPoints tempHealthPoints(healthPointsValue);
    HealthPoints& healthPoints2 = tempHealthPoints; 
    return operator<=(healthPoints1, healthPoints2);
}

bool operator<=(const int healthPointsValue, const HealthPoints& healthPoints1)
{
    return operator<=(healthPoints1, healthPointsValue);
}



//!= operator
bool operator!=(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    return !operator==(healthPoints1, healthPoints2);
}

bool operator!=(const HealthPoints& healthPoints1, const int healthPointsValue)
{
    HealthPoints tempHealthPoints(healthPointsValue);
    HealthPoints& healthPoints2 = tempHealthPoints; 
    return !operator==(healthPoints1, healthPoints2);
}

bool operator!=(const int healthPointsValue, const HealthPoints& healthPoints1)
{
    return operator!=(healthPoints1, healthPointsValue);
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

bool operator<(const HealthPoints& healthPoints1, const int healthPointsValue)
{
    HealthPoints tempHealthPoints(healthPointsValue);
    HealthPoints& healthPoints2 = tempHealthPoints; 
    return operator<(healthPoints1, healthPoints2);
}

bool operator<(const int healthPointsValue, const HealthPoints& healthPoints1)
{
    HealthPoints tempHealthPoints(healthPointsValue);
    HealthPoints& healthPoints2 = tempHealthPoints; 
    return operator<(healthPoints1, healthPoints2);
}



//printing operator
std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints)
{
    os << healthPoints.m_currentHealthPoints << "(" << healthPoints.m_maxHealthPoints << ")";
    return os;
}



