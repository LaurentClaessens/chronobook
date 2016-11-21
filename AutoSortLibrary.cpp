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

// iterator

#include <memory>
#include <iostream>

#include "AutoSortLibrary.h"

AutoSortLibrary::Iterator::Iterator(std::shared_ptr<AutoSortLibrary::node> p):
    punt(p)
{}

bool AutoSortLibrary::Iterator::operator!= (const Iterator& other) const
{
    return punt != other.punt;
}

AutoSortLibrary::node& AutoSortLibrary::Iterator::operator*() const 
{
    return *punt;
}
const AutoSortLibrary::Iterator& AutoSortLibrary::Iterator::operator++()
{
    if (punt) punt=punt->getNext();
    return *this;
}


// node
std::shared_ptr<AutoSortLibrary::node> AutoSortLibrary::node::getNext() const
{
    return next; 
}

void AutoSortLibrary::node::setNext(std::shared_ptr<AutoSortLibrary::node> m_ptr)
{
    next=m_ptr;
}

AutoSortLibrary::node::node(std::shared_ptr<Media> m):
    media(m)
{
    next=nullptr;
};

std::shared_ptr<Media> AutoSortLibrary::node::getMedia() const
{
    return media;
};

// AutoSortLibrary


AutoSortLibrary::Iterator AutoSortLibrary::begin() const
{
    return AutoSortLibrary::Iterator(first);
}
AutoSortLibrary::Iterator AutoSortLibrary::end() const
{
    return AutoSortLibrary::Iterator(nullptr);
}

std::shared_ptr<AutoSortLibrary::node> AutoSortLibrary::getLastNodeBefore(const int year) const
{
    for (auto current_node:*this)
    {
        if (current_node.getMedia()->getYear() > year) {return first;}
    }
    return last;
};
void AutoSortLibrary::append(const std::shared_ptr<Media> m)
{
    auto new_node = std::make_shared<AutoSortLibrary::node>(AutoSortLibrary::node(m));
    if (first==nullptr)
    {
        first=new_node;
        last=new_node;
        return;
    }
    auto m_year = m->getYear();
    auto last_before = getLastNodeBefore(m_year);
    new_node->setNext(last_before->getNext());
    last_before->setNext(new_node);
};

void AutoSortLibrary::show() const
{
    for (auto current_node:*this)
    {
        current_node.getMedia()->Presentation();
    }
};
