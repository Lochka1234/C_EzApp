#ifndef ADD_HPP
#define ADD_HPP
#include <QDialog>
#include "BD.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog {
	Q_OBJECT

public:
	
	Dialog(QWidget* parent = nullptr);		// конструктор
	~Dialog();								// деструктор
	Book getData();							// функция получения данных
	void set_name(QString arg);				// получение названия из строки
	void set_aothor(QString arg);			// получение автора из строки
	void set_genre(QString arg);			// получение жанра из строки 
	void set_year(size_t arg);				// получение года издания из строки
	void set_edition(size_t arg);			// получение тиража из строки

private:
	
	Ui::Dialog* ui;
};
#endif


