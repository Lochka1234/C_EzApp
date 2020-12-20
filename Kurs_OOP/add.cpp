#ifndef ADD_CPP	
#define ADD_CPP
#include "add.hpp"
#include "ui_Dialog.h"

Dialog::Dialog(QWidget* parent) :
	QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
	delete ui;
}

void Dialog::set_name(QString arg)
{
	ui->lineEdit->setText(arg);
}
void Dialog::set_aothor(QString arg)
{
	ui->lineEdit_2->setText(arg);
}

void Dialog::set_genre(QString arg)
{
	ui->lineEdit_3->setText(arg);
}


void Dialog::set_year(size_t arg)
{
	ui->lineEdit_4->setText(QString::number(arg));
	
}

void Dialog::set_edition(size_t arg)
{
	ui->lineEdit_5->setText(QString::number(arg));
}

Book Dialog::getData()
{
	Book result;
	result.set_name(ui->lineEdit->text());
	result.set_Author(ui->lineEdit_2->text());
	result.set_genre(ui->lineEdit_3->text());
	result.set_yerpub(ui->lineEdit_4->text().toInt());
	result.set_edition(ui->lineEdit_5->text().toInt());
	return result;
}
#endif


