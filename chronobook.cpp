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
#include "chronobook.h"
#include "Media.h"
#include "AutoSortLibrary.h"

    
int main ()
{
    std::shared_ptr<Media> dvd1=std::make_shared<DVD>("Truc récent",2012);
    std::shared_ptr<Media> dvd2=std::make_shared<DVD>("Truc ancien",1950);
    std::shared_ptr<Media> dvd3=std::make_shared<DVD>("Truc bof",1960);
    dvd1->Presentation();
    dvd2->Presentation();
    dvd3->Presentation();
    auto my_library = AutoSortLibrary();
    my_library.show();
}
