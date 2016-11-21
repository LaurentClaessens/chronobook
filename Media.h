/*
Copyright 2016 Laurent Claessens
contact : moky.math@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
//*/

#ifndef __MEDIA_H_2034__
#define __MEDIA_H_2034__

#include <string>
using std::string;

/*
 'Media' is a generic media that can describe
 - DVD
 - book
 - comics
 - CD
 - ...

 The purpose of the whole 'chronobook' is to sort a Media list
 by its field 'year'.
//*/


class Media
{
    private :
        string title;
        int year;
        string media_type;      // dvd,cd,comic, ...
    public :
        Media(const string t,const int y);
        void Presentation() const;
        int getYear() const;
        string getTitle() const;
};

class DVD : public Media
{
    public :
        DVD(const string t,const int y);
};

#endif
