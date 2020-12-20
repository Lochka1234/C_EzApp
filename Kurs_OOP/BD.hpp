#ifndef BD_HPP
#define BD_HPP
#include <QString>

class Book
{
protected:
	QString name = "";
	QString Author = "";		//���� �������� ������ ����� 
	size_t year_public = 0;	    //���� �������� ��� �������
	QString genre = "";			//���� �������� ���� �����
	size_t edition = 0;         //���� �������� ����� ����� 
public:
	//������������
	Book();																					//����������� �� ���������
	Book(QString name ,QString Author, QString genre, size_t year_public, size_t edition);	//����������� � ���������� 
	Book(const Book& r) noexcept;															//����������� ����������� 
	Book(Book&& r) noexcept;																//����������� ����������
	~Book();																				//���������� 

	//��������
	void clear();
	
	//��������� ������
	void set_name(QString arg);
	void set_Author(QString arg);
	void set_yerpub(size_t arg);
	void set_genre(QString arg);
	void set_edition(size_t arg);

	//��������� ������
	const QString& get_name();
	const QString& get_Author();
	const size_t& get_yearpub();
	const QString& get_genre();
	const size_t& get_edition();

	//���������
	Book& operator=(const Book& r)=default;		//������� ����������� 
	Book& operator=(Book&& r)=default;			//�������� �����������
};
#endif
