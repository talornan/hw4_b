#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

namespace ariel
{
    class Point{
        private:
            double x;
            double y;
        
        public:

        double getX() const{
            return x;
        }

        double getY() const {
            return y;
        }

        void setX(double newX){
            this->x=newX;
        }

        void setY(double newY){
            this->y=newY;
        }

        /*
        * Constructor for the Point class.
        * @param x The x-coordinate of the Point.
        * @param y The y-coordinate of the Point.
        */
            Point(double xcoord , double ycoord);

        /*
        * Calculates the Euclidean distance between two Points.
        * @param other The other Point.
        * @return The distance between the current Point and the other Point.
        */
        double distance(Point other) const;
        /*
        * Prints the coordinates of the Point.
        */    
            string print() const;
        /*
        * Moves towards a destination Point by a specified distance.
        * @param srce The source Point.
        * @param dest The destination Point.
        * @param dis The maximum distance to move towards the destination.
        * @return The Point that is at most the specified distance away from the destination.
        */    
        static Point moveTowards(const Point& src,const Point& dest,double dis) ;

            bool operator==(const Point& other) const;
    };
}