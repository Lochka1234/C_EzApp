#ifndef KURS_OOP_H
#define KURS_OOP_H
#include <QMessageBox>
#include "vector.hpp"
#include "BD.hpp"

#include <QtWidgets/QMainWindow>
#include "ui_Kurs_OOP.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow()=default;

private slots:
	
    void on_about_triggered();                          // вызов окна "о программе"
    void on_create_triggered();                         // создание базы данных
    void on_open_triggered(bool isClean = true);        // чтение с файла и просмотр базы данных
    void on_save_triggered();                           // сохранение базы данных
    void on_saveAs_triggered();                         // запись базы данных в файл
    void on_merge_triggered();                          // объединение баз данных
    void on_add_triggered();                            // добавление записи в базу данных
    void on_edit_triggered();                           // редактирование записей в базе данных
    void on_del_triggered();                            // удаление записей из базы данных
    void on_lineEdit_textChanged(const QString& arg);   // поиск данных по переданному аргументу

private:
	
    Ui::MainWindow* ui;
    QString file = "";                                  // поле строка содеержащая имя файла
    Daniilvokhromeev::Vector<Book> main_vector;         // поле контейнер с элементами
}; 
#endif

