//Shanti Gharib
//Lab 6

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

class Fraction {
private: 
    static size_t classObjectsCount;
    int numerator{NUMERATOR_DEFAULT}, 
        denominator{DENOMINATOR_DEFAULT};
public:
    static constexpr const int NUMERATOR_DEFAULT{1},
        DENOMINATOR_DEFAULT{1};

    Fraction();
    Fraction(const Fraction &source);
    Fraction(int newNumerator);
    Fraction(int newNumerator, int newDenominator);
    Fraction(int newNumerator, int newDenominator, int mixedNumber);
    ~Fraction();

    void SetNumerator(int newNumerator);
    void SetDenominator(int newDenominator);
    void SetFraction(int newNumerator);
    void SetFraction(int newNumerator, int newDenominator);
    void SetFraction(int newNumerator, int newDenominator, int mixedNumber);

    std::string ToString() const;

    inline size_t GetCurrentMemoryCount();


};

class FractionException {
private:
static constexpr const int NEGATIVE_TEST_VAL{-1};
Fraction obj;
    void ZeroDenominator();
    void ZeroNumerator();
    void MakeNumeratorNegative();
    void MakeDenominatorNegative();
    void SetWholeNumberNegative();
    void MakeNumeratorGreaterThanBase();
public:
    
    FractionException();

    void Demo();
};


size_t Fraction::classObjectsCount{0};

void PrintMemoryCount(Fraction &obj);
void DisplayMenu();
void HandleDefaultMenuCase();


int main() {
    enum { DEMO_EXCEPTION_HANDLING = 1, QUIT };

    int option{0};
    FractionException demoObj;

    while (option != QUIT) {
        
        DisplayMenu();

        std::cin >> option;

        switch (option) {
        
            case DEMO_EXCEPTION_HANDLING: {
                demoObj.Demo();
                break;    
            }

            case QUIT: {
                std::cout << "Program now closed...\n";
                break;
            }

            default: {
                HandleDefaultMenuCase();
                break;
            }
        
        }

    }


}



Fraction::Fraction() {
    ++classObjectsCount;
}

Fraction::Fraction(const Fraction &source) {
    ++classObjectsCount;
    SetFraction(source.numerator, source.denominator);
}

Fraction::Fraction(int newNumerator) {
    ++classObjectsCount;
    SetFraction(newNumerator);
}

Fraction::Fraction(int newNumerator, int newDenominator) {
    ++classObjectsCount;
    SetFraction(newNumerator, newDenominator);
}

Fraction::Fraction(int newNumerator, int newDenominator, int mixedNumber) {
    ++classObjectsCount;
    SetFraction(newNumerator, newDenominator, mixedNumber);
}

Fraction::~Fraction() {
    --classObjectsCount;
    denominator = 1;
    numerator = 0;
}

void Fraction::SetNumerator(int newNumerator) {
    if (newNumerator == 0) {
        throw std::runtime_error("Zero not allowed for numerator");
    }
    else if (newNumerator > 0 != numerator > 0) {
        throw std::runtime_error("Positive Fractions Only");
    }
    numerator = newNumerator;
}

void Fraction::SetDenominator(int newDenominator) {
    if (newDenominator == 0) {
        throw std::runtime_error("Divide by Zero Error");
    }
    else if (newDenominator > 0 != denominator > 0) {
        throw std::runtime_error("Positive Fractions Only");
    }
    denominator = newDenominator;
}

void Fraction::SetFraction(int newNumerator) {
    if (newNumerator < 0) {
        throw std::runtime_error("Positive Fractions Only");
    }
    numerator = newNumerator;
    denominator = DENOMINATOR_DEFAULT;
}

void Fraction::SetFraction(int newNumerator, int newDenominator) {
    if (newNumerator > 0 != newDenominator > 0) {
        throw std::runtime_error("Positive Fractions Only");
    }
    numerator = newNumerator;
    denominator = newDenominator;
}

void Fraction::SetFraction(int newNumerator, int newDenominator, int mixedNumber) {
    if (mixedNumber != 0 && newNumerator > newDenominator) {
        throw std::runtime_error ("Mixed Number Fraction cannot include improper fraction");
    }
    else if (mixedNumber < 0 || (newNumerator > 0 != newDenominator > 0)) {
        throw std::runtime_error("Positive Fractions Only");
    }
    numerator = newNumerator + (mixedNumber * newDenominator);
    denominator = newDenominator;
}

std::string Fraction::ToString() const {
        
    std::ostringstream result;

    if (numerator > denominator) {
            
        const int MIXED_NUMBER = numerator / denominator;

        result << MIXED_NUMBER << " " << (numerator - MIXED_NUMBER * denominator);

    }

    else {
            
        result << numerator;
        
    }

    result << "/" << denominator;

    return result.str();

    
}

inline size_t Fraction::GetCurrentMemoryCount() {
    return classObjectsCount;
}

FractionException::FractionException() {}

void FractionException::ZeroDenominator() {
    PrintMemoryCount(obj);
    try {
        obj.SetDenominator(0);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::ZeroNumerator() {
    PrintMemoryCount(obj);
    try {
        obj.SetNumerator(0);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::MakeNumeratorNegative() {
    PrintMemoryCount(obj);
    try {
        obj.SetNumerator(NEGATIVE_TEST_VAL);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::MakeDenominatorNegative() {
    PrintMemoryCount(obj);
    try {
        obj.SetDenominator(NEGATIVE_TEST_VAL);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::SetWholeNumberNegative() {
    PrintMemoryCount(obj);
    try {
        obj.SetFraction(Fraction::NUMERATOR_DEFAULT, Fraction::DENOMINATOR_DEFAULT * 2, NEGATIVE_TEST_VAL);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::MakeNumeratorGreaterThanBase() {
    PrintMemoryCount(obj);
    try {
        obj.SetFraction(Fraction::DENOMINATOR_DEFAULT + 1, Fraction::DENOMINATOR_DEFAULT, 1);
    }
    catch (const std::exception &err) {
        std::cout << err.what() << "\n\n";
    }
}

void FractionException::Demo() {
    ZeroDenominator();
    ZeroNumerator();
    MakeNumeratorNegative();
    MakeDenominatorNegative();
    SetWholeNumberNegative();
    MakeNumeratorGreaterThanBase();
    
    PrintMemoryCount(obj);
}

void PrintMemoryCount(Fraction &obj) {
    std::cout << std::left << std::setw(15) << "Current objects in memory: " 
        << std::right << obj.GetCurrentMemoryCount() << "\n";
}

void DisplayMenu() {
    std::cout << "\n\nSelect Option\n1. Demonstrate Exception Handling\n2. Quit\n\n";
}

void HandleDefaultMenuCase() {
    std::cout << "\nInvalid option selected\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//Output
// 
// Select Option
// 1. Demonstrate Exception Handling
// 2. Quit
// 
// 1
// Current objects in memory: 1
// Divide by Zero Error
// 
// Current objects in memory: 1
// Zero not allowed for numerator
// 
// Current objects in memory: 1
// Positive Fractions Only
// 
// Current objects in memory: 1
// Positive Fractions Only
// 
// Current objects in memory: 1
// Positive Fractions Only
// 
// Current objects in memory: 1
// Mixed Number Fraction cannot include improper fraction
// 
// Current objects in memory: 1
// 
// 
// Select Option
// 1. Demonstrate Exception Handling
// 2. Quit
// 
// 2
// Program now closed...