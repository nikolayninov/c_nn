#ifndef FUNCTION_H
#define FUNCTION_H

#include <functional>
#include <string>
#include <cmath>

typedef std::function<double(double)> func;
typedef std::function<std::string()> sfunc;

class Function
{

public:
    Function();
    Function(const Function &);
    Function(Function &&);
    ~Function();

    void setGradient(func);
    void setFunc(func);
    void setStringifier(sfunc);

    // Function exp(Function &);

    double call(double) const;
    double gradAt(double) const;
    std::string to_string() const;

    Function exp(const Function);

    friend Function operator+(const Function, const Function);
    friend Function operator-(const Function, const Function);
    friend Function operator*(const Function, const Function);
    friend Function operator/(const Function, const Function);

    friend std::ostream &operator<<(std::ostream &, const Function &);

private:
    func f;
    func grad;
    sfunc stringifier;

    func getGradient() const;
    func getFunc() const;
    sfunc getStringifier() const;
};

#endif