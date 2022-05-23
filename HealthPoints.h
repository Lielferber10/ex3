//created by liel ferber and ori dekel in 22/05/2022

#include <Stdlib.h>
#include <Stdio.h>

class HealthPoints
{
    public:
    
    explicit healthPoints(const int maxHealPoints = 100); //constractur
    healthPoints(const healthPoints&) const; //copy constractur
    ~healthPoints(); //destractur
    HealthPoints& operator=(const healthPoints&); //assignment operator
    HealthPoints& operator=(const int healthPointsValue); //assignment operator
    explicit HealthPoints& operator+(const healthPoints&, int healthPointsValue); //+ operator
    explicit HealthPoints& operator+(int healthPointsValue, const healthPoints&); //+ operator
    explicit HealthPoints& operator-(const healthPoints&, const int healthPointsValue); //- operator
    void operator+=(const int healthPointsValue); //+= operator
    void operator-=(const int healthPointsValue); //-= operator
    bool operator==(const healthPoints&) const; //== operator
    bool operator!=(const healthPoints&) const; //!= operator
    bool operator>=(const healthPoints&) const; //>= operator
    bool operator<=(const healthPoints&) const; //<= operator
    bool operator>(const healthPoints&) const; //> operator
    bool operator<(const healthPoints&) const; //< operator
    friend Std::ostream& operator<<(Std::osstream& os, const healthPoints&) //printing operator
    void InvalidArgument();
    friend void healthPointsBounds() const






    private:

    int m_currentHealPoints;
    const int m_maxHealPoints;
}