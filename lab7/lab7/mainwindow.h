// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QComboBox>
#include "car.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QTableWidget;
class QPushButton;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addCar();
    void removeCar();
    void countOlderCars();
    void sortCars();

private:
    enum class SortType {
        ByYear,
        ByMake
    };

    void setupUI();
    void updateTable();
    void clearInputs();
    void sortCarsByYear();
    void sortCarsByMake();

    QLineEdit *makeInput;
    QLineEdit *modelInput;
    QLineEdit *yearInput;
    QLineEdit *vinInput;
    QLineEdit *yearThresholdInput;
    QLineEdit *vinToRemoveInput;
    QTableWidget *table;
    QComboBox *sortComboBox;
    QVector<Car> cars;
};

#endif // MAINWINDOW_H
