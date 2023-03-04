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

//2.2.4.4

void WrongPointers();


//2.2.2.1

struct Rectangle {
    string Color;
    double Width;
    double Height;  
};
struct Flight {
    string Departure;
    string Destination;
    int Time;
};
struct Movie {
    string Name;
    string Genre;
    int Length;
    int Year; 
    double Rating;
};
struct Time {
    int Hour;
    int Min;
    int Sec;
};

//2.2.5.1
void WriteRectangle(Rectangle& rectangle);

//2.2.5.2
void ReadRectangle(Rectangle& rectangle);

//2.2.5.3
void DemoReadAndWriteRectangles();

//2.2.5.4
void Exchange(Rectangle& rectangle1, Rectangle& rectangle2);

//2.2.5.5
void FindRectangle(Rectangle* rectangles, int count);

//2.2.5.6
void FindMaxRectangle(Rectangle* rectangles, int count);

//2.2.6.1
void DemoDynamicFlight();

//2.2.6.2
void DemoDynamicFlights();

//2.2.6.3
void FindShortestFlight(Flight* flights, int count);

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

//2.2.7.1
struct Circle
{
    double X; 
    double Y; 
    double Radius; 
    string Color; 
};

Circle* MakeCircle(double x, double y, double radius, string color);
Circle* CopyCircle(Circle& circle);

//2.2.7.2
Rectangle* MakeRectangle(string color, double width, double height);
Flight* MakeFlight(string dep, string des, int time);
Movie* MakeMovie(string name, string genre, int length, int year, double rate);
Time* MakeTime(int hour, int min, int sec);

//2.2.7.3
Rectangle* CopyRectangle(Rectangle& rectangle);
Flight* CopyFlight(Flight& flight);
Movie* CopyMovie(Movie& movie);
Time* CopyTime(Time& time);

int main()
{
    setlocale(LC_ALL, "Russian");
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
void DemoSort() {
    int count = 5;
    double* values = new double[count] {100.0, 249.0, 12.0, 45.0, 23.5};
    try {
        Sort(values, count);
    }
    catch (exception) {
        cout << "Exception catched!";
    }
}

//2.2.3.(1,2,3) and 2.2.4.(1,2,3)

void DemoRectangle() {
    Rectangle rectangle;
    Rectangle newRectangle;
    Rectangle massRectangle[3];
    Rectangle* p = &rectangle;
    Rectangle* point = &rectangle;

    rectangle.Color = "Red";
    rectangle.Width = 7.2;
    rectangle.Height = 3.5;   

    cout << "Введите цвет прямоугольника: ";
    cin >> newRectangle.Color;
    cout << "Введите ширину прямоугольника: ";
    cin >> newRectangle.Width;
    cout << "Введите высоту прямоугольника: ";
    cin >> newRectangle.Height;

    cout << "Ширина и высота прямоугольника: " << newRectangle.Width <<"x"<< newRectangle.Height;
    cout << " цвет (eng): " << newRectangle.Color << endl;

    massRectangle[0].Color = "AAA";
    massRectangle[0].Width = 11;
    massRectangle[0].Height = 22;

    massRectangle[1].Color = "BBB";
    massRectangle[1].Width = 33;
    massRectangle[1].Height = 44;

    massRectangle[2].Color = "CCC";
    massRectangle[2].Width = 55;
    massRectangle[2].Height = 66;

    for (int i = 0; i < 3; i++) {
        cout << "Ширина и высота прямоугольника: " << massRectangle[i].Width << "x" << massRectangle[i].Height;
        cout << " цвет (eng): " << massRectangle[i].Color << endl;
    }

    cout << "Ширина и высота прямоугольника: " << p->Width << "x" << p->Height;
    cout << " цвет (eng): " << p->Color << endl;

    cout << "Адрес в первой указателе:" << p << endl;
    cout << "Адрес во втором указателе:" << point << endl;

    Exchange(massRectangle[0], massRectangle[1]);

    cout << "Это massRectangle[0]: " << endl;
    cout << "Ширина и высота прямоугольника: " << massRectangle[0].Width << "x" << massRectangle[0].Height;
    cout << " цвет (eng): " << massRectangle[0].Color << endl;
    cout << "Это massRectangle[1]: " << endl;
    cout << "Ширина и высота прямоугольника: " << massRectangle[1].Width << "x" << massRectangle[1].Height;
    cout << " цвет (eng): " << massRectangle[1].Color << endl;

    
}

void DemoFlight() {
    Flight flight;
    Flight newFlight;
    Flight massFlight[3];
    Flight* p = &flight;
    Flight* point = &flight;

    flight.Departure = "Moscow";
    flight.Destination = "Berlin";
    flight.Time = 360;

    cout << "Введите место вылета: ";
    cin >> newFlight.Departure;
    cout << "Введите место прилета: ";
    cin >> newFlight.Destination;
    cout << "Введите время полета в минутах: ";
    cin >> newFlight.Time;

    cout << "Рейс: " << newFlight.Departure << " - " << newFlight.Destination << ", время полета: " << newFlight.Time << endl;

    massFlight[0].Departure = "AAA";
    massFlight[0].Destination = "BBB";
    massFlight[0].Time = 100;

    massFlight[1].Departure = "CCC";
    massFlight[1].Destination = "DDD";
    massFlight[1].Time = 200;

    massFlight[2].Departure = "EEE";
    massFlight[2].Destination = "FFF";
    massFlight[2].Time = 300;

    for (int i = 0; i < 3; i++) {
        cout << "Рейс: " << massFlight[i].Departure << " - " << massFlight[i].Destination << ", время полета: " << massFlight[i].Time << endl;
    }

    cout << "Рейс: " << p->Departure << " - " << p->Destination << ", время полета: " << p->Time << endl;

    cout << "Адрес в первой указателе:" << p << endl;
    cout << "Адрес во втором указателе:" << point << endl;
}

void DemoMovie() {
    Movie movie;
    Movie newMovie;
    Movie massMovie[3];
    Movie* p = &movie;
    Movie* point = &movie;

    movie.Name = "Star Wars";
    movie.Genre = "Drama";
    movie.Length = 180;  
    movie.Year = 2323;
    movie.Rating = 7.2;


    cout << "Введите название фильма: ";
    cin >> newMovie.Name;
    cout << "Введите жанр фильма: ";
    cin >> newMovie.Genre;
    cout << "Введите длину фильма в минутах: ";
    cin >> newMovie.Length;
    cout << "Введите год выхода фильма: ";
    cin >> newMovie.Year;
    cout << "Введите рейтинг фильма: ";
    cin >> newMovie.Rating;
  
    cout << "Фильм: " << newMovie.Name << ", жанр: " << newMovie.Genre << ", продолжительность: " << newMovie.Length << ", год выхода: " <<
        newMovie.Year << ", оценка: " << newMovie.Rating << endl;

    massMovie[0].Name = "AAA";
    massMovie[0].Genre = "111";
    massMovie[0].Length = 200;
    massMovie[0].Year = 1999;
    massMovie[0].Rating = 6.6;
    

    massMovie[1].Name = "BBB";
    massMovie[1].Genre = "222";
    massMovie[1].Length = 190;
    massMovie[1].Year = 2000;
    massMovie[1].Rating = 6.7;
    

    massMovie[2].Name = "CCC";
    massMovie[2].Genre = "333";
    massMovie[2].Length = 180;
    massMovie[2].Year = 2001;
    massMovie[2].Rating = 6.8;
    

    for (int i = 0; i < 3; i++) {
        cout << "Фильм: " << massMovie[i].Name << ", жанр: " << massMovie[i].Genre << ", продолжительность: " << massMovie[i].Length << ", год выхода: " <<
            massMovie[i].Year << ", оценка: " << massMovie[i].Rating << endl;
    }

    cout << "Фильм: " << p->Name << ", жанр: " << p->Genre << ", продолжительность: " << p->Length << ", год выхода: " <<
        p->Year << ", оценка: " << p->Rating << endl;

    cout << "Адрес в первой указателе:" << p << endl;
    cout << "Адрес во втором указателе:" << point << endl;
}

void DemoTime() {
    Time time;
    Time newTime;
    Time massTime[3];
    Time* p = &time;
    Time* point = &time;

    time.Hour = 12;
    time.Min = 45;
    time.Sec = 19;

    cout << "Введите час времени (до 24): ";
    cin >> newTime.Hour;
    cout << "Введите минуту времени (до 60): ";
    cin >> newTime.Min;
    cout << "Введите секунду времени (до 60): ";
    cin >> newTime.Sec;

    cout << "Время: " << newTime.Hour << ":" << newTime.Min << ":" << newTime.Sec << endl;

    massTime[0].Hour = 0;
    massTime[0].Min = 0;
    massTime[0].Sec = 0;

    massTime[1].Hour = 1;
    massTime[1].Min = 1;
    massTime[1].Sec = 1;

    massTime[2].Hour = 2;
    massTime[2].Min = 2; 
    massTime[2].Sec = 2;

    for (int i = 0; i < 3; i++) {
        cout << "Время: " << massTime[i].Hour << ":" << massTime[i].Min << ":" << massTime[i].Sec << endl;
    }

    cout << "Время: " << p->Hour << ":" << p->Min << ":" << p->Sec << endl;

    cout << "Адрес в первой указателе:" << p << endl;
    cout << "Адрес во втором указателе:" << point << endl;
}

//2.2.4.4

void WrongPointers() {
    Flight flight;
    Movie movie;
    Flight* pointerFlight = &flight;
    Movie* pointerMovie = &movie;
    //Flight* point = &movie;
    //Movie* pointer = &flight;
}

//2.2.5.1

void WriteRectangle(Rectangle& rectangle) {
    cout << "Размер прямоугольника: " << rectangle.Width << "x" << rectangle.Height << ", его цвет: " << rectangle.Color << endl;
}

//2.2.5.2

void ReadRectangle(Rectangle& rectangle) {
    cout << "Введите цвет прямоугольника: ";
    cin >> rectangle.Color;
    cout << "Введите ширину прямоугольника: ";
    cin >> rectangle.Width;
    cout << "Введите высоту прямоугольника: ";
    cin >> rectangle.Height;
}

//2.2.5.3

void DemoReadAndWriteRectangles() {
    Rectangle rectangle[5];
    for (int i = 0; i < 5; i++) {
        ReadRectangle(rectangle[i]);
    }
    for (int i = 0; i < 5; i++) {
        WriteRectangle(rectangle[i]);
    }
}

//2.2.5.4

void Exchange(Rectangle& rectangle1, Rectangle& rectangle2) {
    Rectangle swap;
    swap = rectangle1;
    rectangle1 = rectangle2;
    rectangle2 = swap;
}

//2.2.5.5

void FindRectangle(Rectangle* rectangles, int count) {
    double maxWidth = rectangles[0].Width;
    string maxColor = rectangles[0].Color;
    double maxHeight = rectangles[0].Height;
    for (int i = 1; i < count; i++) {
        if (maxWidth < rectangles[i].Width) {
            maxWidth = rectangles[i].Width;
            maxColor = rectangles[i].Color;
            maxHeight = rectangles[i].Height;
        }
    }
    cout << "Прямоугольник с самой большой шириной: " << maxWidth << "x" << maxHeight << ", цвет: " << maxColor;
}

//2.2.5.6

void FindMaxRectangle(Rectangle* rectangles, int count) {
    double maxWidth = rectangles[0].Width;
    string maxColor = rectangles[0].Color;
    double maxHeight = rectangles[0].Height;
    double maxArea = rectangles[0].Height * rectangles[0].Width;
    for (int i = 1; i < count; i++) {
        if (maxArea < rectangles[0].Height * rectangles[0].Width) {
            maxWidth = rectangles[i].Width;
            maxColor = rectangles[i].Color;
            maxHeight = rectangles[i].Height;
            maxArea = rectangles[0].Height * rectangles[0].Width;
        }
    }
    cout << "Прямоугольник с самой большой площадью: " << maxWidth << "x" << maxHeight << ", цвет: " << maxColor;
}

//2.2.6.1

void DemoDynamicFlight() {
    Flight* flight = new Flight();
    flight->Departure = "Moskow";
    flight->Destination = "Erevan";
    flight->Time = 200;
    cout << "Рейс: " << flight->Departure << " - " << flight->Destination << ", время полета: " << flight->Time << endl;
    delete flight;
}

//2.2.6.2

void DemoDynamicFlights() {
    Flight* flight = new Flight[4];

    flight[0].Departure = "Moskow";
    flight[0].Destination = "Erevan";
    flight[0].Time = 200;

    flight[1].Departure = "Lima";
    flight[1].Destination = "Belgrad";
    flight[1].Time = 204;

    flight[2].Departure = "Tomsk";
    flight[2].Destination = "Cologne";
    flight[2].Time = 220;

    flight[3].Departure = "Novosibirsk";
    flight[3].Destination = "Erevan";
    flight[3].Time = 206;

    for (int i = 0; i < 4; i++) {
        cout << "Рейс: " << flight[i].Departure << " - " << flight[i].Destination << ", время полета: " << flight[i].Time << endl;
    }
    FindShortestFlight(flight, 4);
    delete[] flight;
}

//2.2.6.3

void FindShortestFlight(Flight* flights, int count) {
    int minTime = flights->Time;
    string minDep = flights->Departure;
    string minDes = flights->Destination;
    for (int i = 1; i < count; i++) {
        if (minTime < flights->Time) {
            minTime = flights->Time;
            minDep = flights->Departure;
            minDes = flights->Destination;
        }
    }
    cout << "Самый короткий рейс:" << endl;
    cout << "Рейс: " << minDep << " - " << minDes << ", время полета: " << minTime << endl;
}

//2.2.7.1

Circle* MakeCircle(double x, double y, double radius, string color) {
    Circle* circle = new Circle();
    circle->X = x;
    circle->Y = y;
    circle->Radius = radius;
    circle->Color = color;
    return circle;
}

Circle* CopyCircle(Circle& circle) {
    Circle* circleCopied = new Circle();
    circleCopied->X = circle.X;
    circleCopied->Y = circle.Y;
    circleCopied->Radius = circle.Radius;
    circleCopied->Color = circle.Color;
    return circleCopied;
}

void DemoCircle()
{
    Circle* circle1 = MakeCircle(5.0,7.0,7.5,"Red");
    Circle* circle2 = MakeCircle(2.0, -12.0, 12.75, "Green");
    Circle* circle3 = MakeCircle(-10.0, 10.0, 1.45, "Blue");

    Circle* copiedCircle1 = CopyCircle(*circle1);
    Circle* copiedCircle2 = CopyCircle(*circle2);
    Circle* copiedCircle3 = CopyCircle(*circle3);
}

//2.2.7.2

Rectangle* MakeRectangle(string color, double width, double height) {
    Rectangle* rectangle = new Rectangle();
    rectangle->Color = color;
    rectangle->Width = width;
    rectangle->Height = height;
    return rectangle;
}

Flight* MakeFlight(string dep, string des, int time) {
    Flight* flight = new Flight();
    flight->Departure = dep;
    flight->Destination = des;
    flight->Time = time;
    return flight;
}

Movie* MakeMovie(string name, string genre, int length, int year, double rate) {
    Movie* movie = new Movie();
    movie->Name = name;
    movie->Genre = genre;
    movie->Length = length;
    movie->Year = year;
    movie->Rating = rate;
    return movie;
}

Time* MakeTime(int hour,int min, int sec) {
    Time* time = new Time();
    time->Hour = hour;
    time->Min = min;
    time->Sec = sec;
    return time;
}
//2.2.7.3

Rectangle* CopyRectangle(Rectangle& rectangle) {
    Rectangle* rectangleCopied = new Rectangle();
    rectangleCopied->Color = rectangle.Color;
    rectangleCopied->Height = rectangle.Height;
    rectangleCopied->Width = rectangle.Width;
    return rectangleCopied;
}

Flight* CopyFlight(Flight& flight) {
    Flight* flightCopied = new Flight();
    flightCopied->Departure = flight.Departure;
    flightCopied->Destination = flight.Destination;
    flightCopied->Time = flight.Time;
    return flightCopied;
}

Movie* CopyMovie(Movie& movie) {
    Movie* movieCopied = new Movie();
    movieCopied->Name = movie.Name;
    movieCopied->Genre = movie.Genre;
    movieCopied->Length = movie.Length;
    movieCopied->Year = movie.Year;
    movieCopied->Rating = movie.Rating;
    return movieCopied;
}

Time* CopyTime(Time& time) {
     Time* timeCopied = new Time();
     timeCopied->Hour = time.Hour;
     timeCopied->Min = time.Min;
     timeCopied->Sec = time.Sec;
     return timeCopied;
}