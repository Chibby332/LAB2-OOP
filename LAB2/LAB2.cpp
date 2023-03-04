#include <iostream>
#include <exception>
#include <string.h>
using namespace std;

//2.2.1.1 and 2.2.1.2

void Sort(double* values, int count);
void DemoSort();

//2.2.3.1

void DemoRectangle();
void DemoFlight();
void DemoMovie();
void DemoTime();

//2.2.2.1

struct Rectangle {
    double Width;
    double Height;
    string Color;
};
struct Flight {
    string Departure;
    string Destination;
    int Time;
};
struct Movie {
    string Name;
    int Length;
    int Year;
    string Genre;
    double Rating;
};
struct Time {
    int Hour;
    int Min;
    int Sec;
};

//2.2.2.2

struct Contact {
    string Name;
    string Number;
    int Age;
};
struct Song {
    int Length;
    string Name;
    string Genre;
};
struct Discipline {
    string Name;
    int Grade;
    int Duration;
};

int main()
{



}

//2.2.1.1 and 2.2.1.2
void Sort(double* values, int count) {
    double swap;
    if (count >= 0) {
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (values[i] < values[j])
                {
                    swap = values[i];
                    values[i] = values[j];
                    values[j] = swap;
                }
            }
        }
    }
    else {
        throw exception();
    }
}
void DemoSort()
{
    int count = 5;
    double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};
    try {
        Sort(values, count);
    }
    catch (exception) {
        cout << "Exception catched!";
    }
}

//2.2.3.1

void DemoRectangle() {
    Rectangle rectangle;
    rectangle.Color = "Red";
    rectangle.Height = 3.5;
    rectangle.Width = 7.2;
}
void DemoFlight() {
    Flight flight;
    flight.Departure = "Moscow";
    flight.Destination = "Berlin";
    flight.Time = 360;
}
void DemoMovie() {
    Movie movie;
    movie.Genre = "Drama";
    movie.Length = 180;
    movie.Name = "Star Wars";
    movie.Rating = 7.2;
    movie.Year = 2323;

}
void DemoTime() {
    Time time;
    time.Hour = 12;
    time.Min = 45;
    time.Sec = 19;
}
