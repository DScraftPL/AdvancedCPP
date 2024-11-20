#include "mainwindow.h"
#include <QMessageBox>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *addLayout = new QHBoxLayout();
    countryNameInput = new QLineEdit();
    countryNameInput->setPlaceholderText("Country name");
    populationInput = new QSpinBox();
    populationInput->setRange(0, 2000000000);
    QPushButton *addButton = new QPushButton("Add Country");
    addLayout->addWidget(countryNameInput);
    addLayout->addWidget(populationInput);
    addLayout->addWidget(addButton);

    QHBoxLayout *displayLayout = new QHBoxLayout();
    QPushButton *displayAllButton = new QPushButton("Display All");
    QPushButton *displayNamesButton = new QPushButton("Display Names Only");
    displayLayout->addWidget(displayAllButton);
    displayLayout->addWidget(displayNamesButton);

    QHBoxLayout *rangeLayout = new QHBoxLayout();
    rangeFromInput = new QLineEdit();
    rangeToInput = new QLineEdit();
    rangeFromInput->setPlaceholderText("From population");
    rangeToInput->setPlaceholderText("To population");
    QPushButton *rangeButton = new QPushButton("Display Range");
    rangeLayout->addWidget(rangeFromInput);
    rangeLayout->addWidget(rangeToInput);
    rangeLayout->addWidget(rangeButton);

    QHBoxLayout *removeLayout = new QHBoxLayout();
    removeCountryInput = new QLineEdit();
    removeCountryInput->setPlaceholderText("Country to remove");
    QPushButton *removeButton = new QPushButton("Remove Country");
    removeLayout->addWidget(removeCountryInput);
    removeLayout->addWidget(removeButton);

    QHBoxLayout *sortLayout = new QHBoxLayout();
    sortOrderCombo = new QComboBox();
    sortOrderCombo->addItems({"Ascending", "Descending"});
    QPushButton *sortButton = new QPushButton("Sort by Population");
    sortLayout->addWidget(sortOrderCombo);
    sortLayout->addWidget(sortButton);

    outputDisplay = new QTextEdit();
    outputDisplay->setReadOnly(true);

    mainLayout->addLayout(addLayout);
    mainLayout->addLayout(displayLayout);
    mainLayout->addLayout(rangeLayout);
    mainLayout->addLayout(removeLayout);
    mainLayout->addLayout(sortLayout);
    mainLayout->addWidget(outputDisplay);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addCountry);
    connect(displayAllButton, &QPushButton::clicked, this, &MainWindow::displayCountries);
    connect(displayNamesButton, &QPushButton::clicked, this, &MainWindow::displayCountryNames);
    connect(rangeButton, &QPushButton::clicked, this, &MainWindow::displayCountriesInRange);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::removeCountry);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::displaySortedCountries);

    setWindowTitle("Country Manager");
    resize(600, 400);
}

void MainWindow::addCountry() {
    QString name = countryNameInput->text().trimmed();
    int population = populationInput->value();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a country name");
        return;
    }

    if (countryMap.contains(name)) {
        QMessageBox::warning(this, "Error", "Country already exists");
        return;
    }

    countries.append(qMakePair(name, population));
    countryMap[name] = population;

    countryNameInput->clear();
    populationInput->setValue(0);
    updateDisplay("Country added successfully!");
}

void MainWindow::displayCountries() {
    QString output;
    for (const auto &country : countries) {
        output += QString("%1: %2\n").arg(country.first).arg(country.second);
    }
    updateDisplay(output.isEmpty() ? "No countries to display" : output);
}

void MainWindow::displayCountryNames() {
    QString output;
    for (const auto &country : countries) {
        output += country.first + "\n";
    }
    updateDisplay(output.isEmpty() ? "No countries to display" : output);
}

void MainWindow::displayCountriesInRange() {
    bool okFrom, okTo;
    int from = rangeFromInput->text().toInt(&okFrom);
    int to = rangeToInput->text().toInt(&okTo);

    if (!okFrom || !okTo) {
        QMessageBox::warning(this, "Error", "Please enter valid numbers for range");
        return;
    }

    QString output;
    for (const auto &country : countries) {
        if (country.second >= from && country.second <= to) {
            output += QString("%1: %2\n").arg(country.first).arg(country.second);
        }
    }
    updateDisplay(output.isEmpty() ? "No countries in this range" : output);
}

void MainWindow::removeCountry() {
    QString name = removeCountryInput->text().trimmed();

    if (!countryMap.contains(name)) {
        QMessageBox::warning(this, "Error", "Country not found");
        return;
    }

    countryMap.remove(name);
    for (int i = 0; i < countries.size(); ++i) {
        if (countries[i].first == name) {
            countries.remove(i);
            break;
        }
    }

    removeCountryInput->clear();
    updateDisplay("Country removed successfully!");
}

void MainWindow::displaySortedCountries() {
    QVector<QPair<QString, int>> sortedCountries = countries;
    bool ascending = sortOrderCombo->currentText() == "Ascending";

    std::sort(sortedCountries.begin(), sortedCountries.end(),
              [ascending](const QPair<QString, int> &a, const QPair<QString, int> &b) {
                  return ascending ? a.second < b.second : a.second > b.second;
              });

    QString output;
    for (const auto &country : sortedCountries) {
        output += QString("%1: %2\n").arg(country.first).arg(country.second);
    }
    updateDisplay(output.isEmpty() ? "No countries to display" : output);
}

void MainWindow::updateDisplay(const QString &text) {
    outputDisplay->setText(text);
}
