#ifndef SICT_CRA_Account_H__
#define SICT_CRA_Account_H__
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4

namespace sict {

    class CRA_Account {
    private:
        char m_familyName[MAX_NAME_LENGTH+1];
        char m_givenName[MAX_NAME_LENGTH+1];
        long long m_sin;
        int m_year[MAX_YRS];
        double m_balance[MAX_YRS];
        int m_years;

    public:
        void set(const char* familyName, const char* givenName, long long sin);
        bool isValid() const;
        void display() const;
        void set(int year, double balance);
    };

}
#endif 
