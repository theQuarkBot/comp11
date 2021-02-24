// flights.cpp
//      purpose: compare two flights to determine whether the combination is
//               a valid combination.
//        shows: the layover time and total time.
//  modified by: Neil Powers
//         date: 02/23/21

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int MinuteOfDay(int hour, int minute);
int LegDuration(int start, int end);
void PrintTripInformation(int trip_duration, int layover_duration);
string PrintDuration(int time);

int main()
{
        srand(time(nullptr));

        // Store the hour and minutes of each trip timestamp.
        int hr1, min1, hr2, min2, hr3, min3, hr4, min4;

        // Save flight time stampts to variables.
        cout << "Flight 1: ";
        cin >> hr1 >> min1 >> hr2 >> min2;
        cout << "Flight 2: ";
        cin >> hr3 >> min3 >> hr4 >> min4;

        // Save hh:mm times as minutes
        int flight1_start = MinuteOfDay(hr1, min1);
        int flight1_end   = MinuteOfDay(hr2, min2);
        int flight2_start = MinuteOfDay(hr3, min3);
        int flight2_end   = MinuteOfDay(hr4, min4);

        // Calculate the time of each leg (minutes)
        int leg1_duration = LegDuration(flight1_start, flight1_end);
        int leg2_duration = LegDuration(flight1_end, flight2_start);
        int leg3_duration = LegDuration(flight2_start, flight2_end);
        
        // Calculate total trip time and layover time (minutes).
        int trip_time = leg1_duration + leg2_duration + leg3_duration;
        int layover_time = leg2_duration;

        // Print total trip time and layover time.
        PrintTripInformation(trip_time, layover_time);

        return 0;
}

/* MinuteOfDay
 * Parameters: A number of hours and minutes.
 * Purpose:    Convert hours and minutes to pure minutes.
 * Returns:    An integer representing the number of minutes since the start of
 *             a day.
 */
int MinuteOfDay(int hour, int minute)
{
        return hour * 60 + minute;
}

/* LegDuration
 * Parameters: A start time and and end time of a leg of a trip.
 * Purpose:    Calculate the time between the start and end of a trip.
 * Returns:    An integer representing the minutes between the two timestamps.
 * Notes:      Only works properly for durations up to 23 hours and 59 minutes.
 */
int LegDuration(int start, int end)
{
        if (start < end) return end - start;
        else             return (1440 - start) + end;
}

/* PrintTripInformation
 * Parapeters: Total trip duration (minutes) and layover duration (minutes).
 * Purpose:    Print the total trup duration and layover duration in a
 *             human-readable format.
 * Returns:    Nothing.
 * Notes:      Need a way to insert PrintDuration() more effectively.
 */
void PrintTripInformation(int trip_duration, int layover_duration)
{
        cout << "Layover: " << PrintDuration(layover_duration) << endl;
        cout << "Total: " << PrintDuration(trip_duration) << endl;
}

/* PrintDuration
 * Parameters: A time of day (minutes).
 * Purpose:    Print a time (minutes) in an hour/minute format.
 * Returns:    "".
 * Notes:      Temporary substitution to get the program working. Need a way
 *             to "add" integers to strings for this to return a useful string
 *             instead of printing the time.
 */
string PrintDuration(int time)
{
        int hours, minutes;

        hours = time / 60;
        minutes = time % 60;

        cout << hours << " hr " << minutes << " min";

        return "";
}