#ifndef MODELS_H
#define MODELS_H

#include <cstdlib>
#include <ostream>
#include <string>
#include <sstream>


struct Point {
    double x, y;

    Point(): x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
};

class StringTemplate {
    private:
        std::string total;
    public:
        StringTemplate(std::string t);

        std::string get();

        template <typename ToStringType>
        StringTemplate& replace(const std::string & token, const ToStringType & value);
};

template <typename ToStringType>
StringTemplate& StringTemplate::replace(const std::string & token, const ToStringType & value) {
    auto formattedToken = "${" + token + "}";

    std::ostringstream os;
    os << value;
    std::string valueString = os.str();

    std::size_t pos = total.find(formattedToken);

    while (pos != std::string::npos) {
        total = total.replace(pos, formattedToken.length(), valueString);
        pos = total.find(formattedToken);
    }

    return *this;
}


struct BoundingBox {
    double height, width;

    BoundingBox(): height(0.0), width(0.0)  {}
    BoundingBox(double h, double w): height(h), width(w) {}

    std::string toString() const;

    void scale(double x, double y) {
        width *= x;
        height *= y;
    }
};

bool operator==(const BoundingBox & lhs, const BoundingBox & rhs);
std::ostream& operator <<(std::ostream& os, const BoundingBox & value);
#endif // MODELS_H
