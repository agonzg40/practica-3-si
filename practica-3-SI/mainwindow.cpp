#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <locale>
#include <codecvt>
#include <regex>
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString valor = this->ui->input->toPlainText().toUtf8();
    std::wstring utf8string =valor.toStdWString();
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    letras1 = converter.to_bytes(utf8string);

    input = std::regex_replace(letras1, std::regex("\n"), "  ");

    this->ui->output->setText(QString::fromStdString(input));
}
