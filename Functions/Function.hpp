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

    double call(double) const;
    double gradAt(double) const;
    std::string to_string() const;

    Function exp(const Function);

    friend Function operator+(const Function, const Function);
    friend Function operator-(const Function, const Function);
    friend Function operator*(const Function, const Function);
    friend Function operator/(const Function, const Function);

    friend std::ostream &operator<<(std::ostream &, const Function &);

protected:
    void setGradient(func);
    func getGradient() const;

    void setFunc(func);
    func getFunc() const;

    void setStringifier(sfunc);
    sfunc getStringifier() const;

private:
    func f;
    func grad;
    sfunc stringifier;
};

#endif