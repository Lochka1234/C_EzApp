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
	
    void on_about_triggered();                          // ����� ���� "� ���������"
    void on_create_triggered();                         // �������� ���� ������
    void on_open_triggered(bool isClean = true);        // ������ � ����� � �������� ���� ������
    void on_save_triggered();                           // ���������� ���� ������
    void on_saveAs_triggered();                         // ������ ���� ������ � ����
    void on_merge_triggered();                          // ����������� ��� ������
    void on_add_triggered();                            // ���������� ������ � ���� ������
    void on_edit_triggered();                           // �������������� ������� � ���� ������
    void on_del_triggered();                            // �������� ������� �� ���� ������
    void on_lineEdit_textChanged(const QString& arg);   // ����� ������ �� ����������� ���������

private:
	
    Ui::MainWindow* ui;
    QString file = "";                                  // ���� ������ ����������� ��� �����
    Daniilvokhromeev::Vector<Book> main_vector;         // ���� ��������� � ����������
}; 
#endif

