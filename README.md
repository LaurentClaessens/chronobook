# Chronobook

## Purpose (official)

I want to sort my personal library (DVD, books, CD, comics) in chronological order. So I want the CD of *Das Wohltemperierte Klavier* to be close to the book of *Le Cid*. Thus I need a program that sort for me. What I need :

* For each media, store the publication year and the title.
* output the list of titles in the chronological order.

## Purpose (the real one)

Ok. If I *really* wanted to do so, I would have done
```python
my_library.sort(key=lambda x:x.year)
```
where `my_library` is a `list` of instances of a very trivial class.

So what is the aim ?

* Manipulating C++ smart pointers.

