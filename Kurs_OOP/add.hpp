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
	
	Dialog(QWidget* parent = nullptr);		// �����������
	~Dialog();								// ����������
	Book getData();							// ������� ��������� ������
	void set_name(QString arg);				// ��������� �������� �� ������
	void set_aothor(QString arg);			// ��������� ������ �� ������
	void set_genre(QString arg);			// ��������� ����� �� ������ 
	void set_year(size_t arg);				// ��������� ���� ������� �� ������
	void set_edition(size_t arg);			// ��������� ������ �� ������

private:
	
	Ui::Dialog* ui;
};
#endif


