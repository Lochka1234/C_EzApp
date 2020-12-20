#ifndef KURS_OOP_CPP
#define KURS_OOP_CPP

#include "Kurs_OOP.h"
#include "ui_Kurs_OOP.h"
#include "add.hpp"
#include "vector.hpp"
#include "QFileDialog"
#include "QTextStream"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   
}

void MainWindow::on_about_triggered()
{
    QMessageBox msg;
    msg.setWindowTitle("About");
    msg.setText("Do this: \nstudent IKPI-95, \nVokhromeev Daniil");
    msg.setDefaultButton(QMessageBox::Ok);
    if (msg.exec() == QMessageBox::Ok) { return; }
}

void MainWindow::on_create_triggered()
{
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox msg;
        msg.setWindowTitle("Create");
        msg.setText("Are you sure you want to create a new file? Changes will not be saved.");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg.setDefaultButton(QMessageBox::Yes);
        if (msg.exec() == QMessageBox::No) { return; }
    }
    ui->tableWidget->setRowCount(0);
    main_vector.clear();
    file = "";
}

void MainWindow::on_open_triggered(bool isClean)
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open file", ".", "txt files (*.txt);;");
    QFileInfo check_file(file_name);
    if (check_file.exists() && check_file.isFile()) {
        if (isClean) {
            MainWindow::on_create_triggered();
        }
        QFile file_(file_name);
        if (file_.open(QIODevice::ReadOnly)) {
            QTextStream in(&file_);
            while (!in.atEnd()) {
                Book t;
                QString line = in.readLine();
                QStringList fields = line.split(", ");
                if (fields.size() == 5) {
                    t.set_name(fields[0]);
                    t.set_Author(fields[1]);
                    t.set_genre(fields[2]);
                    t.set_yerpub(fields[3].toInt());
                    t.set_edition(fields[4].toInt());
                    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(t.get_name()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(t.get_Author()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(t.get_genre()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(QString::number(t.get_yearpub())));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::number(t.get_edition())));
                    main_vector.pushBack(t);
                }
            }
            file_.close();
            ui->statusBar->showMessage("File entries added");
            file = file_name;
        }
        else ui->statusBar->showMessage("File " + file_name + " failed to open");
    }
    else ui->statusBar->showMessage("File " + file_name + " does not exist");
}

void MainWindow::on_save_triggered()
{
    if (file == "") {
        MainWindow::on_saveAs_triggered();
        return;
    }
    QFile file_(file);
    if (file_.open(QIODevice::WriteOnly)) {
        QTextStream out(&file_);
        int len = ui->tableWidget->rowCount();
        for (int i = 0; i < len; ++i) {
            QString name = ui->tableWidget->item(i, 0)->text();
            QString aothor = ui->tableWidget->item(i, 1)->text();
            QString genre = ui->tableWidget->item(i, 2)->text();
            QString year = ui->tableWidget->item(i, 3)->text();
            QString edition = ui->tableWidget->item(i, 4)->text();
            out << name << ", " << aothor << ", " << genre << ", " << year << ", " << edition << "\n";
        }
        file_.close();
        ui->statusBar->showMessage("file recorded");
    }
}

    void MainWindow::on_saveAs_triggered()
	{
        QString file_name = QFileDialog::getSaveFileName(this, "Save file", ".", "txt files (*.txt);;");
        if (file_name != "") {
            file = file_name;
            MainWindow::on_save_triggered();
        }
    }

    void MainWindow::on_merge_triggered() {
        QString old_file = file;
        MainWindow::on_open_triggered(false);
        file = old_file;
        ui->statusBar->showMessage("The tables are merged");
    }

    void MainWindow::on_add_triggered() {
        Dialog dialog;
        if (dialog.exec() == QDialog::Accepted) {
            Book t = dialog.getData();
            ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(t.get_name()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(t.get_Author()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(t.get_genre()));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(QString::number(t.get_yearpub())));
            ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(QString::number(t.get_edition())));
            main_vector.pushBack(t);
            ui->statusBar->showMessage("Entry added");
        }else{
            ui->statusBar->showMessage("False");
        }
    }

    void MainWindow::on_edit_triggered() {
        auto list = ui->tableWidget->selectedItems();
        if (list.size() > 0) {
            Dialog dialog;
            dialog.set_name(list.at(0)->text());
            dialog.set_aothor(list.at(1)->text());
            dialog.set_genre(list.at(2)->text());
            dialog.set_year(list.at(3)->text().toInt());
            dialog.set_edition(list.at(4)->text().toInt());
            if (dialog.exec() == QDialog::Accepted) {
                Book t = dialog.getData();
                list.at(0)->setText(t.get_name());
                list.at(1)->setText(t.get_Author());
                list.at(2)->setText(t.get_genre());
                list.at(3)->setText(QString::number(t.get_yearpub()));
                list.at(4)->setText(QString::number(t.get_edition()));
                main_vector[list.at(0)->row()].set_name(t.get_name());
                main_vector[list.at(1)->row()].set_Author(t.get_Author());
                main_vector[list.at(2)->row()].set_genre(t.get_genre());
                main_vector[list.at(3)->row()].set_yerpub(t.get_yearpub());
                main_vector[list.at(4)->row()].set_edition(t.get_edition());
                ui->statusBar->showMessage("Recorded edited");
            }
        }
    }
   
    void MainWindow::on_del_triggered() {
        auto list = ui->tableWidget->selectionModel()->selectedRows();
        if (list.size() > 0) {
            QMessageBox msg;
            msg.setWindowTitle("Delete");
            msg.setText("Are you sure you want to delete the selected rows?");
            msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msg.setDefaultButton(QMessageBox::Yes);
            if (msg.exec() == QMessageBox::Yes) {
                for (auto i = list.rbegin(); i != list.rend(); i++) {
                    auto idx = (*i).row();
                    main_vector.erase(idx);
                    ui->tableWidget->removeRow(idx);
                }
                ui->statusBar->showMessage("Record deleted");
            }
        }
        else ui->statusBar->showMessage("The table is cleared");
    }

    void MainWindow::on_lineEdit_textChanged(const QString& arg) {
        ui->tableWidget->setCurrentCell(-1, -1);
        if (arg == "") { return; }
        ui->tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        auto find_items = ui->tableWidget->findItems(arg, Qt::MatchContains);
        int len = find_items.size();
        for (int i = 0; i < len; ++i) {
            auto item = find_items.at(i);
            ui->tableWidget->setItemSelected(item, true);
        }
        ui->tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        ui->statusBar->showMessage("Found " + QString::number(len) + " slots");
    }
#endif







