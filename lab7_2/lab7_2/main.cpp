#include <QString>
#include <QSet>
#include <iostream>

using namespace std;

bool isPangram(const QString& text) {
    // Convert the string to lowercase for case-insensitive checking
    QString lowerText = text.toLower();

    // Create a set to store unique letters
    QSet<QChar> letters;

    // Iterate through each character in the text
    for (const QChar& ch : lowerText) {
        // Check if the character is a letter from a-z
        if (ch.isLetter() && ch.unicode() >= 'a' && ch.unicode() <= 'z') {
            letters.insert(ch);
        }
    }

    // Check if we found all 26 letters of the Latin alphabet
    return letters.size() == 26;
}

// Example usage in main function
int main() {
    QString testString = "The quick brown fox jumps over the lazy do";
    if (isPangram(testString)) {
        cout << "The string is a pangram!";
    } else {
        cout << "The string is not a pangram.";
    }

    return 0;
}
