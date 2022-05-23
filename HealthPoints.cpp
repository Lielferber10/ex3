//created by liel ferber and ori dekel in 22/05/2022
#include "HealPoints.h"
#include <Stdlib.h>
#include <Stdio.h>



//constractur
HealthPoints::healthPoints(const int maxHealPoints = 100): 
m_currentHealPoints(maxHealPoints), m_maxHealPoints(maxHealPoints)
{
    if(maxHealPoints<=0)
    {
        throw HealthPoints::InvalidArgument;
    }
} 

//copy constractur
HealthPoints::healthPoints(const healthPoints&):
m_currentHealPoints(healthPoints.m_currentHealPoints),
m_maxHealPoints(healthPoints.m_maxHealPoints)
{

}

//assignment operators
HealthPoints& HealthPoints::operator=(const healthPoints&)
{
    this->m_currentHealPoints = healthPoints.m_currentHealPoints;
    this->m_maxHealPoints = healthPoints.m_maxHealPoints;
}

HealthPoints& HealthPoints::operator=(const int healthPointsValue)
{
    this->m_currentHealPoints = healthPointsValue;
    this->m_maxHealPoints = healthPointsValue;
}

//adding operators
healthPoints& HealthPoints::operator+(const healthPoints&, int healthPointsValue)
{
    HealPoints healpointsResult;
    healpointsResult.m_currentHealPoints = healthPoints.m_currentHealPoints + healthPointsValue;
    healpointsResult.m_maxHealPoints = healthPoints.m_maxHealPoints;
    healpointsResult.healthPointsBounds();
    return healpointsResult&;
}

healthPoints& HealthPoints::operator+(int healthPointsValue, const healthPoints&)
{
    return HealthPoints::operator+(healthPoints, healthPointsValue);
}

//subtraction  operator
healthPoints& HealthPoints::operator-(const healthPoints&, int healthPointsValue)
{
    return HealthPoints::operator+(healthPoints, -healthPointsValue)
}

//+= operator
void HealthPoints::operator+=(int healthPointsValue) 
{
    this->m_currentHealPoints += healthPointsValue;
    healpoints.healthPointsBounds();
}

//-= operator
void HealthPoints::operator-=(int healthPointsValue) 
{
    HealthPoints::operator+=(-healthPointsValue);
}

//comparison operator
bool HealthPoints::operator==(const healthPoints&) const
{
    if(this->m_currentHealPoints == healpoints.m_currentHealPoints)
    {
        return true;
    }
    return false;
}

//!= operator
bool HealthPoints::operator!=(const healthPoints&) const
{
    return !HealthPoints::operator==(healthPoints);
}

//>= operator
bool HealthPoints::operator>=(const healthPoints&) const
{
    if(this->m_currentHealPoints >= healpoints.m_currentHealPoints)
    {
        return true;
    }
    return false;
}

//<= operator
bool HealthPoints::operator<=(const healthPoints&) const
{
    if(this->m_currentHealPoints <= healpoints.m_currentHealPoints)
    {
        return true;
    }
    return false;
}

//> operator
bool HealthPoints::operator>(const healthPoints&) const
{
    return !HealthPoints::operator<=(const healthPoints&);
}

//< operator
bool HealthPoints::operator<(const healthPoints&) const
{
    return !HealthPoints::operator>=(healthPoints&);
}

//printing operator
Std::ostream& operator<<(Std::osstream& os, const healthPoints&)
{
    os << healpoints.m_currentHealPoints << "(" << healpoints.m_maxHealPoints << ")";
    return os;
}

friend void healthPointsBounds() const
{
    if(this->m_currentHealPoints < 0)
    {
        this->m_currentHealPoints = 0;
    }
    if(this->m_currentHealPoints > this->m_maxHealPoints)
    {
        this->m_currentHealPoints = this->m_maxHealPoints;
    }
} 