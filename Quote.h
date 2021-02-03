#include <string>
#include <iostream>
class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : bookNo(book), price(sales_price) {}
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug(std::ostream &os) const { os << " bookNo: " << bookNo << " price: " << price; }
    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{

public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
    virtual void debug(std::ostream &os) const { os << "Disc_quote"; }

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote final : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug(std::ostream &os) const final { Quote::debug(os), os << " min_pty: " << quantity << " discount: " << discount; }
};

Bulk_quote::Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double disc) : Disc_quote(book, sales_price, qty, disc) {}

double Bulk_quote::net_price(std::size_t cnt) const
{
    if (cnt >= quantity)
        return (cnt - quantity) * price + quantity * (1 - discount) * price;
    else
        return cnt * price * (1 - discount);
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << "  total due: " << ret << std::endl;
    return ret;
}