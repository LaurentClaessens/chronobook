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

#include "AutoSortLibrary.h"
#include "Utilities.h"

AutoSortLibrary::node::node(std::unique_ptr<Media> m_ptr):
    media(std::move(m_ptr))
{
    next=nullptr;
};

AutoSortLibrary::node::node(node& n):
    next(n.next),
    media(std::move(n.media))
{ }

std::shared_ptr<AutoSortLibrary::node> AutoSortLibrary::node::getNext() const
{
    return next; 
}

void AutoSortLibrary::node::setNext(std::shared_ptr<AutoSortLibrary::node> m_ptr)
{
    next=m_ptr;
}

int AutoSortLibrary::node::getYear() const
{
    return getMedia().getYear();
}

Media AutoSortLibrary::node::getMedia() const
{
    return *media;
};
