/*
 * Comp 11
 * Lab 2
 * 
 * golf.cpp
 *
 * purpose: practice using booleans, conditionals, and constants
 *
 *          Program reads data about temperature, day, time, wind,
 *          whether it's raining, then prints out the price of
 *          admission to Minnie's Mini Golf for those conditions.
 *
 * modified by:  Neil Powers
 * on:           Spring 2021
 */

#include <iostream>
#include <iomanip>

using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double    BASE_PRICE            = 9.0;
const int       HIGH_TEMP_CUTOFF      = 80;
const int       LOW_TEMP_CUTOFF       = 65;
const double    PER_DEGREE_PENALTY    = 0.10;
const int       EVENING_START         = 17;
const double    WEEKEND_EVE_SURCHARGE = 1.00;
const double    RAIN_PENALTY          = 2.00;
const int       RAIN_YES              = 1;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;

int get_int(string prompt);
double temp_adjustment(int tempF);
double time_adjustment(int day, int hour);
double rain_adjustment(int isRaining);
double wind_adjustment(int windspeed);
void report_price(double price);

int main() 
{
        // -- define vars for input and a value used in the tests below
        int     tempF, dayOweek, hour, rainP, windMPH;
        double  price;

        // Avoid unused variable warnings
        (void) MON; 
        (void) TUE; 
        (void) WED; 
        (void) THR; 
        (void) FRI;

        // -- set the precision 
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from use
        tempF = get_int("Temperature (fahrenheit)? ");
        
        dayOweek = get_int("Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? ");

        hour = get_int("Hour of day (0..23)? ");
        
        rainP = get_int("Is it raining (0 = no, 1 = yes)? ");

        windMPH = get_int("Wind speed (MPH)? ");

        // -- compute price based on these values

        price = BASE_PRICE;             // start here then adjust

        // Adjust for temperature
        price += temp_adjustment(tempF);
        
        // Adjust for peak time periods
        price += time_adjustment(dayOweek, hour);
        
        // Adjust for rain
        price += rain_adjustment(rainP);

        // Adjust for wind
        price += wind_adjustment(windMPH);

        // -- report price to user
        report_price(price);

        return 0;
}

// returns an integer input from a user prompt
int get_int(string prompt)
{
        int tempF;
        
        cout << prompt;
        cin  >> tempF;
        
        return tempF;
}

double temp_adjustment(int currentTemp)
{
        if (currentTemp > HIGH_TEMP_CUTOFF) {
                return PER_DEGREE_PENALTY * (currentTemp - HIGH_TEMP_CUTOFF);
        } else if (currentTemp < LOW_TEMP_CUTOFF) {
                return PER_DEGREE_PENALTY * (LOW_TEMP_CUTOFF - currentTemp);
        }
        
        return 0;
}

double time_adjustment(int day, int hour)
{
        if ((day == SAT) or (day == SUN) or (hour > EVENING_START))
                return WEEKEND_EVE_SURCHARGE;
        
        return 0;
}

double rain_adjustment(int isRaining)
{
        if (isRaining == RAIN_YES)
                return -1 * RAIN_PENALTY;
        
        return 0;
}

double wind_adjustment(int windspeed)
{
        return -1 * (windspeed / WIND_GRANULARITY) * WIND_PENALTY;
}

void report_price(double price)
{
        cout << "Price: " << price << endl;
}