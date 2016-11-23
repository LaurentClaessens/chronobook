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


#include <memory>
#include <iostream>
#include "chronobook.h"
#include "Media.h"
#include "AutoSortLibrary.h"

    
int main ()
{
    auto my_library = AutoSortLibrary();
    std::unique_ptr<Media> dvd1( new DVD("Bof",6) );
    std::unique_ptr<Media> dvd2( new DVD("Bof",2) );
    std::unique_ptr<Media> dvd3( new DVD("Bof",4) );
    std::unique_ptr<Media> dvd4( new DVD("Bof",3) );
    std::unique_ptr<Media> dvd5( new DVD("Bof",5) );
    std::unique_ptr<Media> dvd6( new DVD("Bof",1) );
    std::unique_ptr<Media> dvd7( new DVD("Bof",7) );
    my_library.append(std::move(dvd1));
    my_library.append(std::move(dvd2));
    my_library.append(std::move(dvd3));
    my_library.append(std::move(dvd4));
    my_library.append(std::move(dvd5));
    my_library.append(std::move(dvd6));
    my_library.append(std::move(dvd7));
    my_library.show();
}
