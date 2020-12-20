#ifndef BD_HPP
#define BD_HPP
#include <QString>

class Book
{
protected:
	QString name = "";
	QString Author = "";		//поле содержит автора книги 
	size_t year_public = 0;	    //поле содержит год издания
	QString genre = "";			//поле содержит Жанр книги
	size_t edition = 0;         //поле содержит тираж книги 
public:
	//конструкторы
	Book();																					//Конструктор по умолчанию
	Book(QString name ,QString Author, QString genre, size_t year_public, size_t edition);	//конструктор с параметром 
	Book(const Book& r) noexcept;															//Конструктор копирования 
	Book(Book&& r) noexcept;																//Конструктор премещения
	~Book();																				//Диструктор 

	//отчистка
	void clear();
	
	//устаноква данных
	void set_name(QString arg);
	void set_Author(QString arg);
	void set_yerpub(size_t arg);
	void set_genre(QString arg);
	void set_edition(size_t arg);

	//получение данных
	const QString& get_name();
	const QString& get_Author();
	const size_t& get_yearpub();
	const QString& get_genre();
	const size_t& get_edition();

	//операторы
	Book& operator=(const Book& r)=default;		//опетаор копирования 
	Book& operator=(Book&& r)=default;			//оператор перемещения
};
#endif
