// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QPair>
#include <QMap>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void addCountry();
    void displayCountries();
    void displayCountryNames();
    void displayCountriesInRange();
    void removeCountry();
    void displaySortedCountries();

private:
    QVector<QPair<QString, int>> countries;
    QMap<QString, int> countryMap;

    QLineEdit *countryNameInput;
    QSpinBox *populationInput;
    QLineEdit *rangeFromInput;
    QLineEdit *rangeToInput;
    QLineEdit *removeCountryInput;
    QTextEdit *outputDisplay;
    QComboBox *sortOrderCombo;

    void setupUI();
    void updateDisplay(const QString &text);
};

#endif
