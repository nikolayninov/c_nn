#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <cmath>

#include "../Types.hpp"

class Function
{

public:
    Function();
    Function(const Function &);
    Function(Function &&);
    ~Function();

    double call(Scalar) const;
    ColVector call(ColVector &) const;
    Matrix call(Matrix &) const;

    double gradAt(Scalar) const;
    ColVector gradAt(ColVector &) const;
    Matrix gradAt(Matrix &) const;

    std::string to_string() const;

    Function exponent(const Function &);
    friend Function operator+(const Function &, const Function &);
    friend Function operator-(const Function &, const Function &);
    friend Function operator*(const Function &, const Function &);
    friend Function operator/(const Function &, const Function &);

    Function operator=(const Function &);

    friend std::ostream &operator<<(std::ostream &, const Function &);

protected:
    void setGradient(func);
    func getGradient() const;

    void setFunc(func);
    func getFunc() const;

    void setStringifier(sfunc);
    sfunc getStringifier() const;

private:
    std::string name;
    func f;
    func grad;
    sfunc stringifier;
};

#endif