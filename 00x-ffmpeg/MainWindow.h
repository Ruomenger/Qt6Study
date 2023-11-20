//
// Created by ruo on 2023/11/17.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QLabel>
#include <QPushButton>
#include <QWidget>

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushButton_clicked();

private:
    QLabel *label;
    QPushButton *pushButton;
};


#endif //MAINWINDOW_H
