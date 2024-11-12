// mainwindow.cpp
#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QComboBox>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{
    setWindowTitle("Katalog Samochodów");
    setGeometry(100, 100, 800, 800);

    QWidget *mainWidget = new QWidget;
    setCentralWidget(mainWidget);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    // Input form section
    QWidget *formWidget = new QWidget;
    QVBoxLayout *formLayout = new QVBoxLayout(formWidget);

    // Make and model input
    QWidget *makeModelWidget = new QWidget;
    QHBoxLayout *makeModelLayout = new QHBoxLayout(makeModelWidget);
    makeInput = new QLineEdit;
    modelInput = new QLineEdit;
    makeInput->setPlaceholderText("Marka");
    modelInput->setPlaceholderText("Model");
    makeModelLayout->addWidget(new QLabel("Marka i Model:"));
    makeModelLayout->addWidget(makeInput);
    makeModelLayout->addWidget(modelInput);

    // Year input
    QWidget *yearWidget = new QWidget;
    QHBoxLayout *yearLayout = new QHBoxLayout(yearWidget);
    yearInput = new QLineEdit;
    yearInput->setPlaceholderText("Rok produkcji");
    yearLayout->addWidget(new QLabel("Rok produkcji:"));
    yearLayout->addWidget(yearInput);
    yearLayout->addStretch();

    // VIN input
    QWidget *vinWidget = new QWidget;
    QHBoxLayout *vinLayout = new QHBoxLayout(vinWidget);
    vinInput = new QLineEdit;
    vinInput->setPlaceholderText("Numer VIN");
    vinLayout->addWidget(new QLabel("VIN:"));
    vinLayout->addWidget(vinInput);
    vinLayout->addStretch();

    // Add button
    QPushButton *addButton = new QPushButton("Dodaj samochód");
    connect(addButton, &QPushButton::clicked, this, &MainWindow::addCar);

    // Remove car section
    QWidget *removeWidget = new QWidget;
    QHBoxLayout *removeLayout = new QHBoxLayout(removeWidget);
    vinToRemoveInput = new QLineEdit;
    vinToRemoveInput->setPlaceholderText("VIN do usunięcia");
    QPushButton *removeButton = new QPushButton("Usuń samochód");
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeCar);
    removeLayout->addWidget(vinToRemoveInput);
    removeLayout->addWidget(removeButton);

    // Count older cars section
    QWidget *countWidget = new QWidget;
    QHBoxLayout *countLayout = new QHBoxLayout(countWidget);
    yearThresholdInput = new QLineEdit;
    yearThresholdInput->setPlaceholderText("Rok graniczny");
    QPushButton *countButton = new QPushButton("Policz starsze samochody");
    connect(countButton, &QPushButton::clicked, this, &MainWindow::countOlderCars);
    countLayout->addWidget(yearThresholdInput);
    countLayout->addWidget(countButton);

    // Sort section
    QWidget *sortWidget = new QWidget;
    QHBoxLayout *sortLayout = new QHBoxLayout(sortWidget);
    sortComboBox = new QComboBox;
    sortComboBox->addItem("Sortuj według roku", static_cast<int>(SortType::ByYear));
    sortComboBox->addItem("Sortuj według marki", static_cast<int>(SortType::ByMake));
    QPushButton *sortButton = new QPushButton("Sortuj");
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::sortCars);
    sortLayout->addWidget(sortComboBox);
    sortLayout->addWidget(sortButton);

    // Add all sections to form layout
    formLayout->addWidget(makeModelWidget);
    formLayout->addWidget(yearWidget);
    formLayout->addWidget(vinWidget);
    formLayout->addWidget(addButton);
    formLayout->addWidget(removeWidget);
    formLayout->addWidget(countWidget);
    formLayout->addWidget(sortWidget);

    // Create table
    table = new QTableWidget;
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Marka", "Model", "Rok", "VIN"});
    table->horizontalHeader()->setStretchLastSection(true);

    // Add widgets to main layout
    mainLayout->addWidget(formWidget);
    mainLayout->addWidget(table);
}

void MainWindow::addCar()
{
    QString make = makeInput->text();
    QString model = modelInput->text();
    QString year = yearInput->text();
    QString vin = vinInput->text();

    if (!make.isEmpty() && !model.isEmpty() && !year.isEmpty() && !vin.isEmpty()) {
        cars.append(Car(make, model, year, vin));
        updateTable();
        clearInputs();
    }
}

void MainWindow::removeCar()
{
    QString vinToRemove = vinToRemoveInput->text();
    if (!vinToRemove.isEmpty()) {
        auto it = std::remove_if(cars.begin(), cars.end(),
                                 [vinToRemove](const Car& car) { return car.vin() == vinToRemove; });

        if (it != cars.end()) {
            cars.erase(it, cars.end());
            updateTable();
            vinToRemoveInput->clear();
        }
    }
}

void MainWindow::countOlderCars()
{
    QString yearStr = yearThresholdInput->text();
    if (!yearStr.isEmpty()) {
        int year = yearStr.toInt();
        int count = std::count_if(cars.begin(), cars.end(),
                                  [year](const Car& car) { return car.isOlderThan(year); });

        QMessageBox::information(this, "Wynik",
                                 QString("Liczba samochodów starszych niż %1: %2").arg(year).arg(count));
    }
}

void MainWindow::sortCars()
{
    SortType sortType = static_cast<SortType>(sortComboBox->currentData().toInt());
    if (sortType == SortType::ByYear) {
        sortCarsByYear();
    } else {
        sortCarsByMake();
    }
    updateTable();
}

void MainWindow::sortCarsByYear()
{
    std::sort(cars.begin(), cars.end(),
              [](const Car& a, const Car& b) { return a.year() < b.year(); });
}

void MainWindow::sortCarsByMake()
{
    std::sort(cars.begin(), cars.end(),
              [](const Car& a, const Car& b) { return a.make().toLower() < b.make().toLower(); });
}

void MainWindow::updateTable()
{
    table->setRowCount(cars.size());
    for (int i = 0; i < cars.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(cars[i].make()));
        table->setItem(i, 1, new QTableWidgetItem(cars[i].model()));
        table->setItem(i, 2, new QTableWidgetItem(cars[i].yearString()));
        table->setItem(i, 3, new QTableWidgetItem(cars[i].vin()));
    }
}

void MainWindow::clearInputs()
{
    makeInput->clear();
    modelInput->clear();
    yearInput->clear();
    vinInput->clear();
}
