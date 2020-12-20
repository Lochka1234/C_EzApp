#ifndef BD_CPP
#define BD_CPP

#include "BD.hpp"

Book::Book():
	name(""), Author(""), genre(""), edition(0), year_public(0)
{}

Book::Book(QString name, QString Author, QString genre, size_t year_public, size_t edition):

	name(name), Author(Author), genre(genre), year_public(year_public), edition(edition)
{}

Book::Book(const Book & r) noexcept:
	Book(r.name, r.Author, r.genre, r.year_public, r.edition)
{}
Book::Book(Book&& r) noexcept
{
	name = std::move(r.name);
	Author = std::move(r.Author);
	genre = std::move(r.genre);
	year_public = r.year_public;
	edition = r.edition;

	r.name=r.Author = r.genre = ""; r.year_public = r.edition = 0;
}

Book::~Book()
{}


void Book::clear()
{
	name=Author = genre = "";
	year_public = edition = 0;
}
void Book::set_name(QString arg)
{
	name = arg;
}

const QString& Book::get_name()
{
	return name;
}


void Book::set_Author(QString arg)
{
	Author = arg;
}
const QString& Book::get_Author()
 {
	return Author;
 }

void Book::set_genre(QString arg)
{
	genre = arg;
}

const QString& Book::get_genre()
{
	return genre;
}

void Book::set_edition(size_t arg)
{
	edition = arg;
}

const size_t& Book::get_edition()
{
	return edition;
}

void Book::set_yerpub(size_t arg)
{
	year_public = arg;
}

const size_t& Book::get_yearpub()
{
	return year_public;
}

#endif


